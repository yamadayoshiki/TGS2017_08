#ifndef SOUNDNAME_H_
#define SOUNDNAME_H_


enum SoundName
{

	//PlayerSE
	SE_PLAYER_ARM = 0,			//アーム開閉
	SE_PLAYER_CLIP,				//挟んだ時
	SE_PLAYER_DASH,				//ダッシュ
	SE_PLAYER_CRUSH,			//潰しているとき
	SE_PLAYER_CRUSH_AFTER,		//潰したとき
	SE_PLAYER_EXPLOSION,		//自機の爆発
	SE_PLAYER_PLAY,				//弾いたとき
	SE_PLAYER_RESPAWN,			//リスポーン
	SE_PLAYER_CHARGE_FRIST,		//チャージ1段階目
	SE_PLAYER_CHARGE_SECOND,	//チャージ2段階目
	SE_PLAYER_CHARGE_THIRD,		//チャージ3段階目

	//EnemySE
	SE_ENEMY_CHILDAPPEARED,		//子機出現
	SE_ENEMY_ENEMYEXPLOTION,	//敵爆発
	SE_ENEMY_GENERATESINGING,	//親機生成詠唱
	SE_ENEMY_RUSH,				//突進
	SE_ENEMY_SHOT,				//射撃
	SE_ENEMY_SPINBOUND,			//壁から跳ね返る

	//BGM
	BGM_GAME_TITLE,				//タイトルBGM
	BGM_GAME_PLAY,				//ゲームPlayBGM
	BGM_GAME_CLER,				//ゲームクリアBGM
	BGM_GAME_OVER,				//ゲームオーバーBGM

	//SE
	SE_BACK,					//戻る
	SE_DECITION,				//決定
	SE_KOMBOUP,					//コンボアップ
	SE_PAUSE_CLOSE,				//ポーズを閉じる
	SE_PAUSE_OPEN,				//ポーズを開く
	SE_SHOWINGSCORE,			//スコア表示
	SE_SHOWINGSCORE_BEFORE,		//スコア表示前
	SE_START,					//スタート
};

#endif