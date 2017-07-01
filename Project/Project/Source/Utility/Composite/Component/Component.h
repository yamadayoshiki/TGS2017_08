#ifndef COMPONENT_H_
#define COMPONENT_H_
#include "ComponentPtr.h"
//コンポーネント(基底)
class Component
{
public:
	//コンストラクタ
	Component();
	//仮想デストラクタ
	virtual ~Component();
	//子を追加
	virtual void AddChild(ComponentSPtr child) {}
	//子を取り除く
	virtual void RemoveChild(ComponentSPtr child) {}
	//子を取得
	virtual ComponentSPtr GetChild(int index) { return nullptr; }
	//子の数を取得
	virtual int ChildrenCount() { return 0; }
};

inline Component::Component() 
{
}

inline Component::~Component()
{
}

#endif // !COMPONENT_H_
