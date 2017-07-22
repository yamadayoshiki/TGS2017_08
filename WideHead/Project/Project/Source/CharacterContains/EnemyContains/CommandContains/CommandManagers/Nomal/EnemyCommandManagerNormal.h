#ifndef ENEMYCOMMANDMANAGERNORMAL_H_
#define ENEMYCOMMANDMANAGERNORMAL_H_

#include "../Base/EnemyCommandManagerBase.h"

//エネミーコマンドマネージャ/各コマンドとの連携
class EnemyCommandManagerNormal : public EnemyCommandManagerBase
{
public:
	//コンストラクタ
	EnemyCommandManagerNormal(const EnemyBasePtr& enemy);

protected:
	//次のコマンド
	virtual EnemyCommandName GetNextCommand() override;
};
#endif // !ENEMYCOMMANDMANAGERNORMAL_H_
