#ifndef ENEMYSTATECAUGHTRELEASEDEAD_H_
#define ENEMYSTATECAUGHTRELEASEDEAD_H_

#include "../Standard/EnemyStateCaughtStandard.h"

//リリースされたら死ぬ
class EnemyStateCaughtReleaseDead : public EnemyStateCaughtStandard
{
public:
	//コンストラクタ
	EnemyStateCaughtReleaseDead(const EnemyBasePtr& enemy);
	//メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATECAUGHTRELEASEDEAD_H_
