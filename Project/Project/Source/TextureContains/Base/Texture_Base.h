#ifndef TEXTURE_BASE_H_
#define TEXTURE_BASE_H_

#include "../ITexture.h"
#include <iostream>

#include "../../Utility/Rederer2D/Renderer2DPtr.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"

class Texture_Base :public ITexture
{
public:
	//コンストラクタ
	Texture_Base(
		const std::string& texName,
		Renderer2DPtr renderer);
	//デフォルトコンストラクタ
	Texture_Base();
	//仮想デストラクタ
	virtual ~Texture_Base() {
		Finalize();
	}
	//初期化
	virtual void Initialize() override;
	//更新
	virtual void Update(float deltaTime) override;
	//描画
	virtual void Draw() override;
	//終了
	void Finalize() override;
	//パラメーターの取得
	virtual Texture2DParameter* GetParameter() override;
	//コピー禁止
	Texture_Base(const Texture_Base& other) = delete;
	Texture_Base& operator = (const Texture_Base& other) = delete;

protected:
	//各種固有の初期化
	virtual void OnInitialize() {}
	//各種固有の終了処理
	virtual void OnFinalize() {}

protected:
	std::string m_TexName;				//登録名
	Renderer2DPtr p_Renderer;			//レンダラー
	Texture2DParameter* p_Parameter;	//パラメーター
};

#endif // !TEXTURE_BASE_H_
