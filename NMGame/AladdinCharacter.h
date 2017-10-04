#pragma once
#include "Global.h"
#include "Sprite.h"

class AladdinCharacter
{
public:
	AladdinCharacter();
	AladdinCharacter(LPD3DXSPRITE SpriteHandle);
	AladdinCharacter(LPD3DXSPRITE SpriteHandle, D3DXVECTOR3 Position);
	AladdinCharacter(LPD3DXSPRITE SpriteHandle, int X, int Y);
	~AladdinCharacter();

	void			Draw();			//
	void			Animate();
	void			Move(int delta_time);
	void			nextFrame();
	void			resetFrame();

	D3DXVECTOR3			GetPosition();
	void				SetPosition(D3DXVECTOR3 Position);
	void				SetPosition(int X, int Y);

	D3DXVECTOR2			GetVelocity();
	void				SetVelocity(D3DXVECTOR2 Velocity);
	void				SetVelocity(float X, float Y);

protected:
	Sprite*				mSprite;
	LPD3DXSPRITE		mSpriteHandle;
	int					mStartIdx;		//Index bắt đầu của các Rect chứa các Sprite
	int					mEndIdx;		//
	int					mCurrentIdx;	//Index hiện tại
	D3DXVECTOR3			mPosition;		//Vị trí của Aladdin
	D3DXVECTOR2			mVelocity;		//Vận tốc của Aladdin
	DWORD last_time;	 // this is to control the animate rate of kitty
	int ANIMATE_RATE;
	




};