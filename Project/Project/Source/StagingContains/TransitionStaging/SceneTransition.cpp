#include "SceneTransition.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

// コンストラクタ
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager):
	Transition(gameManager){
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 255.0f };


}

// デストラクタ
SceneTransition::~SceneTransition(){
}

// 開始     
void SceneTransition::onStart(){
	p_GameManager->GetRenderer2D()->LoadTexture("black_screen", "Resource/Texture/UI/black_screen.png");

	m_Param.SetPosition({ 0.0f, 0.0f });
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("black_screen"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Color.a = 1.0f;
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 0.0f, 0.0f });
	m_Param.SetRotate(0.0f);
}

//更新
void SceneTransition::onUpdate(float deltaTime){
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime * 60.0f, 0.0f, 255.0f);

	m_Param.SetColor(m_Color);

	m_IsEnd = m_Param.GetColor().a == mModeParametors[mMode].endValue;
}

//描画
void SceneTransition::onDraw() const{
	p_GameManager->GetRenderer2D()->DrawTexture("black_screen", m_Param);
}
