#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <gwave.h>
enum SoundName;

//サウンド管理クラス
class Sound
{
public:
	//コンストラクタ
	Sound();
	//デストラクタ
	~Sound();
	
	//SE読み込み
	void LoadSE(
		const SoundName name,
		const std::string fileName,
		const int cnt = 1,
		const GWAVEFLAG type = GWAVE_DEFAULT);

	//BGM読み込み
	void LoadBGM(
		const SoundName name,
		const std::string fileName,
		const GWAVEFLAG type = GWAVE_DEFAULT);
	
	//アンロード
	void UnLoad();
	
	//SE再生
	void PlaySE(const SoundName name);

	//BGM再生
	void PlayBGM();

	//BGM一時停止
	void StopBGM();

	//BGM再開
	void ReStartBGM();


};

#endif // !SOUND_H_
