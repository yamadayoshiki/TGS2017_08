#include "UIManager.h"

#include "../../FileReader/CsvReader.h"
#include "../../SceneContains/SceneName.h"
#include "../UICreator/UICreator.h"

#include <vector>

// コンストラクタ
UIManager::UIManager(IWorld* world, const IGameManagerPtr& gameManager, const SceneName& scene) :
	Actor(world, ActorName::UI_Manager, GSvector2({ 0.0f, 0.0f }), gameManager) {

	// 各シーンのパスの登録
	regist();

	// シーンに対応したUIの生成
	create(scene);
}

// 各シーンのパスの登録
void UIManager::regist(){
	m_FilePaths[SceneName::GameTitle] = { "TitleScene/UI_Title_Button.csv", "", "" };
	m_FilePaths[SceneName::GameSelect] = { "TitleScene/UI_Title_Button.csv", "", "" };
	m_FilePaths[SceneName::GamePlay] = { "TitleScene/UI_Title_Button.csv", "", "" };
	m_FilePaths[SceneName::GameCredit] = { "TitleScene/UI_Title_Button.csv", "", "" };
	m_FilePaths[SceneName::GameEnd] = { "TitleScene/UI_Title_Button.csv", "", "" };
}

// シーンに対応したUIの生成
void UIManager::create(const SceneName & scene_name){
	addChild(std::make_shared<UICreator>(p_World, p_GameManager, m_FilePaths[scene_name]));
}

