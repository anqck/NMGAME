#pragma once

#ifndef DemoScene_H
#define DemoScene_H
#include "IScene.h"
#include "AladdinGame.h"


class DemoScene : public IScene
{
public:
	DemoScene();
	DemoScene(AladdinGame *game);
	~DemoScene();

	 void Update(float DeltaTime);
	 void LoadResource();
	void OnKeyDown(int keyCode);
	void OnKeyUp(int keyCode);
	void ProcessInput();


protected:
	AladdinHelper	*mAladdinHelper;
	AladdinGame		*mGame;

};

#endif