#ifndef ENEMYSTATEMANAGER_H_
#define ENEMYSTATEMANAGER_H_

#include "../../../../ActorContains/State/Base/StateMgr.h"
#include"../../Entity/Enemys/Base/EnemyBasePtr.h"
#include "../States/EnemyStateName.h"

//�G�l�~�[�X�e�[�g�}�l�[�W���[
class EnemyStateManager : public StateMgr
{
public:
	// �f�t�H���g�R���X�g���N�^
	EnemyStateManager();
	//����State�̎擾
	EnemyStateName GetCurStateName() const;
};

#endif