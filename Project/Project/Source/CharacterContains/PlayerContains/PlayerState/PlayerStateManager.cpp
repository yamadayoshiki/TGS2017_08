#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"
#include "../../../ActorContains/State/Base/State.h"

//コンストラクタ
PlayerStateManager::PlayerStateManager() {}

//コンストラクタ
PlayerStateManager::PlayerStateManager(GSvector2 & position, GSmatrix4& matrix, IGameManagerPtr gameManager)
{
	//ステートの追加

	//通常状態
	add(PlayerStateName::Idol, std::make_shared<PlayerState_Idol>(position, matrix, gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix, gameManager));
	add(PlayerStateName::Run,  std::make_shared<PlayerState_Run> (position, matrix, gameManager));
	add(PlayerStateName::Open, std::make_shared<PlayerState_Open>(position, matrix, gameManager));

	//アームを開いている状態
	add(PlayerStateName::O_Idol, std::make_shared<PlayerState_O_Idol>(position, matrix, gameManager));
	add(PlayerStateName::O_Walk, std::make_shared<PlayerState_O_Walk>(position, matrix, gameManager));
	add(PlayerStateName::O_Run,  std::make_shared<PlayerState_O_Run> (position, matrix, gameManager));

	//はさんでいる状態
	add(PlayerStateName::R_Idol, std::make_shared<PlayerState_R_Idol>(position, matrix, gameManager));
	add(PlayerStateName::R_Walk, std::make_shared<PlayerState_R_Walk>(position, matrix, gameManager));
	add(PlayerStateName::R_Run, std::make_shared<PlayerState_R_Run>(position, matrix, gameManager));
}

void PlayerStateManager::addChild(const ActorName & name, const ActorPtr & child) {
	mStates[(int)PlayerStateName::Idol]->addChild(name, child);
	mStates[(int)PlayerStateName::Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::Open]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Idol]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Run]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Idol]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Run]->addChild(name, child);
}
