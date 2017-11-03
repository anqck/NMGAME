#include "Sprite.h"

Sprite::Sprite( LPWSTR FilePath, D3DCOLOR transcolor, vector<MyRECT> listSourceRect)
{

	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mListRect = listSourceRect;
	mSourceRect = listSourceRect.at(0);

	this->isFlipVertical = false;

	D3DXGetImageInfoFromFile(FilePath, &mImageInfo);

	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), FilePath, mImageInfo.Width,
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


void Sprite::SetFrame(int frameIdx)
{
	mSourceRect = mListRect.at(frameIdx);
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

bool Sprite::IsFlipVertical()
{
	return this->isFlipVertical;
}

void Sprite::FlipVertical(bool flip_vertical)
{
	this->isFlipVertical = flip_vertical;
}

void Sprite::Render()
{
	//Temp code
	D3DXVECTOR2 tempScale = D3DXVECTOR2(((isFlipVertical)?-1:1) * 2, 2.5);

	D3DXVECTOR3 center = D3DXVECTOR3((this->mSourceRect.right - this->mSourceRect.left) / 2, (this->mSourceRect.bottom - this->mSourceRect.top), 0);

	GraphicsHelper::GetInstance()->DrawTexture(mTexture, this->mSourceRect, center, this->mPosition, tempScale);


}
