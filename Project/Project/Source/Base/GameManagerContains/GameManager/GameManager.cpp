#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"
#include"../../../Utility/EnumRap/EnumRap.h"

//�R���X�g���N�^
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState)
	:p_Renderer2D(renderer2D), p_InputState(inputState), p_SceneEnum(std::make_shared<EnumRap<SceneName>>()){
	m_Parameter.m_Remaining = 3;
}

//�R���e���c�̓ǂݍ���
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player_Close", "Resource/Texture/Player/jiki_close.png");
	p_Renderer2D->LoadTexture("Player_Open", "Resource/Texture/Player/jiki_open.png");
	p_Renderer2D->LoadTexture("Player_Clip", "Resource/Texture/Player/jiki_clip.png");

	p_Renderer2D->LoadTexture("Enemy01", "Resource/Texture/Enemys/Enemy1.png");
	p_Renderer2D->LoadTexture("Enemy03", "Resource/Texture/Enemys/Enemy3.png");
}

//�R���e���c�̍폜
void GameManager::UnLoadContent() {
	p_Renderer2D->Initialize();
}

//�X�V����
void GameManager::Update() {
	//���͏����X�V
	p_InputState->Update();
}

//�����_���[�̎擾
Renderer2DPtr GameManager::GetRenderer2D() {
	return p_Renderer2D;
}

//�C���v�b�g�X�e�C�g�̎擾
InputStatePtr GameManager::GetInputState() {
	return p_InputState;
}

//�V�[����Enum�̎擾
EnumRapPtr<SceneName> GameManager::GetSceneEnum(){
	return p_SceneEnum;
}

//�v���C���[�p�����[�^�[�̎擾
Player_Parameter& GameManager::GetPlayerParameter()
{
	return m_Parameter;
}
//�v���C���[�p�����[�^�[�̐ݒ�				
void GameManager::SetPlayerParameter(const Player_Parameter& parameter)
{
	m_Parameter = parameter;
}

//�I������
void GameManager::Finalize() {
	p_Renderer2D->Initialize();
}