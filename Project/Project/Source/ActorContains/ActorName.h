#ifndef ACTORNAME_H_
#define ACTORNAME_H_

enum class ActorName
{
	None = 0,

	/* UIグループ */
	UI_Manager,
	UI_Selector,
	UI_Button,
	UI_Sprite, 
	UI_Text,

	/* エフェクトグループ */
	Explosion = 80,
	Charge,
	Crush,
	Respawn,
	Hajiki,
	Pop,

	/* プレイヤーグループ */
	PlayerManager = 90,		//プレイヤー
	Player,					//プレイヤー
	Player_Arm,				//アーム

	BreakWall,

	/* エネミーグループ */
	EnemyManager = 100,
	Enemy_01,			//横から挟めないやつ
	Enemy_02,			//回転しながら打つやつ
	Enemy_03,			//ストーカー
	Enemy_04,			//挟まれたら動くやつ
	Enemy_05,			//往復するやつ
	Enemy_06,			//親機
	Enemy_07,			//
	Enemy_08,
	Enemy_09,
	Enemy_10,
};

#endif // !ACTORNAME_H_