#include "EnemyStateCrushSpin.h"
//コンストラクタ
EnemyStateCrushSpin::EnemyStateCrushSpin(const EnemyBasePtr & enemy, int limitCounter)
	: EnemyStateCrushStandard(enemy)
	, m_Counter(0)
	, m_LimitCounter(m_LimitCounter) {
}

//各種固有の初期化
void EnemyStateCrushSpin::unique_init() {
	//モーションの変更

	//挟まれた回数加算
	m_Counter++;
}

void EnemyStateCrushSpin::update(float deltaTime) {
	//指定回数に達した場合スピンに切り替え
	if (m_Counter >= m_LimitCounter)
		change(EnemyStateName::Spin);

	else
		change(EnemyStateName::Caught);
}
