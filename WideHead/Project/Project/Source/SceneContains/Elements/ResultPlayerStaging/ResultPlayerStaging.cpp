#include "ResultPlayerStaging.h"

#include "../../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../Define/Def_Nagano.h"
#include"../../../TextureContains/Texture/Texture.h"
#include <gslib.h>

//コンストラクタ
ResultPlayerStaging::ResultPlayerStaging(IWorld* world, const IGameManagerPtr & gameManager)
	:Actor(
		world,
		ActorName::UI_Sprite,
		GSvector2(-650, 0),
		gameManager,
		std::make_shared<Texture>("Player_Image", gameManager->GetDrawManager(), DrawOrder::UI))
{
	//パラメータの設定
	p_Texture->GetParameter()->m_Position = GSvector2(-650, 0);
	p_Texture->GetParameter()->m_Center = { 0.0f, 0.0f };
	p_Texture->GetParameter()->m_Color = m_Color;
}

//更新
void ResultPlayerStaging::onUpdate(float deltaTime)
{
	float t = m_Timer / m_Maxtimer;
	GScolor color = m_Color.lerp(GScolor(1.0f, 1.0f, 1.0f, 1.0f), t);
	p_Texture->GetParameter()->m_Color = color;

	GSvector2 pos = m_Position.lerp(GSvector2(0.0f, 0.0f), t*t);
	//p_Texture->GetParameter()->m_Position = pos;
	setPosition(pos);

	if (m_Timer >= 120.0f)
	{
		is_end = true;
	}
	m_Timer = MIN(m_Timer + deltaTime, m_Maxtimer);
}