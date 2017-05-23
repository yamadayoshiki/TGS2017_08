#include "FourDirection.h"
#include "../../Define/Def_GSvector2.h"
#include "../../Utility/MathSupport/MathSupport.h"

//コンストラクタ
FourDirection::FourDirection(const FourDirectionName directionName)
	:name(directionName) {

}

//コンストラクタ
FourDirection::FourDirection(const GSvector2& vector)
	: FourDirection(GetVector2ToFourDirection(vector)) {
}

//コンストラクタ
FourDirection::FourDirection(const float angle)
	: FourDirection(MathSupport::GetAngleToVector2(angle)) {
}

//デフォルトコンストラクタ
FourDirection::FourDirection()
	: FourDirection(FourDirectionName::None) {
}

//指定方向に回転(90度)
FourDirection FourDirection::Turn(TurnDirection turnDirection) {
	name = GetTurn(turnDirection).name;
	return *this;
}

//指定方向に回転(90度)
FourDirection FourDirection::GetTurn(TurnDirection turnDirection) const {
	//結果変数
	FourDirection result;

	switch (turnDirection.name)
	{
	case TurnDirectionName::Clockwise:
		switch (name)
		{
		case FourDirectionName::Up:
			result.name = FourDirectionName::Right;
			break;
		case FourDirectionName::Right:
			result.name = FourDirectionName::Down;
			break;
		case FourDirectionName::Down:
			result.name = FourDirectionName::Left;
			break;
		case FourDirectionName::Left:
			result.name = FourDirectionName::Up;
			break;
		default:
			result.name = FourDirectionName::None;
			break;
		}
		break;
	case TurnDirectionName::AntiClockwise:
		switch (name)
		{
		case FourDirectionName::Up:
			result.name = FourDirectionName::Left;
			break;
		case FourDirectionName::Right:
			result.name = FourDirectionName::Up;
			break;
		case FourDirectionName::Down:
			result.name = FourDirectionName::Right;
			break;
		case FourDirectionName::Left:
			result.name = FourDirectionName::Down;
			break;
		default:
			result.name = FourDirectionName::None;
			break;
		}
		break;
	}
	return result;
}

//反転
FourDirection FourDirection::TurnOver() {
	name = GetTurnOver().name;
	return *this;
}

//反転
FourDirection FourDirection::GetTurnOver() const {
	FourDirection result;
	switch (name)
	{
	case FourDirectionName::Up:
		result.name = FourDirectionName::Down;
		break;
	case FourDirectionName::Right:
		result.name = FourDirectionName::Left;
		break;
	case FourDirectionName::Down:
		result.name = FourDirectionName::Up;
		break;
	case FourDirectionName::Left:
		result.name = FourDirectionName::Right;
		break;
	default:
		result.name = FourDirectionName::None;
		break;
	}
	return result;
}

//GSvector2に置き換え
GSvector2 FourDirection::GetVector2() const {
	switch (name)
	{
	case FourDirectionName::Up:
		return DIRECTION_UP;

	case FourDirectionName::Right:
		return DIRECTION_RIGHT;

	case FourDirectionName::Down:
		return DIRECTION_DOWN;

	case FourDirectionName::Left:
		return DIRECTION_LEFT;

	default:
		return GSVECTOR2_ZERO;
	}
}

//角度に置き換え
float FourDirection::GetAngle() const {
	float result;
	result = MathSupport::GetVec2ToVec2Angle(GetVector2(), DIRECTION_RIGHT);
	return result;
}

//Gsvector2をFourDirectionNameに変換
FourDirection FourDirection::GetVector2ToFourDirection(const GSvector2& vector)
{
	//結果変数
	FourDirection result;

	//upとなす角
	float angle = MathSupport::GetVec2ToVec2Angle(vector, DIRECTION_UP);

	//下
	if (angle <= -135 || 135 <= angle)
		result.name = FourDirectionName::Down;
	//左
	else if (angle <= -45)
		result.name = FourDirectionName::Left;
	//上
	else if (angle <= 45)
		result.name = FourDirectionName::Up;
	//右
	else if (angle <= 135)
		result.name = FourDirectionName::Right;
	//例外
	else
		result.name = FourDirectionName::None;

	//結果を返す
	return result;
}