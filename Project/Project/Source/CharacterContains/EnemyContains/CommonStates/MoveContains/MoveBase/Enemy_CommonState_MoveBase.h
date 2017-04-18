#ifndef ENEMY_COMMONSTATE_MOVEBASE_H_
#define ENEMY_COMMONSTATE_MOVEBASE_H_

#include "../../../BaseContains/BaseState/Enemy_BaseState.h"

// �ʏ펞�̈ړ��N���X�̃x�[�X
class Enemy_CommonState_MoveBase : public Enemy_BaseState
{
public:
	// �R���X�g���N�^
	Enemy_CommonState_MoveBase(GSvector2& pos, GSmatrix4& mat);
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor & actor) override;
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;

protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor) = 0;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
};

#endif // !ENEMY_COMMONSTATE_MOVEBASE_H_
