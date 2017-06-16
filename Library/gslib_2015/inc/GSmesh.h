/******************************************************************************
* File Name : GSmesh.h                           Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		���b�V���f�[�^ �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef		_GSMESH_H_
#define		_GSMESH_H_

#include	"GStype.h"
#include	"GStexture.h"

/****** �萔�錾 *************************************************************/

#define	GS_MATERIAL_TEXTURE				( 1	<< 0 )	/* �e�N�X�`��			*/
#define	GS_MATERIAL_NORMAL_TEXTURE		( 1	<< 1 )	/* �@���}�b�v			*/
#define	GS_MATERIAL_SPECULAR_TEXTURE	( 1	<< 2 )	/* ���ʔ��˃}�b�v		*/
#define	GS_MATERIAL_AMBIENT_TEXTURE		( 1	<< 3 )	/* �g�U���˃}�b�v		*/
#define	GS_MATERIAL_EMISSIVE_TEXTURE	( 1	<< 4 )	/* ���ȏƖ��}�b�v		*/
#define	GS_MATERIAL_HEIGHT_TEXTURE		( 1	<< 5 )	/* �����}�b�v			*/
#define	GS_MATERIAL_TEXTURE2			( 1	<< 6 )	/* ��Q�e�N�X�`��		*/
#define	GS_MATERIAL_NORMAL_TEXTURE2		( 1	<< 7 )	/* ��Q�@���}�b�v		*/
#define	GS_MATERIAL_MASK_TEXTURE		( 1	<< 8 )	/* �}�X�N�}�b�v			*/
#define	GS_MATERIAL_CUBE_TEXTURE		( 1	<< 9 )	/* �L���[�u���}�b�v	*/

#define	GS_MATERIAL_SPHERE_MAP			( 1	<< 31 )	/* ���`���}�b�s���O	*/
#define	GS_MATERIAL_TEX_CLAMP			( 1	<< 30 )	/* �e�N�X�`�����N�����v	*/

/****** �f�[�^�^�錾 *********************************************************/

/*----- �}�e���A�����\���� ------------------------------------------------*/

typedef	struct							/* �}�e���A���\����			*/
{
	GSbitfield		MaterialInfo;		/* �}�e���A�����t���O		*/
	GScolor			Diffuse;			/* �g�U���J���[				*/
	GScolor			Ambient;			/* �����J���[				*/
	GScolor			Specular;			/* ���ʔ��ˌ��J���[			*/
	GScolor			Emissive;			/* ���ˌ��J���[				*/
	GSfloat			Power;				/* �n�C���C�g�̑N���x		*/
	GStexture*		pTexture;			/* �e�N�X�`��				*/
	GStexture*		pNormalTexture;		/* �@���}�b�v				*/
	GStexture*		pSpecularTexture;	/* ���ʔ��˃}�b�v			*/
	GStexture*		pAmbientTexture;	/* �g�U���˃}�b�v			*/
	GStexture*		pCubeTexture;		/* �L���[�u���}�b�v		*/
	GStexture*		pHeightTexture;		/* �����}�b�v				*/
	GStexture*		pEmissiveTexture;	/* ���ȏƖ��}�b�v			*/
	GStexture*		pMaskTexture;		/* �}�X�N�e�N�X�`��			*/
	GStexture*		pTexture2;			/* ��Q�e�N�X�`���}�b�v		*/
	GStexture*		pNormalTexture2;	/* ��Q�@���}�b�v			*/

} GSmaterial;

/*----- �ʃf�[�^�O���[�v�\���� ---------------------------------------------*/

typedef	struct							/* �ʃf�[�^�O���[�v�^		*/
{
	GSbitfield		FaceInfo;			/* �ʏ��t���O				*/
	GSuint			MaterialNo;			/* �}�e���A���i���o			*/
	GSuint			numIndices;			/* ���_�C���f�b�N�X��		*/
	GSuint			StartIndices;		/* ���_�C���f�b�N�X�J�n�ʒu	*/

} GSfacegroup;

/*----- �{�[���C���f�b�N�X�\���� -------------------------------------------*/

typedef struct {
	GSubyte			Indices[4];			/*�{�[���C���f�b�N�X		*/
} GSblendindices;

/*----- �{�[���C���f�b�N�X�\���� -------------------------------------------*/

typedef struct {
	GSfloat			Weights[4];			/* �{�[���E�F�C�g			*/
} GSblendweight;

/*----- �o�b�t�@�I�u�W�F�N�g�\���� -----------------------------------------*/

typedef struct {
	GLuint		ArrayBuffer;			/* ���_�z��I�u�W�F�N�g				*/
	GLuint		VertexBuffer;			/* ���_�o�b�t�@�I�u�W�F�N�g			*/	
	GLuint		IndexBuffer;			/* �C���f�b�N�X�o�b�t�@�I�u�W�F�N�g */
	GSuint		IndicesOffset;			/* �C���f�b�N�X�o�b�t�@�̃I�t�Z�b�g */
} GSmeshbuffer;

/*----- ���b�V���\���� -----------------------------------------------------*/

typedef	struct							/* ���b�V���^				*/
{
	GSbitfield		MeshInfo;			/* ���b�V�����				*/
	GSuint			numMaterials;		/* �}�e���A���f�[�^��		*/
	GSuint			numFaceGroups;		/* �����_�����O�ʏ��		*/
	GSuint			numIndices;			/* ���_�C���f�b�N�X��		*/
	GSuint			numVertices;		/* ���_�f�[�^�� 			*/
	GSuint			numTexCoords;		/* �e�N�X�`�����W��			*/
	GSuint			numWeights;			/* ���_�E�F�C�g��			*/
	GSmaterial*		pMaterials;			/* �}�e���A���f�[�^�z��		*/
	GSfacegroup*	pFaceGroups;		/* �����_�����O�ʏ��		*/
	GSushort*		pIndices;			/* ���_�C���f�b�N�X			*/
	GSvector3*		pPoints;			/* ���_���W�z��				*/
	GSvector3*		pNormals;			/* �@���x�N�g���z��			*/
	GScolor*		pDiffuseColors;		/* �g�U���J���[�z��			*/
	GScolor*		pSpecularColors;	/* ���ʔ��ˌ��J���[�z��		*/
	GSvector2**		ppTexCoords;		/* �e�N�X�`�����W�z��		*/
	GSblendweight*	pWeights;			/* ���_�E�F�C�g�z��			*/
	GSblendindices*	pBlendIndices;		/* �{�[���C���f�b�N�X�z��	*/
	GSvector3*		pTangents;			/* �ڃx�N�g���z��			*/
	GSvector3*		pBinormals;			/* �]�@���x�N�g���z��		*/
	GSplane*		pPlanes;			/* ���ʃf�[�^�z��			*/
	GSvector3		Center;				/* ���b�V���̋��E���̒��S	*/
	GSfloat			fRadius;			/* ���b�V���̋��E���̔��a	*/
	GSmeshbuffer	Buffer;				/* �o�b�t�@�I�u�W�F�N�g		*/
} GSmesh;

/****** �֐��v���g�^�C�v�錾 *************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/*=============================================================================
*
* Purpose : ���b�V���̐����D
*
* Return  : ���b�V����Ԃ��D
*
*============================================================================*/
extern GSmesh*
gsMeshNew
(
	void
);

/*=============================================================================
*
* Purpose : ���b�V���̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDelete
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���̃N���[���A�b�v�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshCleanUp
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsMeshLoadFile
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
);

/*=============================================================================
*
* Purpose : ���b�V���t�@�C���̓ǂݍ��݁D(�V�F�[�_�[��p�j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsMeshLoadFileEx
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
);

/*=============================================================================
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDraw
(
	GSmesh*			pMesh				/* ���b�V���f�[�^		*/
);

/*=============================================================================
*
* Purpose : ���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawCelShade
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^				*/
	GStexture*		pShadeTexture,		/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*		pShadeLight,		/* ���C�g�̈ʒu					*/
	GScolor*		pLineColor,			/* �֊s���̐F					*/
	GSfloat			fLineWidth			/* �֊s���̑���					*/
);

/*=============================================================================
*
* Purpose : �X�L�j���O���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawSkin
(
	GSmesh*				pMesh,			/* ���b�V���f�[�^		*/
	const GSmatrix4*	pMatrices		/* �ϊ��s��z��			*/
);

/*=============================================================================
*
* Purpose : �X�L�j���O���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsMeshDrawSkinCelShade
(
	GSmesh*				pMesh,			/* ���b�V���f�[�^				*/
	const GSmatrix4*	pMatrices,		/* �ϊ��s��z��					*/
	GStexture*			pShadeTexture,	/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*			pShadeLight,	/* ���C�g�̈ʒu					*/
	GScolor*			pLineColor,		/* �֊s���̐F					*/
	GSfloat				fLineWidth		/* �֊s���̑���					*/
);

/*=============================================================================
*
* Purpose : ���b�V���̕`��D�i�V�F�[�_�[��p�j
*
* Return  : �Ȃ��D
*
=============================================================================*/
extern void
gsMeshDrawEx
(
	GSmesh*			pMesh				/* ���b�V���\����		*/
);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
