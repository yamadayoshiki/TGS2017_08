#include "Player_Parameter.h"

#include "../../../Utility/Rederer2D/Renderer2D.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

void Player_Parameter::DrawRemaining(const Renderer2DPtr& renderer) {
	std::stringstream ss;
	ss << "�~" << std::max<int>(0, m_Remaining);

	// �摜�̕`��
	GSvector2 pos = GSvector2(100, 50);
	renderer->DrawTexture("Player", pos);

	// �p�����[�^�[�̕`��
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG����B");
	gsDrawText(ss.str().c_str());
	
	// �p�����[�^��߂�
	gsFontParameter(GS_FONT_BOLD, 10, "HG����B");
}
