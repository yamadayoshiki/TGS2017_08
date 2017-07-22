#ifndef ENEMYSTATEMOVEREPEL_H_
#define ENEMYSTATEMOVEREPEL_H_

#include "../Base/EnemyStateMoveBaseRepel.h"
#include "../../Standard/Move/EnemyStateMoveStandard.h"

class EnemyStateMoveRepel : public EnemyStateMoveBaseRepel, public EnemyStateMoveStandard
{
public:
	//コンストラクタ
	EnemyStateMoveRepel(const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

	// メッセージ処理
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATEMOVEREPELMOVE_H_
