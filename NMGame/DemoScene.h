#pragma once

#ifndef DemoScene_H
#define DemoScene_H
#include "IScene.h"
#include "AladdinGame.h"
#include "Camel.h"
#include "AladdinCharacter.h"
#include "DemoMap.h"
#include "Camera.h"
#include "QuadTree.h"

#include "ThrowApple.h"


using namespace std;



class DemoScene : public IScene
{
public:
	DemoScene();
	DemoScene(AladdinGame *game);
	~DemoScene();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);
	void					LoadResource();
	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();


protected:
	DemoMap					*mMap;
	AladdinCharacter		*mAladdinHelper;
	AladdinGame				*mGame;
	Camel					*mCamel;
	bool					allowAttack;

	QuadTree				*mQuadTree;

	int						mNumberOfSprite;
	int						mMainIdx;
	vector<AladdinCharacter*>	mAladdinHelperArr;


};

#endif