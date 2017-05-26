#ifndef ENEMYSTATEMOVEREPELMOVE_H_
#define ENEMYSTATEMOVEREPELMOVE_H_

#include "../Base/EnemyStateMoveRepelBase.h"

class EnemyStateMoveRepelMove : public EnemyStateMoveRepelBase
{
public:
	//�R���X�g���N�^
	EnemyStateMoveRepelMove(const EnemyBasePtr& enemy,
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

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
