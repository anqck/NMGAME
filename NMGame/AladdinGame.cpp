#include "AladdinGame.h"


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
	imagepos.y = 450.0f; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	D3DXCreateSprite(GLOBAL::GetDirectDevice(), &sprite);
	vector<RECT> temp;
	RECT rect;
	rect.top = 1212;
	rect.bottom = 1275;
	rect.left = 60;
	rect.right = 110;
	temp.push_back(rect);


	mSprite = new Sprite(sprite, L"Aladdin.png", D3DCOLOR_XRGB(255, 0, 255),temp);
	
}

 void AladdinGame::RenderFrame(int Delta)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mBackground,			// from 
		NULL,				// which portion?
		GLOBAL::GetBackBuffer(),		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);

	mSprite->Render(0, 0);

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(imagetex, NULL, NULL, &imagepos, 0xFFFFFFFF);
	sprite->End();
}

 void AladdinGame::ProcessInput(int Delta)
 {
	 if (IsKeyDown(DIK_RIGHT))
	 {
		 imagepos.x += 10;
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
