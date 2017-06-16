/******************************************************************************
* File Name : GSplane.h                          Ver : 1.00  Date : 2002-03-24
*
* Description :
*
*       ���ʂ̌v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSPLANE_H_
#define		_GSPLANE_H_

#include	"GStype.h"
#include	"GSmath.h"
#include	"GSvector3.h"
#include	<float.h>

/****** �萔�錾 *************************************************************/

#define	GS_FRONT_PLANE			0		/* ���ʂ̑O			*/
#define	GS_BEHIND_PLANE			1		/* ���ʂ̌��		*/
#define	GS_ON_PLANE				2		/* ���ʏ�			*/
#define	GS_INTERSECTS_PLANE		3		/* ���ʂƌ���		*/

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

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
);

/*=============================================================================
*
* Purpose : ���ʂ̐��`��ԁD
*
* Return  : ��Ԍ�̕��ʕ������D
*
*============================================================================*/
extern GSplane*
gsPlaneLerp
(
	GSplane* 		pOut,			/*-> ���ʕ������p�����[�^	*/
	const GSplane*	pP1,			/* �J�n						*/
	const GSplane*	pP2,			/* �I��						*/
	GSfloat			t				/* ��Ԓl( 0.0f �` 1.0f )	*/
);

/*=============================================================================
*
* Purpose : ���ʂ̂Q����ԁD
*
* Return  : ��Ԍ�̕��ʕ������D
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
);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

/* �R���X�g���N�^ */
GSINLINE GSplane::GSplane( GSfloat A, GSfloat B, GSfloat C, GSfloat D ) :
	a( A ), b( B ), c( C ), d( D )
{}

GSINLINE GSplane::GSplane( const GSvector3& N, GSfloat D ) :
	a( N.x ), b( N.y ), c( N.z ), d( D )
{}

GSINLINE GSplane::GSplane( const GSvector3& p, const GSvector3& n )
{
	gsPlaneFromPointNormal( this, &p, &n );
}

GSINLINE GSplane::GSplane( const GSvector3& v1, const GSvector3& v2, const GSvector3& v3 )
{
	gsPlaneFromPoints( this, &v1, &v2, &v3 );
}

/* ���K������ */
GSINLINE GSplane& GSplane::normalize()
{
	gsPlaneNormalize( this, this );
}

/* ���K����̕��ʂ𓾂� */
GSINLINE GSplane GSplane::getNormalized()
{
	GSplane		result;

	gsPlaneNormalize( &result, this );

	return	result;
}

/* ���ʏ�̈ʒu���擾 */
GSINLINE GSvector3 GSplane::getPoint() const
{
	GSvector3		point;

	gsPlanePoint( this, &point );

	return	point;
}

/* ���ʂƃx�N�g���̓��ς����߂� */
GSINLINE GSfloat GSplane::dot( const GSvector3& v ) const
{
	return	gsPlaneDotNormal( this, &v );
}

/* ���ʂƍ��W�̋��������߂� */
GSINLINE GSfloat GSplane::distance( const GSvector3& v ) const
{
	return	gsPlaneDotCoord( this, &v );
}

/* ���ʂƐ������������邩���ׂ� */
GSINLINE bool GSplane::isIntersectLine( const GSvector3& Line0,  const GSvector3& Line1 ) const
{
	if ( gsPlaneIntersected( this, &Line0, &Line1 ) == GS_TRUE )
	{
		return	true;
	}

	return	false;
}

/* ���ʂƐ����̌�_���擾���� */
GSINLINE GSvector3 GSplane::getIntersectLine( const GSvector3& Line0,  const GSvector3& Line1 ) const
{
	GSvector3		result;

	gsPlaneIntersectRay( &result, this, &Line0, &Line1 );

	return	result;
}

/* ���ʂƐ����̌�_���擾���� */
GSINLINE bool GSplane::isIntersectRay( const GSvector3& rayPos,  const GSvector3& rayDir ) const
{
	(void)rayPos;
	/* ��������߂� */
	if ( dot( rayDir.getNormalized() ) == 0.0f )
	{
		/* ���ꂪ�O�ꍇ�̓��C�ƕ��ʂ͕��s�ł��� */
		return	false;
	}

	return	true;
}

/* ���ʂƐ����̌�_���擾���� */
GSINLINE GSvector3 GSplane::getIntersectRay( const GSvector3& ray,  const GSvector3& dir ) const
{
	GSvector3		result;

	gsPlaneIntersectRay( &result, this, &ray, &dir );

	return	result;
}

/* ���ʂƍ��W�̈ʒu�֌W��Ԃ� */
GSINLINE GSenum GSplane::getClassifyPoint( const GSvector3& p ) const
{
	GSfloat		distance;

	return	gsPlaneClassifyPoint( this, &p, &distance );
}

/* ���ʂƋ��̂̈ʒu�֌W��Ԃ� */
GSINLINE GSenum GSplane::getClassifyShpere( const GSvector3& center, GSfloat radius ) const
{
	GSfloat		distance;

	return	gsPlaneClassifySphere( this, &center, radius, &distance );
}

/* ���`��Ԃ��s�� */
GSINLINE GSplane GSplane::lerp( const GSplane& p, GSfloat t ) const
{
	GSplane		result;

	gsPlaneLerp( &result, this, &p, t );

	return	result;
}

/* �Q����Ԃ��s�� */
GSINLINE GSplane GSplane::quadratic( const GSplane& p2, const GSplane& p3, GSfloat t ) const
{
	GSplane		result;

	gsPlaneQuadratic( &result, this, &p2, &p3, t );

	return	result;
}

/* �P�����Z�q�I�[�o�[���[�h */
GSINLINE GSplane  GSplane::operator + () const
{
	return	*this;
}

GSINLINE GSplane  GSplane::operator - () const
{
	return	GSplane( -a, -b, -c, -d );
}

/* �Q�����Z�q�I�[�o�[���[�h */
GSINLINE const GSplane operator * ( const GSmatrix3& mat, const GSplane& p )
{
	GSplane				result;
	GSvector3			P;
	GSvector3			T;
	GSvector3			N;

	/* ���ʏ�̍��W�����߂� */
	gsPlanePoint( &p, &T );

	/* ���ʏ�̍��W��ϊ����� */
	P.x = T.x * mat.m[0][0]
	    + T.y * mat.m[1][0]
	    + T.z * mat.m[2][0];
	P.y = T.x * mat.m[0][1]
	    + T.y * mat.m[1][1]
	    + T.z * mat.m[2][1];
	P.z = T.x * mat.m[0][2]
	    + T.y * mat.m[1][2]
	    + T.z * mat.m[2][2];

	/* �@���x�N�g���̍��W�ϊ� */
	N.x = p.a * mat.m[0][0]
	    + p.b * mat.m[1][0]
	    + p.c * mat.m[2][0];
	N.y = p.a * mat.m[0][1]
	    + p.b * mat.m[1][1]
	    + p.c * mat.m[2][1];
	N.z = p.a * mat.m[0][2]
	    + p.b * mat.m[1][2]
	    + p.c * mat.m[2][2];

	/* ���W�Ɩ@�����畽�ʂ����߂� */
	gsPlaneFromPointNormal( &result, &P, &N );

	return	result;
}

GSINLINE const GSplane operator * ( const GSplane& p, const GSmatrix3& mat )
{
	GSplane				result;
	GSvector3			P;
	GSvector3			T;
	GSvector3			N;

	/* ���ʏ�̍��W�����߂� */
	gsPlanePoint( &p, &T );

	/* ���ʏ�̍��W��ϊ����� */
	P.x = T.x * mat.m[0][0]
	    + T.y * mat.m[0][1]
	    + T.z * mat.m[0][2];
	P.y = T.x * mat.m[1][0]
	    + T.y * mat.m[1][1]
	    + T.z * mat.m[1][2];
	P.z = T.x * mat.m[2][0]
	    + T.y * mat.m[2][1]
	    + T.z * mat.m[2][2];

	/* �@���x�N�g���̍��W�ϊ� */
	N.x = p.a * mat.m[0][0]
	    + p.b * mat.m[0][1]
	    + p.c * mat.m[0][2];
	N.y = p.a * mat.m[1][0]
	    + p.b * mat.m[1][1]
	    + p.c * mat.m[1][2];
	N.z = p.a * mat.m[2][0]
	    + p.b * mat.m[2][1]
	    + p.c * mat.m[2][2];

	/* ���W�Ɩ@�����畽�ʂ����߂� */
	gsPlaneFromPointNormal( &result, &P, &N );

	return	result;
}

GSINLINE const GSplane operator * ( const GSmatrix4& mat, const GSplane& p )
{
	GSplane				result;
	GSvector3			P;
	GSvector3			T;
	GSvector3			N;

	/* ���ʏ�̍��W�����߂� */
	gsPlanePoint( &p, &T );

	/* ���ʏ�̍��W��ϊ����� */
	P.x = T.x * mat.m[0][0]
	    + T.y * mat.m[1][0]
	    + T.z * mat.m[2][0]
	    +       mat.m[3][0];
	P.y = T.x * mat.m[0][1]
	    + T.y * mat.m[1][1]
	    + T.z * mat.m[2][1]
	    +       mat.m[3][1];
	P.z = T.x * mat.m[0][2]
	    + T.y * mat.m[1][2]
	    + T.z * mat.m[2][2]
	    +       mat.m[3][2];

	/* �@���x�N�g���̍��W�ϊ� */
	N.x = p.a * mat.m[0][0]
	    + p.b * mat.m[1][0]
	    + p.c * mat.m[2][0];
	N.y = p.a * mat.m[0][1]
	    + p.b * mat.m[1][1]
	    + p.c * mat.m[2][1];
	N.z = p.a * mat.m[0][2]
	    + p.b * mat.m[1][2]
	    + p.c * mat.m[2][2];

	/* ���W�Ɩ@�����畽�ʂ����߂� */
	gsPlaneFromPointNormal( &result, &P, &N );

	return	result;
}

GSINLINE const GSplane operator * ( const GSplane& p, const GSmatrix4& mat )
{
	GSplane				result;
	GSvector3			P;
	GSvector3			T;
	GSvector3			N;

	/* ���ʏ�̍��W�����߂� */
	gsPlanePoint( &p, &T );

	/* ���ʏ�̍��W��ϊ����� */
	P.x = T.x * mat.m[0][0]
	    + T.y * mat.m[0][1]
	    + T.z * mat.m[0][2]
	    +       mat.m[0][3];
	P.y = T.x * mat.m[1][0]
	    + T.y * mat.m[1][1]
	    + T.z * mat.m[1][2]
	    +       mat.m[1][3];
	P.z = T.x * mat.m[2][0]
	    + T.y * mat.m[2][1]
	    + T.z * mat.m[2][2]
	    +       mat.m[2][3];

	/* �@���x�N�g���̍��W�ϊ� */
	N.x = p.a * mat.m[0][0]
	    + p.b * mat.m[0][1]
	    + p.c * mat.m[0][2];
	N.y = p.a * mat.m[1][0]
	    + p.b * mat.m[1][1]
	    + p.c * mat.m[1][2];
	N.z = p.a * mat.m[2][0]
	    + p.b * mat.m[2][1]
	    + p.c * mat.m[2][2];

	/* ���W�Ɩ@�����畽�ʂ����߂� */
	gsPlaneFromPointNormal( &result, &P, &N );

	return	result;
}

GSINLINE bool operator == ( const GSplane& p1, const GSplane& p2 )
{
	return	( p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d );
}

GSINLINE bool operator != ( const GSplane& p1, const GSplane& p2 )
{
	return	!(p1 == p2 );
}

#endif

#endif

/********** End of File ******************************************************/
