#ifndef PLAYERSTATE_R_MOVEBASE_H_
#define PLAYERSTATE_R_MOVEBASE_H_

#include"../../PlayerState.h"

class PlayerState_R_MoveBase :public PlayerState
{
public:
	//コンストラクタ
	PlayerState_R_MoveBase(GSvector2& position, GSmatrix4& matirx, const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
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
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;
};
#endif // !PLAYERSTATE_R_MOVEBASE_H_