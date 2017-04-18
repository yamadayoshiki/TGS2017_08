#ifndef ENEMY_COMMONSTATE_IDLE_H_
#define ENEMY_COMMONSTATE_IDLE_H_

#include "../MoveBase/Enemy_CommonState_MoveBase.h"

//�ҋ@���
class Enemy_CommonState_Idle :Enemy_CommonState_MoveBase
{
public:
	//�R���X�g���N�^
	Enemy_CommonState_Idle(GSvector2& pos, GSmatrix4& mat);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor)override;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime)override {}
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
};

#endif // !ENEMY_COMMONSTATE_IDLE_H_
