/******************************************************************************
* File Name : GStext.h                           Ver : 1.00  Date : 2003-04-28
*
* Description :
*
*       ������`�� �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSTEXT_H_
#define		_GSTEXT_H_

#include	"GStype.h"

/****** �萔�錾 **************************************************************/

#define	GS_FONT_NORMAL		0			/* �����w��Ȃ�		*/
#define	GS_FONT_BOLD		( 1 << 0 )	/* ��������			*/
#define	GS_FONT_ITALIC		( 1 << 1 )	/* �C�^���b�N		*/
#define	GS_FONT_UNDERLINE	( 1 << 2 )	/* �A���_�[���C��	*/
#define	GS_FONT_STRIKEOUT	( 1 << 3 )	/* ������			*/

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

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
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
