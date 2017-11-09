#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"

enum ThrowingAppleState
{
	Normal,
	Explosion
};
class ThrowingApple : public GameVisibleEntity
{
public:
	ThrowingApple();
	ThrowingApple(D3DXVECTOR3	pos, Direction dir);
	~ThrowingApple();

	void				Update(float DeltaTime);
	void				Render(float DeltaTime);


	bool				isDone();



protected:
	vector<ObjectState*>		mState;
	Direction					mDir;

	ThrowingAppleState			mCurrentState;

	bool						mDone;

	 
};