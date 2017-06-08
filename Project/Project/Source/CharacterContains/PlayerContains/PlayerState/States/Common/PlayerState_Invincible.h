#ifndef PLAYERSTATE_INVINCIBLE_H_
#define PLAYERSTATE_INVINCIBLE_H_

#include"../../PlayerState.h"

class PlayerState_Invincible:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Invincible(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override{}
	//入力処理
	virtual void input() override;

private:
	float		m_FramConter{ 0.0f };
};
#endif // !PLAYERSTATE_INVINCIBLE_H_
