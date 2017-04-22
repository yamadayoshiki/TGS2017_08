#include "Scene.h"

#include<gslib.h>

//コンストラクタ
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager) {
}

//デフォルトコンストラクタ
Scene::Scene()
	: Scene(nullptr) {
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
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE)
		m_IsEnd = true;

	OnUpdate(deltaTime);
}

// 終了しているか？     
bool Scene::IsEnd() const
{
	return m_IsEnd;
}