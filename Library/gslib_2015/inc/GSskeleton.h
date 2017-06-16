/******************************************************************************
* File Name : GSskeleto.h                        Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		�X�P���g�����Ǘ� �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSSKELETON_H_
#define		_GSSKELETON_H_

#include	"GStype.h"
#include	"GSmatrix4.h"

/****** �萔�錾 *************************************************************/

#define	GS_BONE_MAX	256					/* �{�[���f�[�^�̍ő吔		*/

/****** �f�[�^�^�錾 *********************************************************/

/*----- �{�[�����\���� ----------------------------------------------------*/

typedef	struct GSbone					/* �{�[�����\����			*/
{
	GSuint			BoneID;				/* �{�[���h�c				*/
	GSuint			ParentBoneID;		/* �e�{�[���h�c				*/
	GSvector3		ParentBoneOffset;	/* �e�{�[������̑��΍��W	*/
	GSmatrix4		matBoneOffset;		/* ���[�J�����W�ϊ��s��		*/
	struct GSbone*	pParent;			/* �e�{�[���ւ̃|�C���^		*/
	struct GSbone*	pSibling;			/* �Z��{�[���ւ̃|�C���^	*/
	struct GSbone*	pChild;				/* �q�{�[���ւ̃|�C���^		*/

} GSbone;

/*----- �X�P���g�����\���� ------------------------------------------------*/

typedef	struct GSskeleton				/* �X�P���g�����\����		*/
{
	GSuint			numBones;			/* �{�[���̐�				*/
	GSbone*			pBones;				/* �{�[���z��				*/

} GSskeleton;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �X�P���g���̏��̐����D
*
* Return  : �X�P���g������Ԃ��D
*
*============================================================================*/
extern GSskeleton*
gsSkeletonNew
(
	void
);

/*=============================================================================
*
* Purpose : �X�P���g�����̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSkeletonDelete
(
	GSskeleton*		pSkeleton			/* �X�P���g����� 			*/
);

/*=============================================================================
*
* Purpose : �X�P���g�����̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSkeletonCleanUp
(
	GSskeleton*		pSkeleton			/* �X�P���g����� 			*/
);

/*=============================================================================
*
* Purpose : �X�P���g�����t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsSkeletonLoadFile
(
	GSskeleton*			pSkeleton,		/* �X�P���g����� 			*/
	const char*			pszFileName		/* �X�P���g���t�@�C����		*/
);

/*=============================================================================
*
* Purpose : �p���ϊ��s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSkeletonCalculateOrientation
(
	GSskeleton*			pSkeleton,		/* �X�P���g����� 				*/
	GSmatrix4*			pOutMatrices,	/*-> �v�Z��̎p���ϊ��s��z��	*/
	const GSmatrix4*	pParentMatrix,	/* �e�̕ϊ��s��					*/
	const GSmatrix4*	pAnimMatrix		/* �A�j���[�V�����p�s��z��		*/
);

/*=============================================================================
*
* Purpose : ���W�ϊ��s��̌v�Z���s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSkeletonCalculateTransform
(
	GSskeleton*			pSkeleton,		/* �X�P���g����� 			*/
	GSmatrix4*			pOutMatrices,	/*-> ���W�ϊ��s��z��		*/
	const GSmatrix4*	pOrientMatrices	/* �p���ϊ��s��z��			*/
);

/*=============================================================================
*
* Purpose : �{�[���f�[�^�����擾�D
*
* Return  : �{�[���f�[�^����Ԃ��D
*
*============================================================================*/
extern GSuint
gsSkeletonGetNumBones
(
	GSskeleton*			pSkeleton		/* �X�P���g����� 			*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
