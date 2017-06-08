#include"PlayerState.h"
#include <algorithm>
#include<GSmath.h>
#include"../../../Utility/MathSupport/MathSupport.h"
#include "../../../Map/Map.h"
#include"../../../Utility/FourDirection/FourDirection.h"
#include "../../../Define/Def_Nakayama.h"
#include"../../../Map/MapType.h"

//�R���X�g���N�^
PlayerState::PlayerState(const Player_WPtr& player, const IGameManagerPtr& gameManager)
	: p_Player(player)
	, p_GameManager(gameManager)
	, m_TransForm(player.lock()->getTransform())
	, m_Parameter(player.lock()->getParameter())
	, m_Map(player.lock()->getWorld()->GetMap())
{
	p_Input = gameManager->GetInputState();
}

//�p�b�h����
void PlayerState::input() {}

//���[�V�����ύX
void PlayerState::motion_change(const PlayerMotion_ID id)
{

}

//�A�[���X�V
void PlayerState::armUpdate()
{
	//�A�[���̉�]����
	m_Children[ActorName::Player_Arm]->setAngle(p_Player.lock()->getTransform().m_Angle);
	//�A�[���̍��W�X�V����
	m_Children[ActorName::Player_Arm]->setPosition(p_Player.lock()->getTransform().m_Position + p_Player.lock()->getBody()->forward() * 16);
}
//�ړ�����
void PlayerState::move(float deltaTime, float speed)
{
	ResultPushDirection result;
	if (p_Input->PadVelocity().length() > 0.0f)
	{
		//���̓x�N�g��
		inputVelocity = p_Input->PadVelocity();
		if (inputVelocity.length() <= 0) return;

		FourDirection velocity = FourDirection(inputVelocity);

		//�p�x�ݒ�
		p_Player.lock()->setAngle(MathSupport::GetVec2ToVec2Angle(inputVelocity));

		//���W�ړ�
		m_Position = p_Player.lock()->getTransform().m_Position + p_Input->PadVelocity() * speed * deltaTime;
		
		result = m_Map.PushForChara(p_Player.lock()->getPosition(), m_Position, MapType::Double);

		/******************************************************************************************************************************/
		/*�ǂ��o������*/
		m_Position = result.position;
		/*******************************************************************************************************************************/

		p_Player.lock()->setPosition(m_Position);
	}
}

//����p���ɂ��邩
bool PlayerState::is_Scorp_Angle(const Actor& other)
{
	//�����̕����x�N�g��
	GSvector2 myVector = p_Player.lock()->getBody()->forward();
	myVector.normalize();

	//����̃x�N�g��
	GSvector2 targetVector = other.getPosition() - (p_Player.lock()->getPosition() - p_Player.lock()->getBody()->forward() * 16);
	targetVector.normalize();

	//�����Ƒ���̃x�N�g������Ȃ��p�����
	float result = myVector.innerDegree(targetVector);

	//����p��(45�x)�ɂ��邩�H
	if (result <= 45.0f) {
		return true;
	}
	return false;
}

//�e�N�X�`�����O�ύX
void PlayerState::TextureName_Change(const std::string& name)
{
	p_Player.lock()->setName_Animation(name);
}

//�G�Ƃ̏Փˏ���
void PlayerState::Collide(const Actor& other)
{
	if (static_cast<int>(other.getName()) >= 101) {
		change(PlayerStateName::Damage);
	}
	//if (other.getName() == ActorName::Enemy_01 || other.getName() == ActorName::Enemy_02
	//	|| other.getName() == ActorName::Enemy_03 || other.getName() == ActorName::Enemy_04)
	//{
	//	change(PlayerStateName::Damage);
	//}
}

//
void PlayerState::Center_Adjustment()
{
	GSvector2 texCenter = GSvector2(14, 20);
	GSvector2 center = GSvector2(32, 32);
}