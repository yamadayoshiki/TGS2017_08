#ifndef ENEMYSTATEMOVE_H_
#define ENEMYSTATEMOVE_H_

#include "../MoveBase/EnemyStateMoveBase.h"

//�G�l�~�[���������
class EnemyStateMove :public EnemyStateMoveBase
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
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput() override {}

protected:
	float m_Speed;		//�X�s�[�h
};

#endif