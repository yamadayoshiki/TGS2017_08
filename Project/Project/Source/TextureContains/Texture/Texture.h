#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "../Base/Texture_Base.h"
class GameManager;

class Texture :public Texture_Base
{
public:
	//コンストラクタ
	Texture(
		std::string texName,
		IGameManagerPtr gameManager);
	//初期化
	virtual void Initialize() override;
	//更新
	virtual void Update(float deltaTime) override;
	//描画
	virtual void Draw() override;
	//終了
	virtual void Finalize() override;
};

#endif // !TEXTURE_H_
