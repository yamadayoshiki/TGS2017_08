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
#include "GSsave_texture_file.h"
#include "GSsave_dds.h"
#include "heap.h"

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
)
{
	GSboolean result;
	/* �C���[�W�f�[�^�̎擾 */
	GSvoid* image;
	GSuint  size;
	gsTextureGetImage(pTexture, &size, &image);

	/* DDS�t�@�C���̕ۑ� */
	result = gsSaveDDSFile(
		szFlieName,
		pTexture->Type,
		pTexture->dwWidth, pTexture->dwHeight, pTexture->dwDepth,
		pTexture->Mipmap,
		&pTexture->Format,
		image, size);

	/* �C���[�W�f�[�^�̍폜 */
	del_object(image);

	return result;
}

/********** End of File ******************************************************/
