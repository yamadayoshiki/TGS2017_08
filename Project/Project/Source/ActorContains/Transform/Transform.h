#pragma once

#include <gslib.h>

// 変換構造体
struct Transform {
	// 座標
	GSvector2 m_Position;
	// 回転角度
	float m_Angle;
};