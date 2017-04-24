#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"

//コンストラクタ
PlayerStateManager::PlayerStateManager() {}

//コンストラクタ
PlayerStateManager::PlayerStateManager(GSvector2 & position,GSmatrix4& matrix, IGameManagerPtr gameManager)
{
	//ステートの追加

	//通常状態
	add(PlayerStateName::Idol, std::make_shared<PlayerState_Idol>(position, matrix,gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix,gameManager));
	add(PlayerStateName::Run , std::make_shared<PlayerState_Run> (position, matrix,gameManager));
	add(PlayerStateName::Open, std::make_shared<PlayerState_Open>(position, matrix, gameManager));

	//アームを開いている状態
	add(PlayerStateName::O_Idol, std::make_shared<PlayerState_O_Idol>(position, matrix, gameManager));
	add(PlayerStateName::O_Walk, std::make_shared<PlayerState_O_Walk>(position, matrix, gameManager));
	add(PlayerStateName::O_Run,  std::make_shared<PlayerState_O_Run> (position, matrix, gameManager));

}