#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandBase.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"

//�ǉ����ɐi��
class EnemyCommandAlongWallMove :public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
	//��]�����̐ݒ�
	void SetTurnDirection(TurnDirection turnDirection);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�ڕW�n�_�̐ݒ�
	void SetTargetPos();


protected:
	TurnDirection m_TurnDirection;		//��]����
	FourDirection m_CurDirection;		//���݂̐i�s����
	GSvector2 m_NextTargetPos;			//���̖ڕW�n�_
};

#endif