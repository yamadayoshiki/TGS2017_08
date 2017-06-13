#ifndef ENEMYSTATESPINSTANDARD_H_
#define ENEMYSTATESPINSTANDARD_H_

#include "../../Base/EnemyStateBase.h"

//�X�s���X�^���_�[�h�N���X
class EnemyStateSpinStandard : public EnemyStateBase
{
public:
	//�R���X�g���N�^
	EnemyStateSpinStandard(const EnemyBasePtr& enemy,float speed);
	// �e��ԓƎ��̏�����
	virtual void unique_init() override;
	// �X�V����
	virtual void update(float deltaTime) override;
	//�I��
	virtual void end() override;
protected:
	//���b�Z�[�W����
	virtual void OnHandleMessage(EventMessage message, void* param) override;

protected:
	float m_Speed;	//�X�s�[�h
};

#endif // !ENEMYSTATESPINSTANDARD_H_
