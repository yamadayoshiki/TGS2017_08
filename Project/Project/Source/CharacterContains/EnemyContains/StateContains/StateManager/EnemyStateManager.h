#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Entity/Enemys/Base/EnemyBasePtr.h"
#include "../States/EnemyStateName.h"

//エネミーステートマネージャー
class EnemyStateManager : public StateMgr
{
public:
	// デフォルトコンストラクタ
	EnemyStateManager();
	//現在Stateの取得
	EnemyStateName GetCurStateName() const;
};

#endif