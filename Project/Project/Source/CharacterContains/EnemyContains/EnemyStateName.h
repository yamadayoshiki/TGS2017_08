#ifndef ENEMYSTATENAME_H_
#define ENEMYSTATENAME_H_

enum class EnemyStateName
{
	//共通
	Idle,				//その場に止まる
	Move,				//動く
	Caught,				//挟まれている
	Thrown,				//投げられている
	Crush,				//砕かれる
	Dead,				//死に
	None,				//ダミー

	//突撃
	Rush_Preliminary,	//突撃準備
	Rush,				//突撃

	//射撃
	Shot,				//射撃
};

#endif // !ENEMYSTATENAME_H_