#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandNull :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandNull(const EnemyBasePtr& enemy)
		:EnemyCommandBase(enemy) {}
	//各種固有の初期化
	void OnInitialize() override { m_IsEnd = true; }
};


#endif
