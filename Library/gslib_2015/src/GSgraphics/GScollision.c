/******************************************************************************
* File Name : GScollision.c                      Ver : 1.00  Date : 2002-03-24
*
* Description :
*
*       �Փ˔���̌v�Z�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GScollision.h"
#include	"GSmatrix4.h"
#include	"GSvector3.h"
#include	"GSplane.h"
#include	<float.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static GSboolean InsidePolygon( const GSvector3*, GSuint, const GSvector3* );
static GSboolean CollisionPolyEdgeAndSphere( const GSvector3*, GSuint, const GSvector3*, GSfloat, GSvector3* );
static void FindNearestPointOnLineSegment( const GSvector3*, const GSvector3*, const GSvector3*, GSboolean, GSvector3*, GSfloat* );
static void FindNearestPointOfParallelLineSegments( const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, GSboolean, GSvector3*, GSvector3* );
static void AdjustNearestPoints( const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, GSfloat, GSfloat, GSvector3*, GSvector3* );

/****** �}�N���錾 ***********************************************************/

/* 0.0f�`1.0f���Ɏ��܂��Ă��邩�`�F�b�N���� */
#define OUT_OF_RANGE(a) ( ( (a) < 0.0f  || (a) > 1.0f ) ? GS_TRUE: GS_FALSE )

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
)
{
	if ( gsVector3DistanceSq( pCenter1, pCenter2 ) <= SQR( Radius1 + Radius2 ) )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSvector3			Intersect;

	/* ���ʂƐ����̌�_�����߂� */
	if ( gsPlaneIntersectLine( &Intersect, pPlane, pLine0, pLine1 ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ��_���|���S�����ɑ��݂��邩�H */
	if ( InsidePolygon( pPoly, numVertices, &Intersect ) == GS_TRUE )
	{
		/* �|���S���Ƃ̐�����_��ݒ� */
		if ( pIntersectPoint != NULL )
		{
			*pIntersectPoint = Intersect;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSvector3			Intersect;

	/* ���ʂƐ����̌�_�����߂� */
	if ( gsPlaneIntersectRay( &Intersect, pPlane, pRayPos, pRayDir ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ��_���|���S�����ɑ��݂��邩�H */
	if ( InsidePolygon( pPoly, numVertices, &Intersect ) == GS_TRUE )
	{
		/* �|���S���Ƃ̐�����_��ݒ� */
		if ( pIntersectPoint != NULL )
		{
			*pIntersectPoint = Intersect;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSvector3			Poly[3];
	GSplane*			pPlane;
	GSvector3			Center;
	GSvector3			Position;
	GSvector3			Offset;
	GSboolean			bCollision;
	GSboolean			bIntersects;
	GSfloat				Distance;
	GSfloat				DistanceOver;
	GSuint				i;

	Center = *pCenter;

	/* �Փ˃t���O�̏����� */
	bCollision  = GS_FALSE;

	/* ���ʌ����t���O�̏����� */
	bIntersects = GS_FALSE;

	/* �S�|���S�����ʂƋ��̂̏Փ˔�����s�� */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
		pPlane = &pMesh->pPlanes[i];

		/* ���̂��|���S�����ʂƌ������邩���ׂ� */
		if ( gsPlaneClassifySphere( pPlane, &Center, Radius, &Distance ) != GS_INTERSECTS_PLANE )
		{
			continue;
		}
		bIntersects = GS_TRUE;

		/* �|���S�����ʂƋ��̂̒��S�܂ł̑��΍��W�����߂� */
		Offset.x = pPlane->a * Distance;
		Offset.y = pPlane->b * Distance;
		Offset.z = pPlane->c * Distance;

		/* �|���S�����ʏ�ɋ��̂̒��S�ʒu��␳���� */
		gsVector3Subtract( &Position, &Center, &Offset );

		/* �|���S���̂R���_���擾���� */
		Poly[0] = pMesh->pPoints[ pMesh->pIndices[i*3+0] ];
		Poly[1] = pMesh->pPoints[ pMesh->pIndices[i*3+1] ];
		Poly[2] = pMesh->pPoints[ pMesh->pIndices[i*3+2] ];

		/* �|���S�����ʏ�ɋ��̂̒��S���W�����݂��邩�H */
		if ( InsidePolygon( Poly, 3, &Position ) == GS_TRUE )
		{
			bCollision = GS_TRUE;

			if( Distance > 0.0f )
			{
				/* �d�Ȃ��Ă��镔���̕␳�l�����߂� */
				DistanceOver = Radius - Distance;

				Center.x += pPlane->a * DistanceOver;
				Center.y += pPlane->b * DistanceOver;
				Center.z += pPlane->c * DistanceOver;
			}
		}
	}

	/* �S�Ă̕��ʂƌ������Ȃ���ΏI�� */
	if ( bIntersects == GS_FALSE )
	{
		return	bCollision;
	}

	/* �S�|���S���G�b�W�Ƌ��̂̏Փ˔�����s�� */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
		pPlane = &pMesh->pPlanes[i];

		/* ���̂��|���S�����ʂƌ������邩���ׂ� */
		if ( gsPlaneClassifySphere( pPlane, &Center, Radius, NULL ) != GS_INTERSECTS_PLANE )
		{
			continue;
		}

		/* �|���S���̂R���_���擾���� */
		Poly[0] = pMesh->pPoints[ pMesh->pIndices[i*3+0] ];
		Poly[1] = pMesh->pPoints[ pMesh->pIndices[i*3+1] ];
		Poly[2] = pMesh->pPoints[ pMesh->pIndices[i*3+2] ];

		/* �|���S���̃G�b�W�Ƌ��̂̌���������s�� */
		if ( CollisionPolyEdgeAndSphere( Poly, 3, &Center, Radius, &Offset ) == TRUE )
		{
			bCollision = GS_TRUE;

			/* ���̂̒��S�ʒu��␳���� */
			gsVector3Add( &Center, &Center, &Offset );
		}
	}

	/* �␳��̋��̂̒��S���W��ݒ肷�� */
	if ( pOutCenter != NULL )
	{
		*pOutCenter = Center;
	}

	return	bCollision;
}

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
	GSvector3*			pIntersect,		/*-> ���b�V���Ɛ����̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
)
{
	GSvector3			Poly[3];
	GSplane*			pCollisionPlane;
	GSvector3			Intersect;
	GSfloat				DistanceSq;
	GSvector3			minIntersect = { 0, 0, 0 };
	GSfloat				minDistanceSq;
	GSuint				i;

	/* �Փ˖ʂ̏����� */
	pCollisionPlane = NULL;

	/* ��ԋ߂���_�Ƃ̋����������� */
	minDistanceSq = FLT_MAX;

	/* �S�|���S���ƃ��C�̏Փ˔�����s�� */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
#if 0
		/* ���ʂ̃|���S���Ƃ͏Փ˔�������Ȃ� */
		if ( gsPlaneClassifyPoint( &pMesh->pPlanes[i], pRayPos, NULL ) == GS_BEHIND_PLANE )
		{
			continue;
		}
#endif
		/* �|���S���̂R���_���擾���� */
		Poly[0] = pMesh->pPoints[ pMesh->pIndices[i*3+0] ];
		Poly[1] = pMesh->pPoints[ pMesh->pIndices[i*3+1] ];
		Poly[2] = pMesh->pPoints[ pMesh->pIndices[i*3+2] ];

		/* �|���S���ƃ��C�̏Փ˔�����s�� */
		if ( gsCollisionPolyAndRay( Poly, 3, &pMesh->pPlanes[i], pRayPos, pRayDir, &Intersect ) == GS_TRUE )
		{
			/* ���C�̎n�_�ƌ�_�̋��������߂� */
			DistanceSq = gsVector3DistanceSq( pRayPos, &Intersect );

			/* ���C�̎n�_�ɍł��߂���_��V������_�Ƃ��� */
			if ( DistanceSq < minDistanceSq )
			{
				minDistanceSq = DistanceSq;
				minIntersect  = Intersect;

				/* �Փ˖ʂ̃p�����[�^��ۑ� */
				pCollisionPlane = &pMesh->pPlanes[i];
			}
		}
	}

	/* �Փ˂����ʂ����݂��邩�H */
	if ( pCollisionPlane != NULL )
	{
		/* �Փ˂����ʂƂ̌�_��ݒ肷�� */
		if ( pIntersect != NULL )
		{
			*pIntersect = minIntersect;
		}

		/* �Փ˂������ʂ̃p�����[�^��ݒ肷�� */
		if ( pPlane != NULL )
		{
			*pPlane = *pCollisionPlane;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSvector3			Poly[3];
	GSplane*			pCollisionPlane;
	GSvector3			Intersect;
	GSuint				i;

	/* �I�_����_�ɐݒ� */
	Intersect = *pLine1;

	/* �Փ˖ʂ̏����� */
	pCollisionPlane = NULL;

	/* �S�|���S���ƃ��C�̏Փ˔�����s�� */
	for ( i = 0; i < ( pMesh->numIndices / 3 ); i++ )
	{
		/* ���ʂ̃|���S���Ƃ͏Փ˔�������Ȃ� */
		if ( gsPlaneClassifyPoint( &pMesh->pPlanes[i], pLine0, NULL ) == GS_BEHIND_PLANE )
		{
			continue;
		}

		/* �|���S���̂R���_���擾���� */
		Poly[0] = pMesh->pPoints[ pMesh->pIndices[i*3+0] ];
		Poly[1] = pMesh->pPoints[ pMesh->pIndices[i*3+1] ];
		Poly[2] = pMesh->pPoints[ pMesh->pIndices[i*3+2] ];

		/* �|���S���Ɛ����̏Փ˔�����s�� */
		if ( gsCollisionPolyAndLine( Poly, 3, &pMesh->pPlanes[i], pLine0, &Intersect, &Intersect ) == GS_TRUE )
		{
			/* �Փ˖ʂ̃p�����[�^��ۑ� */
			pCollisionPlane = &pMesh->pPlanes[i];
		}
	}

	/* �Փ˂����ʂ����݂��邩�H */
	if ( pCollisionPlane != NULL )
	{
		/* �Փ˂����ʂƂ̌�_��ݒ肷�� */
		if ( pIntersect != NULL )
		{
			*pIntersect = Intersect;
		}

		/* �Փ˂������ʂ̃p�����[�^��ݒ肷�� */
		if ( pPlane != NULL )
		{
			*pPlane = *pCollisionPlane;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSfloat				Distance;
	GSfloat				DistanceOver;
	GSvector3			Offset;
	GSvector3			Position;
	GSenum				Classification;

	/* ���̂��|���S�����ʂƌ������邩���ׂ� */
	Classification = gsPlaneClassifySphere( pPlane, pCenter, Radius, &Distance );

	if ( Classification != GS_INTERSECTS_PLANE )
	{
		/* �������Ă��Ȃ��ꍇ�͏Փ˂��Ȃ� */
		return	GS_FALSE;
	}

	/* �|���S�����ʂƋ��̂̒��S�܂ł̑��΍��W�����߂� */
	Offset.x = pPlane->a * Distance;
	Offset.y = pPlane->b * Distance;
	Offset.z = pPlane->c * Distance;

	/* �|���S�����ʏ�ɋ��̂̒��S�ʒu��␳���� */
	gsVector3Subtract( &Position, pCenter, &Offset );

	/* �|���S�����ʏ�ɋ��̂̒��S���W�����݂��邩�H */
	if ( InsidePolygon( pPoly, numVertices, &Position ) == GS_TRUE )
	{
		/* �d�Ȃ��Ă��镔���̕␳�l�����߂� */
		if ( pOffset != NULL )
		{
			DistanceOver = Radius - Distance;

			if( Distance < 0 )
			{
				DistanceOver = -DistanceOver;
			}
			pOffset->x = pPlane->a * DistanceOver;
			pOffset->y = pPlane->b * DistanceOver;
			pOffset->z = pPlane->c * DistanceOver;
		}

		return	GS_TRUE;
	}

	/* �|���S���̃G�b�W���������̂ƌ������Ă��邩�H */
	return	CollisionPolyEdgeAndSphere( pPoly, numVertices, pCenter, Radius, pOffset );
}

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
	const GSvector3*	pCenter,		/* ���̂̒��S���W			*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	const GSvector3*	pRayPos,		/* ���C�̈ʒu				*/
	const GSvector3*	pRayDir,		/* ���C�̕���				*/
	GSvector3*			pIntersect		/*-> ���C�Ƃ̌�_			*/
)
{
	GSvector3			Q;
	GSfloat				a , b, c, d;
	GSfloat				t;

	/* ���̂ƃ��C�̌���������s�� */
	gsVector3Subtract( &Q, pRayPos, pCenter );
	a = gsVector3LengthSq( pRayDir );
	b = gsVector3Dot( &Q, pRayDir );
	c = gsVector3LengthSq( &Q ) - SQR( Radius );
	if ( ( d = SQR( b ) - a * c ) < 0.0f )
	{
		return	GS_FALSE;
	}

	if ( pIntersect != NULL )
	{
		/* ���̂ƃ��C�̌�_�����߂� */
		t = ( -b - gsSqrt( d ) ) / a;
		gsVector3LinearEquation( pIntersect, pRayPos, pRayDir, t );
	}

	return	GS_TRUE;
}

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
)
{
	GSvector3			Point;
	GSvector3			LineVec;
	GSfloat				DistanceSq;

	/* �����̃x�N�g�������߂� */
	gsVector3Subtract( &LineVec, pLine1, pLine0 );

	/* ������̍ł����̂̒��S���W���߂����W�����߂� */
	FindNearestPointOnLineSegment( pLine0, &LineVec, pCenter, GS_FALSE, &Point, NULL );

	/* ������̍��W�Ƌ��̂̒��S���W�̋��������߂� */
	DistanceSq = gsVector3DistanceSq( &Point, pCenter );

	/* ���߂����������̂̔��a���������ꍇ�͏Փ˂��Ȃ� */
	if( DistanceSq > SQR( Radius ) )
	{
		return	GS_FALSE;
	}

	/* ���C�̃x�N�g���𐳋K������ */
	gsVector3Normalize( &LineVec, &LineVec );

	/* ���̂ƃ��C�̏Փ˔�����s�� */
	return	gsCollisionSphereAndRay( pCenter, Radius, pLine0, &LineVec, pIntersect );
}

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
	GSfloat 			Epsilon,		/* �����臒l						*/
	GSvector3*			pPA,			/*-> ��������̐������ɍł��߂����W	*/
	GSvector3*			pPB				/*-> ��������̐������ɍł��߂����W	*/
)
{
	GSvector3			VA, VB, AB;
	GSfloat				L11, L22, L12;
	GSfloat				ra, rb;
	GSfloat				s, t;
	GSfloat				DetL;

	/* �������C���̃x�N�g�������߂� */
	gsVector3Subtract( &VA, pA2, pA1 );
	gsVector3Subtract( &VB, pB2, pB1 );

	/* �������C���̃x�N�g���̓��a�����߂� */
	L11 = gsVector3LengthSq( &VA );
	L22 = gsVector3LengthSq( &VB );

	if ( L11 < FLT_EPSILON )
	{
		/* �������̒�����臒l�����������ꍇ �i �_�Ɛ����̔��� �j*/
		*pPA = *pA1;

		/* �������̎n�_�Ɛ�������̍��W�ōł��߂����W�����߂� */
		FindNearestPointOnLineSegment( pB1, &VB, pA1, bInfinite, pPB, NULL );
	}
	else if ( L22 < FLT_EPSILON )
	{
		/* �������̒�����臒l�����������ꍇ �i �_�Ɛ����̔��� �j */
		*pPB = *pB1;

		/* �������̎n�_�Ɛ�������̍��W�ōł��߂����W�����߂� */
		FindNearestPointOnLineSegment( pA1, &VA, pB1, bInfinite, pPA, NULL );
	}
	else
	{
		/* �������Ɛ�������臒l�����傫���i �������m�̔��� �j */
		gsVector3Subtract( &AB, pB1, pA1 );
		L12  = -gsVector3Dot( &VA, &VB );
		DetL = L11 * L22 - SQR( L12 );

		if ( ABS( DetL ) < FLT_EPSILON )
		{
			/* �������Ȃ��������m�̐����̍ł��߂��_�����߂� */
			FindNearestPointOfParallelLineSegments
			(
				pA1, pA2, &VA,
				pB1, pB2, &VB,
				bInfinite,
				pPA, pPB
			);
		}
		else
		{
			/* ������������̓��m�̍ł��߂��_�����߂� */
			ra =  gsVector3Dot( &VA, &AB );
			rb = -gsVector3Dot( &VB, &AB );
			t  = ( L11 * rb - ra * L12 ) / DetL;
			s  = ( ra - L12 * t ) / L11;
			gsVector3LinearEquation( pPA, pA1, &VA, s );
			gsVector3LinearEquation( pPB, pB1, &VB, t );

			/* �L���������ǂ��炩�̐�������������Ă���H */
			if ( ( bInfinite == GS_FALSE )
			&& ( OUT_OF_RANGE(s) == GS_TRUE || OUT_OF_RANGE(t) == GS_TRUE ) )
			{
				/* �L�������̓��m�̍ł��߂��_�̒��������� */
				AdjustNearestPoints( pA1, &VA, pB1, &VB, s, t, pPA, pPB );
			}
		}
	}

	/* �ł��߂��_���m�̋�����臒l�����Z���ꍇ�͏Փ˂��Ă��� */
	if ( gsVector3DistanceSq( pPA, pPB ) <= SQR( Epsilon ) )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

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
)
{
	GSboolean result;
	GSvector3 nearA;
	GSvector3 nearB;
	result = gsCollisionLineAndLine(pA1, pA2, pB1, pB2, GS_TRUE, Aw + Bw, &nearA, &nearB);
	if (pNa != NULL)
	{
		*pNa = nearA;
	}
	if (pNb != NULL)
	{
		*pNb = nearB;
	}
	return result;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �����Ƃ�����W�̍ł��אڂ��������̍��W�����߂�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
FindNearestPointOnLineSegment
(
	const GSvector3*	pLinePos,		/* �����̍��W					*/
	const GSvector3*	pLineVec,		/* �����̃x�N�g��				*/
	const GSvector3	*	pPoint,			/* ���ׂ������W					*/
	GSboolean			bInfinite,		/* �����������H					*/
	GSvector3*			pNP,			/*-> ������̗אڂ�����W		*/
	GSfloat*			pParameter		/*-> �����̕������̃p�����[�^	*/
)
{
	GSvector3			LP;
	GSfloat				d, t;


	/* �����̃x�N�g���̒�����臒l�����������H */
	if ( ( d = gsVector3LengthSq( pLineVec ) ) < FLT_EPSILON )
	{
		/* �����̎n�_���ł��߂� �i �����͓_�Ƃ��Ĉ��� �j*/
		*pNP = *pLinePos;

		if ( pParameter != NULL )
		{
			*pParameter = 0.0f;
		}

		return;
	}

	/* �����̎n�_����_�ւ̃x�N�g�������߂� */
	gsVector3Subtract( &LP, pPoint, pLinePos );

	/* ������̒��ׂ������W�ɍł��߂����W�̃p�����[�^�����߂� */
	t = gsVector3Dot( pLineVec, &LP ) / d;

	/* �L���������H */
	if ( bInfinite == GS_FALSE )
	{
		/* �L�������̏ꍇ��t��0.0f�`1.0f�̊ԂŃN�����v���� */
		t = CLAMP( t, 0.0f, 1.0f );
	}

	/* ���߂��p�����[�^����ł��߂����W�����߂� */
	gsVector3LinearEquation( pNP, pLinePos, pLineVec, t );

	if ( pParameter != NULL )
	{
		*pParameter = t;
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �������m���������Ȃ��ꍇ�̐������m�ōł��߂��_�����߂�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
FindNearestPointOfParallelLineSegments
(
	const GSvector3*	pA1,			/* �������̎n�_							*/
	const GSvector3*	pA2,			/* �������̏I�_							*/
	const GSvector3*	pVA,			/* �������̎n�_����I�_�ւ̃x�N�g��		*/
	const GSvector3*	pB1,			/* �������̎n�_							*/
	const GSvector3*	pB2,			/* �������̏I�_							*/
	const GSvector3*	pVB,			/* �����̂̎n�_����I�_�ւ̃x�N�g��		*/
	GSboolean			bInfinite,		/* �����������H							*/
	GSvector3*			pPA,			/*-> ��������̐������ɍł��߂����W		*/
	GSvector3*			pPB				/*-> ��������̐������ɍł��߂����W		*/
)
{
	float				s1, s2;
	float				t;
	GSvector3			tmpPoint;

	/* ��������̍��W�ōł��������̎n�_�ɋ߂����W�����߂� */
	FindNearestPointOnLineSegment( pA1, pVA, pB1, GS_TRUE, pPA, &s1 );

	/* �����������H */
	if ( bInfinite == GS_TRUE )
	{
		/* ���������̏ꍇ�͐������̎n�_���ł��߂����W�Ƃ��� */
		*pPB = *pB1;
	}
	else
	{
		/* ��������̍��W�ōł��������̏I�_�ɋ߂����W�����߂� */
		FindNearestPointOnLineSegment( pA1, pVA, pB2, GS_TRUE, &tmpPoint, &s2 );

		if ( ( s1 < 0.0f ) && ( s2 < 0.0f ) )
		{
			*pPA = *pA1;
			*pPB = ( s1 < s2 ) ? *pB2: *pB1;
		}
		else if ( ( s1 > 1.0f ) && ( s2 > 1.0f ) )
		{
			*pPA = *pA2;
			*pPB = ( s1 < s2 ) ? *pB1: *pB2;
		}
		else
		{
			t = 0.5f * ( CLAMP( s1, 0.0f, 1.0f ) + CLAMP( s2, 0.0f, 1.0f ) );
			gsVector3LinearEquation( pPA, pA1, pVA, t );
			FindNearestPointOnLineSegment( pB1, pVB, pPA, GS_TRUE, pPB, NULL );
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �������m�̍ł��߂��_�̒���������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
AdjustNearestPoints
(
	const GSvector3*	pA1,			/* �������̎n�_						*/
	const GSvector3*	pVA,			/* �������̎n�_����I�_�ւ̃x�N�g��	*/
	const GSvector3*	pB1,			/* �������̎n�_						*/
	const GSvector3*	pVB,			/* �������̎n�_����I�_�ւ̃x�N�g��	*/
	GSfloat				s,				/* �������̒����̕������̃p�����[�^	*/
	GSfloat				t,				/* �������̒����̕������̃p�����[�^	*/
	GSvector3*			pPA,			/*-> ��������̐������ɍł��߂����W	*/
	GSvector3*			pPB				/*-> ��������̐������ɍł��߂����W	*/
)
{
	if ( OUT_OF_RANGE( s ) == GS_TRUE && OUT_OF_RANGE( t ) == GS_TRUE )
	{
		s = CLAMP( s, 0.0f, 1.0f );
		gsVector3LinearEquation( pPA, pA1, pVA, s );
		FindNearestPointOnLineSegment( pB1, pVB, pPA, GS_TRUE, pPB, &t );

		if ( OUT_OF_RANGE( t ) == GS_TRUE )
		{
			t = CLAMP( t, 0.0f, 1.0f );
			gsVector3LinearEquation( pPB, pB1, pVB, t );
			FindNearestPointOnLineSegment( pA1, pVA, pPB, GS_FALSE, pPA, NULL );
			FindNearestPointOnLineSegment( pB1, pVB, pPA, GS_FALSE, pPB, NULL );
		}
	}
	else if ( OUT_OF_RANGE( s ) == GS_TRUE )
	{
		s = CLAMP( s, 0.0f, 1.0f );
		gsVector3LinearEquation( pPA, pA1, pVA, s );
		FindNearestPointOnLineSegment( pB1, pVB, pPA, GS_FALSE, pPB, NULL );
	}
	else if ( OUT_OF_RANGE( t ) == GS_TRUE )
	{
		t = CLAMP( t, 0.0f, 1.0f );
		gsVector3LinearEquation( pPB, pB1, pVB, t );
		FindNearestPointOnLineSegment( pA1, pVA, pPB, GS_FALSE, pPA, NULL );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �|���S�����Ɍ�_�����݂��邩���ׂ�D
*
* Return  : ��_�����݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
InsidePolygon
(
	const GSvector3*	pPoly,			/* �|���S���̒��_�z��	*/
	GSuint				numVertices,	/* ���_�f�[�^��			*/
	const GSvector3*	pPoint			/* ���ʂƂ̌�_			*/
)
{
#define	MATCH_FACTOR	0.99f			/* ��r���̋��e�͈�		*/
	GSfloat				Angle;
	GSfloat				CosTheta;
	GSfloat				LenV1, LenV2;
	GSvector3			V1, V2;
	GSuint				i;

	/* �|���S���̊e���_�ƌ�_�����Ԑ����̊p�x�̍��v�����߂� */
	Angle = 0.0f;
	for ( i = 0; i < numVertices; i++ )
	{
		gsVector3Subtract( &V1, &pPoly[i], pPoint );
		gsVector3Subtract( &V2, &pPoly[ (i + 1) % numVertices ], pPoint );

		/* ���_�ƌ�_�̋��������߂� */
		if ( ( LenV1 = gsVector3Length( &V1 ) ) < 0.0001f
		  || ( LenV2 = gsVector3Length( &V2 ) ) < 0.0001f )
		{
			return	GS_TRUE;
		}

		/* ��̃x�N�g���Ȃ��p�x�����߂� */
		CosTheta = gsVector3Dot( &V1, &V2 ) / ( LenV1 * LenV2 );

		/* �p�x�̍��v�����߂� */
		Angle += gsAcos( CLAMP( CosTheta, -1.0f, 1.0f ) );
	}

	/* ���v�����p�x���R�U�O�x�ł���΁C�|���S����Ɍ�_�����݂��� */
	if( Angle >= ( MATCH_FACTOR * 360.0f ) )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �|���S���̃G�b�W�Ƌ��̂��Փ˂��Ă��邩���ׂ�D
*
* Return  : �Փ˂��Ă���ΐ^�C�Փ˂��Ă��Ȃ���΋U��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
CollisionPolyEdgeAndSphere
(
	const GSvector3*	pPoly,			/* �|���S���̒��_�z��				*/
	GSuint				numVertices,	/* ���_�f�[�^��						*/
	const GSvector3*	pCenter,		/* ���̂̒��S						*/
	GSfloat				Radius,			/* ���̂̔��a						*/
	GSvector3*			pOffset			/*-> ���̂��Փ˂��Ȃ����W�ւ̕␳�l	*/
)
{
	GSvector3			Point;
	GSvector3			Vector;
	GSfloat				DistanceSq;
	GSuint				i;

	for ( i = 0; i < numVertices; i++ )
	{
		/* ���̂̒��S���W�ƃ|���S�������Ԑ�����̍ł��߂����W�����߂� */
		gsVector3Subtract( &Vector, &pPoly[ (i+1) % numVertices ], &pPoly[i] );
		FindNearestPointOnLineSegment( &pPoly[i], &Vector, pCenter, GS_FALSE, &Point, NULL );

		/* ������̍��W�Ƌ��̂̒��S���W�̋��������߂� */
		DistanceSq = gsVector3DistanceSq( &Point, pCenter );

		/* ���߂����������̔��a�����Z���ꍇ�͐����Ƌ��̂��������Ă��� */
		if ( DistanceSq < SQR( Radius ) )
		{
			/* �␳�l�����߂� */
			if ( pOffset != NULL )
			{
				/* �אړ_���狅�̂̒��S�ւ̒P�ʃx�N�g�������߂� */
				gsVector3Subtract( pOffset, pCenter, &Point );
				gsVector3Normalize( pOffset, pOffset );

				/* �������Ă��镔����␳���� */
				gsVector3Scale( pOffset, pOffset, Radius - gsSqrt( DistanceSq ) );
			}

			/* �Փ˂��Ă��� */
			return	GS_TRUE;
		}
	}

	/* �Փ˂��Ă��Ȃ� */
	return GS_FALSE;
}

/********** End of File ******************************************************/
