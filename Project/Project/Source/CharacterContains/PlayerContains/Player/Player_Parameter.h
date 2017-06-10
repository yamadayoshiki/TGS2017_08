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
	//フレームカウンター
	float m_FrameCounter{ 0.0f };
	//フラグ
	bool flag{ false };
	//スピード
	float m_Speed{8.0f};
	//チャージカウンター
	float m_ChargeConter{ 0.0f };
	//チャージパワー
	int m_ChargePower{ 0 };

public:
	void DrawRemaining(const Renderer2DPtr& renderer);
	void DrawCombo(const Renderer2DPtr& renderer);
	void setRemaining(int remaining);
	void addCombo();
	void comboReset(float deltaTime);
	int addBonus();
	void Charge(float deltaTime);
	int getChargePower();
};

#endif // !PLAYER_PARAMETER_H_
