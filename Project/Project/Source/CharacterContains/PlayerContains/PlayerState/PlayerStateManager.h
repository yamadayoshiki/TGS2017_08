#ifndef PLAYER_STATE_MANAGER_H_
#define PLAYER_STATE_MANAGER_H_

#include"../../../ActorContains/State/Base/StateMgr.h"
#include<gslib.h>


class PlayerStateManager :public StateMgr
{
public:
	//�R���X�g���N�^
	PlayerStateManager();
	//�R���X�g���N�^
	PlayerStateManager(GSvector2& position);
};
#endif // !PLAYER_STATE_MANAGER_H_