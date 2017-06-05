#ifndef ENEMYCOMMANDRUSH_H_
#define ENEMYCOMMANDRUSH_H_

#include "../../../Base/EnemyCommandBase.h"

//突撃
class EnemyCommandRush : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandRush(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//デストラクタ
	~EnemyCommandRush();
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
};

#endif
