#include"PlayerState_Damage.h"

//�R���X�g���N�^
PlayerState_Damage::PlayerState_Damage(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Damage::unique_init()
{
	gsPlaySE(SE_PLAYER_EXPLOSION);
	m_Parameter.m_Remaining -= 1;
	p_Player.lock()->setPosition(m_Parameter.m_StratPosition);
}
//�X�V����
void PlayerState_Damage::update(float deltaTaime)
{
	if (m_Parameter.m_Remaining < 0) {
		change(PlayerStateName::Dead);
		return;
	}
		change(PlayerStateName::Invincible);
}
//�Փ˔���
void PlayerState_Damage::collide(const Actor& other) {}
//�I������
void PlayerState_Damage::end() {}
//���͏���
void PlayerState_Damage::input() {}