#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"
#include "../../../ActorContains/State/Base/State.h"

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager() {}

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager(GSvector2 & position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
{
	//�X�e�[�g�̒ǉ�

	//�ʏ���
	add(PlayerStateName::Close, std::make_shared<PlayerState_Close>(position, matrix, player, gameManager));
	add(PlayerStateName::Idle, std::make_shared<PlayerState_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::Run, std::make_shared<PlayerState_Run>(position, matrix, player, gameManager));

	//�A�[�����J���Ă�����
	add(PlayerStateName::Open, std::make_shared<PlayerState_Open>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Idle, std::make_shared<PlayerState_O_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Walk, std::make_shared<PlayerState_O_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::O_Run, std::make_shared<PlayerState_O_Run>(position, matrix, player, gameManager));

	//�͂���ł�����
	add(PlayerStateName::R_Idle, std::make_shared<PlayerState_R_Idle>(position, matrix, player, gameManager));
	add(PlayerStateName::R_Walk, std::make_shared<PlayerState_R_Walk>(position, matrix, player, gameManager));
	add(PlayerStateName::R_Run, std::make_shared<PlayerState_R_Run>(position, matrix, player, gameManager));

	//�ׂ����
	add(PlayerStateName::Crush, std::make_shared<PlayerState_Crush>(position, matrix, player, gameManager));
	add(PlayerStateName::Crush_Barrage, std::make_shared<PlayerState_Crush_Barrage>(position, matrix, player, gameManager));
	add(PlayerStateName::Crush_Hold, std::make_shared<PlayerState_Crush_Hold>(position, matrix, player, gameManager));

	//����
	add(PlayerStateName::Swich, std::make_shared<PlayerState_Swich>(position, matrix, player, gameManager));
}

void PlayerStateManager::addChild(const ActorName & name, const ActorPtr & child) {
	mStates[(int)PlayerStateName::Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::Open]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Run]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::R_Run]->addChild(name, child);
	mStates[(int)PlayerStateName::Close]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush_Barrage]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush_Hold]->addChild(name, child);
	mStates[(int)PlayerStateName::Swich]->addChild(name, child);
}
