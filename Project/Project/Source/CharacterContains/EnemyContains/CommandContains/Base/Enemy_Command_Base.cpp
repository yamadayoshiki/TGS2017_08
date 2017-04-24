#include "Enemy_Command_Base.h"

//�R���X�g���N�^
Enemy_Command_Base::Enemy_Command_Base()
	: m_IsEnd(false)
	, m_StateEnd(false) {
}

//������
void Enemy_Command_Base::Initialize() {
	m_IsEnd = false;
	m_StateEnd = false;
	OnInitialize();
}

//�I�����Ă��邩
bool Enemy_Command_Base::IsEnd() {
	return m_IsEnd;
}

//�ړ��x�N�g���̎擾
GSvector2& Enemy_Command_Base::GetVelocity() {
	return m_Velocity;
}

//�X�e�[�g�I���t���O�̐ݒ�
void Enemy_Command_Base::SetStateEnd(bool stateEnd) {
	m_StateEnd = stateEnd;
}