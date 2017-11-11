#pragma once
#ifndef __GROUND_H__
#define __GROUND_H__
#include "GameVisibleEntity.h"

class Ground :public GameVisibleEntity
{
public:
	Ground();
	Ground(MyRECT bb);

	
};

#endif __GROUND_H__