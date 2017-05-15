#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "../ICharacterManager.h"
#include "../../PlayerContains/Player/Player.h"

#include <vector>

class CharacterManager : public ICharacterManager
{
public:
	//�R���X�g���N�^
	CharacterManager();
	//�f�X�g���N�^
	~CharacterManager();
	//�v���C���[�̍��W���擾
	GSvector2 GetPlayerPos() override;
	//�v���C���[�̍s����擾
	//GSmatrix4 GetPlayerMat() override;
	//�v���C���[�ɋ��܂�Ă���Actor���擾
	ActorPtr GetRoundActor() override;
	//�v���C���[�̃X�e�[�g���擾
	PlayerStateName GetPlayerStateName() override;
	//�v���C���[�̋��܂�Ă���Actor��ݒ�
	virtual void SetRoundActor(const Actor& actor)override;

	//�v���C���[�̐ݒ�
	virtual void SetPlayer(const ActorPtr& player);

private:
	Player* p_Player;							//�v���C���[

	std::vector<Actor> m_RoundActorList;		//���܂ꂽ�A�N�^�[���X�g
};
#endif // !CHARACTERMANAGER_H_