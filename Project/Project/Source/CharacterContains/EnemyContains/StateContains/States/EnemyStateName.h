#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//共通
	Idle,				//その場に止まる
	Move,				//動く
	Caught,				//挟まれている
	Crush,				//砕かれる
	Repel,				//弾く
	Dead,				//死に
	None,				//ダミー
	Stop,				//止まる
	Damage,				//ダメージを受けている

	//突撃
	RushPreliminary,	//突撃準備
	Rush,				//突撃
	StickWall,			//壁に刺さっている

	//ノコノコスピン
	Spin,

	//射撃
	Shot,				//射撃
};

#endif