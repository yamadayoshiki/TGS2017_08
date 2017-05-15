#ifndef PLAYERSTATE_SWICH_H_
#define PLAYERSTATE_SWICH_H_

#include"../../PlayerState.h"

class PlayerState_Swich : public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Swich(const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override {}
private:
	bool		m_Flag;
};
#endif // !PLAYERSTATE_SWICH_H_