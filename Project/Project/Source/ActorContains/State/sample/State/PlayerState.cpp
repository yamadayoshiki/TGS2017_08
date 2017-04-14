#include "PlayerState.h"

#include "../../../../World/World.h"
#include "../../../../Input/InputMgr.h"

// �R���X�g���N�^
PlayerState::PlayerState(Vector3& pos, Matrix& mat):
mPosition(pos), mRotation(mat), mAngle(0), mVelocity(Vector3::Zero) {}

// �p�b�h���͏���
void PlayerState::input(){}

// ���[�V�����̐؂�ւ�
void PlayerState::change_motion(Actor & actor, const PlayerMotionID id, const float speed){
	// ���[�V�����̐؂�ւ�
	actor.setMotion(static_cast<int>(id), speed);
}

// �ړ�����
void PlayerState::move(Actor & actor, float deltaTime, float speed){
	// ���͂��Ȃ��ꍇ��return
	if (InputMgr::GetInstance().AnalogPadVectorL().Length() <= 0)return;

	// �J�������擾
	auto camera = actor.getWorld()->getCamera();
	// �擾�ł��Ȃ��ꍇ��return
	if (camera == nullptr) return;

	// ���͏��𑬓x�ɕϊ�
	mVelocity = (camera->getPose().Forward() * InputMgr::GetInstance().AnalogPadVectorL().z + camera->getPose().Right() * InputMgr::GetInstance().AnalogPadVectorL().x) * Vector3(1, 0, 1);

	// �L�����N�^�́{Z�����̃x�N�g���ƁA���͂̑��x�̐��K���̊O��
	Vector3 forward_cross_target = Vector3::Cross(mRotation.Forward(), -mVelocity.Normalize());
	// �L�����N�^�́{Y�����̃x�N�g���ƁAforward_cross_target�̓���
	float up_dot_cross = Vector3::Dot(mRotation.Up(), forward_cross_target);
	// ��]�p�x�����߂�
	mAngle = Vector3::Angle(mRotation.Forward(), -mVelocity.Normalize()) * MathHelper::Sign(up_dot_cross);

	// �L�����N�^��Y���𒆐S�ɉ�]
	mRotation *= Matrix::CreateFromAxisAngle(mRotation.Up(), mAngle);
	// ��]�s��̐��K��
	mRotation.NormalizeRotationMatrix();

	// ���x�����W�ɉ��Z
	mPosition += mVelocity * speed;
}

// �o������(�p�b�h)
bool PlayerState::awake_pad(){
	bool r_1 = InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_R1);
	bool l_1 = InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1);
	return r_1 && l_1;
}





