#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_
#include <iostream>
#include "../ITexture.h"
#include "../../Utility/Texture2DParameter/Texture2DParameterPtr.h"
#include "../../DrawManager/DrawManagerPtr.h"
#include "../../DrawManager/DrawOrder.h"

class Texture_Base :public ITexture
{
public:
	//コンストラクタ
	Texture_Base(
		const std::string& texName,
		const DrawManagerSPtr& drawManager,
		const DrawOrder drawOrder);
	//デストラクタ
	~Texture_Base();
	//パラメーターの取得
	Texture2DParameterSPtr GetParameter() override;
	//コピー禁止
	Texture_Base(const Texture_Base& other) = delete;
	Texture_Base& operator = (const Texture_Base& other) = delete;

public:
	//初期化
	void Initialize() override;
	//更新
	void Update(float deltaTime) override;
	//ループ回数の取得
	virtual int GetLoopCount() override = 0;
	//ストップ
	void Stop()override;
	//リスタート
	void Restart()override;
	//座標+回転の設定
	void SetPosAndAngle(const GSvector2& pos, float angle)override;
	//表示モード切替
	void ChangeDisplayMode(const DisplayMode mode)override;
	//描画順序切替
	void ChangeDrawOredr(const DrawOrder drawOrder)override;

protected:
	//初期化
	virtual void OnInitialize() {}
	//更新
	virtual void OnUpdate(float deltaTime) {}

protected:
	std::string m_TexName;				//登録名
	Texture2DParameterSPtr p_Parameter;	//パラメーター
	int m_DrawOrderID;					//描画順序ID
	DrawManagerWPtr p_DrawManager;		//描画管理
	bool m_StopFlag;					//ストップフラグ
};

#endif // !TEXTURE_BASE_H_
