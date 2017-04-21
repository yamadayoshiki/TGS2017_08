#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include "../ActorContains/ActorPtr.h"
#include "../Map/Map.h"

#include <string>
#include <map>

class IWorld;
class Map;
class IGameManager;

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
	MapGenerator(IWorld* world, const std::string& file_name,IGameManager* gameManager);
	// �}�b�v�̃��[�h
	void load(const std::string& file_name);
	// ��������A�N�^�[�̓o�^
	void registActor();
	// ��������n�`�̓o�^
	void registMap(Map& map);
	// �A�N�^�[�̐���
	void generate();
private:
	//���[���h
	IWorld* p_World;
	// �A�N�^�[�o�^�pmap
	std::map<int, ActorData> m_Actors;
	// csv�f�[�^
	std::vector<std::vector<int>> m_CsvData;
	//�Q�[���}�l�[�W���[
	IGameManager* p_GameManager;
};

#endif // !MAP_GENERATOR_H_