#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"

//コンストラクタ
PlayerStateManager::PlayerStateManager() {}

//コンストラクタ
PlayerStateManager::PlayerStateManager(GSvector2 & position,GSmatrix4& matrix, GameManager* gameManager)
{
	//ステートの追加
	add(PlayerStateName::Idol, std::make_shared<PlayerState_Idol>(position, matrix,gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix,gameManager));
	add(PlayerStateName::Run , std::make_shared<PlayerState_Run> (position, matrix,gameManager));
}