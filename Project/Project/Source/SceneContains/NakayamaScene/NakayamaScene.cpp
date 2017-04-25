#include "NakayamaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include "../../MapGenerator/MapGenerator.h"


// �R���X�g���N�^    
NakayamaScene::NakayamaScene(const IGameManagerPtr& gameManager, const WorldPtr& world)
	:Scene(gameManager, world) {
}

// �J�n     
void NakayamaScene::OnStart()
{
	MapGenerator* generator = new MapGenerator(p_World/*, "Resource/StreamingAssets/stage1.csv"*/, p_GameManager);
	//generator.registMap(p_World->GetMap());
	p_World->setMapGenerator(generator);
	p_World->generate();
}

// �X�V     
void NakayamaScene::OnUpdate(float deltaTime)
{
	p_World->update(deltaTime);

}

// �`��     
void NakayamaScene::Draw() const
{
	p_World->Draw();

	//p_Renderer2D->DrawTexture("Block5", GSvector2(500, 100),GSrect(0.0f,0.0f,32.0f,32.0f));
}

// ���̃V�[����Ԃ�     
SceneName NakayamaScene::Next() const
{
	return SceneName::GameTitle;
}

// �I��     
void NakayamaScene::End()
{
}