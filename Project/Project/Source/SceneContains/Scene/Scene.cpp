#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"
#include "../../UIContains/UIManager/Base/UIManager.h"
#include "../../ActorContains/ActorGroup.h"

#include <gslib.h>
#include <memory>

//�R���X�g���N�^
Scene::Scene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, p_World(world)
	, m_Transition(std::make_shared<SceneTransition>(gameManager)){
}

// ���z�f�X�g���N�^     
Scene::~Scene() {
}

// �J�n     
void Scene::Start()
{
	m_IsEnd = false;
	// �J�ډ��o�̊J�n
	m_Transition->start();
	// �J�ډ��o���[�h�̐؂�ւ�
	m_Transition->changeMode(Transition::Mode::In);

	//// UI�̐���
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World, p_GameManager, m_SceneName));	

	OnStart();
}

// �X�V     
void Scene::Update(float deltaTime)
{
	//�X�y�[�X�L�[���������玟�̃V�[��
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE || p_GameManager->IsEndScene())
		m_IsEnd = true;

	//���[���h�X�V
	p_World->update(deltaTime);

	//�e��ŗL�̍X�V
	OnUpdate(deltaTime);

	// �J�ډ��o�̊J�n
	m_Transition->update(deltaTime);

	// ���݂̃V�[���̏I��������true�ɂȂ����ꍇ
	if (m_IsEnd) m_Transition->changeMode(Transition::Mode::Out);
}

// �`��     
void Scene::Draw() const
{
	//���[���h�`��
	p_World->draw();
	// �J�ډ��o�̕`��
	m_Transition->draw();
}

// �I�����Ă��邩�H     
bool Scene::IsEnd() const
{
	return m_Transition->isEnd();
}

void Scene::SetName(const SceneName & name){
	m_SceneName = name;
}
