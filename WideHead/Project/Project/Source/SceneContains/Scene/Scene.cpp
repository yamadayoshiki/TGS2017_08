#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../UIContains/UIManager/UIManager.h"
#include"../../Utility/Sound/SoundName.h"
#include "../../WorldContains/EventMessage/EventMessage.h"
#include "ChildScene.h"

#include <chrono>
#include <gslib.h>
#include <memory>

Scene::Scene()
	: m_IsEnd(false)
	, p_GameManager(nullptr)
	, p_World(nullptr)
	, m_SceneName(SceneName::None)
	, m_Transition(nullptr)
	, MapOrder(0)
	, isGameClear(false) {
	m_Brothers.clear();
}

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, p_World(nullptr)
	, m_SceneName(SceneName::None)
	, m_Transition(std::make_shared<SceneTransition>(gameManager))
	, MapOrder(0)
	, isGameClear(false) {
}

// 仮想デストラクタ     
Scene::~Scene() {
	p_World = nullptr;
}

// 開始     
void Scene::Start() {
	m_IsEnd = false;
	PauseFlag = false;
	// 遷移演出の開始
	m_Transition->start();
	// 遷移演出モードの切り替え
	m_Transition->changeMode(Transition::Mode::In);

	//ワールド生成
	p_World = std::make_shared<World>();
	p_World->SetUp(p_GameManager);

	// UIの生成
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	OnStart();
}

// 更新     
void Scene::Update(float deltaTime)
{
	//ワールドが終わったら次のシーン
	if (p_World->IsEnd()) {
		m_IsEnd = true;
	}

	//ポーズでないなら更新
	if (PauseFlag == false) {
		p_World->update(deltaTime);
	}

	//ワールドが終わっていなかったら各種固有の更新
	if (p_World->IsEnd() != true) { OnUpdate(deltaTime); }

	// 遷移演出の開始
	m_Transition->update(deltaTime);

	// 現在のシーンの終了条件がtrueになった場合
	if (m_IsEnd) m_Transition->changeMode(Transition::Mode::Out);
}

// 描画     
void Scene::Draw() const
{
	OnDraw();

	//ワールド描画
	p_World->draw();
	// 遷移演出の描画
	m_Transition->draw();
}

void Scene::End() {
	OnEnd();
	m_Transition->end();
	p_World = nullptr;
}

bool Scene::IsEnd() const {
	return m_Transition->isEnd();
}

SceneName Scene::Next() const {
	return p_World->NextScene();
}

void Scene::SetName(const SceneName & name) {
	m_SceneName = name;
}

SceneName Scene::GetName() {
	return m_SceneName;
}

void Scene::SetUpChild(ChildScene & child) {
	child.SetParent(shared_from_this());
	child.m_IsEnd = m_IsEnd;
	child.p_GameManager = p_GameManager;
	child.p_World = p_World;
	child.MapOrder = MapOrder;
}

//メッセージ処理
void Scene::HandleMessage(EventMessage message, void * param) {
	switch (message)
	{
	case EventMessage::END_SCENE:
		p_World->EndRequest((const SceneName&)param);
	}
}

void Scene::StopWorld() {
	PauseFlag = true;
}

void Scene::Restart() {
	PauseFlag = false;
}

void Scene::SetBrothers(const std::vector<SceneName>& children) {
	m_Brothers.clear();
	for (auto itr = children.begin(); itr != children.end(); itr++)
		m_Brothers.push_back(*itr);
}

bool Scene::IsExistBrother(const SceneName name) {
	for (auto itr = m_Brothers.begin(); itr != m_Brothers.end(); itr++) {
		if (*itr == name)
			return true;
	}

	return false;
}
