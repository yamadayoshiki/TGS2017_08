#pragma once

#include "../../PlayerState.h"

// �o�����̃W�����v���
class PlayerState_A_Jump : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_A_Jump(Vector3& pos, Matrix& mat);
	// �e��ԌŗL�̏�����
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
	// �W�����v��
	float mJumpPower;
};