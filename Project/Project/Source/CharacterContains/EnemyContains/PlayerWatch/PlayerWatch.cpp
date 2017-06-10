#include "PlayerWatch.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Define/Def_Nakayama.h"

#include <GSvector2.h>
#include "../../../Utility/FourDirection/FourDirection.h"

PlayerWatch::PlayerWatch(const ActorPtr user)
	:p_User(user)
	, p_Map(user->getWorld()->GetMap()) {
	p_Player = user->getWorld()->findActor(ActorName::Player);
}

PlayerWatch::~PlayerWatch() {
	p_Map.reset();
	p_Player.reset();
	p_User.reset();
}

GSvector2 PlayerWatch::GetToPlayerDis() const {
	GSvector2 result;
	result = p_Player.lock()->getPosition() - p_User.lock()->getPosition();
	return result;
}

GSvector2 PlayerWatch::GetToPlayerChipDis(MapType type) const {
	GSvector2 result;
	result = p_Map.lock()->GetTilePos(p_Player.lock()->getPosition(), type) - p_Map.lock()->GetTilePos(p_User.lock()->getPosition(), type);
	result = result / ((int)CHIP_SIZE + 1);
	return result;
}

FourDirection PlayerWatch::GetPlayerFrontDir() const {
	return FourDirection(p_Player.lock()->getTransform().m_Angle);
}
