#pragma once
#ifndef SceneManager_H
#define SceneManager_H

#include "IScene.h"




class SceneManager
{
public:
	static SceneManager *GetInstance();
	~SceneManager();

	IScene* GetCurrentScene();
	void	 Update(float DeltaTime);
	void	Render(float DeltaTime);
	void	 ReplaceScene(IScene *scene);
	//void ReplaceScene(Scene *scenedest, TransitionEffect *effect);
	//void OnFinishTransition();

private:
	SceneManager();
	static SceneManager     *mInstace;
	IScene                  *mCurrentScene;
};

#endif