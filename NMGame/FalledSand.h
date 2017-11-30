#pragma once

#include "ObjectStateWithLoop.h"
#include "GameVisibleEntity.h"

class FalledSand : public GameVisibleEntity
{
public:
	FalledSand();
	FalledSand(D3DXVECTOR3	pos);
	~FalledSand();

	void				Update(float DeltaTime);
	void				Render(float DeltaTime);

	bool				isDone();



protected:
	ObjectState*		mState;
	Direction			mDir;

	bool				mDone;


};