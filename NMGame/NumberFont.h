#pragma once
#include <map>
#include "Global.h"
#include "MyRECT.h"
#include "GraphicsHelper.h"

class NumberFont
{

public:
	NumberFont();
	NumberFont(D3DXVECTOR3 pos, std::string string);
	~NumberFont();

	void							Render();

	void							SetString(std::string string);
	void							SetPosition(D3DXVECTOR3 pos);
private:
	std::map<char, MyRECT>			mListAlphabet;
	LPDIRECT3DTEXTURE9				mAlphabetTexture;

	D3DXVECTOR3						mPosition;
	std::string						mString;

};