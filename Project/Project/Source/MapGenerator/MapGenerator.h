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

// マップ生成クラス
class MapGenerator
{
	struct ActorData {
		// 生成するアクターの親
		ActorPtr parent;
		// 生成するアクター自身
		ActorPtr child;
	};

public:
	//コンストラクタ
	MapGenerator(const IWorldPtr world,const IGameManagerPtr& gameManager);
	// マップのロード
	void load(const std::string& file_name);
	// 生成するアクターの登録
	void registActor();
	// 生成する地形の登録
	void registMap();
	// アクターの生成
	void generate();
	//マップの取得
	Map & getMap();
private:
	//ワールド
	IWorldPtr p_World;
	// アクター登録用map
	std::map<int, ActorData> m_Actors;
	// csvデータ
	MapData m_CsvData;
	// マップデータ
	Map m_Map;
	//ゲームマネージャーポインタ
	IGameManagerPtr p_GameManager;
};

#endif // !MAP_GENERATOR_H_