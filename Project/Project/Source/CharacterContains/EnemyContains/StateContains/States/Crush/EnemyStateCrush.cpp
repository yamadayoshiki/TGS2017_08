#include "EnemyStateCrush.h"

//�R���X�g���N�^
EnemyStateCrush::EnemyStateCrush(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateCrush::unique_init() {
	//���[�V�����̕ύX

}

// �X�V����
void EnemyStateCrush::update(float deltaTime) {
	//�_���[�W�ɂ��HP�̌���


	//�����ꂽ��ҋ@��ԂɑJ��

}

// �Փ˔���
void EnemyStateCrush::collide(const Actor & other) {
}

// �I�����̏���
void EnemyStateCrush::end() {
}

