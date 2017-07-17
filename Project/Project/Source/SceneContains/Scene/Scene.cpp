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

//�R���X�g���N�^
Scene::Scene(const IGameManagerPtr& gameManager)
	: m_IsEnd(false)
	, p_GameManager(gameManager)
	, m_Transition(std::make_shared<SceneTransition>(gameManager))
	, MapOrder(0) {
	isGameClear = false;
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
	//p_World->addActor(ActorGroup::UI, std::make_shared<UIManager>(p_World.get(), p_GameManager, m_SceneName));

	OnStart();
}

// �X�V     
void Scene::Update(float deltaTime)
{
	//���[���h���I������玟�̃V�[��
	if (p_World->IsEnd()) {
		m_IsEnd = true;
	}

	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
											  //*/
											  //�t���O�����������ʂ��~�܂�
	if (PauseFlag == false) {
		p_World->update(deltaTime);
	}
	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "world" << ":Update:" << elapsed << std::endl;
	//*/

	//���[���h���I����Ă��Ȃ�������e��ŗL�̍X�V
	if (p_World->IsEnd() != true) { OnUpdate(deltaTime); }

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
