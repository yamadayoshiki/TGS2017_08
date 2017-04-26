#include "World.h" 
#include"../../Define/Def_Nakayama.h"
#include"../../FileReader/CsvReader.h"
#include"../../Map/Map.h"

#include <iostream>

// �R���X�g���N�^
World::World()
	:p_Actors(new ActorManager())
	, m_Map(Map())
{
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

void World::generate()
{
	p_MapGenerator->load("Resource/StreamingAssets/stage1.csv");
	p_MapGenerator->registActor();
	p_MapGenerator->registMap(m_Map);
	p_MapGenerator->generate();
}

//�I������
void World::Finalize()
{
	delete p_Actors;
}

// ���b�Z�[�W���� 
void World::handleMessage(EventMessage message, void* param)
{
	// ���[���h�̃��b�Z�[�W���� 

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

//Map& World::GetMap()
//{
//	return ;
//}

//�}�b�v�W�F�l���[�^�[�̐ݒ�
void World::setMapGenerator(MapGenerator* mapGenerator) {
	p_MapGenerator = mapGenerator;
}