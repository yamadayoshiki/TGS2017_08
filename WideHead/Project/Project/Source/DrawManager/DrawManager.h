#ifndef DRAWMANAGER_H_
#define DRAWMANAGER_H_
#include "../Utility/Rederer2D/Renderer2DPtr.h"
#include "../Utility/Texture2DParameter/Factory/Texture2DParamFactoryPtr.h"
#include "DrawOrder.h"
#include <map>
#include "DrawOrderObject.h"
#include "DisplayMode.h"

struct GSrect;
//描画管理
class DrawManager
{
public:
	//コンストラクタ
	DrawManager(Renderer2DPtr renderer2D);
	//デストラクタ
	~DrawManager();
	//要素の削除
	void Clear();
	//登録(パラメータデフォルト設定)
	DrawOrderID RegisterDefaultParam(const std::string& texName, Texture2DParameterSPtr& param, const DrawOrder order);
	//登録
	DrawOrderID Register(const std::string& texName, const Texture2DParameterSPtr& parameter, const DrawOrder order);
	//表示モード変更
	void ChageDisplayMode(const DrawOrderID id, const DisplayMode mode);
	//削除
	void Remove(const DrawOrderID id);
	//描画オブジェクト構造体の取得
	DrawOrderObject GetDrawObject(const DrawOrderID id);
	//描画
	void Draw();
	//描画テクスチャ矩形の取得
	GSrect GetRect(const std::string& texName);
	//描画順序変更
	void ChangeOrder(const DrawOrderID id, const DrawOrder drawOrder);

private:
	std::map<DrawOrderID, DrawOrderObject>
		m_DrawOrderMap;				//描画オブジェクト
	std::map<DrawOrderID, DrawOrderObject>
		m_NonDisplayDrawOrderMap;	//非表示描画オブジェクト
	int m_Oreder;					//追加順
	Renderer2DPtr p_Renderer;		//レンダラー
	Texture2DParamFactoryUPtr
		p_Texture2DParamFactory;	//テクスチャパラメータ工場

};

#endif // !DRAWMANAGER_H_
