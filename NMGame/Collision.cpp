#include "Collision.h"

Collision*				Collision::mInstance = NULL;

Collision * Collision::GetInstance()
{
	if (!mInstance)
		Collision::mInstance = new Collision();
	return Collision::mInstance;
}
