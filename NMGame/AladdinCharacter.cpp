#include "AladdinCharacter.h"

AladdinCharacter::AladdinCharacter()
{
	this->mPosition = D3DXVECTOR3(0, 0, 0);
	this->mVelocity = D3DXVECTOR2(0, 0);
}

AladdinCharacter::~AladdinCharacter()
{
	if (this->mSprite)
		delete(this->mSprite);
}

void AladdinCharacter::Draw()
{
	this->mSprite->Render();
}

D3DXVECTOR3 AladdinCharacter::GetPosition()
{
	return this->mPosition;
}

D3DXVECTOR2 AladdinCharacter::GetVelocity()
{
	return this->mVelocity;
}

void AladdinCharacter::SetVelocity(D3DXVECTOR2 Velocity)
{
	this->mVelocity = Velocity;
}

void AladdinCharacter::SetVelocity(int X, int Y)
{
	this->mVelocity.x = X;
	this->mVelocity.y = Y;
}

void AladdinCharacter::LoadResource()
{
}

void AladdinCharacter::SetPosition(D3DXVECTOR3 Position)
{
	this->mPosition = Position;
}

void AladdinCharacter::SetPosition(int X, int Y)
{
	this->mPosition.x = X;
	this->mPosition.y = Y;
}
