#include "Texture_Base.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

//コンストラクタ
Texture_Base::Texture_Base(
	const std::string& texName,
	Renderer2DPtr renderer)
	: m_TexName(texName)
	, p_Renderer(renderer)
	, p_Parameter(new Texture2DParameter()) {
}

//デフォルトコンストラクタ
Texture_Base::Texture_Base()
	:Texture_Base("", nullptr) {
}

//初期化
void Texture_Base::Initialize() {
	//画像サイズ通りのRectを設定
	p_Parameter->SetRect(*(p_Renderer->GetTextureRect(m_TexName)));

	//各種固有の初期化
	OnInitialize();
}

//描画
void Texture_Base::Draw() {
	p_Renderer->DrawTexture(m_TexName, *p_Parameter);
}

//終了処理
void Texture_Base::Finalize() {
	delete p_Parameter;
	OnFinalize();
}

//パラメーターの取得
Texture2DParameter* Texture_Base::GetParameter() {
	return p_Parameter;
}