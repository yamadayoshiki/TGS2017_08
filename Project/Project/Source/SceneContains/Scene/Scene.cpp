#include "Scene.h"
#include"../../WorldContains/World/World.h"

#include "../../Base/GameManagerContains/GameManager/GameManager.h"
#include "../../StagingContains/TransitionStaging/SceneTransition.h"
#include "../../ActorContains/ActorGroup.h"
#include "../../UIContains/UIManager/UIManager.h"


#include <gslib.h>
#include <memory>

//�R���X�g���N�^
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, m_Transition(std::make_shared<SceneTransition>(gameManager))
	,MapOrder(0){
	
}

// ���z�f�X�g���N�^     
Scene::~Scene() {
	p_World = nullptr;
}

// �J�n     
void Scene::Start()
{

	m_IsEnd = false;
	// �J�ډ��o�̊J�n
	m_Transition->start();
	// �J�ډ��o���[�h�̐؂�ւ�
	m_Transition->changeMode(Transition::Mode::In);

	//���[���h����
	p_World = std::make_shared<World>();

	// UI�̐���
	p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	OnStart();
}

// �X�V     
void Scene::Update(float deltaTime)
{
	//�X�y�[�X�L�[���������玟�̃V�[��
	if (gsGetKeyTrigger(GKEY_SPACE) == GS_TRUE  || p_World->IsEnd()) {
		m_IsEnd = true;
	}
		
	//�t���O�����������ʂ��~�܂�
	if (PauseFlag == false) {
		//deltaTime = 0;
		p_World->update(deltaTime);
	}
	//���[���h�X�V
	//p_World->update(deltaTime);

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
	OnDraw();

	//���[���h�`��
	p_World->draw();
	// �J�ډ��o�̕`��
	m_Transition->draw();
}

void Scene::End(){
	OnEnd();

	p_World = nullptr;
}

// �I�����Ă��邩�H     
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
