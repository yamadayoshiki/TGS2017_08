#ifndef ENEMY_BASESTATE_H_
#define ENEMY_BASESTATE_H_

#include <gslib.h>
#include "../../../../ActorContains/State/Base/State.h"

/*継承先で使うため*/
#include "../../EnemyStateName.h"

//各エネミーステートの基底クラス
class Enemy_BaseState :public State
{
public:
	//コンストラクタ
	Enemy_BaseState(GSvector2& position, GSmatrix4& rotate);
	// 入力処理
	virtual void input() override;
protected:
	//移動処理
	void Move(Actor& actor, float deltaTime, float speed = 1.0f);

protected:
	//座標の参照
	GSvector2& m_Position;
	//行列の参照
	GSmatrix4& m_Rotate;
	//速度
	GSvector2 m_Velocity;
	//回転角度
	float m_Angle;
};

#endif // !ENEMYBASE_STATE_H_
