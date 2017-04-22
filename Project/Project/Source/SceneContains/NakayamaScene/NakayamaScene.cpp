#include "NakayamaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include "../../MapGenerator/MapGenerator.h"


// コンストラクタ    
NakayamaScene::NakayamaScene()
{
}

// 開始     
void NakayamaScene::OnStart()
{
	p_World = std::make_shared<World>();

	MapGenerator generator(p_World, "Resource/StreamingAssets/stage1.csv",p_GameManager);
	//generator.registMap(p_World->GetMap());
}

// 更新     
void NakayamaScene::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);
}

// 描画     
void NakayamaScene::Draw() const
{
	p_World->Draw();

	//p_Renderer2D->DrawTexture("Block5", GSvector2(500, 100),GSrect(0.0f,0.0f,32.0f,32.0f));
}

// 次のシーンを返す     
SceneName NakayamaScene::Next() const
{
	return SceneName::GameTitle;
}

// 終了     
void NakayamaScene::End()
{
	p_World = nullptr;
}