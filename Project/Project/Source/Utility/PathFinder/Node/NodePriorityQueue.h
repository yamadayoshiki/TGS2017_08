#ifndef NODE_PRIORITY_QUEUE_H_
#define NODE_PRIORITY_QUEUE_H_

#include "PriorityQueue.h"
#include "Node.h"
#include "NodePtr.h"

class NodePriorityQueue {
public:
	// �R���X�g���N�^
	NodePriorityQueue();
	// �󂩁H
	bool empty() const;
	// �m�[�h�̎擾
	NodePtr pop();
	// �m�[�h�̒ǉ�
	void push(const NodePtr& node);

private:
	static bool comp(const NodePtr& n1, const NodePtr& n2);

private:
	using CompNode = bool(*)(const NodePtr&, const NodePtr&);
	PriorityQueue<NodePtr, CompNode> queue_;
};

#endif

