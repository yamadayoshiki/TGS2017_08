#ifndef ENEMYSTATEMOVE_H_
#define ENEMYSTATEMOVE_H_

#include "../Base/EnemyStateMoveBase.h"

//�G�l�~�[���������
class EnemyStateMove : virtual public EnemyStateMoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateMove(
		const EnemyBasePtr& enemy,
		const float speed);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit()override;
	// �X�V����
	virtual void onUpdate(float deltaTime)override;

protected:
	float m_Speed;		//�X�s�[�h
};

#endif