#ifndef ENEMYSTATEBASE_H_
#define ENEMYSTATEBASE_H_

#include <gslib.h>
#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"

//継承先で使うため
#include "../../States/EnemyStateName.h"

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
	void Move(float deltaTime, float speed = 1.0f);
	//回転処理
	void Rotate(float deltaTime);

protected:
	//エネミー本体
	EnemyBasePtr p_Enemy;
};

#endif
