#ifndef PALYERSTATE_DASH_H_
#define PALYERSTATE_DASH_H_

#include"../../../PlayerState.h"

class PlayerState_Dash:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Dash(const PlayerPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other)override;
	//終了処理
	virtual void end()override {}
private:
	//フレームカウンター
	float		m_FrameCounter{ 0.0f };
	//スタート地点
	GSvector2	startPos;
	//エンド地点
	GSvector2	endPos;
	//二点間の距離
	float	m_Distance;
	//方向ベクトル
	GSvector2	m_Direction;
	//スピード
	float		speed;
};
#endif // !PALYERSTATE_DASH_H_

