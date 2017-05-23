#ifndef ENEMYCOMMANDENEMY02STANDBY_H_
#define ENEMYCOMMANDENEMY02STANDBY_H_

#include "../../Base/EnemyCommandBase.h"
#include "../../../../../../Utility/FourDirection/FourDirection.h"

//�G�l�~�[02�ҋ@
class EnemyCommandEnemy02Standby : public EnemyCommandBase
{
public:
	//�R���X�g���N�^
	EnemyCommandEnemy02Standby(
		const EnemyBasePtr& enemy,
		const FourDirection turnDirection);

	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param)override;

protected:
	FourDirection m_TurnDiretion;
};

#endif // !ENEMYCOMMANDENEMY02STANDBY_H_
