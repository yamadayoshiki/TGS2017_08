/******************************************************************************
* File Name : GSmath.h                              Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �Q�[���V�X�e�� ��{�v�Z ��`�w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSMATH_H_
#define		_GSMATH_H_

#include	"GStype.h"
#include	<math.h>
#include	<stdio.h>
#include	<time.h>

/****** �萔�錾 *************************************************************/

#define	GS_PI	3.14159265358979323846264f	/* �~����               */

/****** �}�N���֐��錾 *******************************************************/

/* �����l�̌ܓ����Đ����^�ɕϊ����� */
#define	ROUND( a )			(int)( ( (a) > 0 ) ? ( (a)+0.5F ): ( (a)-0.5F ) )

/* ���̐�Βl�����߂� */
#define	ABS( a )			( ( (a) < 0 ) ? -(a) : (a) )

/* ���C���̏��������̒l�����߂� */
#define	MIN( a, b )			( ( (a) < (b) ) ? (a) : (b) )

/* ���C���傫�����̒l�����߂� */
#define	MAX( a , b )		( ( (a) > (b) ) ? (a) : (b) )

/* �������Ȃ�P�C���Ȃ�|�P�C�[���Ȃ�O�����߂� */
#define	ZSGN( a )			( ( (a) < 0 ) ? -1 : (a) > 0 ? 1 : 0 )

/* �������܂��̓[���Ȃ�P�C���Ȃ�|�P�����߂� */
#define	SGN( a )			( ( (a) < 0 ) ? -1 : 1 )

/* �����悷�� */
#define	SQR( a )			( (a) * (a) )

/* ���������炈�̒l�ɗ��߂� */
#define	CLAMP( v, l, h )	MAX( l, MIN( v, h ) )

/* �����炈�܂ł���`��Ԃ��� �i ���� 0.0 ���� 1.0 ) */
#define	LERP( a, l, h )		( (l) + ( ( (h) - (l) ) * (a) ) )

/* ���P�C���Q�C���R���Q����Ԃ��� �i ���� 0.0 ���� 1.0 ) */
#define	QUADRATIC( a, v1, v2, v3 )										\
(																		\
	(v1)*(1.0f-(a))*(1.0f-(a)) + 2*(v2)*(a)*(1.0f-(a)) + (v3)*(a)*(a)	\
)

/* �z��̗v�f�������߂� */
#define	ARRAY_LENGTH( a )	( sizeof( a ) / sizeof( a[0] ) )

/* ���W�A�����p�x�ɕϊ� */
#define	RAD_TO_DEG( rad )	( (rad) * ( 1.0f / GS_PI * 180.0f ) )

/* �p�x�����W�A���ɕϊ� */
#define	DEG_TO_RAD( deg )	( (deg) * ( 1.0f / 180.0f * GS_PI ) )

/* �p�x�̐��K�������� */
#define	gsDegreeNormalize( x )												\
(																			\
	( (x) >= 0.0f ) ? (GSfloat)fmod( x, 360.0f ): (GSfloat)fmod( x, 360.0f ) + 360.0f \
)

/* �O�p�֐��֌W */
#define	gsCos( x )		( (GSfloat)cos( DEG_TO_RAD( x ) ) )
#define	gsSin( x )		( (GSfloat)sin( DEG_TO_RAD( x ) ) )
#define	gsTan( x )		( (GSfloat)tan( DEG_TO_RAD( x ) ) )
#define	gsAcos( x )		( (GSfloat)RAD_TO_DEG( acos( x ) ) )
#define	gsAsin( x )		( (GSfloat)RAD_TO_DEG( asin( x ) ) )
#define	gsAtan( x, y )	( (GSfloat)gsDegreeNormalize( RAD_TO_DEG( atan2( y, x ) ) ) )

/* �����������߂� */
#define	gsSqrt( x )		( (GSfloat)sqrt( x ) )

/* �����̏��������s�� */
#define	gsRandamize()	( srand( (unsigned int)time(NULL) ), srand( rand() ) )

/* ���������_�̗����l�����߂�*/
#define	gsRandf( min, max )										\
(																\
	( (float)rand() / RAND_MAX ) * ( (max) - (min) ) + (min)	\
)

/* �����l�����߂�*/
#define	gsRand( min, max )										\
(																\
	( rand() % (int)( (max) - (min) + 1 ) ) + (int)(min)		\
)

#endif

/********** End of File ******************************************************/
