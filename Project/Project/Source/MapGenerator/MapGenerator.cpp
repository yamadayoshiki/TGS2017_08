#include"MapGenerator.h"
#include "../Define/Def_Nakayama.h"
#include "../FileReader/CsvReader.h"
#include "../ActorContains/ActorGroup.h"
#include "../ActorContains/Object/TestObj.h"
#include "../Map/Map.h"
#include <GSvector2.h>
#include <iostream>
#include <memory>

//コンストラクタ
MapGenerator::MapGenerator(IWorld* world, const std::string& file_name) : 
	p_World(world){
	load(file_name);

	// アクターの登録
	registActor();

	// アクターの生成
	generate();
}

void MapGenerator::load(const std::string& file_name){
	// ファイルの読み込み
	CsvReader file = CsvReader(file_name);

	// 行のループ
	for (int i = 0; i < file.rows(); i++) {
		std::vector<int> tmp;

		// 列のループ
		for (int j = 0; j < file.columns(); j++) {
			tmp.push_back(file.geti(i, j));
			std::cout << file.get(i, j);
		}

		m_CsvData.push_back(tmp);
		std::cout << "\n";
	}
}

// 生成するアクターの登録
void MapGenerator::registActor(){
	// 親と子を指定
	m_Actors[1] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>(p_World, GSvector2{ 0.0f, 0.0f }) };
	m_Actors[2] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>(p_World, GSvector2{ 0.0f, 0.0f }) };
}

// 生成する地形の登録
void MapGenerator::registMap(Map & map){
	//// 行のループ
	//for (int i = 0; i < m_CsvData.size(); i++) {
	//	std::vector<int> tmp;

	//	// 列のループ
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

// アクターの生成
void MapGenerator::generate()
{
	// 行のループ
	for (int i = 0; i < m_CsvData.size(); i++) {
		// 列のループ
		for (int j = 0; j < m_CsvData[i].size(); j++) {
			// 指定したマスの番号
			int index = m_CsvData[i][j];
			// 番号が見つかったどうか
			if (m_Actors.find(index) != m_Actors.end()) {
				m_Actors[index].parent->addChild(
					m_Actors[index].child->clone(GSvector2(j, i) * CHIP_SIZE)
					);
			}
		}
	}
}
