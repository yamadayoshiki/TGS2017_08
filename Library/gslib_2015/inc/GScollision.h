/******************************************************************************
* File Name : GScollision.h                      Ver : 1.00  Date : 2002-03-24
*
* Description :
*
*       �Փ˔���̌v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSCOLLISION_H_
#define		_GSCOLLISION_H_

#include	"GStype.h"
#include	"GSmesh.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : ���̂Ƌ��̂̏Փ˔���D
*
* Return  : �Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionSphereAndSphere
(
	const GSvector3*	pCenter1,		/* ���̂P�̒��S					*/
	GSfloat				Radius1,		/* ���̂P�̔��a					*/
	const GSvector3*	pCenter2,		/* ���̂Q�̒��S					*/
	GSfloat				Radius2			/* ���̂Q�̔��a					*/
);

/*=============================================================================
*
* Purpose : �|���S���Ɛ����̏Փ˔���D
*
* Return  : �|���S���Ɛ������������Ă���ΐ^�C�������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionPolyAndLine
(
	const GSvector3*	pPoly,			/* �|���S���̒��_�z��				*/
	GSuint				numVertices,	/* ���_�f�[�^��						*/
	const GSplane*		pPlane,			/* �|���S���̕��ʕ������p�����[�^	*/
	const GSvector3*	pLine0,			/* �����̎n�_						*/
	const GSvector3*	pLine1,			/* �����̏I�_						*/
	GSvector3*			pIntersectPoint	/*-> �|���S���Ƃ̐�����_			*/
);

/*=============================================================================
*
* Purpose : �|���S���ƃ��C�̏Փ˔���D
*
* Return  : �|���S���ƃ��C���������Ă���ΐ^�C�������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionPolyAndRay
(
	const GSvector3*	pPoly,			/* �|���S���̒��_�z��				*/
	GSuint				numVertices,	/* ���_�f�[�^��						*/
	const GSplane*		pPlane,			/* �|���S���̕��ʕ������p�����[�^	*/
	const GSvector3*	pRayPos,		/* ���C�̎n�_						*/
	const GSvector3*	pRayDir,		/* ���C�̕���						*/
	GSvector3*			pIntersectPoint	/*-> �|���S���Ƃ̐�����_			*/
);

/*=============================================================================
*
* Purpose : �|���S���Ƌ��̂̏Փ˔���D
*
* Return  : �|���S���Ƌ��̂��Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionPolyAndSphere
(
	const GSvector3*	pPoly,			/* �|���S���̒��_�z��				*/
	GSuint				numVertices,	/* ���_�f�[�^��						*/
	const GSplane*		pPlane,			/* �|���S���̕��ʕ������p�����[�^	*/
	const GSvector3*	pCenter,		/* ���̂̒��S						*/
	GSfloat				Radius,			/* ���̂̔��a						*/
	GSvector3*			pOffset			/*-> ���̂��Փ˂��Ȃ����W�ւ̕␳�l	*/
);

/*=============================================================================
*
* Purpose : ���b�V���Ƌ��̂̏Փ˔���D
*
* Return  : ���b�V���Ƌ��̂��Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionMeshAndSphere
(
	const GSmesh*		pMesh,			/* ���b�V��					*/
	const GSvector3*	pCenter,		/* ���̂̒��S				*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	GSvector3*			pOutCenter		/* �␳��̋��̒��S���W		*/
);

/*=============================================================================
*
* Purpose : ���b�V���ƃ��C�̏Փ˔���D
*
* Return  : ���b�V���ƃ��C���������Ă���ΐ^�C�������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionMeshAndRay
(
	const GSmesh*		pMesh,			/* ���b�V��						*/
	const GSvector3*	pRayPos,		/* ���C�̎n�_					*/
	const GSvector3*	pRayDir,		/* ���C�̕���					*/
	GSvector3*			pIntersect,		/*-> ���b�V���ƃ��C�̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
);

/*=============================================================================
*
* Purpose : ���̂ƃ��C�̏Փ˔���D
*
* Return  : ���C�Ƌ��̂��Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionSphereAndRay
(
	const GSvector3*	pCenter,		/* ���̂̒��S���W				*/
	GSfloat				Radius,			/* ���̂̔��a					*/
	const GSvector3*	pRayPos,		/* ���C�̈ʒu					*/
	const GSvector3*	pRayDir,		/* ���C�̕���					*/
	GSvector3*			pIntersect		/*-> ���C�Ƃ̌�_				*/
);

/*=============================================================================
*
* Purpose : ���b�V���Ɛ����̏Փ˔���D
*
* Return  : ���b�V���Ɛ������������Ă���ΐ^�C�������Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionMeshAndLine
(
	const GSmesh*		pMesh,			/* ���b�V��						*/
	const GSvector3*	pLine0,			/* �����̎n�_					*/
	const GSvector3*	pLine1,			/* �����̏I�_					*/
	GSvector3*			pIntersect,		/*-> ���b�V���Ɛ����̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
);

/*=============================================================================
*
* Purpose : ���̂Ɛ����̏Փ˔���D
*
* Return  : ���̂Ƌ��̂��Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionSphereAndLine
(
	const GSvector3*	pCenter,		/* ���̂̒��S���W			*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	const GSvector3*	pLine0,			/* �����̎n�_				*/
	const GSvector3*	pLine1,			/* �����̏I�_				*/
	GSvector3*			pIntersect		/*-> �����Ƃ̌�_			*/
);

/*=============================================================================
*
* Purpose : �����Ɛ����̏Փ˔���D
*
* Return  : �����Ɛ������Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionLineAndLine
(
	const GSvector3*	pA1,			/* �������̎n�_						*/
	const GSvector3*	pA2,			/* �������̏I�_						*/
	const GSvector3*	pB1,			/* �������̎n�_						*/
	const GSvector3*	pB2,			/* �������̏I�_						*/
	GSboolean			bInfinite,		/* �����������H						*/
	GSfloat				Epsilon,		/* �����臒l						*/
	GSvector3*			pPA,			/*-> ��������̐������ɍł��߂����W	*/
	GSvector3*			pPB				/*-> ��������̐������ɍł��߂����W	*/
);

/*=============================================================================
*
* Purpose : �J�v�Z���ƃJ�v�Z���̏Փ˔���D
*
* Return  : �J�v�Z�����Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsCollisionCapsuleAndCapsule
(
	const GSvector3*	pA1,			/* �J�v�Z�����̎n�_					*/
	const GSvector3*	pA2,			/* �J�v�Z�����̏I�_					*/
	const float			Aw,				/* �J�v�Z�����̕�					*/
	const GSvector3*	pB1,			/* �J�v�Z�����̎n�_					*/
	const GSvector3*	pB2,			/* �J�v�Z�����̏I�_					*/
	const float			Bw,				/* �J�v�Z�����̕�					*/
	GSvector3*			pNa,			/*-> ��������̐������ɍł��߂����W	*/
	GSvector3*			pNb				/*-> ��������̐������ɍł��߂����W	*/

);

#ifdef __cplusplus
}
#endif

/****** �}�N���֐��錾 *******************************************************/

/*=============================================================================
*
* Purpose : �_�Ƌ�`�̏Փ˔���D
*
* Return  : �Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
#define	gsCollisionPointAndRect( p, r )										\
(																			\
   ( ( (r)->left <= (p)->x ) && ( (r)->right  >= (p)->x )					\
  && ( (r)->top  <= (p)->y ) && ( (r)->bottom >= (p)->y ) )					\
  ? GS_TRUE: GS_FALSE														\
)

/*=============================================================================
*
* Purpose : ��`�Ƌ�`�̏Փ˔���D
*
* Return  : �Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
#define	gsCollisionRectAndRect( r1, r2 )									\
(																			\
   ( ( (r2)->left <= (r1)->right  ) && ( (r1)->left <= (r2)->right  )		\
  && ( (r2)->top  <= (r1)->bottom ) && ( (r1)->top  <= (r2)->bottom ) )		\
  ? GS_TRUE: GS_FALSE														\
)

#endif

/********** End of File ******************************************************/
