#include "Start.h"
USING_NS_CC;

Scene* Start::createScene()
{
	auto scene = Scene::create();
	auto layer = Start::create();
	scene->addChild(layer);

	return scene;
}

bool Start::init()
{
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin      = Director::getInstance()->getVisibleOrigin();

	/*
	*	add background
	*/
	auto backGround = Sprite::create("background.png");
	backGround->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	addChild(backGround);

	/*
	*	add start....
	*/
	auto startMenuItem = MenuItemImage::create("item.png",
											   "item.png",
											   CC_CALLBACK_0(Start::startGameCallback, this));
	startMenuItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.8));
	auto startLabel = LabelTTF::create("Start", GAME_FONT_NAME, 40);
	startLabel->setPosition(Vec2(startMenuItem->getContentSize().width / 2, startMenuItem->getContentSize().height / 2));
	startMenuItem->addChild(startLabel);
	
	auto menu = Menu::create(startMenuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);
	return true;
}

void Start::onEnter()
{
	Layer::onEnter();
}

void Start::startGameCallback()
{
	auto gameScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(gameScene);
}