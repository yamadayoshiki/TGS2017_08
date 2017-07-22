#ifndef PLAYERSTATE_CRUSH_AFTER_H_
#define PLAYERSTATE_CRUSH_AFTER_H_

#include"../../PlayerState.h"

class PlayerState_Crush_After :public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Crush_After(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTime)override;
	//衝突判定
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override {}
	//終了処理
	virtual void end()override {}
	//入力処理
	virtual void input() override {}

private:
	//フレームカウンター
	float m_FrameCounter{ 0.0f };
};
#endif // !PLAYERSTATE_CRUSH_AFTER_H_
