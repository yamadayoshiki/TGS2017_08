#ifndef ENEMYSTATEENEMY02MOVEBASE_H_
#define ENEMYSTATEENEMY02MOVEBASE_H_

#include "../../../MoveContains/MoveBase/EnemyStateMoveBase.h"

//Enemy02��p�ړ����N���X
class EnemyStateEnemy02MoveBase : public EnemyStateMoveBase
{
public:
	// �R���X�g���N�^
	EnemyStateEnemy02MoveBase(const EnemyBasePtr& enemy);
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;

protected:
	// �e��ԓƎ��̏�����
	virtual void onUniqueInit() = 0;
	// �X�V����
	virtual void onUpdate(float deltaTime) = 0;
	// �Փ˔���
	virtual void onCollide(const Actor & other) = 0;
	// �I�����̏���
	virtual void onEnd() = 0;
	// ���͏���
	virtual void onInput() = 0;
};

#endif // !ENEMYSTATEENEMY02MOVEBASE_H_
