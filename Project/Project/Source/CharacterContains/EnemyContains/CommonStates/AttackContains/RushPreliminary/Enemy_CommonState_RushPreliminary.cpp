#include "Enemy_CommonState_RushPreliminary.h"

//�R���X�g���N�^
Enemy_CommonState_RushPreliminary::Enemy_CommonState_RushPreliminary(
	GSvector2& pos, 
	GSmatrix4& mat)
	:Enemy_CommonState_AttackBase(pos,mat){
}

// �e��ԓƎ��̏�����
void Enemy_CommonState_RushPreliminary::onUniqueInit(Actor & actor) {}
void Enemy_CommonState_RushPreliminary::onUpdate(Actor & actor, float deltaTime)
{
}
// �X�V����
void onUpdate(Actor & actor, float deltaTime) {}
// �Փ˔���
void Enemy_CommonState_RushPreliminary::onCollide(const Actor & other) {}
// �I�����̏���
void Enemy_CommonState_RushPreliminary::onEnd() {}
// ���͏���
void Enemy_CommonState_RushPreliminary::onInput() {}