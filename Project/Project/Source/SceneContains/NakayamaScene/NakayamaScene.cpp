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
	////�}�b�v�W�F�l���[�^����
	//MapGenerator* generator = new MapGenerator(p_World, p_GameManager);
	////�}�b�v�W�F�l���[�^�ݒ�
	//p_World->setMapGenerator(generator);
	//�}�b�v�f�[�^�ɂ�鐶��
 	p_World->generate(p_World, p_GameManager, "Resource/StreamingAssets/stage1.csv");

	Map map = p_World->GetMap();
	std::unordered_map<Tile, TileData> tmp = map.GetAroundTile(GSvector2(70, 90));
		
	GSvector2 tilePos = tmp[Tile::Down].Position();
	GSrect tileRect = tmp[Tile::Down].Rectangle();
	bool tileFlag = tmp[Tile::Down].Flag();

	int a;
	a = 0;
}

// �X�V     
void NakayamaScene::OnUpdate(float deltaTime)
{
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