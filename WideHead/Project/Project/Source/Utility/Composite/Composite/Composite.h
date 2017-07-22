#ifndef COMPOSITE_H_
#define COMPOSITE_H_
#include "../Component/Component.h"
#include <forward_list>
//コンポジット(枝)
class Composite : public Component
{
public:
	//コンストラクタ
	Composite();
	//デストラクタ
	~Composite();
	//子を追加
	virtual void AddChild(ComponentSPtr child) override;
	//子を取り除く
	virtual void RemoveChild(ComponentSPtr child) override;
	//子の数を取得
	virtual int ChildrenCount() override;

private:
	std::forward_list<ComponentSPtr> m_Children;	//子配列
};

#endif // !COMPOSITE_H_
