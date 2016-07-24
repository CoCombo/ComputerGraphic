#ifndef _START_H_
#define _START_H_

#include "cocos2d.h"
#include "common.h"
#include "HelloWorldScene.h"

class Start : public cocos2d::Layer
{
public:
	static cocos2d::Scene *createScene();
	virtual bool init();
	virtual void onEnter();

	void startGameCallback();
	CREATE_FUNC(Start);
private:
};

#endif