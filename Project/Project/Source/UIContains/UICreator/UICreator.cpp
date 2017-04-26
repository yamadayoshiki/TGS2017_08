#include "UICreator.h"

#include "../UIManager/GameTitle/UIManager_Title.h"
#include "../UIManager/GameSelect/UIManager_Select.h"
#include "../UIManager/GamePlay/UIManager_Play.h"

#include "../../ActorContains/ActorGroup.h"

// コンストラクタ
UICreator::UICreator(const IWorldPtr& world, const IGameManagerPtr& gameManager) : p_World(world), p_GameManager(gameManager){
	regist();
}

// デストラクタ
UICreator::~UICreator(){
}

// UIの登録
void UICreator::regist(){
	m_UIManagers[SceneName::GameTitle] = std::make_shared<UIManager_Title>(p_World, p_GameManager);
	m_UIManagers[SceneName::GamePlay] = std::make_shared<UIManager_Select>(p_World, p_GameManager);
	m_UIManagers[SceneName::NaganoScene] = std::make_shared<UIManager_Title>(p_World, p_GameManager);
}

// シーンに対応したUIの生成
void UICreator::create(const SceneName& scene_name){
	p_World->addActor(ActorGroup::UI, m_UIManagers[scene_name]);
}
