#ifndef PLAYER_STATE_MANAGER_H_
#define PLAYER_STATE_MANAGER_H_

#include"../../../ActorContains/State/Base/StateMgr.h"
#include<gslib.h>
#include"../../../Base/GameManagerContains/GameManager/GameManager.h"

class PlayerStateManager :public StateMgr
{
public:
	//�R���X�g���N�^
	PlayerStateManager();
	//�R���X�g���N�^
	PlayerStateManager(GSvector2& position,GSmatrix4& matrix,GameManager* gameManager);
};
#endif // !PLAYER_STATE_MANAGER_H_