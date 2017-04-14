#pragma once

#include "../../PlayerState.h"

// �ʏ펞�̃K�[�h���
class PlayerState_N_Guard : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_N_Guard(Vector3& pos, Matrix& mat);
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor & actor) override;
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
	// �p�b�h���͏���
	virtual void input() override;
};