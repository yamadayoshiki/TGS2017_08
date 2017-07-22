#include "SceneTransition.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include "../../TextureContains/Texture/Texture.h"
// コンストラクタ
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager)
	: Transition(gameManager)
	, m_Color(1.0f, 1.0f, 1.0f, 1.0f)
	, p_Texture(std::make_shared<Texture>("black_screen", gameManager->GetDrawManager(), DrawOrder::BlackScreen)) {
	p_Texture->GetParameter()->m_Center = { 0.0f, 0.0f };
	p_Texture->GetParameter()->m_Position = { 0.0f, 0.0f };
	// モードの追加
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 1.0f };

	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

// デストラクタ
SceneTransition::~SceneTransition() {
	p_Texture.reset();
}

// 開始
void SceneTransition::onStart() {
	// パラメータの設定
	p_Texture->GetParameter()->m_Color = m_Color;

	p_Texture->ChangeDisplayMode(DisplayMode::Display);
}

//更新
void SceneTransition::onUpdate(float deltaTime) {
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime, 0.0f, 1.0f);
	p_Texture->GetParameter()->m_Color = m_Color;
}

//描画
void SceneTransition::onDraw() const {
}

void SceneTransition::onEnd() {
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
}

bool SceneTransition::isEnd() {
	return p_Texture->GetParameter()->m_Color.a == mModeParametors[mMode].endValue && mMode == Mode::Out;
}