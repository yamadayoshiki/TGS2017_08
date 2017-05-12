#include "EnemyCommandStraight.h"

//�R���X�g���N�^
EnemyCommandStraight::EnemyCommandStraight(const EnemyBasePtr& enemy, GSvector2 velocity)
	:EnemyCommandBase(enemy) {
	m_Velocity = velocity;
}

//�X�V
void EnemyCommandStraight::Update(float deltaTime) {
	//���ʂɕǂ����邩���o

}

//�I��
void EnemyCommandStraight::Finalize() {

}

//�e��ŗL�̏�����
void EnemyCommandStraight::OnInitialize() {

}

//���ʂɕǂ��������ꍇ�̃��A�N�V����
void EnemyCommandStraight::HitWallReaction() {
	TurnBack();
}

//�܂�Ԃ�
void EnemyCommandStraight::TurnBack() {
	m_Velocity = -m_Velocity;
}