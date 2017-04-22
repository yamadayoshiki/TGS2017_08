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
	add(PlayerStateName::Open, std::make_shared<PlayerState_Awake>(position, matrix, gameManager));

	//アームを開いている状態
	add(PlayerStateName::A_Idol, std::make_shared<PlayerState_A_Idol>(position, matrix, gameManager));
	add(PlayerStateName::A_Walk, std::make_shared<PlayerState_A_Walk>(position, matrix, gameManager));
	add(PlayerStateName::A_Run,  std::make_shared<PlayerState_A_Run> (position, matrix, gameManager));

}