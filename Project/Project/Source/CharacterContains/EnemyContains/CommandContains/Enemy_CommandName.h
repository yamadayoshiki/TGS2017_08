#ifndef ENEMY_COMMANDNAME_H_
#define ENEMY_COMMANDNAME_H_

//エネミーに対する入力コマンド
enum class Enemy_CommandName
{
	//移動
	Idle,					//止まる
	Approach_FixedDistance,	//一定距離まで近づく
	Leave_FixedDistance,	//一定距離以上離れる

	//攻撃
	Rush,					//突撃する
	Shot,					//射撃する
};

#endif // !ENEMY_COMMANDNAME_H_
