#include "AladdinGame.h"
#include "DemoScene.h"




AladdinGame::~AladdinGame()
{

}

void AladdinGame::LoadResource()
{

	//Temp code
	//DemoScene* scene = new DemoScene(this);
	//DemoScene * scene = new DemoScene();
	//scene->LoadResource();

	//this->AddScene(scene);

	SceneManager::GetInstance()->Initialize();


	//this->mAladdinHelper = new AladdinHelper(this->mAladdinSpriteHandler, imagepos);
	
}

void AladdinGame::Update(float DeltaTime)
{
	SceneManager::GetInstance()->Update(DeltaTime);
}

 void AladdinGame::RenderFrame(float DeltaTime)
{
	
	 SceneManager::GetInstance()->GetCurrentScene()->Render(DeltaTime);
}

 void AladdinGame::ProcessInput(int Delta)
 {
	 KeyboardHelper::GetInstance()->Acquire();
	 SceneManager::GetInstance()->GetCurrentScene()->ProcessInput();
 }

 void AladdinGame::OnKeyDown(int KeyCode)
 {
	 switch (KeyCode)
	 {
	 case DIK_SPACE:
		 break;
	 }
 }
