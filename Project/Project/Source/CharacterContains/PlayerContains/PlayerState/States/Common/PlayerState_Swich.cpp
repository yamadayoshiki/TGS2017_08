#include"PlayerState_Swich.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
//�R���X�g���N�^
PlayerState_Swich::PlayerState_Swich(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
	, m_Flag(false) {
}

//�e��ԓƎ��̏�����
void PlayerState_Swich::unique_init()
{
	m_Flag = false;
}

//�X�V����
void PlayerState_Swich::update(float deltaTaime)
{
	if (m_Flag == true) {
		change(PlayerStateName::Rounds);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//�Փ˔���
void PlayerState_Swich::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	GSvector2 ArmPos = m_Children[ActorName::Player_Arm]->getPosition();
	GSvector2 EnePos = other.getPosition();
	float distance = ArmPos.distance(EnePos);
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide && is_Scorp_Angle(other) /*&& distance <= 24.0f*/) {
		m_Flag = true;
		//����ɋ��񂾏��𑗂�
		p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS, const_cast<Actor&>(other));
	}
}

//���b�Z�[�W����
void PlayerState_Swich::handleMessage(EventMessage message, void * param)
{
	switch (message)
	{
	case EventMessage::ENEMY_REPEL:
		change(PlayerStateName::Idle);
		break;
	}
}