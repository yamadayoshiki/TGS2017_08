#ifndef PLAYER_PARAMETER_H_
#define PLAYER_PARAMETER_H_

#include "../../../Utility/Rederer2D/Renderer2DPtr.h"

//プレイヤーパラメーター
struct Player_Parameter
{
	//残機数
	int m_Remaining;
public:
	void DrawRemaining(const Renderer2DPtr& renderer);
};

#endif // !PLAYER_PARAMETER_H_
