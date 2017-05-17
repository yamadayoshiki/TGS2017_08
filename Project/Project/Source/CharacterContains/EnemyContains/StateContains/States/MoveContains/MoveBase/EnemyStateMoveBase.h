#ifndef ENEMYSTATEMOVEBASE_H_
#define ENEMYSTATEMOVEBASE_H_

#include "../../Base/EnemyStateBase.h"

// �ʏ펞�̈ړ��N���X�̃x�[�X
class EnemyStateMoveBase : public EnemyStateBase
{
public:
	// �R���X�g���N�^
	EnemyStateMoveBase(const EnemyBasePtr& enemy);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	// �Փ˔���
	virtual void collide(const Actor & other) override;
	// �I�����̏���
	virtual void end() override;
	// ���͏���
	virtual void input() override;
	// ���b�Z�[�W����
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

#endif