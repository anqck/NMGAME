#pragma once
#ifndef __STAIRFLAGCHANGE_H__
#define __STAIRFLAGCHANGE_H__
#include "GameVisibleEntity.h"

class StairFlagChange :public GameVisibleEntity
{
public:
	StairFlagChange();
	StairFlagChange(MyRECT bb, int change1, int change2);

	int change1, change2;


};

#endif __STAIRFLAGCHANGE_H__
