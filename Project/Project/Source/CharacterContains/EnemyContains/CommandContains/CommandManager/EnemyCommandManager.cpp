#include "EnemyCommandManager.h"
#include "../Commands/Interface/IEnemyCommand.h"
#include "../Commands/NullCommand/Enemy_NullCommand.h"

//�R���X�g���N�^
EnemyCommandManager::EnemyCommandManager(const EnemyBasePtr& enemy)
	: p_Enemy(enemy)
	, p_CurCommand(std::make_shared<EnemyCommandNull>(enemy))
	, m_CurCommandNum(-1) {
	Initialize();
}

//�f�X�g���N�^
EnemyCommandManager::~EnemyCommandManager() {
	m_CommandDic.clear();
	m_CommandNameList.clear();
}

//����������
void EnemyCommandManager::Initialize() {
	m_CommandDic.clear();
	m_CommandNameList.clear();
	m_CurCommandNum = -1;
}

//�X�V����
void EnemyCommandManager::Update(float deltaTime) {
	//���݂̃R�}���h�I���`�F�b�N
	if (p_CurCommand->IsEnd() == true)
	{
		m_CurCommandNum++;
		if (m_CurCommandNum >= m_CommandNameList.size())
			m_CurCommandNum = 0;

		//�R�}���h����ւ�
		Change(m_CommandNameList[m_CurCommandNum]);
	}

	//���݂̃R�}���h�X�V
	p_CurCommand->Update(deltaTime);
}

//�I������
void EnemyCommandManager::Finalize() {
}

//�R�}���h�����o�^
void EnemyCommandManager::AddDic(EnemyCommandName name, const IEnemyCommandPtr& command) {
	m_CommandDic[name] = command;
}

//�R�}���h�����o�^
void EnemyCommandManager::AddList(EnemyCommandName name) {
	m_CommandNameList.push_back(name);
}

//�R�}���h�ύX
void EnemyCommandManager::Change(const EnemyCommandName name) {
	p_CurCommand->Finalize();
	p_CurCommand = m_CommandDic[name];
	p_CurCommand->Initialize();
}

//���߃x�N�g���̎擾
GSvector2& EnemyCommandManager::GetCommandVector() const {
	return p_CurCommand->GetVelocity();
}

//���߃X�e�[�g�̎擾
EnemyStateName EnemyCommandManager::GetCommandState() const {
	return p_CurCommand->GetCurrentStateName();
}

//���߉�]�p�x�̎擾
float EnemyCommandManager::GetCommandRotateAngle() const {
	return p_CurCommand->GetRotateAngle();
}