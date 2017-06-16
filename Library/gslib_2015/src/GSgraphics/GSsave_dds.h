/******************************************************************************
* File Name : GSsave_dds.h                         Ver : 1.00  Date : 16-11-24
*
* Description :
*
*       �e�N�X�`���C���[�W��DDS�ŕۑ�����D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_SAVE_DDS_FILE_H_
#define GS_SAVE_DDS_FILE_H_

#include <GStexture.h>

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �e�N�X�`���C���[�W��DDS�t�@�C���ɕۑ��D
*
* Return  : �ۑ��ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsSaveDDSFile
(
	const char*				szFlieName,		/* �ǂݍ��݃t�@�C����	*/
	GLenum					type,			/* �e�N�X�`���^�C�v		*/
	GLsizei					width,			/* ��					*/
	GLsizei					height,			/* ����					*/
	GLsizei					depth,			/* �[��					*/
	GLint					mipmap,			/* �~�b�v�}�b�v			*/
	const GSpixelFormat*	pFormat,		/* �s�N�Z���t�H�[�}�b�g	*/
	const GLvoid*			pImage,			/* �C���[�W�f�[�^		*/
	GLsizei					imageSize		/* �C���[�W�f�[�^�T�C�Y	*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
