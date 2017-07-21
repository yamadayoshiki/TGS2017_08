#ifndef FLASHSPRITE_H_
#define FLASHSPRITE_H_
#include "../AnimationSpriteBase/AnimationSpriteBase.h"
#include <GSvector2.h>
class FlashSprite : public AnimationSpriteBase
{
	enum class State {
		UP,
		DOWN,
	};
public:
	FlashSprite(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const float rateOfTime = 0.02f);

protected:
	void onUpdate(float deltaTime) override;

public:
	//èIóπÇµÇΩÇ©
	bool IsEnd()const override;
	//ï`âÊï\é¶êÿë÷
	void ChangeDisplayMode(const DisplayMode mode)override;

protected:
	State m_CurState;
	float m_CurAlpha;

	float m_Timer;
	float m_RateOfTime;
};
#endif