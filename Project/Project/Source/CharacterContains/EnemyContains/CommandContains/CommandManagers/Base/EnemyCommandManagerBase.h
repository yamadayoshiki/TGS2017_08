#ifndef ENEMYCOMMANDMANAGERBASE_H_
#define ENEMYCOMMANDMANAGERBASE_H_

#include <map>
#include <vector>
#include "../Interface/IEnemyCommandManager.h"
#include "../../../Entity/Enemys/Base/EnemyBasePtr.h"

enum class EnemyCommandName;

//�G�l�~�[�R�}���h�}�l�[�W�����N���X
class EnemyCommandManagerBase : public IEnemyCommandManager
{
public:
	//�R���X�g���N�^
	EnemyCommandManagerBase(const EnemyBasePtr& enemy);
	//�f�X�g���N�^
	virtual ~EnemyCommandManagerBase();
	//������
	void Initialize() override;
	//�X�V
	void Update(float deltaTime) override;
	//�I��
	void Finalize() override;
	//�ǉ�
	void AddDic(const EnemyCommandName name,const IEnemyCommandPtr& command) override;
	//�R�}���h�ύX
	void Change(const EnemyCommandName name) override;
	//���b�Z�[�W����
	virtual void handleMessage(EventMessage message, void* param) override;

public:
	//���߃X�e�[�g�̎擾
	EnemyStateName GetCommandState() override;
	//�����ړ���
	virtual bool IsRegard() const;
	//���߃x�N�g���̎擾
	GSvector2& GetCommandVector() override;
	//���߉�]�p�x�̎擾
	float GetCommandRotateAngle() override;

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() {}
	//�e��ŗL�̏I��
	virtual void OnFinalize() {}
	//���̃R�}���h
	virtual EnemyCommandName GetNextCommand() = 0;

protected:
	EnemyBaseWPtr p_Enemy;										//�G�l�~�[�{��
	std::map<EnemyCommandName, IEnemyCommandPtr> m_CommandDic;	//�R�}���h����
	IEnemyCommandPtr p_CurCommand;								//���݂̃R�}���h
};

#endif