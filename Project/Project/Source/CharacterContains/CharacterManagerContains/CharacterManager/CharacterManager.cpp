#include "CharacterManager.h"
#include "../../PlayerContains/PlayerState/PlayerStateName.h"

//�R���X�g���N�^
CharacterManager::CharacterManager() {

}

CharacterManager::~CharacterManager() {
	delete p_Player;
}


//�v���C���[�̍��W���擾
GSvector2 CharacterManager::GetPlayerPos() {
	return p_Player->getPosition();
}

//�v���C���[�ɋ��܂ꂽ���̍��W
GSvector2 CharacterManager::GetRoundPos() const {
	GSvector2 result = p_Player->getPosition() + p_Player->getBody()->forward() * 10.0f;
	return result;
}

//�v���C���[�ɋ��܂�Ă���Actor���擾
ActorPtr CharacterManager::GetRoundActor() {
	return nullptr;
}

//�v���C���[�̃X�e�[�g���擾
PlayerStateName CharacterManager::GetPlayerStateName() {
	return PlayerStateName::None;
}

//�v���C���[�̋��܂�Ă���Actor��ݒ�
void CharacterManager::SetRoundActor(const ActorPtr& actor) {
	m_RoundActorList.push_back(actor);
}


//�v���C���[�̐ݒ�
void CharacterManager::SetPlayer(const ActorPtr& player) {
	/*if (player->getName() == ActorName::Player)
		p_Player = dynamic_cast<Player*>(player.get());*/
}