#ifndef BODYNAME_H_
#define BODYNAME_H_
//衝突判定図形の名前
enum class BodyName
{
	None,			//なし
	AARectangle,	//軸平行矩形
	Rectangle,		//矩形
	Line,			//線分
};
#endif