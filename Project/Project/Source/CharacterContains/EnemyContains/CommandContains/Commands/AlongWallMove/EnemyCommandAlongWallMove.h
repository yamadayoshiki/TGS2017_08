#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandBase.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"

//��s�錾
class TargetPosition;

//�ǉ����ɐi��
class EnemyCommandAlongWallMove :public EnemyCommandBase
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
	virtual void ArriveReaction();
	//�ڕW�n�_�̐ݒ�
	virtual void SetTargetPos();

protected:
	TurnDirection m_TurnDirection;		//��]����
	GSvector2 m_NextTargetPos;			//���̖ڕW�n�_
	TargetPosition* p_TargetPosition;	//�ڕW�n�_�Ǘ�
};

#endif