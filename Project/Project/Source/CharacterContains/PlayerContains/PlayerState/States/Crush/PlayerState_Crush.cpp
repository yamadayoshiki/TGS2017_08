#include "PlayerState_Crush.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"

PlayerState_Crush::PlayerState_Crush(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{
}
//�e��ԓƎ��̏�����
void PlayerState_Crush::unique_init()
{
	p_Player->getWorld()->sendMessage(EventMessage::PLAYER_CRUSH);
}
//�X�V����
void PlayerState_Crush::update(float deltaTime)
{
	p_Player->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS);
}
//�Փ˔���
void PlayerState_Crush::collide(const Actor& other)
{
	//�����̕����x�N�g��
	GSvector2 myVec = p_Player->getBody()->forward();
	myVec.normalize();

	//����̃x�N�g��
	GSvector2 targetVec = other.getPosition() - p_Player->getPosition();
	targetVec.normalize();
	//�A�[���ɓ������Ă��邩����p���Ȃ�Ԃ�
	if (m_Children[ActorName::Player_Arm]->isCollide(other) && is_Scorp_Angle(myVec, targetVec))return;

	if (other.getName() == ActorName::Enemy_01) change(PlayerStateName::Damage);
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
		change(PlayerStateName::Close);
		break;
	}
}