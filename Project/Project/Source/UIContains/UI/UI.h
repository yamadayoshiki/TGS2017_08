#ifndef UI_H_
#define UI_H_

#include <gslib.h>
#include <memory>
#include <string>
#include <functional>
#include <forward_list>

#include "../UIPtr.h"
#include "../UIName.h"

enum class EventMessage;
class IWorld;

//UI�N���X
class UI{
public:
	//�R���X�g���N�^
	UI(IWorld* world, const UIName& name, const GSvector2& position);
	//�R���X�g���N�^
	explicit UI(const UIName& name = UIName::None);
	//���z�f�X�g���N�^
	virtual ~UI() {	}
	//�X�V
	void update(float deltaTime);
	//�`��
	void draw() const;
	//���S���Ă��邩
	bool GetDead() const;
	//���S����
	void dead();
	//���O��Ԃ�
	const UIName getName() const;
	//���W��Ԃ�
	GSvector2 getPosition() const;
	//�q�̌���
	UIPtr findChildren_NullActor(const UIName& name);
	//�q�̌����iNullPtr����j
	UIPtr findChildren(std::function<bool(const UI&)> fn);
	//�q�̒ǉ�
	void addChild(const UIPtr& child);
	//�q������
	void eachChildren(std::function<void(UI&)> fn);
	//�q������iconst�Łj
	void eachChildren(std::function<void(const UI&)> fn) const;
	//�q���폜����
	void removeChildren(std::function <bool(UI& actor)> fn);
	//�q���폜����
	void removeChildren();
	//�q������
	void clearChildren();
	//���b�Z�[�W����
	void handleMessage(EventMessage message, void* param);

	//���[���h��ݒ�
	void SetWorld(IWorld* world);

	//�R�s�[�֎~
	UI(const UI& other) = delete;
	UI& operator = (const UI& other) = delete;

private:
	//���b�Z�[�W����
	virtual void onMessage(EventMessage message, void* param);
	//�X�V
	virtual void onUpdate(float deltaTime);
	//�`��
	virtual void onDraw() const;

protected:
	//���[���h
	IWorld* p_World;
	//���O
	UIName m_Name;
	//���W
	GSvector2 m_Position;
	//���S�t���O
	bool m_dead;

private:
	//�qUI
	std::forward_list<UIPtr> m_children;
};

#endif // !UI_H_
