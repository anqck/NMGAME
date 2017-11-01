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
	this->mCamel->Update(DeltaTime);
	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		this->mAladdinHelperArr.at(i)->Update(DeltaTime);
	}
}

void DemoScene::Render(float DeltaTime)
{
	

	this->mMap->Render(DeltaTime);

	this->mCamel->Render(DeltaTime);

	
	this->mAladdinHelperArr.at(0)->Render(DeltaTime);

	

	/*for (int i = 0; i < this->mNumberOfSprite; i++)
	{
		this->mAladdinHelperArr.at(i)->Render(DeltaTime);
	}*/
}

void DemoScene::LoadResource()
{
	this->mMap = new DemoMap();
	
	D3DXVECTOR3 imagepos; //vector for the position of the sprite

	imagepos.x = 40.0f; //coord x of our sprite
	imagepos.y = 580.0f; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	D3DXVECTOR3 imagepos1; //vector for the position of the sprite

	imagepos1.x = 300.0f; //coord x of our sprite
	imagepos1.y = 480.0f; //coord y of out sprite
	imagepos1.z = 0.0f; //coord z of out sprite

	vector<D3DXVECTOR3> vPos;
	vPos.push_back(imagepos);
	vPos.push_back(imagepos1);
	
	this->mMainIdx = 0;
	this->mNumberOfSprite = 1;

	

	for (int i = 0; i < this->mNumberOfSprite; i++)
	{
				this->mAladdinHelperArr.push_back(new AladdinCharacter(GLOBAL::GetSpriteHandler(), vPos.at(i)));
	}

	this->mCamel = new Camel(imagepos1);
	

}

void DemoScene::OnKeyDown(int keyCode)
{


	//this->mAladdinHelperArr.at(mMainIdx)->setAllowStateChange(true);
	this->mAladdinHelperArr.at(mMainIdx)->OnKeyDown(keyCode);

}

void DemoScene::OnKeyUp(int keyCode)
{

	this->mAladdinHelperArr.at(mMainIdx)->OnKeyUp(keyCode);
}

void DemoScene::ProcessInput()
{
	this->mAladdinHelperArr.at(mMainIdx)->ProcessInput();	

}
