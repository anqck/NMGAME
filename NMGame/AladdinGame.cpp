#include "AladdinGame.h"
#include "DemoScene.h"

#define ANIMATE_RATE 21

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
	
	this->mBackground = CreateSurfaceFromFile(GLOBAL::GetDirectDevice(), L"Map\\Map1.PNG");

	D3DXIMAGE_INFO mImageInfo;
	D3DXGetImageInfoFromFile(L"temp.png", &mImageInfo);
	D3DXCreateTextureFromFileEx(GLOBAL::GetDirectDevice(), L"temp.png", mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&mImageInfo,
		NULL,
		&imagetex);

	
	

	//Temp code
	D3DXCreateSprite(GLOBAL::GetDirectDevice(), &mAladdinSpriteHandler);
	GLOBAL::SetSpriteHandler(mAladdinSpriteHandler);

	DemoScene* scene = new DemoScene(this);
	this->AddScene(scene);
	SceneManager::GetInstance()->ReplaceScene(scene);
	//this->mAladdinHelper = new AladdinHelper(this->mAladdinSpriteHandler, imagepos);
	
}

 void AladdinGame::RenderFrame(int Delta)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mBackground,			// from 
		NULL,				// which portion?
		GLOBAL::GetBackBuffer(),		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);
	/* GLOBAL::GetDirectDevice()->ColorFill(
		 GLOBAL::GetBackBuffer(),
		 NULL,
		 D3DCOLOR_XRGB(0, 0, 0));*/


	SceneManager::GetInstance()->GetCurrentScene()->Update(Delta);
	 //this->mAladdinHelper->Render(Delta);

	/*this->mAladdin->Animate();
	this->mAladdin->Move(Delta);
	this->mAladdin->Draw();*/
	 
	/*sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(imagetex, NULL, NULL, &imagepos, 0xFFFFFFFF);
	sprite->End();*/
	
	
	
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
