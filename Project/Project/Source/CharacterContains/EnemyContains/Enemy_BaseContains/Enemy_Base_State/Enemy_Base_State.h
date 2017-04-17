#ifndef ENEMY_BASE_STATE_H_
#define ENEMY_BASE_STATE_H_

#include <gslib.h>
#include "../../../../ActorContains/State/Base/State.h"

//各エネミーステートの基底クラス
class Enemy_Base_State :public State
{
public:
	//コンストラクタ
	Enemy_Base_State(GSvector2& position);

protected:
	//移動処理
	void Move(Actor& actor, float deltaTime, float speed = 1.0f);

protected:
	//座標の参照
	GSvector2& m_Position;
	//速度
	GSvector2 m_Velocity;
	//回転角度
	float m_Angle;
};

#endif // !ENEMYBASE_STATE_H_
