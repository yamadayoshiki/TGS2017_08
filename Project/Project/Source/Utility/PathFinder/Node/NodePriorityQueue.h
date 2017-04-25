#ifndef NODE_PRIORITY_QUEUE_H_
#define NODE_PRIORITY_QUEUE_H_

#include "PriorityQueue.h"
#include "Node.h"
#include "NodePtr.h"

class NodePriorityQueue {
public:
	// コンストラクタ
	NodePriorityQueue();
	// 空か？
	bool empty() const;
	// ノードの取得
	NodePtr pop();
	// ノードの追加
	void push(const NodePtr& node);

private:
	static bool comp(const NodePtr& n1, const NodePtr& n2);

private:
	using CompNode = bool(*)(const NodePtr&, const NodePtr&);
	PriorityQueue<NodePtr, CompNode> queue_;
};

#endif

