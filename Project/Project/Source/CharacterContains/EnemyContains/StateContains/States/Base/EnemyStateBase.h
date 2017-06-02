#ifndef ENEMYSTATEBASE_H_
#define ENEMYSTATEBASE_H_

#include <gslib.h>
#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"

//継承先で使うため
#include "../../States/EnemyStateName.h"

struct FourDirection;

//各エネミーステートの基底クラス
class EnemyStateBase :public State
{
public:
	//コンストラクタ
	EnemyStateBase(const EnemyBasePtr& enemy);
	//入力処理
	virtual void input() override;
protected:
	//移動処理
	void ForwardMove(float deltaTime, float speed);
	//注視移動処理
	void RegardMove(FourDirection regardDirection, float deltaTime, float speed);
	//注視移動処理(CLAMPあり)
	//PushDirection RegardMoveClamp(FourDirection regardDirection, float deltaTime, float speed);
	////回転処理
	//void Rotate(float deltaTime, float speed);

private:
	//移動ベクトル算出
	GSvector2 GetVelocity(float deltaTime, float speed);

protected:
	//エネミー本体
	EnemyBaseWPtr p_Enemy;
};

#endif