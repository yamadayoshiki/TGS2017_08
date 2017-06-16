/******************************************************************************
* File Name : GSload_bmp.h                         Ver : 1.00  Date : 16-03-17
*
* Description :
*
*       �r�b�g�}�b�v�t�@�C������e�N�X�`���C���[�W���쐬 ��`�w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_LOAD_BMP_FILE_H_
#define GS_LOAD_BMP_FILE_H_

#include <GStype.h>

#ifdef __cplusplus
extern "C" {
#endif

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
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
