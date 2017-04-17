#ifndef PLAYER_STATE_H_
#define PLAYER_STATE_H_

#include"../../../ActorContains/State/Base/State.h"

enum class PlayerStateID;

// 各プレイヤーステートの基底クラス
class PlayerState :public State
{
public:
	//コンストラクタ
	PlayerState(GSvector2& pos);
	//パッド入力
	virtual void input()override;

protected:
	//モーション変更
	void motion_change(Actor& actor, const PlayerStateID);
	//移動処理
	void move(Actor& actor, float deltaTime, float speed = 1.0f);
	//覚醒条件(パッド)
	bool aweke_pad();

protected:
	//座標の参照
	GSvector2		mPosition;
	//速度
	GSvector2		mVelocity;
	//回転角度
	float			mAngle;
};

#endif // !PLAYER_STATE_H_