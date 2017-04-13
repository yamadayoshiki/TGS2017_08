#ifndef ACTOR_MANAGER_H_ 
#define ACTOR_MANAGER_H_ 

#include "../Actor/Actor.h" 
#include <unordered_map> 

enum class ActorGroup;

// �A�N�^�[�}�l�[�W���[ 
class ActorManager {
public:
	// �R���X�g���N�^     
	ActorManager();
	// ������     
	void initialize();
	// �X�V     
	void update(float deltaTime);
	// �`��     
	void draw() const;
	// �A�N�^�[�̒ǉ�     
	void addActor(ActorGroup group, const ActorPtr& actor);
	// �A�N�^�[�̌���     
	ActorPtr findActor(const ActorName& name);
	// ���b�Z�[�W����     
	void handleMessage(EventMessage message, void* param);
	// �R�s�[�֎~     
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;
	//�C�ӂ̏Փ˔���
	void OptionalCollide(Actor* actor, ActorGroup actorGroup);

private:
	// �Փ˔���     
	void collide();

private:
	// ���[�g�m�[�h     
	Actor m_root;
	// �A�N�^�[�O���[�v     
	std::unordered_map<ActorGroup, ActorPtr> m_actors;
};

#endif