#include"PlayerState_Damage.h"

//�R���X�g���N�^
PlayerState_Damage::PlayerState_Damage(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Damage::unique_init()
{

}
//�X�V����
void PlayerState_Damage::update(float deltaTaime)
{

}
//�Փ˔���
void PlayerState_Damage::collide(const Actor& other) {}
//�I������
void PlayerState_Damage::end() {}
//���͏���
void PlayerState_Damage::input() {}