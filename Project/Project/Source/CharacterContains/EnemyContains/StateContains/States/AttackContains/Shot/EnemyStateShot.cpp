#include "EnemyStateShot.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyStateShot::EnemyStateShot(const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy) {
}
// �e��ԓƎ��̏�����
void EnemyStateShot::onUniqueInit() {
	p_Enemy.lock()->Settexture("Attack");
}
// �X�V����
void EnemyStateShot::onUpdate(float deltaTime) {

}
// �Փ˔���
void EnemyStateShot::onCollide(const Actor & other) {

}
// �I�����̏���
void EnemyStateShot::onEnd() {
	p_Enemy.lock()->Settexture("Normal");
}
// ���͏���
void EnemyStateShot::onInput() {

}