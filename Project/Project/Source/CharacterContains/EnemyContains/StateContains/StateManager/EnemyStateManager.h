#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Enemys/Base/EnemyBasePtr.h"

//エネミーステートマネージャー
class EnemyStateManager :public StateMgr
{
public:
	// デフォルトコンストラクタ
	EnemyStateManager();
};

#endif