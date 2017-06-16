/******************************************************************************
* File Name : gmidires.c                           Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �l�h�c�h���\�[�X�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gmidires.h"
#include	"heap.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �l�h�c�h���\�[�X�Ǘ��\���� ------------------------------------------*/

typedef	struct
{
	GSOUND		gsnd;				/* �T�E���h�n���h��         */
	int			n;					/* �l�h�c�h���\�[�X��       */
	GMIDI**		midi;				/* �l�h�c�h���\�[�X��       */

} midires;

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̐����D
*
* Return  : �l�h�c�h���\�[�X�n���h����Ԃ��D
*
*============================================================================*/
GMIDIRESOURCE
GMidiResNew
(
	GSOUND			gsnd			/* �T�E���h�n���h��         */
)
{
	midires*		mres;

	mres = new_object( sizeof( midires ) );

	mres->gsnd = gsnd;
	mres->n    = 0;
	mres->midi = NULL;

	return	(GMIDIRESOURCE)mres;
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMidiResDelete
(
	GMIDIRESOURCE	hnd				/* �l�h�c�h���\�[�X�n���h�� */
)
{
	midires*		mres = (midires*)hnd;

	/* ���ׂĂ̂l�h�c�h���\�[�X����� */
	GMidiResDelAllResource( hnd );

	del_object( mres );
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMidiResInit
(
	GMIDIRESOURCE	hnd,			/* �l�h�c�h���\�[�X�n���h�� */
	int				n				/* �l�h�c�h���\�[�X��       */
)
{
	midires*		mres = (midires*)hnd;
	int				i;

	/* ���ׂĂ̂l�h�c�h���\�[�X����� */
	GMidiResDelAllResource( hnd );

	mres->n    = n;
	mres->midi = NULL;

	if ( mres->n != 0 )
	{
		mres->midi = new_object( sizeof( GMIDI* ) * mres->n );
	}
	for ( i = 0; i < mres->n; i++ )
	{
		mres->midi[i] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�����ׂĉ���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMidiResDelAllResource
(
	GMIDIRESOURCE	hnd				/* �l�h�c�h���\�[�X�n���h�� */
)
{
	midires*		mres = (midires*)hnd;
	int				i;

	if ( mres->midi == NULL )
	{
		return;
	}

	for ( i = 0; i < mres->n; i++ )
	{
		if ( mres->midi[i] != NULL )
		{
			GSoundDeleteMidi( mres->gsnd, mres->midi[i] );
		
			mres->midi[i] = NULL;
		}
	}
	del_object( mres->midi );

	mres->n    = 0;
	mres->midi = NULL;
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ���������^�C���s������U��Ԃ��D
*
*============================================================================*/
BOOL
GMidiResLoadResource
(
	GMIDIRESOURCE	hnd,			/* �l�h�c�h���\�[�X�n���h�� */
	int				id,				/* �l�h�c�h���\�[�X�h�c     */
	const char*		midi_fname,		/* �l�h�c�h�t�@�C����       */
	BOOL			flag			/* ���[�v�w��t���O         */
)
{
	midires*		mres = (midires*)hnd;
	GMIDI			midi;

	if ( id >= mres->n )
	{
		return	FALSE;
	}

	if ( mres->midi[ id ] != NULL )
	{
		return	FALSE;
	}

	/* �l�h�c�h�t�@�C���̓ǂݍ��� */
	if ( ( midi = GSoundLoadMidi( mres->gsnd, midi_fname, flag ) ) == NULL )
	{
		return	FALSE;
	}
	mres->midi[ id ]= midi;

	return	TRUE;
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̎擾�D
*
* Return  : �ǂݍ��݂ɐ���������^�C���s������U��Ԃ��D
*
*============================================================================*/
GMIDI
GMidiResGetResource
(
	GMIDIRESOURCE	hnd,			/* �l�h�c�h���\�[�X�n���h�� */
	int				id				/* �l�h�c�h���\�[�X�h�c     */
)
{
	midires*		mres = (midires*)hnd;

	if ( id >= mres->n )
	{
		return	NULL;
	}

	return	mres->midi[ id ];
}

/*=============================================================================
*
* Purpose : �l�h�c�h���\�[�X�̉���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GMidiResDelResource
(
	GMIDIRESOURCE	hnd,			/* �l�h�c�h���\�[�X�n���h�� */
	int				id				/* �l�h�c�h���\�[�X�h�c     */
)
{
	midires*		mres = (midires*)hnd;

	if ( id >= mres->n )
	{
		return;
	}
	if ( mres->midi[ id ] == NULL )
	{
		return;
	}

	GSoundDeleteMidi( mres->gsnd, mres->midi[ id ] );

	mres->midi[ id ] = NULL;
}

/********** End of File ******************************************************/
