#ifndef ENEMYSTATEMOVESTANDARD_H_
#define ENEMYSTATEMOVESTANDARD_H_

#include "../Base/EnemyStateMoveBaseStandard.h"

//エネミーが動く状態
class EnemyStateMoveStandard : virtual public EnemyStateMoveBaseStandard
{
public:
	//コンストラクタ
	EnemyStateMoveStandard(
		const EnemyBasePtr& enemy,
		const float speed);
	// 各状態独自の初期化
	virtual void onUniqueInit()override;
	// 更新処理
	virtual void onUpdate(float deltaTime)override;

protected:
	float m_Speed;		//スピード
};

#endif