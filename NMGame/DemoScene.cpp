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

	this->mAladdinHelper->Update(DeltaTime);
	Camera::GetInstance()->Update(this->mAladdinHelper);

	//mCamel->Update(DeltaTime);
	

	mListObjectInViewPort = mQuadTree->GetListObjectInViewport(Camera::GetInstance()->GetBoundingBoxInWorldAxis());

	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		mListObjectInViewPort.at(i)->Update(DeltaTime);
	}
}

void DemoScene::Render(float DeltaTime)
{
	
	LPDIRECT3DSURFACE9			_Surface;
	GraphicsHelper::GetInstance()->GetDirectDevice()->CreateOffscreenPlainSurface(
		100,
		100,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&_Surface,
		NULL);

	GraphicsHelper::GetInstance()->GetDirectDevice()->ColorFill(_Surface, NULL, D3DCOLOR_XRGB(0, 0, 0));

	GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(_Surface,	NULL, GraphicsHelper::GetInstance()->GetBackBuffer(),	NULL,D3DTEXF_NONE);


	this->mMap->Render(DeltaTime,MapLevel::MapLevel1);

	//this->mCamel->Render(DeltaTime);

	
	for (int i = 0; i < mListObjectInViewPort.size(); i++)
	{
		mListObjectInViewPort.at(i)->Render(DeltaTime);
	}

	this->mAladdinHelper->Render(DeltaTime);



	//mCamel->Render(DeltaTime);

	
	this->mMap->Render(DeltaTime, MapLevel::MapLevel2);

}

void DemoScene::LoadResource()
{
	this->mMap = new DemoMap();

	
	D3DXVECTOR3 imagepos; //vector for the position of the sprite

	imagepos.x = 100.0f; //coord x of our sprite
	imagepos.y = WORLD_Y - MAP_HEIGHT + 160; //coord y of out sprite
	imagepos.z = 0.0f; //coord z of out sprite

	this->mAladdinHelper = new AladdinCharacter(imagepos);

	//mCamel = new Camel(D3DXVECTOR3(500, WORLD_Y - MAP_HEIGHT + 90,0));

	Camera::GetInstance()->SetPosition(100.0f, WORLD_Y - MAP_HEIGHT + 90 );

	mQuadTree = new QuadTree();

	mQuadTree->LoadQuadTree("Map//1.txt");

	//this->mCamel = new Camel(imagepos);
	

}

void DemoScene::OnKeyDown(int keyCode)
{

	this->mAladdinHelper->OnKeyDown(keyCode);

}

void DemoScene::OnKeyUp(int keyCode)
{

	this->mAladdinHelper->OnKeyUp(keyCode);
}

void DemoScene::ProcessInput()
{
	this->mAladdinHelper->ProcessInput();
}
