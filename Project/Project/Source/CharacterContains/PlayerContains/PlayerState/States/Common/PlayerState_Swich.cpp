#include"PlayerState_Swich.h"

//�R���X�g���N�^
PlayerState_Swich::PlayerState_Swich(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, player, gameManager) {
}

//�e��ԓƎ��̏�����
void PlayerState_Swich::unique_init()
{

}

//�X�V����
void PlayerState_Swich::update(float deltaTaime)
{
	if (m_Flag == true) {
		change(PlayerStateName::R_Idle);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//�Փ˔���
void PlayerState_Swich::collide(const Actor& other)
{
	if (m_Children[ActorName::Player_Arm]->isCollide(other)) {
		m_Flag = true;
		//����ɋ��񂾏��𑗂�
	}
}