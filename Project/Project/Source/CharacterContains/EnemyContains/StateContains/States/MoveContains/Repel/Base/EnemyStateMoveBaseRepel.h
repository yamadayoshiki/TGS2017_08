#ifndef ENEMYSTATEMOVEBASEREPEL_H_
#define ENEMYSTATEMOVEBASEREPEL_H_

#include "../../Standard/Base/EnemyStateMoveBaseStandard.h"

class EnemyStateMoveBaseRepel : virtual public EnemyStateMoveBaseStandard
{
public:
	//コンストラクタ
	EnemyStateMoveBaseRepel(const EnemyBasePtr& enemy);
protected:
	// メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif