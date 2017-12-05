#pragma once
#include <map>
#include "Global.h"
#include "MyRECT.h"
#include "GraphicsHelper.h"
class Alphabet
{

public:
	Alphabet();
	Alphabet(D3DXVECTOR3 pos,std::string string);	
	~Alphabet();

	void							Render();
	void							OpacityRender(DWORD AlphaValue);

	void							SetString(std::string string);
	void							SetPosition(D3DXVECTOR3 pos);
private:
	std::map<char, MyRECT>	mBangChuCai;
	LPDIRECT3DTEXTURE9				mAlphabetTexture;

	D3DXVECTOR3						mPosition;
	std::string						mString;


};