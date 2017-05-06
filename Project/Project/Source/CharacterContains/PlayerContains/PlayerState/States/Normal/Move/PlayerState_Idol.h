#ifndef PLAYERSTATE_IDOL_H_
#define PLAYERSTATE_IDOL_H_

#include"PlayerState_MoveBase.h"

//待機(通常)状態
class PlayerState_Idol:public PlayerState_MoveBase
{
public:
	//コンストラクタ
	PlayerState_Idol(GSvector2& position,GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void onUniqueInit()override;
	//更新処理
	virtual void onUpdate(float deltaTime){}
	//衝突処理
	virtual void onCollide(const Actor& other)override {}
	//終了処理
	virtual void onEnd()override {}
	//入力処理
	virtual void onInput()override{}
};
#endif // !PLAYERSTATE_IDOL_H_

