/******************************************************************************
* File Name : GSload_dds.h                         Ver : 1.00  Date : 16-03-17
*
* Description :
*
*       DDS�t�@�C������e�N�X�`���C���[�W���쐬 ��`�w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_LOAD_DDS_FILE_H_
#define GS_LOAD_DDS_FILE_H_

#include <GStexture.h>

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : DDS�t�@�C������e�N�X�`���C���[�W���쐬�D
*
* Return  : �����ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadDDSFile
(
	const char*		szFlieName,		/* �ǂݍ��݃t�@�C����		*/
	GLenum*			type,			/* -> �e�N�X�`���^�C�v		*/
	GLsizei*		width,			/* -> ��					*/
	GLsizei*		height,			/* -> ����					*/
	GLsizei*		depth,			/* -> �[��					*/
	GLint*			mipmap,			/* -> �~�b�v�}�b�v			*/
	GSpixelFormat*	pFormat,		/* -> �s�N�Z���t�H�[�}�b�g	*/
	GLvoid**		ppImage			/* -> �C���[�W�f�[�^		*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
