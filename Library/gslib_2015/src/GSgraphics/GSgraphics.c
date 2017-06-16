/******************************************************************************
* File Name : GSgraphics.c                       Ver : 1.00  Date : 2002-07-31
*
* Description :
*
*       �Q�[���V�X�e���p �O���t�B�b�N�X�����D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSgraphics.h"
#include	"GSvector3.h"
#include	"GSmatrix4.h"
#include	"GSquaternion.h"
#include	"GScolor.h"
#include    "GSload_texture_file.h"
#include	"GSshader.h"
#include	"GSrender_target.h"
#include    "GSuniform_block.h"
#include	<stddef.h>
#include	<GL/glu.h>

/****** �萔�錾 *************************************************************/

#define	GS_MESH_MAX			 1024	/* ���b�V���f�[�^�̍ő吔		*/
#define	GS_SKELETON_MAX		 1024	/* �X�P���g���f�[�^�̍ő吔		*/
#define	GS_ANIMATION_MAX	 1024	/* �A�j���[�V�����f�[�^�̍ő吔	*/
#define	GS_TEXTURE_MAX		 1024	/* �e�N�X�`���f�[�^�̍ő吔		*/
#define	GS_OCTREE_MAX		 1024	/* �I�N�c���[�f�[�^�̍ő吔		*/
#define	GS_SHADER_MAX		 1024	/* �V�F�[�_�[�f�[�^�̍ő吔		*/
#define	GS_RENDER_TARGET_MAX 1024	/* �����_�[�^�[�Q�b�g�̍ő吔   */
#define	GS_UNIFORM_BLOCK_MAX 1024	/* UniformBlock�̍ő吔         */

#define	GS_MATRIX_MAX		256		/* �ϊ��s��̍ő吔				*/

/****** �֐��v���g�^�C�v�錾 *************************************************/

void initialize_opengl_ext(void);	/* OpenGL�g���̏����� */

/****** �ϐ��錾 *************************************************************/

/* ���b�V���C�X�P���g���C�A�j���[�V����,�e�N�X�`���f�[�^ */
static GSmesh*		    s_pMeshs[ GS_MESH_MAX ];
static GSskeleton*	    s_pSkeletons[ GS_SKELETON_MAX ];
static GSanimation*	    s_pAnimations[ GS_ANIMATION_MAX ];
static GStexture*	    s_pTextures[ GS_TEXTURE_MAX ];
static GSoctree*	    s_pOctrees[ GS_OCTREE_MAX ];
static GSshaderProgram*	s_pShaders[ GS_SHADER_MAX ];
static GSrendertarget*  s_pRenderTargets[ GS_RENDER_TARGET_MAX ];
static GSunifomBlock*   s_pUniformBlocks[ GS_UNIFORM_BLOCK_MAX ];

/* �Z���V�F�[�f�B���O�p�p�����[�^ */
static GSvector3	s_CelShadeLightPosition = { 1.0f, 1.0f, 1.0f };
static GSfloat		s_CelShadeLineWidth     = 1.5f;
static GSuint		s_CelShadeTexture       = 0;
static GScolor		s_CelShadeLineColor		= { 0.0f, 0.0f, 0.0f, 1.0f };

/* �e�N�X�`���̃J���[�L�[�̃��[�h */
static GSenum		s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
static GSbyte		s_TexColorKeyR = 0;
static GSbyte		s_TexColorKeyG = 0;
static GSbyte		s_TexColorKeyB = 0;

/* �o�C���h���̃X�P���g���i���o */
static GSuint		s_BindSkeleton = 0;

/* �A�j���[�V�����ϊ��s�� */
static GSmatrix4	s_AnimationMatrices[ GS_MATRIX_MAX ];

/* �p���ϊ��s�� */
static GSmatrix4	s_SkeletonMatrices[ GS_MATRIX_MAX ];

/* ���W�ϊ��s�� */
static GSmatrix4	s_TransformMatrices[ GS_MATRIX_MAX ];

/* �e���ԃt���O */
static GSboolean	s_bSkinMesh          = GS_TRUE;
static GSboolean	s_bCalculateSkeleton = GS_TRUE;
static GSboolean	s_bCelShade          = GS_FALSE;

/* �����t�H���g��� */
static GSbitfield	s_FontCode     = GS_FONT_NORMAL;
static GSuint		s_FontPoint    = 10;
static char			s_FontName[32] = "�l�r �S�V�b�N";

/* �e�L�X�g�̕\���ʒu */
static GSvector2	s_TextPosition = { 0.0f, 0.0f };

/* ���s���̃V�F�[�_�[�ԍ� */
static GSuint		s_ExecuteShader = 0;

/* �ޔ𒆂̃r���[�|�[�g�T�C�Y */
static int s_ViewPort[4];

/*=============================================================================
*
* Purpose : �O���t�B�b�N�V�X�e���̏������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsInitGraphics
(
	void
)
{
	GSuint		i;

	/* OpenGL�g���̏�����*/
	initialize_opengl_ext();

	/* �e�탊�\�[�X�̏����� */
	for ( i = 0; i < GS_MESH_MAX; i++ )
	{
		gsDeleteMesh( i );
	}
	for ( i = 0; i < GS_SKELETON_MAX; i++ )
	{
		gsDeleteSkeleton( i );
	}
	for ( i = 0; i < GS_ANIMATION_MAX; i++ )
	{
		gsDeleteAnimation( i );
	}
	for ( i = 0; i < GS_TEXTURE_MAX; i++ )
	{
		gsDeleteTexture( i );
	}
	for ( i = 0; i < GS_OCTREE_MAX; i++ )
	{
		gsDeleteOctree( i );
	}
	for (i = 0; i < GS_SHADER_MAX; i++)
	{
		gsDeleteShader(i);
	}
	for (i = 0; i < GS_RENDER_TARGET_MAX; i++)
	{
		gsDeleteRenderTarget(i);
	}

	/* �Z���V�F�[�h�p�����[�^�̏����� */
	gsVector3Init( &s_CelShadeLightPosition, 1.0f, 1.0f, 1.0f );
	s_CelShadeLineWidth = 1.5f;
	s_CelShadeTexture   = 0;
	gsColorInit( &s_CelShadeLineColor, 0.0f, 0.0f, 0.0f, 1.0f );

	/* �e�N�X�`���̃J���[�L�[�̏����� */
	s_TexColorKeyMode = GS_TEXCOLOR_KEY_DISABLE;
	s_TexColorKeyR    = 0;
	s_TexColorKeyG    = 0;
	s_TexColorKeyB    = 0;

	/* �o�C���h���̃X�P���g���̏����� */
	s_BindSkeleton = 0;

	/* �A�j���[�V�����ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_AnimationMatrices[i] );
	}

	/* �p���ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_SkeletonMatrices[i] );
	}

	/* ���W�ϊ��s��̏����� */
	for ( i = 0; i < GS_MATRIX_MAX; i++ )
	{
		gsMatrix4Identity( &s_TransformMatrices[i] );
	}

	/* �����t�H���g���̏����� */
	s_FontCode  = GS_FONT_NORMAL;
	s_FontPoint = 10;
	strcpy( s_FontName, "�l�r �S�V�b�N" );

	/* �e�L�X�g�̕\���ʒu�������� */
	s_TextPosition.x = 0.0f;
	s_TextPosition.y = 0.0f;

	/* �e���ԃt���O�̏����� */
	s_bSkinMesh          = GS_TRUE;
	s_bCalculateSkeleton = GS_TRUE;
	s_bCelShade          = GS_FALSE;
}

/*=============================================================================
*
* Purpose : �O���t�B�b�N�V�X�e���̏I�������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFinishGraphics
(
	void
)
{
	GSuint		i;

	/* �e�탊�\�[�X�̉�����s�� */
	for ( i = 0; i < GS_MESH_MAX; i++ )
	{
		gsDeleteMesh( i );
	}
	for ( i = 0; i < GS_SKELETON_MAX; i++ )
	{
		gsDeleteSkeleton( i );
	}
	for ( i = 0; i < GS_ANIMATION_MAX; i++ )
	{
		gsDeleteAnimation( i );
	}
	for ( i = 0; i < GS_TEXTURE_MAX; i++ )
	{
		gsDeleteTexture( i );
	}
	for ( i = 0; i < GS_OCTREE_MAX; i++ )
	{
		gsDeleteOctree( i );
	}
	for (i = 0; i < GS_SHADER_MAX; i++)
	{
		gsDeleteShader(i);
	}
	for (i = 0; i < GS_RENDER_TARGET_MAX; i++)
	{
		gsDeleteRenderTarget(i);
	}
	for (i = 0; i < GS_UNIFORM_BLOCK_MAX; i++)
	{
		gsDeleteUniformBlock(i);
	}
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadMesh
(
	GSuint			MeshID,				/* ���b�V���h�c				*/
	const char*		pszMshFileName		/* ���b�V���t�@�C����		*/
)
{
	GSboolean		Result;

	/* ���b�V���f�[�^�����ɑ��݂��邩�H */
	if ( s_pMeshs[ MeshID ] == NULL )
	{
		/* ���b�V���f�[�^�̐��� */
		s_pMeshs[ MeshID ] = gsMeshNew();
	}

	/* ���b�V���f�[�^�̓ǂݍ��� */
	Result = gsMeshLoadFile( s_pMeshs[ MeshID ], pszMshFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐����������b�V���f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteMesh( MeshID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̓ǂݍ��݁D�i�V�F�[�_�[��p�j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadMeshEx
(
	GSuint			MeshID,				/* ���b�V���h�c				*/
	const char*		pszMshFileName		/* ���b�V���t�@�C����		*/
)
{
	GSboolean		Result;

	/* ���b�V���f�[�^�����ɑ��݂��邩�H */
	if (s_pMeshs[MeshID] == NULL)
	{
		/* ���b�V���f�[�^�̐��� */
		s_pMeshs[MeshID] = gsMeshNew();
	}

	/* ���b�V���f�[�^�̓ǂݍ��� */
	Result = gsMeshLoadFileEx(s_pMeshs[MeshID], pszMshFileName);

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐����������b�V���f�[�^���폜���� */
	if (Result == GS_FALSE)
	{
		gsDeleteMesh(MeshID);
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadSkeleton
(
	GSuint			SkeletonID,			/* �X�P���g���h�c			*/
	const char*		pszSklFileName		/* �X�P���g���t�@�C����		*/
)
{
	GSboolean		Result;

	/* �X�P���g���f�[�^�����ɑ��݂��邩�H */
	if ( s_pSkeletons[ SkeletonID ] == NULL )
	{
		/* �X�P���g���f�[�^�̐��� */
		s_pSkeletons[ SkeletonID ] = gsSkeletonNew();
	}

	/* �X�P���g���f�[�^�̓ǂݍ��� */
	Result = gsSkeletonLoadFile( s_pSkeletons[ SkeletonID ], pszSklFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������X�P���g���f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteSkeleton( SkeletonID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadAnimation
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c		*/
	const char*		pszAnmFileName		/* �A�j���[�V�����t�@�C����	*/
)
{
	GSboolean		Result;

	/* �A�j���[�V�����f�[�^�����ɑ��݂��邩�H */
	if ( s_pAnimations[ AnimationID ] == NULL )
	{
		/* �A�j���[�V�����f�[�^�̐��� */
		s_pAnimations[ AnimationID ] = gsAnimationNew();
	}

	/* �A�j���[�V�����f�[�^�̓ǂݍ��� */
	Result = gsAnimationLoadFile( s_pAnimations[ AnimationID ], pszAnmFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������A�j���[�V�����f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteAnimation( AnimationID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadTexture
(
	GSuint			TextureID,			/* �e�N�X�`���h�c			*/
	const char*		pszTexFileName		/* �e�N�X�`���t�@�C����		*/
)
{
	GStexture*		pTexture;

	/* �e�N�X�`���f�[�^�̓ǂݍ��� */
	pTexture = gsLoadTextureFile(pszTexFileName);
	if (pTexture == NULL) {
		return GS_FALSE;
	}

	/* ���Ƀe�N�X�`�����������ꍇ�͍폜  */
	if (s_pTextures[TextureID] != NULL)
	{
		gsDeleteTexture(TextureID);
	}
	/* �e�N�X�`���f�[�^�̍X�V */
	s_pTextures[TextureID] = pTexture;

	return GS_TRUE;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadTextureEx
(
	GSuint			TextureID,			/* �e�N�X�`���h�c			*/
	const char*		pszTexFileName,		/* �e�N�X�`���t�@�C����		*/
	GSenum			Wrap,				/* ���b�v���[�h				*/
	GSenum			Filter,				/* �t�B���^					*/
	GSboolean		GenMipmap			/* �~�b�v�}�b�v��������		*/
) 
{
	GStexture*		pTexture;

	/* �e�N�X�`���t�@�C���̓ǂݍ��� */
	if (gsLoadTexture(TextureID, pszTexFileName) == GS_FALSE) {
		return GS_FALSE;
	}
	pTexture = s_pTextures[TextureID];

	glPushAttrib(GL_ENABLE_BIT);
	/* �~�b�v�}�b�v�̎������� */
	if (GenMipmap == GS_TRUE) {
		gsTextureGenerateMipmap(pTexture);
	}
	gsBindTexture(TextureID);
	/* ���b�v���[�h�̐ݒ� */
	if (Wrap == GS_TEX_CLAMP) {
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(pTexture->Type, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	}
	/* �e�N�X�`���t�B���^�̐ݒ� */
	if (Filter == GS_TEX_NEAREST) {
		if (pTexture->Mipmap <= 1) {
			glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		} else {
			glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		}
	} else if (Filter == GS_TEX_LINEAR) {
		if (pTexture->Mipmap == 1) {
			glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		} else {
			glTexParameteri(pTexture->Type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(pTexture->Type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		}
	}
	glBindTexture(pTexture->Type, 0);
	glPopAttrib();
	return GS_TRUE;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadOctree
(
	GSuint			OctreeID,			/* �I�N�c���[�h�c			*/
	const char*		pszOctFileName		/* �I�N�c���[�t�@�C����		*/
)
{
	GSboolean		Result;

	/* �I�N�c���[�f�[�^�����ɑ��݂��邩�H */
	if ( s_pOctrees[ OctreeID ] == NULL )
	{
		/* �I�N�c���[�f�[�^�̐��� */
		s_pOctrees[ OctreeID ] = gsOctreeNew();
	}

	/* �I�N�c���[�f�[�^�̓ǂݍ��� */
	Result = gsOctreeLoadFile( s_pOctrees[ OctreeID ], pszOctFileName );

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������I�N�c���[�f�[�^���폜���� */
	if ( Result == GS_FALSE )
	{
		gsDeleteOctree( OctreeID );
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̓ǂݍ��݁D(�V�F�[�_�[�Ή��j
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadOctreeEx
(
	GSuint			OctreeID,			/* �I�N�c���[�h�c			*/
	const char*		pszOctFileName		/* �I�N�c���[�t�@�C����		*/
)
{
	GSboolean		Result;

	/* �I�N�c���[�f�[�^�����ɑ��݂��邩�H */
	if (s_pOctrees[OctreeID] == NULL)
	{
		/* �I�N�c���[�f�[�^�̐��� */
		s_pOctrees[OctreeID] = gsOctreeNew();
	}

	/* �I�N�c���[�f�[�^�̓ǂݍ��� */
	Result = gsOctreeLoadFileEx(s_pOctrees[OctreeID], pszOctFileName);

	/* �ǂݍ��݂Ɏ��s�����ꍇ�͐��������I�N�c���[�f�[�^���폜���� */
	if (Result == GS_FALSE)
	{
		gsDeleteOctree(OctreeID);
	}

	return	Result;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓����F�̎w��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureColorKey
(
	GSubyte			ColorKeyR,			/* �Ԑ���					*/
	GSubyte			ColorKeyG,			/* ����					*/
	GSubyte			ColorKeyB			/* �ΐ���					*/
)
{
	/* �����F�̐ݒ������ */
	s_TexColorKeyR = ColorKeyR;
	s_TexColorKeyG = ColorKeyG;
	s_TexColorKeyB = ColorKeyB;
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̓����F���[�h�̎w��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextureColorKeyMode
(
	GSenum			ColorKeyMode		/* �J���[�L�[���[�h			*/
)
{
	/* �����F�̑I����@�̐ݒ� */
	s_TexColorKeyMode = ColorKeyMode;
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	if ( s_pMeshs[ MeshID ] != NULL )
	{
		/* ���b�V���f�[�^�����ł����� */
		gsMeshDelete( s_pMeshs[ MeshID ] );

		s_pMeshs[ MeshID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	if ( s_pSkeletons[ SkeletonID ] != NULL )
	{
		/* �X�P���g���f�[�^�����ł����� */
		gsSkeletonDelete( s_pSkeletons[ SkeletonID ] );

		s_pSkeletons[ SkeletonID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����f�[�^�t�@�C���̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteAnimation
(
	GSuint			AnimationID			/* �A�j���[�V�����h�c		*/
)
{
	if ( s_pAnimations[ AnimationID ] != NULL )
	{
		/* �A�j���[�V�����f�[�^�����ł����� */
		gsAnimationDelete( s_pAnimations[ AnimationID ] );

		s_pAnimations[ AnimationID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�t�@�C���̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c		*/
)
{
	if ( s_pTextures[ TextureID ] != NULL )
	{
		/* �A�j���[�V�����f�[�^�����ł����� */
		gsTextureDelete( s_pTextures[ TextureID ] );

		s_pTextures[ TextureID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteOctree
(
	GSuint			OctreeID				/* �I�N�c���[�h�c		*/
)
{
	if ( s_pOctrees[ OctreeID ] != NULL )
	{
		/* �I�N�c���[�f�[�^�����ł����� */
		gsOctreeDelete( s_pOctrees[ OctreeID ] );

		s_pOctrees[ OctreeID ] = NULL;
	}
}

/*=============================================================================
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	GSskeleton*		pSkeleton;
	GSmesh*			pMesh;

	/* ���b�V���f�[�^���擾���� */
	if ( ( pMesh = s_pMeshs[ MeshID ] ) == NULL )
	{
		return;
	}

	/* �o�C���h���̃X�P���g���̎擾 */
	pSkeleton = s_pSkeletons[ s_BindSkeleton ];

	/* �X�L�j���O���b�V����`�悷�邩�H */
	if ( s_bSkinMesh == GS_TRUE && pSkeleton != NULL )
	{
		/* �X�P���g���̎����v�Z���ݒ肳��Ă��邩�H */
		if ( s_bCalculateSkeleton == GS_TRUE)
		{
			/* �p���ϊ��s��̌v�Z���s�� */
			gsCalculateSkeleton( NULL, s_AnimationMatrices, s_SkeletonMatrices );
		}

		/* �ŏI�I�ȍ��W�ϊ��s����v�Z���� */
		gsSkeletonCalculateTransform
		(
			pSkeleton,
			s_TransformMatrices,
			s_SkeletonMatrices
		);

		/* �Z���V�F�[�f�B���O���s�����H */
		if ( s_bCelShade == GS_TRUE )
		{
			/* �Z���V�F�[�f�B���O���g���ĕ`�悷�� */
			gsMeshDrawSkinCelShade
			(
				pMesh,
				s_TransformMatrices,
				s_pTextures[ s_CelShadeTexture ],
				&s_CelShadeLightPosition,
				&s_CelShadeLineColor,
				s_CelShadeLineWidth
			);
		}
		else
		{
			/* ���b�V����`�悷�� */
			gsMeshDrawSkin( pMesh, s_TransformMatrices );
		}
	}
	else
	{
		/* �Z���V�F�[�f�B���O���s�����H */
		if ( s_bCelShade == GS_TRUE )
		{
			/* �Z���V�F�[�f�B���O���g���ă��b�V����`�悷�� */
			gsMeshDrawCelShade
			(
				pMesh,
				s_pTextures[ s_CelShadeTexture ],
				&s_CelShadeLightPosition,
				&s_CelShadeLineColor,
				s_CelShadeLineWidth
			);
		}
		else
		{
			/* ���b�V����`�悷�� */
			gsMeshDraw( pMesh );
		}
	}
}

/*=============================================================================
*
* Purpose : ���b�V���̕`��D(OpenGL 3.0�ȍ~�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawMeshEx
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	GSskeleton*		pSkeleton;
	GSmesh*			pMesh;

	/* ���b�V���f�[�^���擾���� */
	if ((pMesh = s_pMeshs[MeshID]) == NULL)
	{
		return;
	}
	/* �o�C���h���̃X�P���g���̎擾 */
	pSkeleton = s_pSkeletons[s_BindSkeleton];

	/* �X�L�j���O���b�V����`�悷�邩�H */
	if (s_bSkinMesh == GS_TRUE && pSkeleton != NULL)
	{
		/* �X�P���g���̎����v�Z���ݒ肳��Ă��邩�H */
		if (s_bCalculateSkeleton == GS_TRUE)
		{
			/* �p���ϊ��s��̌v�Z���s�� */
			gsCalculateSkeleton(NULL, s_AnimationMatrices, s_SkeletonMatrices);
			/* �ŏI�I�ȍ��W�ϊ��s����v�Z���� */
			gsSkeletonCalculateTransform
			(
				pSkeleton,
				s_TransformMatrices,
				s_SkeletonMatrices
			);
			/* �{�[���̕ϊ��s��̐ݒ� */
			gsSetShaderParamArrayMatrix4("gs_BoneMatrices", gsSkeletonGetNumBones(pSkeleton), s_TransformMatrices);
		}
	}
	/* ���b�V����`�悷�� */
	gsMeshDrawEx(pMesh);
}

/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawOctree
(
	GSuint			OctreeID				/* �I�N�c���[�h�c				*/
)
{
	GSoctree*		pOctree;

	/* �I�N�c���[�f�[�^���擾���� */
	if ( ( pOctree = s_pOctrees[ OctreeID ] ) == NULL )
	{
		return;
	}

	/* �I�N�c���[�̕`�� */
	gsOctreeDraw( pOctree );
}


/*=============================================================================
*
* Purpose : �I�N�c���[�̕`��D(�V�F�[�_�[�Ή��j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawOctreeEx
(
	GSuint				OctreeID,			/* �I�N�c���[�h�c		*/
	const GSmatrix4*	pProjectionMatrix,	/* �����ϊ��s��			*/
	const GSmatrix4*	pViewMatix			/* ����ϊ��s��			*/
)
{
	GSoctree*		pOctree;

	/* �I�N�c���[�f�[�^���擾���� */
	if ((pOctree = s_pOctrees[OctreeID]) == NULL)
	{
		return;
	}

	/* �I�N�c���[�̕`�� */
	gsOctreeDrawEx(pOctree, pProjectionMatrix, pViewMatix);
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c			*/
)
{
	GStexture*		pTexture;

	if ( ( pTexture = s_pTextures[ TextureID ] ) == NULL )
	{
		return;
	}

	/* �e�N�X�`�����o�C���h���� */
	gsTextureBind( s_pTextures[ TextureID ] );
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindTextureEx
(
	GSuint			TextureID,			/* �e�N�X�`���h�c			*/
	GSuint			Unit				/* �e�N�X�`�����j�b�g�̔ԍ� */
)
{
	glActiveTexture(GL_TEXTURE0 + Unit);
	gsBindTexture(TextureID);
}

/*=============================================================================
*
* Purpose : �e�N�X�`�����A���o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c			*/
)
{
	GStexture*		pTexture;

	if ((pTexture = s_pTextures[TextureID]) == NULL)
	{
		return;
	}
	gsTextureUnbind(s_pTextures[TextureID]);
}


/*=============================================================================
*
* Purpose : �e�N�X�`�����A���o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindTextureEx
(
	GSuint			TextureID,			/* �e�N�X�`���h�c			*/
	GSuint			UnitNo				/* �e�N�X�`�����j�b�g�̔ԍ� */
)
{
	glActiveTexture(GL_TEXTURE0 + UnitNo);
	gsUnbindTexture(TextureID);
	glActiveTexture(GL_TEXTURE0);
}

/*=============================================================================
*
* Purpose : �X�P���g�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	/* �X�P���g�����o�C���h���� */
	s_BindSkeleton = SkeletonID;
}

/*=============================================================================
*
* Purpose : �A�j���[�V�������o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindAnimation
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer				/* �A�j���[�V�����^�C�}		*/
)
{
	gsCalculateAnimation(AnimationID, AnimationNo, fTimer, s_AnimationMatrices);
}

/*=============================================================================
*
* Purpose : �A�j���[�V�������o�C���h����D�i ���`��� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindAnimationLerp
(
	GSuint			AnimationID1,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo1,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer1,			/* �A�j���[�V�����^�C�}		*/
	GSuint			AnimationID2,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo2,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer2,			/* �A�j���[�V�����^�C�}		*/
	GSfloat			fLerp				/* ��Ԓl					*/
)
{
	gsCalculateAnimationLerp(
		AnimationID1, AnimationNo1, fTimer1,
		AnimationID2, AnimationNo2, fTimer2,
		fLerp,
		s_AnimationMatrices
	);
}

/*=============================================================================
*
* Purpose : �A�j���[�V�������o�C���h����D�i ���`��� �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateAnimationLerp
(
	GSuint			AnimationID1,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo1,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer1,			/* �A�j���[�V�����^�C�}		*/
	GSuint			AnimationID2,		/* �A�j���[�V�����h�c		*/
	GSuint			AnimationNo2,		/* �A�j���[�V�����i���o		*/
	GSfloat			fTimer2,			/* �A�j���[�V�����^�C�}		*/
	GSfloat			fLerp,				/* ��Ԓl					*/
	GSmatrix4*		pAnimationMatrices	/*-> �A�j���[�V�����ϊ��s��	*/
)
{
	GSanimation*	pAnimation1;
	GSanimation*	pAnimation2;
	GSuint			numBones;
	GSuint			BoneNo;
	GSvector3		Scale;
	GSquaternion	Rotate;
	GSvector3		Position;
	GSvector3		Scale1;
	GSquaternion	Rotate1;
	GSvector3		Position1;
	GSvector3		Scale2;
	GSquaternion	Rotate2;
	GSvector3		Position2;
	GSmatrix4		matScale;
	GSmatrix4		matRotate;

	/* �Q�̃A�j���[�V�����f�[�^���擾���� */
	if ( ( pAnimation1 = s_pAnimations[ AnimationID1 ] ) == NULL )
	{
		return;
	}
	if ( ( pAnimation2 = s_pAnimations[ AnimationID2 ] ) == NULL )
	{
		/* ��Ԑ悪�Ȃ��ꍇ�̓A�j���[�V�����P�̂݃o�C���h */
		gsBindAnimation( AnimationID1, AnimationNo1, fTimer1 );

		return;
	}

	/* �{�[���f�[�^�����擾���� */
	numBones = gsAnimationGetNumBones( pAnimation1, AnimationNo1 );

	/* �A�j���[�V�����ϊ��s��ɐݒ肷�� */
	for ( BoneNo = 0; BoneNo < numBones; BoneNo++ )
	{
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation1,
			AnimationNo1, BoneNo, fTimer1,
			&Scale1, &Rotate1, &Position1
		);
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation2,
			AnimationNo2, BoneNo, fTimer2,
			&Scale2, &Rotate2, &Position2
		);

		/* �e�L�[����`��Ԃ��� */
		gsVector3Lerp( &Scale, &Scale1, &Scale2, fLerp );
		gsQuaternionSlerp( &Rotate, &Rotate1, &Rotate2, fLerp );
		gsVector3Lerp( &Position, &Position1, &Position2, fLerp );

		/* �e�L�[���s��ɕϊ����� */
		gsMatrix4Scale(&matScale, Scale.x, Scale.y, Scale.z);
		gsMatrix4Quaternion(&matRotate, &Rotate);
		gsMatrix4Multiply
		(
			&pAnimationMatrices[BoneNo], &matScale, &matRotate
		);
		pAnimationMatrices[BoneNo].m[3][0] = Position.x;
		pAnimationMatrices[BoneNo].m[3][1] = Position.y;
		pAnimationMatrices[BoneNo].m[3][2] = Position.z;
	}
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�p�e�N�X�`�����o�C���h����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindCelShadeTexture
(
	GSuint			TextureID			/* �e�N�`���h�c				*/
)
{
	/* �Z���V�F�[�f�B���O�p�e�N�X�`���̃o�C���h */
	s_CelShadeTexture = TextureID;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�p���C�g�̐ݒ������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLightPositionCelShade
(
	GSfloat			LightPositionX,		/* ���C�g�����W 			*/
	GSfloat			LightPositionY,		/* ���C�g�����W 			*/
	GSfloat			LightPositionZ		/* ���C�g�����W 			*/
)
{
	s_CelShadeLightPosition.x = LightPositionX;
	s_CelShadeLightPosition.y = LightPositionY;
	s_CelShadeLightPosition.z = LightPositionZ;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�̗֊s���̑�����ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLineWidthCelShade
(
	GSfloat			LineWidth			/* �֊s���̑���				*/
)
{
	s_CelShadeLineWidth = LineWidth;
}

/*=============================================================================
*
* Purpose : �Z���V�F�[�f�B���O�̗֊s���̃J���[��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsLineColorCelShade
(
	GSfloat			LineColorR,			/* �֊s���̐F�̐Ԑ���		*/
	GSfloat			LineColorG,			/* �֊s���̐F�̗ΐ���		*/
	GSfloat			LineColorB,			/* �֊s���̐F�̐���		*/
	GSfloat			LineColorA			/* �֊s���̃A���t�@����		*/
)
{
	s_CelShadeLineColor.r = LineColorR;
	s_CelShadeLineColor.g = LineColorG;
	s_CelShadeLineColor.b = LineColorB;
	s_CelShadeLineColor.a = LineColorA;
}
/*=============================================================================
*
* Purpose : �w��A�j���[�V�����̃{�[������Ԃ��D
*
* Return  : �{�[������Ԃ��D
*
*============================================================================*/
extern GSuint
gsGetAnimationNumBones
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c			*/
	GSuint			AnimationNo			/* �A�j���[�V�����i���o		*/
)
{
	GSanimation*	pAnimation;
	if ((pAnimation = s_pAnimations[AnimationID]) == NULL)
	{
		return 0;
	}
	/* �{�[���f�[�^�����擾���� */
	return gsAnimationGetNumBones(pAnimation, AnimationNo);
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����ϊ��s����v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateAnimation
(
	GSuint			AnimationID,		/* �A�j���[�V�����h�c			*/
	GSuint			AnimationNo,		/* �A�j���[�V�����i���o			*/
	GSfloat			fTimer,				/* �A�j���[�V�����^�C�}			*/
	GSmatrix4*		pAnimationMatrices	/*-> �A�j���[�V�����ϊ��s��		*/
)
{
	GSanimation*	pAnimation;
	GSuint			numBones;
	GSuint			BoneNo;
	GSvector3		Scale;
	GSquaternion	Rotate;
	GSvector3		Position;
	GSmatrix4		matScale;
	GSmatrix4		matRotate;

	/* �A�j���[�V�����f�[�^�����݂��邩�H */
	if ((pAnimation = s_pAnimations[AnimationID]) == NULL)
	{
		/* �A�j���[�V�������擾�ł��Ȃ������ꍇ�͑S�ĒP�ʍs���ݒ肷�� */
		for (BoneNo = 0; BoneNo < GS_MATRIX_MAX; BoneNo++)
		{
			gsMatrix4Identity(&s_AnimationMatrices[BoneNo]);

		}
		return;
	}

	/* �{�[���f�[�^�����擾���� */
	numBones = gsAnimationGetNumBones(pAnimation, AnimationNo);

	/* �A�j���[�V�����ϊ��s��ɐݒ肷�� */
	for (BoneNo = 0; BoneNo < numBones; BoneNo++)
	{
		/* �L�[�t���[���f�[�^���擾���� */
		gsAnimationGetKeyFrame
		(
			pAnimation,
			AnimationNo, BoneNo, fTimer,
			&Scale, &Rotate, &Position
		);

		/* �e�L�[���s��ɕϊ����� */
		gsMatrix4Scale(&matScale, Scale.x, Scale.y, Scale.z);
		gsMatrix4Quaternion(&matRotate, &Rotate);
		gsMatrix4Multiply
		(
			&pAnimationMatrices[BoneNo], &matScale, &matRotate
		);
		pAnimationMatrices[BoneNo].m[3][0] = Position.x;
		pAnimationMatrices[BoneNo].m[3][1] = Position.y;
		pAnimationMatrices[BoneNo].m[3][2] = Position.z;
	}
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����ϊ��s���ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetMatrixAnimation
(
	GSuint				numMatrices,		/* �A�j���[�V�����ϊ��s��			*/
	const GSmatrix4*	pAnimationMatrices	/* �A�j���[�V�����ϊ��s��z��		*/
)
{
	GSuint i;
	for (i = 0; i < numMatrices; ++i) {
		s_AnimationMatrices[i] =  pAnimationMatrices[i];
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̎p���ϊ��s����v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateSkeleton
(
	const GSmatrix4*	pParentMatrix,		/* �e�̃��f�����O�ϊ��s��		*/
	const GSmatrix4*	pAnimationMatrices,	/* �A�j���[�V�����ϊ��s��z��	*/
	GSmatrix4*			pSkeletonMatrices	/*-> �p���ϊ��s��z��			*/
)
{
	GSskeleton*		pSkeleton;

	/* �X�P���g���f�[�^���擾����*/
	if ( ( pSkeleton = s_pSkeletons[ s_BindSkeleton ] ) != NULL )
	{
		/* �X�P���g���f�[�^����p���ϊ��s����v�Z���� */
		gsSkeletonCalculateOrientation
		(
			pSkeleton,
			pSkeletonMatrices,
			pParentMatrix,
			pAnimationMatrices
		);
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���̎p���ϊ��s���ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetMatrixSkeleton
(
	const GSmatrix4*	pSkeletonMatrices	/* �p���ϊ��s��z��			*/
)
{
	GSuint			i;

	/* �ϊ��s��̐ݒ������ */
	for ( i = 0; i < gsGetSkeletonNumBones(s_BindSkeleton); i++ )
	{
		s_SkeletonMatrices[i] = pSkeletonMatrices[i];
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���̎p���ϊ��s���ݒ肷��D(���`���j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetMatrixOrientation
(
	GSuint				numMatrices,		/* ���W�ϊ��s��			*/
	const GSmatrix4*	pOrientationMatrices	/* �p���ϊ��s��z��			*/
)
{
	GSuint			i;

	/* �ϊ��s��̐ݒ������ */
	for (i = 0; i < numMatrices; i++)
	{
		s_SkeletonMatrices[i] = pOrientationMatrices[i];
	}
}

/*=============================================================================
*
* Purpose : �X�L�j���O���b�V���p�ϊ��s����v�Z����
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateSkinTransform
(
	const GSmatrix4*	pSkeletonMatrices,		/* �p���ϊ��s��z��				*/
	GSmatrix4*			pSkinTransformMatrices	/*-> �X�L�j���O���b�V���p�z��	*/
)
{
	GSskeleton*		pSkeleton;

	/* �X�P���g���f�[�^���擾����*/
	if ((pSkeleton = s_pSkeletons[s_BindSkeleton]) != NULL)
	{
		/* �X�P���g���f�[�^����p���ϊ��s����v�Z���� */
		gsSkeletonCalculateTransform
		(
			pSkeleton,
			pSkinTransformMatrices,
			pSkeletonMatrices
		);
	}
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̃{�[�������擾����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsGetSkeletonNumBones
(
	GSuint		SkeletonID				/* �X�P���g���̂h�c 		*/
)
{
	GSskeleton*	pSkeleton;

	if ( ( pSkeleton = s_pSkeletons[ SkeletonID ] ) == NULL )
	{
		return	0;
	}

	/* �X�P���g���f�[�^����{�[�������擾���� */
	return	gsSkeletonGetNumBones( pSkeleton );
}

/*=============================================================================
*
* Purpose : �A�j���[�V�����̏I���^�C�}���擾����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSuint
gsGetEndAnimationTime
(
	GSuint		AnimationID,			/* �A�j���[�V�����̂h�c		*/
	GSuint		AnimationNo				/* �A�j���[�V�����i���o		*/
)
{
	GSanimation*	pAnimation;

	if ( ( pAnimation = s_pAnimations[ AnimationID ] ) == NULL )
	{
		return	0;
	}

	/* �A�j���[�V�����f�[�^����A�j���[�V�����̏I���^�C�}���擾 */
	return	gsAnimationGetEndTime( pAnimation, AnimationNo );
}

/*=============================================================================
*
* Purpose : �����t�H���g�̃p�����[�^��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsTextPos
(
	GSfloat		PositoinX,		/* �����W					*/
	GSfloat		PositoinY		/* �����W					*/
)
{
	s_TextPosition.x = PositoinX;
	s_TextPosition.y = PositoinY;
}

/*=============================================================================
*
* Purpose : �����t�H���g�̃p�����[�^��ݒ肷��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsFontParameter
(
	GSbitfield	FontCode,		/* �����t�H���g�̑���		*/
	GSuint		FontPoint,		/* �����t�H���g�̃|�C���g��	*/
	const char*	pszFontName		/* �����t�H���g��			*/
)
{
	/* �����t�H���g�̑�����ݒ� */
	s_FontCode = FontCode;

	/* �����t�H���g�̃|�C���g����ݒ� */
	s_FontPoint = FontPoint;

	/* �����t�H���g���̐ݒ� */
	strcpy( s_FontName, pszFontName );
}

/*=============================================================================
*
* Purpose : �e�L�X�g�`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawText
(
	const char*	pString,			/* �\�����镶����		*/
	...								/* �I�v�V�����̈���		*/
)
{
	char		String[512];		/* �\��������o�b�t�@	*/
	GLint		ViewPort[4];
	va_list		ArgList;

	/* �ϒ������̎g�p�J�n */
	va_start( ArgList, pString );

	/* ������̃t�H�[�}�b�g�ϊ����s�� */
	vsprintf( String, pString, ArgList );

	/* �ϐ������̎g�p�I�� */
	va_end( ArgList );

	/* �e��ݒ�t���O�̑ޔ� */
	glPushAttrib( GL_ENABLE_BIT );

	/* ���C�e�B���O�𖳌��ɂ��� */
	glDisable( GL_LIGHTING );

	/* ���o�b�t�@�𖳌��ɂ��� */
	glDisable( GL_DEPTH_TEST );

	/* �ʃJ�����O�𖳌��ɂ��� */
	glDisable( GL_CULL_FACE );

	/* �����ϊ��s��̑ޔ� */
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();

	/* �r���[�|�[�g�̎擾 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* �����ϊ��s��̐ݒ� */
	glLoadIdentity();
	gluOrtho2D( 0, ViewPort[2], ViewPort[3], 0 );

	/* ���f���r���[�ϊ��s��̑ޔ� */
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();

	/* �ϊ��s��̏����� */
	glLoadIdentity();

	/* �e�L�X�g�̈ʒu��ݒ肷�� */
	glRasterPos2f( s_TextPosition.x, s_TextPosition.y );

	/* �e�L�X�g��`�悷�� */
	gsTextDraw
	(
		s_FontCode,			/* �t�H���g�R�[�h		*/
		s_FontPoint,		/* �t�H���g�̃|�C���g��	*/
		s_FontName,			/* �t�H���g��			*/
		String				/* ������				*/
	);

	/* ���f���r���[�ϊ��s��𕜋A */
	glPopMatrix();

	/* �����ϊ��s��𕜋A */
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();

	/* ���f���r���[�ϊ��s��ɐݒ� */
	glMatrixMode( GL_MODELVIEW );

	/* �e��ݒ�t���O�̕��A */
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �X�N���[�����W���烌�C���v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateRay
(
	GSint		ScreenX,				/* �X�N���[�������W		*/
	GSint		ScreenY,				/* �X�N���[�������W		*/
	GSfloat*	pRayPosX,				/*-> ���C�̂����W		*/
	GSfloat*	pRayPosY,				/*-> ���C�̂����W		*/
	GSfloat*	pRayPosZ,				/*-> ���C�̂����W		*/
	GSfloat*	pRayDirX,				/*-> ���C�̃x�N�g��		*/
	GSfloat*	pRayDirY,				/*-> ���C�̃x�N�g��		*/
	GSfloat*	pRayDirZ				/*-> ���C�̃x�N�g��		*/
)
{
	GSvector3	Pos;
	GSvector3	Dir;
	GSvector2	Window;
	GSmatrix4	matProj;
	GSmatrix4	matView;
	GLint		ViewPort[4];

	/* �r���[�|�[�g�̎擾 */
	glGetIntegerv( GL_VIEWPORT, ViewPort );

	/* �����ϊ��s��̎擾 */
	glGetFloatv( GL_PROJECTION_MATRIX, (GLfloat*)&matProj );

	/* ���_�ϊ��s��̎擾 */
	glGetFloatv( GL_MODELVIEW_MATRIX, (GLfloat*)&matView );

	/* �}�E�X�J�[�\���̍��W���E�B���h�E���W�ɕϊ� */
	Window.x = (GSfloat)ScreenX;
	Window.y = ViewPort[3] - (GSfloat)ScreenY;

	/* �r���[�|�[�g�ϊ��̋t�ϊ����s�� */
	Pos.x = ( ( ( Window.x - ViewPort[0] ) * 2.0f / ViewPort[2] ) - 1.0f );
	Pos.y = ( ( ( Window.y - ViewPort[1] ) * 2.0f / ViewPort[3] ) - 1.0f );

	/* �����ϊ��̋t�ϊ����s�� */
	Pos.x /= matProj.m[0][0];
	Pos.y /= matProj.m[1][1];
	Pos.z = -1.0f;

	/* ����ϊ��s��̋t�s������߂� */
	gsMatrix4InverseFast( &matView, &matView );

	/* ����ϊ��̋t�ϊ����s�� */
	gsVector3TransformNormal( &Dir, &Pos, &matView );

	/* ���C�̈ʒu��ݒ� */
	*pRayPosX = matView.m[3][0];
	*pRayPosY = matView.m[3][1];
	*pRayPosZ = matView.m[3][2];

	/* ���C�̕����𐳋K������ */
	gsVector3Normalize( &Dir, &Dir );

	/* ���C�̕�����ݒ肷�� */
	*pRayDirX = Dir.x;
	*pRayDirY = Dir.y;
	*pRayDirZ = Dir.z;
}

/*=============================================================================
*
* Purpose : �X�N���[�����W���v�Z����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCalculateScreen
(
	GSvector2*			pScreen,		/*-> �X�N���[�����W		*/
	const GSvector3*	pWorld			/* ���[���h���W			*/
)
{
	GSmatrix4	matViewProjScreen;
	GSmatrix4	matProj;
	GSmatrix4	matView;
	GSmatrix4   matScreen;
	GLint		ViewPort[4];
	GSvector3   result;

	/* �r���[�|�[�g�̎擾 */
	glGetIntegerv(GL_VIEWPORT, ViewPort);
	/* �X�N���[�����W�ϊ��s����쐬 */
	gsMatrix4Screen(&matScreen, ViewPort[2], ViewPort[3]);
	/* �����ϊ��s��̎擾 */
	glGetFloatv(GL_PROJECTION_MATRIX, (GLfloat*)&matProj);
	/* ���_�ϊ��s��̎擾 */
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&matView);
	/* ���W�ϊ����s�� */
	gsMatrix4Multiply(&matViewProjScreen, &matView, &matProj);
	gsMatrix4Multiply(&matViewProjScreen, &matViewProjScreen, &matScreen);
	gsVector3TransformCoord(&result, pWorld, &matViewProjScreen);
	pScreen->x = result.x;
	pScreen->y = result.y;
}

/*=============================================================================
*
* Purpose : ���b�V���f�[�^�̎擾�D
*
* Return  : ���b�V���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSmesh*
gsGetMesh
(
	GSuint			MeshID				/* ���b�V���h�c				*/
)
{
	return	s_pMeshs[ MeshID ];
}

/*=============================================================================
*
* Purpose : �X�P���g���f�[�^�̎擾�D
*
* Return  : �X�P���g���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSskeleton*
gsGetSkeleton
(
	GSuint			SkeletonID			/* �X�P���g���h�c			*/
)
{
	return	s_pSkeletons[ SkeletonID ];
}

/*=============================================================================
*
* Purpose : �A�j���V���[���f�[�^�̎擾�D
*
* Return  : �A�j���[�V�����f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSanimation*
gsGetAnimation
(
	GSuint			AnimationID			/* �A�j���[�V�����h�c		*/
)
{
	return	s_pAnimations[ AnimationID ];
}

/*=============================================================================
*
* Purpose : �I�N�c���[�f�[�^�̎擾�D
*
* Return  : �I�N�c���[�f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GSoctree*
gsGetOctree
(
	GSuint			OctreeID			/* �I�N�c���[�h�c		*/
)
{
	return	s_pOctrees[ OctreeID ];
}

/*=============================================================================
*
* Purpose : �e�N�X�`���f�[�^�̎擾�D
*
* Return  : �e�N�X�`���f�[�^�̃|�C���^��Ԃ��D
*
*============================================================================*/
extern GStexture*
gsGetTexture
(
	GSuint			TextureID			/* �e�N�X�`���h�c		*/
)
{
	return	s_pTextures[ TextureID ];
}

/*=============================================================================
*
* Purpose : ����@�\�̗L�����D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsEnable
(
	GSenum		Cap					/* ����@�\�������V���{���萔 */
)
{
	switch( Cap )
	{
	case GS_SKIN_MESH:
		s_bSkinMesh = GS_TRUE;
		break;

	case GS_CALC_SKELETON:
		s_bCalculateSkeleton = GS_TRUE;
		break;

	case GS_CEL_SHADE:
		s_bCelShade = GS_TRUE;
		break;
	}
}

/*=============================================================================
*
* Purpose : ����@�\�̖������D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDisable
(
	GSenum		Cap					/* ����@�\�������V���{���萔 */
)
{
	switch( Cap )
	{
	case GS_SKIN_MESH:
		s_bSkinMesh = GS_FALSE;
		break;

	case GS_CALC_SKELETON:
		s_bCalculateSkeleton = GS_FALSE;
		break;

	case GS_CEL_SHADE:
		s_bCelShade = GS_FALSE;
		break;
	}
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadShader
(
	GSuint			ShaderID,				/* �V�F�[�_�[�h�c		*/
	const char*		pszVertexShaderName,	/* ���_�V�F�[�_�[��		*/
	const char*		pszFragmentShaderName	/* �s�N�Z���V�F�[�_�[��	*/
)
{
	return gsLoadShaderEx(ShaderID, pszVertexShaderName, pszFragmentShaderName, NULL, NULL, NULL);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�t�@�C���̓ǂݍ��݁D
*
* Return  : �ǂݍ��݂ɐ�������ΐ^�C���s����΋U��Ԃ��D
*
*============================================================================*/
extern GSboolean
gsLoadShaderEx
(
	GSuint			ShaderID,					/* �V�F�[�_�[�h�c			*/
	const char*		pszVertexShaderName,		/* ���_�V�F�[�_�[��			*/
	const char*		pszFragmentShaderName,		/* �s�N�Z���V�F�[�_�[��		*/
	const char*		pszGeometryShaderName,		/* �W�I���g���V�F�[�_�[��	*/
	const char*		pszTessControlShaderName,	/* �n���V�F�[�_�[��			*/
	const char*		pszTessEvaluationShaderName	/* �h���C���V�F�[�_�[��		*/
)
{
	GSshaderProgram*	pShader;
	GSboolean			compled;
	GSboolean			linked;

	/* �e�N�X�`���f�[�^�̓ǂݍ��� */
	pShader = gsShaderProgramNew();
	if (pShader == NULL) {
		return GS_FALSE;
	}
	/* ���_�V�F�[�_�[�̃R���p�C�� */
	if (pszVertexShaderName != NULL) {
		compled = gsShaderProgramCompleShader(pShader, GL_VERTEX_SHADER, pszVertexShaderName);
		if (compled == GS_FALSE) {
			gsShaderProgramDelete(pShader);
			return GL_FALSE;
		}
	}
	/* �s�N�Z���V�F�[�_�[�̃R���p�C�� */
	if (pszFragmentShaderName != NULL) {
		compled = gsShaderProgramCompleShader(pShader, GL_FRAGMENT_SHADER, pszFragmentShaderName);
		if (compled == GS_FALSE) {
			gsShaderProgramDelete(pShader);
			return GL_FALSE;
		}
	}
	/* �W�I���g���V�F�[�_�[�̃R���p�C�� */
	if (pszGeometryShaderName != NULL) {
		compled = gsShaderProgramCompleShader(pShader, GL_GEOMETRY_SHADER, pszGeometryShaderName);
		if (compled == GS_FALSE) {
			gsShaderProgramDelete(pShader);
			return GL_FALSE;
		}
	}
	/* �n���V�F�[�_�[�̃R���p�C�� */
	if (pszTessControlShaderName != NULL) {
		compled = gsShaderProgramCompleShader(pShader, GL_TESS_CONTROL_SHADER, pszTessControlShaderName);
		if (compled == GS_FALSE) {
			gsShaderProgramDelete(pShader);
			return GL_FALSE;
		}
	}
	/* �h���C���V�F�[�_�[�̃R���p�C�� */
	if (pszTessEvaluationShaderName != NULL) {
		compled = gsShaderProgramCompleShader(pShader, GL_TESS_EVALUATION_SHADER, pszTessEvaluationShaderName);
		if (compled == GS_FALSE) {
			gsShaderProgramDelete(pShader);
			return GL_FALSE;
		}
	}
	/* �V�F�[�_�[�̃����N */
	linked = gsShaderProgramLinkShader(pShader);
	if (linked == GS_FALSE) {
		gsShaderProgramDelete(pShader);
		return GL_FALSE;
	}
	/* �Â��V�F�[�_�[���폜 */
	gsDeleteShader(ShaderID);
	/* �e�N�X�`���f�[�^�̍X�V */
	s_pShaders[ShaderID] = pShader;

	return GS_TRUE;
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteShader
(
	GSuint			ShaderID				/* �V�F�[�_�[�h�c			*/
)
{
	if (s_pShaders[ShaderID] != NULL)
	{
		glUseProgram(0);
		gsShaderProgramDelete(s_pShaders[ShaderID]);
		s_pShaders[ShaderID] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�̊J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBeginShader
(
	GSuint			ShaderID				/* �V�F�[�_�[�h�c			*/
)
{
	s_ExecuteShader = ShaderID;
	if (s_pShaders[s_ExecuteShader] == NULL) {
		glUseProgram(0);
		return;
	}
	gsShaderProgramBegin(s_pShaders[s_ExecuteShader]);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�̏I���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsEndShader
(
	void
)
{
	if (s_pShaders[s_ExecuteShader] != NULL)
	{
		gsShaderProgramEnd(s_pShaders[s_ExecuteShader]);
	}
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParam1f
(
	const char*			name,			/* �p�����[�^��		*/
	GSfloat				param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform1f(location, param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamArray1f
(
	const char*			name,			/* �p�����[�^��		*/
	GSuint				size,			/* �z��̃T�C�Y		*/
	const GSfloat		param[]			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform1fv(location, size, param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParam2f
(
	const char*			name,			/* �p�����[�^��		*/
	const GSvector2*	param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform2f(location, param->x, param->y);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamArray2f
(
	const char*			name,			/* �p�����[�^��		*/
	GSuint				size,			/* �z��̃T�C�Y		*/
	const GSvector2		param[]			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform2fv(location, size, (GLfloat*)param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParam3f
(
	const char*			name,			/* �p�����[�^��		*/
	const GSvector3*	param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform3f(location, param->x, param->y, param->z);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamArray3f
(
	const char*			name,			/* �p�����[�^��		*/
	GSuint				size,			/* �z��̃T�C�Y		*/
	const GSvector3		param[]			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform3fv(location, size, (GLfloat*)param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParam4f
(
	const char*			name,			/* �p�����[�^��		*/
	const GSvector4*	param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform4f(location, param->x, param->y, param->z, param->w);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamArray4f
(
	const char*			name,			/* �p�����[�^��		*/
	GSuint				size,			/* �z��̃T�C�Y		*/
	const GSvector4		param[]			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform4fv(location, size, (GLfloat*)param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamMatrix4
(
	const char*			name,			/* �p�����[�^��		*/
	const GSmatrix4*	param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniformMatrix4fv(location, 1, GL_FALSE, (GLfloat*)param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamArrayMatrix4
(
	const char*			name,			/* �p�����[�^��		*/
	GSuint				size,			/* �z��̃T�C�Y		*/
	const GSmatrix4		param[]			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniformMatrix4fv(location, size, GL_FALSE, (GLfloat*)param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[�Ƀp�����[�^��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamTexture
(
	const char*			name,			/* �p�����[�^��		*/
	const GSint			param			/* �p�����[�^		*/
)
{
	GLint location = gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
	glUniform1i(location, param);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[��Uniform Black�̃C���f�b�N�X��ݒ�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsSetShaderParamUniformBlock
(
	const char*			name,			/* �p�����[�^��		*/
	const GSuint		index			/* �C���f�b�N�X		*/
)
{
	GLint location = gsShaderProgramUniformBlock(s_pShaders[s_ExecuteShader], name);
	glUniformBlockBinding(s_pShaders[s_ExecuteShader]->program, location, index);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[��Unirom�̈ʒu���擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GLuint
gsGetShaderUnirom
(
	const char*			name			/* Unirom��			*/
)
{
	return gsShaderProgramUniform(s_pShaders[s_ExecuteShader], name);
}

/*=============================================================================
*
* Purpose : �V�F�[�_�[��Attribute�̈ʒu���擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GLuint
gsGetShaderAttribute
(
	const char*			name			/* Attribute��		*/
)
{
	return gsShaderProgramAttribute(s_pShaders[s_ExecuteShader], name);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateRenderTarget
(
	GSuint			RenderTargetID,			/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint			width,					/* ��							*/
	GSuint			height,					/* ����							*/
	GSboolean		colorBuffer,			/* �J���[�o�b�t�@���쐬			*/
	GSboolean		depthBuffer,			/* �f�v�X�o�b�t�@���쐬			*/
	GSboolean		formatFloat				/* ���������_�t�H�[�}�b�g		*/
)
{
	const GSpixelFormat* colorBufferrFormat;
	const GSpixelFormat* depthBufferrFormat;
	int numColorBuffer = (colorBuffer) ? 1 : 0;
	colorBufferrFormat = (formatFloat) ? &GS_PIXEL_FORMAT_R16G16B16A16_FLOAT: &GS_PIXEL_FORMAT_R8G8B8A8_UNORM;
	depthBufferrFormat = (formatFloat) ? &GS_PIXEL_FORMAT_D32_FLOAT_S8X24_UINT: &GS_PIXEL_FORMAT_D24_UNORM_S8_UINT;
	colorBufferrFormat = (colorBuffer) ? colorBufferrFormat : NULL;
	depthBufferrFormat = (depthBuffer) ? depthBufferrFormat : NULL;
	gsCreateRenderTargetEx(
		RenderTargetID,
		width, height,
		numColorBuffer,
		colorBufferrFormat,
		depthBufferrFormat,
		GL_LINEAR
	);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateRenderTargetEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	GSuint					numColorBuffer,	/* �J���[�o�b�t�@��				*/
	const GSpixelFormat		colorBuffer[],	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/
)
{
	GSrendertarget* pRenderTagrget;
	/* �����_�[�^�[�Q�b�g�̍쐬 */
	pRenderTagrget = gsRenderTargetNew(width, height, numColorBuffer, colorBuffer, depthBuffer, filter);

	/* ���Ƀ����_�[�^�[�Q�b�g���������ꍇ�͍폜  */
	gsDeleteRenderTarget(RenderTargetID);

	/* �e�N�X�`���f�[�^�̍X�V */
	s_pRenderTargets[RenderTargetID] = pRenderTagrget;
}

/*=============================================================================
*
* Purpose : �V���h�E�}�b�v�p�����_�[�^�[�Q�b�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateRenderTargetShadowMap
(
	GSuint			RenderTargetID,			/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint			width,					/* ��							*/
	GSuint			height,					/* ����							*/
	GSboolean		PCFshadow				/* PCFShadow���g�����H          */
)
{
	gsCreateRenderTarget(RenderTargetID, width, height, GS_FALSE, GS_TRUE, GS_TRUE);
	if (PCFshadow == GS_TRUE) {
		gsBindRenderTargetDepthEx(RenderTargetID, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gsUnbindRenderTargetDepth(RenderTargetID);
	}
}

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateRenderTargetCube
(
	GSuint			RenderTargetID,			/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint			width,					/* ��							*/
	GSuint			height,					/* ����							*/
	GSboolean		formatFloat				/* ���������_�t�H�[�}�b�g		*/
)
{
	const GSpixelFormat* colorBufferrFormat;
	const GSpixelFormat* depthBufferrFormat;
	colorBufferrFormat = (formatFloat) ? &GS_PIXEL_FORMAT_R16G16B16A16_FLOAT : &GS_PIXEL_FORMAT_R8G8B8A8_UNORM;
	depthBufferrFormat = (formatFloat) ? &GS_PIXEL_FORMAT_D32_FLOAT_S8X24_UINT : &GS_PIXEL_FORMAT_D24_UNORM_S8_UINT;
	gsCreateRenderTargetCubeEx(
		RenderTargetID,
		width, height,
		colorBufferrFormat,
		depthBufferrFormat,
		GL_LINEAR
	);
}

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateRenderTargetCubeEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	const GSpixelFormat*	colorBuffer,	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/
)
{
	GSrendertarget* pRenderTagrget;
	/* �����_�[�^�[�Q�b�g�̍쐬 */
	pRenderTagrget = gsRenderTargetCubeNew(width, height, colorBuffer, depthBuffer, filter);

	/* ���Ƀ����_�[�^�[�Q�b�g���������ꍇ�͍폜  */
	gsDeleteRenderTarget(RenderTargetID);

	/* �e�N�X�`���f�[�^�̍X�V */
	s_pRenderTargets[RenderTargetID] = pRenderTagrget;
}


/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteRenderTarget
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c		*/
)
{
	if (s_pRenderTargets[RenderTargetID] != NULL)
	{
		gsRenderTargetDelete(s_pRenderTargets[RenderTargetID]);
		s_pRenderTargets[RenderTargetID] = NULL;
	}
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBeginRenderTarget
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c		*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	/* �r���[�|�[�g�̑ޔ� */
	glGetIntegerv(GL_VIEWPORT, s_ViewPort);
	/* �����_�[�^�[�Q�b�g�̃T�C�Y�Ƀr���[�|�[�g��ݒ� */
	glViewport(0, 0, s_pRenderTargets[RenderTargetID]->Width, s_pRenderTargets[RenderTargetID]->Height);
	/* �����_�[�^�[�Q�b�g��L���ɂ��� */
	gsRenderTargetBegin(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�I���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsEndRenderTarget
(
	void
)
{
	/* �t���[���o�b�t�@�𖳌��ɂ��� */
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	/* �r���[�|�[�g�����ɖ߂� */
	glViewport(s_ViewPort[0], s_ViewPort[1], s_ViewPort[2], s_ViewPort[3]);
}

/*=============================================================================
*
* Purpose : �L���[�u�����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBeginRenderTargetCube
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c		*/
	GSenum					faceNo			/* �L���[�u�}�b�v�̖ʔԍ�		*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	/* �r���[�|�[�g�̑ޔ� */
	glGetIntegerv(GL_VIEWPORT, s_ViewPort);
	/* �����_�[�^�[�Q�b�g�̃T�C�Y�Ƀr���[�|�[�g��ݒ� */
	glViewport(0, 0, s_pRenderTargets[RenderTargetID]->Width, s_pRenderTargets[RenderTargetID]->Height);
	/* �����_�[�^�[�Q�b�g��L���ɂ��� */
	gsRenderTargetCubeBegin(s_pRenderTargets[RenderTargetID], faceNo);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindRenderTargetTexture
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					colorBuffer		/* �J���[�o�b�t�@�̔ԍ�		*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetBindColorBufferTexture(s_pRenderTargets[RenderTargetID], colorBuffer);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindRenderTargetDepth
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c	*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetBindDepthBufferTexture(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindRenderTargetTextureEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					ColorBuffer,	/* �J���[�o�b�t�@�̔ԍ�		*/
	GSuint					UnitNo			/* �e�N�X�`���̔ԍ�			*/
)
{
	glActiveTexture(GL_TEXTURE0 + UnitNo);
	gsRenderTargetBindColorBufferTexture(s_pRenderTargets[RenderTargetID], ColorBuffer);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindRenderTargetDepthEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					UnitNo			/* �e�N�X�`���̔ԍ�			*/
)
{
	glActiveTexture(GL_TEXTURE0 + UnitNo);
	gsRenderTargetBindDepthBufferTexture(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindRenderTargetTexture
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					colorBuffer		/* �J���[�o�b�t�@�̔ԍ�		*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetUnbindColorBufferTexture(s_pRenderTargets[RenderTargetID], colorBuffer);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindRenderTargetDepth
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c	*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetUnbindDepthBufferTexture(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindRenderTargetTextureEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					ColorBuffer,	/* �J���[�o�b�t�@�̔ԍ�		*/
	GSuint					UnitNo			/* �e�N�X�`���̔ԍ�			*/
)
{
	glActiveTexture(GL_TEXTURE0 + UnitNo);
	gsRenderTargetUnbindColorBufferTexture(s_pRenderTargets[RenderTargetID], ColorBuffer);
	glActiveTexture(GL_TEXTURE0);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindRenderTargetDepthEx
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c	*/
	GSuint					UnitNo			/* �e�N�X�`���̔ԍ�			*/
)
{
	glActiveTexture(GL_TEXTURE0 + UnitNo);
	gsRenderTargetUnbindDepthBufferTexture(s_pRenderTargets[RenderTargetID]);
	glActiveTexture(GL_TEXTURE0);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawRenderTarget
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c	*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetDraw(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��D�i�V�F�[�_�[�Ή��j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDrawRenderTargetEx
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c	*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return;
	}
	gsRenderTargetDrawEx(s_pRenderTargets[RenderTargetID]);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̃e�N�X�`�����擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GStexture*
gsGetRenderTargetTexture
(
	GSuint					RenderTargetID,	/* �����_�[�^�[�Q�b�g�h�c		*/
	GSuint					ColorBuffer		/* �J���[�o�b�t�@�̔ԍ�			*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return NULL;
	}
	return s_pRenderTargets[RenderTargetID]->ColorBuffers[ColorBuffer];
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̃f�v�X�e�N�X�`�����擾�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GStexture*
gsGetRenderTargetDepthTexture
(
	GSuint					RenderTargetID	/* �����_�[�^�[�Q�b�g�h�c		*/
)
{
	if (s_pRenderTargets[RenderTargetID] == NULL)
	{
		return NULL;
	}
	return s_pRenderTargets[RenderTargetID]->DepthBuffer;
}

/*=============================================================================
*
* Purpose : UniformBlock�̍쐬�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsCreateUnifomBlock
(
	GSuint			UniformBlockID,			/* Uniform Block �h�c		    */
	GSuint			Size,					/* �T�C�Y						*/
	const GSvoid*	pData					/* �f�[�^						*/
)
{
	GSunifomBlock* pUniformBlock;
	/* UniformBlock�̍쐬 */
	pUniformBlock = gsUnifomBlockNew(Size, pData);

	/* UniformBlock���������ꍇ�͍폜  */
	gsDeleteUniformBlock(UniformBlockID);

	/* UniformBlock�̍X�V */
	s_pUniformBlocks[UniformBlockID] = pUniformBlock;
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍폜�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsDeleteUniformBlock
(
	GSuint				UniformBlockID		/* Uniform Block �h�c		*/
)
{
	if (s_pUniformBlocks[UniformBlockID] != NULL)
	{
		gsUniformBlockDelete(s_pUniformBlocks[UniformBlockID]);
		s_pUniformBlocks[UniformBlockID] = NULL;
	}
}

/*=============================================================================
*
* Purpose : Uniform Block�̃o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsBindUnifomBlock
(
	GSuint				UniformBlockID,		/* Uniform Block �h�c		*/
	GSuint               index				/* �o�b�t�@�C���f�b�N�X     */
)
{
	if (s_pUniformBlocks[UniformBlockID] == NULL)
	{
		return;
	}
	gsUniformBlockBind(s_pUniformBlocks[UniformBlockID], index);
}

/*=============================================================================
*
* Purpose : Uniform Block�̃A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUnbindUnifomBlock
(
	GSuint				UniformBlockID,		/* Uniform Block �h�c		*/
	GSuint              index				/* �o�b�t�@�C���f�b�N�X     */
)
{
	if (s_pUniformBlocks[UniformBlockID] == NULL)
	{
		return;
	}
	gsUniformBlockUnbind(s_pUniformBlocks[UniformBlockID], index);
}

/*=============================================================================
*
* Purpose : Uniform Block�̍X�V�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUpdateUnifomBlock
(
	GSuint				UniformBlockID,		/* Uniform Block �h�c				*/
	const GSvoid*		pData				/* �X�V����o�b�t�@�f�[�^           */
)
{
	if (s_pUniformBlocks[UniformBlockID] == NULL)
	{
		return;
	}
	gsUpdateUnifomBlockEx(
		UniformBlockID,
		gsUniformBlockGetSize(s_pUniformBlocks[UniformBlockID]),
		0,
		pData
	);
}

/*=============================================================================
*
* Purpose : Uniform Block�̍X�V�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsUpdateUnifomBlockEx
(
	GSuint				UniformBlockID,		/* Uniform Block �h�c				*/
	GSuint				Size,				/* �X�V����o�b�t�@�f�[�^�̃o�C�g�� */
	GSuint				Offset,				/* �X�V����ꏊ�̃I�t�Z�b�g         */
	const GSvoid*		pData				/* �X�V����o�b�t�@�f�[�^           */
)
{
	if (s_pUniformBlocks[UniformBlockID] == NULL)
	{
		return;
	}
	gsUniformBlockUpdate(s_pUniformBlocks[UniformBlockID], Size, Offset, pData);
}


/********** End of File ******************************************************/
