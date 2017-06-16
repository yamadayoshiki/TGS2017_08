#ifndef _GS_GRAPHICS_UTIL_H_
#define _GS_GRAPHICS_UTIL_H_

#include <gslib.h>

#ifdef __cplusplus
extern "C" {
#endif

// �Q�c�X�v���C�g�̕`��
extern void gsDrawSprite2D(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSvector2*	translation,		// ���s�ړ���
	const GSrect*		sourceRect,			// �e�N�`�����̈ʒu
	const GSvector2*	center,				// �X�v���C�g�̒��S�ʒu
	const GScolor*		color,				// �J���[
	const GSvector2*	scaling,			// �X�P�[���l
	GSfloat				rotation			// ��]�p�x
);

// �R�c�X�v���C�g�̕`��
extern void gsDrawSprite3D(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSvector3*	translation,		// ���s�ړ���
	const GSrect*		spriteRect,			// �X�v���C�g�̋�`
	const GSrect*		sourceRect,			// �e�N�`�����̈ʒu
	const GScolor*		color,				// �J���[
	const GSvector2*	scaling,			// �X�P�[���l
	GSfloat				rotation			// ��]�p�x
);

// �R�c�X�v���C�g�̕`�� (�V�F�[�_�[�p�j
extern void gsDrawSprite3DEx(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSrect*		spriteRect,			// �X�v���C�g�̋�`
	const GSrect*		sourceRect			// �e�N�`�����̈ʒu
);

// �X�J�C�{�b�N�X�̕`��
extern void gsDrawSkyBox(
	GSuint meshID							// ���b�V��ID
);

// �X�J�C�{�b�N�X�̕`�� (�V�F�[�_�[�p�j
extern void gsDrawSkyBoxEx(
	GSuint cube_map							// �e�N�X�`���h�c�i�L���[�u�}�b�v�j
);

// �X�J�C�{�b�N�X�̕`��
extern void gsDrawSkyBoxCubeMap(
	GSuint cube_map							// �e�N�X�`���h�c�i�L���[�u�}�b�v�j
);

// �L���[�u�}�b�v�ɕ`��
extern void gsDrawCubeMap(
	GSuint cube_map,						// �����_�[�^�[�Q�b�g��ID�i�L���[�u�}�b�v�j
	const GSvector3* pViewPosition,			// ���_�̍��W
	void(*draw_scene)(void*),				// �R�[���o�b�N�֐�
	void* user								// ���[�U�[�|�C���^
);

// �L���[�u�}�b�v�ɕ`��
extern void gsDrawCubeMapEx(
	GSuint cube_map,						// �����_�[�^�[�Q�b�g��ID�i�L���[�u�}�b�v�j
	const GSvector3* pViewPosition,			// ���_�̍��W
											// �R�[���o�b�N�֐�
	void(*draw_scene)(const GSmatrix4* projection, const GSmatrix4* view, void* user),
	void* user								// ���[�U�[�|�C���^
);


#ifdef __cplusplus
}
#endif

#endif
