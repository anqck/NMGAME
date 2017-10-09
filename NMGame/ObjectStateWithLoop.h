#pragma once

#include "ObjectState.h"

class ObjectStateWithLoop : public ObjectState
{
public:
	ObjectStateWithLoop(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity) : ObjectState(rect, Animate_rate, filePath, velocity) { mStartLoopIdx = 0; };
	ObjectStateWithLoop(std::vector<MyRECT> rect, int Animate_rate, LPWSTR filePath, D3DXVECTOR2 velocity, int startLoop) : ObjectState(rect, Animate_rate, filePath, velocity) { mStartLoopIdx = startLoop; };

	void	nextFrame() override;
protected:

	int					mStartLoopIdx;		//Index bắt đầu của các Rect chứa các Sprite

	bool				flagLoop;
};