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
	void					CheckCollision(float DeltaTime);

	
	

	void					AddFlyingObject(GameVisibleEntity* obj);

protected:	
	DemoMap						*mMap;
	AladdinCharacter			*mAladdin;
	AladdinGame					*mGame;

	bool						allowAttack;

	QuadTree					*mQuadTree;

	vector<GameVisibleEntity*>	mListObjectInViewPort;

	vector<GameVisibleEntity*>		mListFlyingObject;	//Các táo ném ra
};

#endif