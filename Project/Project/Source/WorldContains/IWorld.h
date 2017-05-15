#ifndef IWORLD_H_ 
#define IWORLD_H_ 

#include <gslib.h>

#include "../ActorContains/ActorPtr.h"
#include "../ActorContains/ActorName.h"

enum class ActorGroup;
enum class EventMessage;
class Map;
class CharacterManager;

// ���[���h���ۃC���^�[�t�F�[�X 
class IWorld
{
public:
	// ���z�f�X�g���N�^
	virtual ~IWorld() {
		Finalize();
	}
	// �A�N�^�[�̒ǉ�   
	virtual void addActor(ActorGroup group, const ActorPtr& actor) = 0;
	// �A�N�^�[�̌���     
	virtual ActorPtr findActor(const ActorName& name) = 0;
	//�C�ӂ̃A�N�^�[�O���[�v�ƏՓ˔���
	virtual void OptinalCollide(Actor* actor, ActorGroup actorGroup) = 0;
	// ���b�Z�[�W�̑��M    
	virtual void sendMessage(EventMessage message, void* param = nullptr) = 0;
	//�L�����N�^�[�}�l�[�W���[�̎擾
	virtual CharacterManager* getCharacterManager() = 0;
	//�L�����N�^�[�}�l�[�W���[�̐ݒ�
	virtual void setCharacterManager(CharacterManager* characterManager) = 0;

	//virtual Map& GetMap() = 0;
protected:
	// �I������
	virtual void Finalize() {}
};

#endif