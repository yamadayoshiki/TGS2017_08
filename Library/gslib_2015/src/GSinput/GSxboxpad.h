/******************************************************************************
* File Name : GSxboxpad.h                        Ver : 1.00  Date : 2016-04-16
*
* Description :
*
*       XBOX�p�b�h���� �w�b�_�t�@�C��.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_XBOX_PAD_H_
#define GS_XBOX_PAD_H_

#include	<GStype.h>
#include	<Xinput.h>

#ifdef __cplusplus
extern "C" {
#endif

/****** �f�[�^�^�錾 *********************************************************/

extern const GSushort GS_XBOX_PAD_UP;
extern const GSushort GS_XBOX_PAD_DOWN;
extern const GSushort GS_XBOX_PAD_LEFT;
extern const GSushort GS_XBOX_PAD_RIGHT;
extern const GSushort GS_XBOX_PAD_START;
extern const GSushort GS_XBOX_PAD_BACK;
extern const GSushort GS_XBOX_PAD_LEFT_THUMB;
extern const GSushort GS_XBOX_PAD_RIGHT_THUMB;
extern const GSushort GS_XBOX_PAD_LEFT_SHOULDER;
extern const GSushort GS_XBOX_PAD_RIGHT_SHOULDER;
extern const GSushort GS_XBOX_PAD_A;
extern const GSushort GS_XBOX_PAD_B;
extern const GSushort GS_XBOX_PAD_X;
extern const GSushort GS_XBOX_PAD_Y;

/*----- XBOX PAD�f�o�C�X�\���� ----------------------------------------------*/

#define   GS_XBOX_PAD_MAX 4

typedef	struct
{
	int                 num_pad;					/* �p�b�h��				*/
	XINPUT_STATE        state[2][GS_XBOX_PAD_MAX];	/* ���̓o�b�t�@			*/
	XINPUT_STATE*       newbuf;						/* ���݂̓��̓o�b�t�@   */
	XINPUT_STATE*       oldbuf;						/* �O��̓��̓o�b�t�@   */

} GSxboxpad;

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
);

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
);

/*=============================================================================
*
* Purpose : XBOX�p�b�h�̏�Ԃ�ǂݍ��ށD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
XBoxPadRead
(
	GSxboxpad*			pad		/* XBOX�p�b�h         �@�@�@�@      */
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);


#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
