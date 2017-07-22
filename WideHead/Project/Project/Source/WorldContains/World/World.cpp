#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../EventMessage/EventMessage.h"
#include "../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"
#include "../../CharacterContains/Factory/CharacterFactory.h"
#include "../../ActorContains/BodyContains/Factory/BodyFactory.h"
#include <iostream>

// �R���X�g���N�^
World::World()
	: p_Actors(std::make_shared<ActorManager>())
	, m_IsEnd(false)
	, p_BodyFactory(std::make_unique<Body::BodyFactory>()) {
}

// �f�X�g���N�^
World::~World() {
	p_CharacterFactory.reset();
	p_BodyFactory.reset();
}

void World::SetUp(const IGameManagerPtr & gameManager) {
	p_Actors->SetUp(this, gameManager);
}

// �X�V
void World::update(float deltaTime) {
	p_Actors->update(deltaTime);
}

// �`��
void World::draw() const {
	p_Actors->draw();
}

// ���b�Z�[�W���� 
void World::handleMessage(EventMessage message, void* param) {
	// ���[���h�̃��b�Z�[�W���� 
	switch (message)
	{
	case EventMessage::END_SCENE:
		EndRequest((const SceneName&)param);
	default:
		break;
	}

	// �A�N�^�[�̃��b�Z�[�W����    
	p_Actors->handleMessage(message, param);
}

// �A�N�^�[�̒ǉ� 
void World::addActor(ActorGroup group, const ActorPtr& actor) {
	p_Actors->addActor(group, actor);
}

// �A�N�^�[�̌���
ActorPtr World::findActor(const ActorName& name) {
	return p_Actors->findActor(name);
}

//�C�ӂ̈�I�u�W�F�N�g���Փ˔���
void World::OptinalCollide(Actor* actor, ActorGroup actorGroup) {
	p_Actors->OptionalCollide(actor, actorGroup);
}

// ���b�Z�[�W�̑��M
void World::sendMessage(EventMessage message, void* param) {
	handleMessage(message, param);
}

// ���b�Z�[�W�̑��M(�w��A�N�^�[)
void World::sendMessage(EventMessage message, Actor& actor, void* param) {
	actor.handleMessage(message, param);
}

// ���b�Z�[�W�̑��M(�w��A�N�^�[�̂�)
void World::sendMessageOne(EventMessage message, Actor & actor, void * param) {
	actor.handleMessageOne(message, param);
}

//����
void World::generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name) {
	p_MapGenerator->load(file_name);
	p_MapGenerator->registMap();
	p_MapGenerator->generate();
}

//�}�b�v�̎擾
MapPtr World::GetMap() {
	return p_MapGenerator->getMap();
}

//�L�����N�^�[�H��̐ݒ�
void World::SetCharacterFactory(CharacterFactory * characterFactory) {
	p_CharacterFactory.reset(characterFactory);
}

//�L�����N�^�[�H��̎擾
CharacterFactory * World::GetCharacterFactory() const {
	return p_CharacterFactory.get();
}

//�Փ˔���}�`�t�@�N�g���[�̎擾
Body::BodyFactory * World::GetBodyFactory() const {
	return p_BodyFactory.get();
}

void World::SetMapGenerator(const IWorldPtr& world, const IGameManagerPtr& gameManager) {
	p_MapGenerator = std::make_shared<MapGenerator>(world, gameManager);
}

bool World::IsEnd() {
	return m_IsEnd;
}

void World::EndRequest(const SceneName & name) {
	m_NextScene = name;
	m_IsEnd = true;
}

void World::ResetEnd() {
	m_IsEnd = false;
}

SceneName World::NextScene() {
	return m_NextScene;
}

int World::GetSurviverSum() {
	return p_Actors->GetSurviverSum();
}