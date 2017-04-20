#include "NakayamaScene.h"

#include <gslib.h>

#include "../SceneName.h"
#include "../../WorldContains/World/World.h"
#include "../../MapGenerator/MapGenerator.h"


// �R���X�g���N�^    
NakayamaScene::NakayamaScene()
{
}

// �J�n     
void NakayamaScene::OnStart()
{
	p_World = std::make_shared<World>();

	p_Renderer2D = new Renderer2D();
	p_Renderer2D->Initialize();
	p_Renderer2D->LoadTexture("Block5", "Resource/StreamingAssets/Block5.png");

	MapGenerator generator(p_World.get(), "Resource/StreamingAssets/stage1.csv");
	//generator.registMap(p_World->GetMap());
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
	p_World = nullptr;
	delete p_Renderer2D;
}