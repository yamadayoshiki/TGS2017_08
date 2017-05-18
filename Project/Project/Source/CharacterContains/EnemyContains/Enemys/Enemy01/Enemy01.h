#ifndef ENEMY01_H_
#define ENEMY01_H_

#include "../Base/EnemyBase.h"

struct FourDirection;

class Enemy01 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy01(
		IWorld* world,
		const GSvector2& position,
		FourDirection& front,
		const IGameManagerPtr& gameManager);

protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;
	//�Փ˂���
	virtual void onCollide(Actor& other) override;
};

#endif
