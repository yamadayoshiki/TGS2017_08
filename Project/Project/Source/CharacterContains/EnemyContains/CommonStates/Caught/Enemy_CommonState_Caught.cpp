#include "Enemy_CommonState_Caught.h"
//�R���X�g���N�^
Enemy_CommonState_Caught::Enemy_CommonState_Caught(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}
// �e��ԓƎ��̏�����
void Enemy_CommonState_Caught::unique_init(Actor & actor)
{}
// �X�V����
void Enemy_CommonState_Caught::update(Actor & actor, float deltaTime) {}
// �Փ˔���
void Enemy_CommonState_Caught::collide(const Actor & other) {}
// �I�����̏���
void Enemy_CommonState_Caught::end() {}