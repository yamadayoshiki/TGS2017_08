#include"PlayerState_Dash.h"


//�R���X�g���N�^
PlayerState_Dash::PlayerState_Dash(GSvector2& position, GSmatrix4& matrix, const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState_MoveBase(position,matrix,player,gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dash::onUniqueInit()
{
	//Player�̕����x�N�g��
	m_Direction = m_TransForm.m_Position.createFromDirection(m_TransForm.m_Angle);
	m_distance = m_TransForm.m_Position + m_Direction * 64.0f;
}
//�X�V����
void PlayerState_Dash::onUpdate(float deltaTime)
{
	m_TransForm.m_Position += m_Direction * 64;
	change(PlayerStateName::Idle);

}
//�Փˏ���
void PlayerState_Dash::onCollide(const Actor& other)
{

}