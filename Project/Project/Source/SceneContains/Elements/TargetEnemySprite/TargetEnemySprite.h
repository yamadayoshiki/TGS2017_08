#ifndef TARGETENEMYSPRITE_H_
#define TARGETENEMYSPRITE_H_
#include "../AnimationSpriteBase/AnimationSpriteBase.h"
class ZoomSprite;
#include <GSvector2.h>
class TargetEnemySprite : public AnimationSpriteBase
{
private:
	enum State {
		UP,		//ägëÂ
		DOWN,	//èkè¨
		END,	//èIóπ
	};
public:
	TargetEnemySprite(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& targetEnemy,
		const float rateOfTime = 0.02f);

protected:
	void onUpdate(float deltaTime) override;

public:
	//ï`âÊï\é¶êÿë÷
	void ChangeDisplayMode(const DisplayMode mode)override;
	//èIóπÇµÇΩÇ©
	bool IsEnd()const override;

protected:
	std::shared_ptr<ZoomSprite> p_DownTarget;
	std::shared_ptr<ZoomSprite> p_TargetEnemy;

	GSvector2 m_OffsetPos;
};
#endif