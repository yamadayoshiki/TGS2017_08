#include"PlayerState_Dead.h"

//�R���X�g���N�^
PlayerState_Dead::PlayerState_Dead(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dead::unique_init()
{
	p_Player->getWorld()->EndRequest(SceneName::GameResult);
}
//�X�V����
void PlayerState_Dead::update(float deltaTaime)
{
	p_Player->dead();
}

//�I������
void PlayerState_Dead::end()
{
	
}