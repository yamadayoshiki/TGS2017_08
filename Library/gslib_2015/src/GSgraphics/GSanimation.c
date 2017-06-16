/******************************************************************************
* File Name : GSanimation.c                      Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �A�j���[�V�����f�[�^�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSanimation.h"
#include	"GSquaternion.h"
#include	"GSvector3.h"
#include	"GSmath.h"
#include	"gfile.h"
#include	"heap.h"
#include	<string.h>
#include	<memory.h>
#include	<math.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void gsBoneFrameCleanUp( GSboneframe* );
static void gsKeyFrameCleanUp( GSkeyframe* );
static void gsAnimationInitialize( GSanimation*, GSuint );
static void gsBoneFrameInitialize( GSboneframe*, GSuint );
static void gsKeyFrameInitialize( GSkeyframe*, GSuint, GSuint, GSuint, GSuint );
static GSboolean gsBoneFrameLoadFile( GSboneframe*, GFILE );
static GSboolean gsKeyFrameLoadFile( GSkeyframe*, GFILE );
static GSboolean gsScaleKeyLoadFile( GSscalekey*, GFILE );
static GSboolean gsRotateKeyLoadFile( GSrotatekey*, GFILE );
static GSboolean gsPositionKeyLoadFile( GSpositionkey*, GFILE );
static void gsBoneFrameGetKeyFrame( GSboneframe*, GSuint, GSfloat, GSvector3*, GSquaternion*, GSvector3* );
static void gsKeyFrameGetKey( GSkeyframe*, GSfloat, GSvector3*, GSquaternion*, GSvector3* );
static void gsScaleKeyGetScale( GSuint, GSscalekey*, GSfloat, GSvector3* );
static void gsRotateKeyGetRotate( GSuint, GSrotatekey*, GSfloat, GSquaternion* );
static void gsPositionKeyGetPosition( GSuint, GSpositionkey*, GSfloat, GSvector3* );

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
)
{
	GSanimation*		pAnimation;

	pAnimation = new_object( sizeof( GSanimation ) );

	memset( pAnimation, 0, sizeof( GSanimation ) );

	return	pAnimation;
}

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
	GSanimation*	pAnimation			/* �A�j���[�V�����f�[�^			*/
)
{
	/* �A�j���[�V�����f�[�^�̃N���[���A�b�v */
	gsAnimationCleanUp( pAnimation );

	/* �A�j���[�V�����f�[�^�����ł����� */
	del_object( pAnimation );
}

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
)
{
	GSuint			i;

	/* �{�[���t���[���z��̃N���[���A�b�v */
	for ( i = 0; i < pAnimation->numAnimations; i++ )
	{
		gsBoneFrameCleanUp( &pAnimation->pAnimations[i] );
	}

	if ( pAnimation->pAnimations != NULL )
	{
		/* �{�[���t���[���z������� */
		del_object( pAnimation->pAnimations );

		pAnimation->pAnimations = NULL;
	}

	pAnimation->numAnimations = 0;
}

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
)
{
	/* �e�L�[�̒l������������ */
	gsVector3Init( pOutScale, 1.0f, 1.0f, 1.0f );
	gsQuaternionIdentity( pOutRotate );
	gsVector3Init( pOutPosition, 0.0f, 0.0f, 0.0f );

	/* �A�j���[�V�����i���o���A�j���[�V�����f�[�^�������傫���H */
	if ( AnimationNo >= pAnimation->numAnimations )
	{
		return;
	}

	/* �w��A�j���[�V�����C�w��{�[���̃A�j���[�V�����L�[���擾���� */
	gsBoneFrameGetKeyFrame
	(
		&pAnimation->pAnimations[ AnimationNo ],
		BoneNo, fGlobalTime,
		pOutScale, pOutRotate, pOutPosition
	);
}

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
)
{
	GFILE			file;
	GSuint			numAnimations;
	GSuint			i;

	/* �A�j���[�V�����t�@�C���̃I�[�v�� */
	if ( ( file = GFileOpen( pszFileName, "r" ) ) == NULL )
	{
		return	GS_FALSE;
	}

	/* �A�j���[�V�����f�[�^�̃N���[���A�b�v */
	gsAnimationCleanUp( pAnimation );

	/* �A�j���[�V�����f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &numAnimations );

	/* �A�j���[�V�����f�[�^�̏����� */
	gsAnimationInitialize( pAnimation, numAnimations );

	/* �{�[���t���[���̓ǂݍ��� */
	for ( i = 0; i < pAnimation->numAnimations; i++ )
	{
		gsBoneFrameLoadFile( &pAnimation->pAnimations[i], file );
	}

	/* �A�j���[�V�����t�@�C���̃N���[�Y */
	GFileClose( file );

	return	GS_TRUE;
}

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
)
{
	if ( AnimationNo >= pAnimation->numAnimations )
	{
		return	0;
	}

	return	pAnimation->pAnimations[ AnimationNo ].numBoneFrames;
}

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
)
{
	GSboneframe*	pBoneFrame;
	GSkeyframe*		pKeyFrame;
	GSuint			EndTime;
	GSuint			i;

	if ( AnimationNo >= pAnimation->numAnimations )
	{
		return	0;
	}

	/* �I���^�C���̏����� */
	EndTime = 0;

	/* �I���^�C�}�̈�ԑ����L�[���������� */
	pBoneFrame = &pAnimation->pAnimations[ AnimationNo ];
	for ( i = 0; i < pBoneFrame->numBoneFrames; i++ )
	{
		pKeyFrame = &pBoneFrame->pBoneFrames[i];

		if ( pKeyFrame->numScaleKeys != 0 )
		{
			EndTime = MAX( EndTime, pKeyFrame->pScaleKeys[ pKeyFrame->numScaleKeys-1 ].Time );
		}
		if ( pKeyFrame->numRotateKeys != 0 )
		{
			EndTime = MAX( EndTime, pKeyFrame->pRotateKeys[ pKeyFrame->numRotateKeys-1 ].Time );
		}
		if ( pKeyFrame->numPositionKeys != 0 )
		{
			EndTime = MAX( EndTime, pKeyFrame->pPositionKeys[ pKeyFrame->numPositionKeys-1 ].Time );
		}
	}

	return	EndTime;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �{�[���t���[���̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsBoneFrameCleanUp
(
	GSboneframe*		pBoneFrame			/* �{�[���t���[��			*/
)
{
	GSuint			i;

	/* �L�[�t���[���z��̃N���[���A�b�v */
	for ( i = 0; i < pBoneFrame->numBoneFrames; i++ )
	{
		gsKeyFrameCleanUp( &pBoneFrame->pBoneFrames[i] );
	}

	if ( pBoneFrame->pBoneFrames != NULL )
	{
		/* �L�[�t���[���z������� */
		del_object( pBoneFrame->pBoneFrames );

		pBoneFrame->pBoneFrames = NULL;
	}

	pBoneFrame->pBoneFrames = 0;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �L�[�t���[���̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsKeyFrameCleanUp
(
	GSkeyframe*	pKeyFrame				/* �L�[�t���[��				*/
)
{
	/* �X�P�[���L�[������ */
	if ( pKeyFrame->pScaleKeys != NULL )
	{
		del_object( pKeyFrame->pScaleKeys );
	}

	/* ���[�e�[�g�L�[������ */
	if ( pKeyFrame->pRotateKeys != NULL )
	{
		del_object( pKeyFrame->pRotateKeys );
	}

	/* �|�W�V�����L�[������ */
	if ( pKeyFrame->pPositionKeys != NULL )
	{
		del_object( pKeyFrame->pPositionKeys );
	}

	/* �L�[�t���[���f�[�^�������� */
	pKeyFrame->fKeyFrameInfo   = 0;
	pKeyFrame->numScaleKeys    = 0;
	pKeyFrame->numRotateKeys   = 0;
	pKeyFrame->numPositionKeys = 0;
	pKeyFrame->pScaleKeys      = NULL;
	pKeyFrame->pRotateKeys     = NULL;
	pKeyFrame->pPositionKeys   = NULL;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �A�j���[�V�����f�[�^�̏������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsAnimationInitialize
(
	GSanimation*	pAnimation,			/* �A�j���[�V�����f�[�^			*/
	GSuint			numAnimations		/* �A�j���[�V�����f�[�^��		*/
)
{
	size_t			size;

	/* �A�j���[�V�����f�[�^�̃N���[���A�b�v */
	gsAnimationCleanUp( pAnimation );

	pAnimation->numAnimations = numAnimations;

	/* �{�[���t���[���z��̐��� */
	if ( ( size = sizeof(GSboneframe) * pAnimation->numAnimations ) != 0 )
	{
		pAnimation->pAnimations = new_object( size );

		memset( pAnimation->pAnimations, 0, size );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �{�[���t���[���̏������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsBoneFrameInitialize
(
	GSboneframe*	pBoneFrame,			/* �{�[���t���[��			*/
	GSuint			numBones			/* �{�[���f�[�^��			*/
)
{
	size_t			size;

	/* �{�[���t���[���̃N���[���A�b�v */
	gsBoneFrameCleanUp( pBoneFrame );

	/* �{�[���t���[������ݒ� */
	pBoneFrame->numBoneFrames = numBones;

	/* �{�[���t���[���z��̐��� */
	if ( ( size = sizeof(GSkeyframe) * pBoneFrame->numBoneFrames ) != 0 )
	{
		pBoneFrame->pBoneFrames = new_object( size );

		memset( pBoneFrame->pBoneFrames, 0, size );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �L�[�t���[���̏������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsKeyFrameInitialize
(
	GSkeyframe*	pKeyFrame,				/* �L�[�t���[��				*/
	GSuint		fKeyFrameInfo,			/* �L�[�t���[�����			*/
	GSuint		numScaleKeys,			/* �X�P�[���L�[��			*/
	GSuint		numRotateKeys,			/* ���[�e�[�g�L�[��			*/
	GSuint		numPositionKeys			/* �|�W�V�����L�[��			*/
)
{
	size_t			size;

	/* �L�[�t���[���f�[�^�̃N���[���A�b�v */
	gsKeyFrameCleanUp( pKeyFrame );

	/* �L�[�t���[���f�[�^�̏����� */
	pKeyFrame->fKeyFrameInfo   = fKeyFrameInfo;
	pKeyFrame->numScaleKeys    = numScaleKeys;
	pKeyFrame->numRotateKeys   = numRotateKeys;
	pKeyFrame->numPositionKeys = numPositionKeys;

	/* �X�P�[���L�[�̐��� */
	pKeyFrame->pScaleKeys = NULL;
	if ( ( size = sizeof(GSscalekey) * pKeyFrame->numScaleKeys ) != 0 )
	{
		pKeyFrame->pScaleKeys = new_object( size );

		memset( pKeyFrame->pScaleKeys, 0, size );
	}

	/* ���[�e�[�g�L�[�̐��� */
	pKeyFrame->pRotateKeys = NULL;
	if ( ( size = sizeof(GSrotatekey) * pKeyFrame->numRotateKeys ) != 0 )
	{
		pKeyFrame->pRotateKeys = new_object( size );

		memset( pKeyFrame->pRotateKeys, 0, size );
	}

	/* �|�W�V�����L�[�̐��� */
	pKeyFrame->pPositionKeys = NULL;
	if ( ( size = sizeof(GSpositionkey) * pKeyFrame->numPositionKeys ) != 0 )
	{
		pKeyFrame->pPositionKeys = new_object( size );

		memset( pKeyFrame->pPositionKeys, 0, size );
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �{�[���t���[���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsBoneFrameLoadFile
(
	GSboneframe*	pBoneFrame,			/* �{�[���t���[��			*/
	GFILE			file				/* �t�@�C���n���h��			*/
)
{
	GSuint		i;
	GSuint		numBoneFrames = 0;

	/* �{�[���f�[�^���̓ǂݍ��� */
	GFileReadDword( file, &numBoneFrames );

	/* �{�[���t���[���̏����� */
	gsBoneFrameInitialize( pBoneFrame, numBoneFrames );

	/* �L�[�t���[���f�[�^��ǂݍ��� */
	for ( i = 0; i < pBoneFrame->numBoneFrames; i++ )
	{
		gsKeyFrameLoadFile( &pBoneFrame->pBoneFrames[i], file );
	}

	return	GFileIsSuccess( file );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �L�[�t���[���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsKeyFrameLoadFile
(
	GSkeyframe*		pKeyFrame,			/* �L�[�t���[��				*/
	GFILE			file				/* �t�@�C���n���h��			*/
)
{
	GSuint		i;
	GSuint		fKeyFrameInfo   = 0;
	GSuint		numMatrixKeys   = 0;
	GSuint		numScaleKeys    = 0;
	GSuint		numRotateKeys   = 0;
	GSuint		numPositionKeys = 0;

	/* �L�[�t���[�����̓ǂݍ��� */
	GFileReadDwordHex( file, &fKeyFrameInfo );

	/* �X�P�[���L�[���̓ǂݍ��� */
	GFileReadDword( file, &numScaleKeys );

	/* ���[�e�[�g�L�[���̓ǂݍ��� */
	GFileReadDword( file, &numRotateKeys );

	/* �|�W�V�����L�[���̓ǂݍ��� */
	GFileReadDword( file, &numPositionKeys );

	/* �}�g���N�X�L�[���̓ǂݍ��݁i���݃}�g���N�X�L�[�͎g�p���Ȃ��j */
	GFileReadDword( file, &numMatrixKeys );

	/* �L�[�t���[���f�[�^�̏�����*/
	gsKeyFrameInitialize
	(
		pKeyFrame,
		fKeyFrameInfo,
		numScaleKeys,
		numRotateKeys,
		numPositionKeys
	);

	/* �X�P�[���L�[�̓ǂݍ��� */
	for ( i = 0 ;i < pKeyFrame->numScaleKeys; i++ )
	{
		gsScaleKeyLoadFile( &pKeyFrame->pScaleKeys[i], file );
	}

	/* ���[�e�[�g�L�[�̓ǂݍ��� */
	for ( i = 0 ;i < pKeyFrame->numRotateKeys; i++ )
	{
		gsRotateKeyLoadFile( &pKeyFrame->pRotateKeys[i], file );
	}

	/* �|�W�V�����L�[�̓ǂݍ��� */
	for ( i = 0 ;i < pKeyFrame->numPositionKeys; i++ )
	{
		gsPositionKeyLoadFile( &pKeyFrame->pPositionKeys[i], file );
	}

	return	GFileIsSuccess( file );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �X�P�[���L�[�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsScaleKeyLoadFile
(
	GSscalekey*		pKey,				/* �X�P�[���L�[				*/
	GFILE			file				/* �t�@�C���n���h��			*/
)
{
	/* �^�C�}�l�̓ǂݍ��� */
	GFileReadDword( file, &pKey->Time );

	/* �X�P�[���l�̓ǂݍ��� */
	GFileReadVector3( file, &pKey->Scale );

	return	GFileIsSuccess( file );
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���[�e�[�g�L�[�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsRotateKeyLoadFile
(
	GSrotatekey*	pKey,				/* ���[�e�[�g�L�[			*/
	GFILE			file				/* �t�@�C���n���h��			*/
)
{
	/* �^�C�}�l�̓ǂݍ��� */
	GFileReadDword( file, &pKey->Time );

	/* ���[�e�[�g�l�̓ǂݍ��� */
	GFileReadQuaternion( file, &pKey->Rotate );

	/* �N�H�[�^�j�I���𐳋K������ */
	gsQuaternionNormalize( &pKey->Rotate, &pKey->Rotate );

	return	GFileIsSuccess( file );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �|�W�V�����L�[�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����ƋU��Ԃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
gsPositionKeyLoadFile
(
	GSpositionkey*	pKey,				/* �|�W�V�����L�[			*/
	GFILE			file				/* �t�@�C���n���h��			*/
)
{
	/* �^�C�}�l�̓ǂݍ��� */
	GFileReadDword( file, &pKey->Time );

	/* �|�W�V�����l�̓ǂݍ��� */
	GFileReadVector3( file, &pKey->Position );

	return	GFileIsSuccess( file );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �w��{�[���̃L�[�t���[���f�[�^�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsBoneFrameGetKeyFrame
(
	GSboneframe*	pBoneFrame,			/* �{�[���t���[���L�[�t���[��	*/
	GSuint			BoneNo,				/* �擾����{�[���̂h�c			*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}			*/
	GSvector3*		pOutScale,			/*-> �X�P�[���l					*/
	GSquaternion*	pOutRotate,			/*-> ���[�e�[�g�l				*/
	GSvector3*		pOutPosition		/*-> �|�W�V�����l				*/
)
{
	/* �{�[���i���o���{�[���t���[���������傫���H */
	if ( BoneNo >= pBoneFrame->numBoneFrames )
	{
		return;
	}

	/* �L�[�t���[���f�[�^����X�P�[���l�C���[�e�[�g�l�C�|�W�V�����l���擾 */
	gsKeyFrameGetKey
	(
		&pBoneFrame->pBoneFrames[ BoneNo ],
		fGlobalTime,
		pOutScale, pOutRotate, pOutPosition
	);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �L�[�t���[���f�[�^�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsKeyFrameGetKey
(
	GSkeyframe*		pKeyFrame,			/* �}�g���N�X�L�[�z��			*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}			*/
	GSvector3*		pOutScale,			/*-> �X�P�[���l					*/
	GSquaternion*	pOutRoate,			/*-> ���[�e�[�g�l				*/
	GSvector3*		pOutPosition		/*-> �|�W�V�����l				*/
)
{
	/* �e�L�[�̒l������������ */
	gsVector3Init( pOutScale, 1.0f, 1.0f, 1.0f );
	gsQuaternionIdentity( pOutRoate );
	gsVector3Init( pOutPosition, 0.0f, 0.0f, 0.0f );

	/* �X�P�[���L�[�������Ă��邩�H */
	if ( pKeyFrame->pScaleKeys != NULL )
	{
		/* �X�P�[���L�[���擾���� */
		gsScaleKeyGetScale
		(
			pKeyFrame->numScaleKeys,
			pKeyFrame->pScaleKeys,
			fGlobalTime,
			pOutScale
		);
	}

	/* ���[�e�[�g�L�[�������Ă��邩�H */
	if ( pKeyFrame->pRotateKeys != NULL )
	{
		/* ���[�e�[�g�L�[���擾���� */
		gsRotateKeyGetRotate
		(
			pKeyFrame->numRotateKeys,
			pKeyFrame->pRotateKeys,
			fGlobalTime,
			pOutRoate
		);
	}

	/* �|�W�V�����L�[�������Ă��邩�H */
	if ( pKeyFrame->pPositionKeys != NULL )
	{
		/* �|�W�V�����L�[���擾���� */
		gsPositionKeyGetPosition
		(
			pKeyFrame->numPositionKeys,
			pKeyFrame->pPositionKeys,
			fGlobalTime,
			pOutPosition
		);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �X�P�[���L�[�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsScaleKeyGetScale
(
	GSuint			numScaleKeys,		/* �X�P�[���L�[��		*/
	GSscalekey*		pScaleKeys,			/* �X�P�[���L�[�z��		*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}	*/
	GSvector3*		pScale				/*-> �擾�����X�P�[���l	*/
)
{
	GSfloat			fTime;
	GSfloat			fTime1;
	GSfloat			fTime2;
	GSfloat			fLerpValue;
	GSuint			iKey;
	GSuint			iKey1;
	GSuint			iKey2;

	fTime = (float)fmod( fGlobalTime, pScaleKeys[numScaleKeys-1].Time );
	iKey1 = 0;
	iKey2 = 0;

	for ( iKey = 0 ;iKey < numScaleKeys ; iKey++ )
	{
		if ( (float)pScaleKeys[iKey].Time > fTime )
		{
			iKey2 = iKey;

			if ( iKey > 0 )
			{
				iKey1= iKey - 1;
			}
			else
			{
				iKey1 = iKey;
			}

			break;
		}
	}
	fTime1 = (float)pScaleKeys[iKey1].Time;
	fTime2 = (float)pScaleKeys[iKey2].Time;

	if ( ( fTime2 - fTime1 ) ==0 )
	{
		fLerpValue = 0;
	}
	else
	{
		fLerpValue =  ( fTime - fTime1 )  / ( fTime2 - fTime1 );
	}

	/* �X�P�[���L�[�̐��`��Ԃ��s�� */
	gsVector3Lerp
	(
		pScale,
		&pScaleKeys[iKey1].Scale, 
		&pScaleKeys[iKey2].Scale,
		fLerpValue
	);
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���[�e�[�g�L�[�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsRotateKeyGetRotate
(
	GSuint			numRotateKeys,		/* ���[�e�[�g�L�[��			*/
	GSrotatekey*	pRotateKeys,		/* ���[�e�[�g�L�[�z��		*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}		*/
	GSquaternion*	pRotate				/*-> �擾�������[�e�[�g�l	*/
)
{
	GSfloat			fTime;
	GSfloat			fTime1;
	GSfloat			fTime2;
	GSfloat			fLerpValue;
	GSuint			iKey;
	GSuint			iKey1;
	GSuint			iKey2;

	fTime = (float)fmod( fGlobalTime, pRotateKeys[numRotateKeys-1].Time );
	iKey1 = 0;
	iKey2 = 0;
	for ( iKey = 0 ;iKey < numRotateKeys; iKey++ )
	{
		if ( (float)pRotateKeys[iKey].Time > fTime )
		{
			iKey2 = iKey;

			if ( iKey > 0 )
			{
				iKey1 = iKey - 1;
			}
			else
			{
				iKey1 = iKey;
			}
			break;
		}
	}

	fTime1 = (float)pRotateKeys[iKey1].Time;
	fTime2 = (float)pRotateKeys[iKey2].Time;

	if ( ( fTime2 - fTime1 ) == 0 )
	{
		fLerpValue = 0;
	}
	else
	{
		fLerpValue =  ( fTime - fTime1 )  / ( fTime2 - fTime1 );
	}

	/* ���[�e�[�g�L�[�̐��`��Ԃ��s�� */
	gsQuaternionSlerp
	(
		pRotate,
		&pRotateKeys[iKey1].Rotate,
		&pRotateKeys[iKey2].Rotate,
		fLerpValue
	);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �|�W�V�����L�[�̎擾�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
gsPositionKeyGetPosition
(
	GSuint			numPositionKeys,	/* �|�W�V�����L�[��		*/
	GSpositionkey*	pPositionKeys,		/* �|�W�V�����L�[�z��	*/
	GSfloat			fGlobalTime,		/* �擾����L�[�̃^�C�}	*/
	GSvector3*		pPosition			/*-> �擾�����|�W�V����	*/
)
{
	GSfloat			fTime;
	GSfloat			fTime1;
	GSfloat			fTime2;
	GSfloat			fLerpValue;
	GSuint			iKey;
	GSuint			iKey1;
	GSuint			iKey2;

	fTime = (float)fmod( fGlobalTime, pPositionKeys[numPositionKeys-1].Time );
	iKey1 = 0;
	iKey2 = 0;
	for ( iKey = 0 ;iKey < numPositionKeys ; iKey++ )
	{
		if ( (float)pPositionKeys[iKey].Time > fTime )
		{
			iKey2 = iKey;

			if ( iKey > 0 )
			{
				iKey1 = iKey - 1;
			}
			else
			{
				iKey1 = iKey;
			}
			break;
		}
	}
	fTime1 = (float)pPositionKeys[iKey1].Time;
	fTime2 = (float)pPositionKeys[iKey2].Time;

	if ( ( fTime2 - fTime1 ) ==0 )
	{
		fLerpValue = 0;
	}
	else
	{
		fLerpValue =  ( fTime - fTime1 )  / ( fTime2 - fTime1 );
	}

	/* �|�W�V�����L�[�̐��`��Ԃ��s�� */
	gsVector3Lerp
	(
		pPosition,
		&pPositionKeys[iKey1].Position,
		&pPositionKeys[iKey2].Position,
		fLerpValue
	);
}

/********** End of File ******************************************************/
