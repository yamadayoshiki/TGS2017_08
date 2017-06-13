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
//// �R���X�g���N�^    
//NakayamaScene::NakayamaScene(const IGameManagerPtr& gameManager)
//	:Scene(gameManager) {
//}
//
//// �J�n     
//void NakayamaScene::OnStart()
//{
//	////�}�b�v�W�F�l���[�^����
//	//MapGenerator* generator = new MapGenerator(p_World, p_GameManager);
//	////�}�b�v�W�F�l���[�^�ݒ�
//	//p_World->setMapGenerator(generator);
//	//�}�b�v�f�[�^�ɂ�鐶��
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
//// �X�V     
//void NakayamaScene::OnUpdate(float deltaTime)
//{
//	p_World->GetMap()->draw();
//}
//
//// ���̃V�[����Ԃ�     
//SceneName NakayamaScene::Next() const
//{
//	return SceneName::GameTitle;
//}
//
//// �I��     
//void NakayamaScene::End()
//{
//}