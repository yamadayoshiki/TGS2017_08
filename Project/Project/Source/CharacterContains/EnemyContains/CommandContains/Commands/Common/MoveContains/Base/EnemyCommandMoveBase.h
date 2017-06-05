#ifndef ENEMYCOMMANDMOVEBASE_H_
#define ENEMYCOMMANDMOVEBASE_H_

#include "../../../Base/EnemyCommandBase.h"

//先行宣言
class Map;

//動きのあるコマンドの基底クラス
class EnemyCommandMoveBase : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandMoveBase(
		const EnemyBasePtr& enemy,
		const MapType type);

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;

protected:
	//目標地点に到着したリアクション
	virtual void ArriveReaction() = 0;
	//次の目標地点を設定する
	virtual void SetNextTargetPos() = 0;

protected:
	MapType m_Type;					//マップのタイプ
	GSvector2 m_NextTargetPos;		//目標地点
};

#endif // !ENEMYCOMMANDMOVEBASE_H_
