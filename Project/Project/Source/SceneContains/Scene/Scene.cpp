#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../UIContains/UIManager/UIManager.h"
#include"../../Utility/Sound/SoundName.h"
#include "ChildScene.h"

#include <chrono>
#include <gslib.h>
#include <memory>

Scene::Scene()
	: Scene(nullptr) {
}

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, m_Transition(std::make_shared<SceneTransition>(gameManager))
	, MapOrder(0) {
	isGameClear = false;
}

// 仮想デストラクタ     
Scene::~Scene() {
	p_World = nullptr;
}

// 開始     
void Scene::Start()
{

	m_IsEnd = false;
	// 遷移演出の開始
	m_Transition->start();
	// 遷移演出モードの切り替え
	m_Transition->changeMode(Transition::Mode::In);

	//ワールド生成
	p_World = std::make_shared<World>();

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

	/*
	std::chrono::system_clock::time_point  start, end; // 型は auto で可
	start = std::chrono::system_clock::now(); // 計測開始時間
											  //*/
											  //フラグがたったら画面が止まる
	if (PauseFlag == false) {
		p_World->update(deltaTime);
	}
	/*
	end = std::chrono::system_clock::now();  // 計測終了時間
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //処理に要した時間をミリ秒に変換
	std::cout << "world" << ":Update:" << elapsed << std::endl;
	//*/

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

	p_World = nullptr;
}

bool Scene::IsEnd() const
{
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
