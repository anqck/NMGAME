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
#include "SceneInformation.h"
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

	void					GoToLastCheckPoint();

	int						GetAladdinHP();
	int						GetAladdinLife();
	
	int						GetScore();
	void					SetScore(int number);
	void					AddScore(int number);

	void					AddFlyingObject(GameVisibleEntity* obj);

	SceneInformation*		 GetSceneInformation();

protected:	
	//int							mScore; 

	DemoMap						*mMap;
	AladdinCharacter			*mAladdin;
	AladdinGame					*mGame;
	SceneInformation			*mSceneInformation;

	//bool						allowAttack;

	QuadTree					*mQuadTree;

	vector<GameVisibleEntity*>		mListObjectInViewPort;

	vector<GameVisibleEntity*>		mListFlyingObject;	//C�c t�o n�m ra
};

#endif