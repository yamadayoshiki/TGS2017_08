#include "PlayerStateManager.h"
#include"PlayerStateName.h"
#include"PlayerState_Path.h"

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager() {}

//�R���X�g���N�^
PlayerStateManager::PlayerStateManager(GSvector2 & position,GSmatrix4& matrix, IGameManagerPtr gameManager)
{
	//�X�e�[�g�̒ǉ�

	//�ʏ���
	add(PlayerStateName::Idol, std::make_shared<PlayerState_Idol>(position, matrix,gameManager));
	add(PlayerStateName::Walk, std::make_shared<PlayerState_Walk>(position, matrix,gameManager));
	add(PlayerStateName::Run , std::make_shared<PlayerState_Run> (position, matrix,gameManager));
	add(PlayerStateName::Open, std::make_shared<PlayerState_Awake>(position, matrix, gameManager));

	//�A�[�����J���Ă�����
	add(PlayerStateName::A_Idol, std::make_shared<PlayerState_A_Idol>(position, matrix, gameManager));
	add(PlayerStateName::A_Walk, std::make_shared<PlayerState_A_Walk>(position, matrix, gameManager));
	add(PlayerStateName::A_Run,  std::make_shared<PlayerState_A_Run> (position, matrix, gameManager));

}