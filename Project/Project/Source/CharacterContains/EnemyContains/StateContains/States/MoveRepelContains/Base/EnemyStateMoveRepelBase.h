#ifndef ENEMYSTATEMOVEREPELBASE_H_
#define ENEMYSTATEMOVEREPELBASE_H_

#include "../../MoveContains/Base/EnemyStateMoveBase.h"

class EnemyStateMoveRepelBase : public EnemyStateMoveBase
{
public:
	//コンストラクタ
	EnemyStateMoveRepelBase(const EnemyBasePtr& enemy);
	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELBASE_H_
