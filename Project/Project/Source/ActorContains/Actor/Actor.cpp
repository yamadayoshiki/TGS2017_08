#include <algorithm>

#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../Body/Base/HitInfo.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

//コンストラクタ
Actor::Actor(
	const IWorldPtr& world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gaemManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: p_World(world)
	, p_GameManager(gaemManager)
	, m_Name(name)
	, m_Position(position)
	, m_Matrix(GS_MATRIX4_IDENTITY)
	, m_Body(body)
	, m_dead(false)
	, p_Texture(texture)
{
}


Actor::Actor(const ActorName& name)
	:Actor(
		nullptr,
		name,
		{ 0.0f,0.0f }
		, nullptr)
{
}

//仮想デストラクタ
Actor::~Actor() {
}

//更新
void Actor::update(float deltaTime)
{
	onUpdate(deltaTime);
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//描画
void Actor::draw() const
{
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//衝突判定(自分は子を巡回、引数はそれ単体)
void Actor::collide(Actor& other)
{
	if (isCollide(other))
	{
		onCollide(other);
		other.onCollide(*this);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// 死亡しているか？ 
bool Actor::GetDead() const
{
	return m_dead;
}

// 死亡する 
void Actor::dead()
{
	m_dead = true;
}

// 名前を返す 
const ActorName Actor::getName() const
{
	return m_Name;
}

// 座標を返す 
GSvector2 Actor::getPosition() const
{
	return m_Position;
}

//行列の取得
GSmatrix4 Actor::getMatrix() const {
	return m_Matrix;
}

//ポーズの取得
GSmatrix4 Actor::getPose() const {
	return GSmatrix4(m_Matrix).setPosition(m_Position);
}

//回転を取得
void Actor::rotate(const float & angle){
}

//スケールを取得
void Actor::scale(const GSvector2 & scale){
}

// 子の検索 
ActorPtr Actor::findChildren_NullActor(const ActorName& name)
{
	ActorPtr result = findChildren([&](const Actor& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullActor>(p_World, p_GameManager);

	return result;
}

//子の検索
ActorPtr Actor::findChildren(std::function<bool(const Actor&)> fn)
{
	const auto& i
		= std::find_if(
			m_children.begin()
			, m_children.end()
			, [&](const ActorPtr& child)
	{ return fn(*child); });

	if (i != m_children.end())
	{
		return *i;
	}

	for (const auto& child : m_children)
	{
		const auto actor = child->findChildren(fn);

		if (actor != nullptr)
		{
			return actor;
		}
	}
	return nullptr;
}

// 子同士の衝突判定 
void Actor::collideChildren(Actor& other)
{
	eachChildren([&](Actor& my)
	{
		other.eachChildren([&](Actor& target)
		{
			my.collide(target);
		});
	});
}

// 兄弟同士の衝突判定 
void Actor::collideSibling()
{
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
	}
}

// 子の追加 
void Actor::addChild(const ActorPtr& child)
{
	m_children.push_front(child);
}

// 子を巡回 
void Actor::eachChildren(std::function<void(Actor&)> fn)
{
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

// 子を巡回 (const版) 
void Actor::eachChildren(std::function<void(const Actor&)> fn) const
{
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

// 子を削除する 
void Actor::removeChildren(std::function <bool(Actor& actor)> fn)
{
	m_children.remove_if([&](const ActorPtr& child) { return fn(*child); });
}

// 子を削除する 
void Actor::removeChildren()
{
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren(); });
}

// 子を消去 
void Actor::clearChildren()
{
	m_children.clear();
}

//ワールドを設定
void Actor::SetWorld(const IWorldPtr& world) {
	p_World = world;
}

//衝突判定図形の取得
IBodyPtr Actor::getBody() const {
	return m_Body;
}

//クローン生成
ActorPtr Actor::clone(const ActorPtr& source) {

	//実体生成
	GSvector2 pos = GSvector2(source->getPosition());

	//クローン生成
	ActorPtr result = std::make_shared<Actor>(
		source->p_World,
		source->getName(),
		pos,
		source->p_GameManager,
		source->p_Texture,
		source->m_Body);

	//結果を返す
	return result;
}

//クローン生成
ActorPtr Actor::clone(const GSvector2& position) {
	return nullptr;
}


// メッセージ処理 
void Actor::handleMessage(EventMessage message, void* param)
{
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

// メッセージ処理 
void Actor::onMessage(EventMessage, void*)
{
}

// 更新 
void Actor::onUpdate(float)
{
}

// 描画 
void Actor::onDraw() const {
	m_Body->transform(getPose())->draw();
}

// 衝突した 
void Actor::onCollide(Actor&)
{
	dead();
}

// 衝突判定 
bool Actor::isCollide(const Actor& other)
{
	// 回転を含む場合
	return m_Body->transform(getPose())->isCollide(*other.getBody()->transform(other.getPose()).get(), HitInfo());
}