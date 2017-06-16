/******************************************************************************
* File Name : GSoctree.h                         Ver : 1.00  Date : 2003-08-18
*
* Description :
*
*		�I�N�c���[ �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSOCTREE_H_
#define		_GSOCTREE_H_

#include	"GSmesh.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �I�N�c���[�m�[�h�\���� -----------------------------------------------*/

typedef	struct gsoctnode				/* �I�N�c���[�m�[�h�^			*/
{
	GSboolean			bLeafNode;		/* ���[�t�m�[�h�t���O			*/
	GSvector3			PosMin;			/* �m�[�h�̕�					*/
	GSvector3			PosMax;			/* �m�[�h�̒��S�_				*/
	GSmesh*				pMesh;			/* �m�[�h�̃��b�V���f�[�^		*/
	GSuint				DisplayList;	/* ���b�V���̃f�B�X�v���C���X�g	*/
	struct gsoctnode*	pNodes[8];		/* �q�m�[�h�ւ̃|�C���^			*/

} GSoctnode;

/*----- �I�N�c���[�\���� -----------------------------------------------------*/

typedef	struct							/* �I�N�c���[�^					*/
{
	GSmesh*				pMesh;			/* ���b�V���f�[�^				*/
	GSuint				numNodes;		/* �m�[�h�̐�					*/
	GSoctnode*			pNodes;			/* �I�N�c���[�̃m�[�h			*/

} GSoctree;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �I�N�c���[�̐����D
*
* Return  : �I�N�c���[��Ԃ��D
*
*============================================================================*/
extern GSoctree*
gsOctreeNew
(
	void
);

/*=============================================================================
*
* Purpose : �I�N�c���[�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDelete
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeCleanUp
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeLoadFile
(
	GSoctree*		pOctree,			/* �I�N�c���[�f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�t�@�C���̓ǂݍ��݁D(�V�F�[�_�[�p�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeLoadFileEx
(
	GSoctree*		pOctree,			/* �I�N�c���[�f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDraw
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D(�V�F�[�_�[�p�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDrawEx
(
	GSoctree*			pOctree,			/* �I�N�c���[�f�[�^		*/
	const GSmatrix4*	pProjectionMatrix,	/* �����ϊ��s��			*/
	const GSmatrix4*	pViewMatix			/* ����ϊ��s��			*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�Ɛ����̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionLine
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^				*/
	const GSvector3*	pLine0,			/* �����̎n�_					*/
	const GSvector3*	pLine1,			/* �����̏I�_					*/
	GSvector3*			pIntersect,		/*-> ���b�V���Ɛ����̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�ƃ��C�̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionRay
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^				*/
	const GSvector3*	pRayPos,		/* ���C�̎n�_					*/
	const GSvector3*	pRayDir,		/* ���C�̕���					*/
	GSvector3*			pIntersect,		/*-> ���b�V���ƃ��C�̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
);

/*=============================================================================
*
* Purpose : �I�N�c���[�Ƌ��̂̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionSphere
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^			*/
	const GSvector3*	pCenter,		/* ���̂̒��S				*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	GSvector3*			pOutCenter		/*-> �␳��̋��̒��S���W	*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
