#include "GSrender_target.h"
#include "heap.h"
#include <opengl_ext.h>

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̐����D
*
* Return  : �����_�[�^�[�Q�b�g��Ԃ��D
*
*============================================================================*/
extern GSrendertarget*
gsRenderTargetNew
(
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	GSuint					numColorBuffer,	/* �J���[�o�b�t�@��				*/
	const GSpixelFormat		colorBuffer[],	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/
)
{
	GLenum drawBuffers[GS_MRT_MAX];
	GSrendertarget* renderTaget;
	renderTaget = new_object(sizeof(GSrendertarget));
	memset(renderTaget, 0, sizeof(GSrendertarget));
	renderTaget->Width = width;
	renderTaget->Height = height;
	/* �t���[���o�b�t�@�I�u�W�F�N�g�̍쐬�@*/
	glGenFramebuffers(1, &renderTaget->FrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, renderTaget->FrameBuffer);
	/* �J���[�o�b�t�@�̍쐬 */
	renderTaget->NumColorBuffer = numColorBuffer;
	for (GLuint i = 0; i < renderTaget->NumColorBuffer; ++i) {
		renderTaget->ColorBuffers[i] = gsTextureNew(GL_TEXTURE_2D, width, height, 1, 1, &colorBuffer[i], NULL);
		gsTextureBind(renderTaget->ColorBuffers[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, renderTaget->ColorBuffers[i]->dwTexName, 0);
		drawBuffers[i] = GL_COLOR_ATTACHMENT0 + i;
		gsTextureUnbind(renderTaget->ColorBuffers[i]);
	}
	if (numColorBuffer == 0) {
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
	} else {
		glDrawBuffers(numColorBuffer, drawBuffers);
	}
	/* �f�v�X�o�b�t�@�̍쐬 */
	if (depthBuffer != NULL) {
		renderTaget->DepthBuffer = gsTextureNew(GL_TEXTURE_2D, width, height, 1, 1, depthBuffer, NULL);
		gsTextureBind(renderTaget->DepthBuffer);
		GLfloat border_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, renderTaget->DepthBuffer->dwTexName, 0);
		gsTextureUnbind(renderTaget->DepthBuffer);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return renderTaget;
}

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̐����D
*
* Return  : �L���[�u�}�b�v�����_�[�^�[�Q�b�g��Ԃ��D
*
*============================================================================*/
extern GSrendertarget*
gsRenderTargetCubeNew
(
	GSuint					width,			/* ��							*/
	GSuint					height,			/* ����							*/
	const GSpixelFormat*	colorBuffer,	/* �J���[�o�b�t�@�t�H�[�}�b�g	*/
	const GSpixelFormat*	depthBuffer,	/* �f�v�X�o�b�t�@�t�H�[�}�b�g	*/
	GLint					filter			/* �e�N�X�`���t�B���^			*/
)
{
	GSrendertarget* renderTaget;
	renderTaget = new_object(sizeof(GSrendertarget));
	memset(renderTaget, 0, sizeof(GSrendertarget));
	renderTaget->Width = width;
	renderTaget->Height = height;
	/* �t���[���o�b�t�@�I�u�W�F�N�g�̍쐬�@*/
	glGenFramebuffers(1, &renderTaget->FrameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, renderTaget->FrameBuffer);
	/* �J���[�o�b�t�@�̍쐬 */
	renderTaget->NumColorBuffer = 1;
	renderTaget->ColorBuffers[0] = gsTextureNew(GL_TEXTURE_CUBE_MAP, width, height, 1, 1, colorBuffer, NULL);
	gsTextureBind(renderTaget->ColorBuffers[0]);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, filter);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X, renderTaget->ColorBuffers[0]->dwTexName, 0);
	gsTextureUnbind(renderTaget->ColorBuffers[0]);
	/* �f�v�X�o�b�t�@�̍쐬 */
	if (depthBuffer != NULL) {
		renderTaget->DepthBuffer = gsTextureNew(GL_TEXTURE_2D, width, height, 1, 1, depthBuffer, NULL);
		gsTextureBind(renderTaget->DepthBuffer);
		GLfloat border_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE, GL_LUMINANCE);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, renderTaget->DepthBuffer->dwTexName, 0);
		gsTextureUnbind(renderTaget->DepthBuffer);
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	return renderTaget;
}


/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̏��ŁD
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDelete
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	/* �J���[�o�b�t�@�̍폜 */
	for (GLuint i = 0; i < pRenderTarget->NumColorBuffer; ++i) {
		gsTextureDelete(pRenderTarget->ColorBuffers[i]);
	}
	/* �f�v�X�o�b�t�@�̍폜 */
	if (pRenderTarget->DepthBuffer != NULL) {
		gsTextureDelete(pRenderTarget->DepthBuffer);
	}
	/* �t���[���o�b�t�@�I�u�W�F�N�g�̍폜 */
	glDeleteFramebuffers(1, &pRenderTarget->FrameBuffer);
	/*�@�����_�[�^�[�Q�b�g�̍폜 */
	del_object(pRenderTarget);
}


/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBegin
(
	GSrendertarget*			pRenderTarge	/* �����_�[�^�[�Q�b�g	*/
)
{
	glBindFramebuffer(GL_FRAMEBUFFER, pRenderTarge->FrameBuffer);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̎g�p�I���D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetEnd
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	(void)pRenderTarget;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

/*=============================================================================
*
* Purpose : �L���[�u�}�b�v�����_�[�^�[�Q�b�g�̎g�p�J�n�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetCubeBegin
(
	GSrendertarget*			pRenderTarge,	/* �����_�[�^�[�Q�b�g	  */
	GSuint					faceNo			/* �L���[�u�}�b�v�̖ʔԍ� */
)
{
	glBindFramebuffer(GL_FRAMEBUFFER, pRenderTarge->FrameBuffer);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + faceNo, pRenderTarge->ColorBuffers[0]->dwTexName, 0);
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBindColorBufferTexture
(
	GSrendertarget*			pRenderTarget,	/* �����_�[�^�[�Q�b�g	*/
	GSuint					no				/* �J���[�o�b�t�@�̔ԍ�	*/
)
{
	if (pRenderTarget->ColorBuffers[no] != NULL) {
		gsTextureBind(pRenderTarget->ColorBuffers[no]);
	}
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetBindDepthBufferTexture
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	if (pRenderTarget->DepthBuffer != NULL) {
		gsTextureBind(pRenderTarget->DepthBuffer);
	}
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃J���[�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetUnbindColorBufferTexture
(
	GSrendertarget*			pRenderTarget,	/* �����_�[�^�[�Q�b�g	*/
	GSuint					no				/* �J���[�o�b�t�@�̔ԍ�	*/
)
{
	if (pRenderTarget->ColorBuffers[no] != NULL) {
		gsTextureUnbind(pRenderTarget->ColorBuffers[no]);
	}
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�p�̃f�v�X�o�b�t�@�e�N�X�`�����A���o�C���h�D
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetUnbindDepthBufferTexture
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	if (pRenderTarget->DepthBuffer != NULL) {
		gsTextureUnbind(pRenderTarget->DepthBuffer);
	}
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDraw
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	(void)pRenderTarget;
	/* �r���[�|�[�g�S�̂ɕ`�� */
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(-1.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(-1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(1.0f, 1.0f);
	glEnd();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕`��
*
* Return  : �Ȃ��D
*
*============================================================================*/
extern void
gsRenderTargetDrawEx
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	const static GSvector2 vertices[4] = {
		{-1.0f, 1.0f}, {-1.0f, -1.0f}, {1.0f, -1.0f}, {1.0f, 1.0f}
	};
	const static GSvector2 texcoords[4] = {
		{ 0.0f, 1.0f}, {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}
	};
	(void)pRenderTarget;
	glPushAttrib(GL_ENABLE_BIT);
	glDisable(GL_DEPTH_TEST);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(8);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(8, 2, GL_FLOAT, GL_FALSE, 0, texcoords);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableVertexAttribArray(8);
	glDisableVertexAttribArray(0);
	glPopAttrib();
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̕����擾
*
* Return  : �����_�[�^�[�Q�b�g�̕���Ԃ��D
*
*============================================================================*/
extern GSuint
gsRenderTargetGetWidth
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	return pRenderTarget->Width;
}

/*=============================================================================
*
* Purpose : �����_�[�^�[�Q�b�g�̍������擾
*
* Return  : �����_�[�^�[�Q�b�g�̍�����Ԃ��D
*
*============================================================================*/
extern GSuint
gsRenderTargetGetHeight
(
	GSrendertarget*			pRenderTarget	/* �����_�[�^�[�Q�b�g	*/
)
{
	return pRenderTarget->Height;
}

/********** End of File ******************************************************/