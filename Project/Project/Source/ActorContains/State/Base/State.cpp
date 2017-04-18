#include "State.h"

// �R���X�g���N�^
State::State() :
	m_ID(-1),
	m_NextID(-1),
	m_Timer(0), m_IsEnd(false) {}

// �S��ԋ��ʂ̏�����
void State::common_init(Actor & actor, const int id) {
	// �ϐ��̏�����
	m_ID = id;
	m_Timer = 0;
	m_IsEnd = false;
}

// ���͏���
void State::input() {}

// ���ԊǗ�
void State::timer(const float& deltaTime) {
	m_Timer += deltaTime;
}

// �X�e�[�g�̕ύX����
void State::change_int(const int id)
{
	change(id);
}

// �X�e�[�g���I���������ۂ�
bool State::isEnd() {
	return m_IsEnd;
}

// ���̃X�e�[�g�̗v�f
int State::next() const {
	return m_NextID;
}


