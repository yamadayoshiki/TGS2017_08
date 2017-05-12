#include "EnemyCommandRotation.h"
#include "../../../Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyCommandRotation::EnemyCommandRotation(const EnemyBasePtr& enemy, const float angle, const float endTimer)
	: EnemyCommandBase(enemy)
	, m_Angle(angle)
	, m_Angle_PerFrame(angle / endTimer)
	, m_EndTimer(endTimer)
	, m_Timer(0) {
}

//�X�V
void EnemyCommandRotation::Update(float deltaTime) {
	//��]
}

//�I��
void EnemyCommandRotation::Finalize() {
}

//�e��ŗL�̏�����
void EnemyCommandRotation::OnInitialize() {
	m_Timer = 0;
}