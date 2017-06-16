/******************************************************************************
* File Name : gsinput.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       ���̓f�o�C�X�V�X�e���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gsinput.h"
#include	"GSxboxpad.h"

/****** �ϐ��錾 *************************************************************/

static GINPUT	GInput = NULL;			/* ���̓f�o�C�X�n���h��        */

static GSxboxpad* s_xbox_pad = NULL;	/* XBOX�R���g���[���[			*/

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�V�X�e���̏������D
*
* Return  : �������ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsInitInput
(
	HWND			hwnd			/* �E�B���h�E�n���h��           */
)
{

	/* ���̓f�o�C�X�n���h���̐��� */
	if ( GInput == NULL )
	{
		HINSTANCE		hinst;
			
		hinst = GetModuleHandle( NULL );
		if ( ( GInput = GInputNew( hinst, hwnd ) ) == NULL )
		{
			return	FALSE;
		}
	}
	/* X�{�b�N�X�R���g���[���̐��� */
	if (s_xbox_pad == NULL) {
		s_xbox_pad = XBoxPadNew();
	}
	return	TRUE;
}

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�V�X�e���̏I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsFinishInput
(
	void
)
{
	/* ���̓f�o�C�X�n���h���̏��� */
	if ( GInput != NULL )
	{
		GInputDelete( GInput );
	}
	GInput = NULL;

	/* X�{�b�N�X�R���g���[���̏��� */
	if (s_xbox_pad != NULL) {
		XBoxPadDelete(s_xbox_pad);
	}
	s_xbox_pad = NULL;
}

/*=============================================================================
*
* Purpose : �E�B���h�E���A�N�e�B�u�ɂȂ������̏����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsActivateInput
(
	BOOL		active				/* �A�N�e�B�u�t���O             */
)
{
	if ( GInput == NULL )
	{
		return;
	}

	GInputActivateApp( GInput, active );
}

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�̏�Ԃ�ǂݍ��ށD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsReadInput
(
	void
)
{
	GInputReadDevice( GInput );

	XBoxPadRead(s_xbox_pad);
}

/*=============================================================================
*
* Purpose : �L�[�̓��͏�Ԃ𒲂ׂ�D
*
* Return  : �L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsGetKeyState
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetState( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�������ꂽ�����ׂ�D
*
* Return  : �L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsGetKeyTrigger
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetTrigger( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�������ꂽ�����ׂ�D
*
* Return  : �L�[���������ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsGetKeyDetach
(
	GKEYCODE		key_code		/* �L�[�R�[�h                   */
)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	FALSE;
	}

	return	GKeyInpGetDetach( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h�̉�����Ă���L�[�𒲂ׂ�D
*
* Return  : ������Ă���L�[�̃L�[�R�[�h��Ԃ��D
*           ����������Ă��Ȃ���΂O��Ԃ��D
*
*============================================================================*/
GKEYCODE
gsGetKey
(
	void
)
{
	GKEYINP			key;

	if ( ( key = GInputGetKeyborad( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GKeyInpGetKey( key );
}

/*=============================================================================
*
* Purpose : �ڑ�����Ă���W���C�X�e�B�b�N���𒲂ׂ�D
*
* Return  : �ڑ�����Ă���W���C�X�e�B�b�N����Ԃ��D
*
*============================================================================*/
int
gsGetJoyCount
(
	void
)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetCount( joy );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̓��͏�Ԃ𒲂ׂ�D
*
* Return  : �W���C�X�e�B�b�N�̓��͏�Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetJoyState
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetState( joy, joy_no, state );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�������ꂽ�����ׂ�D
*
* Return  : �W���C�X�e�B�b�N�̉����ꂽ��Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetJoyTrigger
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetTrigger( joy, joy_no, state );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�������ꂽ�����ׂ�D
*
* Return  : �W���C�X�e�B�b�N�̗����ꂽ��Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetJoyDetach
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o       */
	GJOYSTATE		state			/* ���ׂ����W���C�X�e�b�N�̏�� */
)
{
	GJOYINP			joy;

	if ( ( joy = GInputGetJoystick( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GJoyInpGetDetach( joy, joy_no, state );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̎��̏�Ԃ𒲂ׂ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsGetJoyAxis
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o			  */
	int*			x,				/*-> ���W���C�X�e�b�B�N�̂����̏��   */
	int*			y,				/*-> ���W���C�X�e�b�B�N�̂����̏��   */
	int*			z				/*-> ���W���C�X�e�b�B�N�̂����̏��   */
)
{
	GJOYINP			joy;
	int				tlx = 0;
	int				tly = 0;
	int				trx = 0;
	int				try = 0;

	if ( ( joy = GInputGetJoystick( GInput ) ) != NULL )
	{
		/* �W���C�X�e�b�N�̎��̏�Ԃ�ǂݍ��� */
		GJoyInpGetAxis(joy, joy_no, &tlx, &tly, &trx, &try);
	}

	if (x != NULL)
	{
		*x = tlx;
	}
	if (y != NULL)
	{
		*y = tly;
	}
	if (z != NULL)
	{
		*z = trx;
	}
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̍����̏�Ԃ𒲂ׂ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsGetJoyLeftAxis
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o			  */
	int*			x,				/*-> �W���C�X�e�b�B�N�̍������̏��   */
	int*			y				/*-> �W���C�X�e�b�B�N�̍������̏��   */
)
{
	GJOYINP			joy;
	int				tlx = 0;
	int				tly = 0;
	int				trx = 0;
	int				try = 0;

	if ((joy = GInputGetJoystick(GInput)) != NULL)
	{
		/* �W���C�X�e�b�N�̎��̏�Ԃ�ǂݍ��� */
		GJoyInpGetAxis(joy, joy_no, &tlx, &tly, &trx, &try);
	}

	if (x != NULL)
	{
		*x = tlx;
	}
	if (y != NULL)
	{
		*y = tly;
	}
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̉E���̏�Ԃ𒲂ׂ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsGetJoyRightAxis
(
	int				joy_no,			/* �W���C�X�e�B�b�N�i���o			  */
	int*			x,				/*-> �E�W���C�X�e�b�B�N�̂����̏��   */
	int*			y				/*-> �E�W���C�X�e�b�B�N�̂����̏��   */
)
{
	GJOYINP			joy;
	int				tlx = 0;
	int				tly = 0;
	int				trx = 0;
	int				try = 0;

	if ((joy = GInputGetJoystick(GInput)) != NULL)
	{
		/* �W���C�X�e�b�N�̎��̏�Ԃ�ǂݍ��� */
		GJoyInpGetAxis(joy, joy_no, &tlx, &tly, &trx, &try);
	}

	if (x != NULL)
	{
		*x = trx;
	}
	if (y != NULL)
	{
		*y = try;
	}
}

/*=============================================================================
*
* Purpose : �}�E�X�̈ړ��ʂ��擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsGetMouseVelocity
(
	int*			x,				/*-> �������ړ���               */
	int*			y,				/*-> �������ړ���               */
	int*			z				/*-> �������ړ���               */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		*x = 0;
		*y = 0;
		*z = 0;

		return;
	}

	GMouseGetVelocity(mou, x, y, z);
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\���̈ʒu���擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsGetMouseCursorPosition
(
	int*			x,				/*-> �����W                     */
	int*			y				/*-> �����W                     */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		*x = 0;
		*y = 0;

		return;
	}

	GMouseGetCursorPosition( mou, x, y );
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���̉�����Ԃ��擾�D
*
* Return  : �}�E�X�̃{�^���̉�����Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetMouseButtonState
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonState( mou, state );
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���������ꂽ�����ׂ�D
*
* Return  : �}�E�X�̃{�^���̉����ꂽ��Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetMouseButtonTrigger
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonTrigger( mou, state );
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���������ꂽ�����ׂ�D
*
* Return  : �}�E�X�̃{�^���̗����ꂽ��Ԃ�Ԃ��D
*
*============================================================================*/
BOOL
gsGetMouseButtonDetach
(
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��       */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return	0;
	}

	return	GMouseGetButtonDetach( mou, state );
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\���̈ʒu��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsSetMouseCursorPosition
(
	int				x,				/* �����W                       */
	int				y				/* �����W                       */
)
{
	GMOUSE			mou;

	if ( ( mou = GInputGetMouse( GInput ) ) == NULL )
	{
		return;
	}

	GMouseSetCursorPosition( mou, x, y );
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\����\���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsShowMouseCursor
(
	void
)
{
	// �}�E�X�J�[�\���̔�\��
	ShowCursor(FALSE);
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\�����\���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsHideMouseCursor
(
	void
)
{
	// �}�E�X�J�[�\���̔�\��
	ShowCursor(FALSE);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̃{�^����������Ă��邩���ׂ�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsXBoxPadButtonState
(
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	return XBoxPadButtonState(s_xbox_pad, pad_no, button);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̃{�^���������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsXBoxPadButtonTrigger
(
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	return XBoxPadButtonTrigger(s_xbox_pad, pad_no, button);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̃{�^�����������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsXBoxPadButtonDetach
(
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSushort			button		/* ���ׂ����{�^����			�@      */
)
{
	return XBoxPadButtonDetach(s_xbox_pad, pad_no, button);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̍��g���K�̒l���擾�D
*
* Return  : ���g���K�̒l��Ԃ��D(0.0f �` 1.0f)
*
*============================================================================*/
extern GSfloat
gsXBoxPadGetLeftTrigger
(
	GSuint				pad_no		/* �p�b�h�i���o                     */
)
{
	return XBoxPadGetLeftTrigger(s_xbox_pad, pad_no);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̉E�g���K�̒l���擾�D
*
* Return  : �E�g���K�̒l��Ԃ��D(0.0f �` 1.0f���K�������l)
*
*============================================================================*/
extern GSfloat
gsXBoxPadGetRightTrigger
(
	GSuint				pad_no		/* �p�b�h�i���o                     */
)
{
	return XBoxPadGetRightTrigger(s_xbox_pad, pad_no);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̍��A�i���O�X�e�B�b�N�̏�Ԃ��擾�D
*
* Return  : ���A�i���O�X�e�B�b�N�̏�Ԃ�Ԃ��D(-1.0f �` 1.0f�ɐ��K�������l)
*
*============================================================================*/
extern void
gsXBoxPadGetLeftAxis
(
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSvector2*			result		/* �A�i���O�X�e�B�b�N�̏��			*/
)
{
	XBoxPadGetLeftAxis(s_xbox_pad, pad_no, result);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̉E�A�i���O�X�e�B�b�N�̏�Ԃ��擾�D
*
* Return  : �E�A�i���O�X�e�B�b�N�̏�Ԃ�Ԃ��D(-1.0f �` 1.0f�ɐ��K�������l)
*
*============================================================================*/
extern void
gsXBoxPadGetRightAxis
(
	GSuint				pad_no,		/* �p�b�h�i���o                     */
	GSvector2*			result		/* �A�i���O�X�e�B�b�N�̏��			*/
)
{
	XBoxPadGetRightAxis(s_xbox_pad, pad_no, result);
}

/*=============================================================================
*
* Purpose : XBOX�R���g���[���̐ڑ����𒲂ׂ�D
*
* Return  : �ڑ�����Ă���XBOX�R���g���[������Ԃ��D
*
*============================================================================*/
extern GSuint
gsXBoxGetPadCount
(
	void
)
{
	return XBoxGetPadCount(s_xbox_pad);
}

/********** End of File ******************************************************/
