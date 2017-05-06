#ifndef ENEMYCOMMANDSHOT_H_
#define ENEMYCOMMANDSHOT_H_

#include "../Base/EnemyCommandBase.h"

class EnemyCommandShot : public EnemyCommandBase
{
public:
	//コンストラクタ
	EnemyCommandShot(const EnemyBasePtr& enemy);
	//更新
	virtual void Update(float deltaTime) override;
	//終了
	virtual void Finalize() override;
	//終了チェック
	virtual bool IsEnd() override;
	//命令ステート
	virtual EnemyStateName GetCurrentStateName() const override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
};

#endif // !ENEMY_COMMAND_SHOT
