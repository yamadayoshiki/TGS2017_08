/******************************************************************************
* File Name : gwaveres.c                           Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �v�`�u�d���\�[�X�Ǘ��D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"gwaveres.h"
#include	"heap.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �v�`�u�d���\�[�X�Ǘ��\���� ------------------------------------------*/

typedef	struct
{
	GSOUND		gsnd;				/* �T�E���h�n���h��         */
	int			n;					/* �v�`�u�d���\�[�X��       */
	GWAVE**		wave;				/* �v�`�u�d���\�[�X         */

} waveres;

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̐����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
GWAVERESOURCE
GWaveResNew
(
	GSOUND			gsnd			/* �T�E���h�n���h��         */
)
{
	waveres*		wres;

	wres = new_object( sizeof ( waveres ) );

	wres->gsnd = gsnd;
	wres->n    = 0;
	wres->wave = NULL;

	return	(GWAVERESOURCE)wres;
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveResDelete
(
	GWAVERESOURCE	hnd				/* �v�`�u�d���\�[�X�n���h�� */
)
{
	waveres*		wres = (waveres*)hnd;

	/* ���ׂĂ̂v�`�u�d���\�[�X����� */
	GWaveResDelAllResource( hnd );

	del_object( wres );
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveResInit
(
	GWAVERESOURCE	hnd,			/* �v�`�u�d���\�[�X�n���h�� */
	int				n				/* �v�`�u�d���\�[�X��       */
)
{
	waveres*		wres = (waveres*)hnd;
	int				i;

	/* ���ׂĂ̂v�`�u�d���\�[�X����� */
	GWaveResDelAllResource( hnd );

	wres->n    = n;
	wres->wave = NULL;

	if ( wres->n != 0 )
	{
		wres->wave = new_object( sizeof( GWAVE* ) * wres->n );
	}
	for ( i = 0; i < wres->n; i++ )
	{
		wres->wave[i] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�����ׂĉ���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveResDelAllResource
(
	GWAVERESOURCE	hnd				/* �v�`�u�d���\�[�X�n���h�� */
)
{
	waveres*		wres = (waveres*)hnd;
	int				i;

	if ( wres->wave == NULL )
	{
		return;
	}

	for ( i = 0; i < wres->n; i++ )
	{
		if ( wres->wave[i] != NULL )
		{
			GSoundDeleteWave( wres->gsnd, wres->wave[i] );
		
			wres->wave[i] = NULL;
		}
	}
	del_object( wres->wave );

	wres->n    = 0;
	wres->wave = NULL;
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ���������^�C���s������U��Ԃ��D
*
*============================================================================*/
BOOL
GWaveResLoadResource
(
	GWAVERESOURCE	hnd,			/* �v�`�u�d���\�[�X�n���h�� */
	int				id,				/* �v�`�u�d���\�[�X�h�c     */
	const char*		wave_fname,		/* �v�`�u�d�t�@�C����       */
	int				cnt,			/* �����Đ���               */
	GWAVEFLAG		flag			/* �Đ��^�C�v�t���O         */
)
{
	waveres*		wres = (waveres*)hnd;
	GWAVE			wave;

	if ( id >= wres->n )
	{
		return	FALSE;
	}

	if ( wres->wave[ id ] != NULL )
	{
		return	FALSE;
	}

	/* �v�`�u�d�t�@�C���̓ǂݍ��� */
	if ( ( wave = GSoundLoadWave( wres->gsnd, wave_fname, cnt, flag ) ) == NULL )
	{
		return	FALSE;
	}
	wres->wave[ id ]= wave;

	return	TRUE;
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̎擾�D
*
* Return  : �ǂݍ��݂ɐ���������^�C���s������U��Ԃ��D
*
*============================================================================*/
GWAVE
GWaveResGetResource
(
	GWAVERESOURCE	hnd,			/* �v�`�u�d���\�[�X�n���h�� */
	int				id				/* �v�`�u�d���\�[�X�h�c     */
)
{
	waveres*		wres = (waveres*)hnd;

	if ( id >= wres->n )
	{
		return	NULL;
	}

	return	wres->wave[ id ];
}

/*=============================================================================
*
* Purpose : �v�`�u�d���\�[�X�̉���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
GWaveResDelResource
(
	GWAVERESOURCE	hnd,			/* �v�`�u�d���\�[�X�n���h�� */
	int				id				/* �v�`�u�d���\�[�X�h�c     */
)
{
	waveres*		wres = (waveres*)hnd;

	if ( id >= wres->n )
	{
		return;
	}
	if ( wres->wave[ id ] == NULL )
	{
		return;
	}

	GSoundDeleteWave( wres->gsnd, wres->wave[ id ] );

	wres->wave[ id ] = NULL;
}

/********** End of File ******************************************************/
