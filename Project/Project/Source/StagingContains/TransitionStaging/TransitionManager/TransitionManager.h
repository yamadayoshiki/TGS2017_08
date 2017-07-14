#ifndef TRANSITIONMANAGER_H_
#define TRANSITIONMANAGER_H_
#include "../TransitionPtr.h"
#include <functional>
#include <stack>
//シーンインターフェイス
class TransitionManager
{
public:
	// コンストラクタ
	TransitionManager();
	// デフォルトコンストラクタ
	//TransitionManager();
	// 追加
	void addTransition( const TransitionPtr& transition);
	// 更新処理
	void update(float deltaTime);
	// 
	void change();
protected:
	std::stack<TransitionPtr> m_Transitions;
};
#endif // !TRANSITIONMANAGER_H_