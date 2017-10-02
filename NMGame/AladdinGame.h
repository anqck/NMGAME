#pragma once
#include "Game.h"
#include "Sprite.h"

class AladdinGame :public GAME
{
public:
	AladdinGame(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate) : GAME(hInstance, Name, windowsWidth, windowsHeight, IsFullScreen, FrameRate) {};
	~AladdinGame();

	virtual void			ProcessInput(int Delta);
protected:
	LPDIRECT3DSURFACE9		mBackground;
	LPD3DXSPRITE			mAladdin;

	Sprite					*mSprite;

	LPDIRECT3DTEXTURE9 imagetex;
	LPD3DXSPRITE sprite; //sprite to display our image
	D3DXVECTOR3 imagepos; //vector for the position of the sprite


	virtual void			LoadResource();
	virtual void			RenderFrame(int Delta);
	virtual void			OnKeyDown(int KeyCode);
};