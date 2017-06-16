/******************************************************************************
* File Name : gtexload_bmp.c                     Ver : 1.00  Date : 2014-07-31
*
* Description :
*
*       png�t�@�C������e�N�X�`���f�[�^��ǂݍ��ށD
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSload_png.h"
#include	"lodepng.h"

/*=============================================================================
*
* Purpose : Png�}�b�v�t�@�C������e�N�X�`���𐶐�����D
*
* Return  : �����ɐ�������ΐ^�C���s������U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadPngFile
(
	const char*			szFlieName,		/* �ǂݍ��݃t�@�C����			*/
	GSuint*				width,			/* -> ��						*/
	GSuint*				height,			/* -> ����						*/
	GSvoid**			image			/* -> �摜�f�[�^				*/
)
{
	/* png�t�@�C���̓ǂݍ��� */
	unsigned error = lodepng_decode32_file((unsigned char**)image, width, height, szFlieName);
	if (error != 0) {
		return GS_FALSE;
	}
	return GS_TRUE;
}

/********** End of File ******************************************************/
