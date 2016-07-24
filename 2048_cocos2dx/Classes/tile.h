#ifndef _TILE_H_
#define _TILE_H_

#include "common.h"
namespace MyGame
{
	class Tile : public cocos2d::Node
	{
	public:
		//Tile();
		//~Tile();

		static  Tile*		   create(int val);
		virtual void           onEnter();
		virtual void           setPosition(const cocos2d::Vec2 &pos);
		virtual void		   setAnchorPoint(const cocos2d::Vec2 &anc);
		virtual const cocos2d::Vec2&  getPosition() const;
		virtual void           setColor(const cocos2d::Color3B &color);
		void		   setValue(int val);
		int			   getValue();
	private:
		cocos2d::Vec2   position;
		cocos2d::Sprite *image;
		cocos2d::LabelTTF  *valueText;

		int  value;
		bool inMarge = false;

		bool init(int val);
	};
}
#endif