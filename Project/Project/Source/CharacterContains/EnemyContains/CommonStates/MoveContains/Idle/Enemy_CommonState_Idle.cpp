#include "Enemy_CommonState_Idle.h"

//�R���X�g���N�^
Enemy_CommonState_Idle::Enemy_CommonState_Idle(GSvector2& pos, GSmatrix4& mat)
	:Enemy_CommonState_MoveBase(pos, mat)
{
}

//�e��ԌŗL�̏�����
void Enemy_CommonState_Idle::onUniqueInit(Actor& actor)
{
	//�A�j���[�V�����̕ύX

}