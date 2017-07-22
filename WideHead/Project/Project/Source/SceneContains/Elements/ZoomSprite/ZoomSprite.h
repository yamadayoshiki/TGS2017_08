#ifndef ZOOMSPRITE_H_
#define ZOOMSPRITE_H_
#include "../AnimationSpriteBase/AnimationSpriteBase.h"
#include <GSvector2.h>
class ZoomSprite : public AnimationSpriteBase
{
protected:
	enum State {
		UP,		//�g��
		DOWN,	//�k��
		END,	//�I��
	};
public:
	ZoomSprite(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const GSvector2& maxScale = GSvector2(1.3f, 1.3f),
		const GSvector2& originScale = GSvector2(1.0f, 1.0f),
		const float rateOfTime = 0.02f);

protected:
	void onUpdate(float deltaTime) override;

public:
	//�I��������
	bool IsEnd()const override;
	//�`��\���ؑ�
	void ChangeDisplayMode(const DisplayMode mode)override;

public:
	//���݂̊g�嗦�̎擾
	GSvector2 GetScale() const;

protected:
	State m_CurState;
	GSvector2 m_OriginScale;
	GSvector2 m_CurScale;
	GSvector2 m_MaxScale;

	float m_Timer;
	float m_RateOfTime;
};
#endif // !ZOOMSPRITE_H_
