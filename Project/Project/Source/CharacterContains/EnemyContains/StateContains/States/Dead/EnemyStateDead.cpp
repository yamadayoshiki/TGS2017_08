#include "EnemyStateDead.h"

//�R���X�g���N�^
EnemyStateDead::EnemyStateDead(
	const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {

}
// �e��ԓƎ��̏�����
void EnemyStateDead::unique_init() {
	//�A�j���[�V�����̕ύX

}
// �X�V����
void EnemyStateDead::update(float deltaTime) {
	//�A�j���[�V�������I��������Actor����폜

}
// �Փ˔���
void EnemyStateDead::collide(const Actor & other) {

}
// �I�����̏���
void EnemyStateDead::end() {

}