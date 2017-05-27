#ifndef ENEMYCOMMANDENEMY04STANDBY_H_
#define ENEMYCOMMANDENEMY04STANDBY_H_

#include "../../Base/EnemyCommandBase.h"

//3回挟まれたら指定方向に動く
class EnemyCommandEnemy04Standby : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandEnemy04Standby(
		const EnemyBasePtr& enemy,
		const FourDirection front);

	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param)override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;

	//目標地点に到着したリアクション
	virtual void ArriveReaction();
	//次の目標地点を設定する
	void SetNextTargetPos();

protected:
	FourDirection m_Front;	//指定方向
	int m_Counter;			//挟まれた回数
	bool m_Flag;			//正面が壁か
};

#endif // !ENEMYCOMMANDSTNDBY_H_

