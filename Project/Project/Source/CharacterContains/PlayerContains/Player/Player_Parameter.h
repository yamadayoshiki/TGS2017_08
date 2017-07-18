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
	//座標
	GSvector2 m_Position{ 0.0f,0.0f };
	//残機数
	int m_Remaining{ 0 };
	//スタート地点
	GSvector2 m_StratPosition;
	//コンボ数
	int m_Combo{ 0 };
	//Maxコンボ数
	int m_MaxCombo{ 0 };
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
	//リトライ数
	int m_RetryCount{ 0 };
	//チャージボーナスコンボ
	int m_BonusCombo{ 0 };

public:
	GSvector2 getPosition()const;
	void setPosition(const GSvector2& position);
	int GetRemaining() const;
	void setRemaining(int remaining);
	void addCombo();
	void comboReset();
	int  getCombo()const;
	int  getMaxCombo()const;
	float getComboCounter()const;
	int addBonus();
	void Charge(float deltaTime);
	int getChargePower();
	bool getChargeFlag()const;
	void addRetryCount();
	int getRetryCount();
};

#endif // !PLAYER_PARAMETER_H_
