#ifndef ENEMYSTATESPINSTANDARD_H_
#define ENEMYSTATESPINSTANDARD_H_

#include "../../Base/EnemyStateBase.h"

//スピンスタンダードクラス
class EnemyStateSpinStandard : public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateSpinStandard(const EnemyBasePtr& enemy,float speed);
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	//終了
	virtual void end() override;
protected:
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;

protected:
	float m_Speed;	//スピード
};

#endif // !ENEMYSTATESPINSTANDARD_H_
