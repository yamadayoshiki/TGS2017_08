#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"
#include "../../UIContains/UIManager/Base/UIManager.h"
#include "../../ActorContains/ActorGroup.h"

#include <gslib.h>
#include <memory>

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, p_World(world)
	, m_Transition(std::make_shared<SceneTransition>(gameManager)){
}

// 仮想デストラクタ     
Scene::~Scene() {
}

// 開始     
void Scene::Start()
{
	m_IsEnd = false;
	// 遷移演出の開始
	m_Transition->start();
	// 遷移演出モードの切り替え
	m_Transition->changeMode(Transition::Mode::In);

	//// UIの生成
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World, p_GameManager, m_SceneName));	

	OnStart();
}

// 更新     
void Scene::Update(float deltaTime)
{
	//スペースキーを押したら次のシーン
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE || p_GameManager->IsEndScene())
		m_IsEnd = true;

	//ワールド更新
	p_World->update(deltaTime);

	//各種固有の更新
	OnUpdate(deltaTime);

	// 遷移演出の開始
	m_Transition->update(deltaTime);

	// 現在のシーンの終了条件がtrueになった場合
	if (m_IsEnd) m_Transition->changeMode(Transition::Mode::Out);
}

// 描画     
void Scene::Draw() const
{
	//ワールド描画
	p_World->draw();
	// 遷移演出の描画
	m_Transition->draw();
}

// 終了しているか？     
bool Scene::IsEnd() const
{
	return m_Transition->isEnd();
}

void Scene::SetName(const SceneName & name){
	m_SceneName = name;
}
