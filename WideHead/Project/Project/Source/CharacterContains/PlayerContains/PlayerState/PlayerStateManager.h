#ifndef PLAYER_STATE_MANAGER_H_
#define PLAYER_STATE_MANAGER_H_

#include "../../../Base/GameManagerContains/IGameManagerPtr.h"
#include"../../../ActorContains/State/Base/StateMgr.h"
#include<gslib.h>

#include "../Player/PlayerPtr.h"

class PlayerStateManager :public StateMgr
{
public:
	//コンストラクタ
	PlayerStateManager();
	//コンストラクタ
	PlayerStateManager(const Player_WPtr& player, IGameManagerPtr gameManager);
	void addChild(const ActorName& name, const ActorPtr& child);
};
#endif // !PLAYER_STATE_MANAGER_H_