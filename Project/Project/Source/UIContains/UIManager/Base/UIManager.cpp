#include "UIManager.h"

#include "../../../FileReader/CsvReader.h"
#include "../../../SceneContains/SceneName.h"
#include "../../../ActorContains/ActorGroup.h"

#include "../GameTitle/UIManager_Title.h"
#include "../GameSelect/UIManager_Select.h"
#include "../GamePlay/UIManager_Play.h"

#include <vector>

UIManager::UIManager(IWorld* world, const IGameManagerPtr& gameManager, const SceneName& scene) :
	Actor(world, ActorName::UIManager, GSvector2({ 0.0f, 0.0f }), gameManager) {

	registActor();

	create(scene);
}

void UIManager::registActor(){
	m_UIManagers[SceneName::GameTitle] = std::make_shared<UIManager_Title>(p_World, p_GameManager);
	m_UIManagers[SceneName::GamePlay] = std::make_shared<UIManager_Select>(p_World, p_GameManager);
	m_UIManagers[SceneName::NaganoScene] = std::make_shared<UIManager_Title>(p_World, p_GameManager);

}

// ÉVÅ[ÉìÇ…ëŒâûÇµÇΩUIÇÃê∂ê¨
void UIManager::create(const SceneName & scene_name){
	addChild(m_UIManagers[scene_name]);
}

void UIManager::addFile(const UIType & type, const CsvReaderPtr & csv_reader){
	//m_FileNames[type] = csv_reader;
}

void UIManager::registButton(const std::string & file_name){

}

void UIManager::registSprite(const std::string & file_name){
	//CsvReader csv = CsvReader("");

}

void UIManager::registText(const std::string & file_name){
	//CsvReader csv = CsvReader("");


}

