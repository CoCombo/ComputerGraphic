#include "tile.h"
using cocos2d::Vec2;
using namespace MyGame;
//color index
int colorIndex(int val)
{
	int index = 0;
	while (val > 1)
	{
		val /= 2;
		index++;
	}
	return index;
}
//create tile
Tile* Tile::create(int val)
{
	auto tile = new Tile();
	if (tile != nullptr && tile->init(val))
	{
		tile->autorelease();
		return tile;
	}
	CC_SAFE_DELETE(tile);
	return nullptr;
}

//tile position
void Tile::setPosition(const Vec2 &pos)
{
	position = pos;
	image->setPosition(pos);
}
void Tile::setAnchorPoint(const Vec2 &anc)
{
	image->setAnchorPoint(anc);
}
//以下函数，由于是const函数，如果要返回引用则必须返回const引用，
//否则接受引用的外部变量就能改变值，当然这也是无法编译通过的
const Vec2& Tile::getPosition() const
{
	return position;
}

//tile color
void Tile::setColor(const Color3B &color)
{
	image->setColor(color);
}
//tile value
void Tile::setValue(int val)
{
	value = val;

	if (val == 0)
		valueText->setString("");
	else
	{
		char valToStr[10];
		sprintf(valToStr, "%d", val);
		valueText->setString(valToStr);
	}
	if (val > 100)
		valueText->setScaleX(0.85f);
	else if (val > 1000)
		valueText->setScaleX(0.7f);
	else if (val > 10000)
		valueText->setScaleX(0.55f);
	else {
		valueText->setScaleX(1.0f);
	}
	//set value text color
	if (val > 4) {
		valueText->setColor(Color3B(255, 255, 255));
	}
	else {
		valueText->setColor(Color3B(60, 60, 60));
	}
	image->setColor(TileColor[colorIndex(val)]);
}

int Tile::getValue()
{
	return value;
}

//tile initialise
bool Tile::init(int val)
{
	if (!Node::init())
		return false;

	//tile image
	image = cocos2d::Sprite::create("item.png");
	addChild(image);

	//value on tile
	valueText = cocos2d::LabelTTF::create(std::string(1, '0' + val), TILE_FONT_NAME, 36);
	valueText->setPosition(Vec2(image->getContentSize().width / 2, image->getContentSize().height / 2));
	setValue(val);
	image->addChild(valueText);
	
	return true;
}

void Tile::onEnter()
{
	Node::onEnter();
	if (value != 0) {
		image->setScale(0.7);
		auto scaleToAction = cocos2d::ScaleTo::create(0.1, 1.0);
		image->runAction(scaleToAction);
	}
}