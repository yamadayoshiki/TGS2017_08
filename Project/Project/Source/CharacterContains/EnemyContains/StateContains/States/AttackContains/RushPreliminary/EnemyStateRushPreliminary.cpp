#include "EnemyStateRushPreliminary.h"

//�R���X�g���N�^
EnemyStateRushPreliminary::EnemyStateRushPreliminary(
	const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy){
}

// �e��ԓƎ��̏�����
void EnemyStateRushPreliminary::onUniqueInit() {}
// �X�V
void EnemyStateRushPreliminary::onUpdate(float deltaTime){}
// �Փ˔���
void EnemyStateRushPreliminary::onCollide(const Actor & other) {}
// �I�����̏���
void EnemyStateRushPreliminary::onEnd() {}
// ���͏���
void EnemyStateRushPreliminary::onInput() {}