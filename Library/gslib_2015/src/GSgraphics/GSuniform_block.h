/******************************************************************************
* File Name : GSuniform_block.h                  Ver : 1.00  Date : 2016-11-27
*
* Description :
*
*        Uniform�u���b�N�Ǘ� �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSUNIFORMBLOCK_H_
#define		_GSUNIFORMBLOCK_H_

#include	"GStype.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- Uniform�u���b�N�\���� -----------------------------------------------*/

typedef struct
{
	GSuint			dwName;
	GSuint			dwSize;
} GSunifomBlock;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̐����D
*
* Return  : Uniform�u���b�N��Ԃ��D
*
*============================================================================*/
extern GSunifomBlock*
gsUnifomBlockNew
(
	GLsizei					Size,		/* �o�b�t�@�f�[�^�T�C�Y */
	const GLvoid*			pData		/* �o�b�t�@�f�[�^		*/
);

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUniformBlockDelete
(
	GSunifomBlock*		pUnifomBlock	/* Uniform�u���b�N		*/
);

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̃f�[�^�̍X�V�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUniformBlockUpdate
(
	GSunifomBlock*		pUnifomBlock,	/* Uniform�u���b�N		            */
	GLsizei				Size,			/* �X�V����o�b�t�@�f�[�^�̃o�C�g�� */
	GLsizei				Offset,			/* �X�V����ꏊ�̃I�t�Z�b�g         */
	const GLvoid*		pData			/* �X�V����o�b�t�@�f�[�^           */
);

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̃f�[�^�T�C�Y�̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsUniformBlockGetSize
(
	GSunifomBlock*		pUnifomBlock	/* Uniform�u���b�N		            */
);

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̃o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUniformBlockBind
(
	GSunifomBlock*		pUnifomBlock,	/* Uniform�u���b�N		            */
	GSuint				index			/* �o�C���h��̃C���f�b�N�X         */
);

/*=============================================================================
*
* Purpose : Uniform�u���b�N�̃A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUniformBlockUnbind
(
	GSunifomBlock*		pUnifomBlock,	/* Uniform�u���b�N		            */
	GSuint				index			/* �A���o�C���h��̃C���f�b�N�X     */
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
