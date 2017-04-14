#pragma once

#include "PlayerState_N_MoveBase.h"

// �ҋ@(�ʏ�)���
class PlayerState_N_Idle : public PlayerState_N_MoveBase {
public:
	// �R���X�g���N�^
	PlayerState_N_Idle(Vector3& pos, Matrix& mat);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor)override;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime)override {}
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput()override {}
};
