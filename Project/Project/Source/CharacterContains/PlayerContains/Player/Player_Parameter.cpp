#include "Player_Parameter.h"

#include "../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/Number/NumberTexture.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

Player_Parameter::Player_Parameter()
{

}

//残機数の描画
void Player_Parameter::DrawRemaining(const Renderer2DPtr& renderer) {
	//std::stringstream ss;
	//ss << "×" << std::max<int>(0, m_Remaining);
	NumberTexture number(1000, 40, 60);
	// 画像の描画
	GSvector2 pos = GSvector2(10, 10);
	renderer->DrawTexture("life", pos);
	renderer->DrawTexture("batu", pos + GSvector2(60,0));
	number.draw(pos + GSvector2(110, 0), m_Remaining, 0);
	//// パラメーターの描画
	//gsTextPos(pos.x + 100, pos.y);
	//gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	//gsDrawText(ss.str().c_str());

	//// パラメータを戻す
	//gsFontParameter(GS_FONT_BOLD, 20, "HG明朝B");
}

//コンボ数の描画
void Player_Parameter::DrawCombo(const Renderer2DPtr & renderer)
{
	std::stringstream ss;
	ss << "COMBO " << m_Combo;
	// 画像の描画
	GSvector2 pos = GSvector2(500, 50);

	// パラメーターの描画
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	gsDrawText(ss.str().c_str());

	// パラメータを戻す
	gsFontParameter(GS_FONT_BOLD, 20, "HG明朝B");
}

//残機数の設定
void Player_Parameter::setRemaining(int remaining)
{
	m_Remaining = remaining;
}

//コンボ数の加算
void Player_Parameter::addCombo()
{
	m_Combo = std::min(m_Combo + 1 + m_BonusCombo, 999);
	if (m_MaxCombo < m_Combo) {
		m_MaxCombo = m_Combo;
	}
	m_ComboTimer = 180.0f;
}

//コンボ数をリセット
void Player_Parameter::comboReset()
{
	m_Combo = 0;
}

int Player_Parameter::getCombo()const
{
	return m_Combo;
}
int Player_Parameter::getMaxCombo() const
{
	return m_MaxCombo;
}
float Player_Parameter::getComboCounter()const
{
	return m_ComboTimer;
}

int Player_Parameter::addBonus()
{
	int bonus;
	//コンボ数を10で割った値かける
	bonus = 100 * m_Combo / 10;
	//結果を返す
	return bonus;
}

//チャージする
void Player_Parameter::Charge(float deltaTime)
{
	//チャージ時間によって返す値を変える
	if (m_ChargeConter > 120 * 3) {
		m_ChargePower = 3;
		m_BonusCombo = 4;
		m_Speed = 0.0f;
	}
	else if (m_ChargeConter > 120 * 2) {
		m_ChargePower = 2;
		m_BonusCombo = 2;
		m_Speed = 3.0f;
	}
	else if (m_ChargeConter > 120) {
		m_ChargePower = 1;
		m_BonusCombo = 1;
		m_Speed = 6.0f;
	}
	else if (m_ChargeConter <= 120)
	{
		m_ChargePower = 0;
		m_BonusCombo = 0;
		m_Speed = 8.0f;
	}
	m_ChargeConter += deltaTime;
}

//チャージしたパワーを返す
int Player_Parameter::getChargePower()
{
	//結果を返す
	return m_ChargePower;
}
bool Player_Parameter::getChargeFlag()const
{
	return Chargeflag;
}

void Player_Parameter::addRetryCount()
{
	m_RetryCount += 1;
}

int Player_Parameter::getRetryCount()
{
	return m_RetryCount;
}
