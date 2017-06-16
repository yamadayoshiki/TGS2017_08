/******************************************************************************
* File Name : gmouse.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �}�E�X����.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gmouse.h"
#include	"heap.h"
#pragma		warning(disable:4201) // �����\���̂̎g�p
#define		DIRECTINPUT_VERSION		0x0800
#include	<dinput.h>

/****** �f�[�^�^�錾 *********************************************************/

/*----- �}�E�X���͍\���� ----------------------------------------------------*/

typedef	struct
{
	HINSTANCE            hinst;		/* �C���X�^���X�n���h��         */
	HWND                 hwnd;		/* �E�B���h�E�n���h��           */
	LPDIRECTINPUT8       dinp;		/* DirectInput�n���h��          */
	LPDIRECTINPUTDEVICE8 idev;		/* �}�E�X�f�o�C�X �@�@          */
	int                  vx;		/* �}�E�X�̂������ړ���       �@*/
	int                  vy;		/* �}�E�X�̂������ړ���       �@*/
	int                  vz;		/* �}�E�X�̂������ړ���       �@*/
	int                  px;		/* �}�E�X�J�[�\�������W         */
	int                  py;		/* �}�E�X�J�[�\�������W         */
	int		             pz;		/* �}�E�X�J�[�\�������W         */
	GMOUSTATE            newbtn;	/* ���݂̃}�E�X�̃{�^���̏��   */
	GMOUSTATE            oldbtn;	/* �O��̃}�E�X�̃{�^���̏��   */

} GINPMOUSE;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	init_mouse_input( GINPMOUSE*, HINSTANCE, HWND );
static void	cleanup_mouse_input( GINPMOUSE* );
static void	read_mouse_input( GINPMOUSE* );
static BOOL	reacquire_mouse_input( GINPMOUSE* );
static BOOL	reacquire_input( LPDIRECTINPUTDEVICE8 );

/*=============================================================================
*
* Purpose : �}�E�X�̐����D
*
* Return  : �}�E�X�n���h����Ԃ��D
*
*============================================================================*/
GMOUSE
GMouseNew
(
	HINSTANCE		hinst,			/* �C���X�^���X�n���h��     */
	HWND			hwnd			/* �E�B���h�E�n���h��       */
)
{
	GINPMOUSE*		mouse;

	mouse = new_object( sizeof( GINPMOUSE ) );

	if ( init_mouse_input( mouse, hinst, hwnd ) == FALSE )
	{
		del_object( mouse );

		return	NULL;
	}

	return	(GMOUSE)mouse;
}

/*=============================================================================
*
* Purpose : �}�E�X�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMouseDelete
(
	GMOUSE			hnd				/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	cleanup_mouse_input( mouse );

	del_object( mouse );
}

/*=============================================================================
*
* Purpose : �}�E�X�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMouseReadDevice
(
	GMOUSE			hnd				/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;
	POINT			position;

	/* �}�E�X�̏�Ԃ̓ǂݍ��� */
	read_mouse_input( mouse );

	/* �E�B���h�E��̃}�E�X�J�[�\���̈ʒu���擾 */
	GetCursorPos(&position);
	ScreenToClient(mouse->hwnd, &position);
	mouse->px = position.x;
	mouse->py = position.y;
	mouse->pz += mouse->vz;
}

/*=============================================================================
*
* Purpose : �}�E�X�̈ړ��ʂ��擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMouseGetVelocity
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int*			x,				/*-> �������ړ���           */
	int*			y,				/*-> �������ړ���           */
	int*			z				/*-> �������ړ���           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( x != NULL )
	{
		*x = mouse->vx;
	}
	if ( y != NULL )
	{
		*y = mouse->vy;
	}
	if ( z != NULL )
	{
		*z = mouse->vz;
	}
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\���̈ʒu���擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMouseGetCursorPosition
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int*			x,				/*-> �����W                 */
	int*			y				/*-> �����W                 */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( x != NULL )
	{
		*x = (int)mouse->px;
	}
	if ( y != NULL )
	{
		*y = (int)mouse->py;
	}
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���̉�����Ԃ��擾�D
*
* Return  : ������Ă���ΐ^�C������Ă�����΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMouseGetButtonState
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( mouse->newbtn & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMouseGetButtonTrigger
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( ( ~mouse->oldbtn & mouse->newbtn ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �}�E�X�̃{�^���������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMouseGetButtonDetach
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	GMOUSTATE		state			/* ���ׂ����}�E�X�̃{�^��   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	if ( ( ( mouse->oldbtn & ~mouse->newbtn ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �}�E�X�J�[�\���̈ʒu��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMouseSetCursorPosition
(
	GMOUSE			hnd,			/* �}�E�X�n���h��           */
	int				x,				/* �����W                   */
	int				y				/* �����W                   */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;
	POINT			point;
	/* �}�E�X�J�[�\���̈ʒu�ݒ� */
	point.x = x;
	point.y = y;
	ClientToScreen(mouse->hwnd, &point);
	SetCursorPos(point.x, point.y);
	mouse->px = x;
	mouse->py = y;
}

/*=============================================================================
*
* Purpose : �}�E�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMouseReacquire
(
	GMOUSE				hnd			/* �}�E�X�n���h��           */
)
{
	GINPMOUSE*		mouse = (GINPMOUSE*)hnd;

	return	reacquire_mouse_input( mouse );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�o�C�X�̏������D
*
* Return  : �������ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
init_mouse_input
(
	GINPMOUSE*			mouse,		/* �}�E�X�n���h��           */
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	LPDIRECTINPUT8 			pdi;
	LPDIRECTINPUTDEVICE8	pdev;
	DIDEVICEINSTANCE		di;

	/* �}�E�X�f�o�C�X�̏����� */
	mouse->hwnd = hwnd;
	mouse->dinp = NULL;
	mouse->idev = NULL;

	/* DirectInput�̐��� */
	if( DirectInput8Create( hinst, DIRECTINPUT_VERSION, &IID_IDirectInput8, &pdi, NULL) != DI_OK )
	{
		OutputDebugString( "DirectInputCreate FAILED\n" );

		return FALSE;
	}

	/* DirectInput�}�E�X�f�o�C�X�̐��� */
	if( pdi->lpVtbl->CreateDevice( pdi, &GUID_SysMouse, &pdev, NULL) != DI_OK)
	{
		OutputDebugString( "CreateDevice FAILED\n" );

		return	FALSE;
	}

	/* �}�E�X�f�[�^�t�H�[�}�b�g�̐ݒ� */
	if( pdev->lpVtbl->SetDataFormat( pdev, &c_dfDIMouse ) != DI_OK )
	{
		OutputDebugString( "SetDataFormat FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* �������x���̐ݒ� */
	if( pdev->lpVtbl->SetCooperativeLevel( pdev, mouse->hwnd,
							 DISCL_NONEXCLUSIVE | DISCL_FOREGROUND ) != DI_OK )
	{
		OutputDebugString( "SetCooperativeLevel FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* ���ʏ��̎擾 */
	di.dwSize = sizeof( di );
	if ( pdev->lpVtbl->GetDeviceInfo( pdev, &di ) != DI_OK )
	{
		OutputDebugString( "GetDeviceInfo FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* �A�N�Z�X���̎擾���s�� */
	reacquire_input( pdev );

	/* DirectInput�n���h���̕ۑ� */
	mouse->dinp = pdi;
	mouse->idev = pdev;

	/* �}�E�X�̏�Ԃ̏����� */
	mouse->vx          = 0;
	mouse->vy          = 0;
	mouse->vz          = 0;
	mouse->px          = 0;
	mouse->py          = 0;
	mouse->pz          = 0;
	mouse->newbtn      = 0;
	mouse->oldbtn      = 0;

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�o�C�X�̏I�������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
cleanup_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	/* DirectInput�}�E�X�f�o�C�X�̏��� */
	if ( mouse->idev != NULL )
	{
		mouse->idev->lpVtbl->Unacquire( mouse->idev );
		mouse->idev->lpVtbl->Release( mouse->idev );
		mouse->idev = NULL;
	}

	/* DirectInput�n���h���̏��� */
	if ( mouse->dinp != NULL )
	{
		mouse->dinp->lpVtbl->Release( mouse->dinp );
		mouse->dinp = NULL;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�[�^�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
read_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	LPDIRECTINPUTDEVICE8	idev;
	DIMOUSESTATE			im;
	HRESULT					hres;

	if ( ( idev = mouse->idev ) == NULL )
	{
		return;
	}

	/* �O��̏�Ԃ�ۑ�   */
	mouse->oldbtn = mouse->newbtn;

	hres = idev->lpVtbl->GetDeviceState( idev, sizeof( im ), &im );
	if( hres == DI_OK )
	{
		/* �ړ��ʂ̎擾 */
		mouse->vx = im.lX;
		mouse->vy = im.lY;
		mouse->vz = im.lZ;

		/* �{�^���̏�Ԃ̎擾 */
		mouse->newbtn = 0;
		if ( ( im.rgbButtons[0] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_1;
		}
		if ( ( im.rgbButtons[1] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_2;
		}
		if ( ( im.rgbButtons[2] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_3;
		}
		if ( ( im.rgbButtons[3] & 0x80 ) != 0 )
		{
			mouse->newbtn |= GMOUSE_BUTTON_4;
		}
	}
	else
	{
		/* �ǂݎ��Ɏ��s�����ꍇ */
		mouse->vx     = 0;
		mouse->vy     = 0;
		mouse->vz     = 0;
		mouse->newbtn = 0;

		if ( ( hres == DIERR_INPUTLOST   )
		  || ( hres == DIERR_NOTACQUIRED ) )
		{
			reacquire_input( idev );
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�}�E�X�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_mouse_input
(
	GINPMOUSE*		mouse			/* �}�E�X�n���h��           */
)
{
	return	reacquire_input( mouse->idev );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_input
(
	LPDIRECTINPUTDEVICE8	idev	/* DirectInput�f�o�C�X      */
)
{
	HRESULT					hres;

	if( idev != NULL )
	{
		/* DirectInput�f�o�C�X�̃A�N�Z�X���̎擾 */
		hres = idev->lpVtbl->Acquire( idev );

		if( SUCCEEDED( hres ) )
		{
			/* �擾�ɐ������� */
			return	TRUE;
		}
		else
		{
			/* �擾�Ɏ��s���� */
			return	FALSE;
		}
	}

	/* �f�o�C�X�����݂��Ȃ� */
	return	FALSE;
}

/********** End of File ******************************************************/
