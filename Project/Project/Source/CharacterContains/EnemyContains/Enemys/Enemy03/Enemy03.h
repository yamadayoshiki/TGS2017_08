#ifndef ENEMY03_H_
#define ENEMY03_H_

#include "../Base/EnemyBase.h"

//�ǉ����ɓ����G
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

	//�N���[������(�g�p���p�����override)
	virtual ActorPtr clone(const GSvector2& position, const FourDirection& front = FourDirection(FourDirectionName::None)) override;

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
