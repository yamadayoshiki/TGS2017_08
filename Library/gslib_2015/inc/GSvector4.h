/******************************************************************************
* File Name : GSvector4.h                         Ver : 1.00  Date : 2001-01-16
*
* Description :
*
*       �S�c�x�N�g���v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSVECTOR4_H_
#define		_GSVECTOR4_H_

#include	"GStype.h"
#include	"GSmath.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �S�c�x�N�g�����������D
*
* Return  : �����������x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Init
(
	GSvector4*		pOut,				/* -> ����				*/
	GSfloat			x,					/* �����W				*/
	GSfloat			y,					/* �����W				*/
	GSfloat			z,					/* �����W				*/
	GSfloat			w					/* �����W				*/
)
{
	pOut->x = x;
	pOut->y = y;
	pOut->z = z;
	pOut->w = w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �S�c�x�N�g���̉��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Add
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = pV1->x + pV2->x;
	pOut->y = pV1->y + pV2->y;
	pOut->z = pV1->z + pV2->z;
	pOut->w = pV1->w + pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̌��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Subtract
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;
	pOut->w = pV1->w - pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏�Z�D
*
* Return  : ��Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Multiply

(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = pV1->x * pV2->x;
	pOut->y = pV1->y * pV2->y;
	pOut->z = pV1->z * pV2->z;
	pOut->w = pV1->w * pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏��Z�D
*
* Return  : ���Z�̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Divide
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = pV1->x / pV2->x;
	pOut->y = pV1->y / pV2->y;
	pOut->z = pV1->z / pV2->z;
	pOut->w = pV1->w / pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̓��ς����Ƃ߂�D
*
* Return  : ���ς�Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4Dot
(
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D�i ���a�݂̂ŕ��������Ƃ�Ȃ� �j
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4LengthSq
(
	const GSvector4*		pV			/* �S�c�x�N�g��			*/
)
{
	return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4Length
(
	const GSvector4*		pV			/* �S�c�x�N�g��			*/
)
{
	return (GSfloat)gsSqrt( gsVector4LengthSq( pV ) );
}

/*=============================================================================
*
* Purpose : �x�N�g���̐��`��ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Lerp
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pMin,			/* �S�c�x�N�g��			*/
	const GSvector4*	pMax,			/* �S�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = LERP( t, pMin->x, pMax->x );
	pOut->y = LERP( t, pMin->y, pMax->y );
	pOut->z = LERP( t, pMin->z, pMax->z );
	pOut->w = LERP( t, pMin->w, pMax->w );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̂Q����ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVcector3Quadratic
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV3,			/* �S�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = QUADRATIC( t, pV1->x, pV2->x, pV3->x );
	pOut->y = QUADRATIC( t, pV1->y, pV2->y, pV3->y );
	pOut->z = QUADRATIC( t, pV1->z, pV2->z, pV3->z );
	pOut->w = QUADRATIC( t, pV1->w, pV2->w, pV3->w );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ő�l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ő�l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Maximize
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x > pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y > pV2->y ) ? pV1->y : pV2->y;
	pOut->z = ( pV1->z > pV2->z ) ? pV1->z : pV2->z;
	pOut->w = ( pV1->w > pV2->w ) ? pV1->w : pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ŏ��l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ŏ��l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Minimize
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV1,			/* �S�c�x�N�g��			*/
	const GSvector4*	pV2				/* �S�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x < pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y < pV2->y ) ? pV1->y : pV2->y;
	pOut->z = ( pV1->z < pV2->z ) ? pV1->z : pV2->z;
	pOut->w = ( pV1->w < pV2->w ) ? pV1->w : pV2->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̃X�P�[�����O�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Scale
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV,				/* �S�c�x�N�g��			*/
	GSfloat				s				/* �X�J���[				*/
)
{
	pOut->x = pV->x * s;
	pOut->y = pV->y * s;
	pOut->z = pV->z * s;
	pOut->w = pV->w * s;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �t�x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Inverse
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pV				/* �S�c�x�N�g��			*/
)
{
	pOut->x = -pV->x;
	pOut->y = -pV->y;
	pOut->z = -pV->z;
	pOut->w = -pV->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �����̕������̌v�Z���s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4LinearEquation
(
	GSvector4*			pOut,			/* -> ����				*/
	const GSvector4*	pP,				/* �S�c�x�N�g��			*/
	const GSvector4*	pV,				/* �S�c�x�N�g��			*/
	GSfloat				t				/* �W��					*/
)
{
	pOut->x = pV->x * t + pP->x;
	pOut->y = pV->y * t + pP->y;
	pOut->z = pV->z * t + pP->z;
	pOut->w = pV->w * t + pP->w;

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���ʊp�C�p����x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4FromEleDir
(
	GSvector4*		pOut,				/* -> ����			*/
	GSfloat			Elavation,			/* �p				*/
	GSfloat			Direction			/* ���ʊp			*/
)
{
	pOut->x =  gsCos( Elavation ) * gsSin( Direction );
	pOut->y = -gsSin( Elavation );
	pOut->z =  gsCos( Elavation ) * gsCos( Direction );
	pOut->w = 1.0f;

	return	pOut;
}
/*=============================================================================
*
* Purpose : �x�N�g���𐳋K������D�i �P�ʃx�N�g�������� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector4Normalize
(
	GSvector4*			pOut,			/*->�P�ʃx�N�g��                */
	const GSvector4*	pV				/* �x�N�g��                     */
)
{
	GSfloat				len;

	if ( ( len = gsVector4Length( pV ) ) != 0 )
	{
		gsVector4Scale( pOut, pV, 1.0f / len  );
	}
}

/*=============================================================================
*
* Purpose : �Q�_�Ԃ̋��������߂�D
*
* Return  : ������Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4Distance
(
	const GSvector4*	pV1,			/* �n�_                         */
	const GSvector4*	pV2				/* �I�_                         */
)
{
	GSvector4			V;

	gsVector4Subtract( &V, pV1, pV2 );

	return	gsVector4Length( &V );
}

/*=============================================================================
*
* Purpose : �Q�_�Ԃ̋��������߂�D�i ���a�����ŕ����������Ȃ� �j
*
* Return  : ������Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4DistanceSq
(
	const GSvector4*	pV1,			/* �n�_                         */
	const GSvector4*	pV2				/* �I�_                         */
)
{
	GSvector4			V;

	gsVector4Subtract( &V, pV1, pV2 );

	return	gsVector4LengthSq( &V );
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̍��p�x�����߂�D
*
* Return  : �p�x��Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector4InnerDegree
(
	const GSvector4*	pV1,			/* �x�N�g���P                   */
	const GSvector4*	pV2				/* �x�N�g���Q                   */
)
{
	GSfloat				cos_theta;
	GSfloat				angle;

	cos_theta = gsVector4Dot( pV1, pV2 )
			  / ( gsVector4Length( pV1 ) * gsVector4Length( pV2 ) );

	angle = gsAcos( CLAMP( cos_theta, -1.0f, 1.0f ) );

	return	angle;
}

/*=============================================================================
*
* Purpose : �x�N�g���̍��W�ϊ����s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4Transform
(
	GSvector4*			pOut,			/* �ϊ���̃x�N�g��			*/
	const GSvector4*	pV,				/* �ϊ��O�̃x�N�g��			*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector4			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    + pV->z * pM->m[2][0]
	    + pV->w * pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    + pV->w * pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    + pV->w * pM->m[3][2];
	v.w = pV->x * pM->m[0][3]
	    + pV->y * pM->m[1][3]
	    + pV->z * pM->m[2][3]
	    + pV->w * pM->m[3][3];

	*pOut = v;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̍��W�ϊ����s���D�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector4*
gsVector4TransformCoord
(
	GSvector4*			pOut,			/* �ϊ���̃x�N�g��			*/
	const GSvector4*	pV,				/* �ϊ��O�̃x�N�g��			*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector4			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    + pV->z * pM->m[2][0]
	    + pV->w * pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    + pV->w * pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    + pV->w * pM->m[3][2];
	v.w = pV->x * pM->m[0][3]
	    + pV->y * pM->m[1][3]
	    + pV->z * pM->m[2][3]
	    + pV->w * pM->m[3][3];

	gsVector4Scale( pOut, &v, 1.0f / v.w );

	return	pOut;
}

#ifdef __cplusplus
}
#endif

/*----- �b�{�{���b�p�[�N���X ------------------------------------------------*/

#ifdef __cplusplus

/* �R���X�g���N�^ */
GSINLINE GSvector4::GSvector4( GSfloat X, GSfloat Y, GSfloat Z, GSfloat W ) :
	x( X ), y( Y ), z( Z ), w( W )
{}

GSINLINE GSvector4::GSvector4( const GSvector2& v2, GSfloat Z, GSfloat W ) :
	x( v2.x ), y( v2.y ), z( Z ), w( W )
{}

GSINLINE GSvector4::GSvector4( const GSvector3& v3, GSfloat W ) :
	x( v3.x ), y( v3.y ), z( v3.z ), w( W )
{}

GSINLINE GSvector4::GSvector4( const GSfloat* p ) :
	x( p[0] ), y( p[1] ), z( p[2] ), w( p[3] )
{}

/* ���K�� */
GSINLINE GSvector4& GSvector4::normalize()
{
	gsVector4Normalize( this, this );

	return	*this;
}

/* ���K����̃x�N�g�����擾���� */
GSINLINE GSvector4 GSvector4::getNormalized() const
{
	GSvector4 result( *this );

	return result.normalize();
}

/* ���������߂� */
GSINLINE GSfloat GSvector4::length() const
{
	return	gsVector4Length( this );
}

/* ���������߂� (�Q��a�̂݁j*/
GSINLINE GSfloat GSvector4::lengthSq() const
{
	return	gsVector4LengthSq( this );
}

/* ���������߂� */
GSINLINE GSfloat GSvector4::distance( const GSvector4& V ) const
{
	return	gsVector4Distance( this, &V );
}

/* ���ς����߂� */
GSINLINE GSfloat GSvector4::dot( const GSvector4& V ) const
{
	return	gsVector4Dot( this, &V );
}

/* �������v�f�����߂� */
GSINLINE GSvector4 GSvector4::minimize( const GSvector4& V ) const
{
	GSvector4	result;

	gsVector4Minimize( &result, this, &V );

	return result;
}

/* �傫���v�f�����߂� */
GSINLINE GSvector4 GSvector4::maximize( const GSvector4& V ) const
{
	GSvector4	result;

	gsVector4Maximize( &result, this, &V );

	return result;
}

/* �N�����v���� */
GSINLINE GSvector4 GSvector4::clamp( const GSvector4& l, const GSvector4& h ) const
{
	GSvector4	result;

	gsVector4Maximize(&result, &l, gsVector4Minimize(&result, this, &h));

	return result;
}


/* ���`��Ԃ��s�� */
GSINLINE GSvector4 GSvector4::lerp( const GSvector4& v4, GSfloat n ) const
{
	GSvector4	result;

	gsVector4Lerp( &result, this, &v4, n );

	return result;
}

/* �Q����Ԃ��s�� */
GSINLINE GSvector4 GSvector4::quadratic( const GSvector4& V2, const GSvector4& V3, GSfloat n ) const
{
	GSvector4	result;

	gsVcector3Quadratic( &result, this, &V2, &V3, n );

	return result;
}

// �L���X�g���Z�q�I�[�o�[���[�h
GSINLINE GSvector4::operator GSfloat* () const
{
	return (float*) this;
}

GSINLINE GSvector4::operator const GSfloat* () const
{
	return (const GSfloat*) this;
}

// �P�����Z�q�I�[�o�[���[�h
GSINLINE GSvector4	GSvector4::operator + () const
{
	return	*this;
}

GSINLINE GSvector4	GSvector4::operator - () const
{
	return	GSvector4( -x, -y, -z, -w );
}

// ������Z�q�I�[�o�[���[�h
GSINLINE GSvector4&	GSvector4::operator += ( const GSvector4& V )
{
	gsVector4Add( this, this, &V );

	return	*this;
}

GSINLINE GSvector4&	GSvector4::operator -= ( const GSvector4& V )
{
	gsVector4Subtract( this, this, &V );

	return	*this;
}

GSINLINE GSvector4&	GSvector4::operator *= ( const GSvector4& V )
{
	gsVector4Multiply( this, this, &V );

	return	*this;
}

GSINLINE GSvector4&	GSvector4::operator /= ( const GSvector4& V )
{
	gsVector4Divide( this, this, &V );

	return	*this;
}

GSINLINE GSvector4&	GSvector4::operator *= ( GSfloat S )
{
	gsVector4Scale( this, this, S );

	return	*this;
}

GSINLINE GSvector4&	GSvector4::operator /= ( GSfloat S )
{
	gsVector4Scale( this, this, 1.0f / S );

	return	*this;
}

// �Q�����Z�q�I�[�o�[���[�h
GSINLINE const GSvector4 operator + ( const GSvector4& v1, const GSvector4& v2 )
{
	GSvector4	result;

	gsVector4Add( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector4 operator - ( const GSvector4& v1, const GSvector4& v2 )
{
	GSvector4	result;

	gsVector4Subtract( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector4 operator * ( const GSvector4& v1, const GSvector4 v2 )
{
	GSvector4	result;

	gsVector4Multiply( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector4 operator * ( const GSvector4& v, GSfloat s )
{
	GSvector4	result;

	gsVector4Scale( &result, &v, s );

	return	result;
}

GSINLINE const GSvector4 operator * ( GSfloat s, const GSvector4& v )
{
	return	v * s;
}

GSINLINE const GSvector4 operator / ( const GSvector4& v, GSfloat s )
{
	GSvector4	result;

	gsVector4Scale( &result, &v, 1.0f / s );

	return	result;
}

GSINLINE const GSvector4 operator * ( const GSmatrix4& M, const GSvector4& v )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[1][0] + v.z * M.m[2][0] + v.w * M.m[3][0];
	GSfloat y = v.x * M.m[0][1] + v.y * M.m[1][1] + v.z * M.m[2][1] + v.w * M.m[3][1];
	GSfloat z = v.x * M.m[0][2] + v.y * M.m[1][2] + v.z * M.m[2][2] + v.w * M.m[3][2];
	GSfloat w = v.x * M.m[0][3] + v.y * M.m[1][3] + v.z * M.m[2][3] + v.w * M.m[3][3];

	return	GSvector4( x / w, y / w, z / w, w );
}

GSINLINE const GSvector4 operator * ( const GSvector4& v, const GSmatrix4& M )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[0][1] + v.z * M.m[0][2] + v.w * M.m[0][3];
	GSfloat y = v.x * M.m[1][0] + v.y * M.m[1][1] + v.z * M.m[1][2] + v.w * M.m[1][3];
	GSfloat z = v.x * M.m[2][0] + v.y * M.m[2][1] + v.z * M.m[2][2] + v.w * M.m[2][3];
	GSfloat w = v.x * M.m[3][0] + v.y * M.m[3][1] + v.z * M.m[3][2] + v.w * M.m[3][3];

	return	GSvector4( x / w, y / w, z / w, w );
}

GSINLINE bool operator == ( const GSvector4& v1, const GSvector4& v2 )
{
    return	( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.z == v2.w );
}

GSINLINE bool operator != ( const GSvector4& v1, const GSvector4& v2 )
{
	return	!( v1 == v2 );
}

GSINLINE bool operator < ( const GSvector4& v1, const GSvector4& v2 )
{
	if ( v1.x != v2.x ) return v1.x < v2.x;
	if ( v1.y != v2.y ) return v1.y < v2.y;
	if ( v1.z != v2.z ) return v1.z < v2.z;
	return v1.w < v2.w;
}

GSINLINE bool operator > ( const GSvector4& v1, const GSvector4& v2 )
{
	if ( v1.x != v2.x ) return v1.x > v2.x;
	if ( v1.y != v2.y ) return v1.y > v2.y;
	if ( v1.z != v2.z ) return v1.z > v2.z;
	return v1.w > v2.w;
}

GSINLINE bool operator <= ( const GSvector4& v1, const GSvector4& v2 )
{
	return	!( v1 > v2 );
}

GSINLINE bool operator >= ( const GSvector4& v1, const GSvector4& v2 )
{
	return	!( v1 < v2 );
}

#endif

#endif

/********** End of File ******************************************************/
