/******************************************************************************
* File Name : ginput.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p���̓f�o�C�X�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"ginput.h"
#include	"heap.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- ���̓f�o�C�X�\���� --------------------------------------------------*/

typedef	struct
{
	GKEYINP				key;		/* �L�[�{�[�h               */
	GJOYINP				joy;		/* �W���C�X�e�B�b�N         */
	GMOUSE				mou;		/* �}�E�X                   */

} GINPDEVICE;

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�n���h���̐����D
*
* Return  : ���̓f�o�C�X�n���h����Ԃ��D
*
*============================================================================*/
GINPUT
GInputNew
(
	HINSTANCE			hinst,		/* �C���X�^���X�n���h��     */
	HWND				hwnd		/* �E�B���h�E�n���h��       */
)
{
	GINPDEVICE*			inp;

	inp = new_object( sizeof( GINPDEVICE ) );

	/* �L�[�{�[�h�̐��� */
	inp->key = GKeyInpNew( hinst, hwnd );

	/* �W���C�X�e�B�b�N�̐��� */
	inp->joy = GJoyInpNew(hinst, hwnd);

	/* �}�E�X�̐��� */
	inp->mou = GMouseNew( hinst, hwnd );

	return	(GINPUT)inp;
}

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�n���h���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GInputDelete
(
	GINPUT				hnd			/* ���̓f�o�C�X�n���h��    */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	/* �L�[�{�[�h�̏��� */
	if ( inp->key != NULL )
	{
		GKeyInpDelete( inp->key );
	}

	/* �W���C�X�e�B�b�N�̏��� */
	if ( inp->joy != NULL )
	{
		GJoyInpDelete( inp->joy );
	}

	/* �}�E�X�̏��� */
	if ( inp->mou != NULL )
	{
		GMouseDelete( inp->mou );
	}

	del_object( inp );
}

/*=============================================================================
*
* Purpose : ���̓f�o�C�X�̏�Ԃ̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GInputReadDevice
(
	GINPUT				hnd			/* ���̓f�o�C�X�n���h��    */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	/* �L�[�{�[�h�̓ǂݍ��݂��s�� */
	if ( inp->key != NULL )
	{
		GKeyInpReadDevice( inp->key );
	}

	/* �W���C�X�e�B�b�N�̓ǂݍ��݂��s�� */
	if ( inp->joy != NULL )
	{
		GJoyInpReadDevice( inp->joy );
	}

	/* �}�E�X�̓ǂݍ��݂��s�� */
	if ( inp->mou != NULL )
	{
		GMouseReadDevice( inp->mou );
	}
}

/*=============================================================================
*
* Purpose : �L�[�{�[�h�n���h���̎擾�D
*
* Return  : �L�[�{�[�h�n���h����Ԃ��D
*
*============================================================================*/
GKEYINP
GInputGetKeyborad
(
	GINPUT				hnd			/* ���̓f�o�C�X�n���h��    */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	return	inp->key;
}

/*=============================================================================
*
* Purpose : �W���C�X�e�B�b�N�n���h���̎擾�D
*
* Return  : �W���C�X�e�B�b�N�n���h����Ԃ��D
*
*============================================================================*/
GJOYINP
GInputGetJoystick
(
	GINPUT				hnd			/* ���̓f�o�C�X�n���h��    */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	return	inp->joy;
}

/*=============================================================================
*
* Purpose : �}�E�X�n���h���̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GMOUSE
GInputGetMouse
(
	GINPUT				hnd			/* ���̓f�o�C�X�n���h��    */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	return	inp->mou;
}

/*=============================================================================
*
* Purpose : ���̓f�o�C�X���A�N�e�B�u�ɂȂ������̏����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GInputActivateApp
(
	GINPUT				hnd,		/* ���̓f�o�C�X�n���h��            */
	BOOL				active		/* �A�N�e�B�u�t���O                */
)
{
	GINPDEVICE*			inp = (GINPDEVICE*)hnd;

	if ( active == TRUE )
	{
		if ( inp->key != NULL )
		{
			GKeyInpReacquire( inp->key );
		}

		if ( inp->joy != NULL )
		{
			GJoyInpReacquire( inp->joy );
		}

		if ( inp->mou != NULL )
		{
			GMouseReacquire( inp->mou );
		}
	}
}

/********** End of File ******************************************************/
