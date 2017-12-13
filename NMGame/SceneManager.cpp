#include "SceneManager.h"
#include "MenuScene.h"
#include "DemoScene.h"
#include "BossScene.h"
#include "DieScene.h"
#include "ContinueScene.h"
#include "LevelCompleteScene.h"

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
	//LevelCompleteScene* scene = new LevelCompleteScene();
	//BossScene * scene = new BossScene();
	//DemoScene * scene = new DemoScene();
	MenuScene * scene = new MenuScene();

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
				break;
		}

		if (this->mCurrentScene->isDone())
		{
			this->mCurrentScene = new LevelCompleteScene();
			break;
		}
		break;
	case  SceneID::SceneID_GameSceneBoss:
		if (((BossScene*)mCurrentScene)->GetAladdinHP() <= -1)
		{
			this->mCurrentScene = new DieScene();
			break;

		}
		if (((BossScene*)mCurrentScene)->GetJafar()->GetHP() == 0)
		{
			this->mCurrentScene = new LevelCompleteScene();
			break;
		}
		break;
	case  SceneID::SceneID_DieScene:
		switch (mCurrentGame->GetSceneID())
		{
		case SceneID::SceneID_GameScene1:
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
		case SceneID::SceneID_GameSceneBoss:
			if ((mCurrentScene)->isDone() == true)
			{
				if (((BossScene*)mCurrentGame)->GetAladdinLife() >= 1)
				{
					this->mCurrentScene = this->mCurrentGame;
					((BossScene*)mCurrentGame)->GoToLastCheckPoint();
				}
				else
					ReplaceScene(new ContinueScene());

			}
			break;
			break;
		}
		
		break;
	case  SceneID::SceneID_ContinueScene:
		if (((ContinueScene*)mCurrentScene)->isDone() == ContinueSceneState::Yes )
		{
			if (this->mCurrentGame->GetSceneID() == SceneID::SceneID_GameScene1)
			{
				DemoScene * scene = new DemoScene();

				ReplaceScene(scene);
			}
			else if (this->mCurrentGame->GetSceneID() == SceneID::SceneID_GameSceneBoss)
			{
				BossScene * scene = new BossScene();

				ReplaceScene(scene);
			}
		}
		else if (((ContinueScene*)mCurrentScene)->isDone() == ContinueSceneState::No)
		{

		}
	case  SceneID::SceneID_MenuScene:
		switch (((MenuScene*)mCurrentScene)->isDone())
		{
		case MenuSceneState::MenuSceneState_Scene1:

			ReplaceScene(new DemoScene());
			break;
		case MenuSceneState::MenuSceneState_SceneBoss:
			ReplaceScene(new BossScene());
			break;
		}
		break;
	case  SceneID::SceneID_LevelComplete:
		if ((mCurrentScene)->isDone())
		{
			MenuScene * scene = new MenuScene();

			ReplaceScene(scene);
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

	if (scene->GetSceneID() == SceneID::SceneID_GameScene1 || scene->GetSceneID() == SceneID::SceneID_GameSceneBoss)
	{

		mCurrentGame = scene;
	}
	this->mCurrentScene = scene;
	
}

SceneManager::SceneManager()
{
}

