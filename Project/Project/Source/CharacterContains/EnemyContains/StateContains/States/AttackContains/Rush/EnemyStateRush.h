#ifndef ENEMYSTATERUSH_H_
#define ENEMYSTATERUSH_H_

#include "../../Base/EnemyStateBase.h"

//突撃
class EnemyStateRush :public EnemyStateBase
{
public:
	//コンストラクタ
	EnemyStateRush(const EnemyBasePtr& enemy,const float speed);

protected:
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;
	//終了
	virtual void end() override;
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
protected:
	float m_Speed;		//スピード
};

#endif
