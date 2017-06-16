/******************************************************************************
* File Name : GSshader.c                         Ver : 1.00  Date : 2016-03-22
*
* Description :
*
*       �V�F�[�_�[ �w�b�_�t�@�C���D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef	_GS_SHADER_H_
#define	_GS_SHADER_H_

#include	"GStype.h"

/* GLSL�v���O���� */
typedef struct
{
	GLuint program;		/* GLSL�v���O�����@*/
} GSshaderProgram;

#ifdef __cplusplus
extern "C" {
#endif

/* �V�F�[�_�[�v���O�����̐��� */
GSshaderProgram* gsShaderProgramNew(void);

/* �V�F�[�_�[�v���O�����̍폜 */
void gsShaderProgramDelete(GSshaderProgram* program);

/* �V�F�[�_�[�̃R���p�C�� */
GSboolean gsShaderProgramCompleShader(GSshaderProgram* program, GLenum type, const char* fileName);

/* �V�F�[�_�[�̃����N */
GSboolean gsShaderProgramLinkShader(GSshaderProgram* program);

/* �v���O�����̊J�n */
void gsShaderProgramBegin(GSshaderProgram* program);

/* �v���O�����̏I�� */
void gsShaderProgramEnd(GSshaderProgram* program);

/* �V�F�[�_�[�p�����[�^�̎擾 */
GLint gsShaderProgramUniform(GSshaderProgram* program, const char* name);

/* UniformBlock�C���f�b�N�X�̎擾 */
GLint gsShaderProgramUniformBlock(GSshaderProgram* program, const char* name);

/* �A�g���r���[�g�̎擾 */
GLint gsShaderProgramAttribute(GSshaderProgram* program, const char* name);

/* �A�g���r���[�g�̐ݒ� */
void gsShaderBindAttribute(GSshaderProgram* program, GLuint index, const char* name);

/* �t���O�����g�f�[�^�̐ݒ� */
void gsShaderBindFragData(GSshaderProgram* program, GLuint color, const char* name);


#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
