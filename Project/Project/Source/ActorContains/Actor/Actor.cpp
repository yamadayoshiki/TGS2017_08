#include <algorithm>

#include "Actor.h"
#include "../NullActor/NullActor.h"
#include "../Body/Base/HitInfo.h"
#include "../../WorldContains/IWorld.h"
#include "../../TextureContains/NullTexture/NullTexture.h"

//�R���X�g���N�^
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

//���z�f�X�g���N�^
Actor::~Actor() {
}

//������
void Actor::initialize()
{

}
//�X�V
void Actor::update(float deltaTime)
{
	onUpdate(deltaTime);
	eachChildren([&](Actor& child) {child.update(deltaTime); });
}

//�`��
void Actor::draw() const
{
	onDraw();
	eachChildren([](const Actor& child) { child.draw(); });
}

//�Փ˔���(�����͎q������A�����͂���P��)
void Actor::collide(Actor& other)
{
	if (isCollide(other))
	{
		onCollide(other);
		other.onCollide(*this);
	}
	eachChildren([&](Actor& child) { child.collide(other); });
}

// ���S���Ă��邩�H 
bool Actor::GetDead() const
{
	return m_dead;
}

// ���S���� 
void Actor::dead()
{
	m_dead = true;
}

// ���O��Ԃ� 
const ActorName Actor::getName() const
{
	return m_Name;
}

// ���W��Ԃ� 
GSvector2 Actor::getPosition() const
{
	return m_Position;
}

//�s��̎擾
GSmatrix4 Actor::getMatrix() const {
	return m_Matrix;
}

//�|�[�Y�̎擾
GSmatrix4 Actor::getPose() const {
	return GSmatrix4(m_Matrix).translate(m_Position);
}

//��]���擾
void Actor::rotate(const float & angle){
}

//�X�P�[�����擾
void Actor::scale(const GSvector2 & scale){
}

// �q�̌��� 
ActorPtr Actor::findChildren_NullActor(const ActorName& name)
{
	ActorPtr result = findChildren([&](const Actor& actor) {return actor.getName() == name; });

	if (result == nullptr)
		result = std::make_shared<NullActor>(p_World, p_GameManager);

	return result;
}

//�q�̌���
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

// �q���m�̏Փ˔��� 
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

// �Z�퓯�m�̏Փ˔��� 
void Actor::collideSibling()
{
	for (auto i = m_children.begin(); i != m_children.end(); ++i)
	{
		std::for_each(std::next(i), m_children.end(), [&](const ActorPtr&  actor) { (*i)->collide(*actor); });
	}
}

// �q�̒ǉ� 
void Actor::addChild(const ActorPtr& child)
{
	m_children.push_front(child);
}

// �q������ 
void Actor::eachChildren(std::function<void(Actor&)> fn)
{
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

// �q������ (const��) 
void Actor::eachChildren(std::function<void(const Actor&)> fn) const
{
	std::for_each(m_children.begin(), m_children.end(), [&](const ActorPtr& child) { fn(*child); });
}

// �q���폜���� 
void Actor::removeChildren(std::function <bool(Actor& actor)> fn)
{
	m_children.remove_if([&](const ActorPtr& child) { return fn(*child); });
}

// �q���폜���� 
void Actor::removeChildren()
{
	removeChildren([](Actor& child) { return child.GetDead(); });
	eachChildren([](Actor& child) { child.removeChildren(); });
}

// �q������ 
void Actor::clearChildren()
{
	m_children.clear();
}

//���[���h��ݒ�
void Actor::SetWorld(const IWorldPtr& world) {
	p_World = world;
}

//�Փ˔���}�`�̎擾
IBodyPtr Actor::getBody() const {
	return m_Body;
}

//�N���[������
ActorPtr Actor::clone(const ActorPtr& source) {

	//���̐���
	GSvector2 pos = GSvector2(source->getPosition());

	//�N���[������
	ActorPtr result = std::make_shared<Actor>(
		source->p_World,
		source->getName(),
		pos,
		source->p_GameManager,
		source->p_Texture,
		source->m_Body);

	//���ʂ�Ԃ�
	return result;
}

//�N���[������
ActorPtr Actor::clone(const GSvector2& position) {
	return nullptr;
}


// ���b�Z�[�W���� 
void Actor::handleMessage(EventMessage message, void* param)
{
	onMessage(message, param);
	eachChildren([&](Actor& child) { child.handleMessage(message, param); });
}

// ���b�Z�[�W���� 
void Actor::onMessage(EventMessage, void*)
{
}

// �X�V 
void Actor::onUpdate(float)
{
}

// �`�� 
void Actor::onDraw() const {
	m_Body->transform(getPose())->draw();
}

// �Փ˂��� 
void Actor::onCollide(Actor&)
{
	dead();
}

// �Փ˔��� 
bool Actor::isCollide(const Actor& other)
{
	// ��]���܂ޏꍇ
	return m_Body->transform(getPose())->isCollide(*other.getBody()->transform(other.getPose()).get(), HitInfo());
}