/******************************************************************************
* File Name : GSframetimer.c                     Ver : 1.00  Date : 2003-04-17
*
* Description :
*
*		�t���[���^�C�}�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSframetimer.h"
#include	<GL/glut.h>

/****** �萔�錾 *************************************************************/

#define	FPS				60					/* �P�b�Ԃ̃t���[����		*/
#define	FRAME_SKIP_MAX	8					/* �ő�t���[���X�L�b�v��	*/
#define	FPS_ERROR		0.1f				/* �^�C�}�̌덷				*/

/****** �O���[�o���ϐ��錾 ***************************************************/

/* �P�b�Ԃ�����̃t���[���� */
static GSfloat	s_FPS = FPS;

/* �P�t���[���̊J�n���� */
static GSfloat	s_StartTime = 0;

/* �O�t���[���̊J�n���� */
static GSfloat	s_PrevTime = 0;

/* �P�t���[���̌o�ߎ��� */
static GSfloat	s_FrameTime = 0;

/* �����I�[�o�[���� */
static GSfloat	s_OverTime = 0;

/* �Œ�E�F�C�g�^�C�} */
static GSfloat	s_WaitTime = 0.25f;

/* �t���[���X�L�b�v�J�E���^ */
static GSuint	s_FrameSkipCount = 0;

/* �ő�t���[���X�L�b�v�� */
static GSuint	s_FrameSkipCountMax = FRAME_SKIP_MAX;


/*=============================================================================
*
* Purpose : �t���[���^�C�}�̃��Z�b�g�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrameTimerReset
(
	void
)
{
	s_StartTime      = 0.0f;
	s_FrameTime      = 0.0f;	
	s_OverTime       = 0.0f;
	s_FrameSkipCount = 0;
	s_PrevTime       = gsTimeGetTime();
}

/*=============================================================================
*
* Purpose : �t���[���^�C�}���X�V����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrameTimerUpdate
(
	void
)
{
	/* �P�t���[���̊J�n�^�C�}���v�� */
	s_StartTime = gsTimeGetTime();

	/* �P�t���[��������̎��Ԃ����߂� */
	s_FrameTime = ( s_StartTime - s_PrevTime ) * s_FPS;

	/* �O��̃^�C�}�l��ݒ肷�� */
	s_PrevTime = s_StartTime;

	/* �e�o�r�^�C�}�ȏ�Ɏ��Ԃ��o�߂��Ă��܂��Ă��邩�H */
	s_OverTime = 0.0f;
	if ( s_FrameTime > 1.0f )
	{
		/* �I�[�o�[�������Ԃ��v�Z���� */
		s_OverTime = s_FrameTime - 1.0f;

		/* �^�C�}�𒲐����� */
		s_FrameTime = 1.0f;

		/* �^�C�}�l�̌덷���l������ */
		if ( s_OverTime <= FPS_ERROR )
		{
			s_OverTime = 0.0f;
		}
	}
}

/*=============================================================================
*
* Purpose : ���������ɂ��`��̃X�L�b�v���K�v�����ׂ�D
*
* Return  : �X�L�b�v����̂ł���ΐ^�C�X�L�b�v���K�v�Ȃ���΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsFrameTimerIsSkip
(
	void
)
{
	/* �ő�X�L�b�v���ȏ�̓X�L�b�v�����Ȃ��悤�ɂ��� */
	if( s_FrameSkipCount >= s_FrameSkipCountMax )
	{
		/* �X�L�b�v�������������� */
		s_FrameSkipCount = 0;

		/* �I�[�o�[�������Ԃ����������� */
		s_OverTime = 0.0f;

		return	GS_FALSE;
	}

	/* ���ԃI�[�o�[���Ă��邩�H*/
	if ( s_OverTime > 0 )
	{
		/* �e�o�r�^�C�}�����I�[�o�[���Ă��邩�H */
		if ( s_OverTime > 1.0f )
		{
			/* �I�[�o�[�������Ԃ𒲐����� */
			s_OverTime -= 1.0f;

			/* �^�C�}�𒲐����� */
			s_FrameTime = 1.0f;
		}
		else
		{
			/* �^�C�}�𒲐����� */
			s_FrameTime = s_OverTime;

			/* �I�[�o�[�������ԕ��͏������������ɂ��� */
			s_OverTime = 0.0f;
		}

		/* �X�L�b�v�J�E���^�𑝉������� */
		s_FrameSkipCount++;

		/* �`����X�L�b�v����K�v������ */
		return	GS_TRUE;
	}

	/* �X�L�b�v�J�E���^������������ */
	s_FrameSkipCount = 0;

	/* �I�[�o�[�������Ԃ����������� */
	s_OverTime = 0.0f;

	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �^�C�}�E�F�C�g������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrameTimerWait
(
	void
)
{
	GSfloat		FrameTime;
	GSfloat		StartTime;
	GSfloat		WaitTime;

	/* �P�t���[��������̎��Ԃ����߂� */
	FrameTime = ( gsTimeGetTime() - s_StartTime ) * s_FPS;

	/* �Œ�E�F�C�g���Ԃ������Ԃ��Z���H */
	if ( FrameTime < s_WaitTime )
	{
		/* �E�F�C�g���鎞�Ԃ����߂� */
		WaitTime = s_WaitTime - FrameTime;

		/* �Œ�E�F�C�g�^�C�}���E�F�C�g���� */
		StartTime = gsTimeGetTime() * s_FPS;
		while ( ( ( ( gsTimeGetTime() * s_FPS ) - StartTime )  ) < WaitTime )
			;
	}
}

/*=============================================================================
*
* Purpose : �t���[���^�C�}�̎擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSfloat
gsFrameTimerGetTime
(
	void
)
{
	return	s_FrameTime;
}

/*=============================================================================
*
* Purpose : �Œ�E�F�C�g���Ԃ̐ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrameTimerSetWaitTime
(
	GSfloat		WaitTime			/* �Œ�E�F�C�g���� */
)
{
	s_WaitTime = WaitTime;
}

/*=============================================================================
*
* Purpose : �e�o�r�̐ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFrameTimerSetFPS
(
	GSfloat		fps					/* �e�o�r�̐ݒ� */
)
{
	s_FPS = fps;
}

/*=============================================================================
*
* Purpose : �b�^�C�}�̎擾�D
*
* Return  : �b�^�C�}��Ԃ��D
*
*============================================================================*/
extern GSfloat
gsTimeGetTime
(
	void
)
{
	LARGE_INTEGER		Time;
	LARGE_INTEGER		Freq;

	/* �^�C�}�̎擾 */
	QueryPerformanceCounter( &Time );

	/* �^�C�}�̕���\���擾 */
	QueryPerformanceFrequency( &Freq );

	/* �b�P�ʂɕϊ����ĕԂ� */
	return	(GSfloat)( (double)Time.QuadPart / (double)Freq.QuadPart );
}

/********** End of File ******************************************************/
