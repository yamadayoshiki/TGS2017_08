#include "EnemyCommandEnemy04Standby.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../Enemys/Base/EnemyBase.h"
#include "../../../../../../Define/Def_Float.h"	//for FLOAT_EPSILON
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Map/Map.h"
#include "../../../../../../Define/Def_Nakayama.h"

//�R���X�g���N�^
EnemyCommandEnemy04Standby::EnemyCommandEnemy04Standby(
	const EnemyBasePtr & enemy,
	const FourDirection front)
	:EnemyCommandBase(enemy)
	, m_Front(front)
	, m_Counter(0)
	, m_Flag(false) {
}

//���b�Z�[�W����
void EnemyCommandEnemy04Standby::handleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::PLAYER_RELEASE:
		m_Counter++;
		if (m_Counter >= 3)
			SetNextTargetPos();

		break;
	}
}

//�e��ŗL�̏�����
void EnemyCommandEnemy04Standby::OnInitialize() {
	//�ϐ�������
	m_Counter = 0;
}

//�e��ŗL�̍X�V
void EnemyCommandEnemy04Standby::OnUpdate(float deltaTime) {
	//���܂ꂽ�񐔂��w��񐔖����̏ꍇreturn
	if (m_Counter < 3)
		return;

	//���܂ꂽ�񐔂��w��񐔈ȏ�̏ꍇ�s��
	else if (m_Counter >= 3)
	{
		//�ڕW�n�_�܂ł̋���
		m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
		//�ڕW�n�_�ɂ��ǂ蒅������
		if (m_Velocity.length() <= FLOAT_EPSILON)
			//�ڕW�n�_�ɓ��B�����Ƃ��̃��A�N�V����
			ArriveReaction();
	}
}

//�ڕW�n�_�ɓ��B�����Ƃ��̃��A�N�V����
void EnemyCommandEnemy04Standby::ArriveReaction() {
	//���܂ꂽ�񐔂����炷
	m_Counter = m_Counter - 3;
}

//���̖ڕW�n�_��ݒ肷��
void EnemyCommandEnemy04Standby::SetNextTargetPos() {
	//���ʂ��ǂȂ�return
	if (m_Flag == true) return;

	//�i�s�����ɂ���}�X���ǂ�
	if (p_Enemy->getWorld()->GetMap().IsInFrontOfTheWall(p_Enemy->getPosition(), m_Front, MapType::Double) == true)
		m_Flag = true;

	//���ʂɂ���^�C���̍��W��ݒ�
	else
	{
		//�ړ���
		GSvector2 velocity = p_Enemy->GetDirection().GetVector2() * CHIP_SIZE * 2;
		//���W�ݒ�
		m_NextTargetPos = p_Enemy->getPosition() + velocity;
	}
}
