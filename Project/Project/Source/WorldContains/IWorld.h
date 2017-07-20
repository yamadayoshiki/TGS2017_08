#ifndef IWORLD_H_ 
#define IWORLD_H_ 

#include <gslib.h>

#include "../ActorContains/ActorPtr.h"
#include "../ActorContains/ActorName.h"
#include "../Map/MapPtr.h"

enum class ActorGroup;
enum class EventMessage;
enum class SceneName;
class CharacterFactory;
namespace Body { class BodyFactory; }

// ���[���h���ۃC���^�[�t�F�[�X 
class IWorld
{
public:
	// ���z�f�X�g���N�^
	virtual ~IWorld() {	}
	// �A�N�^�[�̒ǉ�   
	virtual void addActor(ActorGroup group, const ActorPtr& actor) = 0;
	// �A�N�^�[�̌���     
	virtual ActorPtr findActor(const ActorName& name) = 0;
	//�C�ӂ̃A�N�^�[�O���[�v�ƏՓ˔���
	virtual void OptinalCollide(Actor* actor, ActorGroup actorGroup) = 0;
	// ���b�Z�[�W�̑��M    
	virtual void sendMessage(EventMessage message, void* param = nullptr) = 0;
	// ���b�Z�[�W�̑��M(�w��A�N�^�[)
	virtual void sendMessage(EventMessage message, Actor& actor, void* param = nullptr) = 0;
	// ���b�Z�[�W�̑��M(�w��A�N�^�[�̂�)
	virtual void sendMessageOne(EventMessage message, Actor& actor, void* param = nullptr) = 0;
	// �V�[���̏I��
	virtual void EndRequest(const SceneName& name) = 0;
	//�}�b�v�̎擾
	virtual MapPtr GetMap() = 0;
	//�L�����N�^�[�t�@�N�g���[�̎擾
	virtual CharacterFactory* GetCharacterFactory() const = 0;
	//�Փ˔���}�`�t�@�N�g���[�̎擾
	virtual Body::BodyFactory* GetBodyFactory() const = 0;
};

#endif