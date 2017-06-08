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
	int m_Remaining;
	//スタート地点
	GSvector2 m_StratPosition;
	//コンボ数
	int m_Combo;
public:
	void DrawRemaining(const Renderer2DPtr& renderer);
	void DrawCombo(const Renderer2DPtr& renderer);
	void setRemaining(int remaining);
};

#endif // !PLAYER_PARAMETER_H_
