/******************************************************************************
* File Name : gssound.c                            Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �T�E���h�V�X�e���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gssound.h"
#include	"gmidires.h"
#include	"gwaveres.h"

/****** �萔�錾 *************************************************************/

#define	DEFAULT_SE_MAX	256		/* �f�t�H���g�̂r�d���\�[�X�̍ő吔		*/
#define	DEFAULT_BGM_MAX	32		/* �f�t�H���g�̂a�f�l���\�[�X�̍ő吔	*/

/****** �ϐ��錾 *************************************************************/

static GSOUND        GSound = NULL;	/* �T�E���h�n���h��         */
static GMIDIRESOURCE MRes   = NULL;	/* �l�h�c�h���\�[�X�n���h�� */
static GWAVERESOURCE WRes   = NULL;	/* �v�`�u�d���\�[�X�n���h�� */
static GMIDI         Bgm    = NULL;	/* ���ݍĐ����̂a�f�l       */

/*=============================================================================
*
* Purpose : �T�E���h�V�X�e���̏������D
*
* Return  : �������ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsInitSound
(
	HWND			hwnd			/* �E�B���h�E�n���h��       */
)
{
	if ( GSound == NULL )
	{
		/* �Q�[���V�X�e���p�T�E���h�̐��� */
		GSound = GSoundNew( hwnd );
	}

	if ( GSound != NULL )
	{
		/* �l�h�c�h���\�[�X�̐��� */
		if ( MRes == NULL )
		{
			MRes = GMidiResNew( GSound );
		}

		/* �v�`�u�d���\�[�X�̐��� */
		if ( WRes == NULL )
		{
			WRes = GWaveResNew( GSound );
		}

		/* �a�f�l�̏����� */
		gsInitBGM( DEFAULT_BGM_MAX );

		/* �r�d�̏�����   */
		gsInitSE( DEFAULT_SE_MAX );

		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �T�E���h�V�X�e���̏I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsFinishSound
(
	void
)
{
	if ( GSound == NULL )
	{
		return;
	}

	/* �l�h�c�h�T�E���h�̒�~ */
	GSoundStopMidi( GSound );

	/* �v�`�u�d�T�E���h�̒�~ */
	GSoundStopWave( GSound );

	/* �l�h�c�h���\�[�X�Ǘ��̏��� */
	GMidiResDelete( MRes );

	/* �v�`�u�d���\�[�X�Ǘ��̏��� */
	GWaveResDelete( WRes );

	/* �Q�[���V�X�e���p�T�E���h�̏��� */
	GSoundDelete( GSound );


	/* �n���h����S�ď����� */
	GSound = NULL;
	MRes   = NULL;
	WRes   = NULL;
}

/*=============================================================================
*
* Purpose : �E�B���h�E���A�N�e�B�u�ɂȂ������̏����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsActivateSound
(
	BOOL		active				/* �A�N�e�B�u�t���O         */
)
{
	if ( GSound == NULL )
	{
		return;
	}

	GSoundActivateApp( GSound, active );
}

/*=============================================================================
*
* Purpose : �S�ẴT�E���h���~����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsStopSound
(
	void
)
{
	if ( GSound == NULL )
	{
		return;
	}

	/* �l�h�c�h�Ƃv�`�u�d�̍Đ����~ */
	GSoundStop( GSound );
}

/*=============================================================================
*
* Purpose : �a�f�l�̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsInitBGM
(
	int				n				/* �a�f�l���\�[�X�f�[�^��   */
)
{
	if ( GSound == NULL )
	{
		return;
	}

	/* �a�f�l�̒�~ */
	gsStopBGM();

	/* �a�f�l���\�[�X�̏����� */
	GMidiResInit( MRes, n );
}

/*=============================================================================
*
* Purpose : �a�f�l�f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsLoadBGM
(
	GRESOURCEID		id,				/* �a�f�l���\�[�X�h�c       */
	const char*		fname,			/* �a�f�l�t�@�C����         */
	BOOL			flag			/* ���[�v�w��t���O         */
)
{
	GMIDI			midi;

	if ( GSound == NULL )
	{
		return	FALSE;
	}

	/* �l�h�c�h���\�[�X�̎擾 */
	if ( ( midi = GMidiResGetResource( MRes, id ) ) != NULL )
	{
		if ( midi == Bgm )
		{
			/* �Đ����̂a�f�l�ł���Β�~���� */
			gsStopBGM();
		}
		/* �l�h�c�h���\�[�X�̉�� */
		GMidiResDelResource( MRes, id );
	}

	/* �l�h�c�h���\�[�X�̓ǂݍ��� */
	return	GMidiResLoadResource( MRes, id, fname, flag );
}

/*=============================================================================
*
* Purpose : �a�f�l�̉���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsDeleteBGM
(
	GRESOURCEID		id				/* �a�f�l���\�[�X�h�c       */
)
{
	GMIDI			midi;

	if ( GSound == NULL )
	{
		return;
	}

	/* �l�h�c�h���\�[�X�̎擾 */
	if ( ( midi = GMidiResGetResource( MRes, id ) ) != NULL )
	{
		if ( midi == Bgm )
		{
			/* �Đ����̂a�f�l�ł���Β�~���� */
			gsStopBGM();
		}
		/* �l�h�c�h���\�[�X�̉�� */
		GMidiResDelResource( MRes, id );
	}
}

/*=============================================================================
*
* Purpose : �a�f�l�̍Đ��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsPlayBGM
(
	GRESOURCEID		id				/* �a�f�l���\�[�X�h�c   */
)
{
	GMIDI			midi;

	if ( GSound == NULL )
	{
		return;
	}

	/* �l�h�c�h���\�[�X�̎擾 */
	if ( ( midi = GMidiResGetResource( MRes, id ) ) == NULL )
	{
		return;
	}

	/* ���ɍĐ����ł��邩���ׂ� */
	if ( Bgm == midi )
	{
		return;
	}

	/* �l�h�c�h�T�E���h�̒�~ */
	if ( Bgm != NULL )
	{
		GMidiStop( Bgm );
	}

	/* �l�h�c�h�T�E���h�̍Đ� */
	GMidiPlay( midi );

	/* ���ݍĐ����̂a�f�l�ɐݒ� */
	Bgm = midi;
}

/*=============================================================================
*
* Purpose : �a�f�l�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsStopBGM
(
	void
)
{
	/* �l�h�c�h�T�E���h�̒�~ */
	if ( Bgm != NULL )
	{
		GMidiStop( Bgm );

		Bgm = NULL;
	}
}

/*=============================================================================
*
* Purpose : �a�f�l�̈ꎞ��~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsPauseBGM
(
	void
)
{
	if ( Bgm != NULL )
	{
		GMidiPause( Bgm );
	}
}

/*=============================================================================
*
* Purpose : �a�f�l�̈ꎞ��~����̍ĊJ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsRestartBGM
(
	void
)
{
	if ( Bgm != NULL )
	{
		GMidiRestart( Bgm );
	}
}

/*=============================================================================
*
* Purpose : �a�f�l���Đ��������ׂ�D
*
* Return  : �Đ����ł���ΐ^�C�Đ����łȂ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsIsPlayBGM
(
	void
)
{
	if ( Bgm == NULL )
	{
		return	FALSE;
	}

	return	GMidiIsPlay( Bgm );
}

/*=============================================================================
*
* Purpose : �a�f�l���ꎞ��~�������ׂ�D
*
* Return  : �ꎞ��~���ł���ΐ^�C�Đ����ł���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsIsPauseBGM
(
	void
)
{
	if ( Bgm == NULL )
	{
		return	FALSE;
	}

	return	GMidiIsPause( Bgm );
}

/*=============================================================================
*
* Purpose : �r�d�̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsInitSE
(
	int				n				/* �r�d���\�[�X�f�[�^��   */
)
{
	if ( GSound == NULL )
	{
		return;
	}

	/* �v�`�u�d�T�E���h�̒�~ */
	GSoundStopWave( GSound );

	/* �v�`�u�d���\�[�X�̏����� */
	GWaveResInit( WRes, n );
}

/*=============================================================================
*
* Purpose : �r�d�f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsLoadSE
(
	GRESOURCEID		id,				/* �r�d���\�[�X�h�c         */
	const char*		fname,			/* �r�d�f�[�^�t�@�C����     */
	int				cnt,			/* �����Đ���               */
	GWAVEFLAG		flag			/* �Đ��^�C�v�t���O         */
)
{
	GWAVE			wave;

	if ( GSound == NULL )
	{
		return	FALSE;
	}

	/* �v�`�u�d���\�[�X�̎擾 */
	if ( ( wave = GWaveResGetResource( WRes, id ) ) != NULL )
	{
		/* �v�`�u�d���\�[�X�̉�� */
		GWaveResDelResource( WRes, id );
	}

	/* �v�`�u�d���\�[�X�̓ǂݍ��� */
	return	GWaveResLoadResource( WRes, id, fname, cnt, flag );
}

/*=============================================================================
*
* Purpose : �r�d�̉���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsDeleteSE
(
	GRESOURCEID		id				/* �a�f�l���\�[�X�h�c       */
)
{
	GWAVE			wave;

	if ( WRes == NULL )
	{
		return;
	}

	/* �v�`�u�d���\�[�X�̎擾 */
	if ( ( wave = GWaveResGetResource( WRes, id ) ) != NULL )
	{
		/* �v�`�u�d���\�[�X�̉�� */
		GWaveResDelResource( WRes, id );
	}
}

/*=============================================================================
*
* Purpose : �r�d�̍Đ��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsPlaySE
(
	GRESOURCEID		id					/* �r�d���\�[�X�h�c     */
)
{
	GWAVE			wave;

	if ( GSound == NULL )
	{
		return;
	}

	/* �v�`�u�d���\�[�X�̎擾 */
	if ( ( wave = GWaveResGetResource( WRes, id ) ) == NULL )
	{
		return;
	}

	/* �v�`�u�d�f�[�^���Đ� */
	GWavePlay( wave );
}

/*=============================================================================
*
* Purpose : �r�d�̒�~�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsStopSE
(
	GRESOURCEID		id					/* �r�d���\�[�X�h�c     */
)
{
	GWAVE			wave;

	if ( GSound == NULL )
	{
		return;
	}

	/* �v�`�u�d���\�[�X�̎擾 */
	if ( ( wave = GWaveResGetResource( WRes, id ) ) == NULL )
	{
		return;
	}

	/* �v�`�u�d�f�[�^���~ */
	GWaveStop( wave );
}

/*=============================================================================
*
* Purpose : �r�d���Đ��������ׂ�D
*
* Return  : �Đ����ł���ΐ^�C�Đ����łȂ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
gsIsPlaySE
(
	GRESOURCEID		id					/* �r�d���\�[�X�h�c     */
)
{
	GWAVE			wave;

	if ( GSound == NULL )
	{
		return	FALSE;
	}

	/* �v�`�u�d���\�[�X�̎擾 */
	if ( ( wave = GWaveResGetResource( WRes, id ) ) == NULL )
	{
		return	FALSE;
	}

	return	GWaveIsPlay( wave );
}

/********** End of File ******************************************************/
