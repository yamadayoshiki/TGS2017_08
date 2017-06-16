#include <Windows.h>
#include <stdlib.h>

// UTF16��SJIS�ɕϊ�
char* utf16_to_sjis(const wchar_t* utf16) {
	// ShiftJIS�֕ϊ���̕����񒷂𓾂�
	const int length = WideCharToMultiByte(CP_ACP, 0, utf16, wcslen(utf16), NULL, 0, NULL, NULL);
	// �K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
	char* result = malloc(length + 1);
	if (result != NULL) {
		result[length] = '\0';
		// Unicode����ShiftJIS�֕ϊ�
		WideCharToMultiByte(CP_ACP, 0, utf16, wcslen(utf16), result, length, NULL, NULL);
	}
	return result;
}

// SJIS��UTF16�ɕϊ�
wchar_t* sjis_to_utf16(const char* sjis) {
	// Shift-JIS�����񂩂�UTF-16�ɕϊ������Ƃ��̕����񒷂����߂�
	const int length = MultiByteToWideChar(CP_ACP, 0, sjis, strlen(sjis), NULL, 0);
	// UTF-16������̗̈���m�ۂ���B
	wchar_t* result = malloc(length * 2 + 2);
	if (result != NULL) {
		// \0����
		result[length] = '\0';
		// Shift-JIS�����񂩂�UTF-16�ɕϊ�����B
		MultiByteToWideChar(CP_ACP, 0, sjis, strlen(sjis), result, length);
	}
	return result;
}
