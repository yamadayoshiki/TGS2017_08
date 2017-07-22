#include "EnemyCommandManagerOrder.h"

//�R���X�g���N�^
EnemyCommandManagerOrder::EnemyCommandManagerOrder(const EnemyBasePtr & enemy)
	: EnemyCommandManagerBase(enemy)
	, m_CurCommandNum(-1) {
}

//�R�}���h�����o�^(�ǉ���)
void EnemyCommandManagerOrder::AddList(EnemyCommandName name) {
	m_CommandNameList.push_back(name);
}

//�e��ŗL�̏�����
void EnemyCommandManagerOrder::OnInitialize() {
	m_CommandNameList.clear();
}

//�e��ŗL�̏I��
void EnemyCommandManagerOrder::OnFinalize() {
	m_CommandNameList.clear();
}

//���̃R�}���h
EnemyCommandName EnemyCommandManagerOrder::GetNextCommand() {
	//List�ԍ��̉��Z
	m_CurCommandNum++;
	if (m_CurCommandNum >= m_CommandNameList.size())
		m_CurCommandNum = 0;

	//List�̏���
	return m_CommandNameList[m_CurCommandNum];
}
