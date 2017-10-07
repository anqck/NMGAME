#include "SceneManager.h"

SceneManager*	SceneManager::mInstace;
SceneManager * SceneManager::GetInstance()
{
	if (!mInstace)
		mInstace = new SceneManager();

	return mInstace;
}

SceneManager::~SceneManager()
{
}

IScene * SceneManager::GetCurrentScene()
{
	return this->mCurrentScene;
}

void SceneManager::Update(float DeltaTime)
{
	this->mCurrentScene->Update(DeltaTime);
}

void SceneManager::ReplaceScene(IScene * scene)
{
	/*if (this->mCurrentScene)
		delete(this->mCurrentScene);*/
	this->mCurrentScene = scene;
}

SceneManager::SceneManager()
{
}
