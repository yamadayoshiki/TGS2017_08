#ifndef ENEMYSTATEMOVESTANDARD_H_
#define ENEMYSTATEMOVESTANDARD_H_

#include "../Base/EnemyStateMoveBaseStandard.h"

//�G�l�~�[���������
class EnemyStateMoveStandard : virtual public EnemyStateMoveBaseStandard
{
public:
	//�R���X�g���N�^
	EnemyStateMoveStandard(
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