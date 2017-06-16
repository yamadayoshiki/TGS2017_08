/******************************************************************************
* File Name : GSmatrix3.c                        Ver : 1.00  Date : 1998-05-03
*
* Description :
*
*       �R�s�R����W�ϊ��s��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSmatrix3.h"
#include	"GSvector3.h"
#include	"GSplane.h"
#include	"GSmath.h"
#include	<float.h>

const GSmatrix3	GS_MATRIX3_IDENTITY =
{
	1.0F, 0.0F, 0.0F,
	0.0F, 1.0F, 0.0F,
	0.0F, 0.0F, 1.0F
};

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
	GSmatrix3*		pM					/* �R�c�}�g���N�X   */
)
{
	*pM = GS_MATRIX3_IDENTITY;
}

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
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			tx,					/* �������ړ���			*/
	GSfloat			ty					/* �������ړ���			*/
)
{
	pM->m[0][0] = 1.0f;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = 1.0f;
	pM->m[1][2] = 0.0f;

	pM->m[2][0] = tx;
	pM->m[2][1] = ty;
	pM->m[2][2] = 1.0f;
}

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
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			sx,					/* �������X�P�[���l		*/
	GSfloat			sy,					/* �������X�P�[���l		*/
	GSfloat			sz					/* �������X�P�[���l		*/
)
{
	pM->m[0][0] = sx;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = sy;
	pM->m[1][2] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = sz;
}

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
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
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

	pM->m[0][1] = ( dx * dy ) * oneMinusCosAngle + sinAngle * dz;
	pM->m[1][1] = ( dy * dy ) + cosAngle * ( 1.0f - ( dy * dy ) );
	pM->m[2][1] = ( dy * dz ) * oneMinusCosAngle - sinAngle * dx;

	pM->m[0][2] = ( dx * dz ) * oneMinusCosAngle - sinAngle * dy;
	pM->m[1][2] = ( dy * dz ) * oneMinusCosAngle + sinAngle * dx;
	pM->m[2][2] = ( dz * dz ) + cosAngle * ( 1.0f - ( dz * dz ) );
}

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
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][0] = 1.0f;
	pM->m[0][1] = 0.0f;
	pM->m[0][2] = 0.0f;

	pM->m[1][0] = 0.0f;

	pM->m[2][0] = 0.0f;

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
gsMatrix3RotateY
(
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][1] = 0.0f;

	pM->m[1][0] = 0.0f;
	pM->m[1][1] = 1.0f;
	pM->m[1][2] = 0.0f;

	pM->m[2][1] = 0.0f;

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
gsMatrix3RotateZ
(
	GSmatrix3*		pM,					/* �R�c�}�g���N�X       */
	GSfloat			angle				/* ��������̊p�x       */
)
{
	pM->m[0][2] = 0.0f;

	pM->m[1][2] = 0.0f;

	pM->m[2][0] = 0.0f;
	pM->m[2][1] = 0.0f;
	pM->m[2][2] = 1.0f;

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
gsMatrix3Quaternion
(
	GSmatrix3*			pM,				/* �R�c�}�g���N�X       */
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

	pM->m[1][0] = xy - wz;
	pM->m[1][1] = 1.0f - ( xx + zz );
	pM->m[1][2] = yz + wx;

	pM->m[2][0] = xz + wy;
	pM->m[2][1] = yz - wx;
	pM->m[2][2] = 1.0f - ( xx + yy );
	pM->m[2][3] = 0.0f;
}

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
	GSmatrix3*			pOut,			/*-> �|���Z�̌���   */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
)
{
	GSmatrix3			M;
	int					i, j;

	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 3; j++ )
		{
			M.m[i][j] = pM1->m[i][0] * pM2->m[0][j]
					  + pM1->m[i][1] * pM2->m[1][j]
					  + pM1->m[i][2] * pM2->m[2][j];
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
gsMatrix3MultiplyScalar
(
	GSmatrix3*			pOut,			/*-> �|���Z�̌���   */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	GSfloat				Scalar			/* �X�J���[         */
)
{
	int					i, j;

	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 3; j++ )
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
gsMatrix3Add
(
	GSmatrix3*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
)
{
	int					i, j;

	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 3; j++ )
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
gsMatrix3Subtract
(
	GSmatrix3*			pOut,			/*-> ���Z�̌���     */
	const GSmatrix3*	pM1,			/* �R�c�}�g���N�X   */
	const GSmatrix3*	pM2				/* �R�c�}�g���N�X   */
)
{
	int					i, j;

	for ( i = 0; i < 3; i++ )
	{
		for ( j = 0; j < 3; j++ )
		{
			pOut->m[i][j] = pM1->m[i][j] - pM2->m[i][j];
		}
	}
}

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
)
{
	GSmatrix3			M;

	/* �}�g���N�X�̍s�Ɨ���������� */
	M.m[0][0] = pM->m[0][0];
	M.m[1][0] = pM->m[0][1];
	M.m[2][0] = pM->m[0][2];

	M.m[0][1] = pM->m[1][0];
	M.m[1][1] = pM->m[1][1];
	M.m[2][1] = pM->m[1][2];

	M.m[0][2] = pM->m[2][0];
	M.m[1][2] = pM->m[2][1];
	M.m[2][2] = pM->m[2][2];

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
gsMatrix3Inverse
(
	GSmatrix3*			pOut,			/* �t�R�c�}�g���N�X     */
	const GSmatrix3*	pM				/* �R�c�}�g���N�X       */
)
{
	GSmatrix3			M;
	GSfloat				fDet;
	GSfloat				fInvDet;

	M.m[0][0] = pM->m[1][1] * pM->m[2][2] - pM->m[1][2]* pM->m[2][1];
	M.m[0][1] = pM->m[0][2] * pM->m[2][1] - pM->m[0][1]* pM->m[2][2];
	M.m[0][2] = pM->m[0][1] * pM->m[1][2] - pM->m[0][2]* pM->m[1][1];
	M.m[1][0] = pM->m[1][2] * pM->m[2][0] - pM->m[1][0]* pM->m[2][2];
	M.m[1][1] = pM->m[0][0] * pM->m[2][2] - pM->m[0][2]* pM->m[2][0];
	M.m[1][2] = pM->m[0][2] * pM->m[1][0] - pM->m[0][0]* pM->m[1][2];
	M.m[2][0] = pM->m[1][0] * pM->m[2][1] - pM->m[1][1]* pM->m[2][0];
	M.m[2][1] = pM->m[0][1] * pM->m[2][0] - pM->m[0][0]* pM->m[2][1];
	M.m[2][2] = pM->m[0][0] * pM->m[1][1] - pM->m[0][1]* pM->m[1][0];

	fDet = pM->m[0][0] * M.m[0][0]
	     + pM->m[0][1] * M.m[1][0]
	     + pM->m[0][2] * M.m[2][0];

	if ( fDet == 0.0 )
	{
		/* �t�s������߂鎖���ł��Ȃ� */
		gsMatrix3Identity( pOut );

		return	GS_FALSE;
	}

	fInvDet = 1.0f / fDet;

	M.m[0][0] *= fInvDet;
	M.m[0][1] *= fInvDet;
	M.m[0][2] *= fInvDet;
	M.m[1][0] *= fInvDet;
	M.m[1][1] *= fInvDet;
	M.m[1][2] *= fInvDet;
	M.m[2][0] *= fInvDet;
	M.m[2][1] *= fInvDet;
	M.m[2][2] *= fInvDet;

	*pOut = M;

	return GS_TRUE;
}

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
)
{
	GSmatrix3			matRoll;
	GSmatrix3			matPitch;
	GSmatrix3			matYaw;

	/* ���[���C�s�b�`�C���[�����]�}�g���N�X�����߂� */
	gsMatrix3RotateZ( &matRoll,  Roll  );
	gsMatrix3RotateX( &matPitch, Pitch );
	gsMatrix3RotateY( &matYaw,   Yaw   );

	/* ��]�}�g���N�X���������� */
	gsMatrix3Multiply( pOut, &matRoll, &matPitch );
	gsMatrix3Multiply( pOut, pOut, &matYaw );
}

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
gsMatrix3GetRoll
(
	const GSmatrix3*	pM				/* �s��								*/
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
gsMatrix3GetYaw
(
	const GSmatrix3*	pM				/* �s��								*/
)
{
	/* ���[�����߂� */
	return	gsAtan( pM->m[2][0], pM->m[2][2] );
}

/********** End of File ******************************************************/
