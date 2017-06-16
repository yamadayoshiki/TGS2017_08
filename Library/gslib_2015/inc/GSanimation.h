/******************************************************************************
* File Name : GSanimation.h                      Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		�A�j���[�V�����f�[�^�Ǘ� �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSANIMATION_H_
#define		_GSANIMATION_H_

#include	"GStype.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �X�P�[���L�[�\���� --------------------------------------------------*/

typedef	struct							/* �X�P�[���L�[�^			*/
{
	GSuint			Time;				/* �t���[���^�C�}			*/
	GSvector3		Scale;				/* �X�P�[���l				*/

} GSscalekey;

/*----- ���[�e�[�g�L�[�\���� ------------------------------------------------*/

typedef	struct							/* ���[�e�[�g�L�[�^			*/
{
	GSuint			Time;				/* �t���[���^�C�}			*/
	GSquaternion	Rotate;				/* ���[�e�[�g�l				*/

} GSrotatekey;

/*----- �|�W�V�����L�[�\���� ------------------------------------------------*/

typedef	struct							/* �|�W�V�����L�[�^			*/
{
	GSuint			Time;				/* �t���[���^�C�}			*/
	GSvector3		Position;			/* �|�W�V�����l				*/

} GSpositionkey;

/*----- �L�[�t���[���^�\���� ------------------------------------------------*/

typedef	struct							/* �L�[�t���[���^			*/
{
	GSuint			fKeyFrameInfo;		/* �L�[�t���[�����			*/
	GSuint			numScaleKeys;		/* �X�P�[���L�[��			*/
	GSuint			numRotateKeys;		/* ���[�e�[�g�L�[��			*/
	GSuint			numPositionKeys;	/* �|�W�V�����L�[��			*/
	GSscalekey*		pScaleKeys;			/* �X�P�[���L�[ 			*/
	GSrotatekey*	pRotateKeys;		/* ���[�e�[�g�L�[ 			*/
	GSpositionkey*	pPositionKeys;		/* �|�W�V�����L�[ 			*/

} GSkeyframe;

/*----- �{�[���t���[���\���� ------------------------------------------------*/

typedef	struct							/* �{�[���t���[���^			*/
{
	GSuint			numBoneFrames;		/* �{�[���t���[����			*/
	GSkeyframe*		pBoneFrames;		/* �{�[���t���[���f�[�^��	*/

} GSboneframe;

/*----- �A�j���[�V�����f�[�^�\���� ------------------------------------------*/

typedef	struct							/* �A�j���[�V�����f�[�^�^	*/
{
	GSuint			numAnimations;		/* �A�j���[�V�����f�[�^��	*/
	GSboneframe*	pAnimations;		/* �A�j���[�V�����f�[�^		*/

} GSanimation;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�̐����D
*
* Return  : �A�j���[�V�����f�[�^��Ԃ��D
*
*============================================================================*/
extern GSanimation*
gsAnimationNew
(
	void
);

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsAnimationDelete
(
	GSanimation*		pAnimation				/* �A�j���[�V�����f�[�^			*/
);

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsAnimationCleanUp
(
	GSanimation*	pAnimation			/* �A�j���[�V�����f�[�^			*/
);


/*=============================================================================
*
* Purpose : �A�j���[�V�����L�[�̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsAnimationGetKeyFrame
(
	GSanimation*	pAnimation,			/* �A�j���[�V�����f�[�^			*/
	GSuint			AnimationNo,		/* �擾���郂�[�V�����i���o		*/
	GSuint			BoneNo,				/* �擾����{�[���i���o			*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}			*/
	GSvector3*		pOutScale,			/*-> �X�P�[���l					*/
	GSquaternion*	pOutRotate,			/*-> ���[�e�[�g�l				*/
	GSvector3*		pOutPosition		/*-> �|�W�V�����l				*/
);

/*=============================================================================
*
* Purpose : �A�j���[�V�����t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsAnimationLoadFile
(
	GSanimation*	pAnimation,			/* �A�j���[�V�����f�[�^			*/
	const char*		pszFileName			/* ���[�V�����t�@�C����		*/
);

/*=============================================================================
*
* Purpose : �w��A�j���[�V�����̃{�[������Ԃ��D
*
* Return  : �{�[������Ԃ��D
*
*============================================================================*/
extern GSuint
gsAnimationGetNumBones
(
	GSanimation*	pAnimation,			/* �A�j���[�V�����f�[�^		*/
	GSuint			AnimationNo			/* �A�j���[�V�����i���o		*/
);

/*=============================================================================
*
* Purpose : �A�j���[�V�����̏I���^�C�}�𒲂ׂ�D
*
* Return  : �A�j���[�V�����̏I���^�C�}��Ԃ��D
*
*============================================================================*/
extern GSuint
gsAnimationGetEndTime
(
	GSanimation*	pAnimation,			/* �A�j���[�V�����f�[�^		*/
	GSuint			AnimationNo			/* �A�j���[�V�����i���o		*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
