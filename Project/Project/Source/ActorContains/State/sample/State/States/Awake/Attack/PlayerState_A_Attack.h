#pragma once

#include "PlayerState_A_AttackBase.h"

enum class  PlayerState_Enum;

// �o�����̍U�����
class PlayerState_A_Attack : public PlayerState_A_AttackBase {
public:
	// �R���X�g���N�^
	PlayerState_A_Attack(Vector3& pos, Matrix& mat, PlayerMotionID motion, PlayerState_Enum next);
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
	PlayerMotionID mMotion;
	PlayerState_Enum mNextState;
};
