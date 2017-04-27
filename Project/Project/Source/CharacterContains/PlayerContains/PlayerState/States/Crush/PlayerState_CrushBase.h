#ifndef PLAYERSTATE_CRUSH_BASE_H_
#define PLAYERSTATE_CRUSH_BASE_H_

#include"../../PlayerState.h"
#include"../../PlayerStateName.h"

class PlayerState_CrushBase:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_CrushBase(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init(Actor& actor)override;
	//更新処理
	virtual void update(Actor& actor, float deltaTime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
	//入力処理
	virtual void input() override;

protected:
	//各状態の初期化
	virtual void onUniqueInit(Actor& actor) = 0;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;

protected:
	float		m_FrameCounter;
};
#endif // !PLAYERSTATE_CRUSH_BASE_H_