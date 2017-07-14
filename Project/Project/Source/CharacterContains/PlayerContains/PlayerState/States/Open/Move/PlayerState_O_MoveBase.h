#ifndef PLAYERSTATE_0_MOVEBASE_H_
#define PLAYERSTATE_0_MOVEBASE_H_

#include"../../../PlayerState.h"
#include"../../Normal/Move/PlayerState_MoveBase.h"

class PlayerState_O_MoveBase:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_O_MoveBase(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override;
	//終了処理
	virtual void end()override;
	//入力処理
	virtual void input() override;

protected:
	//各状態の初期化
	virtual void onUniqueInit() = 0;
	// 更新処理
	virtual void onUpdate(float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other, const Body::ContactSet& contactSet) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;
};
#endif // !PLAYERSTATE_O_MOVEBASE_H_

