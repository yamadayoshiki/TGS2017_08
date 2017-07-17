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
#include "../../TextureContains/NumberTexture/NumberTexture.h"
#include <algorithm>

Combo::Combo(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const std::string & file_name)
	: UI_Base(world, ActorName::UI_Combo, position, gameManager,DrawOrder::UI_Front1)
	, p_NumberTexture(std::make_shared<NumberTexture>("NumberTexture_1", gameManager->GetDrawManager(),DrawOrder::UI_Front1, GSvector2(590, 20), 3)) {
	m_MaxTime = 180.0f;
	m_NowTime = 0.0f;
	weidth = 300.0f;
	regist(file_name);
}

void Combo::regist(const std::string & file_name)
{
	CsvReader csv = CsvReader(file_name);
	if (csv.rows() == 1) {
		dead();
		return;
	}

	for (int row = 1; row < csv.rows(); row++) {
		p_Texture = std::make_shared<Texture>(csv.get(row, 0), p_GameManager->GetDrawManager(), DrawOrder::UI);
		p_Texture->GetParameter()->m_Position = GSvector2(csv.getf(row, 1), csv.getf(row, 2));
		p_Texture->GetParameter()->m_Center = { 0.0f, 0.0f };
		p_Texture->ChangeDisplayMode(DisplayMode::Display);
		m_TextureList.push_back(p_Texture);
	}
}

void Combo::onUpdate(float deltaTime)
{
	if (m_TextureList.size() == 0) {
		dead();
		return;
	}

	float result = 0;
	result = m_NowTime / m_MaxTime * weidth;
	m_TextureList[1]->GetParameter()->m_Rect = GSrect(0.0f, 0.0f, result, 50.0f);

	if (p_GameManager->GetPlayerParameter().getComboCounter() > 0) {
		m_NowTime = p_GameManager->GetPlayerParameter().getComboCounter();
		p_GameManager->GetPlayerParameter().m_ComboTimer = 0.0f;
	}
	if (m_NowTime <= 0) {
		m_NowTime = 0.0f;
		p_GameManager->GetPlayerParameter().comboReset();
		return;
	}
	m_NowTime -= deltaTime;

	p_NumberTexture->SetNumber(p_GameManager->GetPlayerParameter().getCombo());
}

void Combo::onDraw() const {
}

void Combo::setTexture()
{
}

void Combo::ChangeDisplayMode(const DisplayMode mode){
	for (auto itr = m_TextureList.begin(); itr != m_TextureList.end(); itr++)
		(*itr)->ChangeDisplayMode(mode);

	p_NumberTexture->ChangeDisplayMode(mode);
}
