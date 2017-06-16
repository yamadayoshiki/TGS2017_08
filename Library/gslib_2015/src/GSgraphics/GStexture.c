/******************************************************************************
* File Name : GStexture.c                        Ver : 1.00  Date : 2016-03-17
*
* Description :
*
*       �e�N�X�`���Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "GStexture.h"
#include "heap.h"
#include <opengl_ext.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void tex_image(GStexture* pTexture, const GLvoid* image);
static void tex_image_2D(GStexture* pTexture, const GLvoid* image);
static void tex_image_3D(GStexture* pTexture, const GLvoid* image);
static void tex_image_cube(GStexture* pTexture, const GLvoid* image);
static void tex_get_image(GStexture* pTexture, GLvoid* image);
static void tex_get_image_2D(GStexture* pTexture, GLvoid* image);
static void tex_get_image_3D(GStexture* pTexture, GLvoid* image);
static void tex_get_image_cube(GStexture* pTexture, GLvoid* image);
static GLsizei image_size(GStexture* pTexture, GLsizei mipLevel);
static GLsizei total_image_size(GStexture* pTexture);
static GLsizei mip_size(GLsizei size, GLint level);
static GLint mip_level(GLsizei size);
static void tex_filter(GStexture* pTexture);
static void tex_wrap(GStexture* pTexture);

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
	GLenum					type,
	GLsizei					width,
	GLsizei					height,
	GLsizei					depth,
	GLint					mipmap,
	const GSpixelFormat*	format,
	const GLvoid*			pImage
)
{
	GStexture*	pTexture;
	pTexture = new_object(sizeof(GStexture));
	pTexture->Type = type;
	pTexture->dwWidth = width;
	pTexture->dwHeight = height;
	pTexture->dwDepth = depth;
	pTexture->Mipmap = mipmap;
	pTexture->Format = *format;
	glGenTextures(1, &pTexture->dwTexName);
	glBindTexture(pTexture->Type, pTexture->dwTexName);
	tex_image(pTexture, pImage);
	tex_filter(pTexture);
	tex_wrap(pTexture);
	glBindTexture(pTexture->Type, 0);
	return pTexture;
}

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
)
{
	/* �e�N�X�`���I�u�W�F�N�g�̍폜 */
	glDeleteTextures(1, &pTexture->dwTexName);
	/* �e�N�X�`���̏��� */
	del_object(pTexture);
}

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
)
{
	glBindTexture(pTexture->Type, pTexture->dwTexName);
	glGenerateMipmap(pTexture->Type);
	pTexture->Mipmap = mip_level(pTexture->dwHeight < pTexture->dwWidth ? pTexture->dwHeight : pTexture->dwWidth);
	tex_filter(pTexture);
	glBindTexture(pTexture->Type, 0);
}

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
)
{
	return	pTexture->dwWidth;
}

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
)
{
	return	pTexture->dwHeight;
}

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
)
{
	return	pTexture->dwDepth;
}

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
)
{
	/* �e�N�`���I�u�W�F�N�g���o�C���h���� */
	glBindTexture(pTexture->Type, pTexture->dwTexName);
	glEnable(pTexture->Type);
}

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
)
{
	/* �e�N�`���I�u�W�F�N�g���A���o�C���h���� */
	glBindTexture(pTexture->Type, 0);
	glDisable(pTexture->Type);
}

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
)
{
	*pSize = total_image_size(pTexture);
	*ppImage = new_object(*pSize);
	gsTextureBind(pTexture);
	tex_get_image(pTexture, *ppImage);
	gsTextureUnbind(pTexture);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�N�X�`���C���[�W�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_image(GStexture* pTexture, const GLvoid* image)
{
	switch (pTexture->Type)
	{
	case GL_TEXTURE_2D: tex_image_2D(pTexture, image); break;
	case GL_TEXTURE_3D: tex_image_3D(pTexture, image); break;
	case GL_TEXTURE_CUBE_MAP: tex_image_cube(pTexture, image); break;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 2D�e�N�X�`���C���[�W�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_image_2D(GStexture* pTexture, const GLvoid* image)
{
	const unsigned char* base = (const unsigned char*)image;
	unsigned int offset = 0;
	GLint mipLevel = 0;
	for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
	{
		if (pTexture->Format.Complessed == GL_FALSE)
		{
			glTexImage2D(
				pTexture->Type,
				mipLevel,
				pTexture->Format.InternalFormat,
				mip_size(pTexture->dwWidth, mipLevel),
				mip_size(pTexture->dwHeight, mipLevel),
				0,
				pTexture->Format.Format,
				pTexture->Format.Type,
				(base != NULL) ? &base[offset] : NULL
			);
		}
		else
		{
			glCompressedTexImage2D(
				pTexture->Type,
				mipLevel,
				pTexture->Format.InternalFormat,
				mip_size(pTexture->dwWidth, mipLevel),
				mip_size(pTexture->dwHeight, mipLevel),
				0,
				image_size(pTexture, mipLevel),
				(base != NULL) ? &base[offset] : NULL
			);
		}
		offset += image_size(pTexture, mipLevel);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 3D�e�N�X�`���C���[�W�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_image_3D(GStexture* pTexture, const GLvoid* image)
{
	const unsigned char* base = (const unsigned char*)image;
	unsigned int offset = 0;
	GLint mipLevel;
	for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
	{
		if (pTexture->Format.Complessed == GL_FALSE)
		{
			glTexImage3D(
				pTexture->Type,
				mipLevel,
				pTexture->Format.InternalFormat,
				mip_size(pTexture->dwWidth,  mipLevel),
				mip_size(pTexture->dwHeight, mipLevel),
				mip_size(pTexture->dwDepth,  mipLevel),
				0,
				pTexture->Format.Format,
				pTexture->Format.Type,
				(base != NULL) ? &base[offset] : NULL
			);
		}
		else
		{
			glCompressedTexImage3D(
				pTexture->Type,
				mipLevel,
				pTexture->Format.InternalFormat,
				mip_size(pTexture->dwWidth,  mipLevel),
				mip_size(pTexture->dwHeight, mipLevel),
				mip_size(pTexture->dwDepth,  mipLevel),
				0,
				image_size(pTexture, mipLevel),
				(base != NULL) ? &base[offset] : NULL
			);
		}
		offset += image_size(pTexture, mipLevel);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : Cube�e�N�X�`���C���[�W�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_image_cube(GStexture* pTexture, const GLvoid* image)
{
	const unsigned char* base = (const unsigned char*)image;
	unsigned int offset = 0;
	GLenum target;
	for (target = GL_TEXTURE_CUBE_MAP_POSITIVE_X; target <= GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; ++target)
	{
		GLint mipLevel;
		for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
		{
			if (pTexture->Format.Complessed == GL_FALSE) {
				glTexImage2D(
					target,
					mipLevel,
					pTexture->Format.InternalFormat,
					mip_size(pTexture->dwWidth,  mipLevel),
					mip_size(pTexture->dwHeight, mipLevel),
					0,
					pTexture->Format.Format,
					pTexture->Format.Type,
					(base != NULL) ? &base[offset]: NULL
				);
			}
			else
			{
				glCompressedTexImage2D(
					target,
					mipLevel,
					pTexture->Format.InternalFormat,
					mip_size(pTexture->dwWidth,  mipLevel),
					mip_size(pTexture->dwHeight, mipLevel),
					0,
					image_size(pTexture, mipLevel),
					(base != NULL) ? &base[offset] : NULL
				);
			}
			offset += image_size(pTexture, mipLevel);
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�N�X�`���C���[�W�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_get_image(GStexture* pTexture, GLvoid* image)
{
	switch (pTexture->Type)
	{
	case GL_TEXTURE_2D: tex_get_image_2D(pTexture, image); break;
	case GL_TEXTURE_3D: tex_get_image_3D(pTexture, image); break;
	case GL_TEXTURE_CUBE_MAP: tex_get_image_cube(pTexture, image); break;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 2D�e�N�X�`���C���[�W�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_get_image_2D(GStexture* pTexture, GLvoid* image)
{
	unsigned char* base = (unsigned char*)image;
	unsigned int offset = 0;
	GLint mipLevel = 0;
	for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
	{
		if (pTexture->Format.Complessed == GL_FALSE)
		{
			glGetTexImage(
				pTexture->Type,
				mipLevel,
				pTexture->Format.Format,
				pTexture->Format.Type,
				&base[offset]
			);
		}
		else
		{
			glGetCompressedTexImage(
				pTexture->Type,
				mipLevel,
				&base[offset]
			);
		}
		offset += image_size(pTexture, mipLevel);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : 3D�e�N�X�`���C���[�W�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_get_image_3D(GStexture* pTexture, GLvoid* image)
{
	tex_get_image_2D(pTexture, image);
}

/*-----------------------------------------------------------------------------
*
* Purpose : Cube�e�N�X�`���C���[�W�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_get_image_cube(GStexture* pTexture, GLvoid* image)
{
	unsigned char* base = (unsigned char*)image;
	unsigned int offset = 0;
	GLenum target;
	for (target = GL_TEXTURE_CUBE_MAP_POSITIVE_X; target <= GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; ++target)
	{
		GLint mipLevel;
		for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
		{
			if (pTexture->Format.Complessed == GL_FALSE)
			{
				glGetTexImage(
					target,
					mipLevel,
					pTexture->Format.Format,
					pTexture->Format.Type,
					&base[offset]
				);
			}
			else
			{
				glGetCompressedTexImage(
					target,
					mipLevel,
					&base[offset]
				);
			}
			offset += image_size(pTexture, mipLevel);
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �C���[�W�T�C�Y�����߂�D
*
* Return  : �C���[�W�T�C�Y��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GLsizei image_size(GStexture* pTexture, GLsizei mipLevel)
{
	GLsizei w = mip_size(pTexture->dwWidth,  mipLevel);
	GLsizei h = mip_size(pTexture->dwHeight, mipLevel);
	GLsizei d = mip_size(pTexture->dwDepth,  mipLevel);
	if (pTexture->Format.Complessed == GL_TRUE)
	{
		w = (w + 3) / 4;
		h = (h + 3) / 4;
	}
	return w * h * d * pTexture->Format.Size;
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���C���[�W�T�C�Y���v�Z����D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GLsizei total_image_size(GStexture* pTexture)
{
	GLsizei result = 0;
	GLint mipLevel;
	for (mipLevel = 0; mipLevel < pTexture->Mipmap; ++mipLevel)
	{
		result += image_size(pTexture, mipLevel);
	}
	return (pTexture->Type == GL_TEXTURE_CUBE_MAP) ? result * 6 : result;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �~�b�v�}�b�v�T�C�Y�����߂�D
*
* Return  : �~�b�v�}�b�v�T�C�Y��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GLsizei mip_size(GLsizei size, GLint level)
{
	const GLint result = (size >> level);
	return (result <= 0) ? 1 : result;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �~�b�v�}�b�v���x�������߂�D
*
* Return  : �~�b�v�}�b�v���x����Ԃ��D
*
*----------------------------------------------------------------------------*/
static GLint mip_level(GLsizei size)
{
	GLint level = 1;
	while ((size >> level) > 0)
	{
		++level;
	}
	return level;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�N�X�`���t�B���^�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_filter(GStexture* pTexture)
{
	if (pTexture->Mipmap <= 1)
	{
		glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�N�X�`�����b�v���[�h�̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void tex_wrap(GStexture* pTexture)
{
	if (pTexture->Type == GL_TEXTURE_CUBE_MAP)
	{
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	}
	else
	{
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_R, GL_REPEAT);
	}
}

/********** End of File ******************************************************/
