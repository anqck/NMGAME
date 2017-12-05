#pragma once

#ifndef ContinueScene_H
#define ContinueScene_H
#include "IScene.h"
#include "AladdinGame.h"

using namespace std;

enum ContinueSceneState
{
	Nothing,
	Yes,
	No,
	RunningToLeft,
	RunningToRight
};
class ContinueScene : public IScene
{
public:
	ContinueScene();
	ContinueScene(AladdinGame *game);
	~ContinueScene();

	void					LoadResource();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);
	

	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();

	ContinueSceneState		isDone();


protected:
	bool					mOpacityRender;
	int						mOpacity;

	vector<ObjectState*>	mBackground;

	vector<ObjectState*>	mAladdin;
	D3DXVECTOR3				mAladdinPosition;
	vector<ObjectState*>	mMonkey;
	D3DXVECTOR3				mMonkeyPosition;
	int						mAladdinAndMonkeyState;

	ObjectState*				mContinueString;

	ContinueSceneState		mSceneState;

	LPDIRECT3DSURFACE9			_Surface;
};

#endif