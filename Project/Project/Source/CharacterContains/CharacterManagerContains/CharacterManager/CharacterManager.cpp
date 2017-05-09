#include "CharacterManager.h"
#include "../../PlayerContains/PlayerState/PlayerStateName.h"

//コンストラクタ
CharacterManager::CharacterManager() {

}

//プレイヤーの座標を取得
GSvector2 CharacterManager::GetPlayerPos() {
	return p_Player->getPosition();
}

//プレイヤーの行列を取得
GSmatrix4 CharacterManager::GetPlayerMat() {
	return p_Player->getMatrix();
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
	if (player->getName() == ActorName::Player)
		p_Player = dynamic_cast<Player*>(player.get());
}