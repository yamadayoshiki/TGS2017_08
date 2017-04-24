#include "Enemy_Command_Approach_FixedDistance.h"

//�R���X�g���N�^
Enemy_Command_Approach_FixedDistance::Enemy_Command_Approach_FixedDistance()
	:Enemy_Command_Base() {
}

//�X�V
void Enemy_Command_Approach_FixedDistance::Update() {

}

//�I��
void Enemy_Command_Approach_FixedDistance::Finalize() {
	delete p_TargetPos;
}

//���߃X�e�[�g
EnemyStateName Enemy_Command_Approach_FixedDistance::GetCurrentStateName() {
	return EnemyStateName::Move;
}

//�ڕW���W�̎w��
void Enemy_Command_Approach_FixedDistance::SetTargetPos(GSvector2* targetPos) {

}

//�e��ŗL�̏�����
void Enemy_Command_Approach_FixedDistance::OnInitialize() {

}