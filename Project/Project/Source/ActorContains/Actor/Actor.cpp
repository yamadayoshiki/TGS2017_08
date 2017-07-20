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

//�R���X�g���N�^
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

//�R���X�g���N�^
Actor::Actor(const ActorName& name)
	: p_World(nullptr)
	, p_GameManager(nullptr)
	, m_Name(name)
	, p_Transform(std::make_shared<Transform>(GSvector2(0.0f, 0.0f), 0.0f))
	, p_Texture(std::make_shared<NullTexture>())
	, p_Body(std::make_shared<Body::NullBody>())
	, m_dead(false) {
}

//������
void Actor::initialize() {
	p_Texture->Initialize();
	onInitialize();
}

//�X�V
void Actor::update(float deltaTime) {
	//�e�N�X�`���X�V
	p_Texture->Update(deltaTime);
	//�e��ŗL�̍X�V
	onUpdate(deltaTime);
	//�q�̍X�V
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//�Փ˔����̍X�V
void Actor::LateUpdate() {
	//�e��ŗL�̍X�V
	OnLateUpdate();
	//���W&�p�x�ݒ�
	p_Texture->SetPosAndAngle(p_Transform->m_Position, p_Transform->m_Angle);
	//�q�̍X�V
	eachChildren([&](Actor& child) {child.LateUpdate(); });
}

//�`��
void Actor::draw() const {
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//�Փ˔���(�����͎q������A�����͂���P��)
void Actor::collide(Actor& other) {
	Body::ContactSet result = isCollide(other);
	if (result.m_IsCollide) {
		onCollide(other, result);
		other.onCollide(*this, result);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// ���S���Ă��邩�H
bool Actor::GetDead() const {
	return m_dead;
}

//���S����
void Actor::dead() {
	p_Texture->ChangeDisplayMode(DisplayMode::NonDisplay);
	m_dead = true;
}

//���O���擾
const ActorName Actor::getName() const {
	return m_Name;
}

//���W���擾
GSvector2 Actor::getPosition() const {
	return p_Transform->m_Position;
}

//�ϊ������擾
TransformPtr Actor::getTransform() const {
	return p_Transform;
}

//�q�̌���
ActorPtr Actor::findChildren_NullActor(const ActorName & name) {
	ActorPtr result = findChildren([&](const Actor& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullActor>(p_World, p_GameManager);

	return result;
}

//�q�̌����iNullPtr����j
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

//�q���m�̏Փ˔���
void Actor::collideChildren(Actor & other) {
	eachChildren([&](Actor& my)
	{
		other.eachChildren([&](Actor& target)
		{
			if (&my != &target)
				my.collide(target);
			//���g�̎q�Ƒ���̎q�̎q���Փ�
			collideChildren(target);
		});
	});
}

//�Z�퓯�m�̏Փ˔���
void Actor::collideSibling() {
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
}

//�q��ǉ�����
void Actor::addChild(const ActorPtr & child) {
	child->initialize();
	m_children.push_front(child);
}

void Actor::addChildNonInit(const ActorPtr & child){
	m_children.push_front(child);
}

//�q�����񂷂�
void Actor::eachChildren(std::function<void(Actor&)> fn) {
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

//�q�����񂷂�(const��)
void Actor::eachChildren(std::function<void(const Actor&)> fn) const {
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

//�q���폜����
void Actor::removeChildren(std::function<bool(Actor&actor)> fn) {
	m_children.remove_if([&](const ActorPtr& child) { return fn(*child); });
}

//�q���폜����(���񂾎q�̍폜)
void Actor::removeChildren_dead() {
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren_dead(); });
}

//�q������
void Actor::clearChildren() {
	for (auto it = m_children.begin(); it != m_children.end(); it++)
		(*it)->clearChildren();

	m_children.clear();
}

//���b�Z�[�W����
void Actor::handleMessage(EventMessage message, void * param) {
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

void Actor::handleMessageOne(EventMessage message, void * param) {
	onMessage(message, param);
}

//���[���h��ݒ�
void Actor::SetWorld(IWorld * world) {
	p_World = world;
}

//���[���h���擾
IWorld * Actor::getWorld() const {
	return p_World;
}

IGameManagerPtr Actor::GetGameMgr() const{
	return p_GameManager;
}

//�Փ˔���}�`�̎擾
Body::IBodyPtr Actor::getBody() const {
	return p_Body;
}

int Actor::getCount() const {
	return std::distance(m_children.begin(), m_children.end());
}

MapType Actor::GetMapType() const {
	return MapType::Default;
}

//���W��ݒ�
void Actor::setPosition(const GSvector2 & pos) {
	p_Transform->m_Position = pos;
}

//�p�x��ݒ�
void Actor::setAngle(const float & angle) {
	p_Transform->m_Angle = angle;
}

//�e�N�X�`�����擾
ITexturePtr Actor::getTexture() const {
	return p_Texture;
}

//csv�Ő���
ActorPtr Actor::CsvGenerate(const int x, const int y, const int csvparam) {
	return nullptr;
}

// �Փ˔���
Body::ContactSet Actor::isCollide(const Actor & other) {
	//���g�Ƃ̔���̏ꍇreturn
	if (this == &other) return Body::ContactSet();
	//�Փ˔���
	return p_Body->IsCollide(other.getBody().get());
}