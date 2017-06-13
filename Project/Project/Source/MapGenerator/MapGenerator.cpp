#include "MapGenerator.h"
#include "../Define/Def_Nakayama.h"
#include "../FileReader/CsvReader.h"
#include "ArrangeData.h"
#include "../ActorContains/ActorGroup.h"
#include "../CharacterContains/Factory/CharacterFactory.h"
#include "../Utility/MathSupport/MathSupport.h"

#include <GSvector2.h>
#include <iostream>
#include <memory>

//コンストラクタ
MapGenerator::MapGenerator(const IWorldPtr world, const IGameManagerPtr& gameManager)
	: p_World(world)
	, p_GameManager(gameManager)
	, p_Map(std::make_shared<Map>(gameManager)) {
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

// 生成する地形の登録
void MapGenerator::registMap() {
	p_Map->regist(m_CsvData);
	p_Map->regist(m_CsvData, MapType::Double);
}

// アクターの生成
void MapGenerator::generate()
{
	//プレイヤーを探して生成
	// 行のループ
	for (unsigned int i = 0; i < m_CsvData.size(); i++)
		// 列のループ
		for (unsigned int j = 0; j < m_CsvData[i].size(); j++)
			if(MathSupport::GetCutNum(m_CsvData[i][j],1,2) == 91)
				p_World.lock()->GetCharacterFactory()->Generate(j, i, m_CsvData[i][j]);

	//プレイヤー以外を生成
	// 行のループ
	for (unsigned int i = 0; i < m_CsvData.size(); i++)
		// 列のループ
		for (unsigned int j = 0; j < m_CsvData[i].size(); j++)
			if (MathSupport::GetCutNum(m_CsvData[i][j], 1, 2) != 91)
			//生成
			p_World.lock()->GetCharacterFactory()->Generate(j, i, m_CsvData[i][j]);
}

//マップの登録
MapPtr MapGenerator::getMap() {
	return p_Map;
}
