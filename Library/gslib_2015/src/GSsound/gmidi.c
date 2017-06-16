/******************************************************************************
* File Name : gmidi.c                              Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e���p �l�h�c�h�f�[�^�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gmidi.h"
#include	"heap.h"
#include	<stdio.h>
#include	<MMSystem.h>

/****** �萔�錾 *************************************************************/

#define MDS_F_NOSTREAMID 0x00000001UL	/* �X�g���[�����k�t���O */

/****** �f�[�^�^�錾 *********************************************************/

/*----- �l�h�c�h�X�g���[���R�[���o�b�N�֐��^ --------------------------------*/

typedef	void (CALLBACK* PMIDIPROC)(HMIDIIN hmidiIn, UINT uiMsg,
						 DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

/*----- �l�h�c�h�X�g���[���o�b�t�@�w�b�_�\���� ------------------------------*/

typedef struct
{
	DWORD			dwTickStart;	/* �^�C�}                      */
	DWORD			dwBuffLen;		/* �o�b�t�@�T�C�Y               */

} MIDSBUFFERHDR;

/*----- �l�c�r�t�@�C�����\���� --------------------------------------------*/

typedef	struct
{
	DWORD			dwTimeFormat;	/* �X�g���[���̎��ԕ����̑���   */
	DWORD			cbMaxBuffer;	/* �o�b�t�@�̍ő�T�C�Y         */
	DWORD			dwFlags;		/* �t�H�[�}�b�g�t���O           */

} MIDSFORMAT;

/*----- MIDI�X�g���[���\���� ------------------------------------------------*/

typedef	struct
{
	BOOL			play_flag;		/* �Đ����t���O                 */
	BOOL			loop_flag;		/* ���[�v�w��t���O             */
	BOOL			pause_flag;		/* �ꎞ��~���t���O             */
	HMIDISTRM		hmstrm;			/* MIDI�X�g���[���n���h��       */
	UINT			strm_id;		/* �X�g���[���h�c               */
	MIDSFORMAT		mfmt;			/* �l�r�c�t�H�[�}�b�g���       */
	DWORD			bufcnt;			/* MIDI�X�g���[���o�b�t�@��     */
	BYTE*			strmbuf;		/* MIDI�X�g���[���o�b�t�@       */
	UINT			curbuf;			/* �Đ����̃o�b�t�@�̈ʒu       */

} MIDIINFO;

/*----- �l�c�r�t�@�C���w�b�_�\���� ------------------------------------------*/

#pragma pack(1)

typedef	struct
{
	BYTE			RIFF[4];		/* "RIFF"                       */
	DWORD			dwSize;			/* �f�[�^�T�C�Y                 */
	BYTE			MIDS[4];		/* "MIDS"                       */
	BYTE			fmt_[4];		/* "fmt "                       */
	DWORD			swFSize;		/* �t�H�[�}�b�g���̃T�C�Y       */
	DWORD			dwTimeFormat;	/* �X�g���[���̎��ԕ����̑���   */
	DWORD			cbMaxBuffer;	/* �o�b�t�@�̍ő�T�C�Y         */
	DWORD			dwFlags;		/* �t�H�[�}�b�g�t���O           */
	BYTE			DATA[4];		/* "DATA"                       */
	DWORD			dwDSize;		/* �f�[�^���̃T�C�Y             */
	DWORD			dwNumBuffs;		/* �f�[�^�o�b�t�@��             */

} MdsHeader;

#pragma pack()

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	open_midi_stream( MIDIINFO* );
static BOOL	close_midi_stream( MIDIINFO* );
static BOOL	play_midi_stream( MIDIINFO* );
static BOOL	stop_midi_stream( MIDIINFO* );
static BOOL	pause_midi_stream( MIDIINFO* );
static BOOL	restart_midi_stream( MIDIINFO* );
static void CALLBACK cback_midi_stream( HMIDIIN,UINT,DWORD,DWORD,DWORD );
static BOOL	fread_mds_file( const char*, MdsHeader*, BYTE** );
static BYTE* create_strmbuf( MdsHeader*, BYTE* );
static BOOL	decompress_strmbuf( MIDIHDR*, MIDIHDR* );

/*=============================================================================
*
* Purpose : �l�h�c�h�̐����D
*
* Return  : �l�h�c�h�n���h����Ԃ��D
*
*============================================================================*/
GMIDI
GMidiNew
(
	const char*		fname,			/* �l�c�r�t�@�C����             */
	BOOL			loop_flag		/* ���[�v�t���O                 */
)
{
	MIDIINFO*		midi;
	MdsHeader		hmds;
	BYTE*			pmds = NULL;

	/* �l�c�r�t�@�C���̓ǂݍ��� */
	if ( fread_mds_file( fname, &hmds, &pmds ) == FALSE )
	{
		return	NULL;
	}

	midi = new_object( sizeof( MIDIINFO ) );

	midi->play_flag         = FALSE;
	midi->loop_flag         = loop_flag;
	midi->pause_flag        = FALSE;
	midi->hmstrm            = NULL;
	midi->strm_id           = MIDI_MAPPER;
	midi->mfmt.dwTimeFormat = hmds.dwTimeFormat;
	midi->mfmt.cbMaxBuffer  = hmds.cbMaxBuffer;
	midi->mfmt.dwFlags      = hmds.dwFlags;
	midi->bufcnt            = hmds.dwNumBuffs;
	midi->strmbuf           = pmds;
	midi->curbuf            = 0;

	return	(GMIDI)midi;
}

/*=============================================================================
*
* Purpose : �l�h�c�h�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMidiDelete
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	stop_midi_stream( midi );

	if ( midi->strmbuf != NULL )
	{
		del_object( midi->strmbuf );
	}

	del_object( midi );
}

/*=============================================================================
*
* Purpose : �l�h�c�h�̍Đ��D
*
* Return  : �Đ��ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiPlay
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	play_midi_stream( midi );
}

/*=============================================================================
*
* Purpose : �l�h�c�h�̒�~�D
*
* Return  : ��~�ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiStop
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	stop_midi_stream( midi );
}

/*=============================================================================
*
* Purpose : �l�h�c�h�̈ꎞ��~�D
*
* Return  : �ꎞ��~�ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiPause
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	pause_midi_stream( midi );
}

/*=============================================================================
*
* Purpose : �l�h�c�h�̈ꎞ��~��Ԃ���̍ĊJ�D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiRestart
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	restart_midi_stream( midi );
}

/*=============================================================================
*
* Purpose : �l�h�c�h���Đ��������ׂ�D
*
* Return  : �Đ����ł���ΐ^�C��~���ł���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiIsPlay
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	midi->play_flag;
}

/*=============================================================================
*
* Purpose : �l�h�c�h���ꎞ��~�������ׂ�D
*
* Return  : �ꎞ��~���ł���ΐ^�C�Đ����ł���΋U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiIsPause
(
	GMIDI			hnd				/* �l�h�c�h�n���h��             */
)
{
	MIDIINFO*		midi = (MIDIINFO*)hnd;

	return	midi->pause_flag;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̃I�[�v���D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
open_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	MIDIPROPTIMEDIV		mptdTimeDiv;
	HMIDISTRM			hmstrm;
	MMRESULT			mrl;

	/* ���ɃI�[�v������Ă����ꍇ�̓N���[�Y���� */
	if ( midi->hmstrm != NULL )
	{
		close_midi_stream( midi );
	}

	/* MIDI�X�g���[���̃I�[�v�� */
	mrl = midiStreamOpen( &hmstrm, &midi->strm_id, 1,
		 (DWORD)(PMIDIPROC)cback_midi_stream, (DWORD)midi, CALLBACK_FUNCTION );
	if ( mrl != MMSYSERR_NOERROR )
	{
		return	FALSE;
	}
	midi->hmstrm  = hmstrm;

	/* �X�g���[���̎��ԕ����̑�����ݒ肷�� */
	ZeroMemory( &mptdTimeDiv, sizeof( mptdTimeDiv ) );
	mptdTimeDiv.cbStruct  = sizeof( mptdTimeDiv );
	mptdTimeDiv.dwTimeDiv = midi->mfmt.dwTimeFormat;
	if ( midiStreamProperty( midi->hmstrm, (BYTE*)&mptdTimeDiv,
						MIDIPROP_SET | MIDIPROP_TIMEDIV ) != MMSYSERR_NOERROR )
	{
		close_midi_stream( midi );

		return FALSE;
	}

	return TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̃N���[�Y�D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
close_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	MIDIHDR*		pmhdr;
	int				i;

	if ( midi->hmstrm == NULL )
	{
		return	FALSE;
	}

	/* �X�g���[�������Z�b�g���� */
	if ( midiOutReset( (HMIDIOUT)midi->hmstrm ) != MMSYSERR_NOERROR )
	{
		return	FALSE;
	}

	pmhdr = (MIDIHDR*)midi->strmbuf;
	for ( i = midi->bufcnt; i > 0; i-- )
	{
		/* �X�g���[���̃w�b�_��������� */
		midiOutUnprepareHeader( (HMIDIOUT)midi->hmstrm, pmhdr,
														sizeof( MIDIHDR ) );

			/* ���̃X�g���[���Ɉڂ� */
		pmhdr = (MIDIHDR*)( ( (BYTE*)pmhdr) + sizeof( MIDIHDR )
			  + pmhdr->dwBufferLength );
	}

	/* �X�g���[�����N���[�Y���� */
	if ( midiStreamClose( midi->hmstrm ) == MMSYSERR_NOERROR )
	{
		midi->hmstrm    = NULL;
		midi->strm_id   = MIDI_MAPPER;
		midi->play_flag = FALSE;

		return TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̍Đ��D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
play_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	MIDIHDR*		pmhdr;
	int				i;

	/* ���ɍĐ�����Ă��邩�H */
	if ( midi->play_flag == TRUE )
	{
		return	FALSE;
	}

	/* �o�b�t�@�̃J�E���^�̏����� */
	midi->curbuf = 0;

	/* MIDI�X�g���[���̃I�[�v�� */
	if( open_midi_stream( midi ) == FALSE )
	{
		return	FALSE;
	}

	pmhdr = (MIDIHDR*)midi->strmbuf;
	for ( i = midi->bufcnt; i > 0; i-- )
	{
		/* �X�g���[���̃w�b�_��p�ӂ��� */
		if ( midiOutPrepareHeader( (HMIDIOUT)midi->hmstrm,
							   pmhdr, sizeof( MIDIHDR ) ) != MMSYSERR_NOERROR )
		{
			stop_midi_stream( midi );

			return	FALSE;
		}

		/* �Đ�����X�g���[�����L���[�ɓ���� */
		if ( midiStreamOut( midi->hmstrm,
							   pmhdr, sizeof( MIDIHDR ) ) != MMSYSERR_NOERROR )
		{
			stop_midi_stream( midi );

			return	FALSE;
		}

		/* ���̃X�g���[���Ɉڂ� */
		pmhdr = (MIDIHDR*)(((BYTE*)pmhdr) + sizeof( MIDIHDR )
		      + pmhdr->dwBufferLength );
	}

	/* ���ۂɍĐ����J�n���邽�ߍĐ����ĊJ���� */
	if ( midiStreamRestart( midi->hmstrm ) != MMSYSERR_NOERROR )
	{
		stop_midi_stream( midi );

		return	FALSE;
	}

	/* �Đ����t���O�̐ݒ� */
	midi->play_flag = TRUE;

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̒�~�D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
stop_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	if ( midi->hmstrm == NULL )
	{
		return	TRUE;
	}

	midi->play_flag = FALSE;
	if ( midiStreamStop( midi->hmstrm ) == MMSYSERR_NOERROR )
	{
		close_midi_stream( midi );

		return	TRUE;
    }

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̈ꎞ��~�D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
pause_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	if ( midi->pause_flag == TRUE )
	{
		return	FALSE;
	}

  	if ( midiStreamPause( midi->hmstrm ) == MMSYSERR_NOERROR )
	{
		midi->pause_flag = TRUE;

		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̍ĊJ�D
*
* Return  : ��������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
restart_midi_stream
(
	MIDIINFO*		midi			/* �l�h�c�h�n���h��             */
)
{
	if ( midi->pause_flag == FALSE )
	{
		return	FALSE;
	}

	if ( midiStreamRestart( midi->hmstrm ) == MMSYSERR_NOERROR )
	{
		midi->pause_flag = FALSE;

		return	TRUE;
	}

	return	FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[���̃R�[���o�b�N�֐��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void CALLBACK
cback_midi_stream
(
	HMIDIIN		hmidiIn,
	UINT		uiMsg,
	DWORD		dwInstance,
	DWORD		dwParam1,
	DWORD		dwParam2
)
{
	MIDIINFO* 	midi = (MIDIINFO*)dwInstance;
	(void)dwParam1; (void)dwParam2; (void)hmidiIn;

	switch( uiMsg )
	{
	case MOM_DONE:
		/* �Đ��ʒu�̃`�F�b�N */
		midi->curbuf++;
		if ( ( midi->curbuf    >= midi->bufcnt )
		  && ( midi->play_flag == TRUE         ) )
		{
			/* �Đ��I�� */
			midi->play_flag = FALSE;

			/* ���[�v����K�v������΃��[�v���� */
			if ( midi->loop_flag == TRUE )
			{
				play_midi_stream( midi );
			}
		}
		break;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�c�r�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_mds_file
(
	const char*		fname,			/* �E�F�[�u�t�@�C����               */
	MdsHeader*		mhdr,			/*-> �l�c�r�t�@�C���w�b�_           */
	BYTE** 			pmds			/*-> �l�c�r�f�[�^                   */
)
{
	FILE*			fhnd;
	BYTE*			buf;
	size_t			size;

	/* �l�c�r�t�@�C���̃I�[�v�� */
	if ( ( fhnd = fopen( fname, "rb" ) ) == NULL )
	{
		return	FALSE;
	}

	/* �l�c�r�t�@�C���w�b�_�̓ǂݍ��� */
	if ( fread( mhdr, sizeof( MdsHeader ), 1, fhnd ) != 1 )
	{
		fclose( fhnd );

		return	FALSE;
	}

	/* �l�c�r�ǂݍ��݃o�b�t�@�̊m�� */
	buf = new_object( mhdr->dwDSize );

	/* �l�c�r�f�[�^�̓ǂݍ��� */
	size = mhdr->dwDSize - sizeof( DWORD );
	if ( fread( buf, sizeof( BYTE ), size, fhnd ) != size )
	{
		fclose( fhnd );

		del_object( *pmds );

		return	FALSE;
	}

	/* �l�c�r�t�@�C���̃N���[�Y */
	fclose( fhnd );

	/* �l�h�c�h�X�g���[�~���O�o�b�t�@�̍쐬 */
	*pmds = create_strmbuf( mhdr, buf );

	/* �ǂݍ��ݗp�o�b�t�@�̏��� */
	del_object( buf );

	if ( *pmds == NULL )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�h�c�h�X�g���[�~���O�o�b�t�@�̍쐬�D
*
* Return  : �l�h�c�h�X�g���[�~���O�o�b�t�@��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BYTE*
create_strmbuf
(
	MdsHeader*		mhdr,			/* �l�c�r�t�@�C���w�b�_             */
	BYTE*			pBuff			/* �t�@�C������ǂݍ��񂾃f�[�^     */
)
{
	MIDIHDR*		pmhdr;
	BYTE*			pmds;
	MIDSBUFFERHDR*	pmhdrBuff;
	MIDIHDR			mhdrCmp;
	size_t			size;
	int				i;

	/* �l�h�c�h�X�g���[�~���O�f�[�^�̃T�C�Y�����߂� */
	size = ( mhdr->cbMaxBuffer + sizeof( MIDIHDR ) ) * mhdr->dwNumBuffs;

	pmds = new_object( size );

	pmhdr = (MIDIHDR*)pmds;

	for ( i = mhdr->dwNumBuffs; i > 0; i-- )
	{
		pmhdr->lpData         = (LPSTR)( pmhdr + 1 );
		pmhdr->dwBufferLength = mhdr->cbMaxBuffer;
		pmhdr->dwFlags        = 0;
		pmhdr->dwUser         = 0;
		pmhdr->lpNext         = NULL;

		pmhdrBuff  = (MIDSBUFFERHDR*)pBuff;
		pBuff     += sizeof(MIDSBUFFERHDR);
		if ( ( mhdr->dwFlags & MDS_F_NOSTREAMID ) == MDS_F_NOSTREAMID )
		{
			/* �o�b�t�@�͈��k����Ă��� */
			mhdrCmp.lpData          = (LPSTR)pBuff;
			mhdrCmp.dwBufferLength  = pmhdrBuff->dwBuffLen;
			mhdrCmp.dwBytesRecorded = pmhdrBuff->dwBuffLen;

			/* �o�b�t�@�̃f�[�^��W�J���� */
			if ( decompress_strmbuf( pmhdr, &mhdrCmp ) == FALSE )
			{
				del_object( pmds );

				return	NULL;
			}
		}
		else
		{
			/* �o�b�t�@�Ƀf�[�^���R�s�[ */
			pmhdr->dwBytesRecorded = pmhdrBuff->dwBuffLen;

			CopyMemory( pmhdr->lpData, pBuff, pmhdrBuff->dwBuffLen );
		}

		/* ���̃o�b�t�@�Ɉړ� */
		pBuff += pmhdrBuff->dwBuffLen;
		pmhdr  = (MIDIHDR*)( ( (BYTE*)pmhdr ) + sizeof( MIDIHDR ) 
		                                      + mhdr->cbMaxBuffer );
	}

	return	pmds;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �l�c�r�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s������U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
decompress_strmbuf
(
	MIDIHDR*	pmhdrDst,			/*-> �W�J���ꂽ�f�[�^           */
	MIDIHDR*	pmhdrSrc			/* ���k���ꂽ�f�[�^             */
)
{
	DWORD*  	pSrcData;
	DWORD*		pDstData;
	DWORD		dwSrc;
	DWORD		dwDst;
	DWORD		dwExtra;

	pSrcData = (DWORD*)pmhdrSrc->lpData;
	pDstData = (DWORD*)pmhdrDst->lpData;
	dwSrc    = pmhdrSrc->dwBytesRecorded;
	dwDst    = pmhdrDst->dwBufferLength;

	/* �o�b�t�@�S�̂̃T�C�Y�� DWORD �̔{���łȂ���΂����Ȃ� */
	if ( ( dwSrc & 3 ) != 0 )
	{
		return	FALSE;
	}

	while ( dwSrc != 0 )
	{
		/* ���Ȃ��Ƃ��C���ԍ��C�X�g���[���h�c�C�C�x���g��DWORD�̗̈悪�K�v */
		if ( dwDst < ( 3 * sizeof( DWORD ) ) )
		{
			return	FALSE;
		}

		/* ���ԍ����R�s�[���� */
		*pDstData++ = *pSrcData++;
		dwSrc -= sizeof( DWORD );
		dwDst -= sizeof( DWORD );

		/* �X�g���[���h�c���O�ɐݒ肷�� */
		*pDstData++ = 0;
		dwDst -= sizeof( DWORD );

		/* ��������f�[�^�����邩�m�F���� */
		if ( dwSrc == 0 )
		{
			return	FALSE;
		}

		/* �C�x���g�f�[�^���R�s�[���� */
		dwExtra = 0;
		if ( ( (*pSrcData) & 0x80000000L ) != 0 )
		{
			dwExtra = (*pSrcData) & 0x00FFFFFFL;
		}

		/* �C�x���g�̒��������E�ɂ��킹�ĂȂ�ׂ� ( ����DWORD�܂� ) */
		dwExtra = ( dwExtra + 3 ) & ~3;

		/* �C�x���g��DWORD���R�s�[���� */
		*pDstData++ = *pSrcData++;
		dwSrc -= sizeof( DWORD );
		dwDst -= sizeof( DWORD );

		/* �C�x���g�p�����[�^���R�s�[���� */
		if ( dwExtra != 0 )
		{
			if ( ( dwExtra > dwSrc ) || ( dwExtra > dwDst ) )
			{
				return	FALSE;
			}
			CopyMemory( pDstData, pSrcData, dwExtra );
		}

		/* �|�C���^���C���N�������g���Ē������X�V���� */
		pDstData += ( dwExtra / sizeof( DWORD ) );
		pSrcData += ( dwExtra / sizeof( DWORD ) );
		dwSrc    -= dwExtra;
		dwDst    -= dwExtra;
	}

	/* ���ʂ̃o�C�g�����v�Z���� */
	pmhdrDst->dwBytesRecorded = ( ((BYTE*)pDstData)
							  - (BYTE*)(pmhdrDst->lpData) );

	return	TRUE;
}

/********** End of File ******************************************************/
