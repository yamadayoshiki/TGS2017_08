#ifndef ENEMYCOMMANDGENERATE_H_
#define ENEMYCOMMANDGENERATE_H_

#include "../../Base/EnemyCommandBase.h"

//他のエネミー生成マン(指定一体のみ)
class EnemyCommandGenerate : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandGenerate(
		const EnemyBasePtr& enemy,
		const float charaNumber,
		const float intervalTime);
	//デストラクタ
	~EnemyCommandGenerate();

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;

protected:
	float m_CharaNumber;	//生成するキャラクターの番号
	float m_IntervalTime;	//生成する時間の間隔
	float m_Timer;			//タイマー
};

#endif // !ENEMYCOMMANDGENERATE_H_
