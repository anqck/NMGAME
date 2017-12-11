#include "SceneManager.h"
#include "MenuScene.h"
#include "DemoScene.h"
#include "BossScene.h"
#include "DieScene.h"
#include "ContinueScene.h"

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

void SceneManager::Initialize()
{
	BossScene * scene = new BossScene();
	//DemoScene * scene = new DemoScene();

	this->ReplaceScene(scene);
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
			if (((DemoScene*)mCurrentGame)->GetAladdinLife() >= 1)
			{
				this->mCurrentScene = this->mCurrentGame;
				((DemoScene*)mCurrentGame)->GoToLastCheckPoint();
			}
			else
				ReplaceScene(new ContinueScene());
			
		}
		break;
	case  SceneID::SceneID_ContinueScene:
		if (((ContinueScene*)mCurrentScene)->isDone() == ContinueSceneState::Yes )
		{
			DemoScene * scene = new DemoScene();

			ReplaceScene(scene);
		}
		else if (((ContinueScene*)mCurrentScene)->isDone() == ContinueSceneState::No)
		{

		}
	case  SceneID::SceneID_MenuScene:
		switch (((MenuScene*)mCurrentScene)->isDone())
		{
		case MenuSceneState::MenuSceneState_Scene1:
			DemoScene * scene = new DemoScene();

			ReplaceScene(scene);
			break;
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

