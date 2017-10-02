#include "Sprite.h"

Sprite::Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR FilePath, D3DCOLOR transcolor, vector<RECT> listSourceRect)
{
	mSpriteHandler = SpriteHandler;
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mListRect = listSourceRect;
	this->_Index = 0;

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

	this->_Count = 13;
	

}

Sprite::~Sprite()
{
	if (mTexture)
		mTexture->Release();
}

void Sprite::Next()
{
	_Index = (_Index + _Count - 1) % _Count;
	mSourceRect = mListRect.at(_Index);
}

void Sprite::Reset()
{
	_Index = 0;
	mSourceRect = mListRect.at(_Index);
}

D3DXVECTOR3 Sprite::GetPosition()
{
	return this->mPosition;
}

void Sprite::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
}

void Sprite::SetPosition(int X, int Y)
{
	 D3DXVECTOR3 position((float)X, (float)Y, 0);
	 this->mPosition = position;
}

D3DXVECTOR2 Sprite::GetScale()
{
	return this->mScale;
}

void Sprite::SetScale(D3DXVECTOR2 scale)
{
	this->mScale = scale;
}

void Sprite::SetScale(float x, float y)
{
	this->mScale = D3DXVECTOR2(x, y);
}

void Sprite::Render()
{
	mSpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	mSpriteHandler->Draw(
		mTexture,
		&mSourceRect,
		NULL,
		&mPosition,
		D3DCOLOR_XRGB(255, 255, 255));
	mSpriteHandler->End();
}
