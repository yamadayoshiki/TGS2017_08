#ifndef ICHARACTERMANAGER_H_
#define ICHARACTERMANAGER_H_

#include "../../ActorContains/ActorPtr.h"

struct GSvector2;
struct GSmatrix4;
enum class PlayerStateName;

class ICharacterManager
{
public:
	//���z�f�X�g���N�^
	~ICharacterManager() {}
	//�v���C���[�̍��W���擾
	virtual GSvector2 GetPlayerPos() = 0;
	//�v���C���[�̍s����擾
	//virtual GSmatrix4 GetPlayerMat() = 0;
	//�v���C���[�ɋ��܂�Ă���Actor���擾
	virtual ActorPtr GetRoundActor() = 0;
	//�v���C���[�̃X�e�[�g���擾
	virtual PlayerStateName GetPlayerStateName() = 0;
	//�v���C���[�̋��܂�Ă���Actor��ݒ�
	virtual void SetRoundActor(const Actor& actor) = 0;
};

#endif // !CHARACTERMANAGER_H_
