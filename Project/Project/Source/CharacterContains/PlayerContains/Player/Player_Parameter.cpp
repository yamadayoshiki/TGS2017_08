#include "Player_Parameter.h"

#include "../../../Utility/Rederer2D/Renderer2D.h"

#include <gslib.h>
#include <GStype.h>
#include <sstream>
#include <algorithm>

void Player_Parameter::DrawRemaining(const Renderer2DPtr& renderer) {
	std::stringstream ss;
	ss << "×" << std::max<int>(0, m_Remaining);

	// 画像の描画
	GSvector2 pos = GSvector2(100, 50);
	renderer->DrawTexture("Player", pos);

	// パラメーターの描画
	gsTextPos(pos.x + 100, pos.y);
	gsFontParameter(GS_FONT_BOLD, 50, "HG明朝B");
	gsDrawText(ss.str().c_str());
	
	// パラメータを戻す
	gsFontParameter(GS_FONT_BOLD, 10, "HG明朝B");
}
