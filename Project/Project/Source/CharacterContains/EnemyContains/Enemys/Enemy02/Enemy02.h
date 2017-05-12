#ifndef ENEMY02_H_
#define ENEMY02_H_

#include "../Base/EnemyBase.h"

class Enemy02 : public EnemyBase
{
	//�R���X�g���N�^
	Enemy02(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager);
protected:
	//�X�V
	virtual void onUpdate(float deltaTime) override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;
};

#endif