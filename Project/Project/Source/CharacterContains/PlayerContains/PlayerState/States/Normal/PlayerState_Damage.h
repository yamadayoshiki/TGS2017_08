#ifndef PLAYERSTATE_DAMAGE_H_
#define PLAYERSTATE_DAMAGE_H_

#include"../../PlayerState.h"

class PlayerState_Damage:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Damage(GSvector2& position,GSmatrix4& matrix, IGameManagerPtr gameManager);
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
};
#endif // !PLAYERSTATE_DAMAGE_H_

