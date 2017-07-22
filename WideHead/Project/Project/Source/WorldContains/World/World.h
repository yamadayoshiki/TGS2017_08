#ifndef WORLD_H_
#define WORLD_H_ 

#include "../IWorld.h" 
#include "../../ActorContains/ActorManager/ActorManager.h"
#include "../../ActorContains/ActorGroup.h"
#include"../../MapGenerator/MapGenerator.h"
#include "../../ActorContains/ActorPtr.h"
#include"../../Map/Map.h"

#include"../../ActorContains/ActorManager/ActorManagerPtr.h"
#include"../../MapGenerator/MapGeneratorPtr.h"
#include "../../CharacterContains/Factory/CharacterFactoryPtr.h"
#include "../../ActorContains/BodyContains/Factory/BodyFactoryPtr.h"

enum class EventMessage;
enum class SceneName;

// ���[���h�N���X
class World :public IWorld
{
public:
	// �R���X�g���N�^  
	World();
	// �f�X�g���N�^
	World::~World();
	// �Z�b�g�A�b�v
	void SetUp(const IGameManagerPtr& gameManager);
	// �X�V    
	void update(float deltaTime);
	// �`��     
	void draw() const;
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
	// ���b�Z�[�W�̑��M(�w��A�N�^�[+�q)
	virtual void sendMessage(EventMessage message, Actor& actor, void* param = nullptr) override;
	// ���b�Z�[�W�̑��M(�w��A�N�^�[�̂�)
	virtual void sendMessageOne(EventMessage message, Actor& actor, void* param = nullptr) override;

	//����
	void generate(const IWorldPtr world, const IGameManagerPtr& gameManager, const std::string& file_name);
	//�}�b�v�̎擾
	MapPtr GetMap() override;
	//�L�����N�^�[�H��̐ݒ�
	void SetCharacterFactory(CharacterFactory* characterFactory);
	//�L�����N�^�[�H��̎擾
	CharacterFactory* GetCharacterFactory() const override;
	//�Փ˔���}�`�t�@�N�g���[�̎擾
	Body::BodyFactory* GetBodyFactory() const override;
	//�}�b�v�W�F�l���[�^�[�̐���
	void SetMapGenerator(const IWorldPtr& world, const IGameManagerPtr& gameManager);

	// �V�[���̏I���̎擾
	virtual bool IsEnd();
	// �V�[���̏I��
	virtual void EndRequest(const SceneName& name) override;
	// �V�[���̏I��
	virtual void ResetEnd();
	// �V�[���̏I��
	virtual SceneName NextScene();
	// �����ڕW�G�̐��̎擾
	int GetSurviverSum();

	// �R�s�[�֎~  
	World(const World& other) = delete;
	World& operator = (const World& other) = delete;

private:
	ActorManagerPtr p_Actors;					//�A�N�^�[�Ǘ�
	MapGeneratorPtr p_MapGenerator;				//�}�b�v�����N���X
	SceneName m_NextScene;						//���̃V�[��
	bool m_IsEnd;								//�I�����Ă��邩
	CharacterFactoryUPtr p_CharacterFactory;	//�L�����N�^�[�H��
	Body::BodyFactoryUPtr p_BodyFactory;		//�Փ˔���}�`�t�@�N�g���[
};
#endif