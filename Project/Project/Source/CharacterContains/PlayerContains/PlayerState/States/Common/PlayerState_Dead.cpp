#include"PlayerState_Dead.h"

//�R���X�g���N�^
PlayerState_Dead::PlayerState_Dead(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dead::unique_init()
{
	p_Player.lock()->getWorld()->EndRequest(SceneName::GameOver);
}
//�X�V����
void PlayerState_Dead::update(float deltaTaime)
{
	//p_Player.lock()->dead();
}

//�I������
void PlayerState_Dead::end()
{
	
}