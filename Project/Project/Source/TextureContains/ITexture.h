#ifndef ITEXTURE_H_
#define ITEXTURE_H_
#include "../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../DrawManager/DisplayMode.h"
struct GSvector2;
class ITexture
{
public:
	//仮想デストラクタ
	virtual ~ITexture() {}
	//初期化
	virtual void Initialize() = 0;
	//更新
	virtual void Update(float deltaTime) = 0;
	//パラメーターの取得
	virtual Texture2DParameterSPtr GetParameter() = 0;
	//ループ回数の取得
	virtual int GetLoopCount() = 0;
	//ストップ
	virtual void Stop() = 0;
	//リスタート
	virtual void Restart() = 0;
	//座標+回転の設定
	virtual void SetPosAndAngle(const GSvector2& pos, float angle) = 0;
	//表示モード切替
	virtual void ChangeDisplayMode(const DisplayMode mode) = 0;
};

#endif // !ITEXTURE_H_
