/******************************************************************************
* File Name : GSoctree.c                         Ver : 1.00  Date : 2003-08-18
*
* Description :
*
*		�I�N�c���[�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSoctree.h"
#include	"GSfrustum.h"
#include	"GScollision.h"
#include	"GSvector3.h"
#include	"GSfile_path.h"
#include	"heap.h"
#include	"gfile.h"
#include	<string.h>
#include	<float.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void DrawOctreeNode( GSoctnode*, GSfrustum* );
static void DrawOctreeNodeEx(GSoctnode*, GSfrustum*);
static GSboolean SphereIsBoxInside( const GSvector3*, const GSvector3*, const GSvector3*, GSfloat );
static GSboolean LineIsInsideBox( const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3* );
static GSboolean CollisionOctreeNodeAndSphere( GSoctnode*, GSvector3*, GSfloat );
static GSboolean CollisionOctreeNodeAndLine( GSoctnode*, const GSvector3*, GSvector3*, GSplane* );
static GSboolean CollisionOctreeNodeAndRay( GSoctnode*, const GSvector3*, const GSvector3*, GSvector3*, GSfloat*, GSplane* );
static GSboolean RayIsIntersectBox( const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3* );
static GSboolean IsIntersect( const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, GSfloat, GSfloat );

/*=============================================================================
*
* Purpose : �I�N�c���[�̐����D
*
* Return  : �I�N�c���[��Ԃ��D
*
*============================================================================*/
extern GSoctree*
gsOctreeNew
(
	void
)
{
	GSoctree*		pOctree;

	pOctree = new_object( sizeof( GSoctree ) );

	memset( pOctree, 0, sizeof( GSoctree ) );

	return	pOctree;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDelete
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
)
{
	/* �I�N�c���[���N���[���A�b�v */
	gsOctreeCleanUp( pOctree );

	/* �I�N�c���[�̍폜 */
	del_object( pOctree );
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeCleanUp
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
)
{
	GSuint			i;

	/* �I�N�c���[�̃m�[�h���폜 */
	if ( pOctree->pNodes != NULL )
	{
		/* �I�N�c���[�̃m�[�h�̃f�B�X�v���C���X�g�ƃ��b�V�����폜 */
		for ( i = 0; i < pOctree->numNodes; i++ )
		{
			if ( pOctree->pNodes[i].bLeafNode == GS_TRUE )
			{
				/* �ʃf�[�^�O���[�v���폜 */
				del_object( pOctree->pNodes[i].pMesh->pFaceGroups );

				/* ���b�V���f�[�^���폜 */
				del_object( pOctree->pNodes[i].pMesh );

				/* �f�B�X�v���C���X�g���폜*/
				glDeleteLists( pOctree->pNodes[i].DisplayList, 1 );
			}
		}
		del_object( pOctree->pNodes );

		pOctree->pNodes = NULL;
	}
	pOctree->numNodes = 0;

	/* �I�N�c���[�̃��b�V�����폜 */
	if ( pOctree->pMesh != NULL )
	{
		gsMeshDelete( pOctree->pMesh );

		pOctree->pMesh = NULL;
	}
}

/*=============================================================================
*
* Purpose : �I�N�c���[�t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeLoadFile
(
	GSoctree*		pOctree,			/* �I�N�c���[�f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
)
{
	GFILE			file;
	GSuint			OctreeInfo;
	GSuint			NodeID;
	GSuint			numFaceGroups;
	GSuint			FaceGroupIndex;
	GSmesh*			pMesh;
	GSoctnode*		pNode;
	GSmesh*			pNodeMesh;
	GSfacegroup*	pFaceGroup;
	char			MeshFileName[_MAX_PATH];
	char			FileName[_MAX_FNAME];
	char			Drive[_MAX_DRIVE];
	char			Dir[_MAX_DIR];
	GSuint			i, j;

	/* �I�N�c���[�t�@�C�����I�[�v������ */
	if ( ( file = GFileOpen( pszFileName, "r" ) ) == NULL )
	{
		/* �t�@�C�����I�[�v���ł��Ȃ����� */
		return	GS_FALSE;
	}

	/* �I�N�c���[�t�@�C�����̓ǂݍ��� */
	GFileReadDword( file, &OctreeInfo );

	/* ���b�V���t�@�C�����̓ǂݍ��� */
	GFileReadString( file, FileName );

	/* �t���p�X�̃��b�V���t�@�C�������쐬���� */
	gsSplitPath( GFileGetFileName( file ), Drive, Dir, NULL, NULL );
	strcpy( MeshFileName, Drive );
	strcat( MeshFileName, Dir );
	strcat( MeshFileName, FileName );

	/* ���b�V���f�[�^�̐��� */
	pMesh = gsMeshNew();

	/* ���b�V���f�[�^�̓ǂݍ��� */
	if ( gsMeshLoadFile( pMesh, MeshFileName ) == GS_FALSE )
	{
		/* �I�N�c���[�t�@�C���̃N���[�Y */
		GFileClose( file );

		/* ���b�V�������ł����� */
		gsMeshDelete( pMesh );

		return	GS_FALSE;
	}

	/* �I�N�c���[���N���[���A�b�v */
	gsOctreeCleanUp( pOctree );

	/* �V�������b�V����ݒ肷�� */
	pOctree->pMesh = pMesh;

	/* �m�[�h���̓ǂݍ��� */
	GFileReadDword( file, &pOctree->numNodes );

	/* �m�[�h�̔z��𐶐����� */
	pOctree->pNodes = new_object( sizeof( GSoctnode ) * pOctree->numNodes );

	/* �m�[�h�̔z���ǂݍ��� */
	for ( i = 0; i < pOctree->numNodes; i++ )
	{
		pNode = &pOctree->pNodes[i];

		/* �m�[�h�̃f�[�^��ǂݍ��� */
		GFileReadByte( file, &pNode->bLeafNode );
		GFileReadVector3( file, &pNode->PosMin );
		GFileReadVector3( file, &pNode->PosMax );
		GFileReadDword( file, &numFaceGroups );
		GFileReadDword( file, &FaceGroupIndex );
		for ( j = 0; j < 8; j++ )
		{
			GFileReadDword( file, &NodeID );
			if ( (GSint)NodeID != -1 )
			{
				pNode->pNodes[j] = &pOctree->pNodes[ NodeID ];
			}
			else
			{
				pNode->pNodes[j] = NULL;
			}
		}
		/* �f�B�X�v���C���X�g�̏����� */
		pNode->DisplayList = 0;

		/* ���[�t�m�[�h�̏ꍇ�̓m�[�h�p�̃��b�V���f�[�^���쐬���� */
		pNode->pMesh = NULL;
		if ( pNode->bLeafNode == GS_TRUE )
		{
			/* ���b�V���f�[�^���쐬���� */
			pNodeMesh = gsMeshNew();

			/* ���b�V���f�[�^���R�s�[���� */
			*pNodeMesh = *pMesh;

			/* �ʃf�[�^�O���[�v����ݒ� */
			pNodeMesh->numFaceGroups = numFaceGroups;

			/* �ʃf�[�^�O���[�v�̎擾 */
			pFaceGroup = &pMesh->pFaceGroups[ FaceGroupIndex ];

			/* �ʃf�[�^�O���[�v���쐬 */
			pNodeMesh->pFaceGroups = new_object( sizeof(GSfacegroup) * numFaceGroups );

			pNodeMesh->numIndices = 0;
			for ( j = 0; j < pNodeMesh->numFaceGroups; j++ )
			{
				pNodeMesh->pFaceGroups[j] = pFaceGroup[j];
				pNodeMesh->pFaceGroups[j].StartIndices = pNodeMesh->numIndices;
				pNodeMesh->numIndices += pFaceGroup[j].numIndices;
			}

			/* ���_�C���f�b�N�X��ݒ� */
			pNodeMesh->pIndices = &pMesh->pIndices[ pFaceGroup->StartIndices ];

			/* ���ʃf�[�^�z���ݒ� */
			pNodeMesh->pPlanes = &pMesh->pPlanes[ pFaceGroup->StartIndices / 3 ];

			/* �m�[�h�Ƀ��b�V����ݒ肷�� */
			pNode->pMesh = pNodeMesh;

			/* �f�B�X�v���C���X�g���쐬���� */
			pNode->DisplayList = glGenLists( 1 );
			glNewList( pNode->DisplayList, GL_COMPILE );
				gsMeshDraw( pNode->pMesh );
			glEndList();
		}
	}

	/* �I�N�c���[�t�@�C���̃N���[�Y */
	GFileClose( file );

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeLoadFileEx
(
	GSoctree*		pOctree,			/* �I�N�c���[�f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
)
{
	GFILE			file;
	GSuint			OctreeInfo;
	GSuint			NodeID;
	GSuint			numFaceGroups;
	GSuint			FaceGroupIndex;
	GSmesh*			pMesh;
	GSoctnode*		pNode;
	GSmesh*			pNodeMesh;
	GSfacegroup*	pFaceGroup;
	char			MeshFileName[_MAX_PATH];
	char			FileName[_MAX_FNAME];
	char			Drive[_MAX_DRIVE];
	char			Dir[_MAX_DIR];
	GSuint			i, j;

	/* �I�N�c���[�t�@�C�����I�[�v������ */
	if ((file = GFileOpen(pszFileName, "r")) == NULL)
	{
		/* �t�@�C�����I�[�v���ł��Ȃ����� */
		return	GS_FALSE;
	}

	/* �I�N�c���[�t�@�C�����̓ǂݍ��� */
	GFileReadDword(file, &OctreeInfo);

	/* ���b�V���t�@�C�����̓ǂݍ��� */
	GFileReadString(file, FileName);

	/* �t���p�X�̃��b�V���t�@�C�������쐬���� */
	gsSplitPath(GFileGetFileName(file), Drive, Dir, NULL, NULL);
	strcpy(MeshFileName, Drive);
	strcat(MeshFileName, Dir);
	strcat(MeshFileName, FileName);

	/* ���b�V���f�[�^�̐��� */
	pMesh = gsMeshNew();

	/* ���b�V���f�[�^�̓ǂݍ��� */
	if (gsMeshLoadFileEx(pMesh, MeshFileName) == GS_FALSE)
	{
		/* �I�N�c���[�t�@�C���̃N���[�Y */
		GFileClose(file);

		/* ���b�V�������ł����� */
		gsMeshDelete(pMesh);

		return	GS_FALSE;
	}

	/* �I�N�c���[���N���[���A�b�v */
	gsOctreeCleanUp(pOctree);

	/* �V�������b�V����ݒ肷�� */
	pOctree->pMesh = pMesh;

	/* �m�[�h���̓ǂݍ��� */
	GFileReadDword(file, &pOctree->numNodes);

	/* �m�[�h�̔z��𐶐����� */
	pOctree->pNodes = new_object(sizeof(GSoctnode) * pOctree->numNodes);

	/* �m�[�h�̔z���ǂݍ��� */
	for (i = 0; i < pOctree->numNodes; i++)
	{
		pNode = &pOctree->pNodes[i];

		/* �m�[�h�̃f�[�^��ǂݍ��� */
		GFileReadByte(file, &pNode->bLeafNode);
		GFileReadVector3(file, &pNode->PosMin);
		GFileReadVector3(file, &pNode->PosMax);
		GFileReadDword(file, &numFaceGroups);
		GFileReadDword(file, &FaceGroupIndex);
		for (j = 0; j < 8; j++)
		{
			GFileReadDword(file, &NodeID);
			if ((GSint)NodeID != -1)
			{
				pNode->pNodes[j] = &pOctree->pNodes[NodeID];
			}
			else
			{
				pNode->pNodes[j] = NULL;
			}
		}
		/* �f�B�X�v���C���X�g�̏����� */
		pNode->DisplayList = 0;

		/* ���[�t�m�[�h�̏ꍇ�̓m�[�h�p�̃��b�V���f�[�^���쐬���� */
		pNode->pMesh = NULL;
		if (pNode->bLeafNode == GS_TRUE)
		{
			/* ���b�V���f�[�^���쐬���� */
			pNodeMesh = gsMeshNew();

			/* ���b�V���f�[�^���R�s�[���� */
			*pNodeMesh = *pMesh;

			/* �ʃf�[�^�O���[�v����ݒ� */
			pNodeMesh->numFaceGroups = numFaceGroups;

			/* �ʃf�[�^�O���[�v�̎擾 */
			pFaceGroup = &pMesh->pFaceGroups[FaceGroupIndex];

			/* �ʃf�[�^�O���[�v���쐬 */
			pNodeMesh->pFaceGroups = new_object(sizeof(GSfacegroup) * numFaceGroups);

			pNodeMesh->numIndices = 0;
			for (j = 0; j < pNodeMesh->numFaceGroups; j++)
			{
				pNodeMesh->pFaceGroups[j] = pFaceGroup[j];
				pNodeMesh->pFaceGroups[j].StartIndices = pNodeMesh->numIndices;
				pNodeMesh->numIndices += pFaceGroup[j].numIndices;
			}

			/* ���_�C���f�b�N�X��ݒ� */
			pNodeMesh->pIndices = &pMesh->pIndices[pFaceGroup->StartIndices];

			/* ���ʃf�[�^�z���ݒ� */
			pNodeMesh->pPlanes = &pMesh->pPlanes[pFaceGroup->StartIndices / 3];

			// �C���f�b�N�X�o�b�t�@�̃I�t�Z�b�g
			pNodeMesh->Buffer.IndicesOffset = pFaceGroup->StartIndices;

			/* �m�[�h�Ƀ��b�V����ݒ肷�� */
			pNode->pMesh = pNodeMesh;
		}
	}

	/* �I�N�c���[�t�@�C���̃N���[�Y */
	GFileClose(file);

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDraw
(
	GSoctree*		pOctree				/* �I�N�c���[�f�[�^		*/
)
{
	GSfrustum		Frustum;
	GSmatrix4		matProj;
	GSmatrix4		matView;
	GScolor			CurrentColor;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_LIGHTING_BIT | GL_TEXTURE_BIT);

	/* ���݂̃J���[���擾���� */
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&CurrentColor);

	/* �����ϊ��s����擾 */
	glGetFloatv( GL_PROJECTION_MATRIX, (GLfloat*)&matProj );

	/* ���f���r���[�ϊ��}�g���N�X���擾���� */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&matView );

	/* ��������쐬���� */
	gsFrustumFromMatrices( &Frustum, &matView, &matProj );

	/* �m�[�h��`�悷�� */
	DrawOctreeNode( &pOctree->pNodes[0], &Frustum );

	/* �J�����g�J���[�𕜋A���� */
	glColor4fv((GLfloat*)&CurrentColor);

	/* �e�탌���_�����O���[�h�̕��A */
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsOctreeDrawEx
(
	GSoctree*			pOctree,			/* �I�N�c���[�f�[�^		*/
	const GSmatrix4*	pProjectionMatrix,	/* �����ϊ��s��			*/
	const GSmatrix4*	pViewMatix			/* ����ϊ��s��			*/
)
{
	GSfrustum		Frustum;
	GScolor			CurrentColor;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_LIGHTING_BIT | GL_TEXTURE_BIT);

	/* ���݂̃J���[���擾���� */
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&CurrentColor);

	/* ��������쐬���� */
	gsFrustumFromMatrices(&Frustum, pViewMatix, pProjectionMatrix);

	/* �m�[�h��`�悷�� */
	DrawOctreeNodeEx(&pOctree->pNodes[0], &Frustum);

	/* �J�����g�J���[�𕜋A���� */
	glColor4fv((GLfloat*)&CurrentColor);

	/* �e�탌���_�����O���[�h�̕��A */
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �I�N�c���[�Ɛ����̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionLine
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^				*/
	const GSvector3*	pLine0,			/* �����̎n�_					*/
	const GSvector3*	pLine1,			/* �����̏I�_					*/
	GSvector3*			pIntersect,		/*-> ���b�V���Ɛ����̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
)
{
	GSvector3			Line1;
	GSplane				Plane;

	Line1 = *pLine1;

	/* �m�[�h�Ɛ����̏Փ˔�����s�� */
	if ( CollisionOctreeNodeAndLine( &pOctree->pNodes[0], pLine0, &Line1, &Plane ) == GS_TRUE )
	{
		/* ��_��ݒ肷�� */
		if ( pIntersect != NULL )
		{
			*pIntersect = Line1;
		}

		/* ���ʃp�����[�^��ݒ肷�� */
		if ( pPlane != NULL )
		{
			*pPlane = Plane;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�ƃ��C�̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionRay
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^				*/
	const GSvector3*	pRayPos,		/* ���C�̎n�_					*/
	const GSvector3*	pRayDir,		/* ���C�̕���					*/
	GSvector3*			pIntersect,		/*-> ���b�V���ƃ��C�̌�_		*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
)
{
	GSvector3			Intersect;
	GSplane				Plane;
	GSfloat				DistanceSq;

	/* ��ԋ߂���_�Ƃ̋����������� */
	DistanceSq = FLT_MAX;

	/* �m�[�h�Ɛ����̏Փ˔�����s�� */
	if ( CollisionOctreeNodeAndRay( &pOctree->pNodes[0],
									pRayPos, pRayDir,
									&Intersect, &DistanceSq, &Plane ) == GS_TRUE )
	{
		/* ��_��ݒ肷�� */
		if ( pIntersect != NULL )
		{
			*pIntersect = Intersect;
		}

		/* ���ʃp�����[�^��ݒ肷�� */
		if ( pPlane != NULL )
		{
			*pPlane = Plane;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�Ƌ��̂̏Փ˔���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsOctreeCollisionSphere
(
	GSoctree*			pOctree,		/* �I�N�c���[�f�[�^			*/
	const GSvector3*	pCenter,		/* ���̂̒��S				*/
	GSfloat				Radius,			/* ���̂̔��a				*/
	GSvector3*			pOutCenter		/*-> �␳��̋��̒��S���W	*/
)
{
	GSvector3			Center;

	Center = *pCenter;

	if ( CollisionOctreeNodeAndSphere( &pOctree->pNodes[0], &Center, Radius ) == GS_TRUE )
	{
		/* �␳��̋��̂̒��S���W��ݒ肷�� */
		if ( pOutCenter != NULL )
		{
			*pOutCenter = Center;
		}

		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�̃��b�V����`��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawOctreeNode
(
	GSoctnode*		pNode,				/* �I�N�c���[�m�[�h		*/
	GSfrustum*		pFrustum			/* ������p�����[�^		*/
)
{
	GSint				i;

	/* �m�[�h��������̒��ɓ����Ă��邩�H */
	if ( gsFrustumIsBoxInside( pFrustum, &pNode->PosMin, &pNode->PosMax ) == GS_FALSE )
	{
		/* ������̒��ɓ����Ă��Ȃ���Ε`�悵�Ȃ� */
		return;
	}

	/* ���[�t�m�[�h���H */
	if ( pNode->bLeafNode == GS_TRUE )
	{
		/* ���[�t�m�[�h�̏ꍇ�̓��b�V����`�悷�� */
		glCallList( pNode->DisplayList );
	
		return;
	}

	/* �q�m�[�h��S�ĕ`�悷�� */
	for ( i = 0; i < 8; i++ )
	{
		if ( pNode->pNodes[i] != NULL )
		{
			DrawOctreeNode( pNode->pNodes[i], pFrustum );
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�̃��b�V����`��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawOctreeNodeEx
(
	GSoctnode*		pNode,				/* �I�N�c���[�m�[�h		*/
	GSfrustum*		pFrustum			/* ������p�����[�^		*/
)
{
	GSint				i;

	/* �m�[�h��������̒��ɓ����Ă��邩�H */
	if (gsFrustumIsBoxInside(pFrustum, &pNode->PosMin, &pNode->PosMax) == GS_FALSE)
	{
		/* ������̒��ɓ����Ă��Ȃ���Ε`�悵�Ȃ� */
		return;
	}

	/* ���[�t�m�[�h���H */
	if (pNode->bLeafNode == GS_TRUE)
	{
		/* ���[�t�m�[�h�̏ꍇ�̓��b�V����`�悷�� */
		gsMeshDrawEx(pNode->pMesh);
		return;
	}

	/* �q�m�[�h��S�ĕ`�悷�� */
	for (i = 0; i < 8; i++)
	{
		if (pNode->pNodes[i] != NULL)
		{
			DrawOctreeNodeEx(pNode->pNodes[i], pFrustum);
		}
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�Ɛ����̏Փ˔���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
CollisionOctreeNodeAndLine
(
	GSoctnode*			pNode,			/* �I�N�c���[�m�[�h				*/
	const GSvector3*	pLine0,			/* �����̎n�_					*/
	GSvector3*			pLine1,			/* �����̏I�_					*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
)
{
	GSboolean			bCollision;
	int					i;

	/* �m�[�h�̒��ɐ��������݂��邩�`�F�b�N���� */
	if ( LineIsInsideBox( &pNode->PosMin, &pNode->PosMax, pLine0, pLine1 ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ���[�t�m�[�h�̏ꍇ�̓��b�V���Ƃ̏Փ˔�����s�� */
	if ( pNode->bLeafNode == GS_TRUE )
	{
		return	gsCollisionMeshAndLine( pNode->pMesh, pLine0, pLine1, pLine1, pPlane );
	}

	/* �S�Ă̎q�m�[�h�Ƃ̏Փ˔�����s�� */
	bCollision = GS_FALSE;
	for ( i = 0; i < 8; i++ )
	{
		if ( pNode->pNodes[i] != NULL )
		{
			if ( CollisionOctreeNodeAndLine( pNode->pNodes[i], pLine0, pLine1, pPlane ) == GS_TRUE )
			{
				/* �Փ˃t���O�̐ݒ� */
				bCollision = GS_TRUE;
			}
		}
	}

	return	bCollision;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�ƃ��C�̏Փ˔���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
CollisionOctreeNodeAndRay
(
	GSoctnode*			pNode,			/* �I�N�c���[�m�[�h				*/
	const GSvector3*	pRayPos,		/* ���C�̈ʒu					*/
	const GSvector3*	pRayDir,		/* ���C�̕���					*/
	GSvector3*			pIntersect,		/*-> ��_�̍��W					*/
	GSfloat*			pDistanceSq,	/*-> ��_�Ƃ̋���				*/
	GSplane*			pPlane			/*-> �Փ˂����ʂ̕��ʃp�����[�^	*/
)
{
	GSvector3			Intersect;
	GSplane				Plane;
	GSboolean			bCollision;
	GSfloat				DistanceSq;
	int					i;

	/* �m�[�h�̒��ɐ��������݂��邩�`�F�b�N���� */
	if ( RayIsIntersectBox( &pNode->PosMin, &pNode->PosMax, pRayPos, pRayDir ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ���[�t�m�[�h�̏ꍇ�̓��b�V���Ƃ̏Փ˔�����s�� */
	if ( pNode->bLeafNode == GS_TRUE )
	{
		if ( gsCollisionMeshAndRay( pNode->pMesh, pRayPos, pRayDir, &Intersect, &Plane ) == GS_TRUE )
		{
			/* �����̎n�_�ƌ�_�̋��������߂� */
			DistanceSq = gsVector3DistanceSq( pRayPos, &Intersect );

			/* �����̎n�_�ɍł��߂���_��V������_�Ƃ��� */
			if ( DistanceSq < *pDistanceSq )
			{
				*pDistanceSq = DistanceSq;
				*pIntersect  = Intersect;
				*pPlane      = Plane;
			}

			return	GS_TRUE;
		}

		return	GS_FALSE;
	}

	/* �S�Ă̎q�m�[�h�Ƃ̏Փ˔�����s�� */
	bCollision = GS_FALSE;
	for ( i = 0; i < 8; i++ )
	{
		if ( pNode->pNodes[i] != NULL )
		{
			if ( CollisionOctreeNodeAndRay( pNode->pNodes[i],
											pRayPos, pRayDir,
											pIntersect, pDistanceSq, pPlane ) == GS_TRUE )
			{
				/* �Փ˃t���O�̐ݒ� */
				bCollision = GS_TRUE;
			}
		}
	}

	return	bCollision;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �m�[�h�Ƌ��̂̏Փ˔���D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
CollisionOctreeNodeAndSphere
(
	GSoctnode*			pNode,			/* �I�N�c���[�m�[�h			*/
	GSvector3*			pCenter,		/* ���̂̒��S				*/
	GSfloat				Radius			/* ���̂̔��a				*/
)
{
	GSboolean			bCollision;
	int					i;

	/* �m�[�h�̒��ɋ��̂����݂��邩�`�F�b�N���� */
	if ( SphereIsBoxInside( &pNode->PosMin, &pNode->PosMax, pCenter, Radius ) == GS_FALSE )
	{
		return	GS_FALSE;
	}

	/* ���[�t�m�[�h�̏ꍇ�̓��b�V���Ƃ̏Փ˔�����s�� */
	if ( pNode->bLeafNode == GS_TRUE )
	{
		return	gsCollisionMeshAndSphere( pNode->pMesh, pCenter, Radius, pCenter );
	}

	/* �S�Ă̎q�m�[�h�Ƃ̏Փ˔�����s�� */
	bCollision = GS_FALSE;
	for ( i = 0; i < 8; i++ )
	{
		if ( pNode->pNodes[i] != NULL )
		{
			if ( CollisionOctreeNodeAndSphere( pNode->pNodes[i], pCenter, Radius ) == GS_TRUE )
			{
				bCollision = GS_TRUE;
			}
		}
	}

	return	bCollision;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �������{�b�N�X���ɑ��݂��邩�`�F�b�N����D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
LineIsInsideBox
(
	const GSvector3*	pMin,			/* �{�b�N�X�̍ŏ����W	*/
	const GSvector3*	pMax,			/* �{�b�N�X�̍ő���W	*/
	const GSvector3*	pLine0,			/* �����̎n�_			*/
	const GSvector3*	pLine1			/* �����̏I�_			*/
)
{
	GSvector3			Dir;

	/* ���S�Ƀ{�b�N�X�����O�ɂ��邩�H */
	if ( ( pLine0->x < pMin->x && pLine1->x < pMin->x )
	  || ( pLine0->y < pMin->y && pLine1->y < pMin->y )
	  || ( pLine0->z < pMin->z && pLine1->z < pMin->z )
	  || ( pLine0->x > pMax->x && pLine1->x > pMax->x )
	  || ( pLine0->y > pMax->y && pLine1->y > pMax->y )
	  || ( pLine0->z > pMax->z && pLine1->z > pMax->z ) )
	{
		return	GS_FALSE;
	}

	/* �n�_���{�b�N�X���ɑ��݂��邩�H */
	if ( ( pLine0->x >= pMin->x && pLine0->x <= pMax->x )
	  && ( pLine0->y >= pMin->y && pLine0->y <= pMax->y )
	  && ( pLine0->z >= pMin->z && pLine0->z <= pMax->z ) )
	{
		return	GS_TRUE;
	}

	/* �I�_���{�b�N�X���ɑ��݂��邩�H */
	if ( ( pLine1->x >= pMin->x && pLine1->x <= pMax->x )
	  && ( pLine1->y >= pMin->y && pLine1->y <= pMax->y )
	  && ( pLine1->z >= pMin->z && pLine1->z <= pMax->z ) )
	{
		return	GS_TRUE;
	}

	/* �������{�b�N�X�ƌ������邩�H */
	gsVector3Subtract( &Dir, pLine1, pLine0 ); 
	gsVector3Normalize( &Dir, &Dir );

	return	RayIsIntersectBox( pMin,  pMax, pLine0, &Dir );
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���̂��{�b�N�X���ɑ��݂��邩�`�F�b�N����D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
SphereIsBoxInside
(
	const GSvector3*	pMin,			/* �{�b�N�X�̍ŏ����W		*/
	const GSvector3*	pMax,			/* �{�b�N�X�̍ő���W		*/
	const GSvector3*	pCenter,		/* ���̂̒��S���W			*/
	GSfloat				Radius			/* ���̂̔��a				*/
)
{
	GSfloat				DistanceSq;

	DistanceSq = 0.0f;

	if( pCenter->x > pMax->x )
	{
		DistanceSq += SQR( pCenter->x - pMax->x );
	}
	else if( pCenter->x < pMin->x )
	{
		DistanceSq += SQR( pMin->x - pCenter->x );
	}

	if( pCenter->y > pMax->y )
	{
		DistanceSq += SQR( pCenter->y - pMax->y );
	}
	else if( pCenter->y < pMin->y )
	{
		DistanceSq += SQR( pMin->y - pCenter->y );
	}

	if( pCenter->z > pMax->z )
	{
		DistanceSq += SQR( pCenter->z - pMax->z );
	}
	else if( pCenter->z < pMin->z )
	{
		DistanceSq += SQR( pMin->z - pCenter->z );
	}

	if ( DistanceSq <= SQR( Radius ) )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���C�ƃ{�b�N�X���������邩�`�F�b�N����D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
RayIsIntersectBox
(
	const GSvector3*	pMin,			/* �{�b�N�X�̍ŏ����W		*/
	const GSvector3*	pMax,			/* �{�b�N�X�̍ő���W		*/
	const GSvector3*	pPos,			/* ���C�̈ʒu				*/
	const GSvector3*	pDir			/* ���C�̕���				*/
)
{
	/* �{�b�N�X�̉��ꂩ�̖ʂ����C���������邩���ׂ� */
	if ( IsIntersect( pMin, pMax, pPos, pDir, -pPos->y + pMax->y,  pDir->y ) == GS_TRUE
	  || IsIntersect( pMin, pMax, pPos, pDir,  pPos->y - pMin->y, -pDir->y ) == GS_TRUE
	  || IsIntersect( pMin, pMax, pPos, pDir, -pPos->x + pMax->x,  pDir->x ) == GS_TRUE
	  || IsIntersect( pMin, pMax, pPos, pDir,  pPos->x - pMin->x, -pDir->x ) == GS_TRUE
	  || IsIntersect( pMin, pMax, pPos, pDir, -pPos->z + pMax->z,  pDir->z ) == GS_TRUE
	  || IsIntersect( pMin, pMax, pPos, pDir,  pPos->z - pMin->z, -pDir->z ) == GS_TRUE )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���C�ƃ{�b�N�X�̉��ꂩ�̖ʂ��������邩�`�F�b�N����D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GSboolean
IsIntersect
(
	const GSvector3*	pMin,			/* �{�b�N�X�̍ŏ����W		*/
	const GSvector3*	pMax,			/* �{�b�N�X�̍ő���W		*/
	const GSvector3*	pPos,			/* ���C�̈ʒu				*/
	const GSvector3*	pDir,			/* ���C�̕���				*/
	GSfloat				Numerator,		/* ���q						*/
	GSfloat				Denominator		/* ����						*/
)
{
#define	MACH_FACTOR		0.0001f
	GSvector3			V;

	/* �����Ɩʂ����s���H */
	if ( Denominator == 0.0f )
	{
		return	GS_FALSE;
	}

	/* ��_�����߂� */
	gsVector3LinearEquation( &V, pPos, pDir, Numerator / Denominator );

	/* ��_���{�b�N�X���ɑ��݂��邩�H */
	if ( ( V.x >= ( pMin->x - MACH_FACTOR ) && V.x <= ( pMax->x + MACH_FACTOR ) )
	  && ( V.y >= ( pMin->y - MACH_FACTOR ) && V.y <= ( pMax->y + MACH_FACTOR ) )
 	  && ( V.z >= ( pMin->z - MACH_FACTOR ) && V.z <= ( pMax->z + MACH_FACTOR ) ) )
	{
		return	GS_TRUE;
	}

	return	GS_FALSE;
}

/********** End of File ******************************************************/
