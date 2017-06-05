#ifndef ENEMYCOMMANDGENERATE_H_
#define ENEMYCOMMANDGENERATE_H_

#include "../../Base/EnemyCommandBase.h"

//他のエネミー生成マン
class EnemyCommandGenerate : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandGenerate(
		const EnemyBasePtr& enemy,
		const MapType type,
		const TurnDirection turnDirection);
	//デストラクタ
	~EnemyCommandGenerate();
	//終了
	virtual void Finalize() override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の更新
	virtual void OnUpdate(float deltaTime) override;
};

#endif // !ENEMYCOMMANDGENERATE_H_
