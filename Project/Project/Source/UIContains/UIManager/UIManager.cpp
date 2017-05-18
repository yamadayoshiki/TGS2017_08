#include "UIManager.h"

#include "../../FileReader/CsvReader.h"
#include "../../SceneContains/SceneName.h"
#include "../UICreator/UICreator.h"

#include "../Button/Button.h"
#include "../Sprite/Sprite.h"
#include "../Text/Text.h"

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
	m_FilePaths[SceneName::GameTitle]	= { "Title/UI_Button.csv",	"Title/UI_Sprite.csv",	"Title/UI_Text.csv" };
	m_FilePaths[SceneName::GameSelect]	= { "Select/UI_Button.csv",	"Select/UI_Sprite.csv",	"Select/UI_Text.csv" };
	m_FilePaths[SceneName::GamePlay]	= { "Play/UI_Button.csv",	"Play/UI_Sprite.csv",	"Play/UI_Text.csv" };
	m_FilePaths[SceneName::GameCredit]	= { "Credit/UI_Button.csv",	"Credit/UI_Sprite.csv",	"Credit/UI_Text.csv" };
	m_FilePaths[SceneName::GameEnd]		= { "End/UI_Button.csv",	"End/UI_Sprite.csv",	"End/UI_Text.csv" };
}

// シーンに対応したUIの生成
void UIManager::create(const SceneName & scene_name){
	addChild(std::make_shared<UICreator<Button>>(p_World, p_GameManager, "Resource/StreamingAssets/UI/" + m_FilePaths[scene_name].button));
	//addChild(std::make_shared<UICreator<Sprite>>(p_World, p_GameManager, "Resource/StreamingAssets/UI/" + m_FilePaths[scene_name].sprite));
	//addChild(std::make_shared<UICreator<Text>>(p_World, p_GameManager,	 "Resource/StreamingAssets/UI/" + m_FilePaths[scene_name].text));
}

