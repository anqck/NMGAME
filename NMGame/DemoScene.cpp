#include "DemoScene.h"

DemoScene::DemoScene()
{
}

DemoScene::DemoScene(AladdinGame * game)
{
	this->mGame = game;
	allowAttack = true;
}

DemoScene::~DemoScene()
{
}

void DemoScene::Update(float DeltaTime)
{
	//this->mAladdinHelper->Update(DeltaTime);	
	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		this->mAladdinHelperArr.at(i)->Update(DeltaTime);
	}
}

void DemoScene::Render(float DeltaTime)
{
	GLOBAL::GetDirectDevice()->StretchRect(
		this->mBackground,			// from 
		NULL,				// which portion?
		GLOBAL::GetBackBuffer(),		// to 
		NULL,				// which portion?
		D3DTEXF_NONE);


	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		this->mAladdinHelperArr.at(i)->Render(DeltaTime);
	}
}

void DemoScene::LoadResource()
{
	this->mBackground = CreateSurfaceFromFile(GLOBAL::GetDirectDevice(), L"Map\\Map1.PNG");

	D3DXIMAGE_INFO mImageInfo;
	D3DXGetImageInfoFromFile(L"temp.png", &mImageInfo);
	D3DXCreateTextureFromFileEx(GLOBAL::GetDirectDevice(), L"temp.png", mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&mImageInfo,
		NULL,
		&imagetex);

	D3DXVECTOR3 imagepos; //vector for the position of the sprite

	imagepos.x = 40.0f; //coord x of our sprite
	imagepos.y = 480.0f; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	D3DXVECTOR3 imagepos1; //vector for the position of the sprite

	imagepos1.x = 300.0f; //coord x of our sprite
	imagepos1.y = 480.0f; //coord y of out sprite
	imagepos1.z = 0.0f; //coord z of out sprite

	vector<D3DXVECTOR3> vPos;
	vPos.push_back(imagepos);
	vPos.push_back(imagepos1);

	//this->mAladdinHelper = new AladdinHelper(GLOBAL::GetSpriteHandler(), imagepos);

	this->mMainIdx = 0;
	this->mNumberOfSprite = 1;
	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		LPD3DXSPRITE temp;
		D3DXCreateSprite(GLOBAL::GetDirectDevice(), &temp);		
		this->mSpriteHandle.push_back(temp);


		this->mAladdinHelperArr.push_back(new AladdinCharacter(temp, vPos.at(i)));
	}
	


	//GLOBAL::SetSpriteHandler(mAladdinSpriteHandler);
}

void DemoScene::OnKeyDown(int keyCode)
{

	keys[keyCode] = true;
	//this->mAladdinHelperArr.at(mMainIdx)->setAllowStateChange(true);
	this->mAladdinHelperArr.at(mMainIdx)->OnKeyDown(keyCode);

}

void DemoScene::OnKeyUp(int keyCode)
{
	keys[keyCode] = false;
	this->mAladdinHelperArr.at(mMainIdx)->OnKeyUp(keyCode);
}

void DemoScene::ProcessInput()
{
	this->mAladdinHelperArr.at(mMainIdx)->ProcessInput(keys);	

}
