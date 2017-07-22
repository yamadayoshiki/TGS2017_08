#ifndef ENEMYCOMMANDRETURNTOTHEREGULARPOSITION_H_
#define ENEMYCOMMANDRETURNTOTHEREGULARPOSITION_H_

#include "../Base/EnemyCommandMoveBase.h"

//マス準拠の正規位置に戻る
class EnemyCommandReturnRegularPos : public EnemyCommandMoveBase
{
public:
	//コンストラクタ
	EnemyCommandReturnRegularPos(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
protected:
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//次の目標地点を設定する
	virtual void SetNextTargetPos() override;
};

#endif