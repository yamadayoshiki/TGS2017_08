//#include "NakayamaScene.h"
//
//#include <gslib.h>
//
//#include "../SceneName.h"
//#include "../../WorldContains/World/World.h"
//#include "../../MapGenerator/MapGenerator.h"
//#include "../../Utility/FourDirection/FourDirection.h"
//
//
//// コンストラクタ    
//NakayamaScene::NakayamaScene(const IGameManagerPtr& gameManager)
//	:Scene(gameManager) {
//}
//
//// 開始     
//void NakayamaScene::OnStart()
//{
//	////マップジェネレータ生成
//	//MapGenerator* generator = new MapGenerator(p_World, p_GameManager);
//	////マップジェネレータ設定
//	//p_World->setMapGenerator(generator);
//	//マップデータによる生成
//	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");
//
//	std::unordered_map<FourDirection, TileData> tmp = p_World->GetMap()->GetAroundTile(GSvector2(70, 90));
//
//	GSvector2 tilePos = tmp[FourDirection(FourDirectionName::Down)].Position();
//	GSrect tileRect = tmp[FourDirection(FourDirectionName::Down)].Rectangle();
//	bool tileFlag = tmp[FourDirection(FourDirectionName::Down)].Flag();
//
//	int a;
//	a = 0;
//}
//
//// 更新     
//void NakayamaScene::OnUpdate(float deltaTime)
//{
//	p_World->GetMap()->draw();
//}
//
//// 次のシーンを返す     
//SceneName NakayamaScene::Next() const
//{
//	return SceneName::GameTitle;
//}
//
//// 終了     
//void NakayamaScene::End()
//{
//}