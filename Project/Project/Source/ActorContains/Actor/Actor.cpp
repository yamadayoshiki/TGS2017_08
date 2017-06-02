#include <algorithm>

#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../Body/Base/HitInfo.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

#include <memory>

//�R���X�g���N�^
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

//�R���X�g���N�^
Actor::Actor(const ActorName& name)
	:Actor(
		nullptr,
		name,
		{ 0.0f,0.0f }
		, nullptr)
{
}

//���z�f�X�g���N�^
Actor::~Actor() {
}

//������
void Actor::initialize() {
}

//�X�V
void Actor::update(float deltaTime) {
	onUpdate(deltaTime);
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//�`��
void Actor::draw() const {
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//�Փ˔���(�����͎q������A�����͂���P��)
void Actor::collide(Actor& other) {
	if (isCollide(other))
	{
		onCollide(other);
		other.onCollide(*this);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// ���S���Ă��邩�H
bool Actor::GetDead() const {
	return m_dead;
}

//���S����
void Actor::dead() {
	m_dead = true;
}

//���O���擾
const ActorName Actor::getName() const {
	return m_Name;
}

//���W���擾
GSvector2 Actor::getPosition() const {
	return m_Transform.m_Position;
}

//�ϊ������擾
Transform Actor::getTransform() const {
	return m_Transform;
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
			my.collide(target);
		});
	});
}

//�Z�퓯�m�̏Փ˔���
void Actor::collideSibling() {
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
	}
}

//�q��ǉ�����
void Actor::addChild(const ActorPtr & child) {
	child->initialize();
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

//�q���폜����
void Actor::removeChildren() {
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren(); });
}

//�q������
void Actor::clearChildren() {
	m_children.clear();
}

//���b�Z�[�W����
void Actor::handleMessage(EventMessage message, void * param) {
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

//���[���h��ݒ�
void Actor::SetWorld(IWorld * world) {
	p_World = world;
}

//���[���h���擾
IWorld * Actor::getWorld() const {
	return p_World;
}

//�Փ˔���}�`�̎擾
IBodyPtr Actor::getBody() const {
	return p_Body->transform(getTransform());
}

int Actor::getCount() const{
	return std::distance(m_children.begin(), m_children.end());
}

//���W��ݒ�
void Actor::setPosition(const GSvector2 & pos) {
	m_Transform.m_Position = pos;
}

//�p�x��ݒ�
void Actor::setAngle(const float & angle) {
	m_Transform.m_Angle = angle;
}

//�e�N�X�`�����擾
ITexturePtr Actor::getTexture() const {
	return p_Texture;
}

//�N���[������(�g�p���p�����override)
ActorPtr Actor::clone(const GSvector2 & position, const FourDirection & front)
{
	return nullptr;
}

//���b�Z�[�W����
void Actor::onMessage(EventMessage message, void * param) {
}

//�e��ŗL�̍X�V
void Actor::onUpdate(float deltaTime) {
}

//�e��ŗL�̕`��
void Actor::onDraw() const {
	p_Body->transform(getTransform())->draw();
}

//�Փ˂���
void Actor::onCollide(Actor & other) {
	dead();
}

// �Փ˔���
bool Actor::isCollide(const Actor & other) {
	// ��]���܂ޏꍇ
	return p_Body->transform(getTransform())->isCollide(*other.getBody().get(), HitInfo());
}