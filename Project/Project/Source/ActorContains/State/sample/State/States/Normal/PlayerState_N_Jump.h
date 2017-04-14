#pragma once

#include "../../PlayerState.h"

// �ʏ펞�̃W�����v���
class PlayerState_N_Jump : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_N_Jump(Vector3& pos, Matrix& mat);
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
private:
	float mJumpPower;
};