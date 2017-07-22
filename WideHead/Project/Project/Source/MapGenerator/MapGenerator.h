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

// マップ生成クラス
class MapGenerator {
public:
	//コンストラクタ
	MapGenerator(const IWorldPtr world, const IGameManagerPtr& gameManager);
	// マップのロード
	void load(const std::string& file_name);
	// 生成する地形の登録
	void registMap();
	// アクターの生成
	void generate();
	//マップの取得
	MapPtr getMap();
private:
	IWorldWPtr p_World;					//ワールド
	MapData m_CsvData;					// csvデータ
	MapPtr p_Map;						// マップデータ
	IGameManagerWPtr p_GameManager;		//ゲームマネージャ
};

#endif // !MAP_GENERATOR_H_