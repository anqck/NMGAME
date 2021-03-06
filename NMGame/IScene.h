#pragma once
#ifndef IScene_H
#define IScene_H

#include "GameVisibleEntity.h"


enum SceneID
{
	SceneID_MenuScene,
	SceneID_GameScene1,
	SceneID_GameSceneBoss,
	SceneID_DieScene,
	SceneID_ContinueScene,
	SceneID_LevelComplete,
	SceneID_ItemIntro,
	SceneID_IntroScene1
};

//Interface contact between "Game" class and "GameSence" class
class IScene
{
public:
	//public virtual method for class "Game" call
	virtual void Update(float DeltaTime) = 0;
	virtual void Render(float DeltaTime) = 0;
	virtual void ProcessInput() = 0;
	virtual void OnKeyDown(int keyCode) = 0;
	virtual void OnKeyUp(int keyCode) = 0;
	virtual void LoadResource() = 0;

	virtual void AddFlyingObject(GameVisibleEntity* obj) {};

	bool		isDone() { return this->mDone; };
	void		SetDone(bool done) { this->mDone = done; };
	//virtual
	SceneID		GetSceneID() { return this->mSceneID; };

	int						GetScore() { return this->mScore; };

	//virtual bool IsDead() = 0;;
	SceneID					mSceneID;
	//SceneInformation			*mSceneInformation;

	int							mScore;
	bool						mDone;
protected:
	//SceneInformation			*mSceneInformation;
	
};


#endif