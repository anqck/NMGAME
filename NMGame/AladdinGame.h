#pragma once
#ifndef AladdinGame_H
#define AladdinGame_H
#include "Game.h"
#include "Sprite.h"
#include "AladdinHelper.h"
#include "SceneManager.h"

#include <vector>

class AladdinGame :public GAME
{
public:
	AladdinGame(HINSTANCE hInstance, LPWSTR Name, int windowsWidth, int windowsHeight, int IsFullScreen, int FrameRate) : GAME(hInstance, Name, windowsWidth, windowsHeight, IsFullScreen, FrameRate) {};
	~AladdinGame();

	
protected:
	LPD3DXSPRITE			mAladdinSpriteHandler;
	


	


	float kitty_vx_last;  // last vx of kitty before stop ( to determine the direction of kitty )
	DWORD last_time;	 // this is to control the animate rate of kitty


	virtual void			ProcessInput(int Delta);
	virtual void			LoadResource();
	void					Update(float DeltaTime) ;
	virtual void			RenderFrame(float Delta);
	virtual void			OnKeyDown(int KeyCode);
};

#endif