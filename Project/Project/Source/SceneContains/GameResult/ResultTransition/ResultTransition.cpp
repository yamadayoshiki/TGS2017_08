#include "ResultTransition.h"

#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../TextureContains/Texture/Texture.h"
#include <gslib.h>

//コンストラクタ
ResultTransition::ResultTransition(const IGameManagerPtr & gameManager)
	:Transition(gameManager), p_Texture(std::make_unique<Texture>("Player_Image", p_GameManager->GetDrawManager(), DrawOrder::UI))
{
	//パラメータの設定
	p_Texture->GetParameter()->m_Position = m_Position;
	p_Texture->GetParameter()->m_Center = { 0.0f, 0.0f };
	p_Texture->GetParameter()->m_Color = m_Color;
}

// デストラクタ
ResultTransition::~ResultTransition() {
	p_Texture.reset();
}

// 開始     
void ResultTransition::onStart() {
	m_Timer = 0.0f;
}

//更新
void ResultTransition::onUpdate(float deltaTime)
{
	float t = m_Timer / m_Maxtimer;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 1.0f), t);
	p_Texture->GetParameter()->m_Color = color;

	GSvector2 pos = m_Position.lerp(GSvector2(0.0f, 0.0f), t*t);
	p_Texture->GetParameter()->m_Position = pos;

	if (m_Timer >= 120.0f)
	{
		is_end = true;
	}
	m_Timer = MIN(m_Timer + deltaTime, m_Maxtimer);
}

//描画
void ResultTransition::onDraw() const
{
}

bool ResultTransition::isEnd()
{
	return is_end;
}
