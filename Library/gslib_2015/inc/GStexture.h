/******************************************************************************
* File Name : GStexture.h                         Ver : 1.00  Date : 2002-08-13
*
* Description :
*
*       �e�N�X�`���Ǘ� �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSTEXTURE_H_
#define		_GSTEXTURE_H_

#include	"GStype.h"
#include	"GSpixel_format.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �e�N�X�`���\���� ----------------------------------------------------*/

typedef struct
{
	GSuint			Type;
	GSuint			dwTexName;
	GSuint			dwWidth;
	GSuint			dwHeight;
	GSuint			dwDepth;
	GSint			Mipmap;
	GSpixelFormat	Format;
} GStexture;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �e�N�X�`���̐����D
*
* Return  : �e�N�X�`����Ԃ��D
*
*============================================================================*/
extern GStexture*
gsTextureNew
(
	GLenum					type,			// �e�N�X�`���^�C�v
	GLsizei					width,			// ��
	GLsizei					height,			// ����
	GLsizei					depth,			// �[��
	GLint					mipmap,			// �~�b�v�}�b�v
	const GSpixelFormat*	format,			// �s�N�Z���t�H�[�}�b�g
	const GLvoid*			pImage			// �C���[�W�f�[�^
);

/*=============================================================================
*
* Purpose : �e�N�X�`���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureDelete
(
	GStexture*		pTexture			/* �e�N�X�`�� 			*/
);

/*=============================================================================
*
* Purpose : �~�b�v�}�b�v�̐����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureGenerateMipmap
(
	GStexture*		pTexture			/* �e�N�X�`�� 			*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`���̕��̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsTextureGetWidth
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`���̍����̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsTextureGetHeight
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`���̐[���̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsTextureGetDepth
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`�����̃o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureBind
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`�����̃A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureUnbind
(
	GStexture*		pTexture			/* �e�N�X�`�� 				*/
);

/*=============================================================================
*
* Purpose : �e�N�X�`���C���[�W�̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureGetImage
(
	GStexture*		pTexture,			/* �e�N�X�`�� 				*/
	GSuint*			pSize,				/*-> �C���[�W�T�C�Y         */
	GSvoid**		ppImage				/*-> �C���[�W�f�[�^         */
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
