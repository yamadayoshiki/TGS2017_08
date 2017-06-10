#ifndef ENEMYCOMMANDPATROL_H_
#define ENEMYCOMMANDPATROL_H_

#include "../Base/EnemyCommandMoveBase.h"

//巡回マン
class EnemyCommandPatrol : public EnemyCommandMoveBase
{
public:
	//コンストラクタ
	EnemyCommandPatrol(
		const EnemyBasePtr& enemy,
		const MapType type);

	//目的地を設定
	void SetPatrolPos(const std::vector<GSvector2>& posList);
	//メッセージ処理
	virtual void handleMessage(EventMessage message,void* param) override;

protected:
	//目標地点に到着したリアクション
	virtual void ArriveReaction() override;
	//次の目標地点を設定する
	void SetNextTargetPos() override;

protected:
	std::vector<GSvector2> m_TargetPosList;			//巡回地点配列
	int m_CurListNum;								//現在の目標地点の巡回リスト上番号
};


#endif