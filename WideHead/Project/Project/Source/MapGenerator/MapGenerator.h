#ifndef MAP_GENERATOR_H_
#define MAP_GENERATOR_H_

#include "../ActorContains/ActorPtr.h"
#include "../Map/Map.h"
#include"../WorldContains/IWorldPtr.h"
#include "../Base/GameManagerContains/IGameManagerPtr.h"
#include "../Map/MapPtr.h"

#include <string>
#include <map>

class IWorld;

// �}�b�v�����N���X
class MapGenerator {
public:
	//�R���X�g���N�^
	MapGenerator(const IWorldPtr world, const IGameManagerPtr& gameManager);
	// �}�b�v�̃��[�h
	void load(const std::string& file_name);
	// ��������n�`�̓o�^
	void registMap();
	// �A�N�^�[�̐���
	void generate();
	//�}�b�v�̎擾
	MapPtr getMap();
private:
	IWorldWPtr p_World;					//���[���h
	MapData m_CsvData;					// csv�f�[�^
	MapPtr p_Map;						// �}�b�v�f�[�^
	IGameManagerWPtr p_GameManager;		//�Q�[���}�l�[�W��
};

#endif // !MAP_GENERATOR_H_