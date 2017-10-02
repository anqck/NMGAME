#pragma once
#include "Game.h"

class AladdinGame :public GAME
{
public:
	AladdinGame(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate) : GAME(hInstance, Name, windowsWidth, windowsHeight, IsFullScreen, FrameRate) {};
	~AladdinGame();
protected:
	LPDIRECT3DSURFACE9			mBackground;
	LPD3DXSPRITE				mAladdin;
	LPDIRECT3DTEXTURE9 imagetex;
	LPD3DXSPRITE sprite; //sprite to display our image
	D3DXVECTOR3 imagepos; //vector for the position of the sprite


	virtual void				LoadResource();
	virtual void				RenderFrame();
};