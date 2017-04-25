#include "NodePriorityQueue.h"

// �R���X�g���N�^
NodePriorityQueue::NodePriorityQueue() : queue_(comp) {
}

// �󂩁H
bool NodePriorityQueue::empty() const {
	return queue_.empty();
}

// �m�[�h�̎擾
NodePtr NodePriorityQueue::pop() {
	auto node = queue_.pop();
	node->close();
	return node;
}

// �m�[�h�̒ǉ�
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
