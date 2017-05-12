#ifndef ENEMYCOMMANDMANAGER_H_
#define ENEMYCOMMANDMANAGER_H_

#include <gslib.h>
#include <map>
#include <vector>

#include "../../Enemys/Base/EnemyBasePtr.h"
#include "../Commands/Interface/IEnemyCommandPtr.h"

enum class EnemyStateName;
enum class EnemyCommandName;

class EnemyCommandManager
{
public:
	//�R���X�g���N�^
	EnemyCommandManager(const EnemyBasePtr& enemy);
	//�f�X�g���N�^
	~EnemyCommandManager();
	//����������
	void Initialize();
	//�X�V����
	void Update(float deltaTime);
	//�I������
	void Finalize();
	//�R�}���h�����o�^
	void AddDic(EnemyCommandName name, const IEnemyCommandPtr& command);
	//�R�}���h�����o�^
	void AddList(EnemyCommandName name);

private:
	//�R�}���h�ύX
	void Change(const EnemyCommandName name);

public:
	//���߃X�e�[�g�̎擾
	EnemyStateName GetCommandState() const;
	//���߃x�N�g���̎擾
	GSvector2& GetCommandVector() const;
	//���߉�]�p�x�̎擾
	float GetCommandRotateAngle() const;

private:
	EnemyBasePtr p_Enemy;										//�G�l�~�[�{��
	std::map<EnemyCommandName, IEnemyCommandPtr> m_CommandDic;	//�R�}���h����
	std::vector<EnemyCommandName> m_CommandNameList;			//�R�}���h����
	IEnemyCommandPtr p_CurCommand;								//���݂̃R�}���h
	int m_CurCommandNum;										//���݂̃R�}���h�ԍ�
};

#endif