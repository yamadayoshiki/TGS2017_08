#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"
#include "../../../ActorContains/State/Base/State.h"

//コンストラクタ
PlayerStateManager::PlayerStateManager() {}

//コンストラクタ
PlayerStateManager::PlayerStateManager(GSvector2 & position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
{
	//ステートの追加

	//通常状態
	add(PlayerStateName::Close, std::make_shared<PlayerState_Close>(position, matrix, player, gameManager));
	add(PlayerStateName::Idle, std::make_shared<PlayerState_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::Run, std::make_shared<PlayerState_Run>(position, matrix, player, gameManager));
	add(PlayerStateName::Dash, std::make_shared<PlayerState_Dash>(position, matrix, player, gameManager));

	//アームを開いている状態
	add(PlayerStateName::Open, std::make_shared<PlayerState_Open>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Idle, std::make_shared<PlayerState_O_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Walk, std::make_shared<PlayerState_O_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Run, std::make_shared<PlayerState_O_Run>(position, matrix, player, gameManager));

	//はさんでいる状態
	add(PlayerStateName::Rounds, std::make_shared<PlayerState_Round>(position, matrix, player, gameManager));
	add(PlayerStateName::R_Idle, std::make_shared<PlayerState_R_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::R_Walk, std::make_shared<PlayerState_R_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::R_Run, std::make_shared<PlayerState_R_Run>(position, matrix, player, gameManager));

	//潰す状態
	add(PlayerStateName::Crush, std::make_shared<PlayerState_Crush>(position, matrix, player, gameManager));
	add(PlayerStateName::Crush_Barrage, std::make_shared<PlayerState_Crush_Barrage>(position, matrix, player, gameManager));
	add(PlayerStateName::Crush_Hold, std::make_shared<PlayerState_Crush_Hold>(position, matrix, player, gameManager));

	//共通
	add(PlayerStateName::Swich, std::make_shared<PlayerState_Swich>(position, matrix, player, gameManager));
	add(PlayerStateName::Release, std::make_shared<PlayerState_Release>(position, matrix, player, gameManager));
}

void PlayerStateManager::addChild(const ActorName & name, const ActorPtr & child) {
	mStates[(int)PlayerStateName::Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::Dash]->addChild(name, child);
	mStates[(int)PlayerStateName::Open]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Rounds]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Close]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush_Barrage]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush_Hold]->addChild(name, child);
	mStates[(int)PlayerStateName::Swich]->addChild(name, child);
	mStates[(int)PlayerStateName::Release]->addChild(name, child);
}
