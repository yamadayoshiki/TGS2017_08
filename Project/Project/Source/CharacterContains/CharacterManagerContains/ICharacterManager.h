#ifndef ICHARACTERMANAGER_H_
#define ICHARACTERMANAGER_H_

#include "../../ActorContains/ActorPtr.h"

struct GSvector2;
struct GSmatrix4;
enum class PlayerStateName;

class ICharacterManager
{
public:
	//仮想デストラクタ
	~ICharacterManager() {}
	//プレイヤーの座標を取得
	virtual GSvector2 GetPlayerPos() = 0;
	//プレイヤーの行列を取得
	//virtual GSmatrix4 GetPlayerMat() = 0;
	//プレイヤーに挟まれているActorを取得
	virtual ActorPtr GetRoundActor() = 0;
	//プレイヤーのステートを取得
	virtual PlayerStateName GetPlayerStateName() = 0;
	//プレイヤーの挟まれているActorを設定
	virtual void SetRoundActor(const Actor& actor) = 0;
};

#endif // !CHARACTERMANAGER_H_
