#pragma once

#include "../../PlayerState.h"

// �o����Ԃ���ʏ펞�ւ̑J�ڒ��̏��
class PlayerState_Normal : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_Normal(Vector3& pos, Matrix& mat);
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
};
