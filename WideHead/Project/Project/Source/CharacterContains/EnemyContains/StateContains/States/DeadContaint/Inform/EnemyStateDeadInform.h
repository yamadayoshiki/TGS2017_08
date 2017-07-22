#ifndef ENEMYSTATEDEADINFORM_H_
#define ENEMYSTATEDEADINFORM_H_

#include "../Standard/EnemyStateDeadStandard.h"

//エネミー02専用死亡クラス

class EnemyStateDeadInform : public EnemyStateDeadStandard
{
public:
	//コンストラクタ
	EnemyStateDeadInform(const EnemyBasePtr& enemy, const ActorName name);
	// 各状態独自の初期化
	virtual void unique_init() override;

protected:
	ActorName m_Name;
};

#endif