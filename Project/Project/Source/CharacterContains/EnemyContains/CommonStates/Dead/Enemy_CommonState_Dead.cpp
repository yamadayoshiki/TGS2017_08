#include "Enemy_CommonState_Dead.h"

//�R���X�g���N�^
Enemy_CommonState_Dead::Enemy_CommonState_Dead(
	GSvector2& pos, 
	GSmatrix4& mat) 
:Enemy_BaseState(pos,mat){

}
// �e��ԓƎ��̏�����
void Enemy_CommonState_Dead::unique_init(Actor & actor) {
}
// �X�V����
void Enemy_CommonState_Dead::update(Actor & actor, float deltaTime) {
}
// �Փ˔���
void Enemy_CommonState_Dead::collide(const Actor & other) {

}
// �I�����̏���
void Enemy_CommonState_Dead::end() {

}