#ifndef PLAYERSTATE_ROUND_H_
#define PLAYERSTATE_ROUND_H_

#include"../../PlayerState.h"

class PlayerState_Round :public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Round(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
	//入力処理
	virtual void input() override;
	//メッセージ処理
	virtual void handleMessage(EventMessage massege, void* param)override;
};
#endif // !PLAYERSTATE_ROUND_H_
