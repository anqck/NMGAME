#include "AladdinGame.h"

#define ANIMATE_RATE 20

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

	//Temp code
	D3DXCreateSprite(GLOBAL::GetDirectDevice(), &sprite);
	vector<RECT> temp;
	/*RECT rect;
	rect.top = 1212;
	rect.bottom = 1275;
	rect.left = 60;
	rect.right = 110;
	temp.push_back(rect);*/
	for (int i = 1; i <= 13; i++)
	{
		RECT rect;
		rect.top = 1212;
		rect.bottom = 1275;
		switch (i)
		{
		case 1:
		{
			rect.left = 7;
			rect.right = 57;
			break;
		}
		case 2:
		{
			rect.left = 60;
			rect.right = 110;
			break;
		}
		case 3:
		{
			rect.left = 113;
			rect.right = 163;
			break;
		}
		case 4:
		{
			rect.left = 162;
			rect.right = 212;
			break;
		}
		case 5:
		{
			rect.left = 219;
			rect.right = 279;
			break;
		}
		case 6:
		{
			rect.left = 276;
			rect.right = 334;
			break;
		}
		case 7:
		{
			rect.left = 326;
			rect.right = 386;
			break;
		}
		case 8:
		{
			rect.left = 376;
			rect.right = 436;
			break;
		}
		case 9:
		{
			rect.left = 431;
			rect.right = 479;
			break;
		}
		case 10:
		{
			rect.left = 487;
			rect.right = 543;
			break;
		}
		case 11:
		{
			rect.left = 547;
			rect.right = 608;
			break;
		}
		case 12:
		{
			rect.left = 609;
			rect.right = 671;
			break;
		}
		case 13:
		{
			rect.left = 669;
			rect.right = 731;
			break;
		}
		}


		temp.push_back(rect);
	}
	kitty_vx = 0;
	kitty_vx_last = 1.0f;
	kitty_vy = 0;


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

	DWORD now = GetTickCount();
	if (now - last_time > 1000 / ANIMATE_RATE)
	{
		if (kitty_vx > 0) this->mSprite->Next();

		last_time = now;
	}


	//mSprite->SetPosition(mSprite->GetPosition().x + kitty_vx * Delta, mSprite->GetPosition().y+ kitty_vy * Delta);
	//mSprite->SetPosition(122 + Delta, 122);
	mSprite->Render();

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->Draw(imagetex, NULL, NULL, &imagepos, 0xFFFFFFFF);
	sprite->End();
}

 void AladdinGame::ProcessInput(int Delta)
 {
	 if (IsKeyDown(DIK_RIGHT))
	 {
		 kitty_vx = 0.3f;
		 kitty_vx_last = kitty_vx;
	 }
	 else
	 {
		 kitty_vx = 0;
		 mSprite->Reset();
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
