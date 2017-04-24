#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//通常状態(アームを開いていない状態)
	Idol,		//静止状態
	Walk,		//移動状態(歩く)
	Run,		//移動状態(走る)
	Closed,		//アームを閉めている状態
				
	//アームが開いている状態
	Open,		//アームを開いてる状態
	O_Idol,			//静止状態
	O_Walk,			//移動状態(歩く)
	O_Run,			//移動状態(走る)

	//何か挟んでいる状態
	Rounds,		//はさんでいる状態
	R_Idol,		//静止状態
	R_Walk,		//移動状態(歩く)
	R_Run,		//移動状態(走る)
	Crush,		//潰す状態
	Throw,		//投げる状態

	//共通
	Damage,		//ダメージ状態
	Dead,		//死に
	None		//ダミー
};
#endif // !PLAYER_STATE_NAME

