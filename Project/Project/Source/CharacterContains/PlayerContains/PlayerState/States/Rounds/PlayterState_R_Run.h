#ifndef PLAYERSTATE_R_RUN_H_
#define PLAYERSTATE_R_RUN_H_

#include"PlayerState_R_MoveBase.h"

class PlayerState_R_Run:public PlayerState_R_MoveBase
{
public:
	//コンストラクタ
	PlayerState_R_Run(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager);
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
#endif // !PLAYERSTATE_R_RUN_H_
