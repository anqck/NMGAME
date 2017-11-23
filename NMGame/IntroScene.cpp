#include "IntroScene.h"

void IntroScene::Update(float DeltaTime)
{
	
	menuselectPos.x += 2;
	if (menuselectPos.x == 120) menuselectPos.x=100;
	
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
	GraphicsHelper::GetInstance()->DrawTexture(this->Title, MyRECT(0, 0, TitleInfo.Width, TitleInfo.Height), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3((BackGroundInfo.Width-TitleInfo.Width/2),30,0),D3DXVECTOR2(1.5,1.5));
	
	//ve menu
	//GraphicsHelper::GetInstance()->DrawTexture(this->ABC,BANGCHUCAI.at(KYTU::B) , D3DXVECTOR3(0, 0, 0), D3DXVECTOR3((BackGroundInfo.Width - TitleInfo.Width / 2), 490, 0), D3DXVECTOR2(1.5, 1.5));
	
	Inchuoi(D3DXVECTOR3(200, 300, 0), Between, D3DXVECTOR2(1.5,1.5));

	GraphicsHelper::GetInstance()->DrawTexture(this->menuselect, MyRECT(0, 0, menuselectInfo.Width, menuselectInfo.Height), D3DXVECTOR3(0, 0, 0), menuselectPos, D3DXVECTOR2(2,2));


}

void IntroScene::LoadResource()
{
	menuselectPos = D3DXVECTOR3(100, 300, 0);
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

	BANGCHUCAI.push_back(MyRECT(17, 15, 29, 31));
	BANGCHUCAI.push_back(MyRECT(47, 113, 119, 61));
	BANGCHUCAI.push_back(MyRECT(47, 73, 83, 61));
	BANGCHUCAI.push_back(MyRECT(0, 118, 126, 14));
	BANGCHUCAI.push_back(MyRECT(15, 90, 102, 29));
	BANGCHUCAI.push_back(MyRECT(47, 84, 94, 61));
	BANGCHUCAI.push_back(MyRECT(15, 103, 115, 29));
	BANGCHUCAI.push_back(MyRECT(30, 101, 111, 44));
	BANGCHUCAI.push_back(MyRECT(15, 116, 126, 29));
	BANGCHUCAI.push_back(MyRECT(30, 88, 100, 44));
	BANGCHUCAI.push_back(MyRECT(34, 0, 14, 48));
	BANGCHUCAI.push_back(MyRECT(32, 15, 29, 46));
	BANGCHUCAI.push_back(MyRECT(17, 30, 44, 31));
	BANGCHUCAI.push_back(MyRECT(49, 0, 14, 63));
	BANGCHUCAI.push_back(MyRECT(17, 45, 59, 31));
	BANGCHUCAI.push_back(MyRECT(0, 0, 14, 16));
	BANGCHUCAI.push_back(MyRECT(32, 30, 44, 46));
	BANGCHUCAI.push_back(MyRECT(47, 15, 29, 61));
	BANGCHUCAI.push_back(MyRECT(30, 121, 127, 46));
	BANGCHUCAI.push_back(MyRECT(30, 112, 120, 46));
	BANGCHUCAI.push_back(MyRECT(0, 15, 29, 16));
	BANGCHUCAI.push_back(MyRECT(47, 30, 44, 61));
	BANGCHUCAI.push_back(MyRECT(32, 45, 59, 46));
	BANGCHUCAI.push_back(MyRECT(47, 45, 59, 61));
	BANGCHUCAI.push_back(MyRECT(0, 60, 74, 14));
	BANGCHUCAI.push_back(MyRECT(15, 60, 74, 29));
	BANGCHUCAI.push_back(MyRECT(0, 30, 44, 16));
	BANGCHUCAI.push_back(MyRECT(0, 45, 59, 16));
	BANGCHUCAI.push_back(MyRECT(30, 75, 87, 46));
	BANGCHUCAI.push_back(MyRECT(45, 60, 72, 59));
	BANGCHUCAI.push_back(MyRECT(17, 0, 14, 33));
	BANGCHUCAI.push_back(MyRECT(0, 75, 89, 14));
	BANGCHUCAI.push_back(MyRECT(15, 75, 89, 29));
	BANGCHUCAI.push_back(MyRECT(0, 90, 104, 14));
	BANGCHUCAI.push_back(MyRECT(30, 60, 74, 44));
	BANGCHUCAI.push_back(MyRECT(0, 105, 117, 14));
	BANGCHUCAI.push_back(MyRECT(47, 120, 124, 51));
	BANGCHUCAI.push_back(MyRECT(45, 95, 103, 61));
	BANGCHUCAI.push_back(MyRECT(47, 104, 112, 63));
	BANGCHUCAI.push_back(MyRECT(0, 0, 0, 0));



	Themchuoi("NHAP MON PHAT TRIEN GAME");
	Themchuoi("098 1389693 ");
	Themchuoi("(TEST......) ");
	Themchuoi("NHAP MON PHAT TRIEN GAME");
	Themchuoi("098 1389693 ");
	Themchuoi("(TEST......) ");

}
void IntroScene::OnKeyDown(int keyCode)
{
	switch (keyCode)
	{
	case VK_UP:
		menuselectPos.y -= Between.y;
		break;
	case VK_DOWN:
		menuselectPos.y += Between.y;
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
void IntroScene::Themchuoi(string str)
{
	vector<KYTU>			mARR;
	for each (char var in str)
	{
		switch (var)
		{
		case '0':
			mARR.push_back(KYTU::Z0);
				break;
		case '1':
			mARR.push_back(KYTU::Z1);
			break;
		case '2':
			mARR.push_back(KYTU::Z2);
			break;
		case '3':
			mARR.push_back(KYTU::Z3);
			break;
		case '4':
			mARR.push_back(KYTU::Z4);
			break;
		case '5':
			mARR.push_back(KYTU::Z5);
			break;
		case '6':
			mARR.push_back(KYTU::Z6);
			break;
		case '7':
			mARR.push_back(KYTU::Z7);
			break;
		case '8':
			mARR.push_back(KYTU::Z8);
			break;
		case '9':
			mARR.push_back(KYTU::Z9);
			break;
		case 'Q' :
			mARR.push_back(KYTU::Q);
			break;
		case 'W':
			mARR.push_back(KYTU::W);
			break;
		case 'E':
			mARR.push_back(KYTU::E);
			break;
		case 'R':
			mARR.push_back(KYTU::R);
			break;
		case 'T':
			mARR.push_back(KYTU::T);
			break;
		case 'Y':
			mARR.push_back(KYTU::Y);
			break;
		case 'U':
			mARR.push_back(KYTU::U);
			break;
		case 'I':
			mARR.push_back(KYTU::I);
			break;
		case 'O':
			mARR.push_back(KYTU::O);
			break;
		case 'P':
			mARR.push_back(KYTU::P);
			break;
		case 'A':
			mARR.push_back(KYTU::A);
			break;
		case 'S':
			mARR.push_back(KYTU::S);
			break;
		case 'D':
			mARR.push_back(KYTU::D);
			break;
		case 'F':
			mARR.push_back(KYTU::F);
			break;
		case 'G':
			mARR.push_back(KYTU::G);
			break;
		case 'H':
			mARR.push_back(KYTU::H);
			break;
		case 'J':
			mARR.push_back(KYTU::J);
			break;
		case 'K':
			mARR.push_back(KYTU::K);
			break;
		case 'L':
			mARR.push_back(KYTU::L);
			break;
		case 'Z':
			mARR.push_back(KYTU::Z);
			break;
		case 'X':
			mARR.push_back(KYTU::X);
			break;
		case 'C':
			mARR.push_back(KYTU::C);
			break;
		case 'V':
			mARR.push_back(KYTU::V);
			break;
		case 'B':
			mARR.push_back(KYTU::B);
			break;
		case 'N':
			mARR.push_back(KYTU::N);
			break;
		case 'M':
			mARR.push_back(KYTU::M);
			break;
		case '(':
			mARR.push_back(KYTU::mo);
			break;
		case ')':
			mARR.push_back(KYTU::dong);
			break;
		case '.':
			mARR.push_back(KYTU::cham);
			break;
		default:
			mARR.push_back(KYTU::trang);
			break;
		}
	}
	mList.push_back(mARR);
	mARR.clear();
	



}

void IntroScene::Inchuoi(D3DXVECTOR3 position, D3DXVECTOR2 between, D3DXVECTOR2 scale)
{
	
	D3DXVECTOR3 POS = position;

	for each (vector<KYTU> varl in mList)
	{
		for each (KYTU var in varl)
		{
			GraphicsHelper::GetInstance()->DrawTexture(this->ABC, BANGCHUCAI.at(var), D3DXVECTOR3(0, 0, 0), POS, scale);
			POS.x += between.x;
		}
		POS.x = position.x;
		POS.y += between.y;

	}
	
}
