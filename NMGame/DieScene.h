#pragma once

#ifndef DieScene_H
#define DieScene_H
#include "IScene.h"
#include "AladdinGame.h"

using namespace std;

class DieScene : public IScene
{
public:
	DieScene();
	DieScene(AladdinGame *game);
	~DieScene();

	void					Update(float DeltaTime);
	void					Render(float DeltaTime);
	void					LoadResource();

	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();

	bool					isDone();


protected:
	vector<ObjectState*>	mObject;
	bool					mOpacityRender;
	int						mOpacity;

	bool					mDone;

	LPDIRECT3DSURFACE9			_Surface;
};

#endif