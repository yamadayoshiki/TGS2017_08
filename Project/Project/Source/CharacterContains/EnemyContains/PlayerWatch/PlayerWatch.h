#ifndef PLAYERWATCH_H_
#define PLAYERWATCH_H_

#include "../../../ActorContains/ActorPtr.h"
#include "../../PlayerContains/Player/PlayerPtr.h"

class Map;
struct GSvector2;
enum class MapType;

//�v���C���[�Ď��N���X
class PlayerWatch 
{
public:
	//�R���X�g���N�^
	PlayerWatch(Map& map, const ActorPtr& user);
	//�f�X�g���N�^
	~PlayerWatch();

	//���[�U�[����v���C���[�܂ł̋����x�N�g��
	GSvector2 GetToPlayerDis() const;
	//���[�U�[����v���C���[�܂ł̋����}�X�x�N�g��(�}�X����)
	GSvector2 GetToPlayerChipDis(MapType type) const;

private:
	ActorWPtr p_User;		//���[�U�[
	ActorWPtr p_Player;		//�v���C���[
	Map& m_Map;				//�}�b�v
};


#endif // !PLAYERWATCH_H_
