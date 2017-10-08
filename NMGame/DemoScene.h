#pragma once

#ifndef DemoScene_H
#define DemoScene_H
#include "IScene.h"
#include "AladdinGame.h"
#include <map>

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
	AladdinCharacter		*mAladdinHelper;
	AladdinGame				*mGame;
	bool					allowAttack;

	vector<LPD3DXSPRITE>	mSpriteHandle;
	int						mNumberOfSprite;
	int						mMainIdx;
	vector<AladdinCharacter*>	mAladdinHelperArr;

	std::map<int, bool> keys;
};

#endif