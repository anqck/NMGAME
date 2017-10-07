#include "AladdinGame.h"
#include "DemoScene.h"



AladdinGame::~AladdinGame()
{
	if (GLOBAL::GetDirect())
		GLOBAL::GetDirect()->Release();

	if (GLOBAL::GetDirectDevice())
		GLOBAL::GetDirectDevice()->Release();

	if (GLOBAL::GetBackBuffer())
		GLOBAL::GetBackBuffer()->Release();
}

void AladdinGame::LoadResource()
{
	
	//Temp code
	DemoScene* scene = new DemoScene(this);
	scene->LoadResource();
	this->AddScene(scene);
	SceneManager::GetInstance()->ReplaceScene(scene);


	//this->mAladdinHelper = new AladdinHelper(this->mAladdinSpriteHandler, imagepos);
	
}

void AladdinGame::Update(int DeltaTime)
{
	SceneManager::GetInstance()->GetCurrentScene()->Update(DeltaTime);
}

 void AladdinGame::RenderFrame(int DeltaTime)
{

	SceneManager::GetInstance()->GetCurrentScene()->Render(DeltaTime);


}

 void AladdinGame::ProcessInput(int Delta)
 {
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
