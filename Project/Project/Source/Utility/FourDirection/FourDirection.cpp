#include "FourDirection.h"
#include "../../Define/Def_GSvector2.h"
#include "../../Utility/MathSupport/MathSupport.h"

//�R���X�g���N�^
FourDirection::FourDirection(const FourDirectionName directionName)
	:name(directionName) {

}

//�R���X�g���N�^
FourDirection::FourDirection(const GSvector2& vector)
	: FourDirection(GetVector2ToFourDirection(vector)) {
}

//�R���X�g���N�^
FourDirection::FourDirection(const float angle)
	: FourDirection(MathSupport::GetAngleToVector2(angle)) {
}

//�f�t�H���g�R���X�g���N�^
FourDirection::FourDirection()
	: FourDirection(FourDirectionName::None) {
}

//�w������ɉ�](90�x)
FourDirection FourDirection::Turn(TurnDirection turnDirection) {
	name = GetTurn(turnDirection).name;
	return *this;
}

//�w������ɉ�](90�x)
FourDirection FourDirection::GetTurn(TurnDirection turnDirection) const {
	//���ʕϐ�
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

//���]
FourDirection FourDirection::TurnOver() {
	name = GetTurnOver().name;
	return *this;
}

//���]
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

//GSvector2�ɒu������
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

//�p�x�ɒu������
float FourDirection::GetAngle() const {
	float result;
	result = MathSupport::GetVec2ToVec2Angle(GetVector2(), DIRECTION_RIGHT);
	return result;
}

//Gsvector2��FourDirectionName�ɕϊ�
FourDirection FourDirection::GetVector2ToFourDirection(const GSvector2& vector)
{
	//���ʕϐ�
	FourDirection result;

	//up�ƂȂ��p
	float angle = MathSupport::GetVec2ToVec2Angle(vector, DIRECTION_UP);

	//��
	if (angle <= -135 || 135 <= angle)
		result.name = FourDirectionName::Down;
	//��
	else if (angle <= -45)
		result.name = FourDirectionName::Left;
	//��
	else if (angle <= 45)
		result.name = FourDirectionName::Up;
	//�E
	else if (angle <= 135)
		result.name = FourDirectionName::Right;
	//��O
	else
		result.name = FourDirectionName::None;

	//���ʂ�Ԃ�
	return result;
}