#include "Enemy_CommonState_Repel.h"

//�R���X�g���N�^
Enemy_CommonState_Repel::Enemy_CommonState_Repel(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}
// �e��ԓƎ��̏�����
void Enemy_CommonState_Repel::unique_init(Actor & actor) {
}
// �X�V����
void Enemy_CommonState_Repel::update(Actor & actor, float deltaTime) {
}
// �Փ˔���
void Enemy_CommonState_Repel::collide(const Actor & other) {
}
// �I�����̏���
void Enemy_CommonState_Repel::end() {
}