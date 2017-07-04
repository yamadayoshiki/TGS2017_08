#ifndef PLAYER_PARAMETER_H_
#define PLAYER_PARAMETER_H_

#include "../../../Utility/Rederer2D/Renderer2DPtr.h"
#include"../../../Utility/Animation/Animation.h"
#include<gslib.h>

//プレイヤーパラメーター
struct Player_Parameter
{
public:
	Player_Parameter();
	//残機数
	int m_Remaining{ 0 };
	//スタート地点
	GSvector2 m_StratPosition;
	//コンボ数
	int m_Combo{ 0 };
	//コンボタイマー
	float m_ComboTimer{ 0.0f };
	//フレームカウンター
	float m_FrameCounter{ 0.0f };
	//チャージフラグ
	bool Chargeflag{ false };
	//スピード
	float m_Speed{5.0f};
	//チャージカウンター
	float m_ChargeConter{ 0.0f };
	//チャージパワー
	int m_ChargePower{ 0 };

public:
	void DrawRemaining(const Renderer2DPtr& renderer);
	void DrawCombo(const Renderer2DPtr& renderer);
	void setRemaining(int remaining);
	void addCombo();
	void comboReset();
	int  getCombo()const;
	float getComboCounter()const;
	int addBonus();
	void Charge(float deltaTime);
	int getChargePower();
	bool getChargeFlag()const;
};

#endif // !PLAYER_PARAMETER_H_
