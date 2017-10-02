#include "Sprite.h"

Sprite::Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR FilePath, D3DCOLOR transcolor, vector<RECT> listSourceRect)
{
	mSpriteHandler = SpriteHandler;
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mListRect = listSourceRect;

	mSourceRect = listSourceRect.at(0);

	D3DXGetImageInfoFromFile(FilePath, &mImageInfo);

	D3DXCreateTextureFromFileEx(GLOBAL::GetDirectDevice(), FilePath, mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transcolor,
		&mImageInfo,
		NULL,
		&mTexture);
}

Sprite::~Sprite()
{
	if (mTexture)
		mTexture->Release();
}

void Sprite::Next()
{
	_Index = (_Index + _Count - 1) % _Count;
}

void Sprite::Render(int X, int Y)
{
	D3DXVECTOR3 position((float)X, (float)Y, 0);

	mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	mSpriteHandler->Draw(
		mTexture,
		&mSourceRect,
		NULL,
		&mPosition,
		D3DCOLOR_XRGB(255, 255, 255));
	mSpriteHandler->End();
}
