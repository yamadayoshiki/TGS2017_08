#pragma once

#include "PlayerState_A_MoveBase.h"

// �o�����̕������
class PlayerState_A_Walk : public PlayerState_A_MoveBase {
public:
	// �R���X�g���N�^
	PlayerState_A_Walk(Vector3& pos, Matrix& mat);
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
};