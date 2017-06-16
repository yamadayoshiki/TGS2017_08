/******************************************************************************
* File Name : GSxboxpad.c                        Ver : 1.00  Date : 2016-04-16
*
* Description :
*
*       XBOX�p�b�h����.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSxboxpad.h"
#include	"heap.h"
#include	<GStype.h>
#include	<Xinput.h>

/*----- XInput��lib�t�@�C�� -------------------------------------------------*/

#pragma comment(lib, "Xinput9_1_0.lib")

/****** �f�[�^�^�錾 *********************************************************/

extern const GSushort GS_XBOX_PAD_UP = XINPUT_GAMEPAD_DPAD_UP;
extern const GSushort GS_XBOX_PAD_DOWN = XINPUT_GAMEPAD_DPAD_DOWN;
extern const GSushort GS_XBOX_PAD_LEFT = XINPUT_GAMEPAD_DPAD_LEFT;
extern const GSushort GS_XBOX_PAD_RIGHT = XINPUT_GAMEPAD_DPAD_RIGHT;
extern const GSushort GS_XBOX_PAD_START = XINPUT_GAMEPAD_START;
extern const GSushort GS_XBOX_PAD_BACK = XINPUT_GAMEPAD_BACK;
extern const GSushort GS_XBOX_PAD_LEFT_THUMB = XINPUT_GAMEPAD_LEFT_THUMB;
extern const GSushort GS_XBOX_PAD_RIGHT_THUMB = XINPUT_GAMEPAD_RIGHT_THUMB;
extern const GSushort GS_XBOX_PAD_LEFT_SHOULDER = XINPUT_GAMEPAD_LEFT_SHOULDER;
extern const GSushort GS_XBOX_PAD_RIGHT_SHOULDER = XINPUT_GAMEPAD_RIGHT_SHOULDER;
extern const GSushort GS_XBOX_PAD_A = XINPUT_GAMEPAD_A;
extern const GSushort GS_XBOX_PAD_B = XINPUT_GAMEPAD_B;
extern const GSushort GS_XBOX_PAD_X = XINPUT_GAMEPAD_X;
extern const GSushort GS_XBOX_PAD_Y = XINPUT_GAMEPAD_Y;

/*=============================================================================
*
* Purpose : XBOX�p�b�h�̐����D
*
* Return  : XBOX��Ԃ��D
*
*============================================================================*/
extern GSxboxpad*
XBoxPadNew
(
	void
)
{
	GSxboxpad*	pad;
	pad = new_object(sizeof(GSxboxpad));
	memset(pad, 0, sizeof(GSxboxpad));
	pad->newbuf = pad->state[0];
	pad->oldbuf = pad->state[1];
	return pad;
}

/*=============================================================================
*
* Purpose : XBOX�p�b�h�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
XBoxPadDelete
(
	GSxboxpad*			pad		/* XBOX�p�b�h         �@�@�@�@      */
)
{
	del_object(pad);
}

/*=============================================================================
*
* Purpose : XBOX�p�b�h�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
XBoxPadRead
(
	GSxboxpad*			pad		/* XBOX�p�b�h         �@�@�@�@      */
)
{
	XINPUT_STATE*	tmp;
	int				i;

	/* ���݂̃o�b�t�@�ƌÂ��o�b�t�@����ꊷ���� */
	tmp = pad->newbuf;
	pad->newbuf = pad->oldbuf;
	pad->oldbuf = tmp;

	/* �S�Ẵp�b�h�̏�Ԃ�ǂݍ��� */
	pad->num_pad = 0;
	for (i = 0; i < GS_XBOX_PAD_MAX; ++i)
	{
		DWORD result;
		ZeroMemory(&pad->newbuf[i], sizeof(XINPUT_STATE)); // ������
		result = XInputGetState(i, &pad->newbuf[i]);
		if (result == ERROR_SUCCESS)
		{
			pad->num_pad++;
		}
	}
}

/*=============================================================================
*
* Purpose : �{�^����������Ă������ׂ�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
XBoxPadButtonState
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return GS_FALSE;
	}
	if ((pad->newbuf[pad_no].Gamepad.wButtons & button) != 0) {
		return GS_TRUE;
	}
	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �{�^���������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
XBoxPadButtonTrigger
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return GS_FALSE;
	}
	if (((~pad->oldbuf[pad_no].Gamepad.wButtons & pad->newbuf[pad_no].Gamepad.wButtons) & button) != 0)
	{
		return GS_TRUE;
	}
	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �{�^�����������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
XBoxPadButtonDetach
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return GS_FALSE;
	}
	if (((pad->oldbuf[pad_no].Gamepad.wButtons & ~pad->newbuf[pad_no].Gamepad.wButtons) & button) != 0)
	{
		return GS_TRUE;
	}
	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : ���g���K�̒l���擾�D
*
* Return  : ���g���K�̒l��Ԃ��D(0.0f �` 1.0f)
*
*============================================================================*/
extern GSfloat
XBoxPadGetLeftTrigger
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no		/* �p�b�h�i���o                     */
)
{
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return 0.0f;
	}
	return (float)pad->newbuf[pad_no].Gamepad.bLeftTrigger / 255.0f;
}

/*=============================================================================
*
* Purpose : �E�g���K�̒l���擾�D
*
* Return  : �E�g���K�̒l��Ԃ��D(0.0f �` 1.0f���K�������l)
*
*============================================================================*/
extern GSfloat
XBoxPadGetRightTrigger
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no		/* �p�b�h�i���o                     */
)
{
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return 0.0f;
	}
	return (GSfloat)pad->newbuf[pad_no].Gamepad.bRightTrigger / 255.0f;
}

/*=============================================================================
*
* Purpose : ���A�i���O�X�e�B�b�N�̏�Ԃ��擾�D
*
* Return  : ���A�i���O�X�e�B�b�N�̏�Ԃ�Ԃ��D(-1.0f �` 1.0f�ɐ��K�������l)
*
*============================================================================*/
extern void
XBoxPadGetLeftAxis
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSvector2*			result		/* �A�i���O�X�e�B�b�N�̏��         */
)
{
	result->x = 0.0f;
	result->y = 0.0f;
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return;
	}
	SHORT lx = pad->newbuf[pad_no].Gamepad.sThumbLX;
	SHORT ly = pad->newbuf[pad_no].Gamepad.sThumbLY;
	lx = (abs(lx) <= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ? 0 : lx;
	ly = (abs(ly) <= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) ? 0 : ly;
	result->x = (GSfloat)lx / 32767.0f;
	result->y = (GSfloat)ly / 32767.0f;
}

/*=============================================================================
*
* Purpose : �E�A�i���O�X�e�B�b�N�̏�Ԃ��擾�D
*
* Return  : �E�A�i���O�X�e�B�b�N�̏�Ԃ�Ԃ��D(-1.0f �` 1.0f�ɐ��K�������l)
*
*============================================================================*/
extern void
XBoxPadGetRightAxis
(
	GSxboxpad*			pad,		/* XBOX�p�b�h         �@�@�@�@      */
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSvector2*			result		/* �A�i���O�X�e�B�b�N�̏��         */
)
{
	result->x = 0.0f;
	result->y = 0.0f;
	if (pad_no >= GS_XBOX_PAD_MAX)
	{
		return;
	}
	SHORT rx = pad->newbuf[pad_no].Gamepad.sThumbRX;
	SHORT ry = pad->newbuf[pad_no].Gamepad.sThumbRY;
	rx = (abs(rx) <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) ? 0 : rx;
	ry = (abs(ry) <= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE) ? 0 : ry;
	result->x = (GSfloat)rx / 32767.0f;
	result->y = (GSfloat)ry / 32767.0f;
}

/*=============================================================================
*
* Purpose : �ڑ�����Ă���W���C�X�e�B�b�N���𒲂ׂ�D
*
* Return  : �ڑ�����Ă���W���C�X�e�B�b�N����Ԃ��D
*
*============================================================================*/
extern GSuint
XBoxGetPadCount
(
	GSxboxpad*			pad			/* XBOX�p�b�h         �@�@�@�@      */
)
{
	return pad->num_pad;
}

/********** End of File ******************************************************/
