#include "EnemyStateThrown.h"

//�R���X�g���N�^
EnemyStateThrown::EnemyStateThrown(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}
// �e��ԓƎ��̏�����
void EnemyStateThrown::unique_init() {
}
// �X�V����
void EnemyStateThrown::update(float deltaTime) {
}
// �Փ˔���
void EnemyStateThrown::collide(const Actor & other) {}
// �I�����̏���
void EnemyStateThrown::end() {
}