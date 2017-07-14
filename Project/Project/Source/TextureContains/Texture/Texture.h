#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"

class Texture :public Texture_Base
{
public:
	//コンストラクタ
	Texture(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//ループ回数の取得
	int GetLoopCount() override { return 0; }
};

#endif // !TEXTURE_H_
