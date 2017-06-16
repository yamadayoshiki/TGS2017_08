/******************************************************************************
* File Name : GSload_bmp.c                     Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �r�b�g�}�b�v�t�@�C������e�N�X�`���f�[�^��ǂݍ��ށD
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSload_bmp.h"
#include	<windows.h>
#include	<stdio.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static BOOL	 fread_bitmapfileheader( FILE*, BITMAPFILEHEADER* );
static BOOL	 fread_bitmapbfinfheader( FILE*, BITMAPINFOHEADER* );
static BOOL	 fread_rgbquad( FILE*, RGBQUAD*, DWORD );
static BOOL	 fread_image( FILE*, GSvoid*, BITMAPFILEHEADER*, BITMAPINFOHEADER*, RGBQUAD* );
static BOOL	 fread_image_2bit( FILE*, GSvoid*, BITMAPINFOHEADER*, RGBQUAD* );
static BOOL	 fread_image_4bit( FILE*, GSvoid*, BITMAPINFOHEADER*, RGBQUAD* );
static BOOL	 fread_image_8bit( FILE*, GSvoid*, BITMAPINFOHEADER*, RGBQUAD* );
static BOOL	 fread_image_24bit( FILE*, GSvoid*, BITMAPINFOHEADER* );
static BOOL  fread_image_32bit( FILE*, GSvoid*, BITMAPINFOHEADER* );
static DWORD calc_palette_ncolors( BITMAPINFOHEADER* );
static DWORD calc_image_size( LONG, LONG, WORD );

/****** �}�N���֐��錾 *******************************************************/

/* �r�b�g�}�b�v�t�@�C���̕��̃p�f�B���O�l�����߂� */
#define	BMPFILE_WIDTH_PAD( w, b )	( ( ( 32 - (w)*(b) ) & 0x01f ) >> 3 )

/* �r�b�g�}�b�v�t�@�C���̕��̃o�C�g�������߂� */
#define	BMPFILE_WIDTH_SIZE( w, b )						\
(														\
	( (w)*(b) + ( ( 32 - (w)*(b) ) & 0x01f ) ) >> 3		\
)

/*=============================================================================
*
* Purpose : �r�b�g�}�b�v�t�@�C������e�N�X�`���C���[�W���쐬�D
*
* Return  : �����ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadBmpFile
(
	const char*			szFlieName,		/* �ǂݍ��݃t�@�C����			*/
	GSuint*				width,			/* -> ��						*/
	GSuint*				height,			/* -> ����						*/
	GSvoid**			image			/* -> �摜�f�[�^				*/
)
{
	FILE*				fp;
	BITMAPFILEHEADER	header;
	BITMAPINFOHEADER	info;
	RGBQUAD				palette[256];
	DWORD				n;

	/* �r�b�g�}�b�v�t�@�C���̃I�[�v��	*/
	if ( ( fp = fopen( szFlieName, "rb" ) ) == NULL )
	{
		return	FALSE;
	}

	/* �r�b�g�}�b�v�t�@�C���w�b�_�̓ǂݍ���	*/
	if ( fread_bitmapfileheader( fp, &header ) == FALSE )
	{
		fclose( fp );
		return	FALSE;
	}

	/* �r�b�g�}�b�v�t�@�C�����̓ǂݍ���	*/
	if ( fread_bitmapbfinfheader( fp, &info ) == FALSE )
	{
		fclose( fp );
		return	FALSE;
	}

	/* �C���[�W�f�[�^�T�C�Y�����߂� */
	if ( info.biSizeImage == 0 )
	{
		info.biSizeImage = calc_image_size( info.biWidth,
											info.biHeight,
											info.biBitCount );
	}

	/* �p���b�g�f�[�^�̓ǂݍ��� */
	if ( ( n = calc_palette_ncolors( &info ) ) != 0 )
	{
		if ( fread_rgbquad( fp, palette, n ) == FALSE )
		{
			fclose( fp );
			return	FALSE;
		}
	}

	/* �C���[�W�f�[�^��ǂݍ��� */
	*width  = info.biWidth;
	*height = info.biHeight;
	*image  = malloc((*width) * (*height) * sizeof(GSbyte) * 4);
	if ( fread_image( fp, *image, &header, &info, palette ) == FALSE )
	{
		fclose( fp );
		free(*image);
		*image = NULL;
		return	FALSE;
	}

	/* �r�b�g�}�b�v�t�@�C���̃N���[�Y	*/
	fclose( fp );

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �r�b�g�}�b�v�t�@�C���w�b�_�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_bitmapfileheader
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	BITMAPFILEHEADER*	pbfhdr		/* �r�b�g�}�b�v�t�@�C���w�b�_   */
)
{
	if ( fread( pbfhdr, sizeof( BITMAPFILEHEADER ), 1, fp ) < 1 )
	{
		return	FALSE;
	}

	if ( pbfhdr->bfType != 0x4D42 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �r�b�g�}�b�v�t�@�C�����̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_bitmapbfinfheader
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	BITMAPINFOHEADER*	pbfinfo		/* �r�b�g�}�b�v�t�@�C�����     */
)
{
	if ( fread( pbfinfo, sizeof( BITMAPINFOHEADER ), 1, fp ) < 1 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �J���[�f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_rgbquad
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	RGBQUAD*			bmiColors,	/* �ǂݍ��ރJ���[�f�[�^         */
	DWORD				n			/* �ǂݍ��ރJ���[�f�[�^��       */
)
{
	if ( n == 0 )
	{
		return	TRUE;
	}

	if ( fread( bmiColors, sizeof( RGBQUAD ), n, fp ) < n )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �r�b�g�}�b�v�t�@�C������C���[�W�f�[�^���e�N�X�`���ɓǂݍ��ށD
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPFILEHEADER*	pbfhdr,		/* �r�b�g�}�b�v�t�@�C���w�b�_   */
	BITMAPINFOHEADER*	pbfinf,		/* �r�b�g�}�b�v�t�@�C�����     */
	RGBQUAD*			palette		/* �r�b�g�}�b�v�f�[�^�̃|�C���^ */
)
{
	BOOL				error = FALSE;

	/* �C���[�W�f�[�^�܂ŃV�[�N���� */
	fseek( fp, pbfhdr->bfOffBits, SEEK_SET );

	switch ( pbfinf->biBitCount )
	{
	case 1:		/* �Q�F�r�b�g�}�b�v			*/
		error = fread_image_2bit( fp, pImage, pbfinf, palette );
		break;

	case 4:		/* �P�U�F�r�b�g�}�b�v		*/
		error = fread_image_4bit( fp, pImage, pbfinf, palette );
		break;

	case 8:		/* �Q�T�U�F�r�b�g�}�b�v		*/
		error = fread_image_8bit( fp, pImage, pbfinf, palette );
		break;

	case 24:	/* �Q�S�r�b�g�r�b�g�}�b�v	*/
		error = fread_image_24bit( fp, pImage, pbfinf );
		break;

	case 32:	/* �R�Q�r�b�g�r�b�g�}�b�v	*/
		error = fread_image_32bit( fp, pImage, pbfinf );
		break;
	}

	return	error;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �Q�������r�b�g�}�b�v�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image_2bit
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPINFOHEADER*	pbfinf,		/* �r�b�g�}�b�v�t�@�C�����     */
	RGBQUAD*			palette		/* �r�b�g�}�b�v�f�[�^�̃|�C���^ */
)
{
	BYTE*				pteximage;
	BYTE*				ptexel;
	BYTE				image = 0;
	BYTE				pixel;
	LONG				pad;
	LONG				x;
	LONG				y;
	LONG				height;

	height = abs( pbfinf->biHeight );
	pteximage = (BYTE*)pImage;

	/* ���̃p�f�B���O�l�����߂� */
	pad = BMPFILE_WIDTH_PAD( pbfinf->biWidth, pbfinf->biBitCount );

	for ( y = 0; y < height; y++ )
	{
		ptexel = &pteximage[ ( height-1 - y ) * pbfinf->biWidth * 4 ];

		for ( x = 0; x < pbfinf->biWidth; x++ )
		{
			/* �W�s�N�Z���ɂP��ǂݍ��� */
			if ( ( x & 0x07 ) == 0 )
			{
				image = (BYTE)fgetc( fp );
			}

			/* �s�N�Z���f�[�^�̎擾 */
			pixel = ( image >> ( 7 - ( x & 0x07 ) ) ) & 1;

			/* �s�N�Z���̐F�f�[�^���擾���� */
			ptexel[0] = palette[ pixel ].rgbRed;
			ptexel[1] = palette[ pixel ].rgbGreen;
			ptexel[2] = palette[ pixel ].rgbBlue;
			ptexel[3] = 0xff;

			ptexel += 4;
		}
		/* �p�f�B���O�����X�L�b�v���� */
		fseek( fp, pad, SEEK_CUR );
	}

	/* �t�@�C���̃G���[�`�F�b�N������ */
	if ( ferror( fp ) != 0 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �S�������r�b�g�}�b�v�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image_4bit
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPINFOHEADER*	pbfinf,		/* �r�b�g�}�b�v�t�@�C�����     */
	RGBQUAD*			palette		/* �r�b�g�}�b�v�f�[�^�̃|�C���^ */
)
{
	BYTE*				pteximage;
	BYTE*				ptexel;
	BYTE				image = 0;
	BYTE				pixel;
	LONG				pad;
	LONG				x;
	LONG				y;
	LONG				height;

	height = abs( pbfinf->biHeight );
	pteximage = (BYTE*)pImage;

	/* ���̃p�f�B���O�l�����߂� */
	pad = BMPFILE_WIDTH_PAD( pbfinf->biWidth, pbfinf->biBitCount );

	for ( y = 0; y < height; y++ )
	{
		ptexel = &pteximage[ ( height-1 - y ) * pbfinf->biWidth * 4 ];

		for ( x = 0; x < pbfinf->biWidth; x++ )
		{
			/* �Q�s�N�Z���ɂP��ǂݍ��� */
			if ( ( x & 0x01 ) == 0 )
			{
				image = (BYTE)fgetc( fp );
			}

			/* �s�N�Z���f�[�^�̎擾 */
			pixel = ( image >> ( ( ~x & 1 ) << 2 ) ) & 0x0f;

			/* �s�N�Z���̐F�f�[�^���擾���� */
			ptexel[0] = palette[ pixel ].rgbRed;
			ptexel[1] = palette[ pixel ].rgbGreen;
			ptexel[2] = palette[ pixel ].rgbBlue;
			ptexel[3] = 0xff;

			ptexel += 4;
		}
		/* �p�f�B���O�����X�L�b�v���� */
		fseek( fp, pad, SEEK_CUR );
	}

	/* �t�@�C���̃G���[�`�F�b�N������ */
	if ( ferror( fp ) != 0 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �W�������r�b�g�}�b�v�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image_8bit
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPINFOHEADER*	pbfinf,		/* �r�b�g�}�b�v�t�@�C�����     */
	RGBQUAD*			palette		/* �r�b�g�}�b�v�f�[�^�̃|�C���^ */
)
{
	BYTE*				pteximage;
	BYTE*				ptexel;
	BYTE				pixel;
	LONG				pad;
	LONG				x;
	LONG				y;
	LONG				height;

	height = abs( pbfinf->biHeight );

	/* �e�N�X�`���C���[�W�̃��b�N */
	pteximage = (BYTE*)pImage;

	/* ���̃p�f�B���O�l�����߂� */
	pad = BMPFILE_WIDTH_PAD( pbfinf->biWidth, pbfinf->biBitCount );

	for ( y = 0; y < height; y++ )
	{
		ptexel = &pteximage[ ( height-1 - y ) * pbfinf->biWidth * 4 ];

		for ( x = 0; x < pbfinf->biWidth; x++ )
		{
			/* �s�N�Z���̐F�f�[�^���擾���� */
			pixel = (BYTE)fgetc( fp );

			/* �s�N�Z���̐F�f�[�^���擾���� */
			ptexel[0] = palette[ pixel ].rgbRed;
			ptexel[1] = palette[ pixel ].rgbGreen;
			ptexel[2] = palette[ pixel ].rgbBlue;
			ptexel[3] = 0xff;

			ptexel += 4;
		}
		/* �p�f�B���O�����X�L�b�v���� */
		fseek( fp, pad, SEEK_CUR );
	}

	/* �t�@�C���̃G���[�`�F�b�N������ */
	if ( ferror( fp ) != 0 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �Q�S�������r�b�g�}�b�v�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image_24bit
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPINFOHEADER*	pbfinf		/* �r�b�g�}�b�v�t�@�C�����     */
)
{
	BYTE*				pteximage;
	BYTE*				ptexel;
	LONG				pad;
	LONG				x;
	LONG				y;
	LONG				height;

	height = abs( pbfinf->biHeight );

	/* �e�N�X�`���C���[�W�̃��b�N */
	pteximage = (BYTE*)pImage;

	/* ���̃p�f�B���O�l�����߂� */
	pad = BMPFILE_WIDTH_PAD( pbfinf->biWidth, pbfinf->biBitCount );

	for ( y = 0; y < height; y++ )
	{
		ptexel = &pteximage[ ( height-1 - y ) * pbfinf->biWidth * 4 ];

		for ( x = 0; x < pbfinf->biWidth; x++ )
		{
			/* �s�N�Z����ǂݍ��� */
			ptexel[2] = (BYTE)fgetc( fp );	/* Blue  */
			ptexel[1] = (BYTE)fgetc(fp);	/* Green */
			ptexel[0] = (BYTE)fgetc(fp);	/* Red   */
			ptexel[3] = (BYTE)0xff;			/* Alpha */

			ptexel += 4;
		}
		/* �p�f�B���O�����X�L�b�v���� */
		fseek( fp, pad, SEEK_CUR );
	}

	/* �t�@�C���̃G���[�`�F�b�N������ */
	if ( ferror( fp ) != 0 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �R�Q�������r�b�g�}�b�v�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static BOOL
fread_image_32bit
(
	FILE*				fp,			/* �t�@�C���n���h��             */
	GSvoid*				pImage,		/* �摜�f�[�^					*/
	BITMAPINFOHEADER*	pbfinf		/* �r�b�g�}�b�v�t�@�C�����     */
)
{
	BYTE*				pteximage;
	BYTE*				ptexel;
	LONG				pad;
	LONG				x;
	LONG				y;
	LONG				height;

	height = abs( pbfinf->biHeight );

	/* �e�N�X�`���C���[�W�̃��b�N */
	pteximage = (BYTE*)pImage;

	/* ���̃p�f�B���O�l�����߂� */
	pad = BMPFILE_WIDTH_PAD( pbfinf->biWidth, pbfinf->biBitCount );

	for ( y = 0; y < height; y++ )
	{
		ptexel = &pteximage[ ( height-1 - y ) * pbfinf->biWidth * 4 ];

		for ( x = 0; x < pbfinf->biWidth; x++ )
		{
			/* �s�N�Z����ǂݍ��� */
			ptexel[2] = (BYTE)fgetc( fp );	/* Blue  */
			ptexel[1] = (BYTE)fgetc(fp);	/* Green */
			ptexel[0] = (BYTE)fgetc(fp);	/* Red   */
			ptexel[3] = (BYTE)fgetc(fp);	/* Alpha */

			ptexel += 4;
		}
		/* �p�f�B���O�����X�L�b�v���� */
		fseek( fp, pad, SEEK_CUR );
	}

	/* �t�@�C���̃G���[�`�F�b�N������ */
	if ( ferror( fp ) != 0 )
	{
		return	FALSE;
	}

	return	TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �r�b�g�}�b�v�t�@�C����񂩂�J���[�f�[�^�������߂�D
*
* Return  : �J���[�f�[�^����Ԃ��D
*
*----------------------------------------------------------------------------*/
static DWORD
calc_palette_ncolors
(
	BITMAPINFOHEADER*	pbfinf		/* �r�b�g�}�b�v�t�@�C�����     */
)
{
	DWORD				ncolor;

	ncolor = 0;
	if ( pbfinf->biBitCount <= 8 )
	{
		if ( pbfinf->biClrUsed == 0 )
		{
			ncolor = 1 << pbfinf->biBitCount;
		}
		else
		{
			ncolor = pbfinf->biClrUsed;
		}
	}

	return	ncolor;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �C���[�W�T�C�Y�����߂�D
*
* Return  : �C���[�W�T�C�Y���o�C�g���ŕԂ��D
*
*----------------------------------------------------------------------------*/
static DWORD
calc_image_size
(
	LONG				width,		/* �r�b�g�}�b�v�̕�             */
	LONG				height,		/* �r�b�g�}�b�v�̍���           */
	WORD				bits		/* �r�b�g�}�b�v�̃r�b�g�[�x     */
)
{
	/* ���������̏ꍇ�͐����� */
	height = ( height < 0 ) ? -height: height;

	/* ���ƍ������|��������ƃo�C�g���ɂȂ� */
	return	BMPFILE_WIDTH_SIZE( width, bits ) * height;
}

/********** End of File ******************************************************/
