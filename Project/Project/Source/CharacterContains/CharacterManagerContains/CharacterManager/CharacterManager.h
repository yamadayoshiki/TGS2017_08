#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "../ICharacterManager.h"
#include "../../PlayerContains/Player/Player.h"

#include <vector>

class CharacterManager : public ICharacterManager
{
public:
	//コンストラクタ
	CharacterManager();
	//デストラクタ
	~CharacterManager();
	//プレイヤーの座標を取得
	GSvector2 GetPlayerPos() override;
	//プレイヤーの行列を取得
	//GSmatrix4 GetPlayerMat() override;
	//プレイヤーに挟まれているActorを取得
	ActorPtr GetRoundActor() override;
	//プレイヤーのステートを取得
	PlayerStateName GetPlayerStateName() override;
	//プレイヤーの挟まれているActorを設定
	virtual void SetRoundActor(const Actor& actor)override;

	//プレイヤーの設定
	virtual void SetPlayer(const ActorPtr& player);

private:
	Player* p_Player;							//プレイヤー

	std::vector<Actor> m_RoundActorList;		//挟まれたアクターリスト
};
#endif // !CHARACTERMANAGER_H_