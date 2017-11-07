#pragma once

#include "Global.h"
#include "MyRECT.h"
#include "GraphicsHelper.h"

#include "ViewPort.h"


#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

using namespace std;

class Sprite {
protected:
	
	

	int _Index;								// Current sprite index
	int _Count;

	LPDIRECT3DTEXTURE9		mTexture;
	D3DXIMAGE_INFO			mImageInfo;
	D3DXVECTOR3				mPosition;
	vector<MyRECT>			mListRect;			// Hình chữ nhật chứa các sprite
	MyRECT					mSourceRect;		// Hình chữ nhật chứ sprite cần vẽ
	D3DXVECTOR2				mScale;				// Phóng to, thu nhỏ sprite

	bool					isFlipVertical;		// Lât hình theo trục dọc

public:
	Sprite( LPWSTR FilePath, D3DCOLOR transcolor, vector<MyRECT> listSourceRect);
	~Sprite();

	void SetFrame(int frameIdx);

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 Position);
	void				SetPosition(int X, int Y);

	D3DXVECTOR2			GetScale();
	void				SetScale(D3DXVECTOR2 scale);
	void				SetScale(float x, float y);

	MyRECT				GetSourceRect();

	bool				IsFlipVertical();
	void				FlipVertical(bool flip_vertical);
	// Render current sprite at location (X,Y) at the target surface
	void				 Render();
	
};
