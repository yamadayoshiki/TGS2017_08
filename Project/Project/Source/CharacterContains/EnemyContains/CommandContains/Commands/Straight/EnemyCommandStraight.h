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
	EnemyCommandStraight(const EnemyBasePtr& enemy, const FourDirection front, const MapType type);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//正面に壁があった場合のリアクション
	virtual void HitWallReaction();
	//折り返す
	void TurnBack();
	//正面に壁があるか
	bool CheckFrontWall();
	//次の目標地点を設定する
	void SetNextTargetPos();

protected:
	GSvector2 m_NextTargetPos;		//次の目標地点
	FourDirection m_CurFront;		//現在向いている方向
	MapType m_Type;
};

#endif // !ENMYCOMMANDSTRAIGHT_H_
