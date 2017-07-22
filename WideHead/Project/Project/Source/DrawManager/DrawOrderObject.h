#ifndef DRAWORDEROBJECT_H_
#define DRAWORDEROBJECT_H_
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include <iostream>
using DrawOrderID = int;
//描画オブジェクト構造体
struct DrawOrderObject
{
	DrawOrderID id;					//描画順
	std::string texName;			//テクスチャの名前
	Texture2DParameterWPtr param;	//テクスチャのパラメータ

									//std::set用比較演算子
	bool operator < (const DrawOrderObject& other) {
		return this->id < other.id;
	}
};
#endif // !DRAWORDEROBJECT_H_
