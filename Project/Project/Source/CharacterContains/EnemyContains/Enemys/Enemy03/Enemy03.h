#ifndef ENEMY03_H_
#define ENEMY03_H_

#include "../Base/EnemyBase.h"

class Enemy03 : public EnemyBase
{
public:
	//�R���X�g���N�^
	Enemy03(
		IWorld* world,
		const GSvector2& position,
		const FourDirection front,
		const TurnDirection turnDirection,
		const IGameManagerPtr& gameManager);
protected:
	//�e��ŗL�̃R�}���h�̐ݒ�
	virtual void SetUpCommand() override;
	//�e��ŗL��State�̐ݒ�
	virtual void SetUpState() override;
	//�`��
	virtual void onDraw() const override;

protected:
	TurnDirection m_TurnDirection;
};

#endif
