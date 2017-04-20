#ifndef ENEMY_COMMONSTATE_RUN_H_
#define ENEMY_COMMONSTATE_RUN_H_

#include "../MoveBase/Enemy_CommonState_MoveBase.h"

class Enemy_CommonState_Run :public Enemy_CommonState_MoveBase
{
public:
	//�R���X�g���N�^
	Enemy_CommonState_Run(GSvector2& pos, GSmatrix4& mat);
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor)override;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime)override;
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput() override {}
};

#endif // !ENEMY_COMMONSTATE_RUN_H_
