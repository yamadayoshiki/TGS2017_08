#include "MapGenerator.h"
#include "../Define/Def_Nakayama.h"
#include "../FileReader/CsvReader.h"
#include "../ActorContains/ActorGroup.h"
#include "../ActorContains/Object/TestObj.h"
#include "../ActorContains/Object/TestEnemy.h"
#include "../CharacterContains/PlayerContains/Player/Player.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy01/Enemy01.h"
#include "../Wall/BreakWall.h"

#include <GSvector2.h>
#include <iostream>
#include <memory>

//コンストラクタ
MapGenerator::MapGenerator(const IWorldPtr world, const IGameManagerPtr& gameManager)
	: p_World(world)
	, p_GameManager(gameManager)
	, m_Map(gameManager){
}

void MapGenerator::load(const std::string& file_name) {
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
void MapGenerator::registActor() {
	// 親と子を指定
	//m_Actors[0] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>(p_World, GSvector2{ 0.0f, 0.0f }) };
	m_Actors[2] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestObj>	 (p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	m_Actors[3] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<TestEnemy>(p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	m_Actors[4] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<BreakWall>(p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	m_Actors[5] = ActorData{ p_World->findActor(ActorName::Player_Manager), std::make_shared<Player>(p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	//m_Actors[6] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<Enemy01>(p_World.get(), GSvector2{ 0.0f, 0.0f }, FourDirection(FourDirectionName::Up), p_GameManager) };
}

// 生成する地形の登録
void MapGenerator::registMap() {
	m_Map.regist(m_CsvData);
	m_Map.regist(m_CsvData, MapType::Double);
}

// アクターの生成
void MapGenerator::generate()
{
	// 行のループ
	for (unsigned int i = 0; i < m_CsvData.size(); i++) {
		// 列のループ
		for (unsigned int j = 0; j < m_CsvData[i].size(); j++) {
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

//マップの登録
Map & MapGenerator::getMap(){
	return m_Map;
}
