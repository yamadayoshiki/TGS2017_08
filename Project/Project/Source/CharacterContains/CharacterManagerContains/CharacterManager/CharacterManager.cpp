#include "CharacterManager.h"
#include "../../PlayerContains/PlayerState/PlayerStateName.h"

//コンストラクタ
CharacterManager::CharacterManager() {

}

CharacterManager::~CharacterManager() {
	delete p_Player;
}


//プレイヤーの座標を取得
GSvector2 CharacterManager::GetPlayerPos() {
	return p_Player->getPosition();
}

//プレイヤーに挟まれた時の座標
GSvector2 CharacterManager::GetRoundPos() const {
	GSvector2 result = p_Player->getPosition() + p_Player->getBody()->forward() * 10.0f;
	return result;
}

//プレイヤーに挟まれているActorを取得
ActorPtr CharacterManager::GetRoundActor() {
	return nullptr;
}

//プレイヤーのステートを取得
PlayerStateName CharacterManager::GetPlayerStateName() {
	return PlayerStateName::None;
}

//プレイヤーの挟まれているActorを設定
void CharacterManager::SetRoundActor(const ActorPtr& actor) {
	m_RoundActorList.push_back(actor);
}


//プレイヤーの設定
void CharacterManager::SetPlayer(const ActorPtr& player) {
	/*if (player->getName() == ActorName::Player)
		p_Player = dynamic_cast<Player*>(player.get());*/
}