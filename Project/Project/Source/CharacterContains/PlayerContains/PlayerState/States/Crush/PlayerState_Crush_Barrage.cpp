#include "PlayerState_Crush_Barrage.h"


//�R���X�g���N�^
PlayerState_Crush_Barrage::PlayerState_Crush_Barrage(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(player, gameManager)
{

}

//�e��ԓƎ��̏�����
void PlayerState_Crush_Barrage::onUniqueInit()
{
}

//�X�V����
void PlayerState_Crush_Barrage::onUpdate(float deltaTime)
{
	change(PlayerStateName::Rounds);
}
