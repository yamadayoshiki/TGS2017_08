#ifndef ENEMYSTATECAUGHTRELEASEDEAD_H_
#define ENEMYSTATECAUGHTRELEASEDEAD_H_

#include "../Standard/EnemyStateCaughtStandard.h"

//�����[�X���ꂽ�玀��
class EnemyStateCaughtReleaseDead : public EnemyStateCaughtStandard
{
public:
	//�R���X�g���N�^
	EnemyStateCaughtReleaseDead(const EnemyBasePtr& enemy);
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATECAUGHTRELEASEDEAD_H_
