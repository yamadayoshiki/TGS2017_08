#include <GL/GLAux.h>
#include <GL\GL.h>
#include <GL/GLU.h>
#include <gslib.h>

#include"GameFrame.h"
#include"../GameManagerContains/GameManager/GameManager.h"
#include"../../SceneContains/SceneName.h"
#include"../../SceneContains/GameTitle/GameTitle.h"
#include"../../SceneContains/GamePlay/GamePlay.h"
#include"../../SceneContains/NaganoScene/NaganoScene.h"
//#include"../../SceneContains/NakayamaScene/NakayamaScene.h"

//�R���X�g���N�^
GameFrame::GameFrame()
	:Game(1024, 768)
	,m_SceneManager()
{
	p_GameManager = std::make_shared<GameManager>(new Renderer2D());
	p_GameManager->LoadContent();
}

//�f�X�g���N�^
GameFrame::~GameFrame()
{
	p_GameManager->UnLoadContent();
}

//������
void GameFrame::start()
{
	m_SceneManager.Add(SceneName::GameTitle, std::make_shared<GameTitle>());
	m_SceneManager.Add(SceneName::GamePlay, std::make_shared<GamePlay>());
	m_SceneManager.Add(SceneName::NaganoScene, std::make_shared<NaganoScene>());
	//m_SceneManager.Add(SceneName::NakayamaScene, std::make_shared<NakayamaScene>());
	m_SceneManager.Change(SceneName::GameTitle);
}

// �X�V
void GameFrame::update(float time)
{
	m_SceneManager.Update(time);
}

// �`��
void GameFrame::draw()
{
	m_SceneManager.Draw();
}

// �I��
void GameFrame::end()
{
	m_SceneManager.End();
}

// ���s����
bool GameFrame::isRunning()
{
	return GetAsyncKeyState(VK_ESCAPE) == 0;
}