#include "NakayamaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include "../../MapGenerator/MapGenerator.h"


// コンストラクタ    
NakayamaScene::NakayamaScene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// 開始     
void NakayamaScene::OnStart()
{
	//マップジェネレータ生成
	MapGenerator* generator = new MapGenerator(p_World, p_GameManager);
	//マップジェネレータ設定
	p_World->setMapGenerator(generator);
	//マップデータによる生成
	p_World->generate();
}

// 更新     
void NakayamaScene::OnUpdate(float deltaTime)
{
}

// 次のシーンを返す     
SceneName NakayamaScene::Next() const
{
	return SceneName::GameTitle;
}

// 終了     
void NakayamaScene::End()
{
}