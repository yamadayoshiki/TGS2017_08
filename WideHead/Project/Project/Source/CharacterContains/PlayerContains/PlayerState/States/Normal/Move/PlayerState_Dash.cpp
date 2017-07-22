#include"PlayerState_Dash.h"

#include "../../../../../../Define/Def_Nakayama.h"
#include "../../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
//�R���X�g���N�^
PlayerState_Dash::PlayerState_Dash(const Player_WPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager)
{

}
//�e��ԓƎ��̏�����
void PlayerState_Dash::unique_init()
{
	//�A�j���[�V�����摜�̕ύX
	TextureName_Change("Player_Close");
	//�t���[���J�E���^�[�̏�����
	m_FramConter = 0.0f;
	//�X�s�[�h������
	speed = 14.0f;
	//Player�̕����x�N�g��
	m_Direction = p_Player.lock()->getTransform()->GetForward();
	//�G���h�n�_�̐ݒ�
	endPos = p_Player.lock()->getPosition() + m_Direction * (64 * 4);

	m_Flag = false;

	gsPlaySE(SE_PLAYER_DASH);

}
//�X�V����
void PlayerState_Dash::update(float deltaTime)
{
	ResultPushDirection resultPush;
	GSvector2 setPos = p_Player.lock()->getTransform()->m_Position += m_Direction * speed * deltaTime;

	/******************************************************************************************************************************/
	/*�ǂ��o������*/
	resultPush = p_Map.lock()->PushForPlayer(p_Player.lock()->getPosition(), setPos, MapType::Double, TerrainName::Wall);
	/*******************************************************************************************************************************/

	p_Player.lock()->setPosition(resultPush.position);

	//�A�[���̍X�V
	armUpdate();
	//�_�b�V���J�n�n�_
	GSvector2 stratPos = p_Player.lock()->getPosition();
	//�J�n�n�_����I�_�n�_�̋��������߂�
	float result = stratPos.distance(endPos);
	//����
	if (result <= 5.0f) {
		change(PlayerStateName::Walk);
	}
	if (p_Map.lock()->IsInFrontOfTheWall(p_Player.lock()->getPosition(), FourDirection(p_Player.lock()->getTransform()->GetForward()), MapType::Double)
		|| m_FramConter >= 15) {
		change(PlayerStateName::Walk);
	}

	m_FramConter += deltaTime;
}
//�Փˏ���
void PlayerState_Dash::collide(const Actor& other, const Body::ContactSet& contactSet)
{
	//�A�[���ɓ������Ă�����Ԃ�
	if (m_Children[ActorName::Player_Arm]->isCollide(other).m_IsCollide &&
		is_Scorp_Angle(other) &&
		m_Flag == true) return;

	//�G�Ƃ̏Փˏ���
	Collide(other, contactSet);
}
//���͏���
void PlayerState_Dash::input()
{
	if (p_Input->IsPadStateTrigger(GS_XBOX_PAD_B)) {
		TextureName_Change("Player_Open");
		m_Flag = true;
	}
	if (p_Input->IsPadStatesDetach(GS_XBOX_PAD_B) && m_Flag == true) {
		change(PlayerStateName::Swich);
	}
}
