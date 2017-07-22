#ifndef ENEMYSTATEMOVEBASEONLYINTHEBACK_H_
#define ENEMYSTATEMOVEBASEONLYINTHEBACK_H_

#include "../../Standard/Base/EnemyStateMoveBaseStandard.h"

//Enemy02専用移動基底クラス
class EnemyStateMoveBaseOnlyInTheBack : virtual public EnemyStateMoveBaseStandard
{
public:
	// コンストラクタ
	EnemyStateMoveBaseOnlyInTheBack(const EnemyBasePtr& enemy);
protected:
	//メッセージ処理
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif