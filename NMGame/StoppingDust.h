#pragma once

#include "ObjectState.h"
#include "GameVisibleEntity.h"

class StoppingDust : public GameVisibleEntity
{
public:
	StoppingDust();
	StoppingDust(D3DXVECTOR3	pos, Direction dir);
	~StoppingDust();

	void				Update(float DeltaTime);
	void				Render(float DeltaTime);

	bool				isDone();



protected:
	ObjectState*		mState;
	Direction			mDir;

	bool				mDone;


};