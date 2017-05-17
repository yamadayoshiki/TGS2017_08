#ifndef IENEMYCOMMANDMANAGER_H_
#define IENEMYCOMMANDMANAGER_H_

#include "../../Commands/Interface/IEnemyCommandPtr.h"

//��s�錾
enum class EnemyCommandName;
enum class EnemyStateName;
struct GSvector2;

//�G�l�~�[�R�}���h�}�l�[�W���C���^�[�t�F�C�X
class IEnemyCommandManager
{
public:
	//���z�f�X�g���N�^
	virtual ~IEnemyCommandManager() {}
	//������
	virtual void Initialize() = 0;
	//�X�V
	virtual void Update(float deltaTime) = 0;
	//�I��
	virtual void Finalize() = 0;
	//�ǉ�
	virtual void AddDic(EnemyCommandName name, const IEnemyCommandPtr& command) = 0;
	//�R�}���h�ύX
	virtual void Change(const EnemyCommandName name) = 0;

public:
	//���߃X�e�[�g�̎擾
	virtual EnemyStateName GetCommandState() = 0;
	//���߃x�N�g���̎擾
	virtual GSvector2& GetCommandVector() = 0;
	//���߉�]�p�x�̎擾
	virtual float GetCommandRotateAngle() = 0;
};

#endif