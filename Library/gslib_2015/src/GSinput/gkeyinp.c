/******************************************************************************
* File Name : gkeyinp.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �L�[�{�[�h����.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gkeyinp.h"
#include	"heap.h"
#define		DIRECTINPUT_VERSION		0x0800
#pragma		warning(disable:4201) // �����\���̂̎g�p
#include	<dinput.h>

/****** �f�[�^�^�錾 *********************************************************/

/*----- �L�[�{�[�h���̓f�o�C�X�\���� ----------------------------------------*/

typedef	struct
{
	HINSTANCE            hinst;				/* �C���X�^���X�n���h��     */
	HWND                 hwnd;				/* �E�B���h�E�n���h��       */
	LPDIRECTINPUT8       dinp;				/* DirectInput�n���h��      */
	LPDIRECTINPUTDEVICE8 idev;				/* �L�[�{�[�h�f�o�C�X       */
	BYTE                 buffer[2][256];	/* �L�[�{�[�h�o�b�t�@       */
	BYTE*                newbuf;			/* ���݂̃L�[�{�[�h�o�b�t�@ */
	BYTE*                oldbuf;			/* �O��̃L�[�{�[�h�o�b�t�@ */

} GINPKEYBOARD;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	init_keyboard_input( GINPKEYBOARD*, HINSTANCE, HWND );
static void	cleanup_keyboard_input( GINPKEYBOARD* );
static void	read_keyboard_input( GINPKEYBOARD* );
static BOOL	get_keyboard_state( GINPKEYBOARD*, GKEYCODE );
static BOOL	get_keyboard_trigger( GINPKEYBOARD*, GKEYCODE );
static BOOL	get_keyboard_detach( GINPKEYBOARD*, GKEYCODE );
static GKEYCODE get_keyboard_key( GINPKEYBOARD* );
static BOOL	reacquire_keyboard_input( GINPKEYBOARD* );
static BOOL	reacquire_input( LPDIRECTINPUTDEVICE8 );

/*=============================================================================
*
* Purpose : �L�[�{�[�h�̐����D
*
* Return  : �L�[�{�[�h�n���h����Ԃ��D
*
*============================================================================*/
GKEYINP
GKeyInpNew
(
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	GINPKEYBOARD*		key;

	key = new_object( sizeof( GINPKEYBOARD ) );

	if ( init_keyboard_input( key, hinst, hwnd ) == FALSE )
	{
		del_object( key );

		return	NULL;
	}

	return	(GKEYINP)key;
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GKeyInpDelete
(
	GKEYINP				hnd			/* �L�[�{�[�h�n���h��       */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	cleanup_keyboard_input( key );

	del_object( key );
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GKeyInpReadDevice
(
	GKEYINP				hnd			/* �L�[�{�[�h�n���h��       */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	read_keyboard_input( key );
}

/*=============================================================================
*
* Purpose : �L�[�̓��͏�Ԃ𒲂ׂ�D
*
* Return  : �L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GKeyInpGetState
(
	GKEYINP				hnd,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	return	get_keyboard_state( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�������ꂽ�����ׂ�D
*
* Return  : �L�[��������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D�D
*
*============================================================================*/
BOOL
GKeyInpGetTrigger
(
	GKEYINP				hnd,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	return	get_keyboard_trigger( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�������ꂽ�����ׂ�D
*
* Return  : �L�[���������ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GKeyInpGetDetach
(
	GKEYINP				hnd,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	return	get_keyboard_detach( key, key_code );
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h���牟����Ă���L�[�𒲂ׂ�D
*
* Return  : ������Ă���L�[�̃L�[�R�[�h��Ԃ��D
*           ����������Ă��Ȃ���΂O��Ԃ��D
*
*============================================================================*/
GKEYCODE
GKeyInpGetKey
(
	GKEYINP				hnd			/* �L�[�{�[�h�n���h��       */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	return	get_keyboard_key( key );
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GKeyInpReacquire
(
	GKEYINP				hnd			/* �L�[�{�[�h�n���h��       */
)
{
	GINPKEYBOARD*		key = (GINPKEYBOARD*)hnd;

	return	reacquire_keyboard_input( key );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�f�o�C�X�̏������D
*
* Return  : �������ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
init_keyboard_input
(
	GINPKEYBOARD*		key,		/* �L�[�{�[�h�n���h��       */
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	LPDIRECTINPUT8 			pdi;
	LPDIRECTINPUTDEVICE8	pdev;
	DIDEVICEINSTANCE		di;

	/* �L�[�{�[�h�f�o�C�X�̏����� */
	key->hwnd = hwnd;
	key->dinp = NULL;
	key->idev = NULL;
	ZeroMemory( key->buffer, sizeof( key->buffer ) );
	key->newbuf = key->buffer[0];
	key->oldbuf = key->buffer[1];

	/* DirectInput�̐��� */
	if( DirectInput8Create( hinst, DIRECTINPUT_VERSION, &IID_IDirectInput8, &pdi, NULL) != DI_OK )
	{
		OutputDebugString( "DirectInputCreate 8.0 FAILED\n" );

		return FALSE;
	}

	/* DirectInput�L�[�{�[�h�f�o�C�X�̐��� */
	if( pdi->lpVtbl->CreateDevice( pdi, &GUID_SysKeyboard, &pdev, NULL) != DI_OK)
	{
		OutputDebugString( "CreateDevice FAILED\n" );

		return	FALSE;
	}

	/* �L�[�{�[�h�f�[�^�t�H�[�}�b�g�̐ݒ� */
	if( pdev->lpVtbl->SetDataFormat( pdev, &c_dfDIKeyboard ) != DI_OK )
	{
		OutputDebugString( "SetDataFormat FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* �������x���̐ݒ� */
	if( pdev->lpVtbl->SetCooperativeLevel( pdev, key->hwnd,
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
	key->dinp = pdi;
	key->idev = pdev;

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�f�o�C�X�̏I�������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
cleanup_keyboard_input
(
	GINPKEYBOARD*		key			/* �L�[�{�[�h�n���h��       */
)
{
	/* DirectInput�L�[�{�[�h�f�o�C�X�̏��� */
	if ( key->idev != NULL )
	{
		key->idev->lpVtbl->Unacquire( key->idev );
		key->idev->lpVtbl->Release( key->idev );
		key->idev = NULL;
	}

	/* DirectInput�n���h���̏��� */
	if ( key->dinp != NULL )
	{
		key->dinp->lpVtbl->Release( key->dinp );
		key->dinp = NULL;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�f�[�^�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
read_keyboard_input
(
	GINPKEYBOARD*		key			/* �L�[�{�[�h�n���h��       */
)
{
	LPDIRECTINPUTDEVICE8	idev;
	HRESULT					hres;
	BYTE*					tmp;

	if ( ( idev = key->idev ) == NULL )
	{
		return;
	}

	/* �V�����o�b�t�@�ƌÂ��o�b�t�@�����ւ��� */
	tmp         = key->newbuf;
	key->newbuf = key->oldbuf;
	key->oldbuf = tmp;

	/* �L�[�{�[�h�̏�Ԃ�ǂݍ��� */
	hres = idev->lpVtbl->GetDeviceState( idev, sizeof( BYTE ) * 256,
														 (LPVOID)key->newbuf );
	if( hres != DI_OK )
	{
		/* �L�[�{�[�h�o�b�t�@�̏����� */
		ZeroMemory( key->newbuf, sizeof( BYTE ) * 256 );

		if ( ( hres == DIERR_INPUTLOST   )
		  || ( hres == DIERR_NOTACQUIRED ) )
		{
			reacquire_input( idev );
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�̏�Ԃ��擾�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
get_keyboard_state
(
	GINPKEYBOARD*		key,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	if ( ( key->newbuf[ key_code ] & 0x80 ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�������ꂽ�����ׂ�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
get_keyboard_trigger
(
	GINPKEYBOARD*		key,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	if ( ( ~key->oldbuf[ key_code ] & key->newbuf[ key_code ] & 0x80 ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�������ꂽ�����ׂ�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
get_keyboard_detach
(
	GINPKEYBOARD*		key,		/* �L�[�{�[�h�n���h��       */
	GKEYCODE			key_code	/* �L�[�R�[�h               */
)
{
	if ( ( key->oldbuf[ key_code ] & ~key->newbuf[ key_code ] & 0x80 ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�̉�����Ă���L�[�̎擾�D
*
* Return  : ������Ă���L�[�̃L�[�R�[�h��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GKEYCODE
get_keyboard_key
(
	GINPKEYBOARD*		key		/* �L�[�{�[�h�n���h��       */
)
{
	int					i;

	for ( i = 0; i < 256; i++ )
	{
		if ( ( key->newbuf[ i ] & 0x80 ) != 0 )
		{
			return	(GKEYCODE)i;
		}
	}

	/* ����������Ă��Ȃ���΂O��Ԃ� */
	return	0;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�L�[�{�[�h�f�o�C�X�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_keyboard_input
(
	GINPKEYBOARD*		key			/* �L�[�{�[�h�n���h��       */
)
{
	return	reacquire_input( key->idev );
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
