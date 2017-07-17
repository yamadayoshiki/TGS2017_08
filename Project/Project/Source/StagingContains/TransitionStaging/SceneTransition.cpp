#include "SceneTransition.h"
#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../DrawManager/DrawManager.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../Define/Def_Nagano.h"
#include "../../TextureContains/Texture/Texture.h"
// �R���X�g���N�^
SceneTransition::SceneTransition(const IGameManagerPtr& gameManager)
	: Transition(gameManager)
	, m_Color(1.0f, 1.0f, 1.0f, 1.0f)
	, p_Texture(std::make_unique<Texture>("black_screen", p_GameManager->GetDrawManager(), DrawOrder::BlackScreen)) {
	p_Texture->GetParameter()->m_Center = { 0.0f, 0.0f };
	p_Texture->GetParameter()->m_Position = { 0.0f, 0.0f };
	// ���[�h�̒ǉ�
	mModeParametors[Mode::In] = { MINUS * FADE_SPEED, 0.0f };
	mModeParametors[Mode::Out] = { PLUS * FADE_SPEED, 1.0f };
}

// �f�X�g���N�^
SceneTransition::~SceneTransition() {
	p_Texture.reset();
}

// �J�n
void SceneTransition::onStart() {
	// �p�����[�^�̐ݒ�
	p_Texture->GetParameter()->m_Color = m_Color;
}

//�X�V
void SceneTransition::onUpdate(float deltaTime) {
	m_Color.a = CLAMP(m_Color.a + mModeParametors[mMode].value * deltaTime, 0.0f, 1.0f);
	p_Texture->GetParameter()->m_Color = m_Color;
}

//�`��
void SceneTransition::onDraw() const {
}

bool SceneTransition::isEnd() {
	return p_Texture->GetParameter()->m_Color.a == mModeParametors[mMode].endValue && mMode == Mode::Out;
}