/******************************************************************************
* File Name : GSmesh.c                           Ver : 1.00  Date : 2003-01-31
*
* Description :
*
*       ���b�V���f�[�^�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include	"GSmesh.h"
#include	"GSvector3.h"	
#include	"GSmatrix4.h"	
#include	"GScolor.h"
#include	"GSplane.h"	
#include	"GSload_texture_file.h"
#include	"GSmath.h"
#include	"GSfile_path.h"
#include	"heap.h"
#include	"gfile.h"
#include	<string.h>
#include	<opengl_ext.h>

/****** �֐��v���g�^�C�v�錾 *************************************************/

static void	DrawMesh(GSmaterial*, GSuint, GSfacegroup*, GSushort*, GSvector3*, GSvector3*, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2**);
static void	DrawMeshCelShade(GSmaterial*, GSuint, GSfacegroup*, GSuint, GSushort*, GSuint, GSvector3*, GSvector3*, GScolor*, GSuint, GSvector2**, GStexture*, GSvector3*, GScolor*, GSfloat);
static void	SetMaterial(GSmaterial*);
static void	LoadMaterial(GSmaterial*, GFILE);
static void	TransformPoints(GSvector3*, GSuint, GSvector3*, const GSmatrix4*);
static void	TransformNormals(GSvector3*, GSuint, GSvector3*, const GSmatrix4*);
static void CalculatePlanes(GSmesh*);
static void CalculateBlendMatrices(GSmatrix4*, GSuint, GSuint, const GSblendweight*, const GSblendindices*, const GSmatrix4*);
static void CreateMeshBuffer(GSmesh*);
static void SetMaterialEx(GSmaterial*);
static void TransformVertices(GSvector3*, GSvector3*, GSvector3*, GSvector3*, GSuint, const GSvector3*, const GSvector3*, const GSvector3*, const GSvector3*, GSuint, const GSblendweight*, const GSblendindices*, const GSmatrix4*);

extern void gsSetShaderParam4f(const char*, const GSvector4*);
extern void gsSetShaderParam1f(const char*, GSfloat);

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
)
{
	GSmesh*		pMesh;

	/* ���b�V���̐��� */
	pMesh = new_object(sizeof(GSmesh));

	/* �S�Ẵ����o���[���N���A���� */
	memset(pMesh, 0, sizeof(GSmesh));

	return	pMesh;
}

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
)
{
	/* ���b�V�����N���[���A�b�v���� */
	gsMeshCleanUp(pMesh);

	/* ���b�V���̏��� */
	del_object(pMesh);
}

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
)
{
	GSuint		i;

	/* �ڃx�N�g���z��̏��� */
	if (pMesh->pBinormals != NULL)
	{
		del_object(pMesh->pBinormals);
	}

	/* �ڃx�N�g���z��̏��� */
	if (pMesh->pTangents != NULL)
	{
		del_object(pMesh->pTangents);
	}

	/* �{�[���C���f�b�N�X�z��̏��� */
	if (pMesh->pBlendIndices != NULL)
	{
		del_object(pMesh->pBlendIndices);
	}

	/* ���_�E�F�C�g�z��̏��� */
	if (pMesh->pWeights != NULL)
	{
		del_object(pMesh->pWeights);
	}

	/* �e�N�X�`�����W�z��̏��� */
	if (pMesh->ppTexCoords != NULL)
	{
		for (i = 0; i < pMesh->numTexCoords; i++)
		{
			if (pMesh->ppTexCoords[i] != NULL)
			{
				del_object(pMesh->ppTexCoords[i]);
			}
		}
		del_object(pMesh->ppTexCoords);
	}

	/* ���ˌ��J���[�z��̏��� */
	if (pMesh->pSpecularColors != NULL)
	{
		del_object(pMesh->pSpecularColors);
	}

	/* �g�U���J���[�z��̏��� */
	if (pMesh->pDiffuseColors != NULL)
	{
		del_object(pMesh->pDiffuseColors);
	}

	/* �@���x�N�g���z��̏��� */
	if (pMesh->pNormals != NULL)
	{
		del_object(pMesh->pNormals);
	}

	/* ���_���W�z��̏��� */
	if (pMesh->pPoints != NULL)
	{
		del_object(pMesh->pPoints);
	}

	/* �}�e���A���f�[�^�̏��� */
	if (pMesh->pMaterials != NULL)
	{
		for (i = 0; i < pMesh->numMaterials; i++)
		{
			/* �e�N�X�`���̏��� */
			if (pMesh->pMaterials[i].pTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pTexture);
			}
			if (pMesh->pMaterials[i].pNormalTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pNormalTexture);
			}
			if (pMesh->pMaterials[i].pSpecularTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pSpecularTexture);
			}
			if (pMesh->pMaterials[i].pAmbientTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pAmbientTexture);
			}
			if (pMesh->pMaterials[i].pCubeTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pCubeTexture);
			}
			if (pMesh->pMaterials[i].pHeightTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pHeightTexture);
			}
			if (pMesh->pMaterials[i].pEmissiveTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pEmissiveTexture);
			}
			if (pMesh->pMaterials[i].pMaskTexture != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pMaskTexture);
			}
			if (pMesh->pMaterials[i].pTexture2 != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pTexture2);
			}
			if (pMesh->pMaterials[i].pNormalTexture2 != NULL)
			{
				gsTextureDelete(pMesh->pMaterials[i].pNormalTexture2);
			}
		}
		del_object(pMesh->pMaterials);
	}

	/* ���_�C���f�b�N�X�z��̏��� */
	if (pMesh->pIndices != NULL)
	{
		del_object(pMesh->pIndices);
	}

	/* �ʃf�[�^�z��̏��� */
	if (pMesh->pFaceGroups != NULL)
	{
		del_object(pMesh->pFaceGroups);
	}

	/* ���ʃf�[�^�z��̏��� */
	if (pMesh->pPlanes != NULL)
	{
		del_object(pMesh->pPlanes);
	}

	/* �o�b�t�@�I�u�W�F�N�g�̍폜 */
	glDeleteVertexArrays(1, &pMesh->Buffer.ArrayBuffer);
	glDeleteBuffers(1, &pMesh->Buffer.IndexBuffer);
	glDeleteBuffers(1, &pMesh->Buffer.VertexBuffer);
	pMesh->Buffer.IndicesOffset = 0;

	/* �S�Ẵ����o���[���N���A���� */
	memset(pMesh, 0, sizeof(GSmesh));
}

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
)
{
	GFILE			file;
	GSuint			bPoints;
	GSuint			numNormals;
	GSuint			bDiffuseColors;
	GSuint			bSpecularColors;
	GSuint			bBoneIndices;
	GSuint			i;
	GSuint			j;

	/* ���b�V���t�@�C�����I�[�v������ */
	if ((file = GFileOpen(pszFileName, "r")) == NULL)
	{
		/* �t�@�C�����I�[�v���ł��Ȃ����� */
		return	GS_FALSE;
	}

	/* ���b�V���̃N���[���A�b�v */
	gsMeshCleanUp(pMesh);

	/* ���b�V�����t���O��ǂݍ��� */
	GFileReadDwordHex(file, &pMesh->MeshInfo);

	/* ���_�f�[�^��񐔂̓ǂݍ��� ( �����_�ł͎g�p���Ă��Ȃ� �j*/
	GFileReadDword(file, &bPoints);

	/* ���_�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword(file, &bPoints);

	/* �@���x�N�g���f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword(file, &numNormals);

	/* �g�U���J���[�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword(file, &bDiffuseColors);

	/* ���ʔ��ˌ��J���[�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword(file, &bSpecularColors);

	/* �e�N�X�`�����W�f�[�^���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numTexCoords);

	/* ���_�E�F�C�g�f�[�^���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numWeights);

	/* �{�[���C���f�b�N�X�f�[�^�t���O�̓ǂݍ��� */
	GFileReadDword(file, &bBoneIndices);

	/* �}�e���A���f�[�^���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numMaterials);

	/* �ʃf�[�^�O���[�v���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numFaceGroups);

	/* ���_�C���f�b�N�X�f�[�^���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numIndices);

	/* ���_�f�[�^���̓ǂݍ��� */
	GFileReadDword(file, &pMesh->numVertices);

	/* �}�e���A���f�[�^�z��̐��� */
	pMesh->pMaterials = new_object(sizeof(GSmaterial) * pMesh->numMaterials);

	/* �}�e���A���f�[�^�z��̓ǂݍ��� */
	for (i = 0; i < pMesh->numMaterials; i++)
	{
		LoadMaterial(&pMesh->pMaterials[i], file);
	}

	/* �ʃO���[�v�z��̐��� */
	pMesh->pFaceGroups = new_object(sizeof(GSfacegroup) * pMesh->numFaceGroups);

	/* �ʃO���[�v�̔z��̓ǂݍ��� */
	for (i = 0; i < pMesh->numFaceGroups; i++)
	{
		/* �ʏ��t���O�̓ǂݍ��� */
		GFileReadDwordHex(file, &pMesh->pFaceGroups[i].FaceInfo);

		/* �}�e���A���C���f�b�N�X�̓ǂݍ���	*/
		GFileReadDword(file, &pMesh->pFaceGroups[i].MaterialNo);

		/* ���_�C���f�b�N�X�̊J�n�ʒu�̓ǂݍ��� */
		GFileReadDword(file, &pMesh->pFaceGroups[i].StartIndices);

		/* ���_�C���f�b�N�X���̓ǂݍ��� */
		GFileReadDword(file, &pMesh->pFaceGroups[i].numIndices);
	}

	/* ���_�C���f�b�N�X�z��̓ǂݍ��� */
	if (pMesh->numIndices != 0)
	{
		pMesh->pIndices = new_object(sizeof(GSushort) * pMesh->numIndices);

		GFileReadWordArray(file, pMesh->numIndices, pMesh->pIndices);
	}

	/* ���_�f�[�^�z��̓ǂݍ��� */
	if (bPoints == GS_TRUE)
	{
		pMesh->pPoints = new_object(sizeof(GSvector3) * pMesh->numVertices);

		GFileReadVector3Array(file, pMesh->numVertices, pMesh->pPoints);
	}

	/* �@���x�N�g���z��̓ǂݍ��� */
	if (numNormals >= 1)
	{
		pMesh->pNormals = new_object(sizeof(GSvector3) * pMesh->numVertices);

		GFileReadVector3Array(file, pMesh->numVertices, pMesh->pNormals);
	}

	/* �g�U���J���[�z��̓ǂݍ��� */
	if (bDiffuseColors == GS_TRUE)
	{
		pMesh->pDiffuseColors = new_object(sizeof(GScolor) * pMesh->numVertices);

		GFileReadColorArray(file, pMesh->numVertices, pMesh->pDiffuseColors);
	}

	/* ���ʔ��ˌ��J���[�z��̓ǂݍ��� */
	if (bSpecularColors == GS_TRUE)
	{
		pMesh->pSpecularColors = new_object(sizeof(GScolor) * pMesh->numVertices);

		GFileReadColorArray(file, pMesh->numVertices, pMesh->pSpecularColors);
	}

	/* �e�N�X�`�����W�z��̓ǂݍ��� */
	if (pMesh->numTexCoords != 0)
	{
		pMesh->ppTexCoords = new_object(sizeof(GSvector2*) * pMesh->numTexCoords);

		for (i = 0; i < pMesh->numTexCoords; i++)
		{
			pMesh->ppTexCoords[i] = new_object(sizeof(GSvector2) * pMesh->numVertices);

			GFileReadTexCoordArray(file, pMesh->numVertices, pMesh->ppTexCoords[i]);
		}
	}

	if (bBoneIndices == GS_TRUE)
	{
		GSfloat*	weights;
		GSuint*		boneIndex;
		/* ���_�E�F�C�g�z��̓ǂݍ��� */
		pMesh->pWeights = new_object(sizeof(GSblendweight) * pMesh->numVertices);
		memset(pMesh->pWeights, 0, sizeof(GSblendweight) * pMesh->numVertices);
		for (i = 0; i < pMesh->numWeights; i++)
		{
			weights = new_object(sizeof(GSfloat) * pMesh->numVertices);
			GFileReadFloatArray(file, pMesh->numVertices, weights);
			for (j = 0; j < pMesh->numVertices; ++j) {
				pMesh->pWeights[j].Weights[i] = weights[j];
			}
			del_object(weights);
		}
		for (i = 0; i < pMesh->numVertices; ++i) {
			float totalWeight = 0.0f;
			for (j = 0; j < pMesh->numWeights; ++j)
			{
				totalWeight += pMesh->pWeights[i].Weights[j];
			}
			pMesh->pWeights[i].Weights[j] = 1.0f - totalWeight;
		}
		++pMesh->numWeights;

		/* �{�[���C���f�b�N�X�z��̓ǂݍ��� */
		boneIndex = new_object(sizeof(GSuint) * pMesh->numVertices);
		GFileReadDwordHexArray(file, pMesh->numVertices, boneIndex);
		pMesh->pBlendIndices = new_object(sizeof(GSblendindices) * pMesh->numVertices);
		for (i = 0; i < pMesh->numVertices; ++i) {
			pMesh->pBlendIndices[i].Indices[0] = (boneIndex[i] >>  0) & 0xff;
			pMesh->pBlendIndices[i].Indices[1] = (boneIndex[i] >>  8) & 0xff;
			pMesh->pBlendIndices[i].Indices[2] = (boneIndex[i] >> 16) & 0xff;
			pMesh->pBlendIndices[i].Indices[3] = (boneIndex[i] >> 24) & 0xff;
		}
		del_object(boneIndex);
	}

	/* �ڃx�N�g���z��̓ǂݍ��� */
	if (numNormals >= 2)
	{
		pMesh->pTangents = new_object(sizeof(GSvector3) * pMesh->numVertices);

		GFileReadVector3Array(file, pMesh->numVertices, pMesh->pTangents);
	}

	/* �]�@���x�N�g���z��̓ǂݍ��� */
	if (numNormals >= 3)
	{
		pMesh->pBinormals = new_object(sizeof(GSvector3) * pMesh->numVertices);

		GFileReadVector3Array(file, pMesh->numVertices, pMesh->pBinormals);
	}

	/* ���b�V���t�@�C���̃N���[�Y */
	GFileClose(file);

	/* ���b�V���̕��ʃf�[�^�z����v�Z���� */
	CalculatePlanes(pMesh);

	return	GS_TRUE;
}

/*=============================================================================
*
* Purpose : ���b�V���t�@�C���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern GSboolean
gsMeshLoadFileEx
(
	GSmesh*			pMesh,				/* ���b�V���f�[�^		*/
	const char*		pszFileName			/* �t�@�C����			*/
)
{
	GSboolean result;
	result = gsMeshLoadFile(pMesh, pszFileName);
	if (result == GS_TRUE)
	{
		CreateMeshBuffer(pMesh);
	}
	return result;
}

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
)
{
	/* ���b�V����`�悷�� */
	DrawMesh
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->pIndices,
		pMesh->pPoints,
		pMesh->pNormals,
		pMesh->pTangents,
		pMesh->pBinormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords
	);
}

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
)
{
	/* �Z���V�F�[�f�B���O���s�����b�V����`�悷�� */
	DrawMeshCelShade
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->numIndices,
		pMesh->pIndices,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords,
		pShadeTexture,
		pShadeLight,
		pLineColor,
		fLineWidth
	);
}

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
)
{
	GSvector3*			pPoints = NULL;
	GSvector3*			pNormals = NULL;
	GSvector3*			pTangents = NULL;
	GSvector3*			pBinormals = NULL;

	/* �{�[���C���f�b�N�X�������Ă��邩�H */
	if (pMesh->pBlendIndices == NULL)
	{
		/* �{�[���C���f�b�N�X���Ȃ��ꍇ�̓X�L�j���O�̌v�Z�͂��Ȃ� */
		gsMeshDraw(pMesh);

		return;
	}
	/* ���_�f�[�^�z��𐶐����� */
	pPoints = new_object(sizeof(GSvector3) * pMesh->numVertices);

	/* �@���x�N�g���z��𐶐�����	*/
	if (pMesh->pNormals != NULL) {
		pNormals = new_object(sizeof(GSvector3) * pMesh->numVertices);
	}

	/* �ڃx�N�g���z��𐶐�����	*/
	if (pMesh->pTangents != NULL) {
		pTangents = new_object(sizeof(GSvector3) * pMesh->numVertices);
	}

	/* �]�@���x�N�g���𐶐����� */
	if (pMesh->pBinormals != NULL) {
		pBinormals = new_object(sizeof(GSvector3) * pMesh->numVertices);
	}

	/* ���_�f�[�^�̍��W�ϊ� */
	TransformVertices
	(
		pPoints, pNormals, pTangents, pBinormals,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->pNormals,
		pMesh->pTangents,
		pMesh->pBinormals, 
		pMesh->numWeights,
		pMesh->pWeights,
		pMesh->pBlendIndices,
		pMatrices
	);
	/* ���b�V����`�悷�� */
	DrawMesh
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->pIndices,
		pPoints,
		pNormals,
		pTangents,
		pBinormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords
	);
	/* �]�@���x�N�g���z������ł����� */
	del_object(pBinormals);

	/* �ڃx�N�g���z������ł����� */
	del_object(pTangents);

	/* �@���x�N�g���z������ł����� */
	del_object(pNormals);

	/* ���_�f�[�^�z������ł����� */
	del_object(pPoints);
}

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
)
{
	GSvector3*			pPoints;
	GSvector3*			pNormals;

	/* �{�[���C���f�b�N�X�������Ă��邩�H */
	if (pMesh->pBlendIndices == NULL)
	{
		/* �{�[���C���f�b�N�X���Ȃ��ꍇ�̓X�L�j���O�̌v�Z�͂��Ȃ� */
		gsMeshDrawCelShade
		(
			pMesh,
			pShadeTexture,
			pShadeLight,
			pLineColor,
			fLineWidth
		);

		return;
	}

	/* ���_�f�[�^�z��𐶐����� */
	pPoints = new_object(sizeof(GSvector3) * pMesh->numVertices);

	/* �@���x�N�g���z��𐶐�����	*/
	pNormals = new_object(sizeof(GSvector3) * pMesh->numVertices);

	/* ���_�f�[�^�̍��W�ϊ� */
	TransformVertices(
		pPoints, pNormals, NULL, NULL,
		pMesh->numVertices,
		pMesh->pPoints,
		pMesh->pNormals,
		NULL, NULL,
		pMesh->numWeights,
		pMesh->pWeights,
		pMesh->pBlendIndices,
		pMatrices
	);

	/* �Z���V�F�[�f�B���O���s�����b�V����`�悷�� */
	DrawMeshCelShade
	(
		pMesh->pMaterials,
		pMesh->numFaceGroups,
		pMesh->pFaceGroups,
		pMesh->numIndices,
		pMesh->pIndices,
		pMesh->numVertices,
		pPoints,
		pNormals,
		pMesh->pDiffuseColors,
		pMesh->numTexCoords,
		pMesh->ppTexCoords,
		pShadeTexture,
		pShadeLight,
		pLineColor,
		fLineWidth
	);

	/* �@���x�N�g���z������ł����� */
	del_object(pNormals);

	/* ���_�f�[�^�z������ł����� */
	del_object(pPoints);
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawMesh
(
	GSmaterial*		pMaterials,			/* �}�e���A���f�[�^�z��	*/
	GSuint			numFaceGroups,		/* �ʃf�[�^�O���[�v��	*/
	GSfacegroup*	pFaceGroups,		/* �ʃf�[�^�O���[�v		*/
	GSushort*		pIndices,			/* ���_�C���f�b�N�X		*/
	GSvector3*		pPoints,			/* ���_�f�[�^�z��		*/
	GSvector3*		pNormals,			/* �@���x�N�g���z��		*/
	GSvector3*		pTangents,			/* �ڃx�N�g���z��		*/
	GSvector3*		pBinormals,			/* �]�@���x�N�g���z��	*/
	GScolor*		pDiffuseColors,		/* �g�U���z��			*/
	GSuint			numTexCoords,		/* �e�N�X�`�����W�z��	*/
	GSvector2**		ppTexCoords			/* �e�N�X�`�����W�z��	*/
)
{
	GScolor			CurrentColor;
	GSuint			i;

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_LIGHTING_BIT | GL_TEXTURE_BIT);

	/* ���݂̃J���[���擾���� */
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&CurrentColor);

	/* ���_�f�[�^�z��̐ݒ� */
	glDisableClientState(GL_VERTEX_ARRAY);
	if (pPoints != NULL)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, pPoints);
	}

	/* �@���x�N�g���z��̐ݒ� */
	glDisableClientState(GL_NORMAL_ARRAY);
	if (pNormals != NULL)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, pNormals);
	}

	/* �ڃx�N�g���z��̐ݒ� */
	glClientActiveTexture(GL_TEXTURE6);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	if (pTangents != NULL)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(3, GL_FLOAT, 0, pTangents);
	}

	/* �]�@���x�N�g���z��̐ݒ� */
	glClientActiveTexture(GL_TEXTURE7);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	if (pBinormals != NULL)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(3, GL_FLOAT, 0, pBinormals);
	}

	/* �J���[�f�[�^�z��̐ݒ� */
	glDisableClientState(GL_COLOR_ARRAY);
	if (pDiffuseColors != NULL)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, 0, pDiffuseColors);
	}

	/* �e�N�X�`�����W2�z��̐ݒ� */
	glClientActiveTexture(GL_TEXTURE1);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	if (numTexCoords >= 2)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, ppTexCoords[1]);
	}

	/* �e�N�X�`�����W�z��̐ݒ� */
	glClientActiveTexture(GL_TEXTURE0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	if (numTexCoords >= 1)
	{
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, ppTexCoords[0]);
	}

	for (i = 0; i < numFaceGroups; i++)
	{
		/* �}�e���A�����̐ݒ������ */
		SetMaterial(&pMaterials[pFaceGroups[i].MaterialNo]);

		/* �O�p�`��`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT,
			&pIndices[pFaceGroups[i].StartIndices]
		);

		/* �J�����g�J���[��ݒ肷�� */
		glColor4fv((GLfloat*)&CurrentColor);
	}


	/* �e�N�X�`���𖳌��ɂ��� */
	glBindTexture(GL_TEXTURE_2D, 0);

	/* �����_�����O���[�h�̕��A */
	glPopAttrib();
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕`��D�i �Z���V�F�[�f�B���O �j
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
DrawMeshCelShade
(
	GSmaterial*		pMaterials,			/* �}�e���A���f�[�^�z��			*/
	GSuint			numFaceGroups,		/* �ʃf�[�^�O���[�v��			*/
	GSfacegroup*	pFaceGroups,		/* �ʃf�[�^�O���[�v				*/
	GSuint			numIndices,			/* ���_�C���f�b�N�X��			*/
	GSushort*		pIndices,			/* ���_�C���f�b�N�X				*/
	GSuint			numVertices,		/* ���_�f�[�^��					*/
	GSvector3*		pPoints,			/* ���_�f�[�^�z��				*/
	GSvector3*		pNormals,			/* �@���x�N�g���z��				*/
	GScolor*		pDiffuseColors,		/* �g�U���z��					*/
	GSuint			numTexCoords,		/* �e�N�X�`�����W�z��			*/
	GSvector2**		ppTexCoords,		/* �e�N�X�`�����W�z��			*/
	GStexture*		pShadeTexture,		/* �V�F�[�f�B���O�p�e�N�X�`��	*/
	GSvector3*		pShadeLight,		/* ���C�g�̈ʒu					*/
	GScolor*		pLineColor,			/* �֊s���̐F					*/
	GSfloat			fLineWidth			/* �֊s���̑���					*/
)
{
	GSmaterial*		pMaterial;
	GSvector2*		pTexCoords;
	GScolor			CurrentColor;
	GSmatrix4		tmpMat;
	GSvector3		tmpLight;
	GScolor			tmpColor;
	GSuint			i;
	(void)numTexCoords;

	/* ���݂̃J���[���擾���� */
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&CurrentColor);

	/* �g�D�[���V�F�[�f�B���O�p�̃e�N�X�`�����W�z��𐶐� */
	pTexCoords = new_object(sizeof(GSvector2) * numVertices);

	/* ���f���r���[�ϊ��}�g���N�X���擾���� */
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&tmpMat);

	/* ���C�g�̕����Ƀ��f���r���[�ϊ��s��̋t�s����|���Z���� */
	tmpLight.x = pShadeLight->x * tmpMat.m[0][0]
		+ pShadeLight->y * tmpMat.m[0][1]
		+ pShadeLight->z * tmpMat.m[0][2];
	tmpLight.y = pShadeLight->x * tmpMat.m[1][0]
		+ pShadeLight->y * tmpMat.m[1][1]
		+ pShadeLight->z * tmpMat.m[1][2];
	tmpLight.z = pShadeLight->x * tmpMat.m[2][0]
		+ pShadeLight->y * tmpMat.m[2][1]
		+ pShadeLight->z * tmpMat.m[2][2];

	/* ���C�g�̃x�N�g���𐳋K������ */
	gsVector3Normalize(&tmpLight, &tmpLight);

	if (pNormals != NULL)
	{
		/* �g�D�[���V�F�[�f�B���O�̃e�N�X�`�����W�̌v�Z���s�� */
		for (i = 0; i < numVertices; i++)
		{
			/* ���C�g�̕����Ɩ@���x�N�g������e�N�X�`�����W�����߂� */
			pTexCoords[i].s = MAX(0.0f, gsVector3Dot(&pNormals[i], &tmpLight));
			pTexCoords[i].t = 0.0f;
		}
	}
	else
	{
		/* �@���x�N�g�������݂��Ȃ��ꍇ�̓V�F�[�f�B���O�ł��Ȃ� */
		for (i = 0; i < numVertices; i++)
		{
			pTexCoords[i].s = 1.0f;
			pTexCoords[i].t = 0.0f;
		}
	}

	/* �e�탌���_�����O���[�h�̑ޔ� */
	glPushAttrib
	(
		GL_ENABLE_BIT |
		GL_DEPTH_BUFFER_BIT |
		GL_COLOR_BUFFER_BIT |
		GL_POLYGON_BIT |
		GL_LIGHTING_BIT |
		GL_TEXTURE_BIT
	);

	/* ���C�e�B���O���I�t�ɂ��� */
	glDisable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_BLEND);

	/* ���_�f�[�^�z��̐ݒ� */
	glDisableClientState(GL_VERTEX_ARRAY);
	if (pPoints != NULL)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, pPoints);
	}

	/* �J���[�f�[�^�z��̐ݒ� */
	glDisableClientState(GL_COLOR_ARRAY);
	if (pDiffuseColors != NULL)
	{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(4, GL_FLOAT, 0, pDiffuseColors);
	}

	/* �@���x�N�g���z��̐ݒ� */
	glDisableClientState(GL_NORMAL_ARRAY);
	if (pNormals != NULL)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, pNormals);
	}

	for (i = 0; i < numFaceGroups; i++)
	{
		/* �}�e���A���f�[�^�̎擾 */
		pMaterial = &pMaterials[pFaceGroups[i].MaterialNo];

		/* �}�e���A���̐ݒ� */
		gsColorModulate(&tmpColor, &pMaterial->Diffuse, &CurrentColor);
		glColor4fv((GLfloat*)&tmpColor);

		/* �@���x�N�g���z��𖳌��ɂ��� */
		glDisableClientState(GL_NORMAL_ARRAY);

		/* �e�N�X�`�����W��L���ɂ��� */
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		/* �Z���V�F�[�f�B���O�p�̃e�N�X�`�����o�C���h���� */
		if (pShadeTexture != NULL)
		{
			gsTextureBind(pShadeTexture);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_TEXTURE_2D);
		}
		else
		{
			glDisable(GL_TEXTURE_2D);
		}

		/* �Z���V�F�[�f�B���O�p�̃e�N�X�`�����W��ݒ肷�� */
		glTexCoordPointer(2, GL_FLOAT, 0, pTexCoords);

		/* �Z���V�F�[�f�B���O�p�|���S����`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT,
			&pIndices[pFaceGroups[i].StartIndices]
		);

		if (pMaterial->pTexture != NULL)
		{
			/* �e�N�X�`���}�b�s���O�̐ݒ� */
			gsTextureBind(pMaterial->pTexture);
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glBlendFunc(GL_DST_COLOR, GL_ZERO);
			glEnable(GL_TEXTURE_2D);

			/* �e�N�X�`�����N�����v���邩�H*/
			if ((pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP) != 0)
			{
				/* �e�N�X�`�����N�����v�ɐݒ肷�� */
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

				/* EDGE�N�����v���L���ł���Ύg�p���� */
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			}
			else
			{
				/* �e�N�X�`�������b�v������ */
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			}

			/* ���`���}�b�s���O���s�����H */
			if ((pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP) != 0)
			{
				/* ���`���}�b�s���O��L���ɂ��� */
				glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
				glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
				glEnable(GL_TEXTURE_GEN_S);
				glEnable(GL_TEXTURE_GEN_T);
				glDisableClientState(GL_TEXTURE_COORD_ARRAY);

				/* �@���x�N�g���z���L���ɂ��� */
				glEnableClientState(GL_NORMAL_ARRAY);
			}
			else
			{
				/* �ʏ�̃e�N�X�`�����W�z��̐ݒ� */
				glTexCoordPointer(2, GL_FLOAT, 0, ppTexCoords[0]);
			}

			/* �ʏ�̃e�N�X�`����`�悷�� */
			glDrawElements
			(
				GL_TRIANGLES,
				pFaceGroups[i].numIndices,
				GL_UNSIGNED_SHORT,
				&pIndices[pFaceGroups[i].StartIndices]
			);

			/* ���`���}�b�s���O�𖳌��ɂ��� */
			glDisable(GL_TEXTURE_GEN_S);
			glDisable(GL_TEXTURE_GEN_T);
		}

		/* �J�����g�J���[�𕜋A���� */
		glColor4fv((GLfloat*)&CurrentColor);
	}

	/* �֊s���̕`����s�� */
	if (fLineWidth > 0)
	{
		float scale = fLineWidth * 0.01f;

		/* �@�������ɒ��_�f�[�^���g�傷�� */
		for (i = 0; i < numVertices; i++)
		{
			pPoints[i].x += pNormals[i].x * scale;
			pPoints[i].y += pNormals[i].y * scale;
			pPoints[i].z += pNormals[i].z * scale;
		}

		/* �e�N�X�`���𖳌��ɂ��� */
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);

		/* �֊s���̐F��ݒ肷�� */
		gsColorModulate(&tmpColor, pLineColor, &CurrentColor);
		glColor4fv((GLfloat*)&tmpColor);

		/* �����_�����O���[�h�̐ݒ� */
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glCullFace(GL_FRONT);

		/* �֊s����`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			numIndices,
			GL_UNSIGNED_SHORT,
			pIndices
		);

		/* �J�����g�J���[�𕜋A���� */
		glColor4fv((GLfloat*)&CurrentColor);
	}
	/* �e�N�X�`���𖳌��ɂ��� */
	glBindTexture(GL_TEXTURE_2D, 0);

	/* �e�탌���_�����O���[�h�̕��A */
	glPopAttrib();

	/* �g�D�[���V�F�[�f�B���O�p�̃e�N�X�`�����W�����ł����� */
	del_object(pTexCoords);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �}�e���A���̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
SetMaterial
(
	GSmaterial*		pMaterial			/* �}�e���A���f�[�^	*/
)
{
	GScolor			Diffuse;
	GScolor			Ambient;
	GScolor			CurrentColor;

	/* ���݂̃J���[���擾���� */
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&CurrentColor);

	/* �����Ɗg�U���J���[�����݂̃J���[�ƕϒ����� */
	gsColorModulate(&Diffuse, &pMaterial->Diffuse, &CurrentColor);
	gsColorModulate(&Ambient, &pMaterial->Ambient, &CurrentColor);

	/* �}�e���A�����̐ݒ� */
	glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat*)&Diffuse);
	glMaterialfv(GL_FRONT, GL_AMBIENT, (GLfloat*)&Ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat*)&pMaterial->Specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, (GLfloat*)&pMaterial->Emissive);
	glMaterialf(GL_FRONT, GL_SHININESS, (GLfloat)pMaterial->Power);

	/* ���C�e�B���O���I�t�̏ꍇ�̃}�e���A���ݒ� */
	glColor4fv((GLfloat*)&Diffuse);

	if (pMaterial->pTexture == NULL)
	{
		/* �e�N�X�`���}�b�s���O�̐ݒ���� */
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_TEXTURE_1D);
	}
	else
	{
		/* �e�N�X�`���}�b�s���O�̐ݒ� */
		glActiveTexture(GL_TEXTURE0);
		gsTextureBind(pMaterial->pTexture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		/* �e�N�X�`�����N�����v���邩�H*/
		if ((pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP) != 0)
		{
			/* �e�N�X�`�����N�����v�ɐݒ肷�� */
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

			/* EDGE�N�����v���L���ł���Ύg�p���� */
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}
		else
		{
			/* �e�N�X�`�������b�v������ */
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
	}

	if ((pMaterial->MaterialInfo & GS_MATERIAL_SPHERE_MAP) != 0)
	{
		/* ���`���}�b�s���O��L���ɂ��� */
		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	else
	{
		/* ���`���}�b�s���O�𖳌��ɂ��� */
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	}
	/* �@���}�b�v�̐ݒ� */
	if (pMaterial->pNormalTexture != 0)
	{
		glActiveTexture(GL_TEXTURE1);
		gsTextureBind(pMaterial->pNormalTexture);
	}
	/* ���ʔ��˃e�N�X�`���̐ݒ� */
	if (pMaterial->pSpecularTexture != 0)
	{
		glActiveTexture(GL_TEXTURE2);
		gsTextureBind(pMaterial->pSpecularTexture);
	}
	/* �A���r�G���g�I�N���[�W�����e�N�X�`���̐ݒ� */
	if (pMaterial->pAmbientTexture != 0)
	{
		glActiveTexture(GL_TEXTURE3);
		gsTextureBind(pMaterial->pAmbientTexture);
	}
	/* ���ȏƖ��}�b�v�̐ݒ� */
	if (pMaterial->pEmissiveTexture != 0)
	{
		glActiveTexture(GL_TEXTURE4);
		gsTextureBind(pMaterial->pEmissiveTexture);
	}
	/* �����}�b�v�̐ݒ� */
	if (pMaterial->pHeightTexture != 0)
	{
		glActiveTexture(GL_TEXTURE5);
		gsTextureBind(pMaterial->pHeightTexture);
	}
	/* ��Q�e�N�X�`���}�b�v�̐ݒ�				*/
	if (pMaterial->pTexture2 != 0)
	{
		glActiveTexture(GL_TEXTURE6);
		gsTextureBind(pMaterial->pTexture2);
	}
	/* ��Q�@���}�b�v�̐ݒ�				*/
	if (pMaterial->pNormalTexture2 != 0)
	{
		glActiveTexture(GL_TEXTURE7);
		gsTextureBind(pMaterial->pNormalTexture2);
	}
	/* �}�X�N�e�N�X�`���̐ݒ� */
	if (pMaterial->pMaskTexture != 0)
	{
		glActiveTexture(GL_TEXTURE8);
		gsTextureBind(pMaterial->pMaskTexture);
	}
	/* �L���[�u���}�b�v�e�N�X�`���̐ݒ� */
	if (pMaterial->pCubeTexture != 0)
	{
		glActiveTexture(GL_TEXTURE9);
		gsTextureBind(pMaterial->pCubeTexture);
	}
	glActiveTexture(GL_TEXTURE0);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �e�N�X�`���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static GStexture*
LoadTexture
(
	GFILE		file					/* �t�@�C��			*/
)
{
	GStexture*	pTexture;
	char		TexFileName[_MAX_PATH];
	char		Drive[_MAX_DRIVE];
	char		Dir[_MAX_DIR];

	/* �I�[�v�����Ă��郁�b�V���t�@�C���̃p�X���擾���� */
	gsSplitPath(GFileGetFileName(file), Drive, Dir, NULL, NULL);
	strcpy(TexFileName, Drive);
	strcat(TexFileName, Dir);

	/* �e�N�X�`���t�@�C�����̓ǂݍ��� */
	GFileReadString(file, TexFileName + strlen(TexFileName));

	/* �e�N�X�`���𐶐� */
	pTexture = gsLoadTextureFile(TexFileName);

	/* �~�b�v�}�b�v�𐶐����� */
	if (pTexture != NULL && pTexture->Mipmap == 1) {
		gsTextureGenerateMipmap(pTexture);
	}
	return pTexture;
}

/*-----------------------------------------------------------------------------
*
* Purpose : �}�e���A���̓ǂݍ��݁D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
LoadMaterial
(
	GSmaterial*	pMaterial,				/* �}�e���A��		*/
	GFILE		file					/* �t�@�C��			*/
)
{
	/* �}�e���A�����t���O�̓ǂݍ��� */
	GFileReadDwordHex(file, &pMaterial->MaterialInfo);

	/* �g�U���J���[�̓ǂݍ��� */
	GFileReadColor(file, &pMaterial->Diffuse);

	/* �����J���[�̓ǂݍ��� */
	GFileReadColor(file, &pMaterial->Ambient);

	/* ���ʔ��ˌ��J���[�̓ǂݍ��� */
	GFileReadColor(file, &pMaterial->Specular);

	/* ���ˌ��J���[�̓ǂݍ��� */
	GFileReadColor(file, &pMaterial->Emissive);

	/* �n�C���C�g�̑N���x�̓ǂݍ��� */
	GFileReadFloat(file, &pMaterial->Power);
	pMaterial->Power = MAX(pMaterial->Power, 1.0f);

	/* �e�N�X�`���̓ǂݍ��� */
	pMaterial->pTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_TEXTURE) != 0)
	{
		pMaterial->pTexture = LoadTexture(file);
	}
	/* �@���}�b�v�̓ǂݍ���	*/
	pMaterial->pNormalTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_NORMAL_TEXTURE) != 0)
	{
		pMaterial->pNormalTexture = LoadTexture(file);
	}
	/* ���ʔ��˃}�b�v�̓ǂݍ���	*/
	pMaterial->pSpecularTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_SPECULAR_TEXTURE) != 0)
	{
		pMaterial->pSpecularTexture = LoadTexture(file);
	}
	/* �A���r�G���g�I�N���[�W�����}�b�v�̓ǂݍ���	*/
	pMaterial->pAmbientTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_AMBIENT_TEXTURE) != 0)
	{
		pMaterial->pAmbientTexture = LoadTexture(file);
	}
	/* ���ȏƖ��}�b�v�̓ǂݍ���			*/
	pMaterial->pEmissiveTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_EMISSIVE_TEXTURE) != 0)
	{
		pMaterial->pEmissiveTexture = LoadTexture(file);
	}
	/* �����}�b�v�̓ǂݍ��� */
	pMaterial->pHeightTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_HEIGHT_TEXTURE) != 0)
	{
		pMaterial->pHeightTexture = LoadTexture(file);
	}
	/* ��Q�e�N�X�`���}�b�v				*/
	pMaterial->pTexture2 = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_TEXTURE2) != 0)
	{
		pMaterial->pTexture2 = LoadTexture(file);
	}
	/* ��Q�@���}�b�v			*/
	pMaterial->pNormalTexture2 = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_NORMAL_TEXTURE2) != 0)
	{
		pMaterial->pNormalTexture2 = LoadTexture(file);
	}
	/* �}�X�N�e�N�X�`���̓ǂݍ���			*/
	pMaterial->pMaskTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_MASK_TEXTURE) != 0)
	{
		pMaterial->pMaskTexture = LoadTexture(file);
	}
	/* �L���[�u���}�b�v�̓ǂݍ���	*/
	pMaterial->pCubeTexture = NULL;
	if ((pMaterial->MaterialInfo & GS_MATERIAL_CUBE_TEXTURE) != 0)
	{
		pMaterial->pCubeTexture = LoadTexture(file);
	}
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���b�V���̕��ʃp�����[�^�̌v�Z������D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
CalculatePlanes
(
	GSmesh*			pMesh				/* ���b�V��					*/
)
{
	GSuint			i;

	/* ���Ƀv���[������������Ă���ꍇ�͏��ł����� */
	if (pMesh->pPlanes != NULL)
	{
		del_object(pMesh->pPlanes);
	}

	/* ���ʃp�����[�^�̔z��𐶐����� */
	pMesh->pPlanes = new_object(sizeof(GSplane) * (pMesh->numIndices / 3));

	/* �S�|���S���ƃ��C�̏Փ˔�����s�� */
	for (i = 0; i < (pMesh->numIndices / 3); i++)
	{
		/* �|���S���̂R���_���擾���� */
		gsPlaneFromPoints(
			&pMesh->pPlanes[i],
			&pMesh->pPoints[pMesh->pIndices[i * 3 + 0]],
			&pMesh->pPoints[pMesh->pIndices[i * 3 + 1]],
			&pMesh->pPoints[pMesh->pIndices[i * 3 + 2]]
		);
	}
}

/*=============================================================================
*
* Purpose : ���b�V���̕`��D
*
* Return  : �Ȃ��D
*
=============================================================================*/
extern void
gsMeshDrawEx
(
	GSmesh*			pMesh				/* ���b�V���\����		*/
)
{
	const GLushort* base = 0;
	GSuint			i;

	/* �����_�����O���[�h�̑ޔ� */
	glPushAttrib(GL_TEXTURE_BIT);

	/* �o�b�t�@�I�u�W�F�N�g�̐ݒ� */
	glBindVertexArray(pMesh->Buffer.ArrayBuffer);
	for (i = 0; i < pMesh->numFaceGroups; ++i)
	{
		/* �}�e���A�����̐ݒ������ */
		SetMaterialEx(&pMesh->pMaterials[pMesh->pFaceGroups[i].MaterialNo]);
		/* �O�p�`��`�悷�� */
		glDrawElements
		(
			GL_TRIANGLES,
			pMesh->pFaceGroups[i].numIndices,
			GL_UNSIGNED_SHORT,
			&base[pMesh->pFaceGroups[i].StartIndices + pMesh->Buffer.IndicesOffset]
		);
	}
	glBindVertexArray(0);

	/* �����_�����O���[�h�̕��A */
	glPopAttrib();
}

/*-----------------------------------------------------------------------------
*
* Purpose : �}�e���A���̐ݒ�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
SetMaterialEx
(
	GSmaterial*		pMaterial			/* �}�e���A���f�[�^	*/
)
{
	/* �}�e���A�����̐ݒ� */
	gsSetShaderParam4f("gs_MaterialAmbient", &pMaterial->Ambient);
	gsSetShaderParam4f("gs_MaterialDiffuse", &pMaterial->Diffuse);
	gsSetShaderParam4f("gs_MaterialSpecular", &pMaterial->Specular);
	gsSetShaderParam4f("gs_MaterialEmission", &pMaterial->Emissive);
	gsSetShaderParam1f("gs_MaterialShininess", pMaterial->Power);
	/* �e�N�X�`���}�b�s���O�̐ݒ� */
	if (pMaterial->pTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE0);
		gsTextureBind(pMaterial->pTexture);
		/* �e�N�X�`�����N�����v���邩�H*/
		if ((pMaterial->MaterialInfo & GS_MATERIAL_TEX_CLAMP) != 0)
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		}
		else
		{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		}
	}
	/* �@���}�b�v�̐ݒ� */
	if (pMaterial->pNormalTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE1);
		gsTextureBind(pMaterial->pNormalTexture);
	}
	/* ���ʔ��˃e�N�X�`���̐ݒ� */
	if (pMaterial->pSpecularTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE2);
		gsTextureBind(pMaterial->pSpecularTexture);
	}
	/* �A���r�G���g�I�N���[�W�����e�N�X�`���̐ݒ� */
	if (pMaterial->pAmbientTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE3);
		gsTextureBind(pMaterial->pAmbientTexture);
	}
	/* ���ȏƖ��}�b�v�̐ݒ� */
	if (pMaterial->pEmissiveTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE4);
		gsTextureBind(pMaterial->pEmissiveTexture);
	}
	/* �����}�b�v�̐ݒ� */
	if (pMaterial->pHeightTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE5);
		gsTextureBind(pMaterial->pHeightTexture);
	}
	/* ��Q�e�N�X�`���}�b�v�̐ݒ�				*/
	if (pMaterial->pTexture2 != NULL)
	{
		glActiveTexture(GL_TEXTURE6);
		gsTextureBind(pMaterial->pTexture2);
	}
	/* ��Q�@���}�b�v�̐ݒ�				*/
	if (pMaterial->pNormalTexture2 != NULL)
	{
		glActiveTexture(GL_TEXTURE7);
		gsTextureBind(pMaterial->pNormalTexture2);
	}
	/* �}�X�N�e�N�X�`���̐ݒ� */
	if (pMaterial->pMaskTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE8);
		gsTextureBind(pMaterial->pMaskTexture);
	}
	/* �L���[�u���}�b�v�e�N�X�`���̐ݒ� */
	if (pMaterial->pCubeTexture != NULL)
	{
		glActiveTexture(GL_TEXTURE9);
		gsTextureBind(pMaterial->pCubeTexture);
	}
	glActiveTexture(GL_TEXTURE0);
}

/*-----------------------------------------------------------------------------
*
* Purpose : �o�b�t�@�I�u�W�F�N�g�̍쐬�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
CreateMeshBuffer
(
	GSmesh*			pMesh				/* ���b�V���\����		*/
)
{
	GLint	offset_points          = -1;
	GLint	offset_weights         = -1;
	GLint	offset_normals         = -1;
	GLint	offset_diffuse_colors  = -1;
	GLint	offset_specular_colors = -1;
	GLint	offset_blend_indices   = -1;
	GLint	offset_texcoord0       = -1;
	GLint	offset_texcoord1       = -1;
	GLint	offset_tangents        = -1;
	GLint	offset_binormals       = -1;
	GLuint	vertex_buffer_size     = 0;
	unsigned char* base = 0;
	/* ���_�o�b�t�@�̃I�t�Z�b�g�ƃT�C�Y���v�Z���� */
	if (pMesh->pPoints != 0)
	{
		offset_points = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector3);
	}
	if (pMesh->pWeights != 0)
	{
		offset_weights = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSblendweight);
	}
	if (pMesh->pNormals != NULL)
	{
		offset_normals = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector3);
	}
	if (pMesh->pDiffuseColors != NULL)
	{
		offset_diffuse_colors = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GScolor);
	}
	if (pMesh->pSpecularColors != NULL)
	{
		offset_specular_colors = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GScolor);
	}
	if (pMesh->pBlendIndices != NULL)
	{
		offset_blend_indices = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSblendindices);
	}
	if (pMesh->numTexCoords >= 1 && pMesh->ppTexCoords[0] != NULL)
	{
		offset_texcoord0 = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector2);
	}
	if (pMesh->numTexCoords >= 2 && pMesh->ppTexCoords[1] != NULL)
	{
		offset_texcoord1 = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector2);
	}
	if (pMesh->pTangents != NULL)
	{
		offset_tangents = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector3);
	}
	if (pMesh->pBinormals != NULL)
	{
		offset_binormals = vertex_buffer_size;
		vertex_buffer_size += pMesh->numVertices * sizeof(GSvector3);
	}
	/* ���_�z��I�u�W�F�N�g�̍쐬 */
	glGenVertexArrays(1, &pMesh->Buffer.ArrayBuffer);
	glBindVertexArray(pMesh->Buffer.ArrayBuffer);
	/* �C���f�b�N�X�o�b�t�@�̍쐬 */
	glGenBuffers(1, &pMesh->Buffer.IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pMesh->Buffer.IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, pMesh->numIndices * sizeof(GLushort), pMesh->pIndices, GL_STATIC_DRAW);
	/* ���_�o�b�t�@�̍쐬 */
	glGenBuffers(1, &pMesh->Buffer.VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, pMesh->Buffer.VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex_buffer_size, 0, GL_STATIC_DRAW);
	if (offset_points != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_points, pMesh->numVertices * sizeof(GSvector3), pMesh->pPoints);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, &base[offset_points]);
	}
	if (offset_weights != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_weights, pMesh->numVertices * sizeof(GSblendweight), pMesh->pWeights);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, &base[offset_weights]);
	}
	if (offset_normals != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_normals, pMesh->numVertices * sizeof(GSvector3), pMesh->pNormals);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, &base[offset_normals]);
	}
	if (offset_diffuse_colors != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_diffuse_colors, pMesh->numVertices * sizeof(GScolor), pMesh->pDiffuseColors);
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, 0, &base[offset_diffuse_colors]);
	}
	if (offset_specular_colors != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_specular_colors, pMesh->numVertices * sizeof(GScolor), pMesh->pSpecularColors);
		glEnableVertexAttribArray(4);
		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, 0, &base[offset_specular_colors]);
	}
	if (offset_blend_indices != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_blend_indices, pMesh->numVertices * sizeof(GSblendindices), pMesh->pBlendIndices);
		glEnableVertexAttribArray(7);
		glVertexAttribPointer(7, 4, GL_UNSIGNED_BYTE, GL_FALSE, 0, &base[offset_blend_indices]);
	}
	if (offset_texcoord0 != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_texcoord0, pMesh->numVertices * sizeof(GSvector2), pMesh->ppTexCoords[0]);
		glEnableVertexAttribArray(8);
		glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, 0, &base[offset_texcoord0]);
	}
	if (offset_texcoord1 != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_texcoord1, pMesh->numVertices  * sizeof(GSvector2), pMesh->ppTexCoords[1]);
		glEnableVertexAttribArray(9);
		glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, 0, &base[offset_texcoord1]);
	}
	if (offset_tangents != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_tangents, pMesh->numVertices * sizeof(GSvector3), pMesh->pTangents);
		glEnableVertexAttribArray(14);
		glVertexAttribPointer(14, 3, GL_FLOAT, GL_FALSE, 0, &base[offset_tangents]);
	}
	if (offset_binormals != -1)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_binormals, pMesh->numVertices * sizeof(GSvector3), pMesh->pBinormals);
		glEnableVertexAttribArray(15);
		glVertexAttribPointer(15, 3, GL_FLOAT, GL_FALSE, 0, &base[offset_binormals]);
	}
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/*-----------------------------------------------------------------------------
*
* Purpose : ���_�u�����h�p�s��̌v�Z�D
*
* Return  : �Ȃ��D
*
*----------------------------------------------------------------------------*/
static void
TransformVertices
(
	GSvector3*				pOutPoints,		/*-> ���_�f�[�^	            */
	GSvector3*				pOutNormals,	/*-> �v�Z��̖@���x�N�g��	*/
	GSvector3*				pOutTangents,	/*-> �v�Z��̐ڃx�N�g��	    */
	GSvector3*				pOutBinormals,	/*-> �v�Z��̏]�@���x�N�g�� */
	GSuint					numVertices,	/* ���_�f�[�^��				*/
	const GSvector3*		pPoints,		/* ���_�f�[�^	            */
	const GSvector3*		pNormals,		/* �@���x�N�g��	            */
	const GSvector3*		pTangents,		/* �ڃx�N�g��	            */
	const GSvector3*		pBinromals,		/* �]�@���x�N�g��	        */
	GSuint					numWeights,		/* �E�F�C�g��				*/
	const GSblendweight*	pWeights,		/* �{�[���E�F�C�g�z��		*/
	const GSblendindices*	pBoneIndices,	/* �{�[���C���f�b�N�X�z��	*/
	const GSmatrix4*		pBoneMetrices	/* �{�[���̕ϊ��s��			*/
)
{
	GSuint i;
	for (i = 0; i < numVertices; ++i) {
		GSmatrix4 boneMatrix = { 0 };
		GSuint j;
		for (j = 0; j < numWeights; ++j) {
			const GSfloat(*s)[4] = pBoneMetrices[pBoneIndices[i].Indices[j]].m;
			GSfloat(*d)[4] = boneMatrix.m;
			GSfloat w = pWeights[i].Weights[j];
			d[0][0] += s[0][0] * w; d[0][1] += s[0][1] * w; d[0][2] += s[0][2] * w;
			d[1][0] += s[1][0] * w; d[1][1] += s[1][1] * w; d[1][2] += s[1][2] * w;
			d[2][0] += s[2][0] * w; d[2][1] += s[2][1] * w; d[2][2] += s[2][2] * w;
			d[3][0] += s[3][0] * w; d[3][1] += s[3][1] * w; d[3][2] += s[3][2] * w;
		}
		gsVector3Transform(&pOutPoints[i], &pPoints[i], &boneMatrix);
		if (pNormals != NULL) {
			gsVector3TransformNormal(&pOutNormals[i], &pNormals[i], &boneMatrix);
		}
		if (pTangents != NULL) {
			gsVector3TransformNormal(&pOutTangents[i], &pTangents[i], &boneMatrix);
		}
		if (pBinromals != NULL) {
			gsVector3TransformNormal(&pOutBinormals[i], &pBinromals[i], &boneMatrix);
		}
	}
}
/********** End of File ******************************************************/
