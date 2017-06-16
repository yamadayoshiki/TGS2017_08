/******************************************************************************
* File Name : GSvector2.h                         Ver : 1.00  Date : 2001-01-16
*
* Description :
*
*       �Q�c�x�N�g���v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSVECTOR2_H_
#define		_GSVECTOR2_H_

#include	"GStype.h"
#include	"GSmath.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �Q�c�x�N�g�����������D
*
* Return  : �����������x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Init
(
	GSvector2*		pOut,				/* -> ����				*/
	GSfloat			x,					/* �����W				*/
	GSfloat			y					/* �����W				*/
)
{
	pOut->x = x;
	pOut->y = y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�c�x�N�g���̉��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Add
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = pV1->x + pV2->x;
	pOut->y = pV1->y + pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̌��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Subtract
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏�Z�D
*
* Return  : ��Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Multiply
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = pV1->x * pV2->x;
	pOut->y = pV1->y * pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏��Z�D
*
* Return  : ���Z�̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Divide
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = pV1->x / pV2->x;
	pOut->y = pV1->y / pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̊O�ς����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2CCW
(
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	return	pV1->x * pV2->y - pV1->y * pV2->x;
}

/*=============================================================================
*
* Purpose : �x�N�g���̓��ς����Ƃ߂�D
*
* Return  : ���ς�Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2Dot
(
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	return pV1->x * pV2->x + pV1->y * pV2->y;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D�i ���a�݂̂ŕ��������Ƃ�Ȃ� �j
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2LengthSq
(
	const GSvector2*		pV			/* �Q�c�x�N�g��			*/
)
{
	return pV->x * pV->x + pV->y * pV->y;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2Length
(
	const GSvector2*		pV			/* �Q�c�x�N�g��			*/
)
{
	return (GSfloat)gsSqrt( gsVector2LengthSq( pV ) );
}

/*=============================================================================
*
* Purpose : �x�N�g���̐��`��ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Lerp
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pMin,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pMax,			/* �Q�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = LERP( t, pMin->x, pMax->x );
	pOut->y = LERP( t, pMin->y, pMax->y );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̂Q����ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Quadratic
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV3,			/* �Q�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = QUADRATIC( t, pV1->x, pV2->x, pV3->x );
	pOut->y = QUADRATIC( t, pV1->y, pV2->y, pV3->y );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ő�l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ő�l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Maximize
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x > pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y > pV2->y ) ? pV1->y : pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ŏ��l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ŏ��l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Minimize
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV1,			/* �Q�c�x�N�g��			*/
	const GSvector2*	pV2				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x < pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y < pV2->y ) ? pV1->y : pV2->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̃X�P�[�����O�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Scale
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV,				/* �Q�c�x�N�g��			*/
	GSfloat				s				/* �X�J���[				*/
)
{
	pOut->x = pV->x * s;
	pOut->y = pV->y * s;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �t�x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Inverse
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pV				/* �Q�c�x�N�g��			*/
)
{
	pOut->x = -pV->x;
	pOut->y = -pV->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �����̕������̌v�Z���s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2LinearEquation
(
	GSvector2*			pOut,			/* -> ����				*/
	const GSvector2*	pP,				/* �Q�c�x�N�g��			*/
	const GSvector2*	pV,				/* �Q�c�x�N�g��			*/
	GSfloat				t				/* �W��					*/
)
{
	pOut->x = pV->x * t + pP->x;
	pOut->y = pV->y * t + pP->y;

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���ʊp����x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2FromDirection
(
	GSvector2*		pOut,				/* -> ����			*/
	GSfloat			Direction			/* ���ʊp			*/
)
{
	pOut->x = gsCos( Direction );
	pOut->y = gsSin( Direction );

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
gsVector2Normalize
(
	GSvector2*			pOut,			/*->�P�ʃx�N�g��                */
	const GSvector2*	pV				/* �x�N�g��                     */
)
{
	GSfloat				len;

	if ( ( len = gsVector2Length( pV ) ) != 0 )
	{
		gsVector2Scale( pOut, pV, 1.0f / len  );
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
gsVector2Distance
(
	const GSvector2*	pV1,			/* �n�_                         */
	const GSvector2*	pV2				/* �I�_                         */
)
{
	GSvector2			V;

	gsVector2Subtract( &V, pV1, pV2 );

	return	gsVector2Length( &V );
}

/*=============================================================================
*
* Purpose : �Q�_�Ԃ̋��������߂�D�i ���a�����ŕ����������Ȃ� �j
*
* Return  : ������Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2DistanceSq
(
	const GSvector2*	pV1,			/* �n�_                         */
	const GSvector2*	pV2				/* �I�_                         */
)
{
	GSvector2			V;

	gsVector2Subtract( &V, pV1, pV2 );

	return	gsVector2LengthSq( &V );
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̍��p�x�����߂�D
*
* Return  : �p�x��Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2InnerDegree
(
	const GSvector2*	pV1,			/* �x�N�g���P                   */
	const GSvector2*	pV2				/* �x�N�g���Q                   */
)
{
	GSfloat				cos_theta;
	GSfloat				angle;

	cos_theta = gsVector2Dot( pV1, pV2 )
			  / ( gsVector2Length( pV1 ) * gsVector2Length( pV2 ) );

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
GSINLINE GSvector2*
gsVector2Transform
(
	GSvector2*			pOut,			/* �ϊ���̃x�N�g��			*/
	const GSvector2*	pV,				/* �ϊ��O�̃x�N�g��			*/
	const GSmatrix3*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector2			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    +         pM->m[2][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    +         pM->m[2][1];

	*pOut = v;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �@���x�N�g���̍��W�ϊ����s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2TransformNormal
(
	GSvector2*			pOut,			/* �ϊ���̖@���x�N�g��		*/
	const GSvector2*	pV,				/* �ϊ��O�̖@���x�N�g��		*/
	const GSmatrix3*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector2			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1];

	*pOut = v;

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���W�ϊ����s���D�i�R�c�ϊ��s����g�p����j
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2TransformCoord
(
	GSvector2*			pOut,			/* �ϊ���̖@���x�N�g��		*/
	const GSvector2*	pV,				/* �ϊ��O�̖@���x�N�g��		*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector2			v;
	GSfloat				w;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    +         pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    +         pM->m[3][1];
	w   = pV->x * pM->m[0][3]
	    + pV->y * pM->m[1][3]
	    +         pM->m[3][3];

	gsVector2Scale( &v, &v, 1.0f / w );

	*pOut = v;

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���˃x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Reflection
(
	GSvector2*			pOut,			/*-> ���˃x�N�g��		*/
	const GSvector2*	pI,				/* ���˃x�N�g��			*/
	const GSvector2*	pN				/* �@���x�N�g��			*/
)
{
	GSvector2			v;
	GSvector2			t;

	/* Out = 2 * ( -I dot N ) * N + I */
	gsVector2Inverse( &v, pI );
	gsVector2Scale( &t, pN, gsVector2Dot( &v, pN ) * 2.0f );
	gsVector2Add( pOut, &t, pI );

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���܃x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector2*
gsVector2Refraction
(
	GSvector2*			pOut,			/*-> ���˃x�N�g��		*/
	const GSvector2*	pI,				/* ���˃x�N�g��			*/
	const GSvector2*	pN,				/* �@���x�N�g��			*/
	GSfloat				Eta				/* ���ܗ���				*/
)
{
	GSvector2			T1, T2;
	GSfloat				cosI;
	GSfloat				cosT2;

	gsVector2Inverse( &T1, pI );
	cosI  = gsVector2Dot( &T1, pN );
	cosT2 = 1.0f - Eta * Eta * ( 1.0f - cosI * cosI );

	if ( cosT2 <= 0.0f )
	{
		gsVector2Init( pOut, 0.0f, 0.0f );
	}
	else
	{
		gsVector2Scale( &T1, pI, Eta );
		gsVector2Scale( &T2, pN, Eta * cosI - gsSqrt( ABS( cosT2 ) ) );
		gsVector2Add( pOut, &T1, &T2 );
	}

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���ʊp�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector2GetDirection
(
	const GSvector2*	pV				/* �x�N�g��				*/
)
{
	GSfloat				x, y;
	GSfloat				l;

	/* �x�N�g���̒��������߂� */
	if ( ( l = gsVector2Length( pV ) ) == 0 )
	{
		/* �������O�̏ꍇ�͂O�ɂ��� */
		return 0.0f;
	}

	/* �x�N�g���𐳋K������ */
	x = pV->x / l;
	y = pV->y / l;

	/* ���p�̌v�Z���s�� */
	return	gsAtan( x, y );
}

#ifdef __cplusplus
}
#endif

/*----- �b�{�{���b�p�[�N���X ------------------------------------------------*/

#ifdef __cplusplus

GSINLINE GSvector2::GSvector2( GSfloat X, GSfloat Y ) :
	x( X ), y( Y )
{}

GSINLINE GSvector2::GSvector2( const GSvector3& v3 ) :
	x( v3.x ), y( v3.y )
{}

GSINLINE GSvector2::GSvector2( const GSvector4& v4 ) :
	x( v4.x ), y( v4.y )
{}

GSINLINE GSvector2::GSvector2( const GSfloat* p ) :
	x( p[0] ), y( p[1] )
{}

/* ���K�� */
GSINLINE GSvector2& GSvector2::normalize()
{
	gsVector2Normalize( this, this );

	return	*this;
}

/* ���K����̃x�N�g�����擾���� */
GSINLINE GSvector2 GSvector2::getNormalized() const
{
	GSvector2 result( *this );

	return	result.normalize();
}

/* ���������߂� */
GSINLINE GSfloat GSvector2::length() const
{
	return	gsVector2Length( this );
}

/* ���������߂� (�Q��a�̂݁j*/
GSINLINE GSfloat GSvector2::lengthSq() const
{
	return	gsVector2LengthSq( this );
}

/* ���������߂� */
GSINLINE GSfloat GSvector2::distance( const GSvector2& V ) const
{
	return	gsVector2Distance( this, &V );
}

/* ���ς����߂� */
GSINLINE GSfloat GSvector2::dot( const GSvector2& V ) const
{
	return	gsVector2Dot( this, &V );
}

/* �O�ς����߂� */
GSINLINE GSfloat GSvector2::CCW( const GSvector2& V ) const
{
	return	gsVector2CCW( this, &V );
}

/* �������v�f�����߂� */
GSINLINE GSvector2 GSvector2::minimize( const GSvector2& V ) const
{
	GSvector2	result;

	gsVector2Minimize( &result, this, &V );

	return result;
}

/* �傫���v�f�����߂� */
GSINLINE GSvector2 GSvector2::maximize( const GSvector2& V ) const
{
	GSvector2	result;

	gsVector2Maximize( &result, this, &V );

	return result;
}

/* �N�����v���� */
GSINLINE GSvector2 GSvector2::clamp( const GSvector2& l, const GSvector2& h ) const
{
	GSvector2	result;

	gsVector2Maximize(&result, &l, gsVector2Minimize(&result, this, &h));

	return result;
}


/* ���`��Ԃ��s�� */
GSINLINE GSvector2 GSvector2::lerp( const GSvector2& V, GSfloat n ) const
{
	GSvector2	result;

	gsVector2Lerp( &result, this, &V, n );

	return result;
}

/* �Q����Ԃ��s�� */
GSINLINE GSvector2 GSvector2::quadratic( const GSvector2& V2, const GSvector2& V3, GSfloat n ) const
{
	GSvector2	result;

	gsVector2Quadratic( &result, this, &V2, &V3, n );

	return result;
}

/* ���˃x�N�g�������߂� */
GSINLINE GSvector2 GSvector2::reflect( const GSvector2& N ) const
{
	GSvector2	result;

	gsVector2Reflection( &result, this, &N );

	return result;
}

/* ���܃x�N�g�������߂� */
GSINLINE GSvector2 GSvector2::refract( const GSvector2& N, GSfloat Eta ) const
{
	GSvector2	result;

	gsVector2Refraction( &result, this, &N, Eta );

	return result;
}

/* �Q�x�N�g���̂Ȃ��p�x�����߂� */
GSINLINE GSfloat GSvector2::degree( const GSvector2& V ) const
{
	return gsVector2InnerDegree( this, &V );
}

/* ���ʊp�����߂� */
GSINLINE GSfloat GSvector2::getDirection() const
{
	return	gsVector2GetDirection( this );
}

/* ���ʊp����x�N�g�������߂� */
GSINLINE GSvector2& GSvector2::fromDirection( GSfloat direction )
{
	gsVector2FromDirection( this, direction );

	return	*this;
}

/* ���ʊp����x�N�g�������߂� */
GSINLINE GSvector2 GSvector2::createFromDirection(GSfloat direction)
{
	GSvector2 result;

	gsVector2FromDirection(&result, direction);

	return	result;
}

/* �Q�̃x�N�g�����Ȃ��p�x�����߂� */
GSINLINE GSfloat GSvector2::innerDegree(const GSvector2& other) const
{
	return	gsVector2InnerDegree(this, &other);
}

// �L���X�g���Z�q�I�[�o�[���[�h
GSINLINE GSvector2::operator GSfloat* () const
{
	return (float*) this;
}

GSINLINE GSvector2::operator const GSfloat* () const
{
	return (const GSfloat*) this;
}

// �P�����Z�q�I�[�o�[���[�h
GSINLINE GSvector2	GSvector2::operator + () const
{
	return	*this;
}

GSINLINE GSvector2	GSvector2::operator - () const
{
	return	GSvector2( -x, -y );
}

// ������Z�q�I�[�o�[���[�h
GSINLINE GSvector2&	GSvector2::operator += ( const GSvector2& V )
{
	gsVector2Add( this, this, &V );

	return	*this;
}

GSINLINE GSvector2&	GSvector2::operator -= ( const GSvector2& V )
{
	gsVector2Subtract( this, this, &V );

	return	*this;
}

GSINLINE GSvector2&	GSvector2::operator *= ( const GSvector2& V )
{
	gsVector2Multiply( this, this, &V );

	return	*this;
}

GSINLINE GSvector2&	GSvector2::operator /= ( const GSvector2& V )
{
	gsVector2Divide( this, this, &V );

	return	*this;
}

GSINLINE GSvector2&	GSvector2::operator *= ( GSfloat S )
{
	gsVector2Scale( this, this, S );

	return	*this;
}

GSINLINE GSvector2&	GSvector2::operator /= ( GSfloat S )
{
	gsVector2Scale( this, this, 1.0f / S );

	return	*this;
}

// �Q�����Z�q�I�[�o�[���[�h
GSINLINE const GSvector2 operator + ( const GSvector2& v1, const GSvector2& v2 )
{
	GSvector2	result;

	gsVector2Add( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector2 operator - ( const GSvector2& v1, const GSvector2& v2 ) 
{
	GSvector2	result;

	gsVector2Subtract( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector2 operator * ( const GSvector2& v1, const GSvector2 v2 )
{
	GSvector2	result;

	gsVector2Multiply( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector2 operator * ( const GSvector2& v, GSfloat s )
{
	GSvector2	result;

	gsVector2Scale( &result, &v, s );

	return	result;
}

GSINLINE const GSvector2 operator * ( GSfloat s, const GSvector2& v )
{
	return	v * s;
}

GSINLINE const GSvector2 operator / ( const GSvector2& v, GSfloat s )
{
	GSvector2	result;

	gsVector2Scale( &result, &v, 1.0f / s );

	return	result;
}

GSINLINE const GSvector2 operator * ( const GSmatrix3& M, const GSvector2& v )
{
	return	GSvector2( v.x * M.m[0][0] + v.y * M.m[1][0] + M.m[2][0],
					   v.x * M.m[0][1] + v.y * M.m[1][1] + M.m[2][1] );
}

GSINLINE const GSvector2 operator * ( const GSvector2& v, const GSmatrix3& M )
{
	return GSvector2( v.x * M.m[0][0] + v.y * M.m[0][1] + M.m[0][2],
					  v.x * M.m[1][0] + v.y * M.m[1][1] + M.m[1][2] );
}

GSINLINE const GSvector2 operator * ( const GSmatrix4& M, const GSvector2& v )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[1][0] + M.m[3][0];
	GSfloat y = v.x * M.m[0][1] + v.y * M.m[1][1] + M.m[3][1];
	GSfloat w = v.x * M.m[0][3] + v.y * M.m[1][3] + M.m[3][3];

	return	GSvector2( x / w, y / w );
}

GSINLINE const GSvector2 operator * ( const GSvector2& v, const GSmatrix4& M )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[0][1] + M.m[0][3];
	GSfloat y = v.x * M.m[1][0] + v.y * M.m[1][1] + M.m[1][3];
	GSfloat w = v.x * M.m[3][0] + v.y * M.m[3][1] + M.m[3][3];

	return	GSvector2( x / w, y / w );
}

GSINLINE bool operator == ( const GSvector2& v1, const GSvector2& v2 )
{
    return	( v1.x == v2.x && v1.y == v2.y );
}

GSINLINE bool operator != ( const GSvector2& v1, const GSvector2& v2 )
{
	return	!( v1 == v2 );
}

GSINLINE bool operator < ( const GSvector2& v1, const GSvector2& v2 )
{
	if ( v1.x != v2.x ) return v1.x < v2.x;
	return v1.y < v2.y;
}

GSINLINE bool operator > ( const GSvector2& v1, const GSvector2& v2 )
{
	if ( v1.x != v2.x ) return v1.x > v2.x;
	return v1.y > v2.y;
}

GSINLINE bool operator <= ( const GSvector2& v1, const GSvector2& v2 )
{
	return	!( v1 > v2 );
}

GSINLINE bool operator >= ( const GSvector2& v1, const GSvector2& v2 )
{
	return	!( v1 < v2 );
}

#endif


#endif

/********** End of File ******************************************************/
