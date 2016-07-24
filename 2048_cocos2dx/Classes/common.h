#ifndef _COMMON_H_
#define _COMMON_H_

#include "cocos2d.h"
using cocos2d::Color3B;
//fonts
#define GAME_FONT_NAME "fonts/tahoma.ttf"
#define TILE_FONT_NAME "fonts/tahoma.ttf"
#define SCORE_FONT_NAME "fonts/tahoma.ttf"
#define TILE_NUM 16

//move direction of tile
enum class MoveDir
{
	LEFT,
	UP,
	RIGHT,
	DOWN
};

//game state
enum class GameState
{
	PREPARED,
	RUNNUING,
	MOVING,
	OVER,
	WIN,
};

//color of tile
static const Color3B TileColor[] = {
	Color3B(220, 210, 200),//0
	Color3B(240, 230, 220),//2
	Color3B(240, 230, 200),//4
	Color3B(240, 170, 120),//8
	Color3B(240, 180, 120),//16
	Color3B(240, 140, 90),//32
	Color3B(240, 120, 90),//64
	Color3B(240, 90, 60),//128
	Color3B(230, 80, 40),//256
	Color3B(240, 60, 40),//512
	Color3B(240, 200, 70),//1024
	Color3B(230, 230, 0),//2048
	Color3B(10, 90, 170)//4096
};

enum SpriteZOrder
{
	ZORDER_BG_LAYER = 0,
	ZORDER_TILE_LAYER,
	ZORDER_RESULT_LAYER
};
#endif