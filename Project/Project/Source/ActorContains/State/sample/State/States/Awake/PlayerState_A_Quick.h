#pragma once

#include "../../PlayerState.h"

// �o�����̍����ړ��i�������j
class PlayerState_A_Quick : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_A_Quick(Vector3& pos, Matrix& mat);
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
};