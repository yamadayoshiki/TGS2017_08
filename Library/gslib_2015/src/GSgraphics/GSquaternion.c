/******************************************************************************
* File Name : GSquaternion.c                      Ver : 1.00  Date : 2002-08-14
*
* Description :
*
*       �N�H�[�^�j�I���̌v�Z�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSquaternion.h"
#include	"GSmath.h"

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
* Purpose : �P�ʃN�H�[�^�j�I����ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSquaternion*
gsQuaternionIdentity
(
	GSquaternion*	pOut				/*-> �N�H�[�^�j�I��		*/
)
{
	gsQuaternionInit( pOut, 0.0f, 0.0f, 0.0f, 1.0f );

	return	pOut;
}

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
)
{
	return	q1->x*q2->x + q1->y*q2->y + q1->z*q2->z + q1->w*q2->w;
}

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
)
{
	return	gsSqrt( gsQuaternionDot( q, q ) );
}

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
)
{
	GSfloat				l;

	l = gsQuaternionLength( q );
	l = ( l > 0.0f ) ? ( 1.0f / l ): 0.0f;

	ans->x = q->x * l;
	ans->y = q->y * l;
	ans->z = q->z * l;
	ans->w = q->w * l;

	return	ans;
}

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
)
{
	GSquaternion		tmp;

	tmp.x =  a->x * b->w + a->y * b->z - a->z * b->y + a->w * b->x;
	tmp.y = -a->x * b->z + a->y * b->w + a->z * b->x + a->w * b->y;
	tmp.z =  a->x * b->y - a->y * b->x + a->z * b->w + a->w * b->z;
	tmp.w = -a->x * b->x - a->y * b->y - a->z * b->z + a->w * b->w;

	*ans = tmp;

	return	ans;
}

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
)
{
	ans->x = a->x * s;
	ans->y = a->y * s;
	ans->z = a->z * s;
	ans->w = a->w * s;

	return	ans;
}

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
)
{
	ans->x = a->x + b->x;
	ans->y = a->y + b->y;
	ans->z = a->z + b->z;
	ans->w = a->w + b->w;

	return	ans;
}

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
)
{
	ans->x = a->x - b->x;
	ans->y = a->y - b->y;
	ans->z = a->z - b->z;
	ans->w = a->w - b->w;

	return	ans;
}

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
)
{
	q->x = gsSin( angle / 2.0f ) * vx;
	q->y = gsSin( angle / 2.0f ) * vy;
	q->z = gsSin( angle / 2.0f ) * vz;
	q->w = gsCos( angle / 2.0f );

	return	q;
}

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
)
{
	GSfloat				fSinYaw;
	GSfloat				fSinPitch;
	GSfloat				fSinRoll;
	GSfloat				fCosYaw;
	GSfloat				fCosPitch;
	GSfloat				fCosRoll;

	fSinYaw   = gsSin( fYaw   / 2.0f );
	fSinPitch = gsSin( fPitch / 2.0f );
	fSinRoll  = gsSin( fRoll  / 2.0f );
	fCosYaw   = gsCos( fYaw   / 2.0f );
	fCosPitch = gsCos( fPitch / 2.0f );
	fCosRoll  = gsCos( fRoll  / 2.0f );

	q->x = fSinRoll * fCosPitch * fCosYaw - fCosRoll * fSinPitch * fSinYaw;
	q->y = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * fSinYaw;
	q->z = fCosRoll * fCosPitch * fSinYaw - fSinRoll * fSinPitch * fCosYaw;
	q->w = fCosRoll * fCosPitch * fCosYaw + fSinRoll * fSinPitch * fSinYaw;

	return	q;
}

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
)
{
	pOut->x = LERP( t, pQ1->x, pQ2->x );
	pOut->y = LERP( t, pQ1->y, pQ2->y );
	pOut->z = LERP( t, pQ1->z, pQ2->z );
	pOut->w = LERP( t, pQ1->w, pQ2->w );

	gsQuaternionNormalize( pOut, pOut );

	return	pOut;
}

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
)
{
	GSfloat				l;

	l = gsQuaternionLength( q );
	l = ( l > 0.0f ) ? ( 1.0f / l ): 0.0f;

	pOut->x = -q->x * l;
	pOut->y = -q->y * l;
	pOut->z = -q->z * l;
	pOut->w =  q->w * l;

	return	pOut;
}

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
)
{
	*pAngle = gsAcos( q->w ) * 2.0f;
	*pVx    = q->x / gsSin( *pAngle / 2.0f );
	*pVy    = q->y / gsSin( *pAngle / 2.0f );
	*pVz    = q->z / gsSin( *pAngle / 2.0f );
}

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
)
{
	GSfloat				tr;
	GSfloat				fourD;

	tr = mat->m[0][0] + mat->m[1][1] + mat->m[2][2] + mat->m[3][3];
	if ( tr >= 1.0f )
	{
		fourD = 2.0f * gsSqrt( tr );
		q->w = fourD / 4.0f;
		q->x = ( mat->m[1][2] - mat->m[2][1] ) / fourD;
		q->y = ( mat->m[2][0] - mat->m[0][2] ) / fourD;
		q->z = ( mat->m[0][1] - mat->m[1][0] ) / fourD;
	}
	else
	{
		GSfloat		qa[4];
		int			i, j, k;

		if ( mat->m[0][0] > mat->m[1][1] )
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
		if ( mat->m[2][2] > mat->m[i][i] )
		{
			i = 2;
		}
		j = ( i + 1 ) % 3;
		k = ( j + 1 ) % 3;

		tr = mat->m[i][i] - mat->m[j][j] - mat->m[k][k] + 1.0f;

		fourD = 2.0f * gsSqrt( tr );

		qa[i] = fourD / 4.0f;
		qa[j] = ( mat->m[j][i] + mat->m[i][j] ) / fourD;
		qa[k] = ( mat->m[k][i] + mat->m[i][k] ) / fourD;
		qa[3] = ( mat->m[j][k] - mat->m[k][j] ) / fourD;

		q->x = qa[0];
		q->y = qa[1];
		q->z = qa[2];
		q->w = qa[3];
	}

	return	q;
}

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
)
{
	GSfloat				tr;
	GSfloat				fourD;

	tr = mat->m[0][0] + mat->m[1][1] + mat->m[2][2] + 1.0f;
	if ( tr >= 1.0f )
	{
		fourD = 2.0f * gsSqrt( tr );
		q->w = fourD / 4.0f;
		q->x = ( mat->m[1][2] - mat->m[2][1] ) / fourD;
		q->y = ( mat->m[2][0] - mat->m[0][2] ) / fourD;
		q->z = ( mat->m[0][1] - mat->m[1][0] ) / fourD;
	}
	else
	{
		GSfloat		qa[4];
		int			i, j, k;

		if ( mat->m[0][0] > mat->m[1][1] )
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
		if ( mat->m[2][2] > mat->m[i][i] )
		{
			i = 2;
		}
		j = ( i + 1 ) % 3;
		k = ( j + 1 ) % 3;

		tr = mat->m[i][i] - mat->m[j][j] - mat->m[k][k] + 1.0f;

		fourD = 2.0f * gsSqrt( tr );

		qa[i] = fourD / 4.0f;
		qa[j] = ( mat->m[j][i] + mat->m[i][j] ) / fourD;
		qa[k] = ( mat->m[k][i] + mat->m[i][k] ) / fourD;
		qa[3] = ( mat->m[j][k] - mat->m[k][j] ) / fourD;

		q->x = qa[0];
		q->y = qa[1];
		q->z = qa[2];
		q->w = qa[3];
	}

	return	q;
}

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
)
{
	GSquaternion		tb;
	GSfloat				fCosTheta;
	GSfloat				fBeta;

	fCosTheta = a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;

	if( fCosTheta < 0.0f ) 
	{
		fCosTheta = -fCosTheta;
		tb.x      = -b->x;
		tb.y      = -b->y; 
		tb.z      = -b->z;
		tb.w      = -b->w;
	}
	else
	{
		tb = *b;
	}

	fBeta = 1.0f - t;

	if ( ( 1.0f - fCosTheta ) > 0.001f ) 
	{
		GSfloat fTheta;

		fTheta = (GSfloat)acos( fCosTheta );

		fBeta  = (GSfloat)( sin( fTheta*fBeta  ) / sin( fTheta ) );
		t      = (GSfloat)( sin( fTheta*t      ) / sin( fTheta ) );
	}

	pOut->x = fBeta * a->x + t * tb.x;
	pOut->y = fBeta * a->y + t * tb.y;
	pOut->z = fBeta * a->z + t * tb.z;
	pOut->w = fBeta * a->w + t * tb.w;

	gsQuaternionNormalize( pOut, pOut );

	return	pOut;
}

/********** End of File ******************************************************/
