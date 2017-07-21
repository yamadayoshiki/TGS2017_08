#include"PlayerState_Round.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../ActorContains/ActorGroup.h"
#include"../../../../NeutralContains/Repel_Effect/Repel_Effect.h"
#include "../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include"../../../../../ActorContains/BodyContains/Factory/BodyFactory.h"
//�R���X�g���N�^
PlayerState_Round::PlayerState_Round(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Round::unique_init()
{
	TextureName_Change("Player_Clip");
	gsPlaySE(SE_PLAYER_CLIP);
	p_Player.lock()->getWorld()->GetBodyFactory()->Transform(p_Player.lock()->getBody(), Body::BodyDataName::Player_Clip);
}
//�X�V����
void PlayerState_Round::update(float deltaTime)
{

}
//�Փ˔���
void PlayerState_Round::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide)return;

	//�G�Ƃ̏Փˏ���
	Collide(other,contactSet);

	p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_RELEASE);
}
//�I������
void PlayerState_Round::end()
{

}
//���͏���
void PlayerState_Round::input()
{
	//�ׂ���ԂɑJ��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_Y)) {
		change(PlayerStateName::Crush);
	}
	//������ԂɑJ��
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		p_Player.lock()->getWorld()->sendMessage(EventMessage::PLAYER_RELEASE);
		change(PlayerStateName::Release);
	}
}

//���b�Z�[�W����
void PlayerState_Round::handleMessage(EventMessage massege, void * param)
{
	switch (massege)
	{
	case EventMessage::PLAYER_ROUNDSLOST:
		change(PlayerStateName::Close);
		p_Player.lock()->getParameter().m_ClipFlag = false;
		break;
	case EventMessage::ENEMY_REPEL:
		p_Player.lock()->getWorld()->addActor(ActorGroup::Effect,
			std::make_shared<Repel_Effect>(
				p_Player.lock()->getWorld(),p_Player.lock()->getPosition(), p_GameManager));
		p_Player.lock()->getParameter().m_ClipFlag = false;
		change(PlayerStateName::Idle);
		break;
	}
}

