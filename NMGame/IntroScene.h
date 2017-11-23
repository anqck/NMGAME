#pragma once
#include "IScene.h"
#include "AladdinGame.h"
#include "Camel.h"
#include "AladdinCharacter.h"
#include "DemoMap.h"
#include "Camera.h"
#include "QuadTree.h"
#include "DemoScene.h"
#include "ThrowApple.h"

enum KYTU
{
	Z0 ,
	Z1 ,
	Z2 ,
	Z3 ,
	Z4 ,
	Z5 ,
	Z6 ,
	Z7 ,
	Z8 ,
	Z9 ,
	A ,
	B ,
	C ,
	D ,
	E ,
	F ,
	G ,
	H ,
	I ,
	J ,
	K ,
	L ,
	M ,
	N ,
	O ,
	P ,
	Q ,
	R ,
	S ,
	T ,
	U ,
	V ,
	W ,
	X ,
	Y ,
	Z ,
	cham ,
	mo,
	dong,
	trang
};
class IntroScene : public IScene
{


public:
	IntroScene();
	~IntroScene();
	void					Update(float DeltaTime);
	void					Render(float DeltaTime);
	void					LoadResource();
	void					OnKeyDown(int keyCode);
	void					OnKeyUp(int keyCode);
	void					ProcessInput();
	void					CheckCollision(float DeltaTime);
	void					Themchuoi(string str);
	void					Inchuoi(D3DXVECTOR3 position, D3DXVECTOR2 between = D3DXVECTOR2(10,10), D3DXVECTOR2 scale = D3DXVECTOR2(1,1));
protected:
	LPDIRECT3DSURFACE9 BackGround;
	D3DXIMAGE_INFO			BackGroundInfo;
	
	LPDIRECT3DTEXTURE9		Title;
	D3DXIMAGE_INFO			TitleInfo;

	vector<MyRECT>			BANGCHUCAI;
	LPDIRECT3DTEXTURE9		ABC;
	D3DXIMAGE_INFO			ABCInfo;

	vector<vector<KYTU>>	mList;

	LPDIRECT3DTEXTURE9		menuselect;
	D3DXIMAGE_INFO			menuselectInfo;
	//D3DXVECTOR3				menuselectPos;
	D3DXVECTOR2				Between; // x theo phuong ngang, y theo phuong thang dung

	ObjectStateWithLoop*		_menuselect;
	int						Option;
	

};