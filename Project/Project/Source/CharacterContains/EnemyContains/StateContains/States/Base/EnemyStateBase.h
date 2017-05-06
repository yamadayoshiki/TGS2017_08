#ifndef ENEMYSTATEBASE_H_
#define ENEMYSTATEBASE_H_

#include <gslib.h>
#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../Enemys/Base/EnemyBasePtr.h"

//�p����Ŏg������
#include "../../States/EnemyStateName.h"

//�e�G�l�~�[�X�e�[�g�̊��N���X
class EnemyStateBase :public State
{
public:
	//�R���X�g���N�^
	EnemyStateBase(const EnemyBasePtr& enemy);
	//���͏���
	virtual void input() override;
protected:
	//�ړ�����
	void Move(float deltaTime, float speed = 1.0f);
	//��]����
	void Rotate(float deltaTime);

protected:
	//�G�l�~�[�{��
	EnemyBasePtr p_Enemy;
};

#endif
