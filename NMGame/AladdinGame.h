#pragma once
#ifndef AladdinGame_H
#define AladdinGame_H
#include "Game.h"
#include "Sprite.h"
#include "AladdinHelper.h"

#include "SceneManager.h"

class AladdinGame :public GAME
{
public:
	AladdinGame(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate) : GAME(hInstance, Name, windowsWidth, windowsHeight, IsFullScreen, FrameRate) {};
	~AladdinGame();

	
protected:
	LPDIRECT3DSURFACE9		mBackground;
	LPD3DXSPRITE			mAladdinSpriteHandler;
	


	LPDIRECT3DTEXTURE9 imagetex;



	float kitty_vx;		// velocity of kitty
	float kitty_vy;

	float kitty_vx_last;  // last vx of kitty before stop ( to determine the direction of kitty )
	DWORD last_time;	 // this is to control the animate rate of kitty


	virtual void			ProcessInput(int Delta);
	virtual void			LoadResource();
	virtual void			RenderFrame(int Delta);
	virtual void			OnKeyDown(int KeyCode);
};

#endif