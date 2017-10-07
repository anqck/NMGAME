#pragma once

#ifndef DemoScene_H
#define DemoScene_H
#include "IScene.h"
#include "AladdinGame.h"

using namespace std;

class DemoScene : public IScene
{
public:
	DemoScene();
	DemoScene(AladdinGame *game);
	~DemoScene();

	 void Update(float DeltaTime);
	 void Render(float DeltaTime);
	 void LoadResource();
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	void ProcessInput();


protected:
	LPDIRECT3DSURFACE9		mBackground;
	LPDIRECT3DTEXTURE9		imagetex;
	AladdinHelper			*mAladdinHelper;
	AladdinGame				*mGame;
	bool					allowAttack;

	vector<LPD3DXSPRITE>	mSpriteHandle;
	int						mNumberOfSprite;
	int						mMainIdx;
	vector<AladdinHelper*>	mAladdinHelperArr;
};

#endif