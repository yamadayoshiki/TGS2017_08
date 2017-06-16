/******************************************************************************
* File Name : GStext.c                           Ver : 1.00  Date : 2003-04-28
*
* Description :
*
*       ������`��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GStext.h"
#include	"heap.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

static HFONT CreateFontHandler( GSuint, GSuint, const char* );
static GSboolean CreateStringBitmapFont( HFONT, const char*, BYTE**, PSIZEL );
static void CreateBitmapBits( HDC, HBITMAP, BYTE**, DWORD* );

/*=============================================================================
*
* Purpose : ������̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextDraw
(
	GSuint			FontCode,			/* �t�H���g�R�[�h				*/
	GSuint			FontPoint,			/* �t�H���g�̃|�C���g��			*/
	const char*		pFontName,			/* �t�H���g��					*/
	const char*		pString				/* ������						*/
)
{
	HFONT			hFont;
	BYTE*			pBitmap;
	SIZEL			BitmapSize;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );

	/* �e�N�X�`���𖳌��ɂ��� */
	glDisable( GL_TEXTURE_2D );
	glDisable( GL_TEXTURE_1D );

	/* �t�H���g���쐬���� */
	hFont = CreateFontHandler( FontCode, FontPoint, pFontName );

	/* �r�b�g�}�b�v�t�H���g�̍쐬 */
	if ( CreateStringBitmapFont( 
			hFont, pString, &pBitmap, &BitmapSize ) == GS_TRUE )
	{
		glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );

		/* �r�b�g�}�b�v�t�H���g��`�悷�� */
		glBitmap( BitmapSize.cx, BitmapSize.cy, 0.0f, (GLfloat)BitmapSize.cy, (GLfloat)BitmapSize.cx, 0.0f, pBitmap );

		/* �r�b�g�}�b�v�t�H���g�̉�� */
		del_object( pBitmap );
	}

	/* �t�H���g�����ł����� */
	DeleteObject( hFont );

	/* �����_�����O���[�h�̕��A */
	glPopAttrib();
}

/*-----------------------------------------------------------------------------
*
* Purpose : �����t�H���g�̍쐬�D
*
* Return  : �t�H���g�n���h����Ԃ��D
*
*----------------------------------------------------------------------------*/
static HFONT
CreateFontHandler
(
	GSuint		FontCode,			/* �t�H���g�R�[�h			*/
	GSuint		FontPoint,			/* �t�H���g�̃|�C���g��		*/
	const char*	pFontName			/* �t�H���g��				*/
)
{
	HFONT		hFont;
	DWORD		Bold;
	BOOL		bItalic;
	BOOL		bUline;
	BOOL		bSout;
	HDC			hDC;

	/* �t�H���g�̑�����ݒ肷�� */
	Bold    = ( ( FontCode & GS_FONT_BOLD      ) != 0 ) ? FW_BOLD: FW_NORMAL;
	bItalic = ( ( FontCode & GS_FONT_ITALIC    ) != 0 ) ? TRUE: FALSE;
	bUline  = ( ( FontCode & GS_FONT_UNDERLINE ) != 0 ) ? TRUE: FALSE;
	bSout   = ( ( FontCode & GS_FONT_STRIKEOUT ) != 0 ) ? TRUE: FALSE;

	/* �f�o�C�X�R���e�L�X�g�̎擾 */
	hDC = wglGetCurrentDC();

	/* �t�H���g���쐬���� */
	hFont = CreateFont
	(
		FontPoint, 0, 0, 0,
		Bold, bItalic, bUline, bSout,
		SHIFTJIS_CHARSET,
		OUT_STROKE_PRECIS,
		CLIP_CHARACTER_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		pFontName
	);

	return	hFont;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �����t�H���g�p�r�b�g�}�b�v�̍쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
CreateStringBitmapFont
(
	HFONT			hFont,			/* �t�H���g							*/
	const char*		pString,		/* ������							*/
	BYTE**			ppBitmap,		/*-> ������p�r�b�g�}�b�v			*/
	PSIZEL			pBitmapSize		/*-> ������p�r�b�g�}�b�v�̃T�C�Y	*/
)
{
	HDC				hDC;
	BITMAP			bmp;
	HBITMAP			hbmp;
	HFONT			hFontOld;
	HBITMAP			hPrevBmp;
	HFONT			hPrevFont;
	HDC				hMemDC;
	DWORD			BitsSize;
	BITMAP			bi;
	int				len;

	/* ������̒��������߂� */
	if ( ( len = lstrlen( pString ) ) == 0 )
	{
		return	GS_FALSE;
	}

	/* �f�o�C�X�R���e�L�X�g���擾 */
	hDC = wglGetCurrentDC();


	/* ���݂̃f�o�C�X�R���e�L�X�g�̃t�H���g�n���h�����擾 */
	hFontOld = SelectObject( hDC, hFont );

	/* �r�b�g�}�b�v������̃T�C�Y���擾���� */
	GetTextExtentPoint32( hDC, pString, len, pBitmapSize );

	/* �r�b�g�}�b�v���쐬���� */
	memset( &bmp, 0, sizeof( BITMAP ) );
	bmp.bmWidth      = pBitmapSize->cx;
	bmp.bmHeight     = pBitmapSize->cy;
	bmp.bmWidthBytes = ( ( pBitmapSize->cx + 7 ) / 8 + 1 ) & (~1);
	bmp.bmPlanes     = 1;
	bmp.bmBitsPixel  = 1;
	bmp.bmBits       = calloc( bmp.bmWidthBytes * pBitmapSize->cy, sizeof(BYTE) );
	hbmp = CreateBitmapIndirect( &bmp );

	/* �r�b�g�}�b�v�C���[�W��������� */
	del_object( bmp.bmBits );

	/* �r�b�g�}�b�v���쐬�ł������H */
	if ( hbmp == 0 )
	{
		/* �t�H���g�n���h���𕜋A���� */
		SelectObject( hDC, hFontOld );

		return	GS_FALSE;
	}

	/* �������f�o�C�X�R���e�L�X�g���쐬���� */
	if ( ( hMemDC = CreateCompatibleDC( hDC ) ) == 0 )
	{
		/* �t�H���g�n���h���𕜋A���� */
		SelectObject( hDC, hFontOld );

		/* �r�b�g�}�b�v��������� */
		DeleteObject( hbmp );

		return	GS_FALSE;
	}

	/* ���݂̃������f�o�C�X�R���e�X�g�̃r�b�g�}�b�v�n���h�����擾 */
	hPrevBmp = SelectObject( hMemDC, hbmp );

	/* ������̔w�i�F�����ɐݒ� */
	SetBkColor( hMemDC, RGB( 0, 0, 0 ) );

	/* �w�i�F�œh��Ԃ� */
	SetBkMode( hMemDC, OPAQUE );

	/* ������̃J���[�̐ݒ� */
	SetTextColor( hMemDC, RGB( 255, 255, 255 ) );

	/* ���݂̃������f�o�C�X�R���e�X�g�̃t�H���g�n���h�����擾 */
	hPrevFont = SelectObject( hMemDC, hFont );

	/* �e�L�X�g��`�悷�� */
	TextOut( hMemDC, 0, 0, pString, len );

	/* �r�b�g�}�b�v�̎擾 */
	GetObject( hbmp, sizeof(bi), &bi );

	/* �r�b�g�}�b�v�C���[�W�̍쐬 */
	CreateBitmapBits( hMemDC, hbmp, ppBitmap, &BitsSize );

	/* �r�b�g�}�b�v�C���[�W�̃T�C�Y���v�Z���� */
	pBitmapSize->cx = ( ( bi.bmWidth + 31 )& ( ~31 ) );
	pBitmapSize->cy = bi.bmHeight;

	/* �������f�o�C�X�R���e�X�g�̃t�H���g�n���h���𕜋A */
	SelectObject( hMemDC, hPrevFont );

	/* �������f�o�C�X�R���e�X�g�̃r�b�g�}�b�v�n���h���𕜋A */
	SelectObject( hMemDC, hPrevBmp );

	/* �������f�o�C�X�e�L�X�g���폜 */
	DeleteDC( hMemDC );

	/* �t�H���g�n���h���𕜋A���� */
	SelectObject( hDC, hFontOld );

	/* �r�b�g�}�b�v���폜���� */
	DeleteObject( hbmp );

	return	GS_TRUE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �����t�H���g�p�r�b�g�}�b�v�̍쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
CreateBitmapBits
(
	HDC				hDC,			/* �f�o�C�X�R���e�L�X�g				*/
	HBITMAP			hBmp,			/* �r�b�g�}�b�v�n���h��				*/
	BYTE**			ppBits,			/*-> �r�b�g�}�b�v�C���[�W			*/
	DWORD*			pBitsSize		/*-> �r�b�g�}�b�v�C���[�W�̃T�C�Y	*/
)
{
	BITMAP			bi;
	struct
	{
		BITMAPINFOHEADER bih;
		RGBQUAD col[2];
	} bic;
	BITMAPINFO* 	binf;

	/* �r�b�g�}�b�v���̍쐬 */
	binf = (BITMAPINFO *)&bic;

	/* �r�b�g�}�b�v���擾���� */
	GetObject( hBmp, sizeof(bi), &bi );

	/* �r�b�g�}�b�v�C���[�W�̃T�C�Y���v�Z���� */
	*pBitsSize = bi.bmHeight * ( ( ( bi.bmWidth + 31 ) & (~31)) / 8 );

	/* �r�b�g�}�b�v�̃C���[�W�𐶐����� */
	*ppBits = calloc( *pBitsSize, sizeof(BYTE) );

	binf->bmiHeader.biSize          = sizeof( binf->bmiHeader );
	binf->bmiHeader.biWidth         = bi.bmWidth;
	binf->bmiHeader.biHeight        = bi.bmHeight;
	binf->bmiHeader.biPlanes        = 1;
	binf->bmiHeader.biBitCount      = 1;
	binf->bmiHeader.biCompression   = BI_RGB;
	binf->bmiHeader.biSizeImage     = *pBitsSize;
	binf->bmiHeader.biXPelsPerMeter = 1;
	binf->bmiHeader.biYPelsPerMeter = 1;
	binf->bmiHeader.biClrUsed       = 0;
	binf->bmiHeader.biClrImportant  = 0;

	/* �r�b�g�}�b�v�C���[�W�̎擾 */
	GetDIBits( hDC, hBmp, 0, bi.bmHeight, *ppBits, binf, DIB_RGB_COLORS );
}

/********** End of File ******************************************************/
