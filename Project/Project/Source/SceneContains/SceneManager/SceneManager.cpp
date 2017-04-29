#include "SceneManager.h"
#include "../NullScene/NullScene.h"

// �R���X�g���N�^     
SceneManager::SceneManager()
	:m_CurrentScene(std::make_shared<NullScene>())
{
}

// ������     
void SceneManager::Initialize()
{
	End();
	m_SceneDic.clear();
}

// �X�V     
void SceneManager::Update(float deltaTime)
{
	m_CurrentScene->Update(deltaTime);
}

// �`��     
void SceneManager::Draw() const
{
	m_CurrentScene->Draw();
}

// �I��     
void SceneManager::End()
{
	m_CurrentScene->End();
	m_CurrentScene = std::make_shared<NullScene>();
}

// �V�[���̒ǉ�    
void SceneManager::Add(SceneName name, const IScenePtr& scene)
{
	m_SceneDic[name] = scene;
	m_SceneDic[name]->SetName(name);
}

// �V�[���̕ύX     
void SceneManager::Change(SceneName name)
{
	End();
	m_CurrentScene = m_SceneDic[name];
	m_CurrentScene->Start();
}