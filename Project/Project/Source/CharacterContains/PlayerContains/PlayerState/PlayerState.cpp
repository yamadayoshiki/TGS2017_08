#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>
#include"../../../Utility/MathSupport/MathSupport.h"
#include "../../../Map/Map.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"

//�R���X�g���N�^
PlayerState::PlayerState(const PlayerPtr& player, const IGameManagerPtr& gameManager)
	: p_Player(player)
	, p_GameManager(gameManager)
	, m_TransForm(player->getTransform())
	, m_Parameter(player->getParameter())
	, m_Map(player->getWorld()->GetMap()) 
{
	p_Input = gameManager->GetInputState();
}

//�p�b�h����
void PlayerState::input() {}

////���[�V�����ύX
//void PlayerState::motion_change(Actor& other, const PlayerStateID)
//{
//
//}

//�A�[���X�V
void PlayerState::armUpdate()
{
	//�A�[���̉�]����
	m_Children[ActorName::Player_Arm]->setAngle(p_Player->getTransform().m_Angle);
	//�A�[���̍��W�X�V����
	m_Children[ActorName::Player_Arm]->setPosition(p_Player->getTransform().m_Position + p_Player->getBody()->forward() * 16);
}
//�ړ�����
void PlayerState::move(float deltaTime, float speed)
{
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//���̓x�N�g��
		inputVelocity = p_Input->PadVelocity();
		if (inputVelocity.length() <= 0) return;

		FourDirection velocity = FourDirection(inputVelocity);


		//if (frontWall.Flag() == 1) {
		//	return;
		//}

		//�p�x�ݒ�
		p_Player->setAngle(MathSupport::GetVec2ToVec2Angle(inputVelocity));

		//���W�ړ�
		m_Position = p_Player->getTransform().m_Position + p_Input->PadVelocity() * speed * deltaTime;
		
		/******************************************************************************************************************************/
		/*�ǂ��o������*/
		m_Position = m_Map.PushForPlayer(p_Player->getPosition(), m_Position);
		/*******************************************************************************************************************************/

		p_Player->setPosition(m_Position);
	}
	//armUpdate();
}