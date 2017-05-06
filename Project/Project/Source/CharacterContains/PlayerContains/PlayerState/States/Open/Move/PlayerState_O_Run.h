#ifndef PLAYERSTATE_O_RUN_H_
#define PLAYERSTATE_O_RUN_H_

#include"PlayerState_O_MoveBase.h"

class PlayerState_O_Run:public PlayerState_O_MoveBase
{
public:
	//コンストラクタ
	PlayerState_O_Run(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void onUniqueInit()override;
	//更新処理
	virtual void onUpdate(float deltaTime) override;
	//衝突処理
	virtual void onCollide(const Actor& other) override {}
	//終了処理
	virtual void onEnd() override {}
	//入力処理
	virtual void onInput() override {}
};
#endif // !PLAYERSTATE_O_RUN_H_