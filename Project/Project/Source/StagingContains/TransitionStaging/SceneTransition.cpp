#include "SceneTransition.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../Utility/Rederer2D/Renderer2D.h"

#include "../../Define/Def_Nagano.h"
#include <gslib.h>

// �R���X�g���N�^
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager):
	Transition(gameManager), m_Color(1.0f, 1.0f, 1.0f, 1.0f){
	// ���[�h�̒ǉ�
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 1.0f };
}

// �f�X�g���N�^
SceneTransition::~SceneTransition(){
}

// �J�n     
void SceneTransition::onStart(){
	// �e�N�X�`���̃��[�h
	p_GameManager->GetRenderer2D()->LoadTexture("black_screen", "Resource/Texture/UI/black_screen.png");

	// �p�����[�^�̐ݒ�
	m_Param.SetPosition({ 0.0f, 0.0f });
	m_Param.SetRect(*p_GameManager->GetRenderer2D()->GetTextureRect("black_screen"));
	m_Param.SetCenter({ 0.0f, 0.0f });
	m_Param.SetColor(m_Color);
	m_Param.SetScale({ 1.0f, 1.0f });
	m_Param.SetRotate(0.0f);
}

//�X�V
void SceneTransition::onUpdate(float deltaTime){
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime, 0.0f, 1.0f);

	m_Param.SetColor(m_Color);
}

//�`��
void SceneTransition::onDraw() const{
	// ���摜�̕`��
	p_GameManager->GetRenderer2D()->DrawTexture("black_screen", m_Param);
}

bool SceneTransition::isEnd(){
	return m_Param.GetColor().a == mModeParametors[mMode].endValue && mMode == Mode::Out;
}
