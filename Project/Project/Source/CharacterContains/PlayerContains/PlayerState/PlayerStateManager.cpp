#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"
#include "../../../ActorContains/State/Base/State.h"

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager() {}

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager(const PlayerPtr& player, IGameManagerPtr gameManager)
{
	//�X�e�[�g�̒ǉ�

	//�ʏ���
	add(PlayerStateName::Close, std::make_shared<PlayerState_Close>(player, gameManager));
	add(PlayerStateName::Idle, std::make_shared<PlayerState_Idle>  (player, gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>  (player, gameManager));
	add(PlayerStateName::Dash, std::make_shared<PlayerState_Dash>  (player, gameManager));

	//�A�[�����J���Ă�����
	add(PlayerStateName::Open, std::make_shared<PlayerState_Open>    (player, gameManager));
	add(PlayerStateName::O_Idle, std::make_shared<PlayerState_O_Idle>(player, gameManager));
	add(PlayerStateName::O_Walk, std::make_shared<PlayerState_O_Walk>(player, gameManager));

	//�͂���ł�����
	add(PlayerStateName::Rounds, std::make_shared<PlayerState_Round> (player, gameManager));

	//�ׂ����
	add(PlayerStateName::Crush, std::make_shared<PlayerState_Crush>(player, gameManager));
	add(PlayerStateName::Crush_Barrage, std::make_shared<PlayerState_Crush_Barrage>(player, gameManager));

	//����
	add(PlayerStateName::Swich, std::make_shared<PlayerState_Swich>		(player, gameManager));
	add(PlayerStateName::Release, std::make_shared<PlayerState_Release> (player, gameManager));
	add(PlayerStateName::Invincible, std::make_shared<PlayerState_Invincible>(player, gameManager));
	add(PlayerStateName::Damage, std::make_shared<PlayerState_Damage>(player, gameManager));
	add(PlayerStateName::Dead, std::make_shared<PlayerState_Dead>(player, gameManager));
}

void PlayerStateManager::addChild(const ActorName & name, const ActorPtr & child) {
	mStates[(int)PlayerStateName::Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::Dash]->addChild(name, child);
	mStates[(int)PlayerStateName::Open]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Idle]->addChild(name, child);
	mStates[(int)PlayerStateName::O_Walk]->addChild(name, child);
	mStates[(int)PlayerStateName::Rounds]->addChild(name, child);
	mStates[(int)PlayerStateName::Close]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush]->addChild(name, child);
	mStates[(int)PlayerStateName::Crush_Barrage]->addChild(name, child);
	mStates[(int)PlayerStateName::Swich]->addChild(name, child);
	mStates[(int)PlayerStateName::Release]->addChild(name, child);
	mStates[(int)PlayerStateName::Invincible]->addChild(name, child);
	mStates[(int)PlayerStateName::Damage]->addChild(name, child);
	mStates[(int)PlayerStateName::Dead]->addChild(name, child);
}
