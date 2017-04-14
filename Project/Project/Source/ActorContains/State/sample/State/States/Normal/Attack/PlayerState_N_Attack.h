#pragma once

#include "PlayerState_N_AttackBase.h"

enum class  PlayerState_Enum;

// �ʏ펞�̍U�����
class PlayerState_N_Attack : public PlayerState_N_AttackBase {
public:
	// �R���X�g���N�^
	PlayerState_N_Attack(Vector3& pos, Matrix& mat, PlayerMotionID motion, PlayerState_Enum next);
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit(Actor & actor)override;
	// �X�V����
	virtual void onUpdate(Actor & actor, float deltaTime)override;
	// �Փ˔���
	virtual void onCollide(const Actor & other)override {}
	// �I�����̏���
	virtual void onEnd()override {}
	// ���͏���
	virtual void onInput()override {}
private:
	// ���[�V����
	PlayerMotionID mMotion;
	// �R���{���̑J�ڐ�
	PlayerState_Enum mNextState;
};
