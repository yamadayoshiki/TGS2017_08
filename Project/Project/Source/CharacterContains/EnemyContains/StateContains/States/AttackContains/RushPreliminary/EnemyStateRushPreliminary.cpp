#include "EnemyStateRushPreliminary.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../TextureContains/ITexture.h"
//�R���X�g���N�^
EnemyStateRushPreliminary::EnemyStateRushPreliminary(
	const EnemyBasePtr& enemy)
	:EnemyStateAttackBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateRushPreliminary::onUniqueInit() {
	//�e�N�X�`���ؑ�
	p_Enemy.lock()->Settexture("RushPreliminary");
}
// �X�V
void EnemyStateRushPreliminary::onUpdate(float deltaTime) {
	if (p_Enemy.lock()->getTexture()->GetLoopCount() >= 1) {
		change(EnemyStateName::Rush);
	}
}
// �Փ˔���
void EnemyStateRushPreliminary::onCollide(const Actor & other, const Body::ContactSet& contactSet) {}
// �I�����̏���
void EnemyStateRushPreliminary::onEnd() {
	//�e�N�X�`���ؑ�
	p_Enemy.lock()->Settexture("Rush");
}