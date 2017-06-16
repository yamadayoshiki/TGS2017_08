/******************************************************************************
* File Name : GSload_texture_file.c              Ver : 1.00  Date : 2016-03-17
*
* Description :
*
*       �摜�t�@�C������e�N�X�`�����쐬����D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "GSload_texture_file.h"
#include "GSload_png.h"
#include "GSload_bmp.h"
#include "GSload_dds.h"
#include "GSfile_path.h"
#include <stdlib.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static GStexture* create_texture_from_bmp(const char* szFlieName);
static GStexture* create_texture_from_png(const char* szFlieName);
static GStexture* create_texture_from_dds(const char* szFlieName);

/* RGBA32�s�N�Z���t�H�[�}�b�g */
static const GSpixelFormat RGBA32 = { GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, 4, GL_FALSE };

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
)
{
	GStexture* pTexture = NULL;
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char texture_file[_MAX_PATH];
	gsSplitPath(szFlieName, drive, dir, fname, NULL);

	/* DDS -> png -> bmp�̗D�揇�ʂœǂݍ��݂����� */

	/* DDS�t�@�C���̓ǂݍ��� */
	gsMakePath(texture_file, drive, dir, fname, ".dds");
	if ((pTexture = create_texture_from_dds(texture_file)) != NULL) {
		return pTexture;
	}
	/* PNG�t�@�C���̓ǂݍ��� */
	gsMakePath(texture_file, drive, dir, fname, ".png");
	if ((pTexture = create_texture_from_png(texture_file)) != NULL) {
		return pTexture;
	}
	/* BMP�t�@�C���̓ǂݍ��� */
	gsMakePath(texture_file, drive, dir, fname, ".bmp");
	if ((pTexture = create_texture_from_bmp(texture_file)) != NULL) {
		return pTexture;
	}
	return NULL;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �摜�t�@�C������e�N�X�`�����쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GStexture*
load_texture_file
(
	const char*	szFlieName		/* �ǂݍ��݃t�@�C����			*/
)
{
	/* �t�@�C���̊g���q�����o�� */
	char ext[_MAX_EXT];
	gsSplitPath(szFlieName, NULL, NULL, NULL, ext);
	if (_stricmp(ext, ".bmp") == 0)
	{
		return create_texture_from_bmp(szFlieName);
	}
	if (_stricmp(ext, ".png") == 0)
	{
		return create_texture_from_png(szFlieName);
	}
	if (_stricmp(ext, ".dds") == 0)
	{
		return create_texture_from_dds(szFlieName);
	}
	return NULL;
}

/*-----------------------------------------------------------------------------
*
* Purpose : BMP�t�@�C������e�N�X�`�����쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GStexture*
create_texture_from_bmp
(
	const char*	szFlieName		/* �ǂݍ��݃t�@�C����			*/
)
{
	GSuint	width;
	GSuint	height;
	GSvoid*	image;
	GStexture* texture;
	// BMP�t�@�C���̓ǂݍ���
	if (gsLoadBmpFile(szFlieName, &width, &height, &image) == GS_FALSE)
	{
		return NULL;
	}
	// �e�N�X�`���̍쐬
	texture = gsTextureNew(GL_TEXTURE_2D, width, height, 1, 1, &RGBA32, image);
	// �C���[�W�f�[�^�̉��
	free(image);
	return texture;
}

/*-----------------------------------------------------------------------------
*
* Purpose : PNG�t�@�C������e�N�X�`�����쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GStexture*
create_texture_from_png
(
	const char*	szFlieName		/* �ǂݍ��݃t�@�C����			*/
)
{
	GSuint  width;
	GSuint  height;
	GSvoid*	image;
	GStexture* texture;
	// PNG�t�@�C���̓ǂݍ���
	if (gsLoadPngFile(szFlieName, &width, &height, &image) == GS_FALSE)
	{
		return NULL;
	}
	// �e�N�X�`���̍쐬
	texture = gsTextureNew(GL_TEXTURE_2D, width, height, 1, 1, &RGBA32, image);
	// �C���[�W�f�[�^�̉��
	free(image);
	return texture;
}

/*-----------------------------------------------------------------------------
*
* Purpose : DDS�t�@�C������e�N�X�`�����쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GStexture*
create_texture_from_dds
(
	const char*	szFlieName		/* �ǂݍ��݃t�@�C����			*/
)
{
	GLenum			type;
	GLsizei			width;
	GLsizei			height;
	GLsizei			depth;
	GLint			mipmap;
	GSpixelFormat	format;
	GLvoid*			image;
	GStexture*		texture;
	// DDS�t�@�C���̓ǂݍ���
	if (gsLoadDDSFile(szFlieName, &type, &width, &height, &depth, &mipmap, &format, &image) == GS_FALSE)
	{
		return NULL;
	}
	// �e�N�X�`���̍쐬
	texture = gsTextureNew(type, width, height, depth, mipmap, &format, image);
	// �C���[�W�f�[�^�̉��
	free(image);
	return texture;
}

/********** End of File ******************************************************/
