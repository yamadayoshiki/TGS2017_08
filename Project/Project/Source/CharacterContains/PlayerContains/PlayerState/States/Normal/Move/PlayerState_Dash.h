#ifndef PALYERSTATE_DASH_H_
#define PALYERSTATE_DASH_H_

#include"../../../PlayerState.h"

class PlayerState_Dash:public PlayerState
{
public:
	//コンストラクタ
	PlayerState_Dash(const Player_WPtr& player, IGameManagerPtr gameManager);
	//各状態独自の初期化
	virtual void unique_init()override;
	//更新処理
	virtual void update(float deltaTaime)override;
	//衝突判定
	virtual void collide(const Actor& other, const Body::ContactSet& contactSet)override;
	//終了処理
	virtual void end()override {}
	//入力処理
	virtual void input()override;

private:
	//フレームカウンター
	float				m_FramConter{ 0.0f };
	//エンド地点
	GSvector2	endPos;
	//二点間の距離
	float	m_Distance;
	//方向ベクトル
	GSvector2	m_Direction;
	//スピード
	float		speed;
	//アームが開いているか？
	bool		m_Flag{false};
};
#endif // !PALYERSTATE_DASH_H_

