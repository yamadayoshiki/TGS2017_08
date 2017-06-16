#include "EnemyCommandBase.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../Map/Map.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Define/Def_Nakayama.h"
#include "../../../../../Define/Def_GSvector2.h"

//�R���X�g���N�^
EnemyCommandBase::EnemyCommandBase(const EnemyBasePtr& enemy)
	: IEnemyCommand()
	, p_Enemy(enemy)
	, m_CurStateName(EnemyStateName::None)
	, m_Regard(false)
	, m_Velocity(GSVECTOR2_ZERO)
	, m_RotateAngle(0.0f)
	, m_NextCommand(EnemyCommandName::None)
	, m_IsEnd(false) {
}

//������
void EnemyCommandBase::Initialize() {
	//�ϐ��̏�����
	m_CurStateName = EnemyStateName::None;
	m_NextCommand = EnemyCommandName::None;
	m_IsEnd = false;
	m_Regard = false;
	//�e��ŗL�̏�����
	OnInitialize();
}

//�X�V
void EnemyCommandBase::Update(float deltaTime) {
	//�ϐ��̏�����
	m_Velocity = GSVECTOR2_ZERO;
	m_RotateAngle = 0;
	//�e��ŗL�̍X�V
	OnUpdate(deltaTime);
}

//�ڕW�n�_�܂ł̈ړ��x�N�g���̎擾
GSvector2 EnemyCommandBase::GetVelocity() const {
	return m_Velocity;
}

//��]�p�x�̎擾
float EnemyCommandBase::GetRotateAngle() const {
	return m_RotateAngle;
}

//�I���`�F�b�N
bool EnemyCommandBase::IsEnd() {
	return m_IsEnd;
}

//���R�}���h�̎擾
EnemyCommandName EnemyCommandBase::GetNextCommand() const {
	return m_NextCommand;
}

//���߃X�e�[�g
EnemyStateName EnemyCommandBase::GetCurrentStateName() const {
	return m_CurStateName;
}

//�����ړ���
bool EnemyCommandBase::IsRegard() const{
	return m_Regard;
}

//���R�}���h�̐ݒ�
void EnemyCommandBase::Change(EnemyCommandName next) {
	m_NextCommand = next;
	m_IsEnd = true;
}