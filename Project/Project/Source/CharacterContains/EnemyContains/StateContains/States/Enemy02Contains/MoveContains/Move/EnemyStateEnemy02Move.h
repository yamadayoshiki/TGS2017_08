#ifndef ENEMYSTATEENEMY02MOVE_H_
#define ENEMYSTATEENEMY02MOVE_H_

#include "../MoveBase/EnemyStateEnemy02MoveBase.h"

//Enemy02��pMove
class EnemyStateEnemy02Move : public EnemyStateEnemy02MoveBase
{
public:
	//�R���X�g���N�^
	EnemyStateEnemy02Move(
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

#endif // !ENEMYSTATEENEMY02MOVE_H_
