/******************************************************************************
* File Name : GSvector3.c                         Ver : 1.00  Date : 2001-01-16
*
* Description :
*
*       �R�c�x�N�g���v�Z
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSvector3.h"
#include	<float.h>

/*=============================================================================
*
* Purpose : �x�N�g���𐳋K������D�i �P�ʃx�N�g�������� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
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
extern GSfloat
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
extern GSfloat
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
extern GSfloat
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
extern void
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
	    + pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    + pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    + pM->m[3][2];

	*pOut = v;
}

/*=============================================================================
*
* Purpose : �x�N�g���̍��W�ϊ����s���D�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
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
	    + pM->m[3][0];
	v.y = pV->x * pM->m[0][1]
	    + pV->y * pM->m[1][1]
	    + pV->z * pM->m[2][1]
	    + pM->m[3][1];
	v.z = pV->x * pM->m[0][2]
	    + pV->y * pM->m[1][2]
	    + pV->z * pM->m[2][2]
	    + pM->m[3][2];
	w   = pV->x * pM->m[0][3]
	    + pV->y * pM->m[1][3]
	    + pV->z * pM->m[2][3]
	    + pM->m[3][3];

	gsVector3Scale( pOut, &v, 1.0f / w );
}

/*=============================================================================
*
* Purpose : �@���x�N�g���̍��W�ϊ����s���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
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
}

/*=============================================================================
*
* Purpose : �ʖ@�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
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
}

/*=============================================================================
*
* Purpose : ���˃x�N�g�������߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsVector3Refrection
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
}

/*=============================================================================
*
* Purpose : �x�N�g������p�ƕ��ʊp�����߂�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsVector3ToEleDir
(
	GSfloat*			pElevation,		/*-> �p				*/
	GSfloat*			pDirection,		/*-> ���ʊp				*/
	const GSvector3*	pV				/* �x�N�g��				*/
)
{
	GSvector3			Normal;
	GSfloat				Len;

	/* �x�N�g���̒��������߂� */
	if ( ( Len = gsVector3Length( pV ) ) == 0 )
	{
		/* �������O�̏ꍇ�͋p�E���ʊp���ɂO�ɂ��� */
		*pDirection = 0.0f;
		*pElevation = 0.0f;

		return;
	}

	/* �x�N�g���𐳋K������ */
	Normal.x = pV->x / Len;
	Normal.y = pV->y / Len;
	Normal.z = pV->z / Len;

	/* ���ʊp�̌v�Z���s�� */
	if ( Normal.x == 0.0f && Normal.z == 0.0f )
	{
		*pDirection = 0.0f;
	}
	else
	{
		*pDirection = gsAtan( Normal.x, Normal.z );
	}

	/* �p�̌v�Z���s�� */
	*pElevation = gsDegreeNormalize( gsAsin( -Normal.y ) );
}

/********** End of File ******************************************************/

