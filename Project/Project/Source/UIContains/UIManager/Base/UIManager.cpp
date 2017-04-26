#include "UIManager.h"

#include "../../../FileReader/CsvReader.h"
#include <vector>

UIManager::UIManager(const IWorldPtr& world, const IGameManagerPtr& gameManager) :
	Actor(world, ActorName::UIManager, GSvector2({ 0.0f, 0.0f }), gameManager) {

	create();
}

void UIManager::addFile(const UIType & type, const CsvReaderPtr & csv_reader){
	//m_FileNames[type] = csv_reader;
}

void UIManager::registButton(const std::string & file_name){

}

void UIManager::registSprite(const std::string & file_name){
	CsvReader csv = CsvReader("");

}

void UIManager::registText(const std::string & file_name){
	CsvReader csv = CsvReader("");


}

void UIManager::create(){
	//addChild(std::make_shared<ButtonManager>());
}
