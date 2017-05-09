#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"

#include <gslib.h>
#include <memory>

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
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

	//ワールド生成
	//using WorldPtr = std::shared_ptr<World>;
	//WorldPtr p_World;
	p_World = std::make_shared<World>();

	p_World->ResetEnd();

	OnStart();
}

// 更新     
void Scene::Update(float deltaTime)
{
	//スペースキーを押したら次のシーン
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE || p_World->IsEnd()) {
		m_IsEnd = true;
	}
		
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

void Scene::End(){
	OnEnd();

	p_World = nullptr;
}

// 終了しているか？     
bool Scene::IsEnd() const
{
	return m_Transition->isEnd();
}

SceneName Scene::Next() const{
	return p_World->NextScene();
}

void Scene::SetName(const SceneName & name){
	m_SceneName = name;
}

SceneName Scene::GetName(){
	return m_SceneName;
}
