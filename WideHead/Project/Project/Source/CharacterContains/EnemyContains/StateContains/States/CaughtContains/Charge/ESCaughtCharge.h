#ifndef ESCAUGHTCHARGE_H_
#define ESCAUGHTCHARGE_H_
#include "../Standard/EnemyStateCaughtStandard.h"

class ESCaughtCharge : public EnemyStateCaughtStandard
{
public:
	//�R���X�g���N�^
	ESCaughtCharge(const EnemyBasePtr& enemy);
	// ���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;
};

#endif // !ESCAUGHTCHARGE_H_