#include <algorithm>

#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"
#include "../Transform/Transform.h"

#include <memory>

#include <chrono>

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
	, p_Transform(std::make_shared<Transform>(position, 0.0f))
	, p_Texture(texture)
	, p_Body(body)
	, m_dead(false) {
	p_Body->SetTransform(p_Transform);
}

//�R���X�g���N�^
Actor::Actor(const ActorName& name)
	:Actor(
		nullptr,
		name,
		{ 0.0f,0.0f }
		, nullptr) {
}

//���z�f�X�g���N�^
Actor::~Actor() {
}

//������
void Actor::initialize() {
}

//�X�V
void Actor::update(float deltaTime) {
	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
	//*/

	onUpdate(deltaTime);

	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << (int)m_Name << ":Update:" << elapsed << std::endl;
	//*/
	eachChildren([&](Actor& child) {child.update(deltaTime); });

}

//�`��
void Actor::draw() const {
	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
	//*/

	onDraw();

	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << (int)m_Name << ":Draw:" << elapsed << std::endl;
	//*/
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
			my.collide(target);
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
	for (auto it = m_children.begin(); it != m_children.end(); it++)
		(*it)->clearChildren();

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
bool Actor::isCollide(const Actor & other) {
	/*
	std::chrono::system_clock::time_point  start, end; // �^�� auto �ŉ�
	start = std::chrono::system_clock::now(); // �v���J�n����
	//*/

	// ��]���܂ޏꍇ
	bool result = p_Body->IsCollide(other.getBody().get());

	/*
	end = std::chrono::system_clock::now();  // �v���I������
	double elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); //�����ɗv�������Ԃ��~���b�ɕϊ�
	std::cout << ":Actor::isCollide:" << elapsed << std::endl;
	//*/

	return result;
}