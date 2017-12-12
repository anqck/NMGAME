#pragma once

#ifndef BossScene_H
#define BossScene_H

#include "IScene.h"
#include "AladdinGame.h"
#include "AladdinCharacter.h"
#include "BossMap.h"
#include "Camera.h"
#include "QuadTree.h"
#include "SceneInformation.h"
#include "ThrowApple.h"
#include "Jafar.h"


using namespace std;



class BossScene : public IScene
{
public:
	BossScene();
	BossScene(AladdinGame *game);
	~BossScene();

	void					LoadResource();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);

	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();
	void					CheckCollision(float DeltaTime);

	void					GoToLastCheckPoint();

	int						GetAladdinHP();
	int						GetAladdinLife();

	//int						GetScore();
	void					SetScore(int number);
	void					AddScore(int number);



	void					AddFlyingObject(GameVisibleEntity* obj);

	MyRECT					GetCenterRegionRECT();
	GameVisibleEntity*		GetJafar();

protected:
	MyRECT						mCenterRegionRECT;

	//int							mScore;

	BossMap						*mMap;
	AladdinCharacter			*mAladdin;
	Jafar						*mJafar;

	SceneInformation			*mSceneInformation;

	vector<GameVisibleEntity*>		mListObjectInViewPort;

	vector<GameVisibleEntity*>		mListFlyingObject;	//Các táo ném ra

	vector<GameVisibleEntity*>		mListLeftApple;
	vector<GameVisibleEntity*>		mListRightApple;
};

#endif