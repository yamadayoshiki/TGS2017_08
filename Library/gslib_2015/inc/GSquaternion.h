/******************************************************************************
* File Name : GSquaternion.h                     Ver : 1.00  Date : 2002-08-14
*
* Description :
*
*       �N�H�[�^�j�I���̌v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSQUATERNION_H_
#define		_GSQUATERNION_H_

#include	"GStype.h"
#include	"GSmath.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionInit
(
	GSquaternion*	pOut,				/*-> �N�H�[�^�j�I��		*/
	GSfloat			x,					/* ������				*/
	GSfloat			y,					/* ������				*/
	GSfloat			z,					/* ������				*/
	GSfloat			w					/* ������				*/
);

/*=============================================================================
*
* Purpose : �P�ʃN�H�[�^�j�I����ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionIdentity
(
	GSquaternion*	pOut				/*-> �N�H�[�^�j�I��		*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̓��ς����߂�D
*
* Return  : ���ς�Ԃ��D
*
*============================================================================*/
extern GSfloat
gsQuaternionDot
(
	const GSquaternion*		q1,			/* �N�H�[�^�j�I��	*/
	const GSquaternion*		q2			/* �N�H�[�^�j�I��	*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̒��������߂�D
*
* Return  : ������Ԃ��D
*
*============================================================================*/
extern GSfloat
gsQuaternionLength
(
	const GSquaternion*		q			/* �N�H�[�^�j�I��	*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̐��K���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionNormalize
(
	GSquaternion*		ans,			/*-> ���K�N�H�[�^�j�I��	*/
	const GSquaternion*	q				/* �N�H�[�^�j�I��		*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionMultiply
(
	GSquaternion*		ans,			/*-> ���~���̌���		*/
	const GSquaternion*	a,				/* �N�H�[�^�j�I����		*/
	const GSquaternion*	b				/* �N�H�[�^�j�I����		*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���ƃX�J���[�̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionMultiplyScalar
(
	GSquaternion*		ans,			/*-> ���~���̌���		*/
	const GSquaternion*	a,				/* �X�J���[				*/
	GSfloat				s				/* �X�J���[				*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̉��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionAdd
(
	GSquaternion*		ans,			/*-> ���{���̌���		*/
	const GSquaternion*	a,				/* �N�H�[�^�j�I����		*/
	const GSquaternion*	b				/* �N�H�[�^�j�I����		*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̌��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionSubtract
(
	GSquaternion*		ans,			/*-> ���|���̌���		*/
	const GSquaternion*	a,				/* �N�H�[�^�j�I����		*/
	const GSquaternion*	b				/* �N�H�[�^�j�I����		*/
);

/*=============================================================================
*
* Purpose : ������̉�]�p�x����N�H�[�^�j�I�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionRotate
(
	GSquaternion*		q,				/* �N�H�[�^�j�I��		*/
	GSfloat				angle,			/* ��]�p�x				*/
	GSfloat				vx,				/* ��]���̂�����		*/
	GSfloat				vy,				/* ��]���̂�����		*/
	GSfloat				vz				/* ��]���̂�����		*/
);

/*=============================================================================
*
* Purpose : ���[�C�s�b�`�C���[������N�H�[�^�j�I�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionYawPitchRoll
(
	GSquaternion*		q,				/* �N�H�[�^�j�I��		*/
	GSfloat				fYaw,			/* ���[					*/
	GSfloat				fPitch,			/* �s�b�`				*/
	GSfloat				fRoll			/* ���[��				*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̐��`��ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionLerp
(
	GSquaternion*		pOut,			/*-> ��Ԃ̌���			*/
	const GSquaternion*	pQ1,			/* �N�H�[�^�j�I��1		*/
	const GSquaternion*	pQ2,			/* �N�H�[�^�j�I��2		*/
	GSfloat				t				/* ��Ԓl				*/
);

/*=============================================================================
*
* Purpose : �t�N�H�[�^�j�I�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionInverse
(
	GSquaternion*		pOut,			/*-> �t�N�H�[�^�j�I��	*/
	const GSquaternion*	q				/* �N�H�[�^�j�I��		*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I�����玲����̉�]�p�x�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsQuaternionToRotate
(
	const GSquaternion*	q,				/* �N�H�[�^�j�I��		*/
	GSfloat*			pAngle,			/*-> ��]�p�x			*/
	GSfloat*			pVx,			/*-> ��]���̂�����		*/
	GSfloat*			pVy,			/*-> ��]���̂�����		*/
	GSfloat*			pVz				/*-> ��]���̂�����		*/
);

/*=============================================================================
*
* Purpose : ��]�s�񂩂�N�H�[�^�j�I�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionRotateMatrix3
(
	GSquaternion*		q,				/* �N�H�[�^�j�I��		*/
	const GSmatrix3*	mat				/* ��]�s��				*/
);

/*=============================================================================
*
* Purpose : ��]�s�񂩂�N�H�[�^�j�I�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionRotateMatrix4
(
	GSquaternion*		q,				/* �N�H�[�^�j�I��		*/
	const GSmatrix4*	mat				/* ��]�s��				*/
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I���̋��ʐ��`��ԁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionSlerp
(
	GSquaternion*		pOut,			/*-> ��Ԃ̌���			*/
	const GSquaternion*	a,				/* �N�H�[�^�j�I��1		*/
	const GSquaternion*	b,				/* �N�H�[�^�j�I��2		*/
	GSfloat				t				/* ��Ԓl				*/
);

#ifdef __cplusplus
}
#endif

/*----- �b�{�{���b�p�[�N���X ------------------------------------------------*/

#ifdef __cplusplus

/* �R���X�g���N�^ */
GSINLINE GSquaternion::GSquaternion( GSfloat X, GSfloat Y, GSfloat Z, GSfloat W ) :
	x( X ), y( Y ), z( Z ), w( W )
{
}

GSINLINE GSquaternion::GSquaternion( GSfloat angle, const GSvector3& axis )
{
	gsQuaternionRotate( this, angle, axis.x, axis.y, axis.z );
}

GSINLINE GSquaternion::GSquaternion( const GSmatrix3& m )
{
	gsQuaternionRotateMatrix3( this, &m );
}

GSINLINE GSquaternion::GSquaternion( const GSmatrix4& m )
{
	gsQuaternionRotateMatrix4( this, &m );
}

GSINLINE GSquaternion::GSquaternion( const GSvector3& xAxis, const GSvector3& yAxis, const GSvector3& zAxis )
{
	GSmatrix3	M;

	M._11 = xAxis.x; M._12 = xAxis.y; M._13 = xAxis.z;
	M._21 = yAxis.x; M._22 = yAxis.y; M._23 = yAxis.z;
	M._31 = zAxis.x; M._32 = zAxis.y; M._33 = zAxis.z;

	gsQuaternionRotateMatrix3( this, &M );
}

/* �P�ʃN�H�[�^�j�I�������� */
GSINLINE GSquaternion& GSquaternion::identity()
{
	gsQuaternionIdentity( this );

	return	*this;
}

/* ���� */
GSINLINE GSfloat GSquaternion::dot( const GSquaternion& q ) const
{
	return	gsQuaternionDot( this, &q );
}

/* ���������߂� */
GSINLINE GSfloat GSquaternion::length() const
{
	gsQuaternionLength( this );
}

/* ���K�����s�� */
GSINLINE GSquaternion& GSquaternion::normalize()
{
	gsQuaternionNormalize( this, this );

	return	*this;
}

/* �t�N�H�[�^�j�I�������� */
GSINLINE GSquaternion& GSquaternion::inverse()
{
	gsQuaternionInverse( this, this );

	return	*this;
}

/* ���K����̃N�H�[�^�j�I�����擾 */
GSINLINE GSquaternion GSquaternion::getNormalized() const
{
	GSquaternion	result( *this );

	result.normalize();

	return	result;
}

/* �t�N�H�[�^�j�I�������擾 */
GSINLINE GSquaternion GSquaternion::getInverse () const
{
	GSquaternion	result( *this );

	result.inverse();

	return	result;
}

/* ��]�p�x����N�H�[�^�j�I����ݒ� */
GSINLINE GSquaternion& GSquaternion::setRotate( GSfloat angle, GSfloat x_, GSfloat y_, GSfloat z_ )
{
	gsQuaternionRotate( this, angle, x_, y_, z_ );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::setRotate( GSfloat angle, const GSvector3& axis )
{
	setRotate( angle, axis.x, axis.y, axis.z );

	return	*this;
}

/* ��]�p�x����N�H�[�^�j�I����ݒ� */
GSINLINE GSquaternion& GSquaternion::setRotateYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll )
{
	gsQuaternionYawPitchRoll( this, yaw, pitch, roll );

	return	*this;
}

/* ��]�s���ݒ� */
GSINLINE GSquaternion& GSquaternion::setMatrix( const GSmatrix3& m )
{
	gsQuaternionRotateMatrix3( this, &m );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::setMatrix( const GSmatrix4& m )
{
	gsQuaternionRotateMatrix4( this, &m );

	return	*this;
}

/* ���Ɗp�x���擾 */
GSINLINE GSvector3 GSquaternion::getAxis() const
{
	GSvector3	v;
	GSfloat		angle;

	gsQuaternionToRotate( this, &angle, &v.x, &v.y, &v.z );

	return	v;
}

GSINLINE GSfloat GSquaternion::getAngle() const
{
	return	gsAcos( w ) * 2.0f;
}

/* ���[�C�s�b�`�C���[���̎擾 */
GSINLINE GSfloat GSquaternion::getYaw() const
{
	return	gsDegreeNormalize( gsAsin( -2.0f * ( x*z - w*y ) ) );
}

GSINLINE GSfloat GSquaternion::getPitch() const
{
	return	gsAtan( 2.0f *( y*z + w*x ), w*w - x*x - y*y + z*z );
}

GSINLINE GSfloat GSquaternion::getRoll() const
{
	return	gsAtan( 2.0f * (x*y + w*z), w*w + x*x - y*y - z*z );
}

/* ���ʐ��`��� */
GSINLINE GSquaternion GSquaternion::slerp ( const GSquaternion& q, GSfloat t ) const
{
	GSquaternion	result;

	gsQuaternionSlerp( &result, this, &q, t );

	return	result;
}

/* ���`��� */
GSINLINE GSquaternion GSquaternion::lerp ( const GSquaternion& q, GSfloat t ) const
{
	GSquaternion	result;

	gsQuaternionLerp( &result, this, &q, t );

	return	result;
}

/* �P�����Z�q�I�[�o�[���[�h */
GSINLINE GSquaternion GSquaternion::operator + () const
{
	return	*this;
}

GSINLINE GSquaternion GSquaternion::operator - () const
{
	return	GSquaternion( -x, -y, -z, -w );
}

/* ������Z�q�I�[�o�[���[�h */
GSINLINE GSquaternion& GSquaternion::operator += ( const GSquaternion& v )
{
	gsQuaternionAdd( this, this, &v );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::operator -= ( const GSquaternion& v )
{
	gsQuaternionSubtract( this, this, &v );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::operator *= ( const GSquaternion& v )
{
	gsQuaternionMultiply( this, this, &v );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::operator *= ( GSfloat s )
{
	gsQuaternionMultiplyScalar( this, this, s );

	return	*this;
}

GSINLINE GSquaternion& GSquaternion::operator /= ( GSfloat s )
{
	gsQuaternionMultiplyScalar( this, this, 1.0f / s );

	return	*this;
}

/* �Q�����Z�q�I�[�o�[���[�h */
GSINLINE const GSquaternion operator + ( const GSquaternion& q1, const GSquaternion& q2 )
{
	GSquaternion	result;

	gsQuaternionAdd( &result, &q1, &q2 );

	return	result;
}

GSINLINE const GSquaternion operator - ( const GSquaternion& q1, const GSquaternion& q2 )
{
	GSquaternion	result;

	gsQuaternionSubtract( &result, &q1, &q2 );

	return	result;
}

GSINLINE const GSquaternion operator * ( const GSquaternion& q1, const GSquaternion& q2 )
{
	GSquaternion	result;

	gsQuaternionMultiply( &result, &q1, &q2 );

	return	result;
}

GSINLINE const GSquaternion operator * ( const GSquaternion& q, const GSfloat s )
{
	GSquaternion	result;

	gsQuaternionMultiplyScalar( &result, &q, s );

	return	result;
}

GSINLINE const GSquaternion operator * ( const GSfloat s, const GSquaternion& q )
{
	return	q * s;
}

GSINLINE bool operator == ( const GSquaternion& q1, const GSquaternion& q2 )
{
	return	( q1.x == q2.x && q1.y == q2.y && q1.z == q2.z && q1.w == q2.w );
}

GSINLINE bool operator != ( const GSquaternion& q1, const GSquaternion& q2 )
{
	return	!( q1 == q2 );
}

#endif

#endif

/********** End of File ******************************************************/
