#ifndef ESCAUGHTCHARGE_H_
#define ESCAUGHTCHARGE_H_
#include "../Standard/EnemyStateCaughtStandard.h"

class ESCaughtCharge : public EnemyStateCaughtStandard
{
public:
	//コンストラクタ
	ESCaughtCharge(const EnemyBasePtr& enemy);
	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ESCAUGHTCHARGE_H_