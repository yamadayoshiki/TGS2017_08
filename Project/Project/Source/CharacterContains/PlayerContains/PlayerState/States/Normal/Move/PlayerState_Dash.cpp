#include"PlayerState_Dash.h"

#include "../../../../../../Define/Def_Nakayama.h"

//�R���X�g���N�^
PlayerState_Dash::PlayerState_Dash(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dash::unique_init()
{
	//�t���[���J�E���^�[�̏�����
	m_FrameCounter = 0.0f;
	//�X�s�[�h������
	speed = 32.0f;
	//Player�̕����x�N�g��
	m_Direction = p_Player->getBody()->forward();
	//�X�^�[�g�n�_�̐ݒ�
	startPos = p_Player->getTransform().m_Position;;
	//�G���h�n�_�̐ݒ�
	endPos	 = p_Player->getTransform().m_Position + m_Direction * (64 * 4);
	//2�_�Ԃ̋���
	m_Distance = startPos.distance(endPos);
}
//�X�V����
void PlayerState_Dash::update(float deltaTime)
{
	GSvector2 setPos = p_Player->getTransform().m_Position += m_Direction * speed * deltaTime;

	/******************************************************************************************************************************/
	/*�ǂ��o������*/
	setPos = m_Map.PushForPlayer(p_Player->getPosition(), setPos);
	/*******************************************************************************************************************************/
	
	p_Player->setPosition(setPos);
	if (speed >= 8.0f && m_FrameCounter > 3) {
		speed = speed / 2.0f;
	}
	armUpdate();
	GSvector2 pos = p_Player->getPosition();
	float result = pos.distance(endPos);
	if (result <= 1.0f) {
		change(PlayerStateName::Walk);
	}
	if (m_Map.IsInFrontOfTheWallForPlayer(p_Player->getPosition(), FourDirection(p_Player->getBody()->forward()))) {
		change(PlayerStateName::Walk);
	}

	m_FrameCounter += deltaTime;
}
//�Փˏ���
void PlayerState_Dash::collide(const Actor& other)
{
	if (m_FrameCounter > 8) {
		//�G�Ƃ̏Փˏ���
		change(PlayerStateName::Damage);
	}
}