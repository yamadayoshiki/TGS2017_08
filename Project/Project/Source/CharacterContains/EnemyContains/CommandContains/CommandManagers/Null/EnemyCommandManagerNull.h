#ifndef ENEMYCOMMANDMANAGERNULL_H_
#define ENEMYCOMMANDMANAGERNULL_H_
#include "../Interface/IEnemyCommandManager.h"
class EnemyCommandManagerNull : public IEnemyCommandManager
{
public:
	//�R���X�g���N�^
	EnemyCommandManagerNull() {}
	//������
	virtual void Initialize() override{}
	//�X�V
	virtual void Update(float deltaTime) override {}
	//�I��
	virtual void Finalize() override {}
	//�ǉ�
	virtual void AddDic(const EnemyCommandName name, const IEnemyCommandPtr& command) override{}
	//�R�}���h�ύX
	virtual void Change(const EnemyCommandName name) override{}
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override {}

public:
	//���߃X�e�[�g�̎擾
	virtual EnemyStateName GetCommandState() override;
	//�����ړ���
	virtual bool IsRegard() const override { return false; }
	//���߃x�N�g���̎擾
	virtual GSvector2& GetCommandVector() override;
	//���߉�]�p�x�̎擾
	virtual float GetCommandRotateAngle() override { return 0.0f; }
};
#endif // !ENEMYCOMMANDMANAGERNULL_H_
