#ifndef PLAYERWATCH_H_
#define PLAYERWATCH_H_

#include "../../../ActorContains/ActorPtr.h"
#include "../../../Map/MapType.h"
#include "../../../Utility/FourDirection/FourDirection.h"
#include "../../../Map/MapPtr.h"

struct GSvector2;

class PlayerWatch
{
public:
	//コンストラクタ
	PlayerWatch(const ActorPtr user);
	//デストラクタ
	~PlayerWatch();
	//ユーザーからプレイヤーまでの距離ベクトル
	GSvector2 GetToPlayerDis() const;
	//ユーザーからプレイヤーまでの距離マスベクトル(マス準拠,MapTypeはユーザー基準)
	GSvector2 GetToPlayerChipDis() const;
	//プレイヤーの正面
	FourDirection GetPlayerFrontDir() const;

private:
	ActorWPtr p_User;		//ユーザー
	ActorWPtr p_Player;		//プレイヤー
	MapWPtr p_Map;			//マップ
};

#endif // !PLAYERWATCH_H_
