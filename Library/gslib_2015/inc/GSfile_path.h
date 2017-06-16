/******************************************************************************
* File Name : GSfile_path.h                      Ver : 1.00  Date : 2016-06-07
*
* Description :
*
*		�t�@�C���p�X�̕����Ƒg�ݗ��� �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef	_GS_FILE_PATH_H_
#define	_GS_FILE_PATH_H_

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

// �t�@�C���p�X�̕���
void gsSplitPath(const char* path, char* drive, char* dir, char* fname, char* ext);

// �t�@�C���p�X�̑g�ݗ���
void gsMakePath(char* path, const char* drive, const char* dir, const char* fname, const char* ext);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
