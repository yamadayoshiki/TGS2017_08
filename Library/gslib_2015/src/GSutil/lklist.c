/******************************************************************************
* File Name : lklist.c                             Ver : 1.00  Date : 98-10-22
*
* Description :
*
*       �A�����X�g�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"lklist.h"
#include	"heap.h"

/****** �f�[�^�^�錾 *********************************************************/

/*----- �A�����X�g�m�[�h�\���� ----------------------------------------------*/

typedef	struct node
{
	struct node*	prev;			/* �O�̃m�[�h�̃|�C���^         */
	struct node*	next;			/* ���̃m�[�h�̃|�C���^         */
	void*			item;			/* �i�[���Ă���v�f             */

} NODE;

/*----- �A�����X�g�\���� -----------------------------------------------------*/

typedef	struct
{
	int				count;			/* ���݂̗v�f��                 */
	NODE			header;			/* �_�~�[�m�[�h�w�b�_           */

} LIST;

/*----- �A�����X�g�����q�\���� -----------------------------------------------*/

typedef	struct
{
	LIST*			list;			/* �A�����X�g�̃|�C���^         */
	NODE*			node;			/* �Q�ƒ��̃m�[�h               */

} ITER;

/****** �֐��v���g�^�C�v�錾 *************************************************/

static NODE*	node_new( void* );
static void		node_delete( NODE* );
static void		node_remove( NODE* );
static void		node_insert_after( NODE*, NODE* );

/*=============================================================================
*
* Purpose : �A�����X�g�̐����D
*
* Return  : �A�����X�g�n���h����Ԃ��D
*
*============================================================================*/
LKLIST
LkListNew
(
	void
)
{
	LIST*		lst;

	lst = new_object( sizeof( LIST ) );

	lst->count       = 0;
	lst->header.prev = &lst->header;
	lst->header.next = &lst->header;
	lst->header.item = NULL;

	return	(LKLIST)lst;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListDelete
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	NODE*		next;

	for ( node = lst->header.next; node != &lst->header; node = next )
	{
		next = node->next;

		node_delete( node );
	}
	del_object( lst );
}

/*=============================================================================
*
* Purpose : �A�����X�g�̗v�f���𒲂ׂ�D
*
* Return  : �A�����X�g�̗v�f����Ԃ��D
*
*============================================================================*/
int
LkListGetCount
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;

	return	lst->count;
}

/*=============================================================================
*
* Purpose : �A�����X�g���󂫂��ǂ������ׂ�D
*
* Return  : �󂫂ł���ΐ^�C�󂫂łȂ���΋U��Ԃ��D
*
*============================================================================*/
BOOL
LkListIsEmpty
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;

	if ( lst->count == 0 )
	{
		return	TRUE;
	}

	return	FALSE;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̐擪�ɗv�f��ǉ��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListAddHead
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void*		item				/* �ǉ�����v�f                 */
)
{
	LIST*		lst = (LIST*)hnd;

	node_insert_after( &lst->header, node_new( item ) );

	lst->count++;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̍Ō���ɗv�f��ǉ��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListAddTail
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void*		item				/* �ǉ�����v�f                 */
)
{
	LIST*		lst = (LIST*)hnd;

	node_insert_after( lst->header.prev, node_new( item ) );

	lst->count++;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̐擪�̗v�f����菜���D
*
* Return  : �A�����X�g�����菜�����擪�̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListRemoveHead
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;
	void*		item;

	if ( lst->count == 0 )
	{
		return	NULL;
	}

	item = lst->header.next->item;

	node_remove( lst->header.next );

	lst->count--;

	return	item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̍Ō���̗v�f����菜���D
*
* Return  : �A�����X�g�����菜�����Ō���̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListRemoveTail
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;
	void*		item;

	if ( lst->count == 0 )
	{
		return	NULL;
	}

	item = lst->header.prev->item;

	node_remove( lst->header.prev );

	lst->count--;

	return	item;
}

/*=============================================================================
*
* Purpose : �A�����X�g����w��v�f����菜���D
*
* Return  : �A�����X�g�����菜�����v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListRemove
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void*		item				/* ��菜���v�f                 */
)
{
	LIST*		lst = (LIST*)hnd;
	void*		find_item;
	NODE*		node;

	find_item = NULL;
	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( node->item == item )
		{
			find_item = node->item;
			node_remove( node );
			lst->count--;
			break;
		}
	}

	return	find_item;
}

/*=============================================================================
*
* Purpose : �A�����X�g����w��ʒu�̗v�f����菜���D
*
* Return  : �A�����X�g�����菜�����v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListRemoveAt
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			index				/* ���o�������ʒu             */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	void*		item;
	int			count;

	if ( index >= lst->count )
	{
		return	NULL;
	}

	node = lst->header.next;
	for ( count = 0; count < index; count++ )
	{
		 node = node->next;
	}
	item = node->item;
	node_remove( node );
	lst->count--;

	return	item;
}

/*=============================================================================
*
* Purpose : �A�����X�g����S�Ă̗v�f����菜���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListRemoveAll
(
	LKLIST		hnd					/* �A�����X�g�n���h��           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	NODE*		next;

	for ( node = lst->header.next; node != &lst->header; node = next )
	{
		next = node->next;

		node_delete( node );
	}
	lst->count = 0;
}

/*=============================================================================
*
* Purpose : �A�����X�g����w��ʒu�̗v�f�����o���D
*
* Return  : �A�����X�g������o�����v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListGetAt
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			index				/* ���o�������ʒu             */
)
{
	LIST*		lst = (LIST*)hnd;
	int			count;
	NODE*		node;

	if ( index >= lst->count )
	{
		return	NULL;
	}

	node = lst->header.next;
	for ( count = 0; count < index; count++ )
	{
		 node = node->next;
	}

	return	node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̎w��ʒu�ɗv�f��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListSetAt
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			index,				/* �ݒ肵�����ʒu               */
	void*		item				/* �ݒ肵�����v�f               */
)
{
	LIST*		lst = (LIST*)hnd;
	int			count;
	NODE*		node;

	if ( index >= lst->count )
	{
		return;
	}

	node = lst->header.next;
	for ( count = 0; count < index; count++ )
	{
		 node = node->next;
	}

	node->item = item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̎w��v�f�̑O�ɗv�f��}���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListInsertBefore
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void*		next,				/* �}���������v�f�̎��̗v�f     */
	void*		item				/* �}���������v�f               */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;

	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( node->item == next )
		{
			break;
		}
	}

	node_insert_after( node->prev, node_new( item ) );

	lst->count++;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̎w��v�f�̌��ɗv�f��}���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListInsertAfter
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void*		prev,				/* �}���������v�f�̑O�̗v�f     */
	void*		item				/* �}���������v�f               */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;

	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( node->item == prev )
		{
			break;
		}
	}

	node_insert_after( node, node_new( item ) );

	lst->count++;
}

/*=============================================================================
*
* Purpose : �A�����X�g����w��v�f�̃C���f�b�N�X�����߂�D
*
* Return  : �v�f�̃C���f�b�N�X��Ԃ��D�����C�v�f���Ȃ������ꍇ�|�P��Ԃ��D
*
*============================================================================*/
int
LkListFindIndex
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	void* 		item				/* �C���f�b�N�X�����߂����v�f   */
)
{
	LIST*		lst = (LIST*)hnd;
	int			count;
	NODE*		node;

	count = 0;
	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( node->item == item )
		{
			break;
		}
		count++;
	}

	if ( node == &lst->header )
	{
		return	-1;
	}

	return	count;
}

/*=============================================================================
*
* Purpose : �A�����X�g����v�f����������D
*
* Return  : �����ɐ�������Δ��������v�f��Ԃ��D
*           �����Ɏ��s�����ꍇ�́C�m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListSearch
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	const void*	key,				/* �����L�[�̃|�C���^           */
	BOOL		(*cmp)( const void* key, const void* item )
									/* ��r�֐��̃|�C���^           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;

	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( cmp( key, node->item ) == TRUE )
		{
			return	node->item;
		}
	}

	return	NULL;
}

/*=============================================================================
*
* Purpose : �A�����X�g����v�f����������D
*
* Return  : �����ɐ�������Δ��������v�f�̃C���f�b�N�X��Ԃ��D
*           �����Ɏ��s�����ꍇ�́C�|�P��Ԃ��D
*
*============================================================================*/
int
LkListSearchIndex
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	const void*	key,				/* �����L�[�̃|�C���^           */
	BOOL		(*cmp)( const void* key, const void* item )
									/* ��r�֐��̃|�C���^           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	int			count;

	count = 0;
	for ( node = lst->header.next; node != &lst->header; node = node->next )
	{
		if ( cmp( key, node->item ) == TRUE )
		{
			return	count;
		}
		count++;
	}

	return	-1;
}

/*=============================================================================
*
* Purpose : �A�����X�g�̗v�f���\�[�g����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListSort
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			(*cmp)( const void* item1, const void* item2 )
									/* ��r�֐��̃|�C���^           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		n1;
	NODE*		n2;
	void*		item;

	for ( n1 = lst->header.next; n1 != lst->header.prev; n1 = n1->next )
	{
		for ( n2 = n1->next; n2 != &lst->header; n2 = n2->next )
		{
			if ( cmp( n1->item, n2->item ) > 0 )
			{
				item     = n1->item;
				n1->item = n2->item;
				n2->item = item;
			}
		}
	}
}

/*=============================================================================
*
* Purpose : �A�����X�g����ő�l�̗v�f����������D
*
* Return  : �A�����X�g�̍ő�l�̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListFindMax
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			(*cmp)( const void* item1, const void* item2 )
									/* ��r�֐��̃|�C���^           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	NODE*		max_node;

	if ( lst->count == 0 )
	{
		return	NULL;
	}

	max_node = lst->header.next;
	for ( node = max_node; node != &lst->header; node = node->next )
	{
		if ( cmp( node->item, max_node->item ) > 0 )
		{
			max_node = node;
		}
	}

	return	max_node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g����ŏ��l�̗v�f����������D
*
* Return  : �A�����X�g�̍ŏ��l�̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListFindMin
(
	LKLIST		hnd,				/* �A�����X�g�n���h��           */
	int			(*cmp)( const void* item1, const void* item2 )
									/* ��r�֐��̃|�C���^           */
)
{
	LIST*		lst = (LIST*)hnd;
	NODE*		node;
	NODE*		min_node;

	if ( lst->count == 0 )
	{
		return	NULL;
	}

	min_node = lst->header.next;
	for ( node = min_node; node != &lst->header; node = node->next )
	{
		if ( cmp( node->item, min_node->item ) < 0 )
		{
			min_node = node;
		}
	}

	return	min_node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̐����D
*
* Return  : �A�����X�g�����q�n���h����Ԃ��D
*
*============================================================================*/
LKITER
LkListIterNew
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	LIST*		lst = (LIST*)hnd;
	ITER*		iter;

	iter = new_object( sizeof( ITER ) );

	iter->list  = lst;
	iter->node  = lst->header.next;

	return	(LKITER)iter;
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
void
LkListIterDelete
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	ITER*		iter = (ITER*)hnd;

	del_object( iter );
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̎Q�ƈʒu��擪�ɐݒ�D
*
* Return  : �A�����X�g�̐擪�̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListIterGetHeadPosition
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	ITER*		iter = (ITER*)hnd;
	LIST*		lst;

	lst = iter->list;
	if ( lst->count == 0 )
	{
		return	NULL;
	}
	iter->node = lst->header.next;

	return	iter->node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̎Q�ƈʒu���Ō���ɐݒ�D
*
* Return  : �A�����X�g�̍Ō���̗v�f��Ԃ��D
*           �A�����X�g���󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListIterGetTailPosition
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	ITER*		iter = (ITER*)hnd;
	LIST*		lst;

	lst = iter->list;
	if ( lst->count == 0 )
	{
		return	NULL;
	}
	iter->node = lst->header.prev;

	return	iter->node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̎Q�ƈʒu�����o���C�Q�ƈʒu�����Ɉړ��D
*
* Return  : �Q�ƈʒu�̗v�f��Ԃ��D�Q�ƈʒu���Ō���𒴂����ꍇ��A�����X�g��
*           �󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListIterGetNext
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	ITER*		iter = (ITER*)hnd;
	LIST*		lst;
	NODE*		node;

	lst = iter->list;
	if ( ( node = iter->node ) == &lst->header )
	{
		return	NULL;
	}
	iter->node = node->next;

	return	node->item;
}

/*=============================================================================
*
* Purpose : �A�����X�g�����q�̎Q�ƈʒu�����o���C�Q�ƈʒu��O�Ɉړ��D
*
* Return  : �Q�ƈʒu�̗v�f��Ԃ��D�Q�ƈʒu���擪�𒴂����ꍇ��A�����X�g��
*           �󂫂̏ꍇ�͂m�t�k�k�|�C���^��Ԃ��D
*
*============================================================================*/
void*
LkListIterGetPrev
(
	LKITER		hnd					/* �A�����X�g�����q�n���h��     */
)
{
	ITER*		iter = (ITER*)hnd;
	LIST*		lst;
	NODE*		node;

	lst = iter->list;
	if ( ( node = iter->node ) == &lst->header )
	{
		return	NULL;
	}
	iter->node = node->prev;

	return	node->item;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�̐����D
*
* Return  : ���������m�[�h��Ԃ��D
*
*----------------------------------------------------------------------------*/
static NODE*
node_new
(
	void*		item				/* �i�[����v�f                 */
)
{
	NODE*		node;

	node = new_object( sizeof( NODE ) );

	node->next = NULL;
	node->prev = NULL;
	node->item = item;

	return	node;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�̏��ŁD
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
node_delete
(
	NODE*		node				/* ���ł�����m�[�h             */
)
{
	del_object( node );
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h����菜���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
node_remove
(
	NODE*		node				/* ��菜���m�[�h               */
)
{
	NODE*		prev;
	NODE*		next;

	prev = node->prev;
	next = node->next;

	prev->next = next;
	next->prev = prev;

	node_delete( node );
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���̃m�[�h�ɑ}���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
node_insert_after
(
	NODE*		node,				/* �}���ʒu�̃m�[�h             */
	NODE*		insert				/* �}������m�[�h               */
)
{
	NODE*		next;

	next       = node->next;
	next->prev = insert;
	node->next = insert;

	insert->next = next;
	insert->prev = node;
}

/********** End of File ******************************************************/
