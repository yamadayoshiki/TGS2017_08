#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

class Enemy01 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy01(
		const IWorldPtr& world,
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
