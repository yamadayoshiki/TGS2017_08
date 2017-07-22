#ifndef TARGETENEMYSPRITE_H_
#define TARGETENEMYSPRITE_H_
#include "../AnimationSpriteBase/AnimationSpriteBase.h"
class ZoomSprite;
#include <GSvector2.h>
class TargetEnemySprite : public AnimationSpriteBase
{
private:
	enum State {
		UP,		//�g��
		DOWN,	//�k��
		END,	//�I��
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
	//�`��\���ؑ�
	void ChangeDisplayMode(const DisplayMode mode)override;
	//�I��������
	bool IsEnd()const override;

protected:
	std::shared_ptr<ZoomSprite> p_DownTarget;
	std::shared_ptr<ZoomSprite> p_TargetEnemy;

	GSvector2 m_OffsetPos;
};
#endif