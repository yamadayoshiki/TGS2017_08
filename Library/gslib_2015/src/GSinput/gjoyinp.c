/******************************************************************************
* File Name : gjoyinp.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �W���C�X�e�B�b�N����.
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gjoyinp.h"
#include	"heap.h"
#pragma		warning(disable:4201) // �����\���̂̎g�p
#define		DIRECTINPUT_VERSION		0x0800
#include	<dinput.h>

/****** �f�[�^�^�錾 *********************************************************/

/*----- �W���C�X�e�B�b�N���̓f�o�C�X�\���� ----------------------------------*/

typedef	struct
{
	HINSTANCE            hinst;					/* �C���X�^���X�n���h��     */
	HWND                 hwnd;					/* �E�B���h�E�n���h��       */
	LPDIRECTINPUT8       dinp;					/* DirectInput�n���h��      */
	int                  n;						/* �W���C�X�e�B�b�N��       */
	LPDIRECTINPUTDEVICE8 idev[GJOYSTICK_MAX];	/* �W���C�X�e�B�b�N�f�o�C�X */
	GJOYSTATE            buf[2][GJOYSTICK_MAX];	/* �W���C�X�e�B�b�N�o�b�t�@ */
	GJOYSTATE*           newbuf;				/* ���݂̓��̓o�b�t�@       */
	GJOYSTATE*           oldbuf;				/* �O��̓��̓o�b�t�@       */

} GINPJOYSTICK;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL init_joystick_input( GINPJOYSTICK*, HINSTANCE, HWND );
static int get_joystick_count( GINPJOYSTICK* );
static void cleanup_joystick_input( GINPJOYSTICK* );
static void read_joystick_input( GINPJOYSTICK* );
static GJOYSTATE get_joystick_state( GINPJOYSTICK*, int );
static GJOYSTATE get_joystick_trigger( GINPJOYSTICK*, int );
static GJOYSTATE get_joystick_detach( GINPJOYSTICK*, int );
static BOOL reacquire_joystick_input( GINPJOYSTICK* );
static BOOL FAR PASCAL init_joystick_device( LPCDIDEVICEINSTANCE, LPVOID );
static void cleanup_joystick_device( LPDIRECTINPUTDEVICE8 );
static GJOYSTATE read_joystick_device( LPDIRECTINPUTDEVICE8 );
static HRESULT set_property( LPDIRECTINPUTDEVICE8,REFGUID,DWORD,DWORD,DWORD );
static BOOL reacquire_input( LPDIRECTINPUTDEVICE8 );
static void read_joystick_axis(LPDIRECTINPUTDEVICE8, int*, int*, int*, int*);

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̐����D
*
* Return  : �W���C�X�e�B�b�N�n���h����Ԃ��D
*
*============================================================================*/
GJOYINP
GJoyInpNew
(
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	GINPJOYSTICK*		joy;

	joy = new_object( sizeof( GINPJOYSTICK ) );

	if ( init_joystick_input( joy, hinst, hwnd ) == FALSE )
	{
		del_object( joy );

		return	NULL;
	}

	return	(GJOYINP)joy;
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GJoyInpDelete
(
	GJOYINP				hnd			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	cleanup_joystick_input( joy );

	del_object( joy );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GJoyInpReadDevice
(
	GJOYINP				hnd			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	read_joystick_input( joy );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̓��͏�Ԃ𒲂ׂ�D
*
* Return  : ������Ă���ΐ^�C������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GJoyInpGetState
(
	GJOYINP				hnd,		/* �W���C�X�e�B�b�N�n���h��         */
	int					joy_no,		/* �W���C�X�e�B�b�N�i���o           */
	GJOYSTATE			state		/* ���ׂ����W���C�X�e�b�N�̏��     */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	if ( ( get_joystick_state( joy, joy_no ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}


/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GJoyInpGetTrigger
(
	GJOYINP				hnd,		/* �W���C�X�e�B�b�N�n���h��         */
	int					joy_no,		/* �W���C�X�e�B�b�N�i���o           */
	GJOYSTATE			state		/* ���ׂ����W���C�X�e�b�N�̏��     */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	if ( ( get_joystick_trigger( joy, joy_no ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�������ꂽ�����ׂ�D
*
* Return  : �����ꂽ��^�C������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GJoyInpGetDetach
(
	GJOYINP				hnd,		/* �W���C�X�e�B�b�N�n���h��         */
	int					joy_no,		/* �W���C�X�e�B�b�N�i���o           */
	GJOYSTATE			state		/* ���ׂ����W���C�X�e�b�N�̏��     */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	if ( ( get_joystick_detach( joy, joy_no ) & state ) != 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̎��̏�Ԃ�ǂݍ��ށD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GJoyInpGetAxis
(
	GJOYINP				hnd,		/* �W���C�X�e�B�b�N�n���h��         */
	int					joy_no,		/* �W���C�X�e�B�b�N�i���o           */
	int*				lx,			/*-> ���W���C�X�e�b�B�N�̂����̏��   */
	int*				ly,			/*-> ���W���C�X�e�b�B�N�̂����̏��   */
	int*				rx,			/*-> �E�W���C�X�e�b�B�N�̂����̏��   */
	int*				ry			/*-> �E�W���C�X�e�b�B�N�̂����̏��   */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	/* �W���C�X�e�B�b�N�̎��̏�Ԃ�ǂݍ��� */
	read_joystick_axis( joy->idev[ joy_no ], lx, ly, rx, ry );
}

/*=============================================================================
*
* Purpose : �ڑ�����Ă���W���C�X�e�B�b�N���𒲂ׂ�D
*
* Return  : �ڑ�����Ă���W���C�X�e�B�b�N����Ԃ��D
*
*============================================================================*/
int
GJoyInpGetCount
(
	GJOYINP				hnd			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	return	get_joystick_count( joy );
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �擾�ł���ΐ^�C�擾�ł��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GJoyInpReacquire
(
	GJOYINP				hnd			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	GINPJOYSTICK*		joy = (GINPJOYSTICK*)hnd;

	return	reacquire_joystick_input( joy );
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̏������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
init_joystick_input
(
	GINPJOYSTICK*		joy,		/* �W���C�X�e�B�b�N�n���h�� */
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	LPDIRECTINPUT8 		pdi;
	joy->hwnd = hwnd;
	joy->dinp = NULL;
	joy->n    = 0;
	ZeroMemory( joy->idev, sizeof( joy->idev ) );
	ZeroMemory( joy->buf,  sizeof( joy->buf  ) );
	joy->newbuf = joy->buf[0];
	joy->oldbuf = joy->buf[1];

	if (DirectInput8Create(hinst, DIRECTINPUT_VERSION, &IID_IDirectInput8, &pdi, NULL) != DI_OK)
	{
		OutputDebugString("DirectInputCreate 8.0 FAILED");
		return	FALSE;
	}
	joy->dinp = pdi;
	pdi->lpVtbl->EnumDevices( pdi, DI8DEVCLASS_GAMECTRL,
                              init_joystick_device, joy, DIEDFL_ATTACHEDONLY );
	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̏I�������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
cleanup_joystick_input
(
	GINPJOYSTICK*		joy			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	int				i;

	/* �S�ẴW���C�X�e�B�b�N�̏I���������s�� */
	for ( i = 0; i < joy->n; i++ )
	{
		cleanup_joystick_device( joy->idev[i] );
		joy->idev[i] = NULL;
	}

	/* DirectInput�n���h���̏��� */
	if ( joy->dinp != NULL )
	{
		joy->dinp->lpVtbl->Release( joy->dinp );
		joy->dinp = NULL;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
read_joystick_input
(
	GINPJOYSTICK*		joy			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	int					i;
	GJOYSTATE*			tmp;

	/* ���݂̃o�b�t�@�ƌÂ��o�b�t�@����ꊷ���� */
	tmp         = joy->newbuf;
	joy->newbuf = joy->oldbuf;
	joy->oldbuf = tmp;

	/* �S�ẴW���C�X�e�B�b�N�̓ǂݍ��݂��s�� */
	for ( i = 0; i < joy->n; i++ )
	{
		joy->newbuf[i] = read_joystick_device( joy->idev[i] );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �W���C�X�e�B�b�N�̐ڑ����𒲂ׂ�D
*
* Return  : �W���C�X�e�B�b�N�̐ڑ�����Ԃ��D
*
*----------------------------------------------------------------------------*/
static int
get_joystick_count
(
	GINPJOYSTICK*		joy			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	return	joy->n;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GJOYSTATE
get_joystick_state
(
	GINPJOYSTICK*		joy,		/* �W���C�X�e�B�b�N�n���h�� */
	int					joy_no		/* �W���C�X�e�B�b�N�i���o   */
)
{
	if ( joy_no >= joy->n )
	{
		return	0;
	}

	return	joy->newbuf[ joy_no ];
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�̓ǂݍ��݁D �i �����オ�� �j
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GJOYSTATE
get_joystick_trigger
(
	GINPJOYSTICK*		joy,		/* �W���C�X�e�B�b�N�n���h�� */
	int					joy_no		/* �W���C�X�e�B�b�N�i���o   */
)
{
	if ( joy_no >= joy->n )
	{
		return	0;
	}

	return	~joy->oldbuf[ joy_no ] & joy->newbuf[ joy_no ];
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�̓ǂݍ��݁D �i ���������� �j
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GJOYSTATE
get_joystick_detach
(
	GINPJOYSTICK*		joy,		/* �W���C�X�e�B�b�N�n���h�� */
	int					joy_no		/* �W���C�X�e�B�b�N�i���o   */
)
{
	if ( joy_no >= joy->n )
	{
		return	0;
	}

	return	joy->oldbuf[ joy_no ] & ~joy->newbuf[ joy_no ];
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�̃A�N�Z�X���̍Ď擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
reacquire_joystick_input
(
	GINPJOYSTICK*		joy			/* �W���C�X�e�B�b�N�n���h�� */
)
{
	int					i;

	for ( i = 0; i < joy->n; i++ )
	{
		if ( reacquire_input( joy->idev[i] ) == FALSE )
		{
			return	FALSE;
		}
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̐����D�i �R�[���o�b�N�֐� �j
*
* Return  : DIENUM_CONTINUE �܂��� FALSE ��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL FAR PASCAL
init_joystick_device
(
	LPCDIDEVICEINSTANCE		pdinst,	/* DirectInput�f�o�C�X�C���X�^���X */
	LPVOID					hnd		/* �W���C�X�e�B�b�N�n���h��        */
)
{
	GINPJOYSTICK*			joy = hnd;
	LPDIRECTINPUT8			pdi;
	LPDIRECTINPUTDEVICE8	pdev;
	DIPROPRANGE				diprg;

	/* DirectInput�W���C�X�e�b�N�f�o�C�X�̐��� */
	pdi = joy->dinp;
	if( pdi->lpVtbl->CreateDevice( pdi, &pdinst->guidInstance, &pdev, NULL) != DI_OK)
	{
		OutputDebugString( "CreateDevice FAILED\n" );

		return	DIENUM_CONTINUE;
	}

	/* �W���C�X�e�B�b�N�f�[�^�t�H�[�}�b�g�̐ݒ� */
	if( pdev->lpVtbl->SetDataFormat( pdev, &c_dfDIJoystick ) != DI_OK )
	{
		OutputDebugString( "SetDataFormat FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	DIENUM_CONTINUE;
	}

	/* �������x���̐ݒ� */
	if( pdev->lpVtbl->SetCooperativeLevel( pdev, joy->hwnd,
							 DISCL_NONEXCLUSIVE | DISCL_FOREGROUND ) != DI_OK )
	{
		OutputDebugString( "SetCooperativeLevel FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	DIENUM_CONTINUE;
	}

	/* ���W���C�X�e�B�b�N��x���̐ݒ� */
	diprg.diph.dwSize       = sizeof( diprg );
	diprg.diph.dwHeaderSize = sizeof( diprg.diph );
	diprg.diph.dwObj        = DIJOFS_X;
	diprg.diph.dwHow        = DIPH_BYOFFSET;
	diprg.lMin              = -1000;
	diprg.lMax              = +1000;
	if( pdev->lpVtbl->SetProperty( pdev, DIPROP_RANGE, &diprg.diph ) != DI_OK )
	{
		OutputDebugString( "SetProperty(DIPH_RANGE) FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}

	/* ���W���C�X�e�B�b�N�̂����̐ݒ� */
	diprg.diph.dwObj        = DIJOFS_Y;
	if( pdev->lpVtbl->SetProperty( pdev, DIPROP_RANGE, &diprg.diph ) != DI_OK )
	{
		OutputDebugString( "SetProperty(DIPH_RANGE) FAILED\n" );

		pdev->lpVtbl->Release( pdev );

		return	FALSE;
	}
	/* �������̖����]�[���̐ݒ� */
	if (set_property(pdev, DIPROP_DEADZONE, DIJOFS_X, DIPH_BYOFFSET, 5000) != DI_OK)
	{
		OutputDebugString("SetProperty(DIPH_DEADZONE) FAILED\n");

		pdev->lpVtbl->Release(pdev);

		return	FALSE;
	}

	/* �������̖����]�[���̐ݒ� */
	if (set_property(pdev, DIPROP_DEADZONE, DIJOFS_Y, DIPH_BYOFFSET, 5000) != DI_OK)
	{
		OutputDebugString("SetProperty(DIPH_DEADZONE) FAILED\n");

		pdev->lpVtbl->Release(pdev);

		return	FALSE;
	}

	/* �E�W���C�X�e�B�b�N��x���̐ݒ� */
	diprg.diph.dwObj = DIJOFS_Z;
	pdev->lpVtbl->SetProperty(pdev, DIPROP_RANGE, &diprg.diph);

	/* �E�W���C�X�e�B�b�N�̂����̐ݒ� */
	diprg.diph.dwObj = DIJOFS_RZ;
	pdev->lpVtbl->SetProperty(pdev, DIPROP_RANGE, &diprg.diph);

	/* �E�����̖����]�[���̐ݒ� */
	set_property(pdev, DIPROP_DEADZONE, DIJOFS_Z, DIPH_BYOFFSET, 5000);

	/* �E�����̖����]�[���̐ݒ� */
	set_property(pdev, DIPROP_DEADZONE, DIJOFS_RZ, DIPH_BYOFFSET, 5000);

	/* �A�N�Z�X���̎擾���s�� */
	reacquire_input( pdev );

	/* �W���C�X�e�B�b�N�̒ǉ��o�^ */
	if ( joy->n < GJOYSTICK_MAX )
	{
		joy->idev[ joy->n ] = pdev;
		joy->n++;
	}
	else
	{
		/* �K�v�ȏ�̃W���C�X�e�B�b�N�͎g���Ȃ� */
		pdev->lpVtbl->Release( pdev );
	}

	return	DIENUM_CONTINUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̏I�������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
cleanup_joystick_device
(
	LPDIRECTINPUTDEVICE8	joy		/* DirectInput�W���C�X�e�B�b�N�f�o�C�X  */
)
{
	if ( joy != NULL )
	{
		joy->lpVtbl->Unacquire( joy );

		joy->lpVtbl->Release( joy );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�W���C�X�e�B�b�N�f�o�C�X�̓ǂݍ��݁D
*
* Return  : �W���C�X�e�B�b�N�̓��͏�Ԃ�Ԃ��D
*
*----------------------------------------------------------------------------*/
static GJOYSTATE
read_joystick_device
(
	LPDIRECTINPUTDEVICE8	joy		/* DirectInput�W���C�X�e�B�b�N�f�o�C�X  */
)
{
	GJOYSTATE				joy_state;
	GJOYSTATE				bmask;
	HRESULT					hres;
	DIJOYSTATE				js;
	int						i;

	if ( joy == NULL )
	{
		return	0;
	}

	/* �W���C�X�e�B�b�N�Ƀ|�[�����O�̎w�����o�� */
	joy->lpVtbl->Poll( joy );

	/* �W���C�X�e�B�b�N�f�[�^�̓ǂݍ��� */
	hres = joy->lpVtbl->GetDeviceState( joy, sizeof( DIJOYSTATE ), &js );

	if ( hres != DI_OK )
	{
		if ( ( hres == DIERR_INPUTLOST   )
		  || ( hres == DIERR_NOTACQUIRED ) )
		{
			reacquire_input( joy );
		}

		return	0;
	}

	/* �����L�[�̃`�F�b�N */
	joy_state = 0;
	if ( js.lX < 0 ) 
	{
		/* ���������ꂽ */
		joy_state |= GJOY_LEFT;
	}
	else if ( js.lX > 0 )
	{
		/* �E�������ꂽ */
		joy_state |= GJOY_RIGHT;
	}
	if ( js.lY < 0 )
	{
		/* �オ�����ꂽ */
		joy_state |= GJOY_UP;
	}
	else if ( js.lY > 0 )
	{
		/* ���������ꂽ */
		joy_state |= GJOY_DOWN;
	}

	/* �{�^���̃`�F�b�N */
	bmask = GJOY_BUTTON_1;
	for ( i = 0; i < GJOY_BUTTON_MAX; i++ )
	{
		if ( ( js.rgbButtons[i] & 0x80 ) != 0 )
		{
			joy_state |= bmask;
		}
		bmask <<= 1;
	}

	return	joy_state;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �W���C�X�e�B�b�N�̎��̏�Ԃ�ǂݍ��ށD
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
read_joystick_axis
(
	LPDIRECTINPUTDEVICE8	joy,	/* DirectInput�W���C�X�e�B�b�N�f�o�C�X  */
	int*					lx,		/*-> �W���C�X�e�b�B�N�̂����̏��       */
	int*					ly,		/*-> �W���C�X�e�b�B�N�̂����̏��       */
	int*					rx,		/*-> �W���C�X�e�b�B�N�̂����̏��       */
	int*					ry		/*-> �W���C�X�e�b�B�N�̂����̏��       */
	)
{
	HRESULT					hres;
	DIJOYSTATE				js;

	*lx = 0;
	*ly = 0;
	*rx = 0;
	*ry = 0;
	if (joy == NULL)
	{
		return;
	}

	/* �W���C�X�e�B�b�N�Ƀ|�[�����O�̎w�����o�� */
	joy->lpVtbl->Poll( joy );

	/* �W���C�X�e�B�b�N�f�[�^�̓ǂݍ��� */
	hres = joy->lpVtbl->GetDeviceState( joy, sizeof( DIJOYSTATE ), &js );

	if ( hres != DI_OK )
	{
		if ( ( hres == DIERR_INPUTLOST   )
		  || ( hres == DIERR_NOTACQUIRED ) )
		{
			reacquire_input( joy );
		}

		return;
	}

	/* ���̏�Ԃ��擾 */
	*lx = (int)js.lX;
	*ly = (int)js.lY;
	*rx = (int)js.lZ;
	*ry = (int)js.lRz;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectInput�f�o�C�X�̃v���o�e�B�̐ݒ�D
*
* Return  : �ݒ���HRESULT�l��Ԃ��D
*
*----------------------------------------------------------------------------*/
static HRESULT
set_property
(
	LPDIRECTINPUTDEVICE8	pdev,	/* DirectInput�f�o�C�X          */
	REFGUID					guid,	/* �ݒ�Ώۂ̎��ʎq             */
	DWORD					obj,	/* �ݒ肷�鍀��                 */
	DWORD					how,	/* �ݒ�l�̕��@                 */
	DWORD					val		/* �ݒ�l                       */
)
{
	DIPROPDWORD				dipdw;

	dipdw.diph.dwSize       = sizeof( dipdw );
	dipdw.diph.dwHeaderSize = sizeof( dipdw.diph );
	dipdw.diph.dwObj        = obj;
	dipdw.diph.dwHow        = how;
	dipdw.dwData            = val;

	return pdev->lpVtbl->SetProperty( pdev, guid, &dipdw.diph );
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
