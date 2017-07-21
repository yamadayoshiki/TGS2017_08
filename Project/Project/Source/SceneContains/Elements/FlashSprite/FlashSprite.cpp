#include "FlashSprite.h"
#include "../../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../../DrawManager/DrawOrder.h"
#include <cmath>
#include <GStype.h>
FlashSprite::FlashSprite(IWorld * world, const GSvector2 & position, const IGameManagerPtr & gameManager, const ITexturePtr & texture, const float rateOfTime)
	: AnimationSpriteBase(
		world,
		position,
		gameManager,
		texture)
	, m_CurState(State::UP)
	, m_CurAlpha(0.0f)
	, m_Timer(0.0f)
	, m_RateOfTime(rateOfTime) {
}

void FlashSprite::onUpdate(float deltaTime) {
	m_CurAlpha = std::pow(m_Timer, 2);
	switch (m_CurState)
	{
	case State::UP:
		m_CurAlpha += m_RateOfTime;
		if (m_Timer >= 1.0f) {
			m_CurAlpha = 1.0f;
			m_Timer = 0.0f;
			m_CurState = State::DOWN;
		}
		break;

	case State::DOWN:
		m_CurAlpha -= m_RateOfTime;
		if (m_Timer >= 1.0f) {
			m_CurAlpha = 1.0f;
			m_Timer = 0.0f;
			m_CurState = State::DOWN;
		}
		break;
	}
	p_Texture->GetParameter()->m_Color.a = m_CurAlpha;
	m_Timer += m_RateOfTime;
}

bool FlashSprite::IsEnd() const {
	return false;
}

void FlashSprite::ChangeDisplayMode(const DisplayMode mode) {
	p_Texture->ChangeDisplayMode(mode);
}
