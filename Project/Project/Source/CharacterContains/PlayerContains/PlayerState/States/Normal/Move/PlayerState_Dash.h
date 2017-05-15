#ifndef PALYERSTATE_DASH_H_
#define PALYERSTATE_DASH_H_

#include"PlayerState_MoveBase.h"

class PlayerState_Dash:public PlayerState_MoveBase
{
public:
	//コンストラクタ
	PlayerState_Dash(const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void onUniqueInit()override;
	//更新処理
	virtual void onUpdate(float deltaTime) override;
	//衝突処理
	virtual void onCollide(const Actor& other) override;
	//終了処理
	virtual void onEnd() override {}
	//入力処理
	virtual void onInput() override {}

private:
	//フレームカウンター
	float		m_FrameCounter{ 0.0f };
	//進距離
	GSvector2	m_distance;
	//方向ベクトル
	GSvector2	m_Direction;
};
#endif // !PALYERSTATE_DASH_H_

