#include <algorithm>

#include "UI.h"
#include "../NullUI/NullUI.h"

//コンストラクタ
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

//更新
void UI::update(float deltaTime)
{
	onUpdate(deltaTime);
	eachChildren([&](UI& child) {child.update(deltaTime); });
}

//描画
void UI::draw() const
{
	onDraw();
	eachChildren([](const UI& child) { child.draw(); });
}

// 死亡しているか？ 
bool UI::GetDead() const
{
	return m_dead;
}

// 死亡する 
void UI::dead()
{
	m_dead = true;
}

// 名前を返す 
const UIName UI::getName() const
{
	return m_Name;
}

// 座標を返す 
GSvector2 UI::getPosition() const
{
	return m_Position;
}

// 子の検索 
UIPtr UI::findChildren_NullActor(const UIName& name)
{
	UIPtr result = findChildren([&](const UI& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullUI>(p_World);

	return result;
}

//子の検索
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

// 子の追加 
void UI::addChild(const UIPtr& child)
{
	m_children.push_front(child);
}

// 子を巡回 
void UI::eachChildren(std::function<void(UI&)> fn)
{
	std::for_each(m_children.begin(), m_children.end(), [&](const UIPtr& child) { fn(*child); });
}

// 子を巡回 (const版) 
void UI::eachChildren(std::function<void(const UI&)> fn) const
{
	std::for_each(m_children.begin(), m_children.end(), [&](const UIPtr& child) { fn(*child); });
}

// 子を削除する 
void UI::removeChildren(std::function <bool(UI& actor)> fn)
{
	m_children.remove_if([&](const UIPtr& child) { return fn(*child); });
}

// 子を削除する 
void UI::removeChildren()
{
	removeChildren([](UI& child) { return child.GetDead(); });
	eachChildren([](UI& child) { child.removeChildren(); });
}

// 子を消去 
void UI::clearChildren()
{
	m_children.clear();
}

//ワールドを設定
void UI::SetWorld(IWorld* world)
{
	p_World = world;
}


// メッセージ処理 
void UI::handleMessage(EventMessage message, void* param)
{
	onMessage(message, param);
	eachChildren([&](UI& child) { child.handleMessage(message, param); });
}

// メッセージ処理 
void UI::onMessage(EventMessage, void*)
{
}

// 更新 
void UI::onUpdate(float)
{
}

// 描画 
void UI::onDraw() const
{
}
