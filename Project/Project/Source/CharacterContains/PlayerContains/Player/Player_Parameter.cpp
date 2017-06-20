#include "Player_Parameter.h"

#include "../../../Utility/Rederer2D/Renderer2D.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

Player_Parameter::Player_Parameter()
{

}

//�c�@���̕`��
void Player_Parameter::DrawRemaining(const Renderer2DPtr& renderer) {
	std::stringstream ss;
	ss << "�~" << std::max<int>(0, m_Remaining);

	// �摜�̕`��
	GSvector2 pos = GSvector2(50, 50);
	renderer->DrawTexture("Player_Clip", pos);

	// �p�����[�^�[�̕`��
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());
	
	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}

//�R���{���̕`��
void Player_Parameter::DrawCombo(const Renderer2DPtr & renderer)
{
	std::stringstream ss;
	ss <<  "COMBO " <<m_Combo;
	// �摜�̕`��
	GSvector2 pos = GSvector2(500, 50);

	// �p�����[�^�[�̕`��
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());

	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}

//�c�@���̐ݒ�
void Player_Parameter::setRemaining(int remaining)
{
	m_Remaining = remaining;
}

//�R���{���̉��Z
void Player_Parameter::addCombo()
{
	m_Combo += 1;
	m_FrameCounter = 0;
}

//�R���{�������Z�b�g
void Player_Parameter::comboReset(float deltaTime)
{
	//
	if (m_FrameCounter > 180) {
		m_Combo = 0;
	}
}

int Player_Parameter::addBonus()
{
	int bonus;
	//�R���{����10�Ŋ������l������
	bonus = 100 * m_Combo / 10;
	//���ʂ�Ԃ�
	return bonus;
}

//�`���[�W����
void Player_Parameter::Charge(float deltaTime)
{
	//�`���[�W���Ԃɂ���ĕԂ��l��ς���
	if (m_ChargeConter > 120 * 3) {
		m_ChargePower = 3;
		m_Speed = 0.0f;
	}
	else if (m_ChargeConter > 120 * 2) {
		m_ChargePower = 2;
		m_Speed = 3.0f;
	}
	else if (m_ChargeConter > 120) {
		m_ChargePower = 1;
		m_Speed = 6.0f;
	}
	else if(m_ChargeConter <= 120)
	{
		m_ChargePower = 0;
		m_Speed = 8.0f;
	}
	m_ChargeConter += deltaTime;
}

//�`���[�W�����p���[��Ԃ�
int Player_Parameter::getChargePower()
{
	//���ʂ�Ԃ�
	return m_ChargePower;
}
bool Player_Parameter::getChargeFlag()const
{
	return Chargeflag;
}