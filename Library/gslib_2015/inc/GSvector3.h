/******************************************************************************
* File Name : GSvector3.h                         Ver : 1.00  Date : 2001-01-16
*
* Description :
*
*       �R�c�x�N�g���v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSVECTOR3_H_
#define		_GSVECTOR3_H_

#include	"GStype.h"
#include	"GSmath.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �R�c�x�N�g�����������D
*
* Return  : �����������x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Init
(
	GSvector3*		pOut,				/* -> ����				*/
	GSfloat			x,					/* �����W				*/
	GSfloat			y,					/* �����W				*/
	GSfloat			z					/* �����W				*/
)
{
	pOut->x = x;
	pOut->y = y;
	pOut->z = z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �R�c�x�N�g���̉��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Add
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = pV1->x + pV2->x;
	pOut->y = pV1->y + pV2->y;
	pOut->z = pV1->z + pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̌��Z�D
*
* Return  : ���Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Subtract
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = pV1->x - pV2->x;
	pOut->y = pV1->y - pV2->y;
	pOut->z = pV1->z - pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏�Z�D
*
* Return  : ��Z��̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Multiply
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = pV1->x * pV2->x;
	pOut->y = pV1->y * pV2->y;
	pOut->z = pV1->z * pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̏��Z�D
*
* Return  : ���Z�̃x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Divide
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = pV1->x / pV2->x;
	pOut->y = pV1->y / pV2->y;
	pOut->z = pV1->z / pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̊O�ς����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Cross
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = pV1->y * pV2->z - pV1->z * pV2->y;
	pOut->y = pV1->z * pV2->x - pV1->x * pV2->z;
	pOut->z = pV1->x * pV2->y - pV1->y * pV2->x;

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
gsVector3Dot
(
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D�i ���a�݂̂ŕ��������Ƃ�Ȃ� �j
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3LengthSq
(
	const GSvector3*		pV			/* �R�c�x�N�g��			*/
)
{
	return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
}

/*=============================================================================
*
* Purpose : �x�N�g���̒��������߂�D
*
* Return  : �x�N�g���̒�����Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3Length
(
	const GSvector3*		pV			/* �R�c�x�N�g��			*/
)
{
	return (GSfloat)gsSqrt( gsVector3LengthSq( pV ) );
}

/*=============================================================================
*
* Purpose : �x�N�g���̐��`��ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Lerp
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pMin,			/* �R�c�x�N�g��			*/
	const GSvector3*	pMax,			/* �R�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = LERP( t, pMin->x, pMax->x );
	pOut->y = LERP( t, pMin->y, pMax->y );
	pOut->z = LERP( t, pMin->z, pMax->z );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̂Q����ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Quadratic
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV3,			/* �R�c�x�N�g��			*/
	GSfloat				t				/* ��Ԓl�i0.0�`1.0)	*/
)
{
	pOut->x = QUADRATIC( t, pV1->x, pV2->x, pV3->x );
	pOut->y = QUADRATIC( t, pV1->y, pV2->y, pV3->y );
	pOut->z = QUADRATIC( t, pV1->z, pV2->z, pV3->z );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ő�l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ő�l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Maximize
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x > pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y > pV2->y ) ? pV1->y : pV2->y;
	pOut->z = ( pV1->z > pV2->z ) ? pV1->z : pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̊e�v�f�̍ŏ��l����쐬���ꂽ�x�N�g�������߂�D
*
* Return  : �e�v�f�̍ŏ��l�����߂��x�N�g����Ԃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Minimize
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV1,			/* �R�c�x�N�g��			*/
	const GSvector3*	pV2				/* �R�c�x�N�g��			*/
)
{
	pOut->x = ( pV1->x < pV2->x ) ? pV1->x : pV2->x;
	pOut->y = ( pV1->y < pV2->y ) ? pV1->y : pV2->y;
	pOut->z = ( pV1->z < pV2->z ) ? pV1->z : pV2->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g���̃X�P�[�����O�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Scale
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV,				/* �R�c�x�N�g��			*/
	GSfloat				s				/* �X�J���[				*/
)
{
	pOut->x = pV->x * s;
	pOut->y = pV->y * s;
	pOut->z = pV->z * s;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �t�x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Inverse
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pV				/* �R�c�x�N�g��			*/
)
{
	pOut->x = -pV->x;
	pOut->y = -pV->y;
	pOut->z = -pV->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �����̕������̌v�Z���s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3LinearEquation
(
	GSvector3*			pOut,			/* -> ����				*/
	const GSvector3*	pP,				/* �R�c�x�N�g��			*/
	const GSvector3*	pV,				/* �R�c�x�N�g��			*/
	GSfloat				t				/* �W��					*/
)
{
	pOut->x = pV->x * t + pP->x;
	pOut->y = pV->y * t + pP->y;
	pOut->z = pV->z * t + pP->z;

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���ʊp�C�p����x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3FromEleDir
(
	GSvector3*		pOut,				/* -> ����			*/
	GSfloat			Elavation,			/* �p				*/
	GSfloat			Direction			/* ���ʊp			*/
)
{
	pOut->x =  gsCos( Elavation ) * gsSin( Direction );
	pOut->y = -gsSin( Elavation );
	pOut->z =  gsCos( Elavation ) * gsCos( Direction );

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
gsVector3Normalize
(
	GSvector3*			pOut,			/*->�P�ʃx�N�g��                */
	const GSvector3*	pV				/* �x�N�g��                     */
)
{
	GSfloat				len;

	if ( ( len = gsVector3Length( pV ) ) != 0 )
	{
		gsVector3Scale( pOut, pV, 1.0f / len  );
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
gsVector3Distance
(
	const GSvector3*	pV1,			/* �n�_                         */
	const GSvector3*	pV2				/* �I�_                         */
)
{
	GSvector3			V;

	gsVector3Subtract( &V, pV1, pV2 );

	return	gsVector3Length( &V );
}

/*=============================================================================
*
* Purpose : �Q�_�Ԃ̋��������߂�D�i ���a�����ŕ����������Ȃ� �j
*
* Return  : ������Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3DistanceSq
(
	const GSvector3*	pV1,			/* �n�_                         */
	const GSvector3*	pV2				/* �I�_                         */
)
{
	GSvector3			V;

	gsVector3Subtract( &V, pV1, pV2 );

	return	gsVector3LengthSq( &V );
}

/*=============================================================================
*
* Purpose : �Q�̃x�N�g���̍��p�x�����߂�D
*
* Return  : �p�x��Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3InnerDegree
(
	const GSvector3*	pV1,			/* �x�N�g���P                   */
	const GSvector3*	pV2				/* �x�N�g���Q                   */
)
{
	GSfloat				cos_theta;
	GSfloat				angle;

	cos_theta = gsVector3Dot( pV1, pV2 )
			  / ( gsVector3Length( pV1 ) * gsVector3Length( pV2 ) );

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
GSINLINE GSvector3*
gsVector3Transform
(
	GSvector3*			pOut,			/* �ϊ���̃x�N�g��			*/
	const GSvector3*	pV,				/* �ϊ��O�̃x�N�g��			*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector3			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    + pV->z * pM->m[2][0]
	    +         pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    +         pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    +         pM->m[3][2];

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
GSINLINE GSvector3*
gsVector3TransformCoord
(
	GSvector3*			pOut,			/* �ϊ���̃x�N�g��			*/
	const GSvector3*	pV,				/* �ϊ��O�̃x�N�g��			*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector3			v;
	GSfloat				w;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    + pV->z * pM->m[2][0]
	    +         pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    +         pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    +         pM->m[3][2];
	w   = pV->x * pM->m[0][3]
	    + pV->y * pM->m[1][3]
	    + pV->z * pM->m[2][3]
	    +         pM->m[3][3];

	gsVector3Scale( pOut, &v, 1.0f / w );

	return	pOut;
}

/*=============================================================================
*
* Purpose : �@���x�N�g���̍��W�ϊ����s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3TransformNormal
(
	GSvector3*			pOut,			/* �ϊ���̖@���x�N�g��		*/
	const GSvector3*	pV,				/* �ϊ��O�̖@���x�N�g��		*/
	const GSmatrix4*	pM				/* ���W�ϊ��s��				*/
) 
{
	GSvector3			v;

	v.x = pV->x * pM->m[0][0]
	    + pV->y * pM->m[1][0]
	    + pV->z * pM->m[2][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2];

	*pOut = v;

	return	pOut;
}

/*=============================================================================
*
* Purpose : �ʖ@�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3CalculateNormal
(
	GSvector3*			pOut,			/*-> �@���x�N�g��		*/
	const GSvector3*	pV0,			/* �O�p�`�̒��_���W�O	*/
	const GSvector3*	pV1,			/* �O�p�`�̒��_���W�P	*/
	const GSvector3*	pV2				/* �O�p�`�̒��_���W�Q	*/
)
{
	GSvector3			V1;
	GSvector3			V2;

	/* �R�p�`�̒��_����x�N�g�������߂� */
	gsVector3Subtract( &V1, pV0, pV1 );
	gsVector3Subtract( &V2, pV1, pV2 );

	/* �Q�̃x�N�g���̊O�ς����߂� */
	gsVector3Cross( pOut, &V1, &V2 );

	/* �x�N�g���̂𐳋K������ */
	gsVector3Normalize( pOut, pOut );

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���˃x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Reflection
(
	GSvector3*			pOut,			/*-> ���˃x�N�g��		*/
	const GSvector3*	pI,				/* ���˃x�N�g��			*/
	const GSvector3*	pN				/* �@���x�N�g��			*/
)
{
	GSvector3			v;
	GSvector3			t;

	/* Out = 2 * ( -I dot N ) * N + I */
	gsVector3Inverse( &v, pI );
	gsVector3Scale( &t, pN, gsVector3Dot( &v, pN ) * 2.0f );
	gsVector3Add( pOut, &t, pI );

	return	pOut;
}

/*=============================================================================
*
* Purpose : ���܃x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSvector3*
gsVector3Refraction
(
	GSvector3*			pOut,			/*-> ���˃x�N�g��		*/
	const GSvector3*	pI,				/* ���˃x�N�g��			*/
	const GSvector3*	pN,				/* �@���x�N�g��			*/
	GSfloat				Eta				/* ���ܗ���				*/
)
{
	GSvector3			T1, T2;
	GSfloat				cosI;
	GSfloat				cosT2;

	gsVector3Inverse( &T1, pI );
	cosI  = gsVector3Dot( &T1, pN );
	cosT2 = 1.0f - Eta * Eta * ( 1.0f - cosI * cosI );

	if ( cosT2 <= 0.0f )
	{
		gsVector3Init( pOut, 0.0f, 0.0f, 0.0f );
	}
	else
	{
		gsVector3Scale( &T1, pI, Eta );
		gsVector3Scale( &T2, pN, Eta * cosI - gsSqrt( ABS( cosT2 ) ) );
		gsVector3Add( pOut, &T1, &T2 );
	}

	return	pOut;
}

/*=============================================================================
*
* Purpose : �x�N�g�����烈�[�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3GetYaw
(
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	GSfloat				x, z;
	GSfloat				l;

	/* �x�N�g���̒��������߂� */
	if ( ( l = gsVector3Length( pV ) ) == 0 )
	{
		/* �������O�̏ꍇ�͂O�ɂ��� */
		return 0.0f;
	}

	/* �x�N�g���𐳋K������ */
	x = pV->x / l;
	z = pV->z / l;

	/* ���[�̌v�Z���s�� */
	return	gsAtan( x, z );
}

/*=============================================================================
*
* Purpose : �x�N�g������s�b�`�����߂�D
*
* Return  : �s�b�`��Ԃ��D
*
*============================================================================*/
GSINLINE GSfloat
gsVector3GetPitch
(
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	GSfloat				y;
	GSfloat				l;

	/* �x�N�g���̒��������߂� */
	if ( ( l = gsVector3Length( pV ) ) == 0 )
	{
		/* �������O�̏ꍇ�͂O�x�ɂ��� */
		return	0.0f;
	}

	/* �x�N�g���𐳋K������ */
	y = pV->y / l;

	/* �s�b�`�̌v�Z���s�� */
	return	gsDegreeNormalize( gsAsin( -y ) );
}

/*=============================================================================
*
* Purpose : �x�N�g������p�ƕ��ʊp�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3ToEleDir
(
	GSfloat*			pElevation,		/*-> �p				*/
	GSfloat*			pDirection,		/*-> ���ʊp				*/
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	if ( pElevation != NULL )
	{
		*pElevation = gsVector3GetPitch( pV );
	}
	if ( pDirection != NULL )
	{
		*pDirection = gsVector3GetYaw( pV );
	}
}

/*=============================================================================
*
* Purpose : �d�S���W�����߂�
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsCalculateBarycentric(
	const GSvector3*	pV0,		/* �O�p�`�̍��W1			*/
	const GSvector3*	pV1,		/* �O�p�`�̍��W2			*/
	const GSvector3*	pV2,		/* �O�p�`�̍��W3			*/
	const GSvector3*	pPoint,		/* �d�S���W�����߂����ʒu	*/
	float*				pU,			/*-> �d�S���W1              */
	float*				pV,			/*-> �d�S���W2              */
	float*				pW			/*-> �d�S���W3              */
)
{
	GSvector3 v0;
	GSvector3 v1;
	GSvector3 v2;
	float d00;
	float d01;
	float d11;
	float d20;
	float d21;
	float denom;
	gsVector3Subtract(&v0, pV1, pV0);
	gsVector3Subtract(&v1, pV2, pV0);
	gsVector3Subtract(&v2, pPoint, pV0);
	d00 = gsVector3Dot(&v0, &v0);
	d01 = gsVector3Dot(&v0, &v1);
	d11 = gsVector3Dot(&v1, &v1);
	d20 = gsVector3Dot(&v2, &v0);
	d21 = gsVector3Dot(&v2, &v1);
	denom = d00 * d11 - d01 * d01;
	*pV = (d11 * d20 - d01 * d21) / denom;
	*pW = (d00 * d21 - d01 * d20) / denom;
	*pU = 1.0f - *pV - *pW;
}

/*=============================================================================
*
* Purpose : �d�S���W������W�����߂�
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3Barycentric
(
	GSvector3*			pOut,		/*-> �d�S���W���狁�߂����W	*/
	const GSvector3*	pV0,		/* �O�p�`�̍��W1			*/
	const GSvector3*	pV1,		/* �O�p�`�̍��W2			*/
	const GSvector3*	pV2,		/* �O�p�`�̍��W3		    */
	float				u,			/* �d�S���W1                */
	float				v,			/* �d�S���W2              �@*/
	float				w			/* �d�S���W3                */
)
{
	GSvector3 v0;
	GSvector3 v1;
	GSvector3 v2;
	gsVector3Scale(&v0, pV0, u);
	gsVector3Scale(&v1, pV1, v);
	gsVector3Scale(&v2, pV2, w);
	gsVector3Add(pOut, &v0,  &v1);
	gsVector3Add(pOut, pOut, &v2);
}

/*=============================================================================
*
* Purpose : ���_�z��̍��W�ϊ�
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3ArrayTransform
(
	GSvector3			Out[],		/*-> ���W�ϊ���̒��_�z��	*/
	const GSvector3		In[],		/* ���_�z��					*/
	GSuint				Size,		/* ���_�z��̃T�C�Y			*/
	const GSmatrix4*	pMatrix		/* ���W�ϊ��s��				*/
)
{
	GSuint i;
	for (i = 0; i < Size; ++i)
	{
		gsVector3Transform(&Out[i], &In[i], pMatrix);
	}
}

/*=============================================================================
*
* Purpose : ���_�z��̍��W�ϊ��i�����ϊ�����j
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3ArrayTransformCoord
(
	GSvector3			Out[],		/*-> ���W�ϊ���̒��_�z��	*/
	const GSvector3		In[],		/* ���_�z��					*/
	GSuint				Size,		/* ���_�z��̃T�C�Y			*/
	const GSmatrix4*	pMatrix		/* ���W�ϊ��s��				*/
)
{
	GSuint i;
	for (i = 0; i < Size; ++i)
	{
		gsVector3TransformCoord(&Out[i], &In[i], pMatrix);
	}
}

/*=============================================================================
*
* Purpose : ���_�z��̍��W�ϊ�
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3ArrayTransformNormal
(
	GSvector3			Out[],		/*-> ���W�ϊ���̒��_�z��	*/
	const GSvector3		In[],		/* ���_�z��					*/
	GSuint				Size,		/* ���_�z��̃T�C�Y			*/
	const GSmatrix4*	pMatrix		/* ���W�ϊ��s��				*/
)
{
	GSuint i;
	for (i = 0; i < Size; ++i)
	{
		gsVector3TransformNormal(&Out[i], &In[i], pMatrix);
	}
}

/*=============================================================================
*
* Purpose : ���_�z��̍��W�ϊ�
*
* Return  : �Ȃ��D
*
*============================================================================*/
GSINLINE void
gsVector3ArrayNormalize
(
	GSvector3			Out[],		/*-> ���W�ϊ���̒��_�z��	*/
	const GSvector3		In[],		/* ���_�z��					*/
	GSuint				Size		/* ���_�z��̃T�C�Y			*/
)
{
	GSuint i;
	for (i = 0; i < Size; ++i)
	{
		gsVector3Normalize(&Out[i], &In[i]);
	}
}

#ifdef __cplusplus
}
#endif

/*----- �b�{�{���b�p�[�N���X ------------------------------------------------*/

#ifdef __cplusplus

/* �R���X�g���N�^ */
GSINLINE GSvector3::GSvector3( GSfloat X, GSfloat Y, GSfloat Z ) :
	x( X ), y( Y ), z( Z )
{}

GSINLINE GSvector3::GSvector3( const GSvector2& v2, GSfloat Z ) :
	x( v2.x ), y( v2.y ), z( Z )
{}

GSINLINE GSvector3::GSvector3( const GSvector4& v4 ) :
	x( v4.x ), y( v4.y ), z( v4.z )
{}

GSINLINE GSvector3::GSvector3( const GSfloat* p ) :
	x( p[0] ), y( p[1] ), z( p[2] )
{}

/* ���K�� */
GSINLINE GSvector3& GSvector3::normalize()
{
	gsVector3Normalize( this, this );

	return	*this;
}

/* ���K����̃x�N�g�����擾���� */
GSINLINE GSvector3 GSvector3::getNormalized() const
{
	GSvector3 result( *this );

	return	result.normalize();
}

/* ���������߂� */
GSINLINE GSfloat GSvector3::length() const
{
	return	gsVector3Length( this );
}

/* ���������߂� (�Q��a�̂݁j*/
GSINLINE GSfloat GSvector3::lengthSq() const
{
	return	gsVector3LengthSq( this );
}

/* ���������߂� */
GSINLINE GSfloat GSvector3::distance( const GSvector3& V ) const
{
	return	gsVector3Distance( this, &V );
}

/* ���ς����߂� */
GSINLINE GSfloat GSvector3::dot( const GSvector3& V ) const
{
	return	gsVector3Dot( this, &V );
}

/* �O�ς����߂� */
GSINLINE GSvector3 GSvector3::cross( const GSvector3& V ) const
{
	GSvector3	result;

	gsVector3Cross( &result, this, &V );

	return result;
}

/* �������v�f�����߂� */
GSINLINE GSvector3 GSvector3::minimize( const GSvector3& V ) const
{
	GSvector3	result;

	gsVector3Minimize( &result, this, &V );

	return result;
}

/* �傫���v�f�����߂� */
GSINLINE GSvector3 GSvector3::maximize( const GSvector3& V ) const
{
	GSvector3	result;

	gsVector3Maximize( &result, this, &V );

	return result;
}

/* �N�����v���� */
GSINLINE GSvector3 GSvector3::clamp( const GSvector3& l, const GSvector3& h ) const
{
	GSvector3	result;

	gsVector3Maximize(&result, &l, gsVector3Minimize(&result, this, &h));

	return result;
}

/* ���`��Ԃ��s�� */
GSINLINE GSvector3 GSvector3::lerp( const GSvector3& V, GSfloat T ) const
{
	GSvector3	result;

	gsVector3Lerp( &result, this, &V, T );

	return result;
}

/* �Q����Ԃ��s�� */
GSINLINE GSvector3 GSvector3::quadratic( const GSvector3& V2, const GSvector3& V3, GSfloat n ) const
{
	GSvector3	result;

	gsVector3Quadratic( &result, this, &V2, &V3, n );

	return result;
}

/* ���˃x�N�g�������߂� */
GSINLINE GSvector3 GSvector3::reflect( const GSvector3& N ) const
{
	GSvector3	result;

	gsVector3Reflection( &result, this, &N );

	return result;
}

/* ���܃x�N�g�������߂� */
GSINLINE GSvector3 GSvector3::refract( const GSvector3& N, GSfloat Eta ) const
{
	GSvector3	result;

	gsVector3Refraction( &result, this, &N, Eta );

	return result;
}

/* �Q�x�N�g���̂Ȃ��p�x�����߂� */
GSINLINE GSfloat GSvector3::degree( const GSvector3& V ) const
{
	return gsVector3InnerDegree( this, &V );
}

/* ���[�����߂� */
GSINLINE GSfloat GSvector3::getYaw() const
{
	return	gsVector3GetYaw( this );
}

/* �s�b�`�����߂� */
GSINLINE GSfloat GSvector3::getPitch() const
{
	return	gsVector3GetPitch( this );
}

/* �s�b�`�E���[����x�N�g�������߂� */
GSINLINE GSvector3& GSvector3::fromPitchYaw( GSfloat picth, GSfloat yaw )
{
	gsVector3FromEleDir( this, picth, yaw );

	return	*this;
}

/** �s�b�`�E���[����x�N�g�������߂� */
GSINLINE  GSvector3 GSvector3::createFromPitchYaw( GSfloat picth, GSfloat yaw )
{
	GSvector3 result;

	gsVector3FromEleDir( &result, picth, yaw );

	return	result;
}

/* �@���x�N�g�������߂� */
GSINLINE GSvector3 GSvector3::calculateNormal( const GSvector3& V1, const GSvector3& V2 ) const
{
	GSvector3	result;

	gsVector3CalculateNormal( &result, this, &V1, &V2 );

	return result;
}

/* �Q�̃x�N�g�����Ȃ��p�x�����߂� */
GSINLINE GSfloat GSvector3::innerDegree(const GSvector3& other) const
{
	return	gsVector3InnerDegree(this, &other);
}

// �L���X�g���Z�q�I�[�o�[���[�h
GSINLINE GSvector3::operator GSfloat* () const
{
	return (float*) this;
}

GSINLINE GSvector3::operator const GSfloat* () const
{
	return (const GSfloat*) this;
}

// �P�����Z�q�I�[�o�[���[�h
GSINLINE GSvector3	GSvector3::operator + () const
{
	return	*this;
}

GSINLINE GSvector3	GSvector3::operator - () const
{
	return	GSvector3( -x, -y, -z );
}

// ������Z�q�I�[�o�[���[�h
GSINLINE GSvector3&	GSvector3::operator += ( const GSvector3& V )
{
	gsVector3Add( this, this, &V );

	return	*this;
}

GSINLINE GSvector3&	GSvector3::operator -= ( const GSvector3& V )
{
	gsVector3Subtract( this, this, &V );

	return	*this;
}

GSINLINE GSvector3&	GSvector3::operator *= ( const GSvector3& V )
{
	gsVector3Multiply( this, this, &V );

	return	*this;
}

GSINLINE GSvector3&	GSvector3::operator /= ( const GSvector3& V )
{
	gsVector3Divide( this, this, &V );

	return	*this;
}

GSINLINE GSvector3&	GSvector3::operator *= ( GSfloat S )
{
	gsVector3Scale( this, this, S );

	return	*this;
}

GSINLINE GSvector3&	GSvector3::operator /= ( GSfloat S )
{
	gsVector3Scale( this, this, 1.0f / S );

	return	*this;
}

// �Q�����Z�q�I�[�o�[���[�h
GSINLINE const GSvector3 operator + ( const GSvector3& v1, const GSvector3& v2 )
{
	GSvector3	result;

	gsVector3Add( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector3 operator - ( const GSvector3& v1, const GSvector3& v2 )
{
	GSvector3	result;

	gsVector3Subtract( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector3 operator * ( const GSvector3& v1, const GSvector3 v2 )
{
	GSvector3	result;

	gsVector3Multiply( &result, &v1, &v2 );

	return	result;
}

GSINLINE const GSvector3 operator * ( const GSvector3& v, GSfloat s )
{
	GSvector3	result;

	gsVector3Scale( &result, &v, s );

	return	result;
}

GSINLINE const GSvector3 operator / ( const GSvector3& v, GSfloat s )
{
	GSvector3	result;

	gsVector3Scale( &result, &v, 1.0f / s);

	return	result;
}


GSINLINE const GSvector3 operator * ( GSfloat s, const GSvector3& v )
{
	return	v * s;
}

GSINLINE const GSvector3 operator * ( const GSmatrix4& M, const GSvector3& v )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[0][1] + v.z * M.m[0][2] + M.m[0][3];
	GSfloat y = v.x * M.m[1][0] + v.y * M.m[1][1] + v.z * M.m[1][2] + M.m[1][3];
	GSfloat z = v.x * M.m[2][0] + v.y * M.m[2][1] + v.z * M.m[2][2] + M.m[2][3];
	GSfloat w = v.x * M.m[3][0] + v.y * M.m[3][1] + v.z * M.m[3][2] + M.m[3][3];

	return	GSvector3( x / w, y / w, z / w );
}

GSINLINE const GSvector3 operator * ( const GSvector3& v, const GSmatrix4& M )
{
	GSfloat x = v.x * M.m[0][0] + v.y * M.m[1][0] + v.z * M.m[2][0] + M.m[3][0];
	GSfloat y = v.x * M.m[0][1] + v.y * M.m[1][1] + v.z * M.m[2][1] + M.m[3][1];
	GSfloat z = v.x * M.m[0][2] + v.y * M.m[1][2] + v.z * M.m[2][2] + M.m[3][2];
	GSfloat w = v.x * M.m[0][3] + v.y * M.m[1][3] + v.z * M.m[2][3] + M.m[3][3];

	return	GSvector3( x / w, y / w, z / w );
}

GSINLINE const GSvector3 operator * ( const GSmatrix3& M, const GSvector3& v )
{
	return	GSvector3( v.x * M.m[0][0] + v.y * M.m[0][1] + v.z * M.m[0][2],
					   v.x * M.m[1][0] + v.y * M.m[1][1] + v.z * M.m[1][2],
					   v.x * M.m[2][0] + v.y * M.m[2][1] + v.z * M.m[2][2] );
}

GSINLINE const GSvector3 operator * ( const GSvector3& v, const GSmatrix3& M )
{
	return GSvector3( v.x * M.m[0][0] + v.y * M.m[1][0] + v.z * M.m[2][0],
					  v.x * M.m[0][1] + v.y * M.m[1][1] + v.z * M.m[2][1],
					  v.x * M.m[0][2] + v.y * M.m[1][2] + v.z * M.m[2][2] );
}

GSINLINE bool operator == ( const GSvector3& v1, const GSvector3& v2 )
{
    return	( v1.x == v2.x && v1.y == v2.y && v1.z == v2.z );
}

GSINLINE bool operator != ( const GSvector3& v1, const GSvector3& v2 )
{
	return	!( v1 == v2 );
}

GSINLINE bool operator < ( const GSvector3& v1, const GSvector3& v2 )
{
	if ( v1.x != v2.x ) return v1.x < v2.x;
	if ( v1.y != v2.y ) return v1.y < v2.y;
	return v1.z < v2.z;
}

GSINLINE bool operator > ( const GSvector3& v1, const GSvector3& v2 )
{
	if ( v1.x != v2.x ) return v1.x > v2.x;
	if ( v1.y != v2.y ) return v1.y > v2.y;
	return v1.z > v2.z;
}

GSINLINE bool operator <= ( const GSvector3& v1, const GSvector3& v2 )
{
	return	!( v1 > v2 );
}

GSINLINE bool operator >= ( const GSvector3& v1, const GSvector3& v2 )
{
	return	!( v1 < v2 );
}

#endif


#endif

/********** End of File ******************************************************/
