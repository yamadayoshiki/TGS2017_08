#include "ZoomSprite.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../DrawManager/DrawOrder.h"
#include <cmath>
ZoomSprite::ZoomSprite(
	IWorld * world,
	const GSvector2 & position,
	const IGameManagerPtr & gameManager,
	const ITexturePtr& texture,
	const GSvector2& maxScale,
	const GSvector2& originScale,
	const float rateOfTime)
	: AnimationSpriteBase(
		world,
		position,
		gameManager,
		texture)
	, m_CurState(UP)
	, m_OriginScale(originScale)
	, m_CurScale(originScale)
	, m_MaxScale(maxScale)
	, m_Timer(0.0f)
	, m_RateOfTime(rateOfTime){
}

void ZoomSprite::onUpdate(float deltaTime) {
	switch (m_CurState) {
	case UP:
		m_CurScale = m_OriginScale.lerp(m_MaxScale, std::pow(m_Timer, 2));
		if (m_CurScale >= m_MaxScale) {
			m_CurScale = m_MaxScale;
			m_Timer = 0.0f;
			m_CurState = State::DOWN;
		}
		break;

	case DOWN:
		m_CurScale = m_MaxScale.lerp(m_OriginScale, std::pow(m_Timer, 2));
		if (m_CurScale <= m_OriginScale) {
			m_CurScale = m_OriginScale;
			m_CurState = END;
		}
		break;

	case END:
		return;
	}
	p_Texture->GetParameter()->m_Scale = m_CurScale;
	m_Timer += m_RateOfTime;
}

bool ZoomSprite::IsEnd() const {
	return (m_CurState == State::END);
}

void ZoomSprite::ChangeDisplayMode(const DisplayMode mode) {
	p_Texture->ChangeDisplayMode(mode);
}

GSvector2 ZoomSprite::GetScale() const {
	return m_CurScale;
}
