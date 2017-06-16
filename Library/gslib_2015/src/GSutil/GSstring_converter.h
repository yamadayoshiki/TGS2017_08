/******************************************************************************
* File Name : GSstring_converter.h                            Ver : 1.00  Date : 2002-08-03
*
* Description :
*
*		�����R�[�h�ϊ� �w�b�_�t�@�C���D�D
*
* Author : Moriharu Ohzu.
*
******************************************************************************/
#ifndef	_GS_STRING_CONVERTER_H_
#define	_GS_STRING_CONVERTER_H_

#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

// UTF16��SJIS�ɕϊ� (�ϊ���̕�����͗vfree)
char* utf16_to_sjis(const wchar_t* utf16);

// SJIS��UTF16�ɕϊ� (�ϊ���̕�����͗vfree)
wchar_t* sjis_to_utf16(const char* sjis);

#ifdef __cplusplus
}
#endif

#endif

/********** End of File ******************************************************/
