#include "EnemyCommandManagerNormal.h"
#include "../../Commands/Interface/IEnemyCommand.h"

//コンストラクタ
EnemyCommandManagerNormal::EnemyCommandManagerNormal(const EnemyBasePtr & enemy)
	:EnemyCommandManagerBase(enemy) {
}

//次のコマンド
EnemyCommandName EnemyCommandManagerNormal::GetNextCommand() {
	return p_CurCommand->GetNextCommand();
}
