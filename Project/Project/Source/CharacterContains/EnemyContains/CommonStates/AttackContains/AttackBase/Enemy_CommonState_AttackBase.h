#ifndef ENEMY_COMMONSTATE_ATTACKBASE_H_
#define ENEMY_COMMONSTATE_ATTACKBASE_H_

#include "../../../BaseContains/BaseState/Enemy_BaseState.h"

//�U����Ԃ̊��N���X
class Enemy_CommonState_AttackBase :public Enemy_BaseState
{
public:
	// �R���X�g���N�^
	Enemy_CommonState_AttackBase(GSvector2& pos, GSmatrix4& mat);
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor & actor) override;
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
	// ���͏���
	virtual void input() override;
protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor) = 0;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() = 0;
};

#endif
