#include "NodePriorityQueue.h"

// コンストラクタ
NodePriorityQueue::NodePriorityQueue() : queue_(comp) {
}

// 空か？
bool NodePriorityQueue::empty() const {
	return queue_.empty();
}

// ノードの取得
NodePtr NodePriorityQueue::pop() {
	auto node = queue_.pop();
	node->close();
	return node;
}

// ノードの追加
void NodePriorityQueue::push(const NodePtr & node) {
	if (node->opened()) {
		queue_.update();
		return;
	}
	node->open();
	queue_.push(node);
}

bool NodePriorityQueue::comp(const NodePtr & n1, const NodePtr & n2) {
	return *n2 < *n1;
}
