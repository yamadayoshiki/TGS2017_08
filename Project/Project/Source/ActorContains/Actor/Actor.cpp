#include <algorithm>

#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../Body/Base/HitInfo.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

#include <memory>

//コンストラクタ
Actor::Actor(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gaemManager,
	const ITexturePtr& texture,
	const IBodyPtr& body)
	: p_World(world)
	, p_GameManager(gaemManager)
	, m_Name(name)
	, m_Transform({ position, 0.0f })
	, p_Texture(texture)
	, p_Body(body)
	, m_dead(false)
{
}

//コンストラクタ
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

//初期化
void Actor::initialize() {
}

//更新
void Actor::update(float deltaTime) {
	onUpdate(deltaTime);
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//描画
void Actor::draw() const {
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//衝突判定(自分は子を巡回、引数はそれ単体)
void Actor::collide(Actor& other) {
	if (isCollide(other))
	{
		onCollide(other);
		other.onCollide(*this);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// 死亡しているか？
bool Actor::GetDead() const {
	return m_dead;
}

//死亡する
void Actor::dead() {
	m_dead = true;
}

//名前を取得
const ActorName Actor::getName() const {
	return m_Name;
}

//座標を取得
GSvector2 Actor::getPosition() const {
	return m_Transform.m_Position;
}

//変換情報を取得
Transform Actor::getTransform() const {
	return m_Transform;
}

//子の検索
ActorPtr Actor::findChildren_NullActor(const ActorName & name) {
	ActorPtr result = findChildren([&](const Actor& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullActor>(p_World, p_GameManager);

	return result;
}

//子の検索（NullPtrあり）
ActorPtr Actor::findChildren(std::function<bool(const Actor&)> fn) {
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

//子同士の衝突判定
void Actor::collideChildren(Actor & other) {
	eachChildren([&](Actor& my)
	{
		other.eachChildren([&](Actor& target)
		{
			my.collide(target);
		});
	});
}

//兄弟同士の衝突判定
void Actor::collideSibling() {
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
	}
}

//子を追加する
void Actor::addChild(const ActorPtr & child) {
	child->initialize();
	m_children.push_front(child);
}

//子を巡回する
void Actor::eachChildren(std::function<void(Actor&)> fn) {
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

//子を巡回する(const版)
void Actor::eachChildren(std::function<void(const Actor&)> fn) const {
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

//子を削除する
void Actor::removeChildren(std::function<bool(Actor&actor)> fn) {
	m_children.remove_if([&](const ActorPtr& child) { return fn(*child); });
}

//子を削除する
void Actor::removeChildren() {
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren(); });
}

//子を消去
void Actor::clearChildren() {
	m_children.clear();
}

//メッセージ処理
void Actor::handleMessage(EventMessage message, void * param) {
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

//ワールドを設定
void Actor::SetWorld(IWorld * world) {
	p_World = world;
}

//ワールドを取得
IWorld * Actor::getWorld() const {
	return p_World;
}

//衝突判定図形の取得
IBodyPtr Actor::getBody() const {
	return p_Body->transform(getTransform());
}

int Actor::getCount() const{
	return std::distance(m_children.begin(), m_children.end());
}

//座標を設定
void Actor::setPosition(const GSvector2 & pos) {
	m_Transform.m_Position = pos;
}

//角度を設定
void Actor::setAngle(const float & angle) {
	m_Transform.m_Angle = angle;
}

//テクスチャを取得
ITexturePtr Actor::getTexture() const {
	return p_Texture;
}

//クローン生成(使用時継承先でoverride)
ActorPtr Actor::clone(const GSvector2 & position, const FourDirection & front)
{
	return nullptr;
}

//メッセージ処理
void Actor::onMessage(EventMessage message, void * param) {
}

//各種固有の更新
void Actor::onUpdate(float deltaTime) {
}

//各種固有の描画
void Actor::onDraw() const {
	p_Body->transform(getTransform())->draw();
}

//衝突した
void Actor::onCollide(Actor & other) {
	dead();
}

// 衝突判定
bool Actor::isCollide(const Actor & other) {
	// 回転を含む場合
	return p_Body->transform(getTransform())->isCollide(*other.getBody().get(), HitInfo());
}