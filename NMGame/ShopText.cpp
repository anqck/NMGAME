#include "ShopText.h"

#include "GraphicsHelper.h"
#include "KeyboardHelper.h"

ShopText::ShopText()
{
	mShopTextOpacityTime = 0;
	mOpacityRendered = false;
	mDone = false;
	mTextRun = false;
	this->mVelocity = D3DXVECTOR2(-0.8, 0);
	this->mCurrentState = ShopTextState::ShopTextState_DoNothing;

	D3DXIMAGE_INFO				mImageInfo0, mImageInfo1;

	D3DXGetImageInfoFromFile(L"Object\\SceneInformation\\ShopText\\0.png", &mImageInfo0);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Object\\SceneInformation\\ShopText\\0.png", mImageInfo0.Width,
		mImageInfo0.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&mImageInfo0,
		NULL,
		&mTexture0);

	D3DXGetImageInfoFromFile(L"Object\\SceneInformation\\ShopText\\1.png", &mImageInfo1);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Object\\SceneInformation\\ShopText\\1.png", mImageInfo1.Width,
		mImageInfo1.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&mImageInfo1,
		NULL,
		&mTexture1);
}

ShopText::~ShopText()
{
}

void ShopText::Render()
{
	switch (mCurrentState)
	{
	case ShopTextState::ShopTextState_DoNothing:
		break;
	case ShopTextState::ShopTextState_FindsMoreGems:
		if (mOpacityRendered)
			GraphicsHelper::GetInstance()->DrawTexture(mTexture0, MyRECT(0, 0, 236, 16), D3DXVECTOR3(0, 0, 0), this->mPosition, D3DXVECTOR2(2.1, 2.1), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0), D3DCOLOR_ARGB(0, 255, 255, 255));

		else
			GraphicsHelper::GetInstance()->DrawTexture(mTexture0, MyRECT(0, 0, 236, 16), D3DXVECTOR3(0,0,0), this->mPosition, D3DXVECTOR2(2.1, 2.1), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case ShopTextState::ShopTextState_ItsADeal:
		if (mOpacityRendered)
		{
			GraphicsHelper::GetInstance()->DrawTexture(mTexture1, MyRECT(0, 0, 181, 16), D3DXVECTOR3(0, 0, 0), this->mPosition, D3DXVECTOR2(2, 2), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0), D3DCOLOR_ARGB(0, 255, 255, 255));
		}
		
		else
			GraphicsHelper::GetInstance()->DrawTexture(mTexture1, MyRECT(0, 0, 181, 16), D3DXVECTOR3(0, 0, 0), this->mPosition, D3DXVECTOR2(2, 2), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	}
}

void ShopText::Update(float DeltaTime)
{
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_LEFT) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_RIGHT))
	{
		mOpacityRendered = false;
		mTextRun = true;
	}

	if (!mTextRun)
	{
		if (mShopTextOpacityTime >= 7 * DeltaTime)
		{

			if (mOpacityRendered)
			{
				mOpacityRendered = false;
			}
			else
				mOpacityRendered = true;

			mShopTextOpacityTime = 0;
		}
		else
			mShopTextOpacityTime += DeltaTime;
	}

	switch (mCurrentState)
	{
	case ShopTextState::ShopTextState_DoNothing:
		mDone = true;
		break;
	case ShopTextState::ShopTextState_FindsMoreGems:
		if (this->mPosition.x + 236*2.1 <= 0)
		{
			this->mCurrentState = ShopTextState::ShopTextState_DoNothing;
			
		}
		else if(mTextRun)
		{
			this->mPosition.x += this->mVelocity.x * DeltaTime;
		}			
		break;
	case ShopTextState::ShopTextState_ItsADeal:
		if (this->mPosition.x + 181 * 2 <= 0)
		{
			this->mCurrentState = ShopTextState::ShopTextState_DoNothing;

		}
		else if (mTextRun)
		{
			this->mPosition.x += this->mVelocity.x * DeltaTime;
		}
		break;
	}
}

void ShopText::PrintText(ShopTextState text)
{
	mDone = false;
	mTextRun = false;
	switch (text)
	{
	case ShopTextState::ShopTextState_DoNothing:
		break;
	case ShopTextState::ShopTextState_FindsMoreGems:
		this->mCurrentState = ShopTextState::ShopTextState_FindsMoreGems ;
		this->mPosition = D3DXVECTOR3(GLOBAL::GetWindowsWidth()/2 - 236, GLOBAL::GetWindowsHeight()/2, 0);
		break;
	case ShopTextState::ShopTextState_ItsADeal:
		this->mPosition = D3DXVECTOR3(GLOBAL::GetWindowsWidth()/2 - 181, GLOBAL::GetWindowsHeight()/2, 0);
		this->mCurrentState = ShopTextState::ShopTextState_ItsADeal;
		break;
	}
}

bool ShopText::isDone()
{
	return this->mDone;
}
