#include"GameManager.h"
#include"../../../Utility/Rederer2D/Renderer2D.h"
#include"../../../Utility/InputState/InputState.h"

//�R���X�g���N�^
GameManager::GameManager(const Renderer2DPtr& renderer2D, const InputStatePtr& inputState)
	:p_Renderer2D(renderer2D), p_InputState(inputState) {
}

//�R���e���c�̓ǂݍ���
void GameManager::LoadContent() {
	p_Renderer2D->LoadTexture("Player", "Resource/white.png");
}

//�R���e���c�̍폜
void GameManager::UnLoadContent() {
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

//�I������
void GameManager::Finalize() {
}