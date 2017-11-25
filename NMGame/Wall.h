#pragma once

#ifndef __WALL_H__
#define __WALL_H__
#include "GameVisibleEntity.h"

class Wall :public GameVisibleEntity
{
public:
	Wall();
	Wall(MyRECT bb);


};

#endif __WALL_H__