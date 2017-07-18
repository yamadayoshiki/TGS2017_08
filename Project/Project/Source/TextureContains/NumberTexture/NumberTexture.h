#ifndef numbertexture_h_
#define numbertexture_h_
#include "../itexture.h"
#include <iostream>
#include <gsvector2.h>
#include "../../utility/texture2dparameter/texture2dparameterptr.h"
#include "../../drawmanager/drawmanagerptr.h"
#include "../../drawmanager/draworder.h"
#include <vector>
#include <GStype.h>

struct Texture2DParamAndID {
	Texture2DParameterSPtr m_TexParam;
	int m_DrawOrderID;
};

/*
横一列同じ幅{0,1,2,3,4,5,6,7,8,9}のテクスチャ想定
右揃え/座標は右上を指定
*/
//番号texture
class NumberTexture : public ITexture
{
public:
	NumberTexture(
		const std::string& texName,			//テクスチャ登録名
		const DrawManagerSPtr& drawManager,	//描画管理
		const DrawOrder drawOrder,			//描画順序
		const GSvector2& pos,				//右上座標
		const int length = 0);				//桁数(デフォルトの場合表示数字桁のみ表示)
	~NumberTexture();

public:
	//初期化
	void Initialize()override;
	//更新
	void Update(float deltatime) override {}
	//パラメーターの取得
	Texture2DParameterSPtr GetParameter()override { return nullptr; }
	//ループ回数の取得
	int GetLoopCount()override { return 0; }
	//ストップ
	void Stop()override {}
	//リスタート
	void Restart()override {}
	//座標+回転の設定
	void SetPosAndAngle(const GSvector2& pos, float angle)override {};
	//表示モード切替
	void ChangeDisplayMode(const DisplayMode mode)override;

public:
	//番号設定
	void SetNumber(int num);
	//座標設定
	void SetPos(const GSvector2& pos);

private:
	//番号設定(表示桁数設定あり)
	void SetNumberLocal(int num);
	//番号設定(表示桁数設定なし)
	void SetNumberLocalNonZero(int num);
	//指定数字の切り取り矩形を取得
	GSrect GetNumToRect(int num);
	//表示桁の切り替え
	void ChangeLength(const int length);
	//指定桁の座標の取得
	GSvector2 GetOneDigitPos(
		const int numDigit,		//桁数
		const GSvector2& pos);	//座標

protected:
	std::string m_TexName;				//登録名
	DrawManagerWPtr p_DrawManager;		//描画管理
	DrawOrder m_DrawOrder;				//描画順序
	GSvector2 m_Position;				//右上座標
	float m_Length;						//表示桁数
	std::vector<Texture2DParamAndID>	//パラメーター配列
		m_ParamVector;
	int m_CutHeight;					//縦幅
	int m_CutWidth;						//1数字のと横幅
	int m_Number;						//数字

};
#endif // !numbertexture_h_
