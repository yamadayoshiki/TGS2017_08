#include "EnemyCommandManagerNormal.h"
#include "../../Commands/Interface/IEnemyCommand.h"

//�R���X�g���N�^
EnemyCommandManagerNormal::EnemyCommandManagerNormal(const EnemyBasePtr & enemy)
	:EnemyCommandManagerBase(enemy) {
}

//���̃R�}���h
EnemyCommandName EnemyCommandManagerNormal::GetNextCommand() {
	return p_CurCommand->GetNextCommand();
}
