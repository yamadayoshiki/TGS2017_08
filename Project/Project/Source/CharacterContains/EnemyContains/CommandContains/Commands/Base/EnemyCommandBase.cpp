#include "EnemyCommandBase.h"

//�R���X�g���N�^
EnemyCommandBase::EnemyCommandBase(const EnemyBasePtr& enemy)
	:p_Enemy(enemy)
	, m_Velocity(GSvector2(0.0f, 0.0f))
	, m_RotateAngle(0.0f) {
}

//������
void EnemyCommandBase::Initialize() {
	OnInitialize();
}

//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
GSvector2 EnemyCommandBase::GetVelocity() const {
	return m_Velocity;
}

//��]�p�x�̎擾
float EnemyCommandBase::GetRotateAngle() const {
	return m_RotateAngle;
}