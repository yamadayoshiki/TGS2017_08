#include "UIManager.h" 
#include "../UIGroup.h"

// �R���X�g���N�^ 
UIManager::UIManager(){
	initialize();
}

// ������ 
void UIManager::initialize(){
}

// �X�V 
void UIManager::update(float deltaTime){
	m_root.update(deltaTime);
	m_root.removeChildren();
}

// �`�� 
void UIManager::draw() const
{
	m_root.draw();
}

// UI�̒ǉ� 
void UIManager::addUI(UIGroup group, const UIPtr& actor)
{
	m_UIs[group]->addChild(actor);
}

// UI�̌��� 
UIPtr UIManager::findUI(const UIName& name)
{
	return m_root.findChildren_NullActor(name);
}

// ���b�Z�[�W���� 
void UIManager::handleMessage(EventMessage message, void* param)
{
	m_root.handleMessage(message, param);
}
