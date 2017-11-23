#include "LevelComplete.h"

IntroScene::IntroScene()
{
	Option = 0;

}
IntroScene::~IntroScene()
{
}

void IntroScene::Update(float DeltaTime)
{
	_menuselect->Update(DeltaTime);

	Option = (Option > 5 ? 0 : Option);
	Option = (Option < 0 ? 5 : Option);

	_menuselect->SetPosition(_menuselect->GetPosition().x, 270 - Between.y*Option);

}

void IntroScene::Render(float DeltaTime)
{

	//GraphicsHelper::GetInstance()->GetDirectDevice()->StretchRect(
	//	this->BackGround,			// from 
	//	NULL,				// which portion?
	//	GraphicsHelper::GetInstance()->GetBackBuffer(),		// to 
	//	NULL,				// which portion?
	//	D3DTEXF_NONE);

	//ve backgroud
	GraphicsHelper::GetInstance()->DrawSurface(this->BackGround, NULL, NULL);
	//GraphicsHelper::GetInstance()->DrawTexture(this->Title, MyRECT(0,0,90,90), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(0, 0), D3DXVECTOR2(0, 0), 0.0f, D3DXVECTOR2(0, 0));

	//ve title
	GraphicsHelper::GetInstance()->DrawTexture(this->Title, MyRECT(0, 0, TitleInfo.Width, TitleInfo.Height), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3((BackGroundInfo.Width - TitleInfo.Width / 2), 30, 0), D3DXVECTOR2(1.5, 1.5));

	//ve menu
	//GraphicsHelper::GetInstance()->DrawTexture(this->ABC,BANGCHUCAI.at(KYTU::B) , D3DXVECTOR3(0, 0, 0), D3DXVECTOR3((BackGroundInfo.Width - TitleInfo.Width / 2), 490, 0), D3DXVECTOR2(1.5, 1.5));

	Inchuoi(D3DXVECTOR3(200, 300, 0), Between, D3DXVECTOR2(1.5, 1.5));

	//GraphicsHelper::GetInstance()->DrawTexture(this->menuselect, MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height), D3DXVECTOR3(0, 0, 0), menuselectPos, D3DXVECTOR2(2,2));

	_menuselect->Render();

}

void IntroScene::LoadResource()
{
	Camera::GetInstance()->SetPosition(0, GLOBAL::GetWindowsHeight());

	//menuselectPos = D3DXVECTOR3(100, 300, 0);
	Between = D3DXVECTOR2(20, 50);
	D3DXGetImageInfoFromFile(L"Map\\menu.PNG", &BackGroundInfo);
	this->BackGround = CreateSurfaceFromFile(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\menu.PNG");

	//this->Title = new Sprite(L"Map\\title.PNG", D3DCOLOR_XRGB(255, 0, 255),NULL, CenterArchor::TopLeft);

	D3DXGetImageInfoFromFile(L"Map\\title.PNG", &TitleInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\title.PNG", TitleInfo.Width,
		TitleInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&TitleInfo,
		NULL,
		&Title);

	D3DXGetImageInfoFromFile(L"Map\\ABC.PNG", &ABCInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\ABC.PNG", ABCInfo.Width,
		ABCInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&ABCInfo,
		NULL,
		&ABC);


	D3DXGetImageInfoFromFile(L"Map\\menuselect.PNG", &menuselectInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\menuselect.PNG", menuselectInfo.Width,
		menuselectInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&menuselectInfo,
		NULL,
		&menuselect);

	vector<MyRECT> temp;

	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(2, 0, 0)));
	//temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(6, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(8, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(6, 0, 0)));
	//temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(4, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(2, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(0, 0, 0)));
	temp.push_back(MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height, D3DXVECTOR3(0, 0, 0)));



	this->_menuselect = new ObjectStateWithLoop(temp, 60, L"Map\\menuselect.PNG", D3DXVECTOR2(0.0f, 0.0f), 0, CenterArchor::CenterBottom);
	temp.clear();
	_menuselect->SetPosition(D3DXVECTOR3(100, 270, 0));




}
void IntroScene::OnKeyDown(int keyCode)
{

	switch (keyCode)
	{
	case VK_UP:

		Option--;
		break;
	case VK_DOWN:
		Option++;
		break;
	case VK_RETURN:

		//if (Option == 5) {
		//this->AddScene(scene);

		//}
		break;
	case VK_ESCAPE:
		PostMessage(GLOBAL::GetHWND(), WM_CLOSE, 0, 0);
	}

}

void IntroScene::OnKeyUp(int keyCode)
{
}

void IntroScene::ProcessInput()
{

}

void IntroScene::CheckCollision(float DeltaTime)
{
}
