#ifndef ENEMY_STATEMANAGER_H_
#define ENEMY_STATEMANAGER_H_

#include "../../../ActorContains/State/Base/StateMgr.h"

//先行宣言
struct GSvector2;
struct GSmatrix4;

class Enemy_StateManager:public StateMgr
{
public:
	// デフォルトコンストラクタ
	Enemy_StateManager();
	// コンストラクタ
	Enemy_StateManager(GSvector2& pos, GSmatrix4& mat);
};

#endif // !ENEMY_STATEMANAGER_H_
