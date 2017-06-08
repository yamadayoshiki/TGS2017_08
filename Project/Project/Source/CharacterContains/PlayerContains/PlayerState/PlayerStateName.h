#ifndef PLAYER_STATE_NAME_H_
#define PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	//通常状態(アームを開いていない状態)
	Idle,				//静止状態
	Walk,				//移動状態(歩く)
	Dash,				//
	Close,				//アームを閉めている状態
				
	//アームが開いている状態
	Open,				//アームを開いてる状態
	O_Idle,				//静止状態
	O_Walk,				//移動状態(歩く)

	//何か挟んでいる状態
	Rounds,			//はさんでいる状態

	//潰す状態
	Crush,			//潰す状態
	Crush_After,	//潰した後の状態

	//共通
	Damage,			//ダメージ状態
	Release,		//離す状態
	Invincible,		//無敵状態
	Swich,			//切り替え
	Dead,			//死に
	None			//ダミー
};
#endif // !PLAYER_STATE_NAME

