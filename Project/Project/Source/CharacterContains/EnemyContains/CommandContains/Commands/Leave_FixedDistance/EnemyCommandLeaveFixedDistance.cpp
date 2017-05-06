#include "EnemyCommandLeaveFixedDistance.h"

//�R���X�g���N�^
EnemyCommandLeaveFixedDistance::EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	:EnemyCommandBase(enemy) {

}

//�e��ŗL�̏�����
void EnemyCommandLeaveFixedDistance::OnInitialize() {

}

//�X�V
void EnemyCommandLeaveFixedDistance::Update(float deltaTime) {

}

//�I��
void EnemyCommandLeaveFixedDistance::Finalize() {

}

//�I���`�F�b�N
bool EnemyCommandLeaveFixedDistance::IsEnd() {
	return false;
}

//���߃X�e�[�g
EnemyStateName EnemyCommandLeaveFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::Move;
}

//�ڕW���W�̐ݒ�
void EnemyCommandLeaveFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//����鋗���̐ݒ�
void EnemyCommandLeaveFixedDistance::SetFixedDistance(const float fixedDistance) {
	m_FixedDistance = fixedDistance;
}