/******************************************************************************
* File Name : GSuniform_block.c                  Ver : 1.00  Date : 2016-11-27
*
* Description :
*
*        Uniform�u���b�N�Ǘ� �\�[�X�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "GSuniform_block.h"
#include "heap.h"
#include <opengl_ext.h>

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
)
{
	GSunifomBlock*	pUnifomBlock;
	pUnifomBlock = new_object(sizeof(GSunifomBlock));
	pUnifomBlock->dwSize = Size;
	glGenBuffers(1, &pUnifomBlock->dwName);
	glBindBuffer(GL_UNIFORM_BUFFER, pUnifomBlock->dwName);
	glBufferData(GL_UNIFORM_BUFFER, Size, pData, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	return pUnifomBlock;
}

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
)
{
	glDeleteBuffers(1, &pUnifomBlock->dwName);
	del_object(pUnifomBlock);
}

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
)
{
	glBindBuffer(GL_UNIFORM_BUFFER, pUnifomBlock->dwName);
	glBufferSubData(GL_UNIFORM_BUFFER, Offset, Size, pData);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

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
)
{
	return pUnifomBlock->dwSize;
}

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
)
{
	glBindBufferBase(GL_UNIFORM_BUFFER, index, pUnifomBlock->dwName);
}

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
)
{
	(void)pUnifomBlock;
	glBindBufferBase(GL_UNIFORM_BUFFER, index, 0);
}

/********** End of File ******************************************************/
