#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include<gslib.h>

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, p_World(world)
	{
}

// 仮想デストラクタ     
Scene::~Scene() {
}

// 開始     
void Scene::Start()
{
	m_IsEnd = false;
	OnStart();
}

// 更新     
void Scene::Update(float deltaTime)
{
	//スペースキーを押したら次のシーン
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE)
		m_IsEnd = true;

	//ワールド更新
	p_World->update(deltaTime);

	//各種固有の更新
	OnUpdate(deltaTime);
}

// 描画     
void Scene::Draw() const
{
	//ワールド描画
	p_World->draw();
}

// 終了しているか？     
bool Scene::IsEnd() const
{
	return m_IsEnd;
}