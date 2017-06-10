#pragma once

enum class EventMessage {
	SELECT,
	END_SCENE,

	MapDataUpdate,		//マップデータ変更

	PLAYER_ROUNDS,		//挟む
	PLAYER_CRUSH,		//潰す
	PLAYER_RELEASE,		//離す
	PLAYER_ROUNDSLOST,	//挟んでいたものがなくなる

	ENEMY02_DEAD,		//エネミー02が死んだ
	ENEMY_REPEL,		//弾く

	ENEMY_SPIN,			//スピン
	ENEMY_COMMAND_DEAD,	//コマンド側から死ぬ命令
};