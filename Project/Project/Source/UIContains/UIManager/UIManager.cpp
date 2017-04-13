#include "UIManager.h" 
#include "../UIGroup.h"

// コンストラクタ 
UIManager::UIManager(){
	initialize();
}

// 初期化 
void UIManager::initialize(){
}

// 更新 
void UIManager::update(float deltaTime){
	m_root.update(deltaTime);
	m_root.removeChildren();
}

// 描画 
void UIManager::draw() const
{
	m_root.draw();
}

// UIの追加 
void UIManager::addUI(UIGroup group, const UIPtr& actor)
{
	m_UIs[group]->addChild(actor);
}

// UIの検索 
UIPtr UIManager::findUI(const UIName& name)
{
	return m_root.findChildren_NullActor(name);
}

// メッセージ処理 
void UIManager::handleMessage(EventMessage message, void* param)
{
	m_root.handleMessage(message, param);
}
