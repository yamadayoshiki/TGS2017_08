#ifndef ENEMYSTATEBASE_H_
#define ENEMYSTATEBASE_H_

#include <gslib.h>
#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"

//継承先で使うため
#include "../../States/EnemyStateName.h"

struct FourDirection;

//各エネミーステートの基底クラス
class EnemyStateBase : virtual public State
{
public:
	//コンストラクタ
	EnemyStateBase(const EnemyBasePtr& enemy);
	//入力処理
	virtual void input() override;
	//メッセージ処理
	void handleMessage(EventMessage message, void * param) override;
protected:
	//移動処理
	void ForwardMove(float deltaTime, float speed);
	//注視移動処理
	void RegardMove(FourDirection regardDirection, float deltaTime, float speed);
	//注視移動処理(CLAMPあり)
	//PushDirection RegardMoveClamp(FourDirection regardDirection, float deltaTime, float speed);
	////回転処理
	//void Rotate(float deltaTime, float speed);
	//各種固有のメッセージ処理
	virtual void OnHandleMessage(EventMessage message, void * param) {}

	// 衝突判定
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// 終了時の処理
	virtual void end() override {}
	//ステートの変更処理
	void Change(const EnemyStateName name, void* param);

private:
	//移動ベクトル算出
	GSvector2 GetVelocity(float deltaTime, float speed);

protected:
	//エネミー本体
	EnemyBaseWPtr p_Enemy;
};

#endif