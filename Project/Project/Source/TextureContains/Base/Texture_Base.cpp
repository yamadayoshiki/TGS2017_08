#include "Texture_Base.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../DrawManager/DrawManager.h"
//コンストラクタ
Texture_Base::Texture_Base(
	const std::string & texName,
	const DrawManagerSPtr& drawManager,
	const DrawOrder drawOrder)
	: m_TexName(texName)
	, p_DrawManager(drawManager) {
	//描画管理に登録
	m_DrawOrderID = p_DrawManager.lock()->RegisterDefaultParam(m_TexName, p_Parameter, drawOrder);
}
//デストラクタ
Texture_Base::~Texture_Base() {
	//描画管理から削除
	p_DrawManager.lock()->Remove(m_DrawOrderID);
}
//パラメーターの取得
Texture2DParameterSPtr Texture_Base::GetParameter() {
	return p_Parameter;
}

void Texture_Base::SetPosAndAngle(const GSvector2 & pos, float angle){
	p_Parameter->m_Position = pos;
	p_Parameter->m_Rotate = angle;
}

void Texture_Base::ChangeDisplayMode(const DisplayMode mode){
	p_DrawManager.lock()->ChageDisplayMode(m_DrawOrderID, mode);
}
