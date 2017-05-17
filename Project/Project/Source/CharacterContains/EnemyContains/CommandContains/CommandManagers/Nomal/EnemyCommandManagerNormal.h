#ifndef ENEMYCOMMANDMANAGERNORMAL_H_
#define ENEMYCOMMANDMANAGERNORMAL_H_

#include "../Base/EnemyCommandManagerBase.h"

//�G�l�~�[�R�}���h�}�l�[�W��/�e�R�}���h�Ƃ̘A�g
class EnemyCommandManagerNormal : public EnemyCommandManagerBase
{
public:
	//�R���X�g���N�^
	EnemyCommandManagerNormal(const EnemyBasePtr& enemy);

protected:
	//���̃R�}���h
	virtual EnemyCommandName GetNextCommand() override;
};
#endif // !ENEMYCOMMANDMANAGERNORMAL_H_
