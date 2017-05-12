#ifndef ENEMYCOMMANDALONGWALLMOVE_H_
#define ENEMYCOMMANDALONGWALLMOVE_H_

#include "../Base/EnemyCommandBase.h"

//�ǉ����ɐi��
class EnemyCommandAlongWallMove :public EnemyCommandBase
{
	//��]����
	enum class TurnDirection
	{
		Clockwise,		//���v���
		AntiClockwise,	//�����v���
	};

public:
	//�R���X�g���N�^
	EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection);
	//�X�V
	virtual void Update(float deltaTime) override;
	//�I��
	virtual void Finalize() override;
	//��]�����̐ݒ�
	void SetturnDirection(TurnDirection turnDirection);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�ڕW�n�_�̐ݒ�
	void SetTargetPos();

protected:
	TurnDirection m_TurnDirection;		//��]����
	GSvector2 m_NextTargetPos;			//���̖ڕW�n�_
};

#endif