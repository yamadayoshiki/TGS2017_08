#include "Enemy_CommonState_Thrown.h"

//�R���X�g���N�^
Enemy_CommonState_Thrown::Enemy_CommonState_Thrown(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}
// �e��ԓƎ��̏�����
void Enemy_CommonState_Thrown::unique_init(Actor & actor) {
}
// �X�V����
void Enemy_CommonState_Thrown::update(Actor & actor, float deltaTime) {
}
// �Փ˔���
void Enemy_CommonState_Thrown::collide(const Actor & other) {}
// �I�����̏���
void Enemy_CommonState_Thrown::end() {
}