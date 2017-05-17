#include "TurnDirection.h"

//コンストラクタ
TurnDirection::TurnDirection(TurnDirectionName name)
	:name(name) {
}

//デフォルトコンストラクタ
TurnDirection::TurnDirection()
	: TurnDirection(TurnDirectionName::None) {
}

//反転
TurnDirection TurnDirection::Reversal() {
	name = GetReversal().name;
	return *this;
}

//反転
TurnDirection TurnDirection::GetReversal() {
	TurnDirection result;
	switch (name)
	{
	case TurnDirectionName::Clockwise:
		result.name = TurnDirectionName::AntiClockwise;
		break;
	case TurnDirectionName::AntiClockwise:
		result.name = TurnDirectionName::Clockwise;
		break;
	default:
		break;
	}
	return result;
}