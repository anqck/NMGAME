#pragma once
#include "Global.h"
#include "AladdinDoNothing.h"
#include "AladdinState.h"
#include "AladdinWalk.h"
#include "AladdinStopWalk.h"
#include "AladdinLookUp.h"
#include "AladdinRest.h"
#include "AladdinStand.h"
#include "AladdinAttack1.h"
#include "AladdinSit.h"
#include "AladdinSitAttack.h"
#include "GameLog.h"
#include "GameVisibleEntity.h"
#include "MyRECT.h"
#include <vector>
#include <map>

enum AState
{
	DoNothing,
	Walk,
	StopWalk,
	LookUp,
	Stand,
	Sit,
	Rest,
	SitAttack,
	Attack1
};

enum Direction
{
	Left,
	Right,
	Up,
	Down
};

class AladdinCharacter : public GameVisibleEntity
{
public:
	AladdinCharacter();
	AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3	pos);


	void			Update(float DeltaTime);
	void			Render(float DeltaTime);			//
	void			OnKeyDown(int keyCode);
	void			OnKeyUp(int keyCode);
	void			ProcessInput(std::map<int, bool> keys);

	AState			getCurrentState();
	void			setCurrentState(AState state);

	void			setDirection(Direction dir);

	void			setAllowStateChange(bool allow);



protected:
	vector<AladdinState*>	mAladdinState;
	AState					mCurrentState;
	Direction				mDir;
	//LPD3DXSPRITE			mSpriteHandle;
	//D3DXVECTOR3			mPosition;

	bool					allowStateChange;
	//float					mTime;
	float					mStopWalkThresHold;
	bool					mIsStopAnimation;

	bool					allowAttack;

	void					_BeforeStateChange(AState changeTo);
	void					_AfterStateChange();

	
};