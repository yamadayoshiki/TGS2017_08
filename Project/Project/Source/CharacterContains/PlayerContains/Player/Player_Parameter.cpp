#include "Player_Parameter.h"

#include "../../../Utility/Rederer2D/Renderer2D.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

Player_Parameter::Player_Parameter()
{

}

void Player_Parameter::DrawRemaining(const Renderer2DPtr& renderer) {
	std::stringstream ss;
	ss << "�~" << std::max<int>(0, m_Remaining);

	// �摜�̕`��
	GSvector2 pos = GSvector2(100, 50);
	renderer->DrawTexture("Player_Clip", pos);

	// �p�����[�^�[�̕`��
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());
	
	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 20, "HG����B");
}

void Player_Parameter::setRemaining(int remaining)
{
	m_Remaining = remaining;
}
