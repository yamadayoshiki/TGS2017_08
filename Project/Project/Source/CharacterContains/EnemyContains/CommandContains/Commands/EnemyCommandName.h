#ifndef ENEMYCOMMANDNAME_H_
#define ENEMYCOMMANDNAME_H_

//エネミーに対する入力コマンド
enum class EnemyCommandName
{
	Straight,						//直進

	AlongWallMoveClockwise,			//時計回りに壁沿い移動
	AlongWallMoveAntiClockwise,		//半時計周りに壁沿い移動
	AlongWallMoveShoest,			//最短ルートで壁沿い移動
	AlongWall,						//壁沿い

	Standby,						//待機

	ClockwiseRotation90,	//時計回りに90度回転
	AntiClockwiseRotation90,//反時計回りに90度回転
	ReverseRotation,		//反転

	SpinMove,				//スピン状態で移動

	None,					//何もない
};

#endif