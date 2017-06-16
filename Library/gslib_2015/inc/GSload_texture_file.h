/******************************************************************************
* File Name : GSload_texture_file.h              Ver : 1.00  Date : 2016-03-17
*
* Description :
*
*       �摜�t�@�C������e�N�X�`�����쐬����D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef GS_LOAD_TEXTURE_FILE_H_
#define GS_LOAD_TEXTURE_FILE_H_

#include <GStexture.h>

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �摜�t�@�C������e�N�X�`���𐶐�����D
*
* Return  : �����ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GStexture*
gsLoadTextureFile
(
	const char*	szFlieName		/* �ǂݍ��݃t�@�C����			*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
