#include"PlayerState_Damage.h"

//�R���X�g���N�^
PlayerState_Damage::PlayerState_Damage(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Damage::unique_init()
{
	m_Parameter.m_Remainig -= 1;
	p_GameManager->SetPlayerParameter(m_Parameter);
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