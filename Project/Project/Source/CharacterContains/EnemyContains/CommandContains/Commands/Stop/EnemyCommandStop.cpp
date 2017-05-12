#include "EnemyCommandStop.h"

//�R���X�g���N�^
EnemyCommandStop::EnemyCommandStop(const EnemyBasePtr& enemy, int stopTimer)
	: EnemyCommandBase(enemy)
	, m_EndTimer(0)
	, m_StopTimer(stopTimer) {
}

//�e��ŗL�̏�����
void EnemyCommandStop::OnInitialize() {
	m_EndTimer = 0;
}

//�X�V
void EnemyCommandStop::Update(float deltaTime) {
	//�^�C�}�[�̍X�V
	m_EndTimer++;
}

//�I��
void EnemyCommandStop::Finalize() {
}