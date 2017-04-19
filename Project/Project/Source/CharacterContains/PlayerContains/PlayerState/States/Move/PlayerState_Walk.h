#ifndef PLAYERSTATE_WALK_H_
#define PLAYERSTATE_WALK_H_

#include"PlayerState_MoveBase.h"

//歩きの状態
class PlayerState_Walk:public PlayerState_MoveBase
{
public:
	//コンストラクタ
	PlayerState_Walk(GSvector2& pos);
	//各状態独自の初期化
	virtual void onUniqueInit(Actor& actor)override;
	//更新処理
	virtual void onUpdate(Actor& actor, float deltaTime) override;
	//衝突処理
	virtual void onCollide(Actor& other) {}
	//終了処理
	virtual void onEnd() {}
	//入力処理
	virtual void onInput() {}
};
#endif // !PLAYERSTATE_WALK_H_

