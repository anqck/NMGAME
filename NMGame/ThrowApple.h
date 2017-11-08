#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"

class ThrowingApple : public GameVisibleEntity
{
public:
	ThrowingApple();
	ThrowingApple(D3DXVECTOR3	pos, Direction dir);
	~ThrowingApple();

	void			Update(float DeltaTime);
	void			Render(float DeltaTime);

	bool			isDone();



protected:
	ObjectState*	mState;
	Direction		mDir;

	bool			mDone;

	 
};