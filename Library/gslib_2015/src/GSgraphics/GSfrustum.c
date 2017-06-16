/******************************************************************************
* File Name : GSfrustum.c                        Ver : 1.00  Date : 2001-03-27
*
* Description :
*
*       ������J�����O�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSfrustum.h"
#include	"GSmatrix4.h"
#include	"GSvector3.h"

/*=============================================================================
*
* Purpose : ����ϊ��s��C�����ϊ��s�񂩂王������쐬����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrustumFromMatrices
(
	GSfrustum*			pFrustum,		/* ������				*/
	const GSmatrix4*	pView,			/* ����ϊ��s��			*/
	const GSmatrix4*	pProjection		/* �����ϊ��s��			*/
)
{
	GSmatrix4			Clip;
	int					i;
	/* ����ϊ��s��Ɠ����ϊ��s���ۑ����� */
	pFrustum->View       = *pView;
	pFrustum->Projection = *pProjection;

	/* ����ϊ��s��Ɠ����ϊ��s����������� */
	gsMatrix4Multiply(&Clip, &pFrustum->View, &pFrustum->Projection);

	/* �N���b�s���O�v���[�����v�Z���� */
	pFrustum->Planes[GS_FRUSTUM_RIGHT_PLANE].a=Clip.m[0][3]-Clip.m[0][0];
	pFrustum->Planes[GS_FRUSTUM_RIGHT_PLANE].b=Clip.m[1][3]-Clip.m[1][0];
	pFrustum->Planes[GS_FRUSTUM_RIGHT_PLANE].c=Clip.m[2][3]-Clip.m[2][0];
	pFrustum->Planes[GS_FRUSTUM_RIGHT_PLANE].d=Clip.m[3][3]-Clip.m[3][0];

	pFrustum->Planes[GS_FRUSTUM_LEFT_PLANE].a=Clip.m[0][3]+Clip.m[0][0];
	pFrustum->Planes[GS_FRUSTUM_LEFT_PLANE].b=Clip.m[1][3]+Clip.m[1][0];
	pFrustum->Planes[GS_FRUSTUM_LEFT_PLANE].c=Clip.m[2][3]+Clip.m[2][0];
	pFrustum->Planes[GS_FRUSTUM_LEFT_PLANE].d=Clip.m[3][3]+Clip.m[3][0];

	pFrustum->Planes[GS_FRUSTUM_BOTTOM_PLANE].a=Clip.m[0][3]+Clip.m[0][1];
	pFrustum->Planes[GS_FRUSTUM_BOTTOM_PLANE].b=Clip.m[1][3]+Clip.m[1][1];
	pFrustum->Planes[GS_FRUSTUM_BOTTOM_PLANE].c=Clip.m[2][3]+Clip.m[2][1];
	pFrustum->Planes[GS_FRUSTUM_BOTTOM_PLANE].d=Clip.m[3][3]+Clip.m[3][1];

	pFrustum->Planes[GS_FRUSTUM_TOP_PLANE].a=Clip.m[0][3]-Clip.m[0][1];
	pFrustum->Planes[GS_FRUSTUM_TOP_PLANE].b=Clip.m[1][3]-Clip.m[1][1];
	pFrustum->Planes[GS_FRUSTUM_TOP_PLANE].c=Clip.m[2][3]-Clip.m[2][1];
	pFrustum->Planes[GS_FRUSTUM_TOP_PLANE].d=Clip.m[3][3]-Clip.m[3][1];

	pFrustum->Planes[GS_FRUSTUM_FAR_PLANE].a=Clip.m[0][3]-Clip.m[0][2];
	pFrustum->Planes[GS_FRUSTUM_FAR_PLANE].b=Clip.m[1][3]-Clip.m[1][2];
	pFrustum->Planes[GS_FRUSTUM_FAR_PLANE].c=Clip.m[2][3]-Clip.m[2][2];
	pFrustum->Planes[GS_FRUSTUM_FAR_PLANE].d=Clip.m[3][3]-Clip.m[3][2];

	pFrustum->Planes[GS_FRUSTUM_NEAR_PLANE].a=Clip.m[0][3]+Clip.m[0][2];
	pFrustum->Planes[GS_FRUSTUM_NEAR_PLANE].b=Clip.m[1][3]+Clip.m[1][2];
	pFrustum->Planes[GS_FRUSTUM_NEAR_PLANE].c=Clip.m[2][3]+Clip.m[2][2];
	pFrustum->Planes[GS_FRUSTUM_NEAR_PLANE].d=Clip.m[3][3]+Clip.m[3][2];

	/* �N���b�s���O�v���[���𐳋K������ */
	for ( i = 0; i < 6; i++ )
	{
		gsPlaneNormalize( &pFrustum->Planes[i], &pFrustum->Planes[i] );
	}
}

/*=============================================================================
*
* Purpose : �_����������ɑ��݂��邩���ׂ�D
*
* Return  : ��������ɑ��݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsFrustumIsPointInside
(
	const GSfrustum*	pFrustum,		/* ������				*/
	const GSvector3*	pPoint			/* �_�̍��W				*/
)
{
	int					i;

	for( i = 0; i < 6; i++ )
	{
		/* �N���b�s���O�v���[���̔w�ʂɍ��W�����݂��邩�H */
		if( gsPlaneClassifyPoint( &pFrustum->Planes[i], pPoint, NULL ) == GS_BEHIND_PLANE )
		{
			/* ������̊O���ɓ_�����݂��� */
			return	GS_FALSE;
		}
	}

	/* ������̓����ɓ_�����݂��� */
	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : �{�b�N�X����������ɑ��݂��邩���ׂ�D
*
* Return  : ��������ɑ��݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsFrustumIsBoxInside
(
	const GSfrustum*	pFrustum,		/* ������				*/
	const GSvector3*	pP1,			/* �{�b�N�X��\�����W�P	*/
	const GSvector3*	pP2				/* �{�b�N�X��\�����W�Q	*/
)
{
	GSvector3			Vertices[8];
	int					i;

	/* �{�b�N�X�̊e���_�����߂� */
	gsVector3Init( &Vertices[0], pP1->x, pP1->y, pP1->z );
	gsVector3Init( &Vertices[1], pP2->x, pP1->y, pP1->z );
	gsVector3Init( &Vertices[2], pP1->x, pP2->y, pP1->z );
	gsVector3Init( &Vertices[3], pP2->x, pP2->y, pP1->z );
	gsVector3Init( &Vertices[4], pP1->x, pP1->y, pP2->z );
	gsVector3Init( &Vertices[5], pP2->x, pP1->y, pP2->z );
	gsVector3Init( &Vertices[6], pP1->x, pP2->y, pP2->z );
	gsVector3Init( &Vertices[7], pP2->x, pP2->y, pP2->z );

	for( i = 0; i < 6; i++ )
	{
		/* �{�b�N�X�̑S���_������N���b�v�v���[���O���ɑ��݂��邩�H */
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[0], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[1], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[2], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[3], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[4], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[5], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[6], NULL ) != GS_BEHIND_PLANE ) continue;
		if ( gsPlaneClassifyPoint( &pFrustum->Planes[i], &Vertices[7], NULL ) != GS_BEHIND_PLANE ) continue;

		/* ������̊O���Ƀ{�b�N�X�����݂��� */
		return	GS_FALSE;
	}

	/* ������̓����Ƀ{�b�N�X�����݂��� */
	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : ���̂���������ɑ��݂��邩���ׂ�D
*
* Return  : ��������ɑ��݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsFrustumIsSphereInside
(
	const GSfrustum*	pFrustum,		/* ������					*/
	const GSvector3*	pCenter,		/* ���̂̒��S���W			*/
	GSfloat				Radius			/* ���̂̔��a				*/
)
{
	int					i;

	for( i = 0; i < 6; i++ )
	{
		/* �N���b�s���O�v���[���̔w�ʂɋ��̂����݂��邩�H */
		if( gsPlaneClassifySphere( &pFrustum->Planes[i], pCenter, Radius, NULL ) == GS_BEHIND_PLANE )
		{
			/* ������̊O���ɓ_�����݂��� */
			return	GS_FALSE;
		}
	}

	/* ������̓����ɓ_�����݂��� */
	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : ������̃R�[�i�[�̍��W�����߂�D
*
* Return  : ��������ɑ��݂���ΐ^�C���݂��Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern void
gsFrustumGetCorners
(
	const GSfrustum*	pFrustum, 		/* ������					*/
	GSvector3			Corners[8]		/*-> �R�[�i�[�̍��W			*/
)
{
	gsMatrix4GetFrustumCorners(Corners, &pFrustum->View, &pFrustum->Projection);
}

/********** End of File ******************************************************/
