#ifndef ENEMYCOMMANDNAME_H_
#define ENEMYCOMMANDNAME_H_

//エネミーに対する入力コマンド
enum class EnemyCommandName
{
	Stop,					//止まる
	ApproachFixedDistance,	//一定距離まで近づく
	LeaveFixedDistance,	//一定距離以上離れる

	MoveRightTargetPos,		//右の目標地点に動く
	MoveBaseTargetPos,		//元いた地点に動く
	MoveUpTargetPos,		//上の目標地点に動く

	Clockwise_90,			//時計回りに90度回転
	ChasePlayer,			//プレイヤーを追いかける

	Rush,					//突撃する
	Shot,					//射撃する

	None,					//何もない
};

#endif