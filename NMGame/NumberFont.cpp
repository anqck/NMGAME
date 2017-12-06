#include "NumberFont.h"

NumberFont::NumberFont()
{
	mListAlphabet['0'] = MyRECT(0, 0, 8, 8);
	mListAlphabet['1'] = MyRECT(0, 27, 33, 8);
	mListAlphabet['2'] = MyRECT(0, 9, 17, 8);
	mListAlphabet['3'] = MyRECT(0, 18, 26, 8);
	mListAlphabet['4'] = MyRECT(9, 0, 8, 17);
	mListAlphabet['5'] = MyRECT(9, 9, 17, 17);
	mListAlphabet['6'] = MyRECT(18, 0, 8, 26);
	mListAlphabet['7'] = MyRECT(18, 9, 17, 26);
	mListAlphabet['8'] = MyRECT(9, 18, 26, 17);
	mListAlphabet['9'] = MyRECT(18, 18, 26, 26);



	D3DXIMAGE_INFO		AlphabetInfo;
	D3DXGetImageInfoFromFile(L"Object\\SceneInformation\\NumberFont.png", &AlphabetInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Object\\SceneInformation\\NumberFont.png", AlphabetInfo.Width,
		AlphabetInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 0, 255),
		&AlphabetInfo,
		NULL,
		&mAlphabetTexture);
}

NumberFont::NumberFont(D3DXVECTOR3 pos, std::string string) : NumberFont()
{
	this->mPosition = pos;
	this->mString = string;
}

NumberFont::~NumberFont()
{
}

void NumberFont::Render()
{
	for (int i = 0; i < this->mString.length(); i++)
	{
		GraphicsHelper::GetInstance()->DrawTexture(mAlphabetTexture, this->mListAlphabet[mString[i]], this->mListAlphabet[mString[i]].GetCenterArchorPosision(CenterArchor::CenterTop), D3DXVECTOR3(this->mPosition.x + 20 * i, this->mPosition.y, 0), D3DXVECTOR2(2.1, 2.1));
	}
}

void NumberFont::SetString(std::string string)
{
	this->mString = string;
}

void NumberFont::SetPosition(D3DXVECTOR3 pos)
{
	this->mPosition = pos;
}
