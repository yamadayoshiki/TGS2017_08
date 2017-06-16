/******************************************************************************
* File Name : GSplane.c                          Ver : 1.00  Date : 2002-03-24
*
* Description :
*
*       ���ʂ̌v�Z�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSplane.h"
#include	"GSvector3.h"
#include	<float.h>

/*=============================================================================
*
* Purpose : ���ʏ�̍��W�ƕ��ʂ̖@���x�N�g�����畽�ʂ��쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsPlaneFromPointNormal
(
	GSplane* 			pOut,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pPoint,			/* ���ʏ�̍��W			*/
	const GSvector3*	pNormal			/* ���ʂ̖@���x�N�g��	*/
)
{
	pOut->a = pNormal->x;
	pOut->b = pNormal->y;
	pOut->c = pNormal->z;
	pOut->d = -gsVector3Dot( pNormal, pPoint );
}

/*=============================================================================
*
* Purpose : ���ʏ�̂R�̍��W���畽�ʂ��쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsPlaneFromPoints
(
	GSplane* 			pOut,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pV1,			/* ���ʂ��\��������W�P	*/
	const GSvector3*	pV2,			/* ���ʂ��\��������W�Q	*/
	const GSvector3*	pV3				/* ���ʂ��\��������W�R	*/
)
{
	GSvector3			Normal;

	/* �@���x�N�g�������߂� */
	gsVector3CalculateNormal( &Normal, pV1, pV2, pV3 );

	/* �@���x�N�g���ƍ��W���畽�ʂ̃p�����[�^�����߂� */
	gsPlaneFromPointNormal( pOut, pV1, &Normal );
}

/*=============================================================================
*
* Purpose : ���ʏ�̓_�̍��W�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsPlanePoint
(
	const GSplane*		pPlane,			/* ���ʕ������p�����[�^	*/
	GSvector3*			pPoint			/*-> ���ʏ�̓_�̍��W	*/
)
{
	pPoint->x = pPlane->a * -pPlane->d;
	pPoint->y = pPlane->b * -pPlane->d;
	pPoint->z = pPlane->c * -pPlane->d;
}

/*=============================================================================
*
* Purpose : ���ʂƂR�����x�N�g���̓��ς����߂�D( w = 1.0�Ƃ��� )
*
* Return  : ���ς�Ԃ��D
*
*============================================================================*/
extern GSfloat
gsPlaneDotNormal
(
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	return	pPlane->a * pV->x + pPlane->b * pV->y + pPlane->c * pV->z;
}

/*=============================================================================
*
* Purpose : ���ʂƂR�����x�N�g���̓��ς����߂�D( w = 0.0�Ƃ��� )
*
* Return  : ���ς�Ԃ��D
*
*============================================================================*/
extern GSfloat
gsPlaneDotCoord
(
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	return	pPlane->a * pV->x
		  + pPlane->b * pV->y
		  + pPlane->c * pV->z
		  + pPlane->d;
}

/*=============================================================================
*
* Purpose : ���ʂ𐳋K������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsPlaneNormalize
(
	GSplane*			pOut,			/* ���ʂƐ����̌�_�̍��W	*/
	const GSplane* 		pPlane			/* ���ʕ������p�����[�^		*/
)
{
	GSfloat				Len;

	Len = gsSqrt( SQR( pPlane->a ) + SQR( pPlane->b ) + SQR( pPlane->c ) );

	if ( Len != 0 )
	{
		pOut->a = pPlane->a / Len;
		pOut->b = pPlane->b / Len;
		pOut->c = pPlane->c / Len;
		pOut->d = pPlane->d / Len;
	}
}

/*=============================================================================
*
* Purpose : ���ʂ̍��W�ϊ����s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsPlaneTransform
(
	GSplane*			pOut,			/*-> �ϊ���̕��ʕ������p�����[�^	*/
	const GSplane*		pPlane,			/* ���ʕ������p�����[�^				*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��						*/
)
{
	GSvector3			P;
	GSvector3			N;

	/* ���ʏ�̍��W�����߂� */
	gsPlanePoint( pPlane, &P );

	/* ���ʏ�̍��W��ϊ����� */
	gsVector3TransformCoord( &P, &P, pM );

	/* �@���x�N�g���̍��W�ϊ� */
	N.x = pPlane->a * pM->m[0][0]
	    + pPlane->b * pM->m[1][0]
	    + pPlane->c * pM->m[2][0];
	N.y = pPlane->a * pM->m[0][1]
	    + pPlane->b * pM->m[1][1]
	    + pPlane->c * pM->m[2][1];
	N.z = pPlane->a * pM->m[0][2]
	    + pPlane->b * pM->m[1][2]
	    + pPlane->c * pM->m[2][2];

	/* ���W�Ɩ@�����畽�ʂ����߂� */
	gsPlaneFromPointNormal( pOut, &P, &N );
}

/*=============================================================================
*
* Purpose : ���ʂƐ������������邩���ׂ�D
*
* Return  : ��������ΐ^�C�������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsPlaneIntersected
(
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pLine0,			/* �����̎n�_			*/
	const GSvector3*	pLine1			/* �����̏I�_			*/
)
{
	GSfloat				Distance1;
	GSfloat				Distance2;

	/* ���ʂƎn�_�̋��������߂� */
	Distance1 = gsPlaneDotCoord( pPlane, pLine0 );

	/* ���ʂƏI�_�̋��������߂� */
	Distance2 = gsPlaneDotCoord( pPlane, pLine1 );

	/* �n�_�ƏI�_�̋������������̏ꍇ�͌������Ȃ� */
	if ( ( Distance1 * Distance2 ) > 0 )
	{
		return	GS_FALSE;
	}

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : ���ʂƃ��C������������W�����߂�D
*
* Return  : ��������ΐ^�C�������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsPlaneIntersectRay
(
	GSvector3*			pOut,			/* ���ʂƐ����̌�_�̍��W	*/
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^		*/
	const GSvector3*	pRayPos,		/* ���C�̎n�_				*/
	const GSvector3*	pRayDir			/* ���C�̕���				*/
)
{
	GSvector3			Normal;
	GSfloat				Denominator;
	GSfloat				Numerator;
	GSfloat				Distance;

	/* �����̕����𐳋K������ */
	gsVector3Normalize( &Normal, pRayDir );

	/* ��������߂� */
	Denominator = gsPlaneDotNormal( pPlane, &Normal );

	/* ���ꂪ�O�̏ꍇ�͕��ʂƒ��������s�ƂȂ� */
	if( Denominator == 0.0f )
	{
		return	GS_FALSE;
	}

	if ( pOut != NULL )
	{
		/* ���q�����߂� */
		Numerator = -gsPlaneDotCoord( pPlane, pRayPos );

		/* �n�_�ƕ��ʂ̋��������߂� */
		Distance = Numerator / Denominator;

		/* ��_�����߂� */
		gsVector3LinearEquation( pOut, pRayPos, &Normal, Distance );
	}

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : ���ʂƐ���������������W�����߂�D
*
* Return  : ��������ΐ^�C�������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsPlaneIntersectLine
(
	GSvector3*			pOut,			/* ���ʂƐ����̌�_�̍��W	*/
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^		*/
	const GSvector3*	pLine0,			/* �����̎n�_				*/
	const GSvector3*	pLine1			/* �����̏I�_				*/
)
{
	GSvector3			Direction;

	/* ���ʂƐ�������_�������H */
	if ( gsPlaneIntersected( pPlane, pLine0, pLine1 ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	gsVector3Subtract( &Direction, pLine1, pLine0 ); 

	/* ���ʂƐ����̌�_�����߂� */
	return	gsPlaneIntersectRay( pOut, pPlane, pLine0, &Direction );
}

/*=============================================================================
*
* Purpose : ���ʂƍ��W�̈ʒu�֌W��Ԃ��D
*
* Return  : ���ʂ̐��ʁC���ʂ̗��ʁC���ʏ�ɂ���̉��ꂩ��Ԃ��D
*
*           ����   : GS_FRONT_PLANE
*           �w��   : GS_BEHIND_PLANE
*           ���ʏ� : GS_ON_PLANE
*
*============================================================================*/
extern GSenum
gsPlaneClassifyPoint
(
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^	*/
	const GSvector3*	pPoint,			/* �_�̍��W				*/
	GSfloat*			pDistance		/* ���ʂƓ_�̋���		*/
)
{
	GSfloat				Distance;

	/* ���ʂƓ_�Ƃ̋��������߂� */
	Distance = gsPlaneDotCoord( pPlane, pPoint );

	if ( pDistance != NULL )
	{
		*pDistance = Distance;
	}

	/* ���ʂ̑O�ʂɓ_�����݂��邩�H*/
	if( Distance > FLT_EPSILON )
	{
		return	GS_FRONT_PLANE;
	}

	/* ���ʂ̔w�ʂɓ_�����݂��邩�H*/
	if( Distance < -FLT_EPSILON )
	{
		return	GS_BEHIND_PLANE;
	}

	/* ���ʏ�ɓ_�����݂��� */
	return	GS_ON_PLANE;
}

/*=============================================================================
*
* Purpose : ���ʂƋ��̂̈ʒu�֌W��Ԃ��D
*
* Return  : ���ʂ̐��ʁC���ʂ̗��ʁC���ʂƌ����̉��ꂩ��Ԃ��D
*
*           ���� : GS_FRONT_PLANE
*           �w�� : GS_BEHIND_PLANE
*           ���� : GS_INTERSECTS_PLANE
*
*============================================================================*/
extern GSenum
gsPlaneClassifySphere
(
	const GSplane* 		pPlane,			/* ���ʕ������p�����[�^		*/
	const GSvector3*	pCenter,		/* ���̂̒��S���W			*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	GSfloat*			pDistance		/* ���ʂƋ��̂̒��S�Ƃ̋���	*/
)
{
	GSfloat				Distance;

	/* ���ʂƒ��S���W�_�̋��������߂� */
	Distance = gsPlaneDotCoord( pPlane, pCenter );

	if ( pDistance != NULL )
	{
		*pDistance = Distance;
	}

	/* ���ʂƋ��̂��������Ă��邩�H*/
	if( ABS( Distance ) < Radius )
	{
		return	GS_INTERSECTS_PLANE;
	}

	/* ���ʂ̑O�ʂɋ��̂����݂��邩�H*/
	if( Distance >= Radius )
	{
		return	GS_FRONT_PLANE;
	}

	/* ���ʏ�̔w�ʂɋ��̂����݂��� */
	return	GS_BEHIND_PLANE;
}

/*=============================================================================
*
* Purpose : ���ʂ̐��`��ԁD
*
* Return  : ��������ΐ^�C�������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSplane*
gsPlaneLerp
(
	GSplane* 		pOut,			/*-> ���ʕ������p�����[�^	*/
	const GSplane*	pP1,			/* �J�n						*/
	const GSplane*	pP2,			/* �I��						*/
	GSfloat			t				/* ��Ԓl( 0.0f �` 1.0f )	*/
)
{
	pOut->a = LERP( pP1->a, pP2->a, t );
	pOut->b = LERP( pP1->b, pP2->b, t );
	pOut->c = LERP( pP1->c, pP2->c, t );
	pOut->d = LERP( pP1->d, pP2->d, t );

	gsVector3Normalize( &pOut->normal, &pOut->normal );

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���ʂ̂Q����ԁD
*
* Return  : ��������ΐ^�C�������Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSplane*
gsPlaneQuadratic
(
	GSplane* 		pOut,			/*-> ���ʕ������p�����[�^	*/
	const GSplane*	pP1,			/* �J�n						*/
	const GSplane*	pP2,			/* ����						*/
	const GSplane*	pP3,			/* �I��						*/
	GSfloat			t				/* ��Ԓl( 0.0f �` 1.0f )	*/
)
{
	pOut->a = QUADRATIC( pP1->a, pP2->a, pP3->a, t );
	pOut->b = QUADRATIC( pP1->b, pP2->b, pP3->b, t );
	pOut->c = QUADRATIC( pP1->c, pP2->c, pP3->c, t );
	pOut->d = QUADRATIC( pP1->d, pP2->d, pP3->d, t );

	gsVector3Normalize( &pOut->normal, &pOut->normal );

	return	pOut;
}

/********** End of File ******************************************************/
