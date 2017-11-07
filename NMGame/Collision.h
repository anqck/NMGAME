#pragma once

#include "MyRECT.h"

class Collision
{
public:
	static Collision*		GetInstance();

private:
	static Collision*		mInstance;
};