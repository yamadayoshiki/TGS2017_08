#ifndef ENEMYSTATECRUSHSPIN_H_
#define ENEMYSTATECRUSHSPIN_H_

#include "../Standard/EnemyStateCrushStandard.h"

//３回クラッシュされたらスピン状態に移行
class EnemyStateCrushSpin : public EnemyStateCrushStandard
{
public:
	//コンストラクタ
	EnemyStateCrushSpin(const EnemyBasePtr& enemy, int limitCounter);
protected:
	// 各状態独自の初期化
	virtual void unique_init() override;
	// 更新処理
	virtual void update(float deltaTime) override;

private:
	int m_Counter;		//クラッシュ回数
	int m_LimitCounter;	//クラッシュ回数上限
};

#endif