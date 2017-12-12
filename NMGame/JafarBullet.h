#pragma once

#include "GameVisibleEntity.h"
#include "ObjectStateWithLoop.h"
#include "KeyboardHelper.h"
#include "Global.h"
#include "AladdinCharacter.h"

#define	DEFAULT_JARFARBULLET_VELOCITY 0.7
enum JafarBulletState
{
	JafarBulletState_Normal,
	JafarBulletState_Explosion
};
class JafarBullet : public GameVisibleEntity
{
public:
	JafarBullet() : GameVisibleEntity() {};
	JafarBullet(D3DXVECTOR3	pos, AladdinCharacter* ala);
	//JafarBullet(D3DXVECTOR3	pos, Direction dir, D3DXVECTOR2 defaultVelocity) :JafarBullet(pos, dir) { this->mVelocity = defaultVelocity; };
	~JafarBullet();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

	virtual ObjectState*		GetCurrentState();

	bool						isDone();

	void						processCollision(float DeltaTime, GameVisibleEntity * obj, CollisionResult collision);

	JafarBulletState			GetCurrentStateID();

protected:
	vector<ObjectState*>		mState;

	Direction					mDir;
	AladdinCharacter			*mAladdin;

	JafarBulletState			mCurrentState;

	bool						mDone;
	bool						mCollisioned;

};