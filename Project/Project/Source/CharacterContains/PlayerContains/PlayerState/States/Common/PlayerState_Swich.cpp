#include"PlayerState_Swich.h"
#include"../../../../../WorldContains/EventMessage/EventMessage.h"
#include"../../../../../Utility/MathSupport/MathSupport.h"


//�R���X�g���N�^
PlayerState_Swich::PlayerState_Swich(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
	,m_Flag(false){
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
void PlayerState_Swich::collide(const Actor& other)
{
	//�t���O
	bool flag = false;
	//�����̕����x�N�g��
	GSvector2 tmp = p_Player->getBody()->forward();
	tmp.normalize();


	//����̃x�N�g��
	GSvector2 v = other.getPosition() - p_Player->getPosition();
	v.normalize();
	//�����Ƒ���̃x�N�g������Ȃ��p�����
	float l_result1 = tmp.innerDegree(v);
	//����p��(30�x)�ɂ��邩�H
	if (l_result1 <= 30.0f) {
		flag = true;
	}

	if (m_Children[ActorName::Player_Arm]->isCollide(other) && flag == true) {
		m_Flag = true;
		//����ɋ��񂾏��𑗂�
		p_Player->getWorld()->sendMessage(EventMessage::PLAYER_ROUNDS, const_cast<Actor&>(other));
	}
}