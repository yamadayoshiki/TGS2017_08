#ifndef PLAYERSTATE_CLOSE_H_
#define PLAYERSTATE_CLOSE_H_

#include"../../PlayerState.h"

class PlayerState_Close:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Close(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
};
#endif // !PLAYERSTATE_CLOSE_H_