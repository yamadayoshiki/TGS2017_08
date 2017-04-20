#ifndef ENEMY_COMMONSTATE_CRUSH_H_
#define ENEMY_COMMONSTATE_CRUSH_H_

#include "../../BaseContains/BaseState/Enemy_BaseState.h"

class Enemy_CommonState_Crush :public Enemy_BaseState
{
	//�R���X�g���N�^
	Enemy_CommonState_Crush(GSvector2& pos, GSmatrix4& mat);
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor & actor) override;
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
};

#endif // !ENEMY_COMMONSTATE_CRUSH_H_
