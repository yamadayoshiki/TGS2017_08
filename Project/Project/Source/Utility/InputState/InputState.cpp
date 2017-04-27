#include"InputState.h"

//�R���X�g���N�^
InputState::InputState()
	:mKeyVelocity(GSvector2(0.0f,0.0f))
	,mPadVelocity(GSvector2(0.0f,0.0f))
{

}
//�f�X�g���N�^
InputState::~InputState()
{
}
//�L�[�������ꂽ��^
bool InputState::IsKeyTrigger(GKEYCODE key_code)
{
	return gsGetKeyTrigger(key_code);
}
//�L�[��������Ă���ΐ^
bool InputState::IsKeyState(GKEYCODE key_code)
{
	return gsGetKeyState(key_code);
	
}

//�L�[�������ꂽ��^
bool InputState::IsKeyStateDetach(GKEYCODE key_code)
{
	return gsGetKeyDetach(key_code);
}

//KeyVelocity�̃Q�b�^�[
GSvector2 InputState::KeyVelocity()
{
	return mKeyVelocity;
}

//KeyVelocity�̍X�V
void InputState::UpdateKeyVelocity()
{
	mKeyVelocity = GSvector2(0.0f, 0.0f);

	if (gsGetKeyState(GKEY_RIGHT)) {
		mKeyVelocity.x = 1.0f;
	}
	else if (gsGetKeyState(GKEY_LEFT)) {
		mKeyVelocity.x = -1.0f;
	}
	else if (gsGetKeyState(GKEY_UP)){
		mKeyVelocity.y = -1.0f;
}
	else if (gsGetKeyState(GKEY_DOWN)) {
		mKeyVelocity.x = 1.0f;
	}
	if (mKeyVelocity.length() != 0.0f) {
		mKeyVelocity.getNormalized();
	}
}

//�{�^���������ꂽ��^
bool InputState::IsPadTrigger(GSushort Button)
{
	return gsXBoxPadButtonTrigger(0,Button);
}

//�{�^����������Ă���ΐ^
bool InputState::IsPadState(GSushort Button)
{
	return gsXBoxPadButtonState(0,Button);
}

//�{�^���������ꂽ��^
bool InputState::IsPadStatemStatesDetach(GSushort Button)
{
	return gsXBoxPadButtonDetach(0,Button);
}

//PadVelocity�̃Q�b�^�[
GSvector2 InputState::PadVelocity()
{
	return mPadVelocity;
}

//PadVelocity�̍X�V
void InputState::UpdatePadVelocity()
{
	gsXBoxPadGetLeftAxis(0, &mPadVelocity);

	mPadVelocity.y = -mPadVelocity.y;

	mPadVelocity.normalize();
}

void InputState::Update()
{
	UpdateKeyVelocity();
	UpdatePadVelocity();
}