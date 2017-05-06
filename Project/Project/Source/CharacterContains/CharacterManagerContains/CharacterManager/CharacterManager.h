#include "../ICharacterManager.h"
#include "../../PlayerContains/Player/Player.h"

#include <vector>

class CharacterManager :ICharacterManager
{
public:
	//コンストラクタ
	CharacterManager();
	//デストラクタ
	~CharacterManager() { delete p_Player; }
	//プレイヤーの座標を取得
	GSvector2 GetPlayerPos() override;
	//プレイヤーの行列を取得
	GSmatrix4 GetPlayerMat() override;
	//プレイヤーに挟まれているActorを取得
	ActorPtr GetRoundActor() override;
	//プレイヤーのステートを取得
	PlayerStateName GetPlayerStateName() override;
	//プレイヤーの挟まれているActorを設定
	virtual void SetRoundActor(const ActorPtr& actor) = 0;

	//プレイヤーの設定
	virtual void SetPlayer(const ActorPtr& player);

private:
	Player* p_Player;							//プレイヤー

	std::vector<ActorPtr> m_RoundActorList;		//挟まれたアクターリスト
};