#include "DieScene.h"
#include "Camera.h"

DieScene::DieScene()
{
	LoadResource();

	mOpacityRender = false;
	mOpacity = 255;

	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight() );

	mDone = false;

	this->mSceneID = SceneID::SceneID_DieScene;
}

DieScene::DieScene(AladdinGame * game) : DieScene()
{

}

DieScene::~DieScene()
{
}

void DieScene::Update(float DeltaTime)
{
	for (int i = 0; i < this->mObject.size(); i++)
	{
		this->mObject.at(i)->Update(DeltaTime);
	}

	if (!mOpacityRender)
	{
		if (this->mObject.at(1)->GetCurrentIdx() >= 20)
		{
			mOpacityRender = true;
		}
	}
	
	
}

void DieScene::Render(float DeltaTime)
{
	
	

	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface, NULL, GraphicsHelper::GetInstance()->GetBackBuffer(), NULL, D3DTEXF_NONE);

	for (int i = 0; i < this->mObject.size(); i++)
	{

			this->mObject.at(i)->OpacityRender(D3DCOLOR_ARGB(mOpacity, 255, 255, 255));

			if (mOpacityRender && mOpacity>= 5)
			{
				mOpacity -= 15;
			}
			else
			{
				if(mOpacity <= 0)
					mDone = true;
			}
	}
}

void DieScene::LoadResource()

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


	//DoNothing	
	temp.push_back(MyRECT(0, 0, 68, 29, D3DXVECTOR3(-2, 0, 0)));
	temp.push_back(MyRECT(55, 64, 121, 91, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(79, 0, 57, 123, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(0, 69, 127, 54, D3DXVECTOR3(1, 0, 0)));
	temp.push_back(MyRECT(0, 128, 179, 53, D3DXVECTOR3(4, -1, 0)));
	temp.push_back(MyRECT(30, 0, 63, 78));
	this->mObject.push_back(new ObjectStateWithLoop(temp, 12, L"Object\\Monkey.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mObject.at(0)->SetPosition(D3DXVECTOR3(500, 300, 0));

	//ThanDen
	temp.push_back(MyRECT(0, 0, 80, 48));
	temp.push_back(MyRECT(54, 303, 364, 105,D3DXVECTOR3(5,0,0)));
	temp.push_back(MyRECT(159, 210, 255, 217, D3DXVECTOR3(12, 0, 0)));
	temp.push_back(MyRECT(106, 277, 322, 164, D3DXVECTOR3(10, 0, 0)));
	temp.push_back(MyRECT(109, 365, 404, 159, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(165, 297, 337, 216, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(108, 442, 477, 159, D3DXVECTOR3(5, 1, 0)));
	temp.push_back(MyRECT(109, 405, 441, 160, D3DXVECTOR3(6, 1, 0)));
	temp.push_back(MyRECT(56, 410, 449, 105, D3DXVECTOR3(6, 1, 0)));
	temp.push_back(MyRECT(52, 365, 409, 108, D3DXVECTOR3(2, -1, 0)));
	temp.push_back(MyRECT(106, 323, 364, 159, D3DXVECTOR3(0, 1, 0)));
	temp.push_back(MyRECT(0, 471, 510, 50, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(165, 256, 296, 216, D3DXVECTOR3(8, -1, 0)));
	temp.push_back(MyRECT(56, 450, 487, 107));
	temp.push_back(MyRECT(160, 338, 375, 217));
	temp.push_back(MyRECT(0, 427, 470, 55));
	temp.push_back(MyRECT(0, 303, 364, 53));
	temp.push_back(MyRECT(0, 365, 426, 51));
	temp.push_back(MyRECT(0, 159, 235, 83));
	temp.push_back(MyRECT(0, 81, 158, 85));
	temp.push_back(MyRECT(49, 0, 75, 134));
	temp.push_back(MyRECT(135, 0, 68, 218));
	temp.push_back(MyRECT(86, 76, 142, 167));
	temp.push_back(MyRECT(86, 143, 209, 160));
	temp.push_back(MyRECT(168, 69, 135, 242));
	temp.push_back(MyRECT(168, 136, 202, 242));
	temp.push_back(MyRECT(0, 236, 302, 74));
	temp.push_back(MyRECT(84, 210, 276, 158));
	temp.push_back(MyRECT(168, 69, 135, 242));
	temp.push_back(MyRECT(168, 136, 202, 242));
	temp.push_back(MyRECT(0, 236, 302, 74));
	temp.push_back(MyRECT(84, 210, 276, 158));
	temp.push_back(MyRECT(168, 69, 135, 242));
	temp.push_back(MyRECT(168, 136, 202, 242));
	temp.push_back(MyRECT(0, 236, 302, 74));
	temp.push_back(MyRECT(84, 210, 276, 158));
	this->mObject.push_back(new ObjectState(temp, 12, L"Object\\ThanDen.png", D3DXVECTOR2(0, 0), CenterArchor::CenterBottom));
	temp.clear();

	this->mObject.at(1)->SetPosition(D3DXVECTOR3(340, 300, 0));
}

void DieScene::OnKeyDown(int keyCode)
{
	
}

void DieScene::OnKeyUp(int keyCode)
{
}

void DieScene::ProcessInput()
{
	if (KeyboardHelper::GetInstance()->IsKeyDown(DIK_S) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_A) || KeyboardHelper::GetInstance()->IsKeyDown(DIK_D) )
	{
		mOpacityRender = true;
	}
}

//bool DieScene::isDone()
//{
//	return mDone;
//}

