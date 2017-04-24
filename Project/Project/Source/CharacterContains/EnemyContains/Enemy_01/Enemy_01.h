#ifndef ENEMY_01_H_
#define ENEMY_01_H_

#include "../BaseContains/Base/Enemy_Base.h"

class Enemy_01 : public Enemy_Base
{
public:
	//�R���X�g���N�^
	Enemy_01(
		const IWorldPtr& world,
		const ActorName& name,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const ITexturePtr& texture,
		const IBodyPtr& body);
protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;
};

#endif // !ENEMY_01_H_
