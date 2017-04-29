#include "SceneManager.h"
#include "../NullScene/NullScene.h"

// コンストラクタ     
SceneManager::SceneManager()
	:m_CurrentScene(std::make_shared<NullScene>())
{
}

// 初期化     
void SceneManager::Initialize()
{
	End();
	m_SceneDic.clear();
}

// 更新     
void SceneManager::Update(float deltaTime)
{
	m_CurrentScene->Update(deltaTime);
}

// 描画     
void SceneManager::Draw() const
{
	m_CurrentScene->Draw();
}

// 終了     
void SceneManager::End()
{
	m_CurrentScene->End();
	m_CurrentScene = std::make_shared<NullScene>();
}

// シーンの追加    
void SceneManager::Add(SceneName name, const IScenePtr& scene)
{
	m_SceneDic[name] = scene;
	m_SceneDic[name]->SetName(name);
}

// シーンの変更     
void SceneManager::Change(SceneName name)
{
	End();
	m_CurrentScene = m_SceneDic[name];
	m_CurrentScene->Start();
}