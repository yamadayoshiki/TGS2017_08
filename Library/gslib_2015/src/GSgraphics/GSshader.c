/******************************************************************************
* File Name : GSshader.c                         Ver : 1.00  Date : 2016-03-22
*
* Description :
*
*       �V�F�[�_�[�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#include "GSshader.h"
#include "heap.h"
#include <stdio.h>
#include <opengl_ext.h>
#include <assert.h>

/* GLSL�V�F�[�_�[�\���� */
typedef struct
{
	GLenum Type;		/* �V�F�[�_�[�^�C�v */
	GLuint Shader;		/* �V�F�[�_�[		*/
} GSshader;

static GSshader* gsShaderNew(GLenum type);
static void gsShaderDelete(GSshader* shader);
static GLint gsShaderComplie(GSshader* shader, const char* fileName);

/* �V�F�[�_�[�v���O�����̐��� */
GSshaderProgram* gsShaderProgramNew(void) {
	GSshaderProgram* program;
	program = new_object(sizeof(GSshaderProgram));
	program->program = glCreateProgram();
	return program;
}

/* �V�F�[�_�[�v���O�����̍폜 */
void gsShaderProgramDelete(GSshaderProgram* program) {
	glDeleteProgram(program->program);
	del_object(program);
}

/* �V�F�[�_�[�̃R���p�C�� */
GSboolean gsShaderProgramCompleShader(GSshaderProgram* program, GLenum type, const char* fileName) {
	// �V�F�[�_�[�̍쐬
	GSshader* shader;
	GLint compled;
	shader = gsShaderNew(type);
	compled = gsShaderComplie(shader, fileName);
	if (compled == GL_FALSE) {
		gsShaderDelete(shader);
		return GS_FALSE;
	}
	// �V�F�[�_�[���A�^�b�`
	glAttachShader(program->program, shader->Shader);
	gsShaderDelete(shader);
	return GS_TRUE;
}

/* �V�F�[�_�[�̃����N */
GSboolean gsShaderProgramLinkShader(GSshaderProgram* program) {
	// �V�F�[�_�[�̃����N
	glLinkProgram(program->program);
	// �����N�G���[�̊m�F
	GLint linked = 0;
	glGetProgramiv(program->program, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		// �R���p�C���G���[���o��
		GLint length = 0;
		GLchar* log = NULL;
		glGetProgramiv(program->program, GL_INFO_LOG_LENGTH, &length);
		log = new_object(length);
		glGetProgramInfoLog(program->program, length, 0, log);
		OutputDebugStringA("glsl link error\n");
		OutputDebugStringA(log);
		del_object(log);
		assert(!"glsl link error");
		return GS_FALSE;
	}
	return GS_TRUE;
}

/* �v���O�����̊J�n */
void gsShaderProgramBegin(GSshaderProgram* program) {
	glUseProgram(program->program);
}

/* �v���O�����̏I�� */
void gsShaderProgramEnd(GSshaderProgram* program) {
	(void)program;
	glUseProgram(0);
}

/* �V�F�[�_�[�p�����[�^�̎擾 */
GLint gsShaderProgramUniform(GSshaderProgram* program, const char* name) {
	return glGetUniformLocation(program->program, name);
}

/* UniformBlock�C���f�b�N�X�̎擾 */
GLint gsShaderProgramUniformBlock(GSshaderProgram* program, const char* name) {
	return glGetUniformBlockIndex(program->program, name);
}

/* �A�g���r���[�g�̎擾 */
GLint gsShaderProgramAttribute(GSshaderProgram* program, const char* name) {
	return glGetAttribLocation(program->program, name);
}

/* �A�g���r���[�g�̐ݒ� */
void gsShaderBindAttribute(GSshaderProgram* program, GLuint index, const char* name) {
	glBindAttribLocation(program->program, index, name);
}

/* �t���O�����g�f�[�^�̐ݒ� */
void gsShaderBindFragData(GSshaderProgram* program, GLuint color, const char* name) {
	glBindFragDataLocation(program->program, color, name);
}

// �V�F�[�_�[�t�@�C���̓ǂݍ���
static GLint gsShaderLoadFile(const char* fileName, GLchar** program, GLint* length) {
	FILE*	fp;
	if ((fp = fopen(fileName, "rb")) == NULL) {
		OutputDebugStringA("�V�F�[�_�[�t�@�C�����J���܂���!\n");
		OutputDebugStringA(fileName);
		OutputDebugStringA("\n");
		assert(!"file open error");
		return GL_FALSE;
	}
	fseek(fp,0, SEEK_END);
	*length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	*program = new_object(*length);
	fread(*program, sizeof(char), *length, fp);
	fclose(fp);
	return GL_TRUE;
}

// �V�F�[�_�[�̐���
static GSshader* gsShaderNew(GLenum type) {
	GSshader* shader;
	shader = new_object(sizeof(GSshader));
	shader->Type = type;
	shader->Shader = glCreateShader(type);
	return shader;
}

// �V�F�[�_�[�̍폜
static void gsShaderDelete(GSshader* shader) {
	glDeleteShader(shader->Shader);
	del_object(shader);
}

// �V�F�[�_�[�̃R���p�C��
static GLint gsShaderComplie(GSshader* shader, const char* fileName) {
	GLchar* program;
	GLint	length;
	GLint	compiled;
	GLint	error;
	/* �V�F�[�_�[�̃R���p�C�� */
	error = gsShaderLoadFile(fileName, &program, &length);
	if (error == GL_FALSE) return GL_FALSE;
	glShaderSource(shader->Shader, 1, &program, &length);
	glCompileShader(shader->Shader);
	del_object(program);
	/* �R���p�C���G���[�̃`�F�b�N */
	glGetShaderiv(shader->Shader, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		// �R���p�C���G���[���o��
		GLchar* log = NULL;
		glGetShaderiv(shader->Shader, GL_INFO_LOG_LENGTH, &length);
		log = new_object(length);
		glGetShaderInfoLog(shader->Shader, length, 0, log);
		glDeleteShader(shader->Shader);
		shader->Shader = 0;
		OutputDebugStringA("glsl compile error\n");
		OutputDebugStringA(fileName);
		OutputDebugStringA("\n");
		OutputDebugStringA(log);
		del_object(log);
		assert(!"glsl compile error");
		return GL_FALSE;
	}
	return GL_TRUE;
}

/********** End of File ******************************************************/
