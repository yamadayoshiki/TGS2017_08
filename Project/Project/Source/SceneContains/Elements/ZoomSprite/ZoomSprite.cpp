#include "ZoomSprite.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
ZoomSprite::ZoomSprite(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const ITexturePtr& texture)
	: Actor(
		world,
		ActorName::UI_Sprite,
		position,
		gameManager,
		texture)
	, m_CurState(UP)
	, m_Scale(1.0f) {
}

void ZoomSprite::onUpdate(float deltaTime) {
	switch (m_CurState) {
	case UP:
		m_Scale += 0.05f;
		if (m_Scale >= 1.30f)
			m_CurState = DOWN;
		break;

	case DOWN:
		m_Scale -= 0.08f;
		if (m_Scale <= 1.0f) {
			m_Scale = 1.0f;
			m_CurState = END;
		}
		break;

	case END:
		return;
	}
	p_Texture->GetParameter()->m_Scale = GSvector2(m_Scale, m_Scale);
}
