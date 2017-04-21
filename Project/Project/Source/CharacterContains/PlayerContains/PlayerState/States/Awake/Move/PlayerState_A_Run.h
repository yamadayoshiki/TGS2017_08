#ifndef PLAYERSTATE_A_RUN_H_
#define PLAYERSTATE_A_RUN_H_

#include"PlayerState_A_MoveBase.h"

class PlayerState_A_Run:public PlayerState_A_MoveBase
{
public:
	//コンストラクタ
	PlayerState_A_Run(GSvector2& position, GSmatrix4& matrix, IGameManager* gameManager);
	//各状態独自の初期化
	virtual void onUniqueInit(Actor& actor)override;
	//更新処理
	virtual void onUpdate(Actor& actor, float deltaTime) override;
	//衝突処理
	virtual void onCollide(const Actor& other) override {}
	//終了処理
	virtual void onEnd() override {}
	//入力処理
	virtual void onInput() override {}
};
#endif // !PLAYERSTATE_A_RUN_H_
