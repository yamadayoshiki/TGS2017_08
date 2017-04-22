#ifndef PLAYER_STATE_MANAGER_H_
#define PLAYER_STATE_MANAGER_H_

#include "../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../../ActorContains/State/Base/StateMgr.h"
#include<gslib.h>

class PlayerStateManager :public StateMgr
{
public:
	//�R���X�g���N�^
	PlayerStateManager();
	//�R���X�g���N�^
	PlayerStateManager(GSvector2& position,GSmatrix4& matrix,IGameManagerPtr gameManager);
};
#endif // !PLAYER_STATE_MANAGER_H_