#ifndef PLAYER_PARAMETER_H_
#define PLAYER_PARAMETER_H_

#include "../../../Utility/Rederer2D/Renderer2DPtr.h"

//�v���C���[�p�����[�^�[
struct Player_Parameter
{
	//�c�@��
	int m_Remaining;
public:
	void DrawRemaining(const Renderer2DPtr& renderer);
};

#endif // !PLAYER_PARAMETER_H_
