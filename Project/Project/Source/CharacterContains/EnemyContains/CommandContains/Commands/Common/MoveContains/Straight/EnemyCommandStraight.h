#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandMoveBase.h"
#include "../../../../../../../Map/MapType.h"

//直進クラス
class EnemyCommandStraight :public EnemyCommandMoveBase
{
public:
	//コンストラクタ
	EnemyCommandStraight(
		const EnemyBasePtr& enemy,
		const MapType type);
protected:
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//次の目標地点を設定する
	virtual void SetNextTargetPos() override;
protected:
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();
};

#endif