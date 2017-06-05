#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandMoveBase.h"
#include "../../../../../../../Utility/FourDirection/FourDirection.h"

//��s�錾
class TargetPosition;

//�ǉ����ɐi��
class EnemyCommandAlongWallMove :public EnemyCommandMoveBase
{
public:
	//�R���X�g���N�^
	EnemyCommandAlongWallMove(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//�f�X�g���N�^
	~EnemyCommandAlongWallMove();
	//�I��
	virtual void Finalize() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̍X�V
	virtual void OnUpdate(float deltaTime) override;
	//�ڕW�n�_�ɓ����������A�N�V����
	virtual void ArriveReaction() override;
	//���̖ڕW�n�_��ݒ肷��
	virtual void SetNextTargetPos()override {}

protected:
	//�ڕW�n�_�̐ݒ�
	virtual void SetTargetPos();

protected:
	TurnDirection m_TurnDirection;		//��]����
	TargetPosition* p_TargetPosition;	//�ڕW�n�_�Ǘ�
};

#endif