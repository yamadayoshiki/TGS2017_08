#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Enemys/Base/EnemyBasePtr.h"

//先行宣言
struct GSvector2;
struct GSmatrix4;

//エネミーステートマネージャー
class EnemyStateManager :public StateMgr
{
public:
	// デフォルトコンストラクタ
	EnemyStateManager();
	// コンストラクタ
	EnemyStateManager(const EnemyBasePtr& enemy);
};

#endif
