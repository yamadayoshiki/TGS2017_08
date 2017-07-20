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
		p_Player.lock()->getWorld()->sendMessageOne(EventMessage::PLAYER_ROUNDS, const_cast<Actor&>(other));
		p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS, *(p_Player.lock()->getWorld()->findActor(ActorName::UI_ALL).get()));
		//�����x�N�g�����擾
		GSvector2 dis = other.getPosition() - p_Player.lock()->getPosition();
		//X�������킹��
		if (fabs(dis.x) > fabs(dis.y))
			p_Player.lock()->setPosition(GSvector2(p_Player.lock()->getPosition().x, other.getPosition().y));
		//Y�������킹��
		else
			p_Player.lock()->setPosition(GSvector2(other.getPosition().x, p_Player.lock()->getPosition().y));
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