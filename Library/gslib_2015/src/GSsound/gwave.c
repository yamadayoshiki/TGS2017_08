/******************************************************************************
* File Name : gwave.c                              Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �E�F�[�u�f�[�^�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gwave.h"
#include	"heap.h"
#include	<stdio.h>

/****** �f�[�^�^�錾 *********************************************************/

/*----- �E�F�[�u�f�[�^�\���� ------------------------------------------------*/

typedef struct
{
	GWAVEFLAG			flag;		/* �Đ��^�C�v�w��t���O                  */
	int					volume;		/* �{�����[��                            */
	int					pan;		/* ���E�̃`�����l���̑��΃{�����[��      */
	void*				wave;		/* �E�F�[�u�t�@�C���f�[�^                */
	LPWAVEFORMATEX		wvfmt;		/* �E�F�[�u�t�@�C���t�H�[�}�b�g          */
	LPBYTE				wvdata;		/* �E�F�[�u�f�[�^                        */
	DWORD				wvsize;		/* �E�F�[�u�f�[�^�T�C�Y                  */
	int					bufcnt;		/* DirectSound�o�b�t�@��                 */
	int					bufidx;		/* DirectSound�o�b�t�@�C���f�b�N�X       */
	LPDIRECTSOUNDBUFFER	lpBuf[1];	/* DirectSound�o�b�t�@                   */

} WAVEINFO;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static LPDIRECTSOUNDBUFFER	create_sound_buffer( LPDIRECTSOUND, WAVEINFO* );
static BOOL	play_sound_buffer( WAVEINFO*, LPDIRECTSOUNDBUFFER );
static BOOL	is_play_sound_buffer( LPDIRECTSOUNDBUFFER );
static void	stop_sound_buffer( LPDIRECTSOUNDBUFFER );
static BOOL	wave_to_buffer( LPDIRECTSOUNDBUFFER, LPBYTE, DWORD );
static BOOL	fread_wave_file( const char*, LPBYTE* );
static BOOL	unpuck_wave_chunk( void*, LPWAVEFORMATEX*, LPBYTE*, DWORD* );

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̐����D
*
* Return  : �E�F�[�u�f�[�^�n���h����Ԃ��D
*
*============================================================================*/
GWAVE
GWaveNew
(
	LPDIRECTSOUND		lpDS,		/* DirectSound�n���h��              */
	const char*			fname,		/* WAVE�t�@�C����                   */
	int					cnt,		/* �����Đ���                       */
	GWAVEFLAG			flag		/* �Đ��^�C�v�w��t���O             */
)
{
	WAVEINFO*			wave;
	LPBYTE				pwav;
	LPWAVEFORMATEX		lpwfmx;
	LPBYTE				wvdata;
	DWORD				wvsize;
	size_t				size;
	int					i;
	HRESULT				dsval;

	/* �E�F�[�u�t�@�C���̓ǂݍ��� */
	if ( fread_wave_file( fname, &pwav ) == FALSE )
	{
		return	NULL;
	}

	/* �E�F�[�u�f�[�^�̃A���p�b�N */
	if ( unpuck_wave_chunk( pwav, &lpwfmx, &wvdata, &wvsize ) == FALSE )
	{
		del_object( pwav );

		return	NULL;
	}

	size = sizeof( WAVEINFO ) + ( cnt - 1 ) * sizeof( LPDIRECTSOUNDBUFFER );

	wave = new_object( size );

	wave->flag   = flag;
	wave->volume = 0;
	wave->pan    = 0;
	wave->wave   = pwav;
	wave->wvfmt  = lpwfmx;
	wave->wvdata = wvdata;
	wave->wvsize = wvsize;
	wave->bufcnt = cnt;
	wave->bufidx = 0;

	/* �T�E���h�o�b�t�@�̏����� */
	for ( i = 0; i < cnt; i++ )
	{
		wave->lpBuf[i] = NULL;
	}

	/* �I���W�i���T�E���h�o�b�t�@�̍쐬 */
	if ( ( wave->lpBuf[0] = create_sound_buffer( lpDS, wave ) ) == NULL )
	{
		GWaveDelete( wave );
	}

	/* �����Đ��p�̃T�E���h�o�b�t�@�̍쐬 */
	for ( i = 1; i < cnt; i++ )
	{
		dsval = lpDS->lpVtbl->DuplicateSoundBuffer( lpDS, wave->lpBuf[0],
		                                                 &wave->lpBuf[i] );
		if ( dsval != DS_OK )
		{
			GWaveDelete( wave );

			return	NULL;
		}
	}

	return	(GWAVE)wave;
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveDelete
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;
	LPDIRECTSOUNDBUFFER	lpBuf;
	int					i;

	for ( i = 0; i < wave->bufcnt; i++ )
	{
		if ( ( lpBuf = wave->lpBuf[i] ) != NULL )
		{
			lpBuf->lpVtbl->Release( lpBuf );
		}
	}

	if ( wave->wave != NULL )
	{
		del_object( wave->wave );
	}

	del_object( wave );
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̍Đ��������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWavePlayInit
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	GWaveStop( hnd );

	GWaveSetVolume( hnd, 0 );

	GWaveSetPan( hnd, 0 );
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̍Đ��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWavePlay
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;

	/* �E�F�[�u�f�[�^�̍Đ� */
	if ( play_sound_buffer( wave, wave->lpBuf[ wave->bufidx ] ) == TRUE )
	{
		/* ���̃o�b�t�@�Ɉړ� */
		wave->bufidx = ( wave->bufidx + 1 ) % wave->bufcnt;
	}
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^���Đ��������ׂ�D
*
* Return  : �Đ����ł���ΐ^�C�Đ����łȂ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GWaveIsPlay
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;
	int					i;

	for ( i = 0; i < wave->bufcnt; i++ )
	{
		if ( is_play_sound_buffer( wave->lpBuf[i] ) == TRUE )
		{
			return	TRUE;
		}
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveStop
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;
	int					i;

	for ( i = 0; i < wave->bufcnt; i++ )
	{
		stop_sound_buffer( wave->lpBuf[i] );
	}
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̃{�����[���ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveSetVolume
(
	GWAVE				hnd,		/* �E�F�[�u�f�[�^�n���h��           */
	int					volume		/* ���E�̃`�����l���̑��΃{�����[�� */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;
	LPDIRECTSOUNDBUFFER	lpBuf;
	int					i;

	wave->volume = volume;

	for ( i = 0; i < wave->bufcnt; i++ )
	{
		lpBuf = wave->lpBuf[i];

		lpBuf->lpVtbl->SetVolume( lpBuf, (LONG)volume );
	}
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̃{�����[���擾�D
*
* Return  : �E�F�[�u�f�[�^�̃{�����[���擾��Ԃ��D
*
*============================================================================*/
int
GWaveGetVolume
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;

	return	wave->volume;
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̍��E�̃`�����l���̑��΃{�����[����ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveSetPan
(
	GWAVE				hnd,		/* �E�F�[�u�f�[�^�n���h��           */
	int					pan			/* ���E�̃`�����l���̑��΃{�����[�� */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;
	LPDIRECTSOUNDBUFFER	lpBuf;
	int					i;

	wave->volume = pan;

	for ( i = 0; i < wave->bufcnt; i++ )
	{
		lpBuf = wave->lpBuf[i];

		lpBuf->lpVtbl->SetPan( lpBuf, (LONG)pan );
	}
}

/*=============================================================================
*
* Purpose : �E�F�[�u�f�[�^�̍��E�̃`�����l���̑��΃{�����[�����擾����D
*
* Return  : ���E�̃`�����l���̑��΃{�����[����Ԃ��D
*
*============================================================================*/
int
GWaveGetPan
(
	GWAVE				hnd			/* �E�F�[�u�f�[�^�n���h��           */
)
{
	WAVEINFO*			wave = (WAVEINFO*)hnd;

	return	wave->pan;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectSound�o�b�t�@�̍쐬�D
*
* Return  : DirectSound�o�b�t�@��Ԃ��D
*
*----------------------------------------------------------------------------*/
static LPDIRECTSOUNDBUFFER
create_sound_buffer
(
	LPDIRECTSOUND		lpDS,		/* DirectSound�n���h��              */
	WAVEINFO*			wave		/* �E�F�[�u�f�[�^���               */
)
{
	LPDIRECTSOUNDBUFFER	lpBuf;
	DSBUFFERDESC		dsbd;
	HRESULT				hrs;

	/* �T�E���h�o�b�t�@�̏���ݒ� */
	ZeroMemory( &dsbd, sizeof( dsbd ) );
	dsbd.dwSize        = sizeof( dsbd );
	dsbd.dwFlags       = DSBCAPS_STATIC
		               | DSBCAPS_CTRLPAN
					   | DSBCAPS_CTRLVOLUME
					   | DSBCAPS_CTRLFREQUENCY;
	dsbd.dwBufferBytes = wave->wvsize;
	dsbd.lpwfxFormat   = wave->wvfmt;

	/* �T�E���h�o�b�t�@�̍쐬 */
	hrs = lpDS->lpVtbl->CreateSoundBuffer( lpDS, &dsbd, &lpBuf, NULL );

	if ( hrs != DS_OK )
	{
		return	NULL;
	}

	/* �T�E���h�o�b�t�@�ɃE�F�[�u�f�[�^��]�� */
	if ( wave_to_buffer( lpBuf, wave->wvdata, wave->wvsize ) == FALSE )
	{
		lpBuf->lpVtbl->Release( lpBuf );

		return	NULL;
	}

	return	lpBuf;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectSound�o�b�t�@�̍Đ��D
*
* Return  : �Đ�����������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
play_sound_buffer
(
	WAVEINFO*			wave,		/* �E�F�[�u�f�[�^���               */
	LPDIRECTSOUNDBUFFER	lpBuf		/* �Đ�����T�E���h�o�b�t�@         */
)
{
	DWORD		dwStatus;
	DWORD		dwFlags;

	/* �T�E���h�o�b�t�@�̏�Ԃ̎擾 */
	if ( lpBuf->lpVtbl->GetStatus( lpBuf, &dwStatus ) != DS_OK )
	{
		return	FALSE;
	}

	/* �T�E���h�o�b�t�@�������Ă��邩�`�F�b�N */
	if ( ( dwStatus & DSBSTATUS_BUFFERLOST) == DSBSTATUS_BUFFERLOST )
	{
		/* �T�E���h�o�b�t�@�̕��� */
		if ( lpBuf->lpVtbl->Restore( lpBuf ) != DS_OK )
		{
			return	FALSE;
		}

		/* �E�F�[�u�f�[�^�̍ē]�� */
		if ( wave_to_buffer( lpBuf, wave->wvdata, wave->wvsize ) == FALSE )
		{
			return	FALSE;
		}
	}

	/* �Đ����̃`�F�b�N */
	if ( ( dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING )
	{
		if ( ( wave->flag & GWAVE_WAIT ) == GWAVE_WAIT )
		{
			/* �T�E���h�I���҂� */
			return	FALSE;
		}

		/* �T�E���h��~ */
		stop_sound_buffer( lpBuf );
	}

	/* ���[�v�w��̐ݒ� */
	dwFlags = 0;
	if ( ( wave->flag & GWAVE_LOOP ) == GWAVE_LOOP )
	{
		/* �T�E���h�I���҂� */
		dwFlags = DSBPLAY_LOOPING;
	}

	/* �T�E���h�̍Đ� */
	if ( lpBuf->lpVtbl->Play( lpBuf, 0,0, dwFlags ) != DS_OK )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DirectSound�o�b�t�@�̒�~�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
is_play_sound_buffer
(
	LPDIRECTSOUNDBUFFER	lpBuf		/* �T�E���h�o�b�t�@                  */
)
{
	DWORD		dwStatus;

	/* �T�E���h�o�b�t�@�̏�Ԃ̎擾 */
	if ( lpBuf->lpVtbl->GetStatus( lpBuf, &dwStatus ) != DS_OK )
	{
		return	FALSE;
	}

	/* �Đ����̃`�F�b�N */
	if ( ( dwStatus & DSBSTATUS_PLAYING ) == DSBSTATUS_PLAYING )
	{
		return	TRUE;
	}

	return	FALSE;
}
/*-----------------------------------------------------------------------------
*
* Purpose : DirectSound�o�b�t�@�̒�~�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
stop_sound_buffer
(
	LPDIRECTSOUNDBUFFER	lpBuf		/* ��~����T�E���h�o�b�t�@         */
)
{
	lpBuf->lpVtbl->Stop( lpBuf );

	lpBuf->lpVtbl->SetCurrentPosition( lpBuf, 0 );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �T�E���h�o�b�t�@�ɃE�F�[�u�f�[�^��]���D
*
* Return  : �]���ɐ�������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
wave_to_buffer
(
	LPDIRECTSOUNDBUFFER	lpBuf,		/* �]����̃T�E���h�o�b�t�@         */
	LPBYTE				wave,		/* �E�F�[�u�f�[�^                   */
	DWORD				size		/* �E�F�[�u�f�[�^�̃T�C�Y           */
)
{
	HRESULT				hrs;
	LPVOID				lpAudioPtr1;
	LPVOID				lpAudioPtr2;
	DWORD				dwAudioBytes1;
	DWORD				dwAudioBytes2;

	/* �T�E���h�o�b�t�@�̃��b�N */
	hrs = lpBuf->lpVtbl->Lock( lpBuf, 0, size,
	           &lpAudioPtr1, &dwAudioBytes1, &lpAudioPtr2, &dwAudioBytes2, 0 );
	if ( hrs != DS_OK )
	{
		return	FALSE;
	}

	/* �T�E���h�o�b�t�@�Ƀf�[�^��]�� */
	CopyMemory( lpAudioPtr1, wave, dwAudioBytes1 );

	if( dwAudioBytes2 != 0 )
	{
		CopyMemory( lpAudioPtr2, wave + dwAudioBytes1, dwAudioBytes2 );
	}

	/* �T�E���h�o�b�t�@�̃A�����b�N */
	lpBuf->lpVtbl->Unlock( lpBuf, lpAudioPtr1, dwAudioBytes1,
	                              lpAudioPtr2, dwAudioBytes2 );

	return TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �E�F�[�u�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_wave_file
(
	const char*		fname,			/* �E�F�[�u�t�@�C����               */
	LPBYTE* 		pwave			/* �E�F�[�u�f�[�^                   */
)
{
	FILE*			fhnd;
	long			size;

	/* �E�F�[�u�t�@�C���̃I�[�v�� */
	if ( ( fhnd = fopen( fname, "rb" ) ) == NULL )
	{
		return	FALSE;
	}

	/* �t�@�C���T�C�Y�����߂� */
	if ( fseek( fhnd, 0, SEEK_END ) != 0 )
	{
		fclose( fhnd );

		return	FALSE;
	}
	size = ftell( fhnd );

	/* �t�@�C���̈ʒu��擪�ɖ߂� */
	if ( fseek( fhnd, 0, SEEK_SET ) != 0 )
	{
		fclose( fhnd );

		return	FALSE;
	}

	/* �E�F�[�u�f�[�^�̊m�� */
	*pwave = new_object( size );

	/* �E�F�[�u�f�[�^�̓ǂݍ��� */
	if ( fread( *pwave, sizeof(BYTE), size, fhnd ) != (size_t)size )
	{
		fclose( fhnd );

		del_object( *pwave );

		return	FALSE;
	}

	/* �E�F�[�u�t�@�C���̃N���[�Y */
	fclose( fhnd );

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �E�F�[�u�f�[�^�̃A���p�b�N�D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
unpuck_wave_chunk
(
	void*			pRIFFBytes,		/* �E�F�[�u�t�@�C���f�[�^  */
	LPWAVEFORMATEX*	lpwfmx,			/*-> �E�F�[�u�t�H�[�}�b�g  */
	LPBYTE*			lpChunkData,	/*-> �E�F�[�u�f�[�^        */
	DWORD*			lpCkSize		/*-> �E�F�[�u�f�[�^�T�C�Y  */
)
{
	DWORD*			dwChunkBitsPtr;
	DWORD*			dwChunkTailPtr;
	DWORD			dwChunkID;
	DWORD			dwType;
	DWORD			dwLength;

	if ( lpwfmx != NULL )
	{
		*lpwfmx = NULL;
	}

	if ( lpChunkData != NULL )
	{
		*lpChunkData = NULL;
	}

	if ( lpCkSize != NULL )
	{
		*lpCkSize = 0;
	}

	dwChunkBitsPtr = (DWORD*)pRIFFBytes;

	/* �`�����N�h�c�̎��o�� */
	dwChunkID = *dwChunkBitsPtr++;	

	/* �`�����N�T�C�Y�̎��o�� */
	dwLength = *dwChunkBitsPtr++;

	/* �t�H�[���^�C�v�h�c�̎��o�� */
	dwType = *dwChunkBitsPtr++;

	/* �`�����N�h�c�̃`�F�b�N */
	if ( dwChunkID != mmioFOURCC( 'R','I','F','F' ) )
	{
		return	FALSE;
	}

	/* �t�H�[���^�C�v�h�c�̃`�F�b�N */
	if ( dwType != mmioFOURCC( 'W','A','V','E' ) )
	{
		return	FALSE;
	}

	dwChunkTailPtr = (DWORD*)( (BYTE*)dwChunkBitsPtr + dwLength - 4 );

	while( TRUE )
	{
		/* �`�����N�h�c�̎��o�� */
		dwType = *dwChunkBitsPtr++;

		/* �`�����N�T�C�Y�̎��o�� */
		dwLength = *dwChunkBitsPtr++;

		switch( dwType )
		{
		case mmioFOURCC( 'f','m','t',' ' ):
			/* �v�`�u�d�f�[�^�t�H�[�}�b�g�̎擾 */
			if ( lpwfmx != NULL && *lpwfmx == NULL )
			{
				if ( dwLength < sizeof( WAVEFORMAT ) )
				{
					return	FALSE;
				}
				*lpwfmx = (LPWAVEFORMATEX)dwChunkBitsPtr;

				if ( ( lpChunkData == 0 || *lpChunkData != NULL ) 
				  && ( lpCkSize    == 0 || *lpCkSize    != 0    ) )
				{
					return	TRUE;
				}
			}
			break;

		case mmioFOURCC( 'd','a','t','a' ):
			/* �v�`�u�d�f�[�^�̎擾 */
			if ( ( lpChunkData != NULL  && *lpChunkData == NULL )
			  || ( lpCkSize    != NULL  && *lpCkSize    == 0    ) )
			{
				if ( lpChunkData != NULL )
				{
					*lpChunkData = (LPBYTE)dwChunkBitsPtr;
				}

				if ( lpCkSize != NULL)
				{
					*lpCkSize = dwLength;
				}

				if ( ( lpwfmx == NULL ) || ( *lpwfmx != NULL ) )
				{
					return	TRUE;
				}
			}
			break;
		}
		/* ���̃`�����N�f�[�^�Ɉړ� */
		dwChunkBitsPtr = (DWORD*)((BYTE*)dwChunkBitsPtr + ((dwLength+1)&~1) );

		if ( dwChunkBitsPtr >= dwChunkTailPtr )
		{
			break;
		}
	}

	return	FALSE;
}

/********** End of File ******************************************************/
