#include"PlayerState_Damage.h"

//�R���X�g���N�^
PlayerState_Damage::PlayerState_Damage(GSvector2& position,GSmatrix4& matrix, IGameManager* gameManager)
	:PlayerState(position,matrix,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Damage::unique_init(Actor& actor)
{

}
//�X�V����
void PlayerState_Damage::update(Actor& actor, float deltaTaime)
{

}
//�Փ˔���
void PlayerState_Damage::collide(const Actor& other){}
//�I������
void PlayerState_Damage::end(){}
//���͏���
void PlayerState_Damage::input(){}