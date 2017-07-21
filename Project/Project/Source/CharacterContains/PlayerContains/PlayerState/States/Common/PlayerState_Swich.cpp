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
	if (p_Player.lock()->getParameter().getClipFlag() == true) {
		change(PlayerStateName::Rounds);
	}
	else {
		change(PlayerStateName::Close);
	}
}

//�Փ˔���
void PlayerState_Swich::collide(const Actor& other, const Body::ContactSet& contactSet){
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