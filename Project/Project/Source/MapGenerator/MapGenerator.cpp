#include "MapGenerator.h"
#include "../Define/Def_Nakayama.h"
#include "../FileReader/CsvReader.h"
#include "ArrangeData.h"
#include "../ActorContains/ActorGroup.h"
#include "../CharacterContains/PlayerContains/Player/Player.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy01/Enemy01.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy02/Enemy02.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy03/Enemy03.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy04/Enemy04.h"
#include "../CharacterContains/EnemyContains/Enemys/Enemy05/Enemy05.h"

#include "../Wall/BreakWall.h"

#include <GSvector2.h>
#include <iostream>
#include <memory>

//コンストラクタ
MapGenerator::MapGenerator(const IWorldPtr world, const IGameManagerPtr& gameManager)
	: p_World(world)
	, p_GameManager(gameManager)
	, m_Map(gameManager) {
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
	/*0=空,1=壁*/
	// 親と子を指定
	m_Actors[4] = ActorData{ p_World->findActor(ActorName::EnemyManager), std::make_shared<BreakWall>(p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	m_Actors[5] = ActorData{ p_World->findActor(ActorName::Player_Manager), std::make_shared<Player>(p_World.get(), GSvector2{ 0.0f, 0.0f },p_GameManager) };
	//エネミー
	m_Actors[11] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy01>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),p_GameManager) };
	m_Actors[12] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy02>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),FourDirection(FourDirectionName::Right),p_GameManager) };
	m_Actors[13] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy02>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),FourDirection(FourDirectionName::Left),p_GameManager) };
	m_Actors[14] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy02>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),FourDirection(FourDirectionName::Down),p_GameManager) };
	m_Actors[15] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy03>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),TurnDirection(TurnDirectionName::Clockwise),p_GameManager) };
	m_Actors[16] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy03>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),TurnDirection(TurnDirectionName::AntiClockwise),p_GameManager) };
	m_Actors[17] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy04>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),p_GameManager) };
	m_Actors[18] = ActorData{ p_World->findActor(ActorName::EnemyManager),std::make_shared<Enemy05>(p_World.get(),GSvector2(0.0f,0.0f),FourDirection(FourDirectionName::None),p_GameManager) };
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
			ArrangeData data;
			data.SetData(m_CsvData[i][j]);
			// 番号が見つかったどうか
			if (m_Actors.find(data.actorKey) != m_Actors.end()) {
				m_Actors[data.actorKey].parent->addChild(
					m_Actors[data.actorKey].child->clone(GSvector2(j, i) * CHIP_SIZE, data.front)
					);
			}
		}
	}
}

//マップの登録
Map & MapGenerator::getMap() {
	return m_Map;
}
