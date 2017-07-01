#ifndef DRAWORDERMANAGER_H_
#define DRAWORDERMANAGER_H_
#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include <iostream>
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "DrawOrder.h"
#include <map>
using DrawOrderID = int;
//描画オブジェクト構造体
struct DrawOrderObject
{
	DrawOrderID id;					//描画順
	std::string texName;			//テクスチャの名前
	Texture2DParameterWPtr param;	//テクスチャのパラメータ
	//std::set用比較演算子
	bool operator < (const DrawOrderObject& other) {
		return this->id < other.id;
	}
};

//描画管理
class DrawOrderManager
{
public:
	//コンストラクタ
	DrawOrderManager(Renderer2DPtr renderer2D);
	//デストラクタ
	~DrawOrderManager();
	//要素の削除
	void Clear();
	//登録
	DrawOrderID Register(const std::string& texName, const Texture2DParameterPtr& parameter, const DrawOrder order);
	//削除
	void Remove(const DrawOrderID id);
	//描画オブジェクト構造体の取得
	DrawOrderObject GetDrawObject(const DrawOrderID id);
	//描画
	void Draw();
private:
	std::map<DrawOrderID,DrawOrderObject> m_DrawOrderSet;	//描画オブジェクト
	int m_Oreder;				//追加順
	Renderer2DPtr p_Renderer;	//レンダラー
};

#endif // !DRAWMANAGER_H_
