#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "tile.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	virtual void onEnter();
	/*
	bool touchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	void touchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	void touchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	*/
	void keyPress  (cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void operateTiles(MoveDir dir);
	void genRandomTile();
	void moveTiles(MyGame::Tile *currtile, int targetRow, int targetCol, int currRow, int currCol);
	void mergeTile(MyGame::Tile *currtile, int targetRow, int targetCol, int currRow, int currCol);
	void newGameCallback();
	void addScore(int value);
	std::vector< std::tuple<int, int> > getEmptyTile();
	cocos2d::Vec2 calculateTilePos(int row, int col);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	cocos2d::Vec2 beginPos;
	cocos2d::Vec2 endPos;
	GameState gameState =  GameState::PREPARED;
	MyGame::Tile *tiles[4][4];

	int currScore = 0;
	int bestScore = 0;
	cocos2d::LabelTTF *currScoreLabel;
	cocos2d::LabelTTF *bestScoreLabel;
};

#endif // __HELLOWORLD_SCENE_H__
