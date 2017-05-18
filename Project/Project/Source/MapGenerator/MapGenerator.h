#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include "../ActorContains/ActorPtr.h"
#include "../Map/Map.h"
#include"../WorldContains/IWorldPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"

#include <string>
#include <map>

class IWorld;
class Map;

// �}�b�v�����N���X
class MapGenerator
{
	struct ActorData {
		// ��������A�N�^�[�̐e
		ActorPtr parent;
		// ��������A�N�^�[���g
		ActorPtr child;
	};

public:
	//�R���X�g���N�^
	MapGenerator(const IWorldPtr world,const IGameManagerPtr& gameManager);
	// �}�b�v�̃��[�h
	void load(const std::string& file_name);
	// ��������A�N�^�[�̓o�^
	void registActor();
	// ��������n�`�̓o�^
	void registMap();
	// �A�N�^�[�̐���
	void generate();
	//�}�b�v�̎擾
	Map & getMap();
private:
	//���[���h
	IWorldPtr p_World;
	// �A�N�^�[�o�^�pmap
	std::map<int, ActorData> m_Actors;
	// csv�f�[�^
	MapData m_CsvData;
	// �}�b�v�f�[�^
	Map m_Map;
	//�Q�[���}�l�[�W���[�|�C���^
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_GENERATOR_H_