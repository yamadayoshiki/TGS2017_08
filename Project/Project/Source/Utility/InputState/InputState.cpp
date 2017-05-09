#include"InputState.h"

//コンストラクタ
InputState::InputState()
	:mKeyVelocity(GSvector2(0.0f,0.0f))
	,mPadVelocity(GSvector2(0.0f,0.0f))
{

}
//デストラクタ
InputState::~InputState()
{
}
//キーが押されたら真
bool InputState::IsKeyTrigger(GKEYCODE key_code)
{
	return gsGetKeyTrigger(key_code);
}
//キーが押されていれば真
bool InputState::IsKeyState(GKEYCODE key_code)
{
	return gsGetKeyState(key_code);
	
}

//キーが離されたら真
bool InputState::IsKeyStateDetach(GKEYCODE key_code)
{
	return gsGetKeyDetach(key_code);
}

//KeyVelocityのゲッター
GSvector2 InputState::KeyVelocity()
{
	return mKeyVelocity;
}

//KeyVelocityの更新
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

//ボタンが押されたら真
bool InputState::IsPadStateTrigger(GSushort Button)
{
	return gsXBoxPadButtonTrigger(0,Button);
}

//ボタンが押されていれば真
bool InputState::IsPadState(GSushort Button)
{
	return gsXBoxPadButtonState(0,Button);
}

//ボタンが離されたら真
bool InputState::IsPadStatesDetach(GSushort Button)
{
	return gsXBoxPadButtonDetach(0,Button);
}

//PadVelocityのゲッター
GSvector2 InputState::PadVelocity()
{
	return mPadVelocity;
}

//PadVelocityの更新(アナログスティック)
void InputState::UpdatePadVelocity()
{
	mPadVelocity = GSvector2(0.0f, 0.0f);

	gsXBoxPadGetLeftAxis(0, &mPadVelocity);

	mPadVelocity.y = -mPadVelocity.y;

	mPadVelocity.normalize();
}

//PadVelpcityの更新(十字キー)
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