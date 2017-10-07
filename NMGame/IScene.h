#pragma once
#ifndef IScene_H
#define IScene_H




//Interface contact between "Game" class and "GameSence" class
class IScene
{
public:
	//public virtual method for class "Game" call
	virtual void Update(float DeltaTime) = 0;
	virtual void ProcessInput() = 0;
	virtual void OnKeyDown(int keyCode) = 0;
	virtual void OnKeyUp(int keyCode) = 0;
	virtual void LoadResource() = 0;

	
	//virtual bool IsDead() = 0;
};


#endif