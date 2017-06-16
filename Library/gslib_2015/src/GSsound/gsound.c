/******************************************************************************
* File Name : gsound.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �T�E���h�f�[�^�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gsound.h"
#include	"heap.h"
#include	"lklist.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �T�E���h�f�[�^�Ǘ��\���� --------------------------------------------*/

typedef	struct
{
	HWND			hwnd;			/* �E�B���h�E�n���h��           */
	LPDIRECTSOUND 	lpDS;			/* DirectSound�n���h��          */
	LKLIST			mlst;			/* �l�h�c�h�f�[�^���X�g         */
	LKLIST			wlst;			/* �v�`�u�d�f�[�^���X�g         */
	GMIDI			mstop;			/* ��~���̂l�h�c�h�f�[�^       */

} SOUNDENV;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	is_midi_play( const void*, const void* );
static BOOL	is_midi_pause( const void*, const void* );

/*=============================================================================
*
* Purpose : �T�E���h�n���h���̐����D
*
* Return  : �T�E���h�n���h����Ԃ��D
*
*============================================================================*/
GSOUND
GSoundNew
(
	HWND			hwnd			/* �E�B���h�E�n���h��           */
)
{
	SOUNDENV*		snd;
	LPDIRECTSOUND 	lpDS;
	HRESULT			dsval;

	CoInitialize(NULL);

	/* DirectSound�̍쐬 */
	dsval = DirectSoundCreate( NULL, &lpDS, NULL );
	if ( dsval != DS_OK )
	{
		OutputDebugString( "DirectSoundCreate FAILED" );

		return	NULL;
	}

	/* �������x���̐ݒ� */
	dsval = lpDS->lpVtbl->SetCooperativeLevel( lpDS, hwnd, DSSCL_NORMAL );
	if ( dsval != DS_OK )
	{
		lpDS->lpVtbl->Release( lpDS );

		OutputDebugString( "SetCooperativeLevel FAILED" );

		return	NULL;
	}

	snd = new_object( sizeof( SOUNDENV ) );

	snd->hwnd  = hwnd;
	snd->lpDS  = lpDS;
	snd->mlst  = LkListNew();
	snd->wlst  = LkListNew();
	snd->mstop = NULL;

	return	(GSOUND)snd;
}

/*=============================================================================
*
* Purpose : �T�E���h�n���h���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundDelete
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	LPDIRECTSOUND 	lpDS;

	/* �S�ẴT�E���h�f�[�^������ */
	GSoundCleanUp( hnd );

	/* �E�F�[�u�f�[�^���X�g�̏��� */
	LkListDelete( snd->wlst );

	/* �l�h�c�h�f�[�^���X�g�̏��� */
	LkListDelete( snd->mlst );

	/* DirectSound�̏��� */
	if ( ( lpDS = snd->lpDS ) != NULL )
	{
		lpDS->lpVtbl->Release( lpDS );
	}

	del_object( snd );

	CoUninitialize();
}

/*=============================================================================
*
* Purpose : �S�ẴT�E���h�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundStop
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	/* �v�`�u�d�T�E���h�̒�~ */
	GSoundStopWave( hnd );

	/* �l�h�c�h�T�E���h�̒�~ */
	GSoundStopMidi( hnd );
}

/*=============================================================================
*
* Purpose : �S�Ă̂v�`�u�d�T�E���h�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundStopWave
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GWAVE			wave;
	LKITER			iter;

	iter = LkListIterNew( snd->wlst );
	while ( ( wave = LkListIterGetNext( iter ) ) != NULL )
	{
		GWaveStop( wave );
	}
	LkListIterDelete( iter );
}

/*=============================================================================
*
* Purpose : �S�Ă̂l�h�c�h�T�E���h�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundStopMidi
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GMIDI			midi;
	LKITER			iter;

	iter = LkListIterNew( snd->mlst );
	while ( ( midi = LkListIterGetNext( iter ) ) != NULL )
	{
		GMidiStop( midi );
	}
	LkListIterDelete( iter );

	snd->mstop = NULL;
}

/*=============================================================================
*
* Purpose : �S�ẴT�E���h�f�[�^�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundCleanUp
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	/* �S�ẴE�F�[�u�f�[�^������ */
	GSoundCleanUpWave( hnd );

	/* �S�Ă̂l�h�c�h�f�[�^������ */
	GSoundCleanUpMidi( hnd );
}

/*=============================================================================
*
* Purpose : �S�ẴE�F�[�u�f�[�^�����ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundCleanUpWave
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GWAVE			wave;

	while ( ( wave = LkListRemoveHead( snd->wlst ) ) != NULL )
	{
		GWaveDelete( wave );
	}
}

/*=============================================================================
*
* Purpose : �S�Ă̂l�h�c�h�f�[�^�����ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundCleanUpMidi
(
	GSOUND			hnd				/* �T�E���h�n���h��             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GMIDI			midi;

	while ( ( midi = LkListRemoveHead( snd->mlst ) ) != NULL )
	{
		GMidiDelete( midi );
	}
	snd->mstop = NULL;
}

/*=============================================================================
*
* Purpose : �v�`�u�d�t�@�C���̓ǂݍ��݁D
*
* Return  : �v�`�u�d�f�[�^�n���h����Ԃ��D
*
*============================================================================*/
GWAVE
GSoundLoadWave
(
	GSOUND			hnd,			/* �T�E���h�n���h��             */
	const char*		fname,			/* �v�`�u�d�t�@�C����           */
	int				cnt,			/* �����Đ���                   */
	GWAVEFLAG		flag			/* �Đ��^�C�v�t���O             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GWAVE			wave;

	/* �v�`�u�d�f�[�^��V�K�ǂݍ��� */
	if ( ( wave = GWaveNew( snd->lpDS, fname, cnt, flag ) ) == NULL )
	{
		return	NULL;
	}

	/* �v�`�u�d�f�[�^�̓o�^ */
	LkListAddTail( snd->wlst, wave );

	return	wave;
}

/*=============================================================================
*
* Purpose : �v�`�u�d�f�[�^�̏��ŁD
*
* Return  : ���łł���ΐ^�C�ł��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GSoundDeleteWave
(
	GSOUND			hnd,			/* �T�E���h�n���h��             */
	GWAVE			wave			/* �v�`�u�d�f�[�^�n���h��       */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;

	/* �v�`�u�d�f�[�^���X�g����폜 */
	if ( LkListRemove( snd->wlst, wave ) != NULL )
	{
		/* �v�`�u�d�f�[�^�̏��� */
		GWaveDelete( wave );

		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �l�h�c�h�t�@�C���̓ǂݍ��݁D
*
* Return  : �l�h�c�h�f�[�^�n���h����Ԃ��D
*
*============================================================================*/
GMIDI
GSoundLoadMidi
(
	GSOUND			hnd,			/* �T�E���h�n���h��             */
	const char*		fname,			/* �l�c�r�t�@�C����             */
	BOOL			flag			/* ���[�v�w��t���O             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GMIDI			midi;

	/* �l�h�c�h�f�[�^��V�K�ǂݍ��� */
	if ( ( midi = GMidiNew( fname, flag ) ) == NULL )
	{
		return	NULL;
	}

	/* �l�h�c�h�f�[�^�̓o�^ */
	LkListAddTail( snd->mlst, midi );

	return	midi;
}

/*=============================================================================
*
* Purpose : �l�h�c�h�f�[�^�̏��ŁD
*
* Return  : ���łł���ΐ^�C�ł��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GSoundDeleteMidi
(
	GSOUND			hnd,			/* �T�E���h�n���h��             */
	GMIDI			midi			/* �l�h�c�h�f�[�^�n���h��       */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;

	/* �l�h�c�h�f�[�^���X�g����폜 */
	if ( LkListRemove( snd->mlst, midi ) != NULL )
	{
		if ( snd->mstop == midi )
		{
			snd->mstop = NULL;
		}

		/* �l�h�c�h�f�[�^�̏��� */
		GMidiDelete( midi );

		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �T�E���h���A�N�e�B�u�ɂȂ������̏����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GSoundActivateApp
(
	GSOUND			hnd,			/* �T�E���h�n���h��             */
	BOOL			active			/* �A�N�e�B�u�t���O             */
)
{
	SOUNDENV*		snd = (SOUNDENV*)hnd;
	GMIDI			midi;

	if ( active == TRUE )
	{
		if ( snd->mstop == NULL )
		{
			return;
		}
		/* �Đ����̂l�h�c�h�T�E���h������ */
		midi = LkListSearch( snd->mlst, NULL, is_midi_pause );
		if ( midi == snd->mstop )
		{
			/* ��~�����T�E���h�̍ĊJ */
			GMidiRestart( midi );
		}
		snd->mstop = NULL;
	}
	else
	{
		/* �Đ����̂v�`�u�d�T�E���h�̒�~ */
		GSoundStopWave( hnd );

		/* �Đ����̂l�h�c�h�T�E���h������ */
		midi = LkListSearch( snd->mlst, NULL, is_midi_play );
		if ( midi != NULL )
		{
			/* �Đ����̃T�E���h���~ */
			GMidiPause( midi );

			snd->mstop = midi;
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �Đ����̂l�h�c�h�f�[�^�̌����֐��D
*
* Return  : ������ΐ^�C������Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
is_midi_play
(
	const void*			key,		/* �����L�[                             */
	const void*			item		/* ��r����f�[�^                       */
)
{
	GMIDI				midi   = (GMIDI)item;
	(void)key;

	if ( GMidiIsPlay( midi ) == TRUE )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �Đ����̂l�h�c�h�f�[�^�̌����֐��D
*
* Return  : ������ΐ^�C������Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
is_midi_pause
(
	const void*			key,		/* �����L�[                             */
	const void*			item		/* ��r����f�[�^                       */
)
{
	GMIDI				midi = (GMIDI)item;
	(void)key;

	if ( GMidiIsPause( midi ) == TRUE )
	{
		return	TRUE;
	}

	return	FALSE;
}

/********** End of File ******************************************************/
