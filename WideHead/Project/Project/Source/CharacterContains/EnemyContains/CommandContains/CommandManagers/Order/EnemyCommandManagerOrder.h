#ifndef ENEMYCOMMANDMANAGERORDER_H_
#define ENEMYCOMMANDMANAGERORDER_H_

#include <vector>
#include "../Base/EnemyCommandManagerBase.h"

//�G�l�~�[�R�}���h�}�l�[�W��/�����t��
class EnemyCommandManagerOrder :public EnemyCommandManagerBase
{
public:
	//�R���X�g���N�^
	EnemyCommandManagerOrder(const EnemyBasePtr& enemy);
	//�R�}���h�����o�^(�ǉ���)
	void AddList(EnemyCommandName name);

protected:
	//�e��ŗL�̏�����
	virtual void OnInitialize() override;
	//�e��ŗL�̏I��
	virtual void OnFinalize() override;
	//���̃R�}���h
	virtual EnemyCommandName GetNextCommand() override;

protected:
	std::vector<EnemyCommandName> m_CommandNameList;	//�R�}���h����
	int m_CurCommandNum;								//���݂̃R�}���h�ԍ�
};

#endif // !ENEMYCOMMANDMANAGERORDER_H_
