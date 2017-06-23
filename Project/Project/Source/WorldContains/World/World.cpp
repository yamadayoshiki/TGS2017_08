#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../EventMessage/EventMessage.h"
#include "../../CharacterContains/EnemyContains/Entity/Enemys/Base/EnemyBase.h"
#include "../../CharacterContains/Factory/CharacterFactory.h"
#include <iostream>

// �R���X�g���N�^
World::World()
	:p_Actors(std::make_shared<ActorManager>()),
	m_IsEnd(false),
	m_Target()
{
	m_Target[0] = ActorName::Enemy_05;
	m_Target[1] = ActorName::Enemy_05;
	m_Target[2] = ActorName::Enemy_06;
	m_Target[3] = ActorName::Enemy_09;
	m_Target[4] = ActorName::Enemy_05;
	m_Target[5] = ActorName::Enemy_05;
	m_Target[6] = ActorName::Enemy_05;
	m_Target[7] = ActorName::Enemy_08;
}

// �f�X�g���N�^
World::~World() {
	Finalize();
}

// �X�V
void World::update(float deltaTime) {
	p_Actors->update(deltaTime);
}

// �`��
void World::draw() const {
	p_Actors->draw();
}

//�I������
void World::Finalize() {
}

// ���b�Z�[�W���� 
void World::handleMessage(EventMessage message, void* param) {
	// ���[���h�̃��b�Z�[�W���� 
	switch (message)
	{
	case EventMessage::END_SCENE: EndRequest((const SceneName&)param);
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

//����
void World::generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name){
	p_MapGenerator->load(file_name);
	p_MapGenerator->registMap();
	p_MapGenerator->generate();
}

//�}�b�v�̎擾
MapPtr World::GetMap() {
	return p_MapGenerator->getMap();
}

//�L�����N�^�[�H��̐ݒ�
void World::SetCharacterFactory(CharacterFactory * characterFactory){
	p_CharacterFactory.reset(characterFactory);
}

//�L�����N�^�[�H��̎擾
CharacterFactory * World::GetCharacterFactory() const{
	return p_CharacterFactory.get();
}

void World::SetMapGenerator(const IWorldPtr& world, const IGameManagerPtr& gameManager){
	p_MapGenerator = std::make_shared<MapGenerator>(world,gameManager);
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

int World::GetSurviverSum(int mapOrder) {
	int sum = 0;
	/*findActor(ActorName::EnemyManager)->eachChildren([&](Actor& child) {
		EnemyBase* enemy = dynamic_cast<EnemyBase*>(&child);
		if (enemy->CanDead() && !enemy->GetHitPoint().IsDead()) { sum++; }
	});
	return sum;*/

	//����̓G��|�����玟�̃X�e�[�W�ɐi��
	findActor(ActorName::EnemyManager)->eachChildren([&](Actor& child)
	{
		if (child.getName() == m_Target[mapOrder])
		{
			EnemyBase* l_Enemy = dynamic_cast<EnemyBase*>(&child);
			if (l_Enemy->CanDead() && !l_Enemy->GetHitPoint().IsDead())
			{
				sum += 1;
			}
		}
		
	});
	
	return sum;
}