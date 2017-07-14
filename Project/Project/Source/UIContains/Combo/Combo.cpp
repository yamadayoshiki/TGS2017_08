#include "Combo.h"

#include "../../FileReader/CsvReader.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/InputState/InputState.h"
#include "../../Utility/Rederer2D/Renderer2D.h"
#include "../Selector/Selector.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "../../SceneContains/SceneName.h"
#include"../../Utility/Animation/Animation.h"
#include"../../TextureContains/AnimationTexture/AnimationTexture.h"
#include"../../TextureContains/Texture/Texture.h"
#include"../../Utility/Number/NumberTexture.h"
#include <algorithm>

Combo::Combo(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	:UI_Base(world, ActorName::UI_Combo, position, gameManager) {
	m_MaxTime = 180.0f;
	m_NowTime = 0.0f;
	weidth = 300.0f;
	regist(file_name);
}

void Combo::regist(const std::string & file_name)
{
	//CsvReader csv = CsvReader(file_name);
	//if (csv.rows() == 1) {
	//	dead();
	//	return;
	//}

	//for (int row = 1; row < csv.rows(); row++) {
	//	m_NameList.push_back(csv.get(row, 0));
	//	Texture2DParameter param;
	//	param.m_Rect = *p_Renderer2D->GetTextureRect(csv.get(row, 0));
	//	param.m_Position = GSvector2(csv.getf(row, 1), csv.getf(row, 2));
	//	m_TextParamList.push_back(param);
	//}
}

void Combo::onUpdate(float deltaTime)
{
	//if (m_NameList.size() <= 0) {
	//	return;
	//}
	//float result = 0;
	//result = m_NowTime / m_MaxTime * weidth;
	//m_TextParamList[1].m_Rect = GSrect(0.0f, 0.0f, result, 50.0f);

	//if (p_GameManager->GetPlayerParameter().getComboCounter() > 0) {
	//	m_NowTime = p_GameManager->GetPlayerParameter().getComboCounter();
	//	p_GameManager->GetPlayerParameter().m_ComboTimer = 0.0f;
	//}
	//if (m_NowTime <= 0 /*&& p_GameManager->GetPlayerParameter().getCombo() > 0*/) {
	//	m_NowTime = 0.0f;
	//	p_GameManager->GetPlayerParameter().comboReset();
	//	return;
	//}
	//m_NowTime -= deltaTime;
}

void Combo::onDraw() const
{
	/*if (m_NameList.size() <= 0) {
		return;
	}
	NumberTexture namber(1000, 40, 60);
	p_Renderer2D->DrawTexture(m_NameList[0], m_TextParamList[0]);
	p_Renderer2D->DrawTexture(m_NameList[1], m_TextParamList[1]);
	p_Renderer2D->DrawTexture(m_NameList[2], m_TextParamList[2]);
	namber.draw(GSvector2(370, 20), p_GameManager->GetPlayerParameter().getCombo(), 3);*/
}
void Combo::setTexture()
{

}
