#ifndef INPUTSTATE_H_
#define INPUTSTATE_H_

#include<gslib.h>

class InputState
{
public:
	//�R���X�g���N�^
	InputState();
	//�f�X�g���N�^
	~InputState();
	//�L�[�������ꂽ��^
	bool IsKeyTrigger(GKEYCODE key_code);
	//�L�[��������Ă���ΐ^
	bool IsKeyState(GKEYCODE key_code);
	//�L�[�������ꂽ��^
	bool IsKeyStateDetach(GKEYCODE key_code);
	//KeyVelocity�̃Q�b�^�[
	GSvector2 KeyVelocity();

	//�{�^���������ꂽ��^
	bool IsPadStateTrigger(GSushort Button);
	//�{�^����������Ă���ΐ^
	bool IsPadState(GSushort Button);
	//�{�^���������ꂽ��^
	bool IsPadStatesDetach(GSushort Button);
	//PadVelocity�̃Q�b�^�[
	GSvector2 PadVelocity();

	void Update();

private:
	//KeyVelocity�̍X�V
	void UpdateKeyVelocity();
	//PadVelocity�̍X�V(�A�i���O�X�e�B�b�N)
	void UpdatePadVelocity();
	//PadVelpcity�̍X�V(�\���L�[)
	void UpdatePadVelocity_Button();

private:
	//KeyVelocity
	GSvector2		mKeyVelocity;
	//PadVelocity
	GSvector2		mPadVelocity;

};
#endif // !INPUTSTATE_H_

