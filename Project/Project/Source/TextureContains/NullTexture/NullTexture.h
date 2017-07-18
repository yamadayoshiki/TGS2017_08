#ifndef NULLTEXTURE_H_
#define NULLTEXTURE_H_
#include "../ITexture.h"
//空の実装
class NullTexture :public ITexture
{
public:
	//デフォルトコンストラクタ
	NullTexture() {}
	//初期化
	void Initialize() override {}
	//更新
	void Update(float deltaTime) override {}
	//パラメーターの取得
	Texture2DParameterSPtr GetParameter() override { return nullptr; }
	//ループ回数の取得
	int GetLoopCount() override { return 0; }
	//ストップ
	void Stop()override {}
	//リスタート
	void Restart()override {}
	//座標+回転の設定
	void SetPosAndAngle(const GSvector2& pos, float angle)override {};
	//表示モード切替
	void ChangeDisplayMode(const DisplayMode mode)override {}
};
#endif // !NULLTEXTURE_H_