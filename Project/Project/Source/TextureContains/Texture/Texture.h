#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"
class GameManager;

class Texture :public Texture_Base
{
public:
	//コンストラクタ
	Texture(
		const std::string& texName,
		Renderer2D* renderer);
	//更新
	virtual void Update(float deltaTime) override;

protected:
	//各種固有の初期化
	virtual void OnInitialize() override;
	//各種固有の終了処理
	virtual void OnFinalize() override {}
};

#endif // !TEXTURE_H_
