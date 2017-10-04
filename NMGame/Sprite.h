#pragma once

#include "Global.h"

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

class Sprite {
protected:
	
	

	int _Index;								// Current sprite index
	int _Count;
	LPD3DXSPRITE			mSpriteHandler;
	LPDIRECT3DTEXTURE9		mTexture;
	D3DXIMAGE_INFO			mImageInfo;
	D3DXVECTOR3				mPosition;
	vector<RECT>			mListRect;			// Hình chữ nhật chứa các sprite
	RECT					mSourceRect;		// Hình chữ nhật chứ sprite cần vẽ
	D3DXVECTOR2				mScale;				// Phóng to, thu nhỏ sprite
	D3DXMATRIX				mMatrix;			// Ma trận hỗ trợ dời hình
	bool					isFlipVertical;		// Lât hình theo trục dọc

public:
	Sprite(LPD3DXSPRITE SpriteHandler, LPWSTR FilePath, D3DCOLOR transcolor, vector<RECT> listSourceRect);
	~Sprite();

	void Next(); // ???
	void Reset(); // ???
	void SetFrame(int frameIdx);

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 Position);
	void				SetPosition(int X, int Y);

	D3DXVECTOR2			GetScale();
	void				SetScale(D3DXVECTOR2 scale);
	void				SetScale(float x, float y);

	bool				IsFlipVertical();
	void				FlipVertical(bool flip_vertical);
	// Render current sprite at location (X,Y) at the target surface
	void Render();
	
};
