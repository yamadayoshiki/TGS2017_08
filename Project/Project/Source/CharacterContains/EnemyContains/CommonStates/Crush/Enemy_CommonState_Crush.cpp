#include "Enemy_CommonState_Crush.h"

//�R���X�g���N�^
Enemy_CommonState_Crush::Enemy_CommonState_Crush(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}

// �e��ԓƎ��̏�����
void Enemy_CommonState_Crush::unique_init(Actor & actor) {
}

// �X�V����
void Enemy_CommonState_Crush::update(Actor & actor, float deltaTime) {
}

// �Փ˔���
void Enemy_CommonState_Crush::collide(const Actor & other) {
}

// �I�����̏���
void Enemy_CommonState_Crush::end() {
}