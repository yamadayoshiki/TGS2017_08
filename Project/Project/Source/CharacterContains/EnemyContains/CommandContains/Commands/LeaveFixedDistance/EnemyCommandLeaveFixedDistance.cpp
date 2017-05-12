#include "EnemyCommandLeaveFixedDistance.h"

//�R���X�g���N�^
EnemyCommandLeaveFixedDistance::EnemyCommandLeaveFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	: EnemyCommandBase(enemy)
	, m_FixedDistance(fixedDistance) {

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

//���߃X�e�[�g
EnemyStateName EnemyCommandLeaveFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::None;
}

//�ڕW���W�̐ݒ�
void EnemyCommandLeaveFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_NextTargetPos = targetPos;
}

//����鋗���̐ݒ�
void EnemyCommandLeaveFixedDistance::SetFixedDistance(const float fixedDistance) {
	m_FixedDistance = fixedDistance;
}