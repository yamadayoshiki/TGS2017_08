#include "PlayerState_Crush.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Crush_Effect/Crush_Effect.h"
#include "../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"

PlayerState_Crush::PlayerState_Crush(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{
}
//�e��ԓƎ��̏�����
void PlayerState_Crush::unique_init()
{
	gsPlaySE(SE_PLAYER_CRUSH);
	p_Player.lock()->getWorld()->addActor(ActorGroup::Effect, std::make_shared<Crush_Effect>(p_Player.lock()->getWorld(),m_Children[ActorName::Player_Arm]->getPosition(), p_GameManager));
	p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_CRUSH,(void*)m_Parameter.getChargePower());
	p_GameManager->GetPlayerParameter().addCombo();
}
//�X�V����
void PlayerState_Crush::update(float deltaTime)
{
	change(PlayerStateName::Rounds);
}
//�Փ˔���
void PlayerState_Crush::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//�A�[���ɓ������Ă��邩����p���Ȃ�Ԃ�
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide && is_Scorp_Angle(other))return;
	//�G�Ƃ̏Փˏ���
	Collide(other,contactSet);
}

//���b�Z�[�W����
void PlayerState_Crush::handleMessage(EventMessage massege, void* param)
{
	switch (massege)
	{
	case EventMessage::PLAYER_ROUNDS:
		change(PlayerStateName::Rounds);
		break;

	case EventMessage::PLAYER_ROUNDSLOST:
		change(PlayerStateName::Crush_After);
		break;

	case EventMessage::ENEMY_REPEL:
		change(PlayerStateName::Idle);
		break;
	}
}