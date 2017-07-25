#ifndef ENEMYCOMMANDNULL_H_
#define ENEMYCOMMANDNULL_H_

#include "../Interface/IEnemyCommand.h"

class EnemyCommandNull : public IEnemyCommand
{
public:
	//�R���X�g���N�^
	EnemyCommandNull() {}
	//������
	virtual void Initialize()override {}
	//�X�V
	virtual void Update(float deltaTime) override {}
	//�I��
	virtual void Finalize() override {}
	//�I���`�F�b�N
	virtual bool IsEnd() override { return true; }
	//���R�}���h�̎擾
	virtual EnemyCommandName GetNextCommand() const override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override {}
	//���߃X�e�[�g
	virtual EnemyStateName GetCurrentStateName() const override;
	//�����ړ���
	virtual bool IsRegard() const override { return false; }
	//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
	virtual GSvector2 GetVelocity() const override;
	//��]�p�x�̎擾
	virtual float GetRotateAngle() const override { return 0.0f; }
};


#endif
