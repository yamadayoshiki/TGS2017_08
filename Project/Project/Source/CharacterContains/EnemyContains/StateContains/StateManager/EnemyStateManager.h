#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Enemys/Base/EnemyBasePtr.h"

//��s�錾
struct GSvector2;
struct GSmatrix4;

//�G�l�~�[�X�e�[�g�}�l�[�W���[
class EnemyStateManager :public StateMgr
{
public:
	// �f�t�H���g�R���X�g���N�^
	EnemyStateManager();
	// �R���X�g���N�^
	EnemyStateManager(const EnemyBasePtr& enemy);
};

#endif
