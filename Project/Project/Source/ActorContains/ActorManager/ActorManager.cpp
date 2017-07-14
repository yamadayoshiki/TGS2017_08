#include "ActorManager.h" 
#include "../Actor/Actor.h"
#include "../ActorGroup.h"
#include "../NullActor/NullActor.h"
#include <memory>
#include <chrono>

// �R���X�g���N�^ 
ActorManager::ActorManager() {
	p_Root = std::make_unique<Actor>();
	initialize();
}

// �f�X�g���N�^
ActorManager::~ActorManager() {
	m_actors.clear();
	p_Root->clearChildren();
}

// ������ 
void ActorManager::initialize() {
	m_actors[ActorGroup::None] = std::make_shared<Actor>();
	m_actors[ActorGroup::UI] = std::make_shared<Actor>();
	m_actors[ActorGroup::Effect] = std::make_shared<Actor>();
	m_actors[ActorGroup::Player] = std::make_shared<Actor>(ActorName::PlayerManager);
	m_actors[ActorGroup::Enemy] = std::make_shared<Actor>(ActorName::EnemyManager);
	// �`�揇�͉�����
	p_Root->clearChildren();
	p_Root->addChild(m_actors[ActorGroup::None]);
	p_Root->addChild(m_actors[ActorGroup::UI]);
	p_Root->addChild(m_actors[ActorGroup::Effect]);
	p_Root->addChild(m_actors[ActorGroup::Player]);
	p_Root->addChild(m_actors[ActorGroup::Enemy]);
}

// �X�V 
void ActorManager::update(float deltaTime) {
	p_Root->update(deltaTime);
	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
	//*/
	collide();
	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << "ActorMagr" << ":Collide:" << elapsed << std::endl;
	//*/
	p_Root->LateUpdate();
	p_Root->removeChildren();
}

// �`�� 
void ActorManager::draw() const {
	p_Root->draw();
}

// �A�N�^�[�̒ǉ� 
void ActorManager::addActor(ActorGroup group, const ActorPtr& actor) {
	//������
	actor->initialize();
	//�ǉ�
	m_actors[group]->addChild(actor);
}

// �A�N�^�[�̌��� 
ActorPtr ActorManager::findActor(const ActorName& name) {
	return p_Root->findChildren_NullActor(name);
}

// ���b�Z�[�W���� 
void ActorManager::handleMessage(EventMessage message, void* param) {
	p_Root->handleMessage(message, param);
}

int ActorManager::getCount(ActorGroup group) const {
	return m_actors.at(group)->getCount();
}

//�C�ӂ̏Փ˔���
void ActorManager::OptionalCollide(Actor* actor, ActorGroup actorGroup) {
	actor->collideChildren(*m_actors[actorGroup]);
}

// �Փ˔��� 
void ActorManager::collide() {
	m_actors[ActorGroup::Player]->collideChildren(*m_actors[ActorGroup::Enemy]);
}