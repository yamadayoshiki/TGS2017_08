/******************************************************************************
* File Name : GSmatrix3.c                        Ver : 1.00  Date : 1998-05-03
*
* Description :
*
*       �R�s�R����W�ϊ��s��v�Z �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSMATRIX3_H_
#define		_GSMATRIX3_H_

#include	"GStype.h"
#include	"GSvector2.h"
#include	"GSvector3.h"
#include	"GSquaternion.h"

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �P�ʍs������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Identity
(
	GSmatrix3*			pM				/* �R�c�}�g���N�X   */
);

/*=============================================================================
*
* Purpose : ���s�ړ��s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Translate
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				tx,				/* �������ړ���			*/
	GSfloat				ty				/* �������ړ���			*/
);

/*=============================================================================
*
* Purpose : �g��E�k���s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Scale
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				sx,				/* �������X�P�[���l		*/
	GSfloat				sy,				/* �������X�P�[���l		*/
	GSfloat				sz				/* �������X�P�[���l		*/
);

/*=============================================================================
*
* Purpose : ��]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Rotate
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				angle,			/* ��]�p�x				*/
	GSfloat				dx,				/* ��]���̂�����		*/
	GSfloat				dy,				/* ��]���̂�����		*/
	GSfloat				dz				/* ��]���̂�����		*/
);

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3RotateX
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				angle			/* ��������̊p�x       */
);

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3RotateY
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				angle			/* ��������̊p�x       */
);

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3RotateZ
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	GSfloat				angle			/* ��������̊p�x       */
);

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I�������]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Quaternion
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
	const GSquaternion*	q				/* �N�H�[�^�j�I��		*/
);

/*=============================================================================
*
* Purpose : �s��̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Multiply
(
	GSmatrix3*			pOut,			/*-> ��Z�̌���     */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
);

/*=============================================================================
*
* Purpose : �s��ƃX�J���[�̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3MultiplyScalar
(
	GSmatrix3*			pOut,			/*-> �|���Z�̌���   */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	GSfloat				Scalar			/* �X�J���[         */
);

/*=============================================================================
*
* Purpose : �s��̉��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Add
(
	GSmatrix3*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
);

/*=============================================================================
*
* Purpose : �s��̌��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Subtract
(
	GSmatrix3*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
);

/*=============================================================================
*
* Purpose : �]�u�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3Transpose
(
	GSmatrix3*			pOut,			/* �]�u�R�c�}�g���N�X   */
	const GSmatrix3*	pM				/* �R�c�}�g���N�X       */
);

/*=============================================================================
*
* Purpose : �t�s������߂�D
*
* Return  : �t�s�񂪋��܂�ΐ^�C���܂�Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern	GSboolean
gsMatrix3Inverse
(
	GSmatrix3*			pOut,			/* �t�R�c�}�g���N�X     */
	const GSmatrix3*	pM				/* �R�c�}�g���N�X       */
);

/*=============================================================================
*
* Purpose : ���[�C�s�b�`�C���[�������]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix3YawPitchRoll
(
	GSmatrix3*			pOut,			/* ��]�}�g���N�X					*/
	GSfloat				Yaw,			/*-> ���[  �i��������̉�]�p�x�j	*/
	GSfloat				Pitch,			/*-> �s�b�`�i��������̉�]�p�x�j	*/
	GSfloat				Roll			/*-> ���[���i�y�������̉�]�p�x�j	*/
);

/*=============================================================================
*
* Purpose : ��]�s�񂩂烍�[�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix3GetRoll
(
	const GSmatrix3*	pM				/* �s��								*/
);

/*=============================================================================
*
* Purpose : ��]�s�񂩂�s�b�`�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix3GetPitch
(
	const GSmatrix3*	pM				/* �s��								*/
);

/*=============================================================================
*
* Purpose : ��]�s�񂩂烈�[�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix3GetYaw
(
	const GSmatrix3*	pM				/* �s��								*/
);

#ifdef __cplusplus
}
#endif

/*----- �b�{�{���b�p�[�N���X ------------------------------------------------*/

#ifdef __cplusplus


/* �R���X�g���N�^ */
GSINLINE GSmatrix3::GSmatrix3(
	GSfloat	m11, GSfloat m12, GSfloat m13,
	GSfloat	m21, GSfloat m22, GSfloat m23,
	GSfloat	m31, GSfloat m32, GSfloat m33 ) :
		_11( m11 ), _12( m12 ), _13( m13 ),
		_21( m21 ), _22( m22 ), _23( m23 ),
		_31( m31 ), _32( m32 ), _33( m33 )
{}

GSINLINE GSmatrix3::GSmatrix3(
	const GSvector3& axisX,
	const GSvector3& axisY,
	const GSvector3& axisZ ) :
	_11( axisX.x ), _12( axisX.y ), _13( axisX.z ),
	_21( axisY.x ), _22( axisY.y ), _23( axisY.z ),
	_31( axisZ.x ), _32( axisZ.y ), _33( axisZ.z )
{}

GSINLINE GSmatrix3::GSmatrix3( const GSfloat* p ) :
	_11( p[0]  ), _12( p[1]  ), _13( p[2] ),
	_21( p[3]  ), _22( p[4]  ), _23( p[5] ),
	_31( p[6]  ), _32( p[7]  ), _33( p[8] )
{}

GSINLINE GSmatrix3::GSmatrix3( const GSmatrix4& M ) :
	_11( M._11 ), _12( M._12 ), _13( M._13 ),
	_21( M._21 ), _22( M._22 ), _23( M._23 ),
	_31( M._31 ), _32( M._32 ), _33( M._33 )
{}

GSINLINE GSmatrix3::GSmatrix3( const GSquaternion& q )
{
	gsMatrix3Quaternion( this, &q );
}

/* �t�s��ɂ��� */
GSINLINE GSmatrix3& GSmatrix3::inverse()
{
	gsMatrix3Inverse( this, this );

	return	*this;
}

/* �]�u�s��ɂ��� */
GSINLINE GSmatrix3& GSmatrix3::transpose()
{
	gsMatrix3Transpose( this, this );

	return	*this;
}

/* �t�s��]�u�s��ɂ��� */
GSINLINE GSmatrix3& GSmatrix3::inverseTranspose()
{
	inverse();

	transpose();

	return	*this;
}

/* �t�s����擾 */
GSINLINE GSmatrix3 GSmatrix3::getInverse() const
{
	GSmatrix3		result;

	gsMatrix3Inverse( &result, this );

	return	result;
}

/* �]�u�s����擾 */
GSINLINE GSmatrix3 GSmatrix3::getTranspose() const
{
	GSmatrix3		result;

	gsMatrix3Transpose( &result, this );

	return	result;
}

/* �]�u�t�s����擾 */
GSINLINE GSmatrix3 GSmatrix3::getInverseTranspose() const
{
	GSmatrix3		result;

	gsMatrix3Inverse( &result, this );

	gsMatrix3Transpose( &result, this );

	return	result;
}

/* �X�P�[���l�̐ݒ� */
GSINLINE GSmatrix3& GSmatrix3::setScale( GSfloat x, GSfloat y, GSfloat z )
{
	gsMatrix3Scale( this, x, y, z );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setScale( const GSvector3& scaleFactor )
{
	return	setScale( scaleFactor.x, scaleFactor.y, scaleFactor.z );
}

GSINLINE GSmatrix3& GSmatrix3::setScale( GSfloat scaleFactor )
{
	return	setScale( scaleFactor, scaleFactor, scaleFactor );
}

/* ��]�p�x�̐ݒ� */
GSINLINE GSmatrix3& GSmatrix3::setRotation( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ )
{
	gsMatrix3Rotate( this, angle, axisX, axisY, axisZ );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setRotation( GSfloat angle, const GSvector3& axis )
{
	return setRotation( angle, axis.x, axis.y, axis.z );
}

GSINLINE GSmatrix3& GSmatrix3::setRotation( const GSquaternion& q )
{
	gsMatrix3Quaternion( this, &q );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setRotationX( GSfloat angle )
{
	gsMatrix3RotateX( this, angle );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setRotationY( GSfloat angle )
{
	gsMatrix3RotateY( this, angle );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setRotationZ( GSfloat angle )
{
	gsMatrix3RotateZ( this, angle );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setRotationYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll )
{
	gsMatrix3YawPitchRoll( this, yaw, pitch, roll );

	return	*this;
}

/* ���s�ړ��ʂ̐ݒ� */
GSINLINE GSmatrix3& GSmatrix3::setTranslation( GSfloat x, GSfloat y )
{
	gsMatrix3Translate( this, x, y );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setTranslation( const GSvector2& translation )
{
	return	setTranslation( translation.x, translation.y );
}

/* �P�ʍs�񉻂��� */
GSINLINE GSmatrix3& GSmatrix3::identity()
{
	gsMatrix3Identity( this );

	return	*this;
}

/* �s��̐��K���@*/
GSINLINE GSmatrix3& GSmatrix3::normalize()
{
	setAxisX(getAxisX().getNormalized());
	setAxisY(getAxisY().getNormalized());
	return	*this;
}

/* �s��̐��K���@*/
GSINLINE GSmatrix3 GSmatrix3::getNormalized() const
{
	GSmatrix3 result = *this;
	return	result.normalize();
}

/* �g��k���s�����Z */
GSINLINE GSmatrix3& GSmatrix3::scale( GSfloat x, GSfloat y, GSfloat z )
{
	GSmatrix3	s;

	gsMatrix3Multiply(this, this, &s.setScale(x, y, z) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::scale( const GSvector3& scaleFactor )
{
	return	scale( scaleFactor.x, scaleFactor.y, scaleFactor.z );
}

GSINLINE GSmatrix3& GSmatrix3::scale( GSfloat scaleFactor )
{
	return	scale( scaleFactor, scaleFactor, scaleFactor );
}

/* ��]�s�����Z */
GSINLINE GSmatrix3& GSmatrix3::rotate( GSfloat angle, GSfloat axisX, GSfloat axisY, GSfloat axisZ )
{
	GSmatrix3	r;

	gsMatrix3Multiply(this, this, &r.setRotation(angle, axisX, axisY, axisZ) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::rotate( GSfloat angle, const GSvector3& axis )
{
	return rotate( angle, axis.x, axis.y, axis.z );
}

GSINLINE GSmatrix3& GSmatrix3::rotate( const GSquaternion& q )
{
	GSmatrix3	r;

	gsMatrix3Multiply( this, this, &r.setRotation(q) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::rotateX( GSfloat angle )
{
	GSmatrix3	r;

	gsMatrix3Multiply( this, this, &r.setRotationX( angle ) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::rotateY( GSfloat angle )
{
	GSmatrix3	r;

	gsMatrix3Multiply( this, this, &r.setRotationY(angle) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::rotateZ( GSfloat angle )
{
	GSmatrix3	r;

	gsMatrix3Multiply( this, this, &r.setRotationZ(angle) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::rotateYawPitchRoll( GSfloat yaw, GSfloat pitch, GSfloat roll )
{
	GSmatrix3	r;

	gsMatrix3Multiply( this, this, &r.setRotationYawPitchRoll(yaw, pitch, roll) );

	return	*this;
}

/* ���s�ړ��s�����Z */
GSINLINE GSmatrix3& GSmatrix3::translate( GSfloat x, GSfloat y )
{
	GSmatrix3	t;

	gsMatrix3Multiply( this, this, &t.setTranslation(x, y) );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::translate( const GSvector2& translation )
{
	translate( translation.x, translation.y );

	return	*this;
}

/* ���W�ϊ� */
GSINLINE GSvector2 GSmatrix3::transform( const GSvector2& v2 ) const
{
	GSvector2	result;

	gsVector2Transform( &result, &v2, this );

	return	result;
}

GSINLINE GSvector3 GSmatrix3::transform( const GSvector3& v3 ) const
{
	GSvector3	result;

	result = *this * v3;

	return	result;
}

GSINLINE GSvector2 GSmatrix3::transformNormal( const GSvector2& v2 ) const
{
	GSvector2	result;

	gsVector2TransformNormal( &result, &v2, this );

	return	result;
}

/* �X�P�[���l�̎擾 */
GSINLINE GSvector3 GSmatrix3::getScale() const
{
	return	GSvector3(getAxisX().length(), getAxisY().length(), getAxisZ().length());
}

/* �s��̕�ԁ@*/
GSINLINE GSmatrix3 GSmatrix3::lerp(const GSmatrix3& other, float t) const
{
	GSvector3    s = getScale().lerp(other.getScale(), t);
	GSquaternion r = GSquaternion(getNormalized()).slerp(GSquaternion(other.getNormalized()), t);
	return	GSmatrix3().identity().scale(s).rotate(r);
}

/* ���̐ݒ� */
GSINLINE GSmatrix3& GSmatrix3::setAxisX( const GSvector3& axisX )
{
	_11 = axisX.x; _12 = axisX.y; _13 = axisX.z;

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setAxisY( const GSvector3& axisY )
{
	_21 = axisY.x; _22 = axisY.y; _23 = axisY.z;

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::setAxisZ( const GSvector3& axisZ )
{
	_31 = axisZ.x; _32 = axisZ.y; _33 = axisZ.z;

	return	*this;
}

/* ���̎擾 */
GSINLINE GSvector3 GSmatrix3::getAxisX() const
{
	return	GSvector3( _11, _12, _13 );
}

GSINLINE GSvector3 GSmatrix3::getAxisY() const
{
	return	GSvector3( _21, _22, _23 );
}

GSINLINE GSvector3 GSmatrix3::getAxisZ() const
{
	return	GSvector3( _31, _32, _33 );
}

/* ���[���E�s�b�`�E���[�̎擾 */
GSINLINE GSfloat GSmatrix3::getRoll() const
{
	return	gsMatrix3GetRoll( this );
}

GSINLINE GSfloat GSmatrix3::getPitch() const
{
	return	gsMatrix3GetPitch( this );
}

GSINLINE GSfloat GSmatrix3::getYaw() const
{
	return	gsMatrix3GetYaw( this );
}

/* �N�H�[�^�j�I�����擾 */
GSINLINE GSquaternion GSmatrix3::getQuaternion() const
{
	GSquaternion	q;

	gsQuaternionRotateMatrix3( &q, this );

	return	q;
}

GSINLINE GSmatrix3::operator GSfloat* () const
{
	return	(GSfloat*)v;
}

GSINLINE GSmatrix3::operator const GSfloat* () const
{
	return	(const GSfloat*)v;
}

/* �P�����Z�q�I�[�o�[���[�h */
GSINLINE GSmatrix3 GSmatrix3::operator + () const
{
	return	*this;
}

GSINLINE GSmatrix3 GSmatrix3::operator - () const
{
	return	GSmatrix3( -_11, -_12, -_13, 
					   -_21, -_22, -_23, 
					   -_31, -_32, -_33 );
}

/* ������Z�q�I�[�o�[���[�h */
GSINLINE GSmatrix3& GSmatrix3::operator += ( const GSmatrix3& M )
{
	gsMatrix3Add( this, this, &M );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::operator -= ( const GSmatrix3& M )
{
	gsMatrix3Subtract( this, this, &M );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::operator *= ( const GSmatrix3& M )
{
	gsMatrix3Multiply( this, this, &M );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::operator *= ( GSfloat s )
{
	gsMatrix3MultiplyScalar( this, this, s );

	return	*this;
}

GSINLINE GSmatrix3& GSmatrix3::operator /= ( GSfloat s )
{
	gsMatrix3MultiplyScalar( this, this, 1.0f / s );

	return	*this;
}

/* �Q�����Z�q�I�[�o�[���[�h */
GSINLINE const GSmatrix3 operator + ( const GSmatrix3& m1, const GSmatrix3& m2 )
{
	GSmatrix3	result;

	gsMatrix3Add( &result, &m1, &m2 );

	return	result;
}

GSINLINE const GSmatrix3 operator - ( const GSmatrix3& m1, const GSmatrix3& m2 )
{
	GSmatrix3	result;

	gsMatrix3Subtract( &result, &m1, &m2 );

	return	result;
}

GSINLINE const GSmatrix3 operator * ( const GSmatrix3& m1, const GSmatrix3& m2 )
{
	GSmatrix3	result;

	gsMatrix3Multiply( &result, &m1, &m2 );

	return	result;
}

GSINLINE const GSmatrix3 operator * ( const GSmatrix3& m, const GSfloat s )
{
	GSmatrix3	result;

	gsMatrix3MultiplyScalar( &result, &m, s );

	return	result;
}

GSINLINE const GSmatrix3 operator * ( const GSfloat s, const GSmatrix3& m )
{
	return	m * s;
}

GSINLINE const GSmatrix3 operator / ( const GSmatrix3& m, const GSfloat s )
{
	return	m * ( 1.0f / s ) ;
}

GSINLINE bool operator == ( const GSmatrix3& m1, const GSmatrix3& m2 )
{
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			if ( m1.m[i][j] != m2.m[i][j] ) return false;
		}
	}

	return	true;
}

GSINLINE bool operator != ( const GSmatrix3& m1, const GSmatrix3& m2 )
{
	return	!( m1 == m2 );
}

#endif

#endif

/********** End of File ******************************************************/
