#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../EventMessage/EventMessage.h"

#include <iostream>

// �R���X�g���N�^
World::World()
	:p_Actors(std::make_shared<ActorManager>()),
	m_IsEnd(false){
}

// �f�X�g���N�^
World::~World() {
	Finalize();
}

// �X�V
void World::update(float deltaTime)
{
	p_Actors->update(deltaTime);
}

// �`��
void World::draw() const
{
	p_Actors->draw();
}

void World::Draw() const
{
	p_Actors->draw();
}

//�I������
void World::Finalize()
{
	
}

// ���b�Z�[�W���� 
void World::handleMessage(EventMessage message, void* param)
{
	// ���[���h�̃��b�Z�[�W���� 
	switch (message)
	{
	case EventMessage::END_SCENE : EndRequest((const SceneName&)param);
	default:
		break;
	}

	// �A�N�^�[�̃��b�Z�[�W����    
	p_Actors->handleMessage(message, param);
}

// �A�N�^�[�̒ǉ� 
void World::addActor(ActorGroup group, const ActorPtr& actor)
{
	p_Actors->addActor(group, actor);
}

// �A�N�^�[�̌���
ActorPtr World::findActor(const ActorName& name)
{
	return p_Actors->findActor(name);
}

//�C�ӂ̈�I�u�W�F�N�g���Փ˔���
void World::OptinalCollide(Actor* actor, ActorGroup actorGroup)
{
	p_Actors->OptionalCollide(actor, actorGroup);
}

// ���b�Z�[�W�̑��M
void World::sendMessage(EventMessage message, void* param)
{
	handleMessage(message, param);
}

void World::generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name)
{
	p_MapGenerator = std::make_shared<MapGenerator>(world, gameManager);
	p_MapGenerator->load(file_name);
	p_MapGenerator->registActor();
	p_MapGenerator->generate();

	p_MapGenerator->registMap();
}

Map & World::GetMap(){
	return p_MapGenerator->getMap();
}

bool World::IsEnd(){
	return m_IsEnd;
}

void World::EndRequest(const SceneName & name){
	m_NextScene = name;
	m_IsEnd = true;
}

void World::ResetEnd(){
	m_IsEnd = false;
}

SceneName World::NextScene(){
	return m_NextScene;
}

//Map& World::GetMap()
//{
//	return ;
//}

////�}�b�v�W�F�l���[�^�[�̐ݒ�
//void World::setMapGenerator(MapGenerator* mapGenerator) {
//	p_MapGenerator = mapGenerator;
//}