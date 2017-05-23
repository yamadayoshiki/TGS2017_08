#ifndef ENMYCOMMANDSTRAIGHT_H_
#define ENMYCOMMANDSTRAIGHT_H_

#include "../Base/EnemyCommandBase.h"
#include "../../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../../Map/MapType.h"

//直進クラス
class EnemyCommandStraight :public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandStraight(
		const EnemyBasePtr& enemy,
		const MapType type);
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
	//目標地点に到着したリアクション
	virtual void ArriveReaction();
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();
	//次の目標地点を設定する
	void SetNextTargetPos();

protected:
	GSvector2 m_NextTargetPos;		//次の目標地点
	MapType m_Type;					//マップタイプ
};

#endif
