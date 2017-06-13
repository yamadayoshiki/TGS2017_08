#ifndef ENEMYSTATESTOP_H_
#define ENEMYSTATESTOP_H_

#include "../../MoveContains/Standard/Base/EnemyStateMoveBaseStandard.h"

//動かない
class EnemyStateStopStandard : virtual public EnemyStateMoveBaseStandard
{
public:
	//コンストラクタ
	EnemyStateStopStandard(const EnemyBasePtr& enemy, float limitTimer);
	//各種固有の初期化処理
	virtual void unique_init() override;
	//更新処理
	virtual void update(float deltaTime) override;

protected:
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;

protected:
	float m_LimitTimer;	//何フレーム止まるのか
	float m_Timer;		//タイマー
};

#endif // !ENEMYSTATESTOP_H_