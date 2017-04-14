#pragma once

#include "../../../PlayerState.h"

// �ʏ��Ԃ̍U�����
class PlayerState_A_AttackBase : public PlayerState {
public:
	// �R���X�g���N�^
	PlayerState_A_AttackBase(Vector3& pos, Matrix& mat);
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
private:
	// �X�e�[�g�ڍs���̍��W
	Vector3 mStartPos;
};
