#ifndef PLAYERSTATE_CRUSH_BARRAGE_H_
#define PLAYERSTATE_CRUSH_BARRAGE_H_

#include"PlayerState_CrushBase.h"

class PlayerState_Crush_Barrage:public PlayerState_CrushBase
{
public:
	//コンストラクタ
	PlayerState_Crush_Barrage(const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void onUniqueInit()override;
	//更新処理
	virtual void onUpdate(float deltaTime)override;
	//衝突処理
	virtual void onCollide(const Actor& other)override {}
	//終了処理
	virtual void onEnd()override {}
	//入力処理
	virtual void onInput()override {}
};
#endif // !PLAYERSTATE_CRUSH_BARRAGE_H_

