#include "EnemyCommandManagerBase.h"
#include "../../Commands/Interface/IEnemyCommand.h"
#include "../../Commands/Null/EnemyCommandNull.h"
#include <GSvector2.h>

//�R���X�g���N�^
EnemyCommandManagerBase::EnemyCommandManagerBase(const EnemyBasePtr& enemy)
	: p_Enemy(enemy)
	, p_CurCommand(std::make_shared<EnemyCommandNull>()) {
	m_CommandDic.clear();
	Initialize();
}

//�f�X�g���N�^
EnemyCommandManagerBase::~EnemyCommandManagerBase() {
	Finalize();
	p_Enemy.reset();
}

//������
void EnemyCommandManagerBase::Initialize() {
	m_CommandDic.clear();
	//�e��ŗL�̏�����
	OnInitialize();
}

//�X�V
void EnemyCommandManagerBase::Update(float deltaTime) {
	//���݂̃R�}���h�X�V
	p_CurCommand->Update(deltaTime);

	//�I�����肪true�̏ꍇ�ύX
	if (p_CurCommand->IsEnd() == true)
		Change(GetNextCommand());
}

//�I��
void EnemyCommandManagerBase::Finalize() {
	m_CommandDic.clear();
	//�e��ŗL�̏I��
	OnFinalize();
}

//�ǉ�
void EnemyCommandManagerBase::AddDic(const EnemyCommandName name, const IEnemyCommandPtr& command) {
	m_CommandDic[name] = command;
}

//���߃X�e�[�g�̎擾
EnemyStateName EnemyCommandManagerBase::GetCommandState() {
	return p_CurCommand->GetCurrentStateName();
}

//�����ړ���
bool EnemyCommandManagerBase::IsRegard() const {
	return p_CurCommand->IsRegard();
}

//���߃x�N�g���̎擾
GSvector2 & EnemyCommandManagerBase::GetCommandVector() {
	return p_CurCommand->GetVelocity();
}

//���߉�]�p�x�̎擾
float EnemyCommandManagerBase::GetCommandRotateAngle() {
	return p_CurCommand->GetRotateAngle();
}

//�R�}���h�ύX
void EnemyCommandManagerBase::Change(const EnemyCommandName name) {
	p_CurCommand->Finalize();
	p_CurCommand = m_CommandDic[name];
	p_CurCommand->Initialize();
}

//���b�Z�[�W����
void EnemyCommandManagerBase::handleMessage(EventMessage message, void * param) {
	p_CurCommand->handleMessage(message, param);
}
