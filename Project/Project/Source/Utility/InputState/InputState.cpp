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
bool InputState::IsPadStateTrigger(GSushort Button)
{
	return gsXBoxPadButtonTrigger(0,Button);
}

//�{�^����������Ă���ΐ^
bool InputState::IsPadState(GSushort Button)
{
	return gsXBoxPadButtonState(0,Button);
}

//�{�^���������ꂽ��^
bool InputState::IsPadStatesDetach(GSushort Button)
{
	return gsXBoxPadButtonDetach(0,Button);
}

//PadVelocity�̃Q�b�^�[
GSvector2 InputState::PadVelocity()
{
	return mPadVelocity;
}

//PadVelocity�̍X�V(�A�i���O�X�e�B�b�N)
void InputState::UpdatePadVelocity()
{
	mPadVelocity = GSvector2(0.0f, 0.0f);

	gsXBoxPadGetLeftAxis(0, &mPadVelocity);

	mPadVelocity.y = -mPadVelocity.y;

	mPadVelocity.normalize();
}

//PadVelpcity�̍X�V(�\���L�[)
void InputState::UpdatePadVelocity_Button()
{
	mPadVelocity = GSvector2(0.0f, 0.0f);

	if (gsXBoxPadButtonState(0,GS_XBOX_PAD_UP)) {
		mPadVelocity.y = -1.0f;
	}
	else if (gsXBoxPadButtonState(0,GS_XBOX_PAD_DOWN)) {
		mPadVelocity.y = 1.0f;
	}
	else if (gsXBoxPadButtonState(0, GS_XBOX_PAD_LEFT)) {
		mPadVelocity.x = -1.0f;
	}
	else if (gsXBoxPadButtonState(0, GS_XBOX_PAD_RIGHT)) {
		mPadVelocity.x = 1.0f;
	}
	mPadVelocity.normalize();
}


void InputState::Update()
{
	UpdateKeyVelocity();
	//UpdatePadVelocity();
	UpdatePadVelocity_Button();
}