#ifndef COMPOSITE_H_
#define COMPOSITE_H_
#include "../Component/Component.h"
#include <forward_list>
//�R���|�W�b�g(�})
class Composite : public Component
{
public:
	//�R���X�g���N�^
	Composite();
	//�f�X�g���N�^
	~Composite();
	//�q��ǉ�
	virtual void AddChild(ComponentSPtr child) override;
	//�q����菜��
	virtual void RemoveChild(ComponentSPtr child) override;
	//�q�̐����擾
	virtual int ChildrenCount() override;

private:
	std::forward_list<ComponentSPtr> m_Children;	//�q�z��
};

#endif // !COMPOSITE_H_
