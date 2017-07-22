#ifndef ENEMYSTATEDEADINFORMCHILDREN_H_
#define ENEMYSTATEDEADINFORMCHILDREN_H_

#include "../Standard/EnemyStateDeadStandard.h"

//子供を殺す
class EnemyStateDeadInformChildren : public EnemyStateDeadStandard
{
public:
	//コンストラクタ
	EnemyStateDeadInformChildren(
		const EnemyBasePtr& enemy);
protected:
	// 各状態独自の初期化
	virtual void unique_init() override;
};
#endif // !ENEMYSTATEDEADINFORMCHILDREN_H_
