/******************************************************************************
* File Name : gskeleton.c                        Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �X�P���g�����Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSskeleton.h"
#include	"GSmatrix4.h"
#include	"gfile.h"
#include	"heap.h"
#include	<string.h>
#include	<memory.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void		 gsSkeletonLinkBone( GSskeleton* );
static void		 gsBoneAddChild( GSbone*, GSbone* );
static void		 gsBoneCalculate( GSbone*, GSmatrix4*, const GSmatrix4*, const GSmatrix4* );
static GSboolean gsBoneLoadFile( GSbone*, GFILE );

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
)
{
	GSskeleton*		pSkeleton;

	pSkeleton = new_object( sizeof(GSskeleton) );

	memset( pSkeleton, 0, sizeof(GSskeleton ) );

	return	pSkeleton;
}

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
)
{
	/* �{�[���f�[�^�N���[���A�b�v */
	gsSkeletonCleanUp( pSkeleton );

	/* �X�P���g���������� */
	del_object( pSkeleton );
}

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
)
{
	if ( pSkeleton->pBones != NULL );
	{
		del_object( pSkeleton->pBones );

		pSkeleton->pBones = NULL;
	}
	pSkeleton->numBones = 0;
}

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
	GSskeleton*		pSkeleton,			/* �X�P���g����� 			*/
	const char*		pszFileName			/* �X�P���g���t�@�C����		*/
)
{
	GFILE			file;
	GSboolean		fError;
	GSuint			i;

	/* �X�P���g�����t�@�C���̃I�[�v�� */
	if ( ( file = GFileOpen( pszFileName, "r" ) ) == NULL )
	{
		return	GS_FALSE;
	}

	/* �X�P���g�����̃N���[���A�b�v */
	gsSkeletonCleanUp( pSkeleton );

	/* �{�[���̐���ǂݍ��� */
	GFileReadDword( file, &pSkeleton->numBones );

	/* �X�P���g�����̏����� */
	pSkeleton->pBones = new_object( sizeof( GSbone ) * pSkeleton->numBones );

	memset( pSkeleton->pBones, 0, sizeof( GSbone ) * pSkeleton->numBones );

	/* �{�[�����̓ǂݍ��� */
	for ( i = 0; i < pSkeleton->numBones; i++ )
	{
		gsBoneLoadFile( &pSkeleton->pBones[i], file );
	}

	/* �t�@�C���̓ǂݍ��݂��������� */
	if ( ( fError = GFileIsSuccess( file ) ) == GS_TRUE )
	{
		/* �e�q�Z��̃����N������ */
		gsSkeletonLinkBone( pSkeleton );
	}

	/* �X�P���g�����t�@�C�����N���[�Y���� */
	GFileClose( file );

	return	fError;
}

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
)
{
	/* �e�{�[���̍��W�ϊ����s�� */
	gsBoneCalculate
	(
		&pSkeleton->pBones[0],
		pOutMatrices,
		pParentMatrix,
		pAnimMatrix
	);
}

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
)
{
	GSuint				i;

	/* ���[�J�����W�ϊ��s��Ǝp���ϊ��s����������� */
	for ( i = 0; i < pSkeleton->numBones; i++ )
	{
		gsMatrix4Multiply
		(
			&pOutMatrices[i],
			&pSkeleton->pBones[i].matBoneOffset,
			&pOrientMatrices[i]
		);
	}
}

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
)
{
	return	pSkeleton->numBones;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�{�[���̊K�w�\����ݒ肷��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsSkeletonLinkBone
(
	GSskeleton*		pSkeleton			/* �X�P���g����� 			*/
)
{
	GSbone*			pParentBone;
	GSbone*			pChildBone;
	GSuint			i;
	GSuint			j;

	for ( i = 0; i < pSkeleton->numBones; i++ )
	{
		/* �e�{�[���̎擾 */
		pParentBone = &pSkeleton->pBones[i];
		for ( j = 1; j < pSkeleton->numBones; j++ )
		{
			/* �q�{�[���̎擾 */
			pChildBone = &pSkeleton->pBones[j];

			/* �e�{�[���̂h�c�������Ă���{�[�����H */
			if ( pParentBone->BoneID == pChildBone->ParentBoneID )
			{
				/* �e�{�[���Ɏq�{�[���������N������ */
				gsBoneAddChild( pParentBone, pChildBone );
			}
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�{�[���Ɏq�{�[����ݒ肷��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsBoneAddChild
(
	GSbone*		pParentBone,			/* �e�{�[��					*/
	GSbone*		pChildBone				/* �q�{�[��					*/
)
{
	/* �e�|�C���^�̃����N������ */
	pChildBone->pParent  = pParentBone;
	pChildBone->pSibling = pParentBone->pChild;
	pParentBone->pChild  = pChildBone;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �{�[���̕ϊ��s��̌v�Z���s���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsBoneCalculate
(
	GSbone*				pBone,			/* �{�[�����				*/
	GSmatrix4*			pOutMatrices,	/*-> �v�Z��̕ϊ��s��z��	*/
	const GSmatrix4*	pParentMatrix,	/* �e�̕ϊ��s��				*/
	const GSmatrix4*	pAnimMatrices	/* �A�j���[�V�����p�s��z��	*/
)
{
	GSmatrix4*			pOutMatrix;

	/* �ϊ���̍s����擾 */
	pOutMatrix = &pOutMatrices[ pBone->BoneID ];

	/* �s��̏����� */
	gsMatrix4Identity( pOutMatrix );

	/* �A�j���[�V�����ϊ��s��̎擾 */
	if (pAnimMatrices != NULL)
	{
		*pOutMatrix = pAnimMatrices[pBone->BoneID];
	}

	/* �e����̑��΍��W�����f�����O�ϊ��s��ɉ����� */
	pOutMatrix->m[3][0] += pBone->ParentBoneOffset.x;
	pOutMatrix->m[3][1] += pBone->ParentBoneOffset.y;
	pOutMatrix->m[3][2] += pBone->ParentBoneOffset.z;

	/* �e�̕ϊ��s����������� */
	if ( pParentMatrix != NULL )
	{
		/* �e�̕ϊ��s��ƍ��� */
		gsMatrix4Multiply( pOutMatrix, pOutMatrix, pParentMatrix );
	}

	/* �Z��������Ă���ΌZ����v�Z������ */
	if ( pBone->pSibling != NULL )
	{
		gsBoneCalculate
		(
			pBone->pSibling,
			pOutMatrices,
			pParentMatrix,
			pAnimMatrices
		);
	}

	/* �q���������Ă���Ύq�����v�Z������ */
	if ( pBone->pChild != NULL )
	{
		gsBoneCalculate
		(
			pBone->pChild,
			pOutMatrices,
			pOutMatrix,
			pAnimMatrices
		);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �{�[�����̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsBoneLoadFile
(
	GSbone*		pBone,					/* �{�[�����				*/
	GFILE		file					/* �t�@�C���n���h��			*/
)
{
	/* �{�[���h�c�̓ǂݍ��� 	*/
	GFileReadDword( file, &pBone->BoneID );

	/* �e�{�[���h�c�̓ǂݍ��� */
	GFileReadDword( file, &pBone->ParentBoneID );

	/* �e����̑��΍��W�̓ǂݍ��� */
	GFileReadVector3( file, &pBone->ParentBoneOffset );

	/* ���[�J�����W�ϊ��s��̓ǂݍ��� */
	GFileReadMatrix4( file, &pBone->matBoneOffset );

	/* �e�q�Z��̃|�C���^�������� */
	pBone->pParent  = NULL;
	pBone->pSibling = NULL;
	pBone->pChild   = NULL;

	return	GFileIsSuccess( file );
}

/********** End of File ******************************************************/
