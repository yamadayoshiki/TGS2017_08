#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <gwave.h>
enum SoundName;

//�T�E���h�Ǘ��N���X
class Sound
{
public:
	//�R���X�g���N�^
	Sound();
	//�f�X�g���N�^
	~Sound();
	
	//SE�ǂݍ���
	void LoadSE(
		const SoundName name,
		const std::string fileName,
		const int cnt = 1,
		const GWAVEFLAG type = GWAVE_DEFAULT);

	//BGM�ǂݍ���
	void LoadBGM(
		const SoundName name,
		const std::string fileName,
		const GWAVEFLAG type = GWAVE_DEFAULT);
	
	//�A�����[�h
	void UnLoad();
	
	//SE�Đ�
	void PlaySE(const SoundName name);

	//BGM�Đ�
	void PlayBGM();

	//BGM�ꎞ��~
	void StopBGM();

	//BGM�ĊJ
	void ReStartBGM();


};

#endif // !SOUND_H_
