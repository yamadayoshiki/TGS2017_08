#pragma once

#include "../../../PlayerState.h"

// �ʏ펞�̈ړ��N���X�̃x�[�X
class PlayerState_N_MoveBase : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_N_MoveBase(Vector3& pos, Matrix& mat);
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
