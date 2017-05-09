#include "SceneTransition.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

// コンストラクタ
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager):
	Transition(gameManager), m_Color(1.0f, 1.0f, 1.0f, 1.0f){
	// モードの追加
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 1.0f };
}

// デストラクタ
SceneTransition::~SceneTransition(){
}

// 開始     
void SceneTransition::onStart(){
	// テクスチャのロード
	p_GameManager->GetRenderer2D()->LoadTexture("black_screen", "Resource/Texture/UI/black_screen.png");

	// パラメータの設定
	m_Param.SetPosition({ 0.0f, 0.0f });
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("black_screen"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//更新
void SceneTransition::onUpdate(float deltaTime){
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime, 0.0f, 1.0f);

	m_Param.SetColor(m_Color);
}

//描画
void SceneTransition::onDraw() const{
	// 黒画像の描画
	p_GameManager->GetRenderer2D()->DrawTexture("black_screen", m_Param);
}

bool SceneTransition::isEnd(){
	return m_Param.GetColor().a == mModeParametors[mMode].endValue && mMode == Mode::Out;
}
