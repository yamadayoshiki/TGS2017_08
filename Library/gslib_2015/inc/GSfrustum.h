/******************************************************************************
* File Name : GSfrustum.h                        Ver : 1.00  Date : 2002-03-27
*
* Description :
*
*       ������J�����O�w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSFRUSTUM_H_
#define		_GSFRUSTUM_H_

#include	"GStype.h"
#include	"GSplane.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �N���b�s���O�v���[���񋓌^ ------------------------------------------*/

enum
{
	GS_FRUSTUM_LEFT_PLANE = 0,			/* ���N���b�s���O�v���[��	*/
	GS_FRUSTUM_RIGHT_PLANE,				/* �E�N���b�s���O�v���[��	*/
	GS_FRUSTUM_TOP_PLANE,				/* ��N���b�s���O�v���[��	*/
	GS_FRUSTUM_BOTTOM_PLANE,			/* ���N���b�s���O�v���[��	*/
	GS_FRUSTUM_NEAR_PLANE,				/* �߃N���b�s���O�v���[��	*/
	GS_FRUSTUM_FAR_PLANE				/* ���N���b�s���O�v���[��	*/
};

/*----- ������\���� --------------------------------------------------------*/

typedef	struct							/* ������\����				*/
{
	GSplane		Planes[6];				/* �N���b�s���O�v���[��		*/
	GSmatrix4	View;					/* ����ϊ��s��				*/
	GSmatrix4	Projection;				/* �����ϊ��s��				*/

} GSfrustum;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

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
);

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
);

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
);

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
);

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
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
