#include "Alphabet.h"


Alphabet::Alphabet()
{
	mBangChuCai['0'] = MyRECT(17, 15, 29, 31);
	mBangChuCai['1'] = MyRECT(47, 113, 119, 61);
	mBangChuCai['2'] = MyRECT(47, 73, 83, 61);
	mBangChuCai['3'] = MyRECT(0, 118, 126, 14);
	mBangChuCai['4'] = MyRECT(15, 90, 102, 29);
	mBangChuCai['5'] = MyRECT(47, 84, 94, 61);
	mBangChuCai['6'] = MyRECT(15, 103, 115, 29);
	mBangChuCai['7'] = MyRECT(30, 101, 111, 44);
	mBangChuCai['8'] = MyRECT(15, 116, 126, 29);
	mBangChuCai['9'] = MyRECT(30, 88, 100, 44);
	mBangChuCai['A'] = MyRECT(34, 0, 14, 48);
	mBangChuCai['B'] = MyRECT(32, 15, 29, 46);
	mBangChuCai['C'] = MyRECT(17, 30, 44, 31);
	mBangChuCai['D'] = MyRECT(49, 0, 14, 63);
	mBangChuCai['E'] = MyRECT(17, 45, 59, 31);
	mBangChuCai['F'] = MyRECT(0, 0, 14, 16);
	mBangChuCai['G'] = MyRECT(32, 30, 44, 46);
	mBangChuCai['H'] = MyRECT(47, 15, 29, 61);
	mBangChuCai['I'] = MyRECT(30, 121, 127, 46);
	mBangChuCai['J'] = MyRECT(30, 112, 120, 46);
	mBangChuCai['K'] = MyRECT(0, 15, 29, 16);
	mBangChuCai['L'] = MyRECT(47, 30, 44, 61);
	mBangChuCai['M'] = MyRECT(32, 45, 59, 46);
	mBangChuCai['N'] = MyRECT(47, 45, 59, 61);
	mBangChuCai['O'] = MyRECT(0, 60, 74, 14);
	mBangChuCai['P'] = MyRECT(15, 60, 74, 29);
	mBangChuCai['Q'] = MyRECT(0, 30, 44, 16);
	mBangChuCai['R'] = MyRECT(0, 45, 59, 16);
	mBangChuCai['S'] = MyRECT(30, 75, 87, 46);
	mBangChuCai['T'] = MyRECT(45, 60, 72, 59);
	mBangChuCai['U'] = MyRECT(17, 0, 14, 33);
	mBangChuCai['V'] = MyRECT(0, 75, 89, 14);
	mBangChuCai['W'] = MyRECT(15, 75, 89, 29);
	mBangChuCai['X'] = MyRECT(0, 90, 104, 14);
	mBangChuCai['Y'] = MyRECT(30, 60, 74, 44);
	mBangChuCai['Z'] = MyRECT(0, 105, 117, 14);
	mBangChuCai['.'] = MyRECT(47, 120, 124, 51, D3DXVECTOR3(0, -10, 0));
	mBangChuCai['('] = MyRECT(45, 95, 103, 61);
	mBangChuCai[')'] = MyRECT(47, 104, 112, 63);
	mBangChuCai[' '] = MyRECT(0, 0, 0, 0);

	D3DXIMAGE_INFO		AlphabetInfo;
	D3DXGetImageInfoFromFile(L"Map\\ABC.PNG", &AlphabetInfo);
	D3DXCreateTextureFromFileEx(GraphicsHelper::GetInstance()->GetDirectDevice(), L"Map\\ABC.PNG", AlphabetInfo.Width,
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

Alphabet::Alphabet(D3DXVECTOR3 pos, std::string string):Alphabet()
{
	this->mPosition = pos;
	this->mString = string;
}

Alphabet::~Alphabet()
{
}

void Alphabet::Render()
{

	for (int i = 0; i < this->mString.length(); i++)
	{
		GraphicsHelper::GetInstance()->DrawTexture(mAlphabetTexture, this->mBangChuCai[mString[i]], this->mBangChuCai[mString[i]].GetCenterArchorPosision(CenterArchor::CenterTop), D3DXVECTOR3(this->mPosition.x + 20 * i, this->mPosition.y,0), D3DXVECTOR2(1.5,1.5));
	}

}

void Alphabet::SetString(std::string string)
{
	this->mString = string;
}
