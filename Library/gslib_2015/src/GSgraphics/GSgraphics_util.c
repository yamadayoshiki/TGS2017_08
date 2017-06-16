#include "GSgraphics_util.h"

// �Q�c�X�v���C�g�̕`��
extern void gsDrawSprite2D(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSvector2*	translation,		// ���s�ړ���
	const GSrect*		sourceRect,			// �e�N�`�����̈ʒu
	const GSvector2*	center,				// �X�v���C�g�̒��S�ʒu
	const GScolor*		color,				// �J���[
	const GSvector2*	scaling,			// �X�P�[���l
	GSfloat				rotation			// ��]�p�x
) {
	GScolor currentColor;
	GLsizei	texWidth;
	GLsizei	texHeight;
	GLfloat	width;
	GLfloat	height;
	GSrect texCoord = { 0.0f, 0.0f, 1.0f, 1.0f };

	// �e�탌���_�����O�X�e�[�g�̑ޔ�
	glPushAttrib( GL_ENABLE_BIT );
	// ���C�e�B���O�𖳌��ɂ���
	glDisable( GL_LIGHTING );
	// ���o�b�t�@�𖳌��ɂ���
	glDisable( GL_DEPTH_TEST );
	// �ʃJ�����O�𖳌��ɂ���
	glDisable( GL_CULL_FACE );

	// �J�����g�J���[���擾����
	glGetFloatv( GL_CURRENT_COLOR, (float*)&currentColor);

	// �����ϊ��s��̑ޔ�
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	// �r���[�|�[�g�̎擾
	int viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );
	// ���ˉe�̕ϊ��s���ݒ�
	glLoadIdentity();
	gluOrtho2D( 0.0f, (float)viewport[2], (float)viewport[3], 0.0f );

	// ���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	// �ϊ��s��̏�����
	glLoadIdentity();

	// ���s�ړ��ʂ̐ݒ���s��
	if ( translation != 0 ) {
		glTranslatef( translation->x, translation->y, 0.0f );
	}
	// �g��k�����s��
	if ( scaling != 0 ) {
		glScalef( scaling->x, scaling->y, 0.0f );
	}
	// ��]�p�x�̐ݒ���s��
	glRotatef( rotation, 0.0f, 0.0f, 1.0f );
	// ���S�ʒu�̕␳���s��
	if ( center != 0 ) {
		glTranslatef( -center->x, -center->y, 0 );
	}
	// ���_�J���[�̐ݒ�
	if ( color != 0 ) {
		glColor4f( color->r, color->g, color->b, color->a );
	}
	// �e�N�X�`�����o�C���h����
	gsBindTexture( textureID );

	// �o�C���h���̃e�N�X�`���̕��ƍ������擾
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH,  &texWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	width = (GLfloat)texWidth;
	height = (GLfloat)texHeight;
	if ( sourceRect != 0 ) {
		// �e�N�X�`�����W�̌v�Z���s��
		texCoord.left   = sourceRect->left   / width;
		texCoord.top    = sourceRect->top    / height;
		texCoord.right  = sourceRect->right  / width;
		texCoord.bottom = sourceRect->bottom / height;
		// �l�p�`�̕��ƍ��������߂�
		width  = ABS(sourceRect->right  - sourceRect->left);
		height = ABS(sourceRect->bottom - sourceRect->top);
	}
	// �l�p�`�̕`��
	glBegin( GL_QUADS );
		glTexCoord2f(texCoord.left, texCoord.top);
		glVertex2f(0.0f, 0.0f);
		glTexCoord2f(texCoord.left, texCoord.bottom);
		glVertex2f(0.0f, height);
		glTexCoord2f(texCoord.right, texCoord.bottom);
		glVertex2f(width, height);
		glTexCoord2f(texCoord.right, texCoord.top);
		glVertex2f(width, 0.0f);
	glEnd();
	// ���f���r���[�ϊ��s��𕜋A
	glPopMatrix();
	// �����ϊ��s��𕜋A
	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	// ���f���r���[�ϊ��s��ɐݒ�
	glMatrixMode( GL_MODELVIEW );
	// �J�����g�J���[�𕜋A����
	glColor4fv( (float*)&currentColor );
	// �����_�����O�X�e�[�g�̕��A
	glPopAttrib();
}

// �R�c�X�v���C�g�̕`��
extern void gsDrawSprite3D(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSvector3*	translation,		// ���s�ړ���
	const GSrect*		spriteRect,			// �X�v���C�g�̋�`
	const GSrect*		sourceRect,			// �e�N�`�����̈ʒu
	const GScolor*		color,				// �J���[
	const GSvector2*	scaling,			// �X�P�[���l
	GSfloat				rotation			// ��]�p�x
) {
	GScolor currentColor;
	GSmatrix4 matView;
	GLsizei	texWidth;
	GLsizei texHeight;
	GSrect texCoord = { 0.0f, 0.0f, 1.0f, 1.0f };

	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT);
	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// �J�����g�J���[���擾����
	glGetFloatv(GL_CURRENT_COLOR, (GLfloat*)&currentColor);

	// ���f���r���[�ϊ��s��̑ޔ�
	glMatrixMode( GL_MODELVIEW );
	glPushMatrix();
	// ���s�ړ��ʂ̐ݒ���s��
	if ( translation != 0 ) {
		glTranslatef(translation->x, translation->y, translation->z);
	}
	// ����ϊ��s����擾����
	glGetFloatv(GL_MODELVIEW_MATRIX, (float*)&matView);
	// �r���{�[�h�����p�̕ϊ��s����쐬
	matView.m[3][0] = 0;
	matView.m[3][1] = 0;
	matView.m[3][2] = 0;
	gsMatrix4Transpose(&matView, &matView);
	// �r���{�[�h�����p�̕ϊ��s���ݒ肷��
	glMultMatrixf((float*)&matView);
	// ��]�p�x�̐ݒ���s�� */
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);
	// �g��k�����s��
	if ( scaling != 0 ) {
		glScalef(scaling->x, scaling->y, 1.0f);
	}
	// ���_�J���[�̐ݒ�
	if ( color != 0 ) {
		glColor4f(color->r, color->g, color->b, color->a);
	}
	// �e�N�X�`�����o�C���h����
	gsBindTexture(textureID);
	// �o�C���h���̃e�N�X�`���̕��ƍ������擾
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH,  &texWidth );
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	if ( sourceRect != 0 ) {
		// �e�N�X�`�����W�̌v�Z���s��
		texCoord.left   = sourceRect->left   / texWidth;
		texCoord.top    = sourceRect->top    / texHeight;
		texCoord.right  = sourceRect->right  / texWidth;
		texCoord.bottom = sourceRect->bottom / texHeight;
	}
	// �l�p�`�̕`�� 
	glBegin( GL_QUADS );
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(texCoord.left, texCoord.top);
		glVertex2f(spriteRect->left, spriteRect->top);
		glTexCoord2f(texCoord.left, texCoord.bottom);
		glVertex2f(spriteRect->left, spriteRect->bottom);
		glTexCoord2f(texCoord.right, texCoord.bottom);
		glVertex2f(spriteRect->right, spriteRect->bottom);
		glTexCoord2f(texCoord.right, texCoord.top);
		glVertex2f(spriteRect->right, spriteRect->top);
	glEnd();

	// ���f���r���[�ϊ��s��𕜋A
	glPopMatrix();
	// �J�����g�J���[�𕜋A����
	glColor4fv((GLfloat*)&currentColor);
	// �����_�����O���[�h�̕��A
	glPopAttrib();
}

// �R�c�X�v���C�g�̕`��
extern void gsDrawSprite3DEx(
	GSuint				textureID,			// �e�N�X�`���h�c
	const GSrect*		spriteRect,			// �X�v���C�g�̋�`
	const GSrect*		sourceRect			// �e�N�`�����̈ʒu
) {
	GLsizei	  texWidth;
	GLsizei   texHeight;
	GSrect    texCoord = { 0.0f, 0.0f, 1.0f, 1.0f };
	struct {
		GSvector2 position;
		GSvector2 texcoord;
	} vertices[4];
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT);
	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// �e�N�X�`�����o�C���h����
	gsBindTexture(textureID);
	// �o�C���h���̃e�N�X�`���̕��ƍ������擾
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH,  &texWidth);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &texHeight);
	if (sourceRect != 0) {
		// �e�N�X�`�����W�̌v�Z���s��
		texCoord.left   = sourceRect->left   / texWidth;
		texCoord.top    = sourceRect->top    / texHeight;
		texCoord.right  = sourceRect->right  / texWidth;
		texCoord.bottom = sourceRect->bottom / texHeight;
	}
	// ���_�o�b�t�@�̐ݒ�
	vertices[0].position.x = spriteRect->left;
	vertices[0].position.y = spriteRect->top;
	vertices[0].texcoord.x = texCoord.left;
	vertices[0].texcoord.y = texCoord.top;
	vertices[1].position.x = spriteRect->left;
	vertices[1].position.y = spriteRect->bottom;
	vertices[1].texcoord.x = texCoord.left;
	vertices[1].texcoord.y = texCoord.bottom;
	vertices[2].position.x = spriteRect->right;
	vertices[2].position.y = spriteRect->top;
	vertices[2].texcoord.x = texCoord.right;
	vertices[2].texcoord.y = texCoord.top;
	vertices[3].position.x = spriteRect->right;
	vertices[3].position.y = spriteRect->bottom;
	vertices[3].texcoord.x = texCoord.right;
	vertices[3].texcoord.y = texCoord.bottom;
	// �l�p�`�̕`�� 
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), &vertices[0].position);
	glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), &vertices[0].texcoord);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glDisableVertexAttribArray(8);
	glDisableVertexAttribArray(0);
	// �����_�����O���[�h�̕��A
	glPopAttrib();
}

// �X�J�C�{�b�N�X�̕`��
extern void gsDrawSkyBox(GSuint meshID) {
	GSmatrix4 matView;
	// �e�탌���_�����O���[�h�̑ޔ�
	glPushAttrib(GL_ENABLE_BIT);
	// ���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	// ���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);
	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// �t�H�O�𖳌��ɂ���
	glDisable(GL_FOG);
	// ����ϊ��s���ޔ�����
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// �X�J�C�{�b�N�X�p�̕ϊ��s���ݒ肷�� */
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&matView);
	matView.m[3][0] = 0;
	matView.m[3][1] = 0;
	matView.m[3][2] = 0;
	glLoadMatrixf((GLfloat*)&matView);
	// �X�J�C�{�b�N�X��`�悷��
	gsDrawMesh( meshID );
	// ����ϊ��s��𕜋A����
	glPopMatrix();
	// �e�탌���_�����O���[�h�̕��A
	glPopAttrib();
}

// �X�J�C�{�b�N�X�̕`��
extern void gsDrawSkyBoxEx(GSuint cube_map) {
	// �C���f�b�N�X�o�b�t�@
	static const GLushort indices[] = {
		0, 3, 1, 1, 3, 2,	// �O
		4, 5, 7, 5, 6, 7,	// ��
		0, 1, 4, 1, 5, 4,	// ��
		7, 6, 3, 6, 2, 3,	// �E
		0, 4, 3, 4,	7, 3,	// ��
		5, 1, 6, 1, 2, 6	// ��
	};
	// ���_�f�[�^
	static const float vertices[] = {
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f
	};
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glActiveTexture(GL_TEXTURE0);
	gsBindTexture(cube_map);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_SHORT, indices);
	glDisableVertexAttribArray(0);
	gsUnbindTexture(cube_map);
	glPopAttrib();
}

// �X�J�C�{�b�N�X�̕`��
extern void gsDrawSkyBoxCubeMap(GSuint cube_map) {
	// �C���f�b�N�X�o�b�t�@
	static const GLushort indices[] = {
		0, 3, 1, 1, 3, 2,	// �O
		4, 5, 7, 5, 6, 7,	// ��
		0, 1, 4, 1, 5, 4,	// ��
		7, 6, 3, 6, 2, 3,	// �E
		0, 4, 3, 4,	7, 3,	// ��
		5, 1, 6, 1, 2, 6	// ��
	};
	// ���_�f�[�^
	static const float vertices[] = {
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,
		 1.0f,  1.0f, -1.0f
	};
	GSmatrix4 matView;
	glPushAttrib(GL_ENABLE_BIT);
	// ���C�e�B���O�𖳌��ɂ���
	glDisable(GL_LIGHTING);
	// ���o�b�t�@�𖳌��ɂ���
	glDisable(GL_DEPTH_TEST);
	// �ʃJ�����O�𖳌��ɂ���
	glDisable(GL_CULL_FACE);
	// �t�H�O�𖳌��ɂ���
	glDisable(GL_FOG);
	// ����ϊ��s���ޔ�����
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// �X�J�C�{�b�N�X�p�̕ϊ��s���ݒ肷�� */
	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat*)&matView);
	matView.m[3][0] = 0;
	matView.m[3][1] = 0;
	matView.m[3][2] = 0;
	glLoadMatrixf((GLfloat*)&matView);
	// �L���[�u�}�b�v���o�C���h
	gsBindTexture(cube_map);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(3, GL_FLOAT, 0, vertices);
	glDrawElements(GL_TRIANGLES, 6 * 6, GL_UNSIGNED_SHORT, indices);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	// �L���[�u�}�b�v���A���o�C���h
	gsUnbindTexture(cube_map);
	// ����ϊ��s��𕜋A����
	glPopMatrix();
	// �e�탌���_�����O���[�h�̕��A
	glPopAttrib();
}

// �L���[�u�}�b�v�ɕ`��
extern void gsDrawCubeMap(GSuint cube_map, const GSvector3* pViewPosition, void(*draw_scene)(void*), void* user) {
	static const struct {
		GSenum		face;
		GSvector3	at;
		GSvector3	up;
	} cube_map_faces[] = {
		{ GS_CUBE_MAP_POSITIVE_X,{  1.0f,  0.0f,  0.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_NEGATIVE_X,{ -1.0f,  0.0f,  0.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_POSITIVE_Y,{  0.0f,  1.0f,  0.0f },{ 0.0f, 0.0f, -1.0f } },
		{ GS_CUBE_MAP_NEGATIVE_Y,{  0.0f, -1.0f,  0.0f },{ 0.0f, 0.0f,  1.0f } },
		{ GS_CUBE_MAP_POSITIVE_Z,{  0.0f,  0.0f,  1.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_NEGATIVE_Z,{  0.0f,  0.0f, -1.0f },{ 0.0f, 1.0f,  0.0f } }
	};
	int i;
	/* �����ˉe�̕ϊ��s���ݒ肷�� */
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glScalef(-1.0f, -1.0f, 1.0f);
	gluPerspective(90.0f, 1.0f, 0.1f, 10000.0f);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	/* �L���[�u�}�b�v�Ƀ����_�����O */
	for (i = 0; i < 6; ++i) {
		GSvector3 view_position = { 0.0f, 0.0f, 0.0f };
		GSvector3 at;
		if (pViewPosition != NULL) view_position = *pViewPosition;
		gsVector3Add(&at, &view_position, &cube_map_faces[i].at);
		gsBeginRenderTargetCube(cube_map, cube_map_faces[i].face);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(
			view_position.x, view_position.y, view_position.z,
			at.x, at.y, at.z,
			cube_map_faces[i].up.x, cube_map_faces[i].up.y, cube_map_faces[i].up.z
		);
		draw_scene(user);
		gsEndRenderTarget();
	}
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

// �L���[�u�}�b�v�ɕ`��
extern void gsDrawCubeMapEx(GSuint cube_map, const GSvector3* pViewPosition, void(*draw_scene)(const GSmatrix4* projection, const GSmatrix4* view, void* user), void* user) {
	static const struct {
		GSenum		face;
		GSvector3	at;
		GSvector3	up;
	} cube_map_faces[] = {
		{ GS_CUBE_MAP_POSITIVE_X,{ 1.0f,  0.0f,  0.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_NEGATIVE_X,{ -1.0f, 0.0f,  0.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_POSITIVE_Y,{ 0.0f,  1.0f,  0.0f },{ 0.0f, 0.0f, -1.0f } },
		{ GS_CUBE_MAP_NEGATIVE_Y,{ 0.0f, -1.0f,  0.0f },{ 0.0f, 0.0f,  1.0f } },
		{ GS_CUBE_MAP_POSITIVE_Z,{ 0.0f,  0.0f,  1.0f },{ 0.0f, 1.0f,  0.0f } },
		{ GS_CUBE_MAP_NEGATIVE_Z,{ 0.0f,  0.0f, -1.0f },{ 0.0f, 1.0f,  0.0f } }
	};
	int i;
	/* �����ˉe�̕ϊ��s����쐬���� */
	GSmatrix4 projection;
	GSmatrix4 view;
	GSmatrix4 scale;
	gsMatrix4Scale(&scale, -1.0f, -1.0f, 1.0f);
	gsMatrix4PerspectiveRH(&projection, 90.0f, 1.0f, 0.1f, 10000.0f);
	gsMatrix4Multiply(&projection, &projection, &scale);
	/* �L���[�u�}�b�v�Ƀ����_�����O */
	for (i = 0; i < 6; ++i) {
		GSvector3 view_position = { 0.0f, 0.0f, 0.0f };
		GSvector3 at;
		if (pViewPosition != NULL) view_position = *pViewPosition;
		gsVector3Add(&at, &view_position, &cube_map_faces[i].at);
		gsBeginRenderTargetCube(cube_map, cube_map_faces[i].face);
		gsMatrix4LookAtRH(&view, &view_position, &at, &cube_map_faces[i].up);
		draw_scene(&projection, &view, user);
		gsEndRenderTarget();
	}
}

// end of flie
