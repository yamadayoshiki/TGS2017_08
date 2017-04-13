#include <algorithm>

#include "UI.h"
#include "../NullUI/NullUI.h"

//�R���X�g���N�^
UI::UI(
	IWorld* world,
	const UIName& name,
	const GSvector2& position
	)
	: p_World(world)
	, m_Name(name)
	, m_Position(position)
	, m_dead(false)
{
}

UI::UI(const UIName& name)
	:UI(
		nullptr,
		name,
		{ 0.0f,0.0f })
{
}

//�X�V
void UI::update(float deltaTime)
{
	onUpdate(deltaTime);
	eachChildren([&](UI& child) {child.update(deltaTime); });
}

//�`��
void UI::draw() const
{
	onDraw();
	eachChildren([](const UI& child) { child.draw(); });
}

// ���S���Ă��邩�H 
bool UI::GetDead() const
{
	return m_dead;
}

// ���S���� 
void UI::dead()
{
	m_dead = true;
}

// ���O��Ԃ� 
const UIName UI::getName() const
{
	return m_Name;
}

// ���W��Ԃ� 
GSvector2 UI::getPosition() const
{
	return m_Position;
}

// �q�̌��� 
UIPtr UI::findChildren_NullActor(const UIName& name)
{
	UIPtr result = findChildren([&](const UI& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullUI>(p_World);

	return result;
}

//�q�̌���
UIPtr UI::findChildren(std::function<bool(const UI&)> fn)
{
	const auto& i
		= std::find_if(
			m_children.begin()
			, m_children.end()
			, [&](const UIPtr& child)
	{ return fn(*child); });

	if (i != m_children.end())
	{
		return *i;
	}

	for (const auto& child : m_children)
	{
		const auto ui = child->findChildren(fn);

		if (ui != nullptr)
		{
			return ui;
		}
	}
	return nullptr;
}

// �q�̒ǉ� 
void UI::addChild(const UIPtr& child)
{
	m_children.push_front(child);
}

// �q������ 
void UI::eachChildren(std::function<void(UI&)> fn)
{
	std::for_each(m_children.begin(), m_children.end(), [&](const UIPtr& child) { fn(*child); });
}

// �q������ (const��) 
void UI::eachChildren(std::function<void(const UI&)> fn) const
{
	std::for_each(m_children.begin(), m_children.end(), [&](const UIPtr& child) { fn(*child); });
}

// �q���폜���� 
void UI::removeChildren(std::function <bool(UI& actor)> fn)
{
	m_children.remove_if([&](const UIPtr& child) { return fn(*child); });
}

// �q���폜���� 
void UI::removeChildren()
{
	removeChildren([](UI& child) { return child.GetDead(); });
	eachChildren([](UI& child) { child.removeChildren(); });
}

// �q������ 
void UI::clearChildren()
{
	m_children.clear();
}

//���[���h��ݒ�
void UI::SetWorld(IWorld* world)
{
	p_World = world;
}


// ���b�Z�[�W���� 
void UI::handleMessage(EventMessage message, void* param)
{
	onMessage(message, param);
	eachChildren([&](UI& child) { child.handleMessage(message, param); });
}

// ���b�Z�[�W���� 
void UI::onMessage(EventMessage, void*)
{
}

// �X�V 
void UI::onUpdate(float)
{
}

// �`�� 
void UI::onDraw() const
{
}
