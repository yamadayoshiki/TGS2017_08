#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"
#include "../Transform/Transform.h"
#include "../../TextureContains/ITexture.h"
#include "../../Utility/Texture2DParameter/Texture2DParameter.h"
#include "../../ActorContains/BodyContains/Elements/ContactSet/ContactSet.h"
#include "../BodyContains/Factory/BodyFactory.h"
#include "../BodyContains/Interface/IBody.h"
#include "../BodyContains/NullBody/NullBody.h"
#include <memory>
#include <chrono>
#include <algorithm>

//コンストラクタ
Actor::Actor(
	IWorld* world,
	const ActorName& name,
	const GSvector2& position,
	const IGameManagerPtr& gameManager,
	const ITexturePtr& texture,
	const Body::MotionType type,
	const Body::BodyDataName dataName)
	: p_World(world)
	, p_GameManager(gameManager)
	, m_Name(name)
	, p_Transform(std::make_shared<Transform>(position, 0.0f))
	, p_Texture(texture)
	, m_dead(false) {
	p_Body = world->GetBodyFactory()->Generate(type, dataName);
	p_Body->SetTransform(p_Transform);
	p_Texture->SetPosAndAngle(p_Transform->m_Position, p_Transform->m_Angle);
}

//コンストラクタ
Actor::Actor(const ActorName& name)
	: p_World(nullptr)
	, p_GameManager(nullptr)
	, m_Name(name)
	, p_Transform(std::make_shared<Transform>(GSvector2(0.0f, 0.0f), 0.0f))
	, p_Texture(std::make_shared<NullTexture>())
	, p_Body(std::make_shared<Body::NullBody>())
	, m_dead(false) {
}

//初期化
void Actor::initialize() {
	p_Texture->Initialize();
	onInitialize();
}

//更新
void Actor::update(float deltaTime) {
	//テクスチャ更新
	p_Texture->Update(deltaTime);
	//各種固有の更新
	onUpdate(deltaTime);
	//子の更新
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//衝突判定後の更新
void Actor::LateUpdate() {
	//各種固有の更新
	OnLateUpdate();
	//座標&角度設定
	p_Texture->SetPosAndAngle(p_Transform->m_Position, p_Transform->m_Angle);
	//子の更新
	eachChildren([&](Actor& child) {child.LateUpdate(); });
}

//描画
void Actor::draw() const {
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//衝突判定(自分は子を巡回、引数はそれ単体)
void Actor::collide(Actor& other) {
	Body::ContactSet result = isCollide(other);
	if (result.m_IsCollide) {
		onCollide(other, result);
		other.onCollide(*this, result);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// 死亡しているか？
bool Actor::GetDead() const {
	return m_dead;
}

//死亡する
void Actor::dead() {
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
	m_dead = true;
}

//名前を取得
const ActorName Actor::getName() const {
	return m_Name;
}

//座標を取得
GSvector2 Actor::getPosition() const {
	return p_Transform->m_Position;
}

//変換情報を取得
TransformPtr Actor::getTransform() const {
	return p_Transform;
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
			if (&my != &target)
				my.collide(target);
			//自身の子と相手の子の子を衝突
			collideChildren(target);
		});
	});
}

//兄弟同士の衝突判定
void Actor::collideSibling() {
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
}

//子を追加する
void Actor::addChild(const ActorPtr & child) {
	child->initialize();
	m_children.push_front(child);
}

void Actor::addChildNonInit(const ActorPtr & child){
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

//子を削除する(死んだ子の削除)
void Actor::removeChildren_dead() {
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren_dead(); });
}

//子を消去
void Actor::clearChildren() {
	for (auto it = m_children.begin(); it != m_children.end(); it++)
		(*it)->clearChildren();

	m_children.clear();
}

//メッセージ処理
void Actor::handleMessage(EventMessage message, void * param) {
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

void Actor::handleMessageOne(EventMessage message, void * param) {
	onMessage(message, param);
}

//ワールドを設定
void Actor::SetWorld(IWorld * world) {
	p_World = world;
}

//ワールドを取得
IWorld * Actor::getWorld() const {
	return p_World;
}

IGameManagerPtr Actor::GetGameMgr() const{
	return p_GameManager;
}

//衝突判定図形の取得
Body::IBodyPtr Actor::getBody() const {
	return p_Body;
}

int Actor::getCount() const {
	return std::distance(m_children.begin(), m_children.end());
}

MapType Actor::GetMapType() const {
	return MapType::Default;
}

//座標を設定
void Actor::setPosition(const GSvector2 & pos) {
	p_Transform->m_Position = pos;
}

//角度を設定
void Actor::setAngle(const float & angle) {
	p_Transform->m_Angle = angle;
}

//テクスチャを取得
ITexturePtr Actor::getTexture() const {
	return p_Texture;
}

//csvで生成
ActorPtr Actor::CsvGenerate(const int x, const int y, const int csvparam) {
	return nullptr;
}

// 衝突判定
Body::ContactSet Actor::isCollide(const Actor & other) {
	//自身との判定の場合return
	if (this == &other) return Body::ContactSet();
	//衝突判定
	return p_Body->IsCollide(other.getBody().get());
}