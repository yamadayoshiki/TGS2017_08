#include "Enemy_CommonState_Run.h"

//�R���X�g���N�^
Enemy_CommonState_Run::Enemy_CommonState_Run(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat) {
}
// �e��ԓƎ��̏�����
void Enemy_CommonState_Run::onUniqueInit(Actor & actor) {

}
// �X�V����
void Enemy_CommonState_Run::onUpdate(Actor & actor, float deltaTime) {
}