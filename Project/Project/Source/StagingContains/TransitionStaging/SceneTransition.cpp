#include "SceneTransition.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
// コンストラクタ
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager)
	: Transition(gameManager)
	, m_Color(1.0f, 1.0f, 1.0f, 1.0f)
	, m_DrawID(0) {
	// モードの追加
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 1.0f };
	//ブラックスクリーン追加
	m_DrawID = p_GameManager->GetDrawManager()->RegisterDefaultParam("black_screen", p_Param, DrawOrder::BlackScreen);
}

// デストラクタ
SceneTransition::~SceneTransition() {
	p_GameManager->GetDrawManager()->Remove(m_DrawID);
}

// 開始
void SceneTransition::onStart() {
	// パラメータの設定
	p_Param->m_Center = { 0.0f, 0.0f };
	p_Param->m_Color = m_Color;
}

//更新
void SceneTransition::onUpdate(float deltaTime) {
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime, 0.0f, 1.0f);
	p_Param->m_Color = m_Color;
}

//描画
void SceneTransition::onDraw() const {
}

bool SceneTransition::isEnd() {
	return p_Param->m_Color.a == mModeParametors[mMode].endValue && mMode == Mode::Out;
}