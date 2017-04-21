#ifndef PLAYER_STATE_MOVEBASE_H_
#define PLAYER_STATE_MOVEBASE_H_

#include"../../../PlayerState.h"
#include"../../../PlayerStateName.h"

//移動クラスのベース
class PlayerState_MoveBase:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_MoveBase(GSvector2& position,GSmatrix4& matrix, IGameManager* gameManager);
	//各状態独自の初期化
	virtual void unique_init(Actor& actor)override;
	//更新処理
	virtual void update(Actor& actor, float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override;
	//入力処理
	virtual void input() override;

protected:
	//各状態の初期化
	virtual void onUniqueInit(Actor& actor)=0;
	// 更新処理
	virtual void onUpdate(Actor & actor, float deltaTime) = 0;
	// 衝突判定
	virtual void onCollide(const Actor & other) = 0;
	// 終了時の処理
	virtual void onEnd() = 0;
	// 入力処理
	virtual void onInput() = 0;
};

#endif // !PLAYER_STATE_MOVEBASE_H_

