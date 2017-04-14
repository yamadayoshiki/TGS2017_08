#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../ActorPtr.h"
#include "../ActorName.h"

enum class EventMessage;
class IWorld;

//�A�N�^�[�N���X
class Actor
{
public:
	//�R���X�g���N�^
	Actor(
		IWorld* world,
		const ActorName& name,
		const GSvector2& position
		);
	//�R���X�g���N�^
	explicit Actor(const ActorName& name = ActorName::None);
	//���z�f�X�g���N�^
	virtual ~Actor() {	}
	//�X�V
	void update(float deltaTime);
	//�`��
	void draw() const;
	//�Փ˔���(�����͎q������A�����͂���P��)
	void collide(Actor& other);
	//���S���Ă��邩
	bool GetDead() const;
	//���S����
	void dead();
	//���O��Ԃ�
	const ActorName getName() const;
	//���W��Ԃ�
	GSvector2 getPosition() const;
	//�q�̌���
	ActorPtr findChildren_NullActor(const ActorName& name);
	//�q�̌����iNullPtr����j
	ActorPtr findChildren(std::function<bool(const Actor&)> fn);
	//�q���m�̏Փ˔���
	void collideChidren(Actor& other);
	//�Z�퓯�m�̏Փ˔���
	void collideSibling();
	//�q�̒ǉ�
	void addChild(const ActorPtr& child);
	//�q������
	void eachChildren(std::function<void(Actor&)> fn);
	//�q������iconst�Łj
	void eachChildren(std::function<void(const Actor&)> fn) const;
	//�q���폜����
	void removeChildren(std::function <bool(Actor& actor)> fn);
	//�q���폜����
	void removeChildren();
	//�q������
	void clearChildren();
	//���b�Z�[�W����
	void handleMessage(EventMessage message, void* param);

	//���[���h��ݒ�
	void SetWorld(IWorld* world);

	//�R�s�[�֎~
	Actor(const Actor& other) = delete;
	Actor& operator = (const Actor& other) = delete;

private:
	//���b�Z�[�W����
	virtual void onMessage(EventMessage message, void* param);
	//�X�V
	virtual void onUpdate(float deltaTime);
	//�`��
	virtual void onDraw() const;
	//�Փ˂���
	virtual void onCollide(Actor& other);
	//�Փ˔���
	bool isCollide(const Actor& other) const;


protected:
	//���[���h
	IWorld* p_World;
	//���O
	ActorName m_Name;
	//���W
	GSvector2 m_Position;
	//���S�t���O
	bool m_dead;

private:
	//�q�A�N�^�[
	std::forward_list<ActorPtr> m_children;
};

#endif // !ACTOR_H_
