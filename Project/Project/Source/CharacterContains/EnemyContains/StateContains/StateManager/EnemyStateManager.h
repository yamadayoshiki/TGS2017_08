#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Enemys/Base/EnemyBasePtr.h"

//先行宣言
struct GSvector2;
struct GSmatrix4;
enum class EnemyStateName;

//エネミーステートマネージャー
class EnemyStateManager :public StateMgr
{
public:
	// デフォルトコンストラクタ
	EnemyStateManager();
};

#endif