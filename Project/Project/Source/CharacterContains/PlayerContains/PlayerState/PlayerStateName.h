#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//通常状態(アームを開いていない状態)
	Idol,		//静止状態
	Walk,		//移動状態(歩く)
	Run,		//移動状態(走る)
	Open,		//アームを開いてる状態
	Closed,		//アームを閉めている状態
	Rounds,		//はさんでいる状態
	Crush,		//潰す状態
	Throw,		//投げる状態
	Damage,		//ダメージ状態
	Dead,		//死に
				
	//アームが開いている状態
	A_Idol,			//静止状態
	A_Walk,			//移動状態(歩く)
	A_Run,			//移動状態(走る)

	None		//ダミー
};
#endif // !PLAYER_STATE_NAME

