#include "PlayerWatch.h"
#include "../../PlayerContains/Player/Player.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Define/Def_Nakayama.h"
#include <GSvector2.h>

//コンストラクタ
PlayerWatch::PlayerWatch(Map& map, const ActorPtr & user)
	: p_User(user)
	, m_Map(map) {
	p_Player = p_User.lock()->getWorld()->findActor(ActorName::Player);
}

//デストラクタ
PlayerWatch::~PlayerWatch() {
	p_Player.reset();
	p_User.reset();
}

//ユーザーからプレイヤーまでの距離ベクトル
GSvector2 PlayerWatch::GetToPlayerDis() const {
	GSvector2 result;
	result = p_Player.lock()->getPosition() - p_User.lock()->getPosition();
	return result;
}

//ユーザーからプレイヤーまでの距離ベクトル(マス座標準拠)
GSvector2 PlayerWatch::GetToPlayerChipDis(MapType type) const {
	GSvector2 result;
	result = m_Map.GetTilePos(p_Player.lock()->getPosition(), type) - m_Map.GetTilePos(p_User.lock()->getPosition(), type);
	result = result / ((int)CHIP_SIZE + 1);
	return result;
}