#ifndef PLAYERWATCH_H_
#define PLAYERWATCH_H_

#include "../../../ActorContains/ActorPtr.h"
#include "../../PlayerContains/Player/PlayerPtr.h"

class Map;
struct GSvector2;
enum class MapType;

//プレイヤー監視クラス
class PlayerWatch 
{
public:
	//コンストラクタ
	PlayerWatch(Map& map, const ActorPtr& user);
	//デストラクタ
	~PlayerWatch();

	//ユーザーからプレイヤーまでの距離ベクトル
	GSvector2 GetToPlayerDis() const;
	//ユーザーからプレイヤーまでの距離マスベクトル(マス準拠)
	GSvector2 GetToPlayerChipDis(MapType type) const;

private:
	ActorWPtr p_User;		//ユーザー
	ActorWPtr p_Player;		//プレイヤー
	Map& m_Map;				//マップ
};


#endif // !PLAYERWATCH_H_
