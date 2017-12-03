#include "SceneManager.h"
#include "DemoScene.h"
#include "DieScene.h"
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
	switch (this->mCurrentScene->GetSceneID())
	{
	case  SceneID::SceneID_GameScene1:
		if (((DemoScene*)mCurrentScene)->GetAladdinHP() <= -1)
		{
			this->mCurrentScene = new DieScene();
		}
		break;
	case  SceneID::SceneID_DieScene:
		if (((DieScene*)mCurrentScene)->isDone() == true)
		{
			
			this->mCurrentScene = this->mCurrentGame;
			((DemoScene*)mCurrentGame)->GoToLastCheckPoint();
		}
		break;
	}

		this->mCurrentScene->Update(DeltaTime);
}

void SceneManager::Render(float DeltaTime)
{
	this->mCurrentScene->Render(DeltaTime);
}

void SceneManager::ReplaceScene(IScene * scene)
{
	/*if (this->mCurrentScene)
		delete(this->mCurrentScene);*/
	if (scene->GetSceneID() == SceneID::SceneID_GameScene1)
	{
		mCurrentGame = scene;
	}
	this->mCurrentScene = scene;
}

SceneManager::SceneManager()
{
}
