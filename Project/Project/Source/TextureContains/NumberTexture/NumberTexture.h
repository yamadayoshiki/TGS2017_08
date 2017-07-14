//#ifndef NUMBERTEXTURE_H_
//#define NUMBERTEXTURE_H_
//#include "../ITexture.h"
//#include <iostream>
//#include <GSvector2.h>
//#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
//#include "../../DrawManager/DrawManagerPtr.h"
//#include "../../DrawManager/DrawOrder.h"
//#include <vector>
////整列位置
//enum class AlignType {
//	Right,	//右揃え
//	Left,	//左揃え
//};
//
///*
//横一列同じ幅{0,1,2,3,4,5,6,7,8,9}のテクスチャ想定
//*/
////番号Texture
//class NumberTexture : public ITexture
//{
//public:
//	NumberTexture(
//		const std::string& texName,			//テクスチャ登録名
//		const DrawManagerSPtr& drawManager,	//描画管理
//		const DrawOrder drawOrder,			//描画順序
//		const AlignType type,				//整列位置
//		const int length = 0);				//桁数(デフォルトの場合表示数字桁のみ表示)
//	~NumberTexture();
//
//public:
//	//初期化
//	void Initialize()override;
//	//更新
//	void Update(float deltaTime) override;
//	//パラメーターの取得
//	Texture2DParameterSPtr GetParameter()override { return nullptr; }
//	//ループ回数の取得
//	int GetLoopCount()override { return 0; }
//	//番号設定
//	void SetNumber(int num);
//	//座標設定
//	void SetPos(const GSvector2& pos);
//	//座標+回転の設定
//	void SetPosAndAngle(const GSvector2& pos, float angle)override;
//
//private:
//	//番号設定(表示桁数設定あり)
//	void SetNumber(int num);
//	//番号設定(表示桁数設定なし)
//	void SetNumber(int num);
//
//protected:
//	std::string m_TexName;				//登録名
//	int m_CutWidth;						//1数字の幅
//	AlignType m_Type;					//整列位置
//	int m_Length;						//表示桁数
//	std::vector<Texture2DParameterSPtr>	//パラメーター配列
//		p_ParamVector;
//	int m_DrawOrderID;					//描画順序ID
//	DrawManagerWPtr p_DrawManager;		//描画管理
//};
//#endif // !NUMBERTEXTURE_H_
