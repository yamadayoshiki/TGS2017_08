/******************************************************************************
* File Name : gfile.c                            Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �Q�[���V�X�e���p�t�@�C�����o�́D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gfile.h"
#include	"heap.h"
#include	<stdio.h>
#include	<string.h>

/****** �萔�錾 *************************************************************/

#define	MAX_BUFFER_SIZE		256			/* �ő�ǂݍ��݃o�b�t�@�T�C�Y */
#define	DELIMITER			" \n\r\t,"	/* �f�t�H���g�f���~�^		  */

/****** �f�[�^�^�錾 *********************************************************/

/*----- �t�@�C���\���� ------------------------------------------------------*/

typedef	struct	GFile
{
	char*		pszFileName;			/* �t�@�C����				*/
	FILE*		pFile;					/* �t�@�C���|�C���^			*/
	GSboolean	bError;					/* �G���[�t���O				*/
	GSboolean	bEOF;					/* �d�n�e�t���O				*/
	char*		pszDelimiter;			/* �f���~�^����				*/

} GFile;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static GSboolean	GFileReadTxtFile( GFILE, const char*, void* );
static GSboolean	GFileReadBuffer( GFILE, char* );
static GSboolean	GFileReadSkipDelimiter( GFILE, char* );
static GSboolean	GFileSkipLine( GFILE );

/****** �}�N���֐��錾 *******************************************************/

/*----- �f���~�^�����̃`�F�b�N�}�N�� ------------------------------------------*/

#define	isdelimiter( fp, c )									\
(																\
	( strchr( (fp)->pszDelimiter, (c) ) != NULL ) ? GS_TRUE: GS_FALSE	\
)

/*=============================================================================
*
* Purpose : �t�@�C���̃I�[�v���D
*
* Return  : �t�@�C���n���h����Ԃ��D
*           �t�@�C���̃I�[�v���Ɏ��s�����ꍇ�m�t�k�k��Ԃ��D
*
*============================================================================*/
extern GFILE
GFileOpen
(
	const char*		pszFileName,		/* �t�@�C����			*/
	const char*		pszMode				/* �I�[�v�����[�h		*/
)
{
	GFile*			pGFile;
	FILE*			fp;

	/* �t�@�C�����I�[�v������ */
	if ( ( fp = fopen( pszFileName, pszMode ) ) == NULL )
	{
		return	NULL;
	}

	/* �t�@�C���𐶐��������� */
	pGFile = new_object( sizeof(GFile) );

	pGFile->pszFileName = new_object( strlen( pszFileName ) + 1 );
	strcpy( pGFile->pszFileName, pszFileName );
	pGFile->pFile       = fp;
	pGFile->bError      = GS_FALSE;
	pGFile->bEOF        = GS_FALSE;

	/* �f�t�H���g�̃f���~�^������ݒ肷�� */
	pGFile->pszDelimiter = new_object( strlen( DELIMITER ) + 1 );
	strcpy( pGFile->pszDelimiter, DELIMITER );

	return	(GFILE)pGFile;
}

/*=============================================================================
*
* Purpose : �t�@�C���̃N���[�Y�D
*
* Return  : �N���[�Y�ɐ�������ΐ^�C���s�����ꍇ�͋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileClose
(
	GFILE			hnd					/* �t�@�C���n���h��		*/
)
{
	GFile*		pGFile = (GFile*)hnd;
	int			Error;

	/* �t�@�C�����N���[�Y���� */
	Error = fclose( pGFile->pFile );

	/* �f���~�^���������ł����� */
	del_object( pGFile->pszDelimiter );

	/* �t�@�C���������ł����� */
	del_object( pGFile->pszFileName );

	/* �t�@�C�������ł����� */
	del_object( pGFile );

	if ( Error != 0 )
	{
		return	GS_FALSE;
	}

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : �t�@�C���A�N�Z�X�ŃG���[�������������ׂ�D
*
* Return  : �G���[�ł���ΐ^�C�G���[�łȂ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileIsError
(
	GFILE			hnd					/* �t�@�C���n���h��		*/
)
{
	GFile*		pGFile = (GFile*)hnd;

	return	pGFile->bError;
}

/*=============================================================================
*
* Purpose : �t�@�C���A�N�Z�X���������������ׂ�D
*
* Return  : �����ł���ΐ^�C���s�ł���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileIsSuccess
(
	GFILE			hnd					/* �t�@�C���n���h��		*/
)
{
	GFile*		pGFile = (GFile*)hnd;

	if ( pGFile->bError == GS_FALSE )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �t�@�C�����d�n�e�܂ŒB���������ׂ�D
*
* Return  : �d�n�e�ł���ΐ^�C�����łȂ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileIsEOF
(
	GFILE			hnd					/* �t�@�C���n���h��		*/
)
{
	GFile*		pGFile = (GFile*)hnd;

	return	pGFile->bEOF;
}

/*=============================================================================
*
* Purpose : �t�@�C�����̎擾�D
*
* Return  : �t�@�C�����̐擪�A�h���X��Ԃ��D
*
*============================================================================*/
extern char*
GFileGetFileName
(
	GFILE			hnd					/* �t�@�C���n���h��		*/
)
{
	GFile*		pGFile = (GFile*)hnd;

	return	pGFile->pszFileName;
}

/*=============================================================================
*
* Purpose : �f���~�^�����̐ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
GFileSetDelimiter
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	const char*		pszDelimiter		/* �f���~�^����			*/
)
{
	GFile*		pGFile = (GFile*)hnd;

	/* ���݂̃f���~�^���������ł����� */
	del_object( pGFile->pszDelimiter );

	/* �V�����f���~�^������ݒ肷�� */
	pGFile->pszDelimiter = new_object( strlen( pszDelimiter ) + 1 );
	strcpy( pGFile->pszDelimiter, pszDelimiter );
}

/*=============================================================================
*
* Purpose : �P�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadByte
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSubyte*		pByte				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GSuint			input;
	GSboolean		Success;

	if ( ( Success = GFileReadTxtFile( hnd, "%d", &input ) ) == GS_TRUE )
	{
		*pByte = (GSubyte)input;
	}

	return	Success;
}

/*=============================================================================
*
* Purpose : �Q�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadWord
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSushort*		pWord				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GSuint			input;
	GSboolean		Success;

	if ( ( Success = GFileReadTxtFile( hnd, "%d", &input ) ) == GS_TRUE )
	{
		*pWord = (GSushort)input;

		return	GS_TRUE;
	}

	return	Success;
}

/*=============================================================================
*
* Purpose : �S�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadDword
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint*			pDword				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	return	GFileReadTxtFile( hnd, "%d", pDword );
}

/*=============================================================================
*
* Purpose : �P�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadByteHex
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSubyte*		pByte				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GSuint			input;
	GSboolean		Success;

	if ( ( Success = GFileReadTxtFile( hnd, "%x", &input ) ) == GS_TRUE )
	{
		*pByte = (GSubyte)input;
	}

	return	Success;
}

/*=============================================================================
*
* Purpose : �Q�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadWordHex
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSushort*			pWord				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GSuint			input;
	GSboolean		Success;

	if ( ( Success = GFileReadTxtFile( hnd, "%x", &input ) ) == GS_TRUE )
	{
		*pWord = (GSushort)input;
	}

	return	Success;
}

/*=============================================================================
*
* Purpose : �S�o�C�g�T�C�Y�̃f�[�^��ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadDwordHex
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint*			pDword				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	return	GFileReadTxtFile( hnd, "%x", pDword );
}

/*=============================================================================
*
* Purpose : ���������_�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadFloat
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSfloat*		pFloat				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	return	GFileReadTxtFile( hnd, "%f", pFloat );
}

/*=============================================================================
*
* Purpose : ������̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadString
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	char*			pszString			/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	return	GFileReadTxtFile( hnd, "%s", pszString );
}

/*=============================================================================
*
* Purpose : �R�c�x�N�g���^�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadVector3
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSvector3*		pVector3d			/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GFileReadFloat( hnd, &pVector3d->x );
	GFileReadFloat( hnd, &pVector3d->y );
	GFileReadFloat( hnd, &pVector3d->z );

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���^�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadQuaternion
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSquaternion*	pQuaternion			/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GFileReadFloat( hnd, &pQuaternion->x );
	GFileReadFloat( hnd, &pQuaternion->y );
	GFileReadFloat( hnd, &pQuaternion->z );
	GFileReadFloat( hnd, &pQuaternion->w );

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����W�^�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadTexCoord
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSvector2*		pTexcood			/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GFileReadFloat( hnd, &pTexcood->s );
	GFileReadFloat( hnd, &pTexcood->t );

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �J���[�^�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadColor
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GScolor*		pColor				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GFileReadFloat( hnd, &pColor->r );
	GFileReadFloat( hnd, &pColor->g );
	GFileReadFloat( hnd, &pColor->b );
	GFileReadFloat( hnd, &pColor->a );

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �}�g���N�X�^�̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadMatrix4
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSmatrix4*		pMatrix				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	int			i;
	int			j;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			GFileReadFloat( hnd, &pMatrix->m[i][j] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �P�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadByteArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numByte,			/* �z��̗v�f��			*/
	GSubyte*		pByteArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint		i;

	if ( pByteArray != NULL )
	{
		for ( i = 0; i < numByte; i++ )
		{
			GFileReadByte( hnd, &pByteArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �Q�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadWordArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numWord,			/* �z��̗v�f��			*/
	GSushort*			pWordArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint		i;

	if ( pWordArray != NULL )
	{
		for ( i = 0; i < numWord; i++ )
		{
			GFileReadWord( hnd, &pWordArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �S�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadDwordArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numDword,			/* �z��̗v�f��			*/
	GSuint*			pDwordArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pDwordArray != NULL )
	{
		for ( i = 0; i < numDword; i++ )
		{
			GFileReadDword( hnd, &pDwordArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �P�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadByteHexArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numByte,			/* �z��̗v�f��			*/
	GSubyte*		pByteArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pByteArray != NULL )
	{
		for ( i = 0; i < numByte; i++ )
		{
			GFileReadByteHex( hnd, &pByteArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �Q�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadWordHexArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numWord,			/* �z��̗v�f��			*/
	GSushort*		pWordArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pWordArray != NULL )
	{
		for ( i = 0; i < numWord; i++ )
		{
			GFileReadWordHex( hnd, &pWordArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �S�o�C�g�T�C�Y�̃f�[�^�z���ǂݍ��ށD�i�P�U�i���j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadDwordHexArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numDword,			/* �z��̗v�f��			*/
	GSuint*			pDwordArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pDwordArray != NULL )
	{
		for ( i = 0; i < numDword; i++ )
		{
			GFileReadDwordHex( hnd, &pDwordArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : ���������_�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadFloatArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numFloat,			/* �z��̗v�f��			*/
	GSfloat*		pFloatArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pFloatArray != NULL )
	{
		for ( i = 0; i < numFloat; i++ )
		{
			GFileReadFloat( hnd, &pFloatArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �R�c���W�^�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadVector3Array
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numVector3,			/* �z��̗v�f��			*/
	GSvector3*		pVector3Array		/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pVector3Array != NULL )
	{
		for ( i = 0; i < numVector3; i++ )
		{
			GFileReadVector3( hnd, &pVector3Array[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �J���[�^�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadColorArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numColorArray,		/* �z��̗v�f��			*/
	GScolor*		pColorArray			/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pColorArray != NULL )
	{
		for ( i = 0; i < numColorArray; i++ )
		{
			GFileReadColor( hnd, &pColorArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����W�^�̃f�[�^�z���ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*============================================================================*/
extern GSboolean
GFileReadTexCoordArray
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	GSuint			numTexCoord,		/* �z��̗v�f��			*/
	GSvector2*		pTexCoordArray		/* �z��̐擪�A�h���X	*/
)
{
	GSuint			i;

	if ( pTexCoordArray != NULL )
	{
		for ( i = 0; i < numTexCoord; i++ )
		{
			GFileReadTexCoord( hnd, &pTexCoordArray[i] );
		}
	}

	return	GFileIsSuccess( hnd );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�L�X�g�t�@�C���̃f�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
GFileReadTxtFile
(
	GFILE			hnd,				/* �t�@�C���n���h��		*/
	const char*		farmat,				/* �ϊ��t�H�[�}�b�g�w��	*/
	void*			pinput				/*-> �ǂݍ��񂾃f�[�^	*/
)
{
	GFile*			pGFile = (GFile*)hnd;
	char			buffer[MAX_BUFFER_SIZE];

	/* ������̓ǂݍ��� */
	if ( GFileReadBuffer( hnd, buffer ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ��������w��̃t�H�[�}�b�g�ŕϊ����� */
	if ( sscanf( buffer, farmat, pinput ) == 0 )
	{
		/* �ϊ����ł��Ȃ���΃G���[ */
		pGFile->bError = GS_TRUE;
	}

	return	GFileIsSuccess( hnd );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �ǂݍ��݃o�b�t�@�Ƀf�[�^��ǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
GFileReadBuffer
(
	GFILE			hnd,				/* �t�@�C���n���h��			*/
	char*			pbuffer				/*-> �ǂݍ��݃o�b�t�@		*/
)
{
	GFile*			pGFile = (GFile*)hnd;
	char			c;
	int				ic;

	/* ���G���[��Ԃł��邩�H */
	if ( GFileIsError( hnd ) == GS_TRUE )
	{
		return	GS_FALSE;
	}

	/* ���ɂd�n�e�Ȃ̂ɓǂݍ���ł��܂��ƃG���[ */
	if ( GFileIsEOF( hnd ) == GS_TRUE )
	{
		pGFile->bError = GS_TRUE;

		return	GS_FALSE;
	}

	/* �f���~�^�̕����̓X�L�b�v���� */
	if ( GFileReadSkipDelimiter( hnd, &c ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* �f���~�^�܂œǂݍ��� */
	*pbuffer++ = c;
	while ( GS_TRUE )
	{
		/* �ꕶ���ǂݍ��� */
		ic = fgetc( pGFile->pFile );

		/* �d�n�e���ǂ����H */
		if ( feof( pGFile->pFile ) != 0 )
		{
			pGFile->bEOF = GS_TRUE;

			break;
		}

		/* �G���[�ł��邩�H */
		if ( ferror( pGFile->pFile ) != 0 )
		{
			pGFile->bError = GS_TRUE;

			break;
		}

		/* �f���~�^�������H */
		if ( isdelimiter( pGFile, ic ) == GS_TRUE )
		{
			break;
		}

		*pbuffer++ = (char)ic;
	}
	*pbuffer = '\0';

	return	GFileIsSuccess( hnd );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �f���~�^�ƃR�����g��ǂݔ�΂��ĂP�����ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
GFileReadSkipDelimiter
(
	GFILE			hnd,				/* �t�@�C���n���h��			*/
	char*			pChar				/*-> �ǂݍ��񂾕���			*/
)
{
	GFile*			pGFile = (GFile*)hnd;
	int				c;

	/* �f���~�^�������X�L�b�v���� */
	do
	{
		/* �ꕶ���ǂݍ��� */
		c = fgetc( pGFile->pFile );

		/* �d�n�e���ǂ����H */
		if ( feof( pGFile->pFile ) != 0 )
		{
			pGFile->bEOF = GS_TRUE;

			break;
		}

		/* �G���[���ǂ����H */
		if ( ferror( pGFile->pFile ) != 0 )
		{
			pGFile->bError = GS_TRUE;

			break;
		}

		/* �����C�R�����g�ł���� */
		if ( c == '#' )
		{
			/* �R�����g�s�͍s���܂ŃX�L�b�v���� */
			GFileSkipLine( pGFile );

			/* �s���͉��s�����ł��� */
			c = '\n';
		}
	} while ( isdelimiter( pGFile, c ) == GS_TRUE );

	/* �d�n�e�܂��́C�G���[���H */
	if ( GFileIsEOF( pGFile ) == GS_TRUE || GFileIsError( pGFile ) == GS_TRUE )
	{
		return	GS_FALSE;
	}

	*pChar = (char)c;

	return	GS_TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �s���܂œǂݔ�΂�����D
*
* Return  : �ǂݔ�΂��̂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
GFileSkipLine
(
	GFILE		hnd						/* �t�@�C���n���h��			*/
)
{
	GFile*			pGFile = (GFile*)hnd;

	/* EOF���ǂ����H */
	while ( feof( pGFile->pFile ) == 0 )
	{
		/* �G���[��Ԃł��邩�H */
		if ( ferror( pGFile->pFile ) != 0 )
		{
			return	GS_FALSE;
		}
		/* ���s�R�[�h�����͂����܂ŃX�L�b�v���� */
		if ( fgetc( pGFile->pFile ) == '\n' )
		{
			return	GS_TRUE;
		}
	}

	return	GS_FALSE;
}

/********** End of File ******************************************************/
