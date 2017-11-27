#pragma once
#ifndef __JUMPBAR_H__
#define __JUMPBAR_H__
#include "GameVisibleEntity.h"

enum JumpBarState
{
	JumpBarState_Normal,
	JumpBarState_JumpOn
};

class JumpBar :public GameVisibleEntity
{
public:
	JumpBar();
	JumpBar(MyRECT bb);
	~JumpBar();

	void						Render(float DeltaTime);
	void						Update(float DeltaTime);

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

protected:
	vector<ObjectState*>		mState;
	JumpBarState					mCurrentState;


};

#endif __JUMPBAR_H__