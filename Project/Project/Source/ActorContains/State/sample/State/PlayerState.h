#pragma once

#include "../../../State/Base/State.h"

enum class PlayerMotionID;

// �e�v���C���[�X�e�[�g�̊��N���X
class PlayerState : public State {
public:
	// �R���X�g���N�^
	PlayerState(Vector3& pos, Matrix& mat);
	// �p�b�h���͏���
	virtual void input() override;
protected:
	// ���[�V�����̐؂�ւ�
	void change_motion(Actor& actor, const PlayerMotionID id, const float speed = 1.0f);
	// �ړ�����
	void move(Actor & actor, float deltaTime, float speed = 1.0f);
	// �o������(�p�b�h)
	bool awake_pad();
protected:
	// ���W�̎Q��
	Vector3& mPosition;
	// �s��̎Q��
	Matrix&  mRotation;
	// ���x
	Vector3 mVelocity;
	// ��]�p�x
	float mAngle;
};