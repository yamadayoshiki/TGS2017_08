#include "UIManager.h"

#include "../../FileReader/CsvReader.h"
#include "../../SceneContains/SceneName.h"
#include "../UICreator/UICreator.h"

#include <vector>

// �R���X�g���N�^
UIManager::UIManager(IWorld* world, const IGameManagerPtr& gameManager, const SceneName& scene) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {

	// �e�V�[���̃p�X�̓o�^
	regist();

	// �V�[���ɑΉ�����UI�̐���
	create(scene);
}

// �e�V�[���̃p�X�̓o�^
void UIManager::regist(){
	m_FilePaths[SceneName::GameTitle] = { "Title/UI_Button.csv", "Title/UI_Sprite.csv", "" };
	m_FilePaths[SceneName::GameSelect] = { "Title/UI_Button.csv", "", "" };
	m_FilePaths[SceneName::GamePlay] = { "Title/UI_Button.csv", "", "" };
	m_FilePaths[SceneName::GameCredit] = { "Title/UI_Button.csv", "", "" };
	m_FilePaths[SceneName::GameEnd] = { "Title/UI_Button.csv", "", "" };
}

// �V�[���ɑΉ�����UI�̐���
void UIManager::create(const SceneName & scene_name){
	addChild(std::make_shared<UICreator>(p_World, p_GameManager, m_FilePaths[scene_name]));
}

