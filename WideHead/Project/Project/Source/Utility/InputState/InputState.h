#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include<gslib.h>

class InputState
{
public:
	//コンストラクタ
	InputState();
	//デストラクタ
	~InputState();
	//キーが押されたら真
	bool IsKeyTrigger(GKEYCODE key_code);
	//キーが押されていれば真
	bool IsKeyState(GKEYCODE key_code);
	//キーが離されたら真
	bool IsKeyStateDetach(GKEYCODE key_code);
	//KeyVelocityのゲッター
	GSvector2 KeyVelocity();

	//ボタンが押されたら真
	bool IsPadStateTrigger(GSushort Button);
	//ボタンが押されていれば真
	bool IsPadState(GSushort Button);
	//ボタンが離されたら真
	bool IsPadStatesDetach(GSushort Button);
	//PadVelocityのゲッター
	GSvector2 PadVelocity();

	void Update();

private:
	//KeyVelocityの更新
	void UpdateKeyVelocity();
	//PadVelocityの更新(アナログスティック)
	void UpdatePadVelocity();
	//PadVelpcityの更新(十字キー)
	void UpdatePadVelocity_Button();

private:
	//KeyVelocity
	GSvector2		mKeyVelocity;
	//PadVelocity
	GSvector2		mPadVelocity;

};
#endif // !INPUTSTATE_H_

