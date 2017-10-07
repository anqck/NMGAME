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
	this->mNumberOfSprite = 2;
	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		LPD3DXSPRITE temp;
		D3DXCreateSprite(GLOBAL::GetDirectDevice(), &temp);		
		this->mSpriteHandle.push_back(temp);


		this->mAladdinHelperArr.push_back(new AladdinHelper(temp, vPos.at(i)));
	}
	


	//GLOBAL::SetSpriteHandler(mAladdinSpriteHandler);
}

void DemoScene::OnKeyDown(int keyCode)
{
	//this->mAladdinHelperArr.at(mMainIdx)->setAllowStateChange(true);

	switch (keyCode)
	{
	case VK_SPACE:

		if (allowAttack && (this->mAladdinHelperArr.at(mMainIdx)->getAladdinState() != AladdinState::Attack1) && (this->mAladdinHelperArr.at(mMainIdx)->getAladdinState() != AladdinState::SitAttack))
		{
			allowAttack = false;
			this->mAladdinHelperArr.at(mMainIdx)->setAllowStateChange(true);

			if (this->mAladdinHelperArr.at(mMainIdx)->getAladdinState() == AladdinState::Sit)
				this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::SitAttack);
			else
  				this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::Attack1);
		}
		break;
	default:
		this->mAladdinHelperArr.at(mMainIdx)->setAllowStateChange(true);
		break;
	}
}

void DemoScene::OnKeyUp(int keyCode)
{

	if (keyCode == VK_SPACE)
	{
		allowAttack = true;
		
	}
}

void DemoScene::ProcessInput()
{

	if (this->mGame->IsKeyDown(DIK_RIGHT))
	{
	 this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelperArr.at(mMainIdx)->setDirection(Direction::Right);
	
	}
	else if (this->mGame->IsKeyDown(DIK_LEFT))
	{
	 this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::Walk);
	 this->mAladdinHelperArr.at(mMainIdx)->setDirection(Direction::Left);

	}
	else if (this->mGame->IsKeyDown(DIK_UP))
	{
	 this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::LookUp);
	}
	else if (this->mGame->IsKeyDown(DIK_DOWN))
	{
		
			this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::Sit);
	}
	else if (this->mGame->IsKeyDown(VK_SPACE))
	{
		
		
	}
	else
	{
	 this->mAladdinHelperArr.at(mMainIdx)->setAladdinState(AladdinState::DoNothing);

	}
}
