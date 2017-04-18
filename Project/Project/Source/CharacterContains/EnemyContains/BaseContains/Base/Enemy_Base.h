#ifndef ENEMY_BASE_H_
#define ENEMY_BASE_H_

#include "../../../../ActorContains/Actor/Actor.h"

class Enemy_Base :public Actor
{
public:
	//�R���X�g���N�^
	Enemy_Base(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position,
		const IBodyPtr& body = std::make_shared<DammyBody>()
		);
	//���z�f�X�g���N�^
	virtual ~Enemy_Base() {}

protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;

protected:

};
#endif // !ENEMY_H_
