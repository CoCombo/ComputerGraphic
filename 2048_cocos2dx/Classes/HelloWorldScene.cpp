#include "HelloWorldScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	cocos2d::log("initialize game.");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
	
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
      //    you may modify it.
	//set game background
	auto backGround = Sprite::create("background.png");
	backGround->setPosition(Vec2(0.0, 0.0));
	backGround->setAnchorPoint(Vec2(0.0, 0.0));
	addChild(backGround, ZORDER_BG_LAYER);
	
	//set game name
	auto gameName = LabelTTF::create("2048", GAME_FONT_NAME, 64);
	gameName->setPosition(Vec2(origin.x + visibleSize.width * 0.22, origin.y + visibleSize.height * 0.9));
	gameName->setColor(Color3B(0x5B, 0x5B, 0x5B));
	addChild(gameName, ZORDER_BG_LAYER);

	/*
	*	set new game menu
	*/
	auto newMenuItem = MenuItemImage::create("item.png",
											 "item.png",
											 CC_CALLBACK_0(HelloWorld::newGameCallback, this));
	newMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(60, 210)));

	auto newMenuName = LabelTTF::create("New Game", GAME_FONT_NAME, 20);
	newMenuName->setPosition(Vec2(newMenuItem->getContentSize().width / 2, newMenuItem->getContentSize().height * 0.6));
	newMenuName->setScaleX(0.8);
	newMenuName->setColor(Color3B::BLACK);
	newMenuItem->addChild(newMenuName);

	auto menu = Menu::create(newMenuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);
	
	/*
	*   set current score field 
	*/
	//set current score background
	auto scoreBG = Sprite::create("item.png");
	scoreBG->setPosition(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.67);
	scoreBG->setColor(Color3B(240, 180, 120));
	addChild(scoreBG, ZORDER_BG_LAYER);
	//set current score name
	auto scoreName = LabelTTF::create("Score", SCORE_FONT_NAME, 24);
	scoreName->setPosition(Vec2(scoreBG->getContentSize().width / 2, scoreBG->getContentSize().height * 0.85));
	scoreName->setColor(Color3B(0x55, 0x55, 0x55));
	scoreBG->addChild(scoreName, ZORDER_BG_LAYER);
	//set current score value
	currScoreLabel = LabelTTF::create("0", SCORE_FONT_NAME, 24);
	currScoreLabel->setPosition(Vec2(scoreBG->getContentSize().width / 2, scoreBG->getContentSize().height * 0.4));
	currScoreLabel->setColor(Color3B(0x8A, 0x8A, 0x8A));
	scoreBG->addChild(currScoreLabel, ZORDER_BG_LAYER);

	/*
	*	set best score field
	*/
	//set best score background
	auto bestScoreBG = Sprite::create("item.png");
	bestScoreBG->setPosition(Vec2(origin.x + visibleSize.width * 0.85, origin.y + visibleSize.height * 0.67));
	addChild(bestScoreBG, ZORDER_BG_LAYER); 
	//set best score name
	auto bestScoreName = LabelTTF::create("BestScore", SCORE_FONT_NAME, 24);
	bestScoreName->setPosition(Vec2(bestScoreBG->getContentSize().width / 2, bestScoreBG->getContentSize().height * 0.85));
	bestScoreName->setColor(Color3B(0x55, 0x55, 0x55));
	bestScoreName->setScaleX(0.7);
	bestScoreBG->addChild(bestScoreName);
	//set best score value
	bestScoreLabel = LabelTTF::create("0", SCORE_FONT_NAME, 24);
	bestScoreLabel->setPosition(Vec2(bestScoreBG->getContentSize().width / 2, bestScoreBG->getContentSize().height * 0.4));
	bestScoreLabel->setColor(Color3B(0x8A, 0x8A, 0x8A));
	bestScoreBG->addChild(bestScoreLabel);
	
	gameState = GameState::RUNNUING;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			tiles[i][j] = nullptr;
    return true;
}

void HelloWorld::onEnter()
{
	Layer::onEnter();
	//regist keyboard event
	
	log("on game enter.");
	auto keyListener = EventListenerKeyboard::create();
	auto eventDispatcher = Director::getInstance()->getEventDispatcher();
	keyListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPress, this);
	eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	//generate random tile
	genRandomTile();
}

void HelloWorld::keyPress(cocos2d::EventKeyboard::KeyCode keyCode, Event *event)
{
	// cocos2d::log("key press keycode: %d", keyCode);
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		operateTiles(MoveDir::UP);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		operateTiles(MoveDir::DOWN);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		operateTiles(MoveDir::LEFT);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		operateTiles(MoveDir::RIGHT);
		break;
	default:
		break;
	}
}

void HelloWorld::operateTiles(MoveDir dir)
{
	auto currTile = tiles[0][0];
	switch (dir)
	{
	case MoveDir::LEFT:
		log("press leftbutton.");
		for (int row = 0; row < 4; row++)
		{
			for (int col = 1; col < 4; col++)
			{
				if (tiles[row][col] != nullptr)
				{
					log("find tile. %d %d", row, col);
					int leftEmptyPos = 0;
					currTile = tiles[row][col];
					while (leftEmptyPos < col  && tiles[row][leftEmptyPos] != nullptr)
						leftEmptyPos++;
					log("target pos %d %d", row, leftEmptyPos);
					if (leftEmptyPos != col)
					{
						gameState = GameState::MOVING;
						moveTiles(currTile, row, leftEmptyPos, row, col);
					}
					if (leftEmptyPos > 0 && tiles[row][leftEmptyPos]->getValue() == tiles[row][leftEmptyPos - 1]->getValue())
					{
						log("merge: %d", leftEmptyPos);
						gameState = GameState::MOVING;
						mergeTile(currTile, row, leftEmptyPos - 1, row, leftEmptyPos);
					}
					
				}
			}
		}
		break;
	case MoveDir::UP:
		log("press up button");
		for (int col = 0; col < 4; col++)
		{
			for (int row = 2; row >= 0; row--)
			{
				if (tiles[row][col] != nullptr)
				{
					int upEmptyPos = 3;
					currTile = tiles[row][col];
					while (upEmptyPos > row && tiles[upEmptyPos][col] != nullptr)
						upEmptyPos--;
					if (upEmptyPos != row)
					{
						gameState = GameState::MOVING;
						moveTiles(currTile, upEmptyPos, col, row, col);
					}
					if (upEmptyPos < 3 && tiles[upEmptyPos][col]->getValue() == tiles[upEmptyPos + 1][col]->getValue())
					{
						gameState = GameState::MOVING;
						mergeTile(currTile, upEmptyPos + 1, col,upEmptyPos, col);
					}
				}
			}
		}
		break;
	case MoveDir::RIGHT:
		log("press right key");
		for (int row = 0; row < 4; row++)
		{
			for (int col = 2; col >= 0; col--)
			{
				if (tiles[row][col] != nullptr)
				{
					int rightEmptyPos = 3;
					currTile = tiles[row][col];
					while (rightEmptyPos > col && tiles[row][rightEmptyPos] != nullptr)
						rightEmptyPos--;
					if (rightEmptyPos != col)
					{
						gameState = GameState::MOVING;
						moveTiles(currTile, row, rightEmptyPos, row, col);
					}
					if (rightEmptyPos < 3 && tiles[row][rightEmptyPos + 1]->getValue() == tiles[row][rightEmptyPos]->getValue())
					{
						gameState = GameState::MOVING;
						mergeTile(currTile, row, rightEmptyPos + 1, row, rightEmptyPos);
					}
				}
			}
		}
		break;
	case MoveDir::DOWN:
		log("press down key");
		for (int col = 0; col < 4; col++)
		{
			for (int row = 1; row < 4; row++)
			{
				if (tiles[row][col] != nullptr)
				{
					int downEmptyPos = 0;
					currTile = tiles[row][col];
					while (downEmptyPos < row && tiles[downEmptyPos][col] != nullptr)
						downEmptyPos++;
					if (downEmptyPos != row)
					{
						gameState = GameState::MOVING;
						moveTiles(currTile, downEmptyPos, col, row, col);
					}
					if (downEmptyPos > 0 && tiles[downEmptyPos - 1][col]->getValue() == tiles[downEmptyPos][col]->getValue())
					{
						gameState = GameState::MOVING;
						mergeTile(currTile, downEmptyPos - 1, col, downEmptyPos, col);
					}
				}
			}
		}
		break;
	default:
		break;
	}
	if (gameState == GameState::MOVING)
		genRandomTile();
}

void HelloWorld::genRandomTile()
{
	std::vector< std::tuple<int, int> > emptySlot = getEmptyTile();
	int randval = random<int>(1, 10) > 5 ? 4 : 2;
	int randPos = random<int>(0, emptySlot.size() - 1);
	int row = std::get<0>(emptySlot[randPos]);
	int col = std::get<1>(emptySlot[randPos]);
	//create random tile
	auto tile = MyGame::Tile::create(randval);
	tile->setPosition(calculateTilePos(row, col));
	tiles[row][col] = tile;
	addChild(tile, ZORDER_TILE_LAYER);

	gameState = GameState::RUNNUING;
}

std::vector< std::tuple<int, int> > HelloWorld::getEmptyTile()
{
	std::vector< std::tuple<int, int> > emptySlot;
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (tiles[row][col] == nullptr)
				emptySlot.push_back(std::make_tuple(row, col));
		}
	}
	return emptySlot;
}

/*x direction 65+i*77, y direction 103+i*77 */
Vec2 HelloWorld::calculateTilePos(int row, int col)
{
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto pos = Vec2(65 + col * 77, 103 + row * 77);

	return pos;
}

void HelloWorld::moveTiles(MyGame::Tile *currTile, int targetRow, int targetCol, int currRow, int currCol)
{
	auto size = Director::getInstance()->getVisibleSize();
	auto tileAction = MoveBy::create(0.05f, Vec2((targetCol - currCol) * 77, (targetRow - currRow) * 77));
	currTile->runAction(tileAction);
	tiles[targetRow][targetCol] = currTile;
	tiles[currRow][currCol] = nullptr;
}


void HelloWorld::mergeTile(MyGame::Tile *currtile, int targetRow, int targetCol, int currRow, int currCol)
{
	
	auto tile = MyGame::Tile::create(currtile->getValue() * 2);
	tile->setPosition(calculateTilePos(targetRow, targetCol));
	currtile->stopAllActions();
	currtile->removeFromParent();
	tiles[targetRow][targetCol]->removeFromParent();
	tiles[targetRow][targetCol] = tile;
	tiles[currRow][currCol] = nullptr;

	addScore(tile->getValue());

	addChild(tile);
}

void HelloWorld::newGameCallback()
{
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (tiles[row][col] != nullptr)
			{
				tiles[row][col]->removeFromParent();
				tiles[row][col] = nullptr;
			}
	genRandomTile();
}

void HelloWorld::addScore(int value)
{
	char buff[10];
	currScore += value;
	sprintf(buff, "%d", currScore);

	currScoreLabel->setString(buff);
}