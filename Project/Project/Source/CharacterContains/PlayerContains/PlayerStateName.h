#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	Idol,		//静止状態
	Move,		//移動状態
	Open,		//アームを開いてる状態
	Closed,		//アームを閉めている状態
	Rounds,		//はさんでいる状態
	Crush,		//潰す状態
	Throw,		//投げる状態
	Dead,		//死に
	None		//ダミー
};
#endif // !PLAYER_STATE_NAME

