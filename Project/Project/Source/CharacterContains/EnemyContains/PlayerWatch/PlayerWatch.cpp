#include "PlayerWatch.h"
#include "../../../WorldContains/World/World.h"
#include "../../../Define/Def_Nakayama.h"
#include "../../../Utility/CsvConvertTwoDVector/CsvConvertTwoDVector.h"
#include "../../../Utility/CsvConvertTwoDVector/CsvCellData.h"
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

GSvector2 PlayerWatch::GetToPlayerChipDis() const{
	//プレイヤーがいるマス
	CsvCellData player = CsvConvertTwoDVector::Vector2CnvCsvPos(p_Player.lock()->getPosition(), p_User.lock()->GetMapType());
	//エネミーがいるマス
	CsvCellData enemy = CsvConvertTwoDVector::Vector2CnvCsvPos(p_User.lock()->getPosition(), p_User.lock()->GetMapType());
	//差分
	int x = player.x - enemy.x;
	int y = player.y - enemy.y;
	
	return GSvector2(x, y);
}

FourDirection PlayerWatch::GetPlayerFrontDir() const {
	return FourDirection(p_Player.lock()->getTransform().m_Angle);
}
