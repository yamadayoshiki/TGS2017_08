#ifndef ACTORNAME_H_
#define ACTORNAME_H_

enum class ActorName
{
	/* プレイヤーグループ */
	Player = 0,			//プレイヤー
	Player_Arm,			//アーム

	/* エネミーグループ */
	Enemy_01,			//横から挟めないやつ
	Enemy_02,			//回転しながら打つやつ
	Enemy_03,			//ストーカー

	/* ニュートラルグループ */
	Neutral_Explosion,	//爆発

	/* UIグループ */
	UI_Manager,
	UI_Selector,
	UI_Button,
	UI_Sprite,

	/* テスト用 */
	EnemyManager,
	Enemy,
	None,
};

#endif // !ACTORNAME_H_
