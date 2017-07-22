#ifndef ENEMYCOMMANDENEMY02STANDBY_H_
#define ENEMYCOMMANDENEMY02STANDBY_H_

#include "../../Base/EnemyCommandBase.h"
#include "../../../../../../Utility/FourDirection/FourDirection.h"

//エネミー02待機
class EnemyCommandEnemy02Standby : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandEnemy02Standby(
		const EnemyBasePtr& enemy,
		const FourDirection turnDirection);

	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param)override;

protected:
	FourDirection m_TurnDiretion;
};

#endif // !ENEMYCOMMANDENEMY02STANDBY_H_
