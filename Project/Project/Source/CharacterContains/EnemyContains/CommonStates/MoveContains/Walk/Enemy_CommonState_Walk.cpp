#include "Enemy_CommonState_Walk.h"

//�R���X�g���N�^
Enemy_CommonState_Walk::Enemy_CommonState_Walk(GSvector2& pos, GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat)
{
}

// �e��ԓƎ��̏�����
void Enemy_CommonState_Walk::onUniqueInit(Actor & actor)
{

}

// �X�V����
void Enemy_CommonState_Walk::onUpdate(Actor& actor, float deltaTime)
{

}