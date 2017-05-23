#pragma once

enum class EventMessage {
	SELECT,
	END_SCENE,

	PLAYER_ROUNDS,		//挟む
	PLAYER_CRUSH,		//潰す
	PLAYER_RELEASE,		//離す
	PLAYER_ROUNDSLOST,	//挟んでいたものがなくなる

	ENEMY02_DEAD,		//エネミー02が死んだ
	ENEMY_REPEL,		//弾く
};