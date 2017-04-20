#include"MapGenerator.h"
#include "../Define/Def_Nakayama.h"
#include "../FileReader/CsvReader.h"
#include "../ActorContains/ActorGroup.h"
#include "../ActorContains/Object/TestObj.h"
#include "../Map/Map.h"
#include <GSvector2.h>
#include <iostream>
#include <memory>

//�R���X�g���N�^
MapGenerator::MapGenerator(IWorld* world, const std::string& file_name) : 
	p_World(world){
	load(file_name);

	// �A�N�^�[�̓o�^
	registActor();

	// �A�N�^�[�̐���
	generate();
}

void MapGenerator::load(const std::string& file_name){
	// �t�@�C���̓ǂݍ���
	CsvReader file = CsvReader(file_name);

	// �s�̃��[�v
	for (int i = 0; i < file.rows(); i++) {
		std::vector<int> tmp;

		// ��̃��[�v
		for (int j = 0; j < file.columns(); j++) {
			tmp.push_back(file.geti(i, j));
			std::cout << file.get(i, j);
		}

		m_CsvData.push_back(tmp);
		std::cout << "\n";
	}
}

// ��������A�N�^�[�̓o�^
void MapGenerator::registActor(){
	// �e�Ǝq���w��
	m_Actors[1] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>(p_World, GSvector2{ 0.0f, 0.0f }) };
	m_Actors[2] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>(p_World, GSvector2{ 0.0f, 0.0f }) };
}

// ��������n�`�̓o�^
void MapGenerator::registMap(Map & map){
	//// �s�̃��[�v
	//for (int i = 0; i < m_CsvData.size(); i++) {
	//	std::vector<int> tmp;

	//	// ��̃��[�v
	//	for (int j = 0; j < m_CsvData[i].size(); j++) {
	//		if (m_CsvData[i][j] == 1) {
	//			tmp.push_back(1);
	//		}
	//		else {
	//			tmp.push_back(0);
	//		}
	//	}
	//	map.getmap().push_back(tmp);
	//}
}

// �A�N�^�[�̐���
void MapGenerator::generate()
{
	// �s�̃��[�v
	for (int i = 0; i < m_CsvData.size(); i++) {
		// ��̃��[�v
		for (int j = 0; j < m_CsvData[i].size(); j++) {
			// �w�肵���}�X�̔ԍ�
			int index = m_CsvData[i][j];
			// �ԍ������������ǂ���
			if (m_Actors.find(index) != m_Actors.end()) {
				m_Actors[index].parent->addChild(
					m_Actors[index].child->clone(GSvector2(j, i) * CHIP_SIZE)
					);
			}
		}
	}
}
