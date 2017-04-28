#ifndef WORLD_H_
#define WORLD_H_ 

#include "../IWorld.h" 
#include "../../ActorContains/ActorManager/ActorManager.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../ActorContains/ActorPtr.h"
#include"../../Map/Map.h"

#include"../../ActorContains/ActorManager/ActorManagerPtr.h"
#include"../../MapGenerator/MapGeneratorPtr.h"
enum class EventMessage;

// ���[���h�N���X
class World :public IWorld
{
public:
	// �R���X�g���N�^  
	World();
	// �f�X�g���N�^
	World::~World();
	// �X�V    
	void update(float deltaTime);
	// �`��     
	void draw() const;
	// �`��
	void Draw() const;
	//�I������
	void Finalize() override;
	// ���b�Z�[�W����  
	void handleMessage(EventMessage message, void* param);
	// �A�N�^�[�̒ǉ�   
	virtual void addActor(ActorGroup group, const ActorPtr& actor) override;
	// �A�N�^�[�̌���    
	virtual ActorPtr findActor(const ActorName& name) override;
	// �A�N�^�[�ƔC�ӂ̏Փ˔���
	virtual void OptinalCollide(Actor* actor, ActorGroup actorGroup) override;
	// ���b�Z�[�W�̑��M    
	virtual void sendMessage(EventMessage message, void* param = nullptr) override;


	//����
	void generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name);
	//�}�b�v�̎擾
	Map& GetMap();
	////�}�b�v�W�F�l���[�^�[�̐ݒ�
	//void setMapGenerator(MapGenerator* mapGenerator);


	// �R�s�[�֎~  
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	// �A�N�^�[�}�l�[�W���[
	ActorManagerPtr p_Actors;
	//�}�b�v�W�F�l���[�^
	MapGeneratorPtr p_MapGenerator;

	
};
#endif