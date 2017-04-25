#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include<gslib.h>

//�R���X�g���N�^
Scene::Scene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, p_World(world)
	{
}

// ���z�f�X�g���N�^     
Scene::~Scene() {
}

// �J�n     
void Scene::Start()
{
	m_IsEnd = false;
	OnStart();
}

// �X�V     
void Scene::Update(float deltaTime)
{
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE)
		m_IsEnd = true;

	

	OnUpdate(deltaTime);
}

// �I�����Ă��邩�H     
bool Scene::IsEnd() const
{
	return m_IsEnd;
}