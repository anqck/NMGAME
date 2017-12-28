#include "IntroScene1.h"
#include "Camera.h"

IntroScene1::IntroScene1()
{
	this->mOpacity = 0;
	this->mOpacityRender = false;

	this->mSceneID = SceneID::SceneID_IntroScene1;

	SoundHelper::GetInstance()->Stop();

	LoadResource();

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());


	mCurrentIdx = 0;

	mDone = false;
}

IntroScene1::IntroScene1(AladdinGame * game)
{
}

IntroScene1::~IntroScene1()
{
}

void IntroScene1::LoadResource()
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
		100,
		100,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_Surface,
		NULL);

	GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

	vector<MyRECT> temp;

	//Background
	temp.push_back(MyRECT(0, 0, 320, 240));
	temp.push_back(MyRECT(241, 0, 320, 481));
	temp.push_back(MyRECT(0, 321, 641, 240));
	temp.push_back(MyRECT(241, 321, 641, 481));
	temp.push_back(MyRECT(0, 642, 962, 240));
	temp.push_back(MyRECT(241, 642, 962, 481));
	temp.push_back(MyRECT(482, 0, 320, 722));
	temp.push_back(MyRECT(723, 0, 320, 963));
	temp.push_back(MyRECT(482, 321, 641, 722));
	temp.push_back(MyRECT(723, 321, 641, 963));
	temp.push_back(MyRECT(482, 642, 962, 722));
	temp.push_back(MyRECT(723, 642, 962, 963));
	temp.push_back(MyRECT(0, 963, 1283, 240));
	temp.push_back(MyRECT(241, 963, 1283, 481));
	temp.push_back(MyRECT(0, 1284, 1604, 240));
	temp.push_back(MyRECT(482, 963, 1283, 722));
	temp.push_back(MyRECT(241, 1284, 1604, 481));
	temp.push_back(MyRECT(0, 1605, 1925, 240));
	temp.push_back(MyRECT(723, 963, 1283, 963));
	temp.push_back(MyRECT(482, 1284, 1604, 722));
	temp.push_back(MyRECT(241, 1605, 1925, 481));
	temp.push_back(MyRECT(723, 1284, 1604, 963));
	temp.push_back(MyRECT(482, 1605, 1925, 722));
	temp.push_back(MyRECT(723, 1605, 1925, 963));


	temp.push_back(MyRECT(241, 642, 962, 481));
	temp.push_back(MyRECT(482, 0, 320, 722));
	temp.push_back(MyRECT(723, 0, 320, 963));
	temp.push_back(MyRECT(482, 321, 641, 722));
	temp.push_back(MyRECT(723, 321, 641, 963));
	temp.push_back(MyRECT(482, 642, 962, 722));
	temp.push_back(MyRECT(723, 642, 962, 963));
	temp.push_back(MyRECT(0, 963, 1283, 240));
	temp.push_back(MyRECT(241, 963, 1283, 481));
	temp.push_back(MyRECT(0, 1284, 1604, 240));
	temp.push_back(MyRECT(482, 963, 1283, 722));
	temp.push_back(MyRECT(241, 1284, 1604, 481));
	temp.push_back(MyRECT(0, 1605, 1925, 240));
	temp.push_back(MyRECT(723, 963, 1283, 963));
	temp.push_back(MyRECT(482, 1284, 1604, 722));
	temp.push_back(MyRECT(241, 1605, 1925, 481));
	temp.push_back(MyRECT(723, 1284, 1604, 963));
	temp.push_back(MyRECT(482, 1605, 1925, 722));
	temp.push_back(MyRECT(723, 1605, 1925, 963));
	temp.push_back(MyRECT(241, 642, 962, 481));
	temp.push_back(MyRECT(482, 0, 320, 722));
	temp.push_back(MyRECT(723, 0, 320, 963));
	temp.push_back(MyRECT(482, 321, 641, 722));
	temp.push_back(MyRECT(723, 321, 641, 963));
	temp.push_back(MyRECT(482, 642, 962, 722));
	temp.push_back(MyRECT(723, 642, 962, 963));
	temp.push_back(MyRECT(0, 963, 1283, 240));
	temp.push_back(MyRECT(241, 963, 1283, 481));
	temp.push_back(MyRECT(0, 1284, 1604, 240));
	temp.push_back(MyRECT(482, 963, 1283, 722));
	temp.push_back(MyRECT(241, 1284, 1604, 481));
	temp.push_back(MyRECT(0, 1605, 1925, 240));
	temp.push_back(MyRECT(723, 963, 1283, 963));
	temp.push_back(MyRECT(482, 1284, 1604, 722));
	temp.push_back(MyRECT(241, 1605, 1925, 481));
	temp.push_back(MyRECT(723, 1284, 1604, 963));
	temp.push_back(MyRECT(482, 1605, 1925, 722));
	temp.push_back(MyRECT(723, 1605, 1925, 963));
	this->mBackground.push_back(new ObjectState(temp, 12, L"Object\\Scene\\IntroScene1\\1.png", D3DXVECTOR2(0, 0), CenterArchor::TopLeft, D3DXVECTOR2(GLOBAL::GetWindowsWidth() / 320.0, GLOBAL::GetWindowsHeight() / 240.0)));
	temp.clear();




	this->mBackground.at(0)->SetPosition(0, GLOBAL::GetWindowsHeight());
}

void IntroScene1::Update(float DeltaTime)
{
	this->mBackground.at(0)->Update(DeltaTime);


	if (this->mBackground.at(0)->isDone())
		mOpacityRender = true;

	if (mOpacityRender)
	{
		if (mOpacity >= 5)
		{
			mOpacity -= 15;
		}
		else
		{
			if (mOpacity <= 0)
			{
				mDone = true;
			}
		}
	}
	else
	{
		if (mOpacity < 255)
			mOpacity += 15;
	}
	
}

void IntroScene1::Render(float DeltaTime)
{
	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);


	this->mBackground.at(0)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));
}

bool IntroScene1::isDone()
{
	return mDone;
}

void IntroScene1::OnKeyDown(int keyCode)
{
}

void IntroScene1::OnKeyUp(int keyCode)
{
}

void IntroScene1::ProcessInput()
{
	if ((KeyboardHelper::GetInstance()->IsKeyDown(DIK_S) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_A) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_D)) && this->mBackground.at(0)->GetCurrentIdx() >= 15)
	{
		mOpacityRender = true;
	}
}
