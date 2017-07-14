#ifndef ENEMYSTATEBASE_H_
#define ENEMYSTATEBASE_H_

#include <gslib.h>
#include "../../../../../ActorContains/State/Base/State.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"

//�p����Ŏg������
#include "../../States/EnemyStateName.h"

struct FourDirection;

//�e�G�l�~�[�X�e�[�g�̊��N���X
class EnemyStateBase : virtual public State
{
public:
	//�R���X�g���N�^
	EnemyStateBase(const EnemyBasePtr& enemy);
	//���͏���
	virtual void input() override;
	//���b�Z�[�W����
	void handleMessage(EventMessage message, void * param) override;
protected:
	//�ړ�����
	void ForwardMove(float deltaTime, float speed);
	//�����ړ�����
	void RegardMove(FourDirection regardDirection, float deltaTime, float speed);
	//�����ړ�����(CLAMP����)
	//PushDirection RegardMoveClamp(FourDirection regardDirection, float deltaTime, float speed);
	////��]����
	//void Rotate(float deltaTime, float speed);
	//�e��ŗL�̃��b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void * param) {}

	// �Փ˔���
	virtual void collide(const Actor & other, const Body::ContactSet& contactSet) override {}
	// �I�����̏���
	virtual void end() override {}
	//�X�e�[�g�̕ύX����
	void Change(const EnemyStateName name, void* param);

private:
	//�ړ��x�N�g���Z�o
	GSvector2 GetVelocity(float deltaTime, float speed);

protected:
	//�G�l�~�[�{��
	EnemyBaseWPtr p_Enemy;
};

#endif