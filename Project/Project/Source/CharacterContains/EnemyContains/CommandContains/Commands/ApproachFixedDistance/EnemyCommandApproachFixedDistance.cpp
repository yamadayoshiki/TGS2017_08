#include "EnemyCommandApproachFixedDistance.h"

//�R���X�g���N�^
EnemyCommandApproachFixedDistance::EnemyCommandApproachFixedDistance(const EnemyBasePtr& enemy, float fixedDistance)
	: EnemyCommandBase(enemy)
	, m_TargetPos(GSvector2(0.0f, 0.0f))
	, m_FixedDistance(fixedDistance) {
}

//�e��ŗL�̏�����
void EnemyCommandApproachFixedDistance::OnInitialize() {

}

//�X�V
void EnemyCommandApproachFixedDistance::Update(float deltaTime) {

}

//�I��
void EnemyCommandApproachFixedDistance::Finalize() {
}

//�I���`�F�b�N
bool EnemyCommandApproachFixedDistance::IsEnd() {
	return false;
}

//���߃X�e�[�g
EnemyStateName EnemyCommandApproachFixedDistance::GetCurrentStateName() const {
	return EnemyStateName::Move;
}

//�ڕW���W�̎w��
void EnemyCommandApproachFixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//�߂Â������̐ݒ�
void EnemyCommandApproachFixedDistance::SetFixedDistance(float fixedDistance) {
	m_FixedDistance = fixedDistance;
}