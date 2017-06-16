/******************************************************************************
* File Name : GSmatrix4.c                        Ver : 1.00  Date : 1998-05-03
*
* Description :
*
*       �O�������W�ϊ��s��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSmatrix4.h"
#include	"GSvector3.h"
#include	"GSplane.h"
#include	"GSmath.h"
#include	<float.h>

const GSmatrix4 GS_MATRIX4_IDENTITY = {
	1.0F, 0.0F, 0.0F, 0.0F,
	0.0F, 1.0F, 0.0F, 0.0F,
	0.0F, 0.0F, 1.0F, 0.0F,
	0.0F, 0.0F, 0.0F, 1.0F
};

/*=============================================================================
*
* Purpose : �P�ʍs������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Identity
(
	GSmatrix4*		pM					/* �R�c�}�g���N�X   */
)
{
	*pM = GS_MATRIX4_IDENTITY;
}

/*=============================================================================
*
* Purpose : ���s�ړ��s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Translate
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			tx,					/* �������ړ���			*/
	GSfloat			ty,					/* �������ړ���			*/
	GSfloat			tz					/* �������ړ���			*/
)
{
	pM->m[0][0] = 1.0f;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = 1.0f;
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = 1.0f;
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = tx;
	pM->m[3][1] = ty;
	pM->m[3][2] = tz;
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : �g��E�k���s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Scale
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			sx,					/* �������X�P�[���l		*/
	GSfloat			sy,					/* �������X�P�[���l		*/
	GSfloat			sz					/* �������X�P�[���l		*/
)
{
	pM->m[0][0] = sx;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = sy;
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = sz;
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : ��]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Rotate
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle,				/* ��]�p�x				*/
	GSfloat			dx,					/* ��]���̂�����		*/
	GSfloat			dy,					/* ��]���̂�����		*/
	GSfloat			dz					/* ��]���̂�����		*/
)
{
	GSfloat			sinAngle;
	GSfloat			cosAngle;
	GSfloat			oneMinusCosAngle;
	GSfloat			Len;

	sinAngle         = gsSin(angle);
	cosAngle         = gsCos(angle);
	oneMinusCosAngle = 1.0f - cosAngle;

	if ( ( Len = gsSqrt( dx * dx + dy * dy + dz * dz ) ) != 0 )
	{
		dx *= ( 1.0f / Len );
		dy *= ( 1.0f / Len );
		dz *= ( 1.0f / Len );
	}

	pM->m[0][0] = ( dx * dx ) + cosAngle * ( 1.0f - ( dx * dx ) );
	pM->m[1][0] = ( dx * dy ) * oneMinusCosAngle - sinAngle * dz;
	pM->m[2][0] = ( dx * dz ) * oneMinusCosAngle + sinAngle * dy;
	pM->m[3][0] = 0.0f;

	pM->m[0][1] = ( dx * dy ) * oneMinusCosAngle + sinAngle * dz;
	pM->m[1][1] = ( dy * dy ) + cosAngle * ( 1.0f - ( dy * dy ) );
	pM->m[2][1] = ( dy * dz ) * oneMinusCosAngle - sinAngle * dx;
	pM->m[3][1] = 0.0f;

	pM->m[0][2] = ( dx * dz ) * oneMinusCosAngle - sinAngle * dy;
	pM->m[1][2] = ( dy * dz ) * oneMinusCosAngle + sinAngle * dx;
	pM->m[2][2] = ( dz * dz ) + cosAngle * ( 1.0f - ( dz * dz ) );
	pM->m[3][2] = 0.0f;

	pM->m[0][3] = 0.0f;
	pM->m[1][3] = 0.0f;
	pM->m[2][3] = 0.0f;
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4RotateX
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][0] = 1.0f;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;

	pM->m[1][1] = gsCos( angle );
	pM->m[1][2] = gsSin( angle );
	pM->m[2][1] = -pM->m[1][2];
	pM->m[2][2] =  pM->m[1][1];
}

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4RotateY
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][1] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = 1.0f;
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][1] = 0.0f;
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;

	pM->m[0][0] =  gsCos( angle );
	pM->m[2][0] =  gsSin( angle );
	pM->m[0][2] = -pM->m[2][0];
	pM->m[2][2] =  pM->m[0][0];
}

/*=============================================================================
*
* Purpose : ��������̉�]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4RotateZ
(
	GSmatrix4*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = 1.0f;
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;

	pM->m[0][0] =  gsCos( angle );
	pM->m[0][1] =  gsSin( angle );
	pM->m[1][0] = -pM->m[0][1];
	pM->m[1][1] =  pM->m[0][0];
}

/*=============================================================================
*
* Purpose : �N�H�[�^�j�I�������]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Quaternion
(
	GSmatrix4*			pM,				/* �R�c�}�g���N�X       */
	const GSquaternion*	q				/* �N�H�[�^�j�I��		*/
)
{
	GSfloat		xx, yy, zz;
	GSfloat		xy, xz, yz;
	GSfloat		wx, wy, wz;

	xx = q->x * q->x * 2.0f;
	yy = q->y * q->y * 2.0f;
	zz = q->z * q->z * 2.0f;
	xy = q->x * q->y * 2.0f;
	xz = q->x * q->z * 2.0f;
	yz = q->y * q->z * 2.0f;
	wx = q->w * q->x * 2.0f;
	wy = q->w * q->y * 2.0f;
	wz = q->w * q->z * 2.0f;

	pM->m[0][0] = 1.0f - ( yy + zz );
	pM->m[0][1] = xy + wz;
	pM->m[0][2] = xz - wy;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = xy - wz;
	pM->m[1][1] = 1.0f - ( xx + zz );
	pM->m[1][2] = yz + wx;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = xz + wy;
	pM->m[2][1] = yz - wx;
	pM->m[2][2] = 1.0f - ( xx + yy );
	pM->m[2][3] = 0.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : �s��̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Multiply
(
	GSmatrix4*			pOut,			/*-> �|���Z�̌���   */
	const GSmatrix4*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix4*	pM2				/* �R�c�}�g���N�X   */
)
{
	GSmatrix4			M;
	int					i, j;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			M.m[i][j] = pM1->m[i][0] * pM2->m[0][j]
					  + pM1->m[i][1] * pM2->m[1][j]
					  + pM1->m[i][2] * pM2->m[2][j]
					  + pM1->m[i][3] * pM2->m[3][j];
		}
	}

	*pOut = M;
}

/*=============================================================================
*
* Purpose : �s��ƃX�J���[�̏�Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4MultiplyScalar
(
	GSmatrix4*			pOut,			/*-> �|���Z�̌���   */
	const GSmatrix4*	pM1,			/* �R�c�}�g���N�X   */
	GSfloat				Scalar			/* �X�J���[         */
)
{
	int					i, j;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			pOut->m[i][j] = pM1->m[i][j] * Scalar;
		}
	}
}

/*=============================================================================
*
* Purpose : �s��̉��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Add
(
	GSmatrix4*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix4*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix4*	pM2				/* �R�c�}�g���N�X   */
)
{
	int					i, j;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			pOut->m[i][j] = pM1->m[i][j] + pM2->m[i][j];
		}
	}
}

/*=============================================================================
*
* Purpose : �s��̌��Z�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Subtract
(
	GSmatrix4*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix4*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix4*	pM2				/* �R�c�}�g���N�X   */
)
{
	int					i, j;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			pOut->m[i][j] = pM1->m[i][j] - pM2->m[i][j];
		}
	}
}

/*=============================================================================
*
* Purpose : �����ϊ��s������߂�D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4PerspectiveRH
(
	GSmatrix4*	pM,						/* �����ϊ��}�g���N�X			*/
	GSfloat		Fov,					/* ����p						*/
	GSfloat		Aspect,					/* �A�X�y�N�g��					*/
	GSfloat 	zNear,					/* �߃N���b�v�ʂ܂ł̋���		*/
	GSfloat 	zFar					/* ���N���b�v�ʂ܂ł̋���		*/
)
{
	GSfloat			f;

	f = gsCos( Fov / 2.0f ) / gsSin( Fov / 2.0f );

	pM->m[0][0] = f / Aspect;
	pM->m[0][1] = 0;
	pM->m[0][2] = 0;
	pM->m[0][3] = 0;

	pM->m[1][0] = 0;
	pM->m[1][1] = f;
	pM->m[1][2] = 0;
	pM->m[1][3] = 0;

	pM->m[2][0] = 0;
	pM->m[2][1] = 0;
	pM->m[2][2] = ( zFar + zNear ) / ( zNear - zFar );
	pM->m[2][3] = -1.0f;

	pM->m[3][0] = 0;
	pM->m[3][1] = 0;
	pM->m[3][2] = ( 2.0f * zFar * zNear ) / ( zNear - zFar );
	pM->m[3][3] = 0;
}

/*=============================================================================
*
* Purpose : �����ϊ��s������߂�D�i������W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4PerspectiveLH
(
	GSmatrix4*	pM,						/* �����ϊ��}�g���N�X			*/
	GSfloat		Fov,					/* ����p						*/
	GSfloat		Aspect,					/* �A�X�y�N�g��					*/
	GSfloat 	zNear,					/* �߃N���b�v�ʂ܂ł̋���		*/
	GSfloat 	zFar					/* ���N���b�v�ʂ܂ł̋���		*/
)
{
	GSfloat		f;

	f = gsCos( Fov / 2.0f ) / gsSin( Fov / 2.0f );

	pM->m[0][0] = f / Aspect;
	pM->m[0][1] = 0;
	pM->m[0][2] = 0;
	pM->m[0][3] = 0;

	pM->m[1][0] = 0;
	pM->m[1][1] = f;
	pM->m[1][2] = 0;
	pM->m[1][3] = 0;

	pM->m[2][0] = 0;
	pM->m[2][1] = 0;
	pM->m[2][2] = ( zFar + zNear ) / ( zNear - zFar );
	pM->m[2][3] = 1.0f;

	pM->m[3][0] = 0;
	pM->m[3][1] = 0;
	pM->m[3][2] = ( 2.0f * zFar * zNear ) / ( zNear - zFar );
	pM->m[3][3] = 0;
}

/*=============================================================================
*
* Purpose : �����ϊ��s������߂�D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsMatrix4FrustumRH
(
	GSmatrix4*	pM,						/* �����ϊ��}�g���N�X			*/
	GSfloat		Left,					/* �N���b�v�ʂ̍����̍��W		*/
	GSfloat		Right,					/* �N���b�v�ʂ̉E���̍��W		*/
	GSfloat		Bottom,					/* �N���b�v�ʂ̉����̍��W		*/
	GSfloat		Top,					/* �N���b�v�ʂ̏㑤�̍��W		*/
	GSfloat		zNear,					/* �߃N���b�v�ʂ̍��W			*/
	GSfloat		zFar					/* ���N���b�v�ʂ̍��W			*/
)
{
	pM->m[0][0] = ( 2.0f * zNear ) / ( Right - Left );
	pM->m[0][1] = 0.0f;  
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;  
	pM->m[1][1] = ( 2.0f * zNear ) / ( Top - Bottom );
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = ( Right + Left ) / ( Right - Left );
	pM->m[2][1] = ( Top + Bottom ) / ( Top - Bottom );
	pM->m[2][2] = -( zFar + zNear ) / ( zFar - zNear );
	pM->m[2][3] = -1.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = -( 2.0f * zFar * zNear ) / ( zFar - zNear );
	pM->m[3][3] = 0.0f;
}

/*=============================================================================
*
* Purpose : �����ϊ��s������߂�D�i������W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
gsMatrix4FrustumLH
(
	GSmatrix4*	pM,						/* �����ϊ��}�g���N�X			*/
	GSfloat		Left,					/* �N���b�v�ʂ̍����̍��W		*/
	GSfloat		Right,					/* �N���b�v�ʂ̉E���̍��W		*/
	GSfloat		Bottom,					/* �N���b�v�ʂ̉����̍��W		*/
	GSfloat		Top,					/* �N���b�v�ʂ̏㑤�̍��W		*/
	GSfloat		zNear,					/* �߃N���b�v�ʂ̍��W			*/
	GSfloat		zFar					/* ���N���b�v�ʂ̍��W			*/
)
{
	pM->m[0][0] = ( 2.0f * zNear ) / ( Right - Left );
	pM->m[0][1] = 0.0f;  
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = 0.0f;  
	pM->m[1][1] = ( 2.0f * zNear ) / ( Top - Bottom );
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = ( Right + Left ) / ( Right - Left );
	pM->m[2][1] = ( Top + Bottom ) / ( Top - Bottom );
	pM->m[2][2] = -( zFar + zNear ) / ( zFar - zNear );
	pM->m[2][3] = 1.0f;

	pM->m[3][0] = 0.0f;
	pM->m[3][1] = 0.0f;
	pM->m[3][2] = -( 2.0f * zFar * zNear ) / ( zFar - zNear );
	pM->m[3][3] = 0.0f;
}

/*=============================================================================
*
* Purpose : ���ˉe�ϊ��s������߂�D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4OrthoRH
(
	GSmatrix4*	pM,						/* ���ˉe�ϊ��}�g���N�X		*/
	GSfloat		Left,					/* �N���b�v�ʂ̍����̍��W	*/
	GSfloat		Right,					/* �N���b�v�ʂ̉E���̍��W	*/
	GSfloat		Bottom,					/* �N���b�v�ʂ̉����̍��W	*/
	GSfloat		Top,					/* �N���b�v�ʂ̏㑤�̍��W	*/
	GSfloat		zNear,					/* �߃N���b�v�ʂ̍��W		*/
	GSfloat		zFar					/* ���N���b�v�ʂ̍��W		*/
)
{
	pM->m[0][0] = 2.0f / ( Right - Left );
	pM->m[0][1] = 0;
	pM->m[0][2] = 0;
	pM->m[0][3] = 0; 

	pM->m[1][0] = 0;
	pM->m[1][1] = 2.0f / ( Top - Bottom );
	pM->m[1][2] = 0;
	pM->m[1][3] = 0;

	pM->m[2][0] = 0;
	pM->m[2][1] = 0;
	pM->m[2][2] = -2.0f / ( zFar - zNear );
	pM->m[2][3] = 0; 

	pM->m[3][0] = -( Right + Left   ) / ( Right - Left   );
	pM->m[3][1] = -( Top   + Bottom ) / ( Top   - Bottom );
	pM->m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	pM->m[3][3] = 1;
}

/*=============================================================================
*
* Purpose : ���ˉe�ϊ��s������߂�D�i������W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4OrthoLH
(
	GSmatrix4*	pM,						/* ���ˉe�ϊ��}�g���N�X		*/
	GSfloat		Left,					/* �N���b�v�ʂ̍����̍��W	*/
	GSfloat		Right,					/* �N���b�v�ʂ̉E���̍��W	*/
	GSfloat		Bottom,					/* �N���b�v�ʂ̉����̍��W	*/
	GSfloat		Top,					/* �N���b�v�ʂ̏㑤�̍��W	*/
	GSfloat		zNear,					/* �߃N���b�v�ʂ̍��W		*/
	GSfloat		zFar					/* ���N���b�v�ʂ̍��W		*/
)
{
	pM->m[0][0] = 2.0f / ( Right - Left );
	pM->m[0][1] = 0;
	pM->m[0][2] = 0;
	pM->m[0][3] = 0; 

	pM->m[1][0] = 0;
	pM->m[1][1] = 2.0f / ( Top - Bottom );
	pM->m[1][2] = 0;
	pM->m[1][3] = 0;

	pM->m[2][0] = 0;
	pM->m[2][1] = 0;
	pM->m[2][2] = 2.0f / ( zFar - zNear );
	pM->m[2][3] = 0; 

	pM->m[3][0] = -( Right + Left   ) / ( Right - Left   );
	pM->m[3][1] = -( Top   + Bottom ) / ( Top   - Bottom );
	pM->m[3][2] = -( zFar  + zNear  ) / ( zFar  - zNear  );
	pM->m[3][3] = 1;
}

/*=============================================================================
*
* Purpose : ����ϊ��s������߂�D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4LookAtRH
(
	GSmatrix4*			pM,				/* ���_�ϊ��}�g���N�X   */
	const GSvector3*	from,			/* ���_�̍��W           */
	const GSvector3*	at,				/* �ڕW�_�̍��W         */
	const GSvector3*	up				/* ���_�̏㑤�̕���     */
)
{
	GSvector3			xaxis;
	GSvector3			yaxis;
	GSvector3			zaxis;

	/* �������̃x�N�g�������߂� */
	gsVector3Subtract( &zaxis, from, at );
	gsVector3Normalize( &zaxis, &zaxis );

	/* �������̃x�N�g�������߂� */
	gsVector3Cross( &xaxis, up, &zaxis );
	gsVector3Normalize( &xaxis, &xaxis );

	/* �������̃x�N�g�������߂� */
	gsVector3Cross( &yaxis, &zaxis, &xaxis );

	/* ��]�s��Ɋe�x�N�g����ݒ肷�� */
	pM->m[0][0] = xaxis.x;
	pM->m[0][1] = yaxis.x;
	pM->m[0][2] = zaxis.x;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = xaxis.y;
	pM->m[1][1] = yaxis.y;
	pM->m[1][2] = zaxis.y;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = xaxis.z;
	pM->m[2][1] = yaxis.z;
	pM->m[2][2] = zaxis.z;
	pM->m[2][3] = 0.0f;

	/* ���_�̈ʒu��ݒ肷�� */
	pM->m[3][0] = -gsVector3Dot( from, &xaxis );
	pM->m[3][1] = -gsVector3Dot( from, &yaxis );
	pM->m[3][2] = -gsVector3Dot( from, &zaxis );
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : ����ϊ��s������߂�D�i������W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4LookAtLH
(
	GSmatrix4*			pM,				/* ���_�ϊ��}�g���N�X   */
	const GSvector3*	from,			/* ���_�̍��W           */
	const GSvector3*	at,				/* �ڕW�_�̍��W         */
	const GSvector3*	up				/* ���_�̏㑤�̕���     */
)
{
	GSvector3			xaxis;
	GSvector3			yaxis;
	GSvector3			zaxis;

	/* �������̃x�N�g�������߂� */
	gsVector3Subtract( &zaxis, at, from );
	gsVector3Normalize( &zaxis, &zaxis );

	/* �������̃x�N�g�������߂� */
	gsVector3Cross( &xaxis, up, &zaxis );
	gsVector3Normalize( &xaxis, &xaxis );

	/* �������̃x�N�g�������߂� */
	gsVector3Cross( &yaxis, &zaxis, &xaxis );

	/* ��]�s��Ɋe�x�N�g����ݒ肷�� */
	pM->m[0][0] = xaxis.x;
	pM->m[0][1] = yaxis.x;
	pM->m[0][2] = zaxis.x;
	pM->m[0][3] = 0.0f;

	pM->m[1][0] = xaxis.y;
	pM->m[1][1] = yaxis.y;
	pM->m[1][2] = zaxis.y;
	pM->m[1][3] = 0.0f;

	pM->m[2][0] = xaxis.z;
	pM->m[2][1] = yaxis.z;
	pM->m[2][2] = zaxis.z;
	pM->m[2][3] = 0.0f;

	/* ���_�̈ʒu��ݒ肷�� */
	pM->m[3][0] = -gsVector3Dot( from, &xaxis );
	pM->m[3][1] = -gsVector3Dot( from, &yaxis );
	pM->m[3][2] = -gsVector3Dot( from, &zaxis );
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : ����ϊ��s��ɕϊ�����D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4ConvViewRH
(
	GSmatrix4*			pOut,			/* ����ϊ��}�g���N�X     */
	const GSmatrix4*	pM				/* �R�c�}�g���N�X       */
)
{
	GSvector3 from;
	GSvector3 at;
	GSvector3 up;
	from.x = pM->m[3][0];
	from.y = pM->m[3][1];
	from.z = pM->m[3][2];
	at.x  = pM->m[2][0] + pM->m[3][0];
	at.y  = pM->m[2][1] + pM->m[3][1];
	at.z  = pM->m[2][2] + pM->m[3][2];
	up.x  = pM->m[1][0];
	up.y  = pM->m[1][1];
	up.z  = pM->m[1][2];
	gsMatrix4LookAtRH(pOut, &from, &at, &up);
}

/*=============================================================================
*
* Purpose : ����ϊ��s��̋t�s�ϊ�������D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4InverseLookAtRH
(
	const GSmatrix4*	pM,				/* ���_�ϊ��}�g���N�X    */
	GSvector3*			pFrom,			/*-> ���_�̍��W          */
	GSvector3*			pAt,			/*-> �ڕW�_�̍��W        */
	GSvector3*			pUp				/*-> ���_�̏㑤�̕���    */
)
{
	GSmatrix4			invMat;
	gsMatrix4InverseFast(&invMat, pM);
	if (pFrom != NULL) {
		pFrom->x = invMat.m[3][0];
		pFrom->y = invMat.m[3][1];
		pFrom->z = invMat.m[3][2];
	}
	if (pAt != NULL) {
		pAt->x = invMat.m[3][0] - invMat.m[2][0];
		pAt->y = invMat.m[3][1] - invMat.m[2][1];
		pAt->z = invMat.m[3][2] - invMat.m[2][2];
	}
	if (pUp != NULL) {
		pUp->x = invMat.m[1][0];
		pUp->y = invMat.m[1][1];
		pUp->z = invMat.m[1][2];
	}
}

/*=============================================================================
*
* Purpose : ����ϊ��s��ɕϊ�����D�i������W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4ConvViewLH
(
	GSmatrix4*			pOut,			/* ����ϊ��}�g���N�X     */
	const GSmatrix4*	pM				/* �R�c�}�g���N�X       */
)
{
	GSvector3 from;
	GSvector3 at;
	GSvector3 up;
	from.x = pM->m[3][0];
	from.y = pM->m[3][1];
	from.z = pM->m[3][2];
	at.x   = pM->m[2][0] + pM->m[3][0];
	at.y   = pM->m[2][1] + pM->m[3][1];
	at.z   = pM->m[2][2] + pM->m[3][2];
	up.x   = pM->m[1][0];
	up.y   = pM->m[1][1];
	up.z   = pM->m[1][2];
	gsMatrix4LookAtLH(pOut, &from, &at, &up);
}

/*=============================================================================
*
* Purpose : �����ϊ��s��̋t�ϊ��D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4InversePerspectiveRH
(
	const GSmatrix4*	pM,				/* �����ϊ��}�g���N�X			*/
	GSfloat*			pFov,			/*-> ����p						*/
	GSfloat*			pAspect,		/*-> �A�X�y�N�g��				*/
	GSfloat*		 	pNear,			/*-> �߃N���b�v�ʂ܂ł̋���		*/
	GSfloat* 			pFar			/*-> ���N���b�v�ʂ܂ł̋���		*/
)
{
	static const GSvector3 NEAR_CLIP = { 0.0f, 0.0f, -1.0f };
	static const GSvector3 FAR_CLIP = { 0.0f, 0.0f,  1.0f };
	static const GSvector3 FAR_RIGHT = { 1.0f, 0.0f,  1.0f };
	static const GSvector3 FAR_TOP = { 0.0f, 1.0f,  1.0f };
	GSmatrix4 invProjection;
	GSvector3 invNear;
	GSvector3 invFar;
	GSvector3 invFarRight;
	GSvector3 invFarTop;
	float result_n;
	float result_f;
	float result_aspect;
	float result_fov;
	gsMatrix4Inverse(&invProjection, pM);
	gsVector3TransformCoord(&invNear, &NEAR_CLIP, &invProjection);
	gsVector3TransformCoord(&invFar, &FAR_CLIP, &invProjection);
	gsVector3TransformCoord(&invFarRight, &FAR_RIGHT, &invProjection);
	gsVector3TransformCoord(&invFarTop, &FAR_TOP, &invProjection);
	result_n = -invNear.z;
	result_f = -invFar.z;
	result_aspect = invFarRight.x / invFarTop.y;
	result_fov = gsAtan(result_f, invFarRight.x / result_aspect) * 2.0f;
	if (pNear   != NULL) *pNear   = result_n;
	if (pFar    != NULL) *pFar    = result_f;
	if (pAspect != NULL) *pAspect = result_aspect;
	if (pFov    != NULL) *pFov    = result_fov;
}

/*=============================================================================
*
* Purpose : �����ϊ��s��̋t�ϊ��D�i�E����W�n�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4InverseOrthoRH
(
	const GSmatrix4*	pM,				/* ���ˉe�ϊ��}�g���N�X		*/
	GSfloat*			pLeft,			/*-> �N���b�v�ʂ̍����̍��W	*/
	GSfloat*			pRight,			/*-> �N���b�v�ʂ̉E���̍��W	*/
	GSfloat*			pBottom,		/*-> �N���b�v�ʂ̉����̍��W	*/
	GSfloat*			pTop,			/*-> �N���b�v�ʂ̏㑤�̍��W	*/
	GSfloat*			pNear,			/*-> �߃N���b�v�ʂ̍��W		*/
	GSfloat*			pFar			/*-> ���N���b�v�ʂ̍��W		*/
)
{
	static const GSvector3 MIN_POSITION = { -1.0f, -1.0f, -1.0f };
	static const GSvector3 MAX_POSITION = { 1.0f,  1.0f,  1.0f };
	GSmatrix4 invProjection;
	GSvector3 invMin;
	GSvector3 invMax;
	gsMatrix4Inverse(&invProjection, pM);
	gsVector3TransformCoord(&invMin, &MIN_POSITION, &invProjection);
	gsVector3TransformCoord(&invMax, &MAX_POSITION, &invProjection);
	if (pLeft   != NULL) *pLeft   =  invMin.x;
	if (pRight  != NULL) *pRight  =  invMax.x;
	if (pBottom != NULL) *pBottom =  invMin.y;
	if (pTop    != NULL) *pTop    =  invMax.y;
	if (pNear   != NULL) *pNear   = -invMin.z;
	if (pFar    != NULL) *pFar    = -invMax.z;
}

/*=============================================================================
*
* Purpose : �X�N���[�����W�ϊ��s������߂�D�i���㌴�_�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Screen
(
	GSmatrix4*			pM,				/* �X�N���[�����W�ϊ��s��	*/
	GSfloat				width,			/* �r���[�|�[�g�̕�			*/
	GSfloat				height			/* �r���[�|�[�g�̍���		*/
)
{
	GSfloat w = width  / 2.0f;
	GSfloat h = height / 2.0f;
	pM->m[0][0] = w;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;
	pM->m[0][3] = 0.0f;
	pM->m[1][0] = 0.0f;
	pM->m[1][1] = -h;
	pM->m[1][2] = 0.0f;
	pM->m[1][3] = 0.0f;
	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = 1.0f;
	pM->m[2][3] = 0.0f;
	pM->m[3][0] = w;
	pM->m[3][1] = h;
	pM->m[3][2] = 0.0f;
	pM->m[3][3] = 1.0f;
}

/*=============================================================================
*
* Purpose : �]�u�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Transpose
(
	GSmatrix4*			pOut,			/* �]�u�R�c�}�g���N�X   */
	const GSmatrix4*	pM				/* �R�c�}�g���N�X       */
)
{
	int					i, j;
	GSmatrix4			M;

	/* �}�g���N�X�̍s�Ɨ���������� */
	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			M.m[i][j] = pM->m[j][i];
		}
	}
	*pOut = M;
}

/*=============================================================================
*
* Purpose : �t�s������߂�D�i �X�P�[�����O����Ă��Ȃ��s��̂ݗL�� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4InverseFast
(
	GSmatrix4*			pOut,			/* �t�R�c�}�g���N�X     */
	const GSmatrix4*	pM				/* �R�c�}�g���N�X       */
)
{
	GSmatrix4			M;

	M.m[0][0] = pM->m[0][0];
	M.m[1][0] = pM->m[0][1];
	M.m[2][0] = pM->m[0][2];

	M.m[0][1] = pM->m[1][0];
	M.m[1][1] = pM->m[1][1];
	M.m[2][1] = pM->m[1][2];

	M.m[0][2] = pM->m[2][0];
	M.m[1][2] = pM->m[2][1];
	M.m[2][2] = pM->m[2][2];

	M.m[3][0] = -( pM->m[3][0] * M.m[0][0]
	             + pM->m[3][1] * M.m[1][0]
	             + pM->m[3][2] * M.m[2][0] );
	M.m[3][1] = -( pM->m[3][0] * M.m[0][1] 
	             + pM->m[3][1] * M.m[1][1]
	             + pM->m[3][2] * M.m[2][1] );
	M.m[3][2] = -( pM->m[3][0] * M.m[0][2]
	             + pM->m[3][1] * M.m[1][2]
	             + pM->m[3][2] * M.m[2][2] );

	M.m[0][3] = pM->m[0][3];
	M.m[1][3] = pM->m[1][3];
	M.m[2][3] = pM->m[2][3];
	M.m[3][3] = pM->m[3][3];

	*pOut = M;
}

/*=============================================================================
*
* Purpose : �t�s������߂�D
*
* Return  : �t�s�񂪋��܂�ΐ^�C���܂�Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern	GSboolean
gsMatrix4Inverse
(
	GSmatrix4*			pOut,			/* �t�R�c�}�g���N�X     */
	const GSmatrix4*	pM				/* �R�c�}�g���N�X       */
)
{
	GSmatrix4			M;
	GSfloat				d12;
	GSfloat				d13;
	GSfloat				d23;
	GSfloat				d24;
	GSfloat				d34;
	GSfloat				d41;
	GSfloat				invDet;
	GSfloat				det;

/* �ǐ���ǂ����邽�߂̈ꎞ�}�N����` */
#define MAT( r,c )	(pM->m[(c)][(r)])

#define m11 MAT(0,0)
#define m12 MAT(0,1)
#define m13 MAT(0,2)
#define m14 MAT(0,3)
#define m21 MAT(1,0)
#define m22 MAT(1,1)
#define m23 MAT(1,2)
#define m24 MAT(1,3)
#define m31 MAT(2,0)
#define m32 MAT(2,1)
#define m33 MAT(2,2)
#define m34 MAT(2,3)
#define m41 MAT(3,0)
#define m42 MAT(3,1)
#define m43 MAT(3,2)
#define m44 MAT(3,3)

	d12 = ( m31 * m42 - m41 * m32 );
	d13 = ( m31 * m43 - m41 * m33 );
	d23 = ( m32 * m43 - m42 * m33 );
	d24 = ( m32 * m44 - m42 * m34 );
	d34 = ( m33 * m44 - m43 * m34 );
	d41 = ( m34 * m41 - m44 * m31 );

	M.m[0][0] =  ( m22 * d34 - m23 * d24 + m24 * d23 );
	M.m[0][1] = -( m21 * d34 + m23 * d41 + m24 * d13 );
	M.m[0][2] =  ( m21 * d24 + m22 * d41 + m24 * d12 );
	M.m[0][3] = -( m21 * d23 - m22 * d13 + m23 * d12 );

	det = m11 * M.m[0][0]
		+ m12 * M.m[0][1]
		+ m13 * M.m[0][2]
		+ m14 * M.m[0][3];

	if( det == 0.0 )
	{
		/* �t�s������߂鎖���ł��Ȃ� */
		gsMatrix4Identity( pOut );

		return	GS_FALSE;
	}

	invDet = 1.0f / det;

	M.m[0][0] *= invDet;
	M.m[0][1] *= invDet;
	M.m[0][2] *= invDet;
	M.m[0][3] *= invDet;

	M.m[1][0] = -( m12 * d34 - m13 * d24 + m14 * d23 ) * invDet;
	M.m[1][1] =  ( m11 * d34 + m13 * d41 + m14 * d13 ) * invDet;
	M.m[1][2] = -( m11 * d24 + m12 * d41 + m14 * d12 ) * invDet;
	M.m[1][3] =  ( m11 * d23 - m12 * d13 + m13 * d12 ) * invDet;

	d12 = m11 * m22 - m21 * m12;
	d13 = m11 * m23 - m21 * m13;
	d23 = m12 * m23 - m22 * m13;
	d24 = m12 * m24 - m22 * m14;
	d34 = m13 * m24 - m23 * m14;
	d41 = m14 * m21 - m24 * m11;

	M.m[2][0] =  ( m42 * d34 - m43 * d24 + m44 * d23 ) * invDet;
	M.m[2][1] = -( m41 * d34 + m43 * d41 + m44 * d13 ) * invDet;
	M.m[2][2] =  ( m41 * d24 + m42 * d41 + m44 * d12 ) * invDet;
	M.m[2][3] = -( m41 * d23 - m42 * d13 + m43 * d12 ) * invDet;
	M.m[3][0] = -( m32 * d34 - m33 * d24 + m34 * d23 ) * invDet;
	M.m[3][1] =  ( m31 * d34 + m33 * d41 + m34 * d13 ) * invDet;
	M.m[3][2] = -( m31 * d24 + m32 * d41 + m34 * d12 ) * invDet;
	M.m[3][3] =  ( m31 * d23 - m32 * d13 + m33 * d12 ) * invDet;

	*pOut = M;

/* �ꎞ�}�N����S�č폜���� */
#undef m11
#undef m12
#undef m13
#undef m14
#undef m21
#undef m22
#undef m23
#undef m24
#undef m31
#undef m32
#undef m33
#undef m34
#undef m41
#undef m42
#undef m43
#undef m44
#undef MAT

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : �n���ʃV���h�E�}�g���N�X�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4Shadow
(
	GSmatrix4*			pM,			/* �e�ϊ��s��			*/
	const GSplane*		pPlane,		/* ���ʂ̃p�����[�^		*/
	const GSvector3*	pLightPos	/* ���C�g�̈ʒu			*/
)
{
	GSfloat		dot;

	dot = gsPlaneDotCoord( pPlane, pLightPos );

	pM->m[0][0] = dot - pLightPos->x * pPlane->a;
	pM->m[1][0] = -pLightPos->x * pPlane->b;
	pM->m[2][0] = -pLightPos->x * pPlane->c;
	pM->m[3][0] = -pLightPos->x * pPlane->d;

	pM->m[0][1] = -pLightPos->y * pPlane->a;
	pM->m[1][1] = dot - pLightPos->y * pPlane->b;
	pM->m[2][1] = -pLightPos->y * pPlane->c;
	pM->m[3][1] = -pLightPos->y * pPlane->d;

	pM->m[0][2] = -pLightPos->z * pPlane->a;
	pM->m[1][2] = -pLightPos->z * pPlane->b;
	pM->m[2][2] = dot - pLightPos->z * pPlane->c;
	pM->m[3][2] = -pLightPos->z * pPlane->d;

	pM->m[0][3] = -pPlane->a;
	pM->m[1][3] = -pPlane->b;
	pM->m[2][3] = -pPlane->c;
	pM->m[3][3] = dot - pPlane->d;
}

/*=============================================================================
*
* Purpose : ���[�C�s�b�`�C���[�������]�s������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMatrix4YawPitchRoll
(
	GSmatrix4*			pOut,			/* ��]�}�g���N�X					*/
	GSfloat				Yaw,			/*-> ���[  �i��������̉�]�p�x�j	*/
	GSfloat				Pitch,			/*-> �s�b�`�i��������̉�]�p�x�j	*/
	GSfloat				Roll			/*-> ���[���i�y�������̉�]�p�x�j	*/
)
{
	GSmatrix4			matRoll;
	GSmatrix4			matPitch;
	GSmatrix4			matYaw;

	/* ���[���C�s�b�`�C���[�����]�}�g���N�X�����߂� */
	gsMatrix4RotateZ( &matRoll,  Roll  );
	gsMatrix4RotateX( &matPitch, Pitch );
	gsMatrix4RotateY( &matYaw,   Yaw   );

	/* ��]�}�g���N�X���������� */
	gsMatrix4Multiply( pOut, &matRoll, &matPitch );
	gsMatrix4Multiply( pOut, pOut, &matYaw );
}

/*=============================================================================
*
* Purpose : ��]�s�񂩂�s�b�`�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix4GetPitch
(
	const GSmatrix4*	pM				/* �s��								*/
)
{
	/* �s�b�`�����߂� */
	return	gsDegreeNormalize( gsAsin( -pM->m[2][1] ) );
}

/*=============================================================================
*
* Purpose : ��]�s�񂩂烍�[�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix4GetRoll
(
	const GSmatrix4*	pM				/* �s��								*/
)
{
	/* ���[�������߂� */
	return	gsAtan( pM->m[0][1], pM->m[1][1] );
}

/*=============================================================================
*
* Purpose : ��]�s�񂩂烈�[�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsMatrix4GetYaw
(
	const GSmatrix4*	pM				/* �s��								*/
)
{
	/* ���[�����߂� */
	return	gsAtan(pM->m[2][2], pM->m[2][0]);
}

/*=============================================================================
*
* Purpose : ������̃R�[�i�[�̍��W�����߂�D
*
* Return  : ��������ɑ��݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern void
gsMatrix4GetFrustumCorners
(
	GSvector3			Corners[8],			/*-> ������̃R�[�i�[�̍��W		*/
	const GSmatrix4*	pView,				/* ����ϊ��s��			*/
	const GSmatrix4*	pProjection			/* �����ϊ��s��			*/
)
{
	static const GSvector3 NEAR_FAR_POSITION[] = {
		{ -1.0f,  1.0f,  -1.0f }, // near left top
		{ -1.0f, -1.0f,  -1.0f }, // near left bottom
		{  1.0f, -1.0f,  -1.0f }, // near right bottom
		{  1.0f,  1.0f,  -1.0f }, // near right top
		{ -1.0f,  1.0f,   1.0f }, // far left top
		{ -1.0f, -1.0f,   1.0f }, // far left bottom
		{  1.0f, -1.0f,   1.0f }, // far right bottom
		{  1.0f,  1.0f,   1.0f }, // far right top
	};
	GSmatrix4 view_projection;
	GSmatrix4 inv_view_projection;
	gsMatrix4Multiply(&view_projection, pView, pProjection);
	gsMatrix4Inverse(&inv_view_projection, &view_projection);
	for (int i = 0; i < 8; ++i) {
		gsVector3TransformCoord(&Corners[i], &NEAR_FAR_POSITION[i], &inv_view_projection);
	}
}

/********** End of File ******************************************************/
