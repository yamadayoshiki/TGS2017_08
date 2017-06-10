#include "EnemyStateCrushSpin.h"
//�R���X�g���N�^
EnemyStateCrushSpin::EnemyStateCrushSpin(const EnemyBasePtr & enemy, int limitCounter)
	: EnemyStateCrushStandard(enemy)
	, m_Counter(0)
	, m_LimitCounter(m_LimitCounter) {
}

//�e��ŗL�̏�����
void EnemyStateCrushSpin::unique_init() {
	//���[�V�����̕ύX

	//���܂ꂽ�񐔉��Z
	m_Counter++;
}

void EnemyStateCrushSpin::update(float deltaTime) {
	//�w��񐔂ɒB�����ꍇ�X�s���ɐ؂�ւ�
	if (m_Counter >= m_LimitCounter)
		change(EnemyStateName::Spin);

	else
		change(EnemyStateName::Caught);
}
