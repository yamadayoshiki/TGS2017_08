#ifndef ENEMY02_H_
#define ENEMY02_H_

#include "../Base/EnemyBase.h"

class Enemy02 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy02(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const FourDirection turnDirection,
		const IGameManagerPtr& gameManager);
protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;

protected:
	FourDirection m_TurnDirection;
};

#endif