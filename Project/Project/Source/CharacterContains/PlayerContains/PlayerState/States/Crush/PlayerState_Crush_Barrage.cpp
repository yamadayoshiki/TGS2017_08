#include "PlayerState_Crush_Barrage.h"


//�R���X�g���N�^
PlayerState_Crush_Barrage::PlayerState_Crush_Barrage(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_CrushBase(position, matrix, player, gameManager)
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
