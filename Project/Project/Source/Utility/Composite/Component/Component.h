#ifndef COMPONENT_H_
#define COMPONENT_H_
#include "ComponentPtr.h"
//�R���|�[�l���g(���)
class Component
{
public:
	//�R���X�g���N�^
	Component();
	//���z�f�X�g���N�^
	virtual ~Component();
	//�q��ǉ�
	virtual void AddChild(ComponentSPtr child) {}
	//�q����菜��
	virtual void RemoveChild(ComponentSPtr child) {}
	//�q���擾
	virtual ComponentSPtr GetChild(int index) { return nullptr; }
	//�q�̐����擾
	virtual int ChildrenCount() { return 0; }
};

inline Component::Component() 
{
}

inline Component::~Component()
{
}

#endif // !COMPONENT_H_
