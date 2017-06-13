#ifndef PLAYERWATCH_H_
#define PLAYERWATCH_H_

#include "../../../ActorContains/ActorPtr.h"
#include "../../../Map/MapType.h"
#include "../../../Utility/FourDirection/FourDirection.h"
#include "../../../Map/MapPtr.h"

struct GSvector2;

class PlayerWatch
{
public:
	//�R���X�g���N�^
	PlayerWatch(const ActorPtr user);
	//�f�X�g���N�^
	~PlayerWatch();
	//���[�U�[����v���C���[�܂ł̋����x�N�g��
	GSvector2 GetToPlayerDis() const;
	//���[�U�[����v���C���[�܂ł̋����}�X�x�N�g��(�}�X����,MapType�̓��[�U�[�)
	GSvector2 GetToPlayerChipDis() const;
	//�v���C���[�̐���
	FourDirection GetPlayerFrontDir() const;

private:
	ActorWPtr p_User;		//���[�U�[
	ActorWPtr p_Player;		//�v���C���[
	MapWPtr p_Map;			//�}�b�v
};

#endif // !PLAYERWATCH_H_
