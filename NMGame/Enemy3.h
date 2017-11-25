#pragma once
#include "Enemy.h"

enum Eneymy3State
{
	Eneymy3State_Normal,
	Eneymy3State_Explosion
};
class Enemy3 : public Enemy 
{
public:
	Enemy3();
	Enemy3(MyRECT bb, D3DXVECTOR3 pos) ;
	~Enemy3();

	void						Update(float DeltaTime);
	void						Render(float DeltaTime);

private:
	Eneymy3State				mCurrentState;


};