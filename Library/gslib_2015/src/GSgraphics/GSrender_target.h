/******************************************************************************
* File Name : GSrender_target.h                  Ver : 1.00  Date : 2016-03-21
*
* Description :
*
*		�����_�[�^�[�Q�b�g �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSRENDER_TARGAT_H_
#define		_GSRENDER_TARGAT_H_

#include	"GStype.h"
#include	"GStexture.h"

/****** �萔�錾 *************************************************************/

#define GS_MRT_MAX				8

/****** �f�[�^�^�錾 *********************************************************/

/*----- �����_�[�^�[�Q�b�g�\���� --------------------------------------------*/

typedef	struct
{
	/* ��							*/
	GSuint		Width;
	/* ����							*/
	GSuint		Height;
	/* �t���[���o�b�t�@�I�u�W�F�N�g */
	GLuint		FrameBuffer;
	/* �J���[�o�b�t�@��				*/
	GLuint		NumColorBuffer;
	/* �J���[�o�b�t�@�e�X�N�`��		*/
	GStexture*	ColorBuffers[GS_MRT_MAX];
	/* �f�v�X�o�b�t�@�e�X�N�`��		*/
	GStexture*	DepthBuffer;
} GSrendertarget;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̐����D
*
* Return  : �����_�[�^�[�Q�b�g��Ԃ��D
*
*============================================================================*/
extern GSrendertarget*
gsRenderTargetNew
(
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	GSuint					numColorBuffer,	/* �J���[�o�b�t�@��				*/
	const GSpixelFormat		colorBuffer[],	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/

);

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̐����D
*
* Return  : �L���[�u�}�b�v�����_�[�^�[�Q�b�g��Ԃ��D
*
*============================================================================*/
extern GSrendertarget*
gsRenderTargetCubeNew
(
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	const GSpixelFormat*	colorBuffer,	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/

);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDelete
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBegin
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�I���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetEnd
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetCubeBegin
(
	GSrendertarget*			pRenderTarge,	/* �����_�[�^�[�Q�b�g	  */
	GSuint					faceNo			/* �L���[�u�}�b�v�̖ʔԍ� */
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBindColorBufferTexture
(
	GSrendertarget*			pRenderTarget,	/* �����_�[�^�[�Q�b�g	*/
	GSuint					no				/* �J���[�o�b�t�@�̔ԍ�	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBindDepthBufferTexture
(
	GSrendertarget*			pRenderTarge	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetUnbindColorBufferTexture
(
	GSrendertarget*			pRenderTarget,	/* �����_�[�^�[�Q�b�g	*/
	GSuint					no				/* �J���[�o�b�t�@�̔ԍ�	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetUnbindDepthBufferTexture
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDraw
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDrawEx
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕����擾
*
* Return  : �����_�[�^�[�Q�b�g�̕���Ԃ��D
*
*============================================================================*/
extern GSuint
gsRenderTargetGetWidth
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍������擾
*
* Return  : �����_�[�^�[�Q�b�g�̍�����Ԃ��D
*
*============================================================================*/
extern GSuint
gsRenderTargetGetHeight
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
