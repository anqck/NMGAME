#pragma once

#include "ObjectState.h"

class ObjectStateWithLoop : public ObjectState
{
public:
	ObjectStateWithLoop(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, CenterArchor center = CenterArchor::TopLeft) : ObjectState(rect, Animate_rate, filePath, velocity, center) { mStartLoopIdx = 0; };
	ObjectStateWithLoop(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, int startLoop, CenterArchor center = CenterArchor::TopLeft) : ObjectState(rect, Animate_rate, filePath, velocity, center) { mStartLoopIdx = startLoop; };

	void				nextFrame() override;

	bool				isDone();
protected:

	int					mStartLoopIdx;		//Index bắt đầu của các Rect chứa các Sprite

	bool				flagLoop;
};