#ifndef ENEMYSTATESTOPONLYINTHEBACK_H_
#define ENEMYSTATESTOPONLYINTHEBACK_H_

#include "../../MoveContains/OnlyInTheBack/Base/EnemyStateMoveBaseOnlyInTheBack.h"
#include "../Standard/EnemyStateStopStandard.h"

class EnemyStateStopOnlyInTheBack : public EnemyStateMoveBaseOnlyInTheBack , public EnemyStateStopStandard
{
public:
	//�R���X�g���N�^
	EnemyStateStopOnlyInTheBack(const EnemyBasePtr& enemy, float limitTimer);
	//�e��ŗL�̏���������
	virtual void unique_init() override;
	//�X�V����
	virtual void update(float deltaTime) override;

protected:
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;
};

#endif // !ENEMYSTATESTOPONLYINTHEBACK_H_
