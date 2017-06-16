/******************************************************************************
* File Name : GSsave_texture_file.c              Ver : 1.00  Date : 2016-03-17
*
* Description :
*
*      �e�N�X�`�����摜�t�@�C���ɕۑ�����D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_SAVE_TEXTURE_FILE_H_
#define GS_SAVE_TEXTURE_FILE_H_

#include <GStype.h>
#include <GStexture.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �e�N�X�`�����摜�t�@�C���ɕۑ�����D
*
* Return  : �����ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsSaveTextureFile
(
	const char*	szFlieName,		/* �ۑ��t�@�C����				*/
	GStexture*	pTexture		/* �e�N�X�`��					*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
