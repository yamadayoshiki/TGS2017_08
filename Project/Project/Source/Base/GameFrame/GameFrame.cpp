#include <gslib.h>

#include"GameFrame.h"

#include"../GameManagerContains/GameManager/GameManager.h"
#include"../../Utility/Rederer2D/Renderer2D.h"
#include"../../Utility/InputState/InputState.h"
#include"../../Utility/EnumRap/EnumRap.h"

#include"../../SceneContains/SceneName.h"
#include"../../SceneContains/GameTitle/GameTitle.h"
#include"../../SceneContains/GameSelect/GameSelect.h"
#include"../../SceneContains/GamePlay/GamePlay.h"
#include"../../SceneContains/GameResult/GameResult.h"
#include"../../SceneContains/GameCredit/GameCredit.h"
#include"../../SceneContains/GameEnd/GameEnd.h"

#include"../../SceneContains/NaganoScene/NaganoScene.h"
#include"../../SceneContains/NakayamaScene/NakayamaScene.h"
#include"../../SceneContains/yamadaScene/yamadaScene.h"

#include "../../Define/Def_Nagano.h"
#include"../../WorldContains/World/World.h"

//�R���X�g���N�^
GameFrame::GameFrame() : Game(SCREEN_SIZE.x, SCREEN_SIZE.y)
	, m_SceneManager() {
	//�Q�[���}�l�[�W���[����
	p_GameManager = std::make_shared<GameManager>(
		std::make_shared<Renderer2D>(),
		std::make_shared<InputState>());

	//�R���e���c�̓ǂݍ���
	p_GameManager->LoadContent();
}

//�f�X�g���N�^
GameFrame::~GameFrame() {
	// �R���e���c�̍폜
	p_GameManager->UnLoadContent();
}

//������
void GameFrame::start(){
	// �V�[����string�Ή��̓o�^
	p_GameManager->GetSceneEnum()->AddEnum("GameTitle", SceneName::GameTitle);
	p_GameManager->GetSceneEnum()->AddEnum("GameSelect", SceneName::GameSelect);
	p_GameManager->GetSceneEnum()->AddEnum("GamePlay", SceneName::GamePlay);
	p_GameManager->GetSceneEnum()->AddEnum("GameResult", SceneName::GameResult);
	p_GameManager->GetSceneEnum()->AddEnum("GameCredit", SceneName::GameCredit);
	p_GameManager->GetSceneEnum()->AddEnum("GameEnd", SceneName::GameEnd);

	//�V�[���̒ǉ�
	m_SceneManager.Add(SceneName::GameTitle, std::make_shared<GameTitle>(p_GameManager));
	m_SceneManager.Add(SceneName::GameSelect, std::make_shared<GameSelect>(p_GameManager));
	m_SceneManager.Add(SceneName::GamePlay, std::make_shared<GamePlay>(p_GameManager));
	m_SceneManager.Add(SceneName::GameResult, std::make_shared<GameResult>(p_GameManager));
	m_SceneManager.Add(SceneName::GameCredit, std::make_shared<GameCredit>(p_GameManager));
	m_SceneManager.Add(SceneName::GameEnd, std::make_shared<GameEnd>(p_GameManager));

	//�����V�[���̐ݒ�
	m_SceneManager.Change(SceneName::GameTitle);
}

// �X�V
void GameFrame::update(float time)
{
	p_GameManager->Update();
	if (p_GameManager->GetInputState()->IsKeyState(VK_SPACE)) return;
	m_SceneManager.Update(time);
}

// �`��
void GameFrame::draw()
{
	m_SceneManager.Draw();
}

// �I��
void GameFrame::end(){
	m_SceneManager.End();
}

// ���s����
bool GameFrame::isRunning(){
	// End�V�[���łȂ��ꍇ�͎��s��
	return m_SceneManager.GetSceneName() != SceneName::GameEnd && GetAsyncKeyState(VK_ESCAPE) == 0;
}