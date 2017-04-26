#include "Enemy_Command_Approach_FixedDistance.h"

//�R���X�g���N�^
Enemy_Command_Approach_FixedDistance::Enemy_Command_Approach_FixedDistance(float fixedDistance)
	: Enemy_Command_Base()
	, m_TargetPos(GSvector2(0.0f, 0.0f))
	, m_FixedDistance(fixedDistance) {
}

//�X�V
void Enemy_Command_Approach_FixedDistance::Update() {

}

//�I��
void Enemy_Command_Approach_FixedDistance::Finalize() {
}

//���߃X�e�[�g
EnemyStateName Enemy_Command_Approach_FixedDistance::GetCurrentStateName() {
	return EnemyStateName::Move;
}

//�ڕW���W�̎w��
void Enemy_Command_Approach_FixedDistance::SetTargetPos(const GSvector2& targetPos) {
	m_TargetPos = targetPos;
}

//�e��ŗL�̏�����
void Enemy_Command_Approach_FixedDistance::OnInitialize() {

}