#ifndef SE_NAME_H_
#define SE_NAME_H_


enum SE_Name
{
	SE_PLAYER_ARM = 0,			//アーム開閉
	SE_PLAYER_DASH,				//ダッシュ
	SE_PLAYER_CRUSH,			//潰しているとき
	SE_PLAYER_CRUSH_AFTER,		//潰したとき
	SE_PLAYER_EXPLOSION,		//自機の爆発
	SE_PLAYER_PLAY,				//弾いたとき
	SE_PLAYER_RESPAWN,			//リスポーン

	SE_ENEMY_CHILDAPPEARED,		//子機出現
	SE_ENEMY_ENEMYEXPLOTION,	//敵爆発
	SE_ENEMY_GENERATESINGING,	//親機生成詠唱
	SE_ENEMY_RUSH,				//突進
	SE_ENEMY_SHOT,				//射撃
	SE_ENEMY_SPINBOUND,			//壁から跳ね返る
};

#endif // !SE_NAME_H_
