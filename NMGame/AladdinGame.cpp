#include "AladdinGame.h"

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

	
	imagepos.x = 8.0f; //coord x of our sprite
	imagepos.y = 480.0f; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	//Temp code
	D3DXCreateSprite(GLOBAL::GetDirectDevice(), &mAladdinSpriteHandler);
	
	this->mAladdin = new AladdinWalk(this->mAladdinSpriteHandler);
	this->mAladdin->SetPosition(imagepos);


	/*kitty_vx = 0;
	kitty_vx_last = 1.0f;
	kitty_vy = 0;*/


	
}

 void AladdinGame::RenderFrame(int Delta)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mBackground,			// from 
		NULL,				// which portion?
		GLOBAL::GetBackBuffer(),		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);

	this->mAladdin->Animate();
	this->mAladdin->Move(Delta);
	this->mAladdin->Draw();

	//DWORD now = GetTickCount();
	//if (now - last_time > 1000 / ANIMATE_RATE)
	//{
	//	//if (kitty_vx > 0) this->mSprite->Next();
	//	if (this->mAladdin->GetVelocity().x > 0) this->mAladdin->nextFrame();

	//	last_time = now;
	//}


	//mSprite->SetPosition(mSprite->GetPosition().x + kitty_vx * Delta, mSprite->GetPosition().y+ kitty_vy * Delta);
	//mSprite->SetPosition(122 + Delta, 122);
	//mSprite->Render();

	/*sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(imagetex, NULL, NULL, &imagepos, 0xFFFFFFFF);
	sprite->End();*/
	
	
	
}

 void AladdinGame::ProcessInput(int Delta)
 {
	 if (IsKeyDown(DIK_RIGHT))
	 {
		 this->mAladdin->SetVelocity(0.3f, .0f);
		 kitty_vx = 0.3f;
		 kitty_vx_last = kitty_vx;
	 }
	 else
	 {
		 this->mAladdin->SetVelocity(0.0f, .0f);
		 this->mAladdin->resetFrame();
		 kitty_vx = 0;
		// mSprite->Reset();
	 }
 }

 void AladdinGame::OnKeyDown(int KeyCode)
 {
	 switch (KeyCode)
	 {
	 case DIK_SPACE:
		 break;
	 }
 }
