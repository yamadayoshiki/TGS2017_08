#include "TurnDirection.h"

//�R���X�g���N�^
TurnDirection::TurnDirection(TurnDirectionName name)
	:name(name) {
}

//�f�t�H���g�R���X�g���N�^
TurnDirection::TurnDirection()
	: TurnDirection(TurnDirectionName::None) {
}

//���]
TurnDirection TurnDirection::Reversal() {
	name = GetReversal().name;
	return *this;
}

//���]
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