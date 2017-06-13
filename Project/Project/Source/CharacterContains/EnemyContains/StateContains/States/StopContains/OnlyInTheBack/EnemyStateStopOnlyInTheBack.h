#ifndef ENEMYSTATESTOPONLYINTHEBACK_H_
#define ENEMYSTATESTOPONLYINTHEBACK_H_

#include "../../MoveContains/OnlyInTheBack/Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../Standard/EnemyStateStopStandard.h"

class EnemyStateStopOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack , public EnemyStateStopStandard
{
public:
	//コンストラクタ
	EnemyStateStopOnlyInTheBack(const EnemyBasePtr& enemy, float limitTimer);
	//各種固有の初期化処理
	virtual void unique_init() override;
	//更新処理
	virtual void update(float deltaTime) override;

protected:
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATESTOPONLYINTHEBACK_H_
