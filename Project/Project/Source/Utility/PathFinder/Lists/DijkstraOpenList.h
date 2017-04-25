#ifndef DIJKSTRA_OPEN_LIST_H_
#define DIJKSTRA_OPEN_LIST_H_

#include "../Node/NodePriorityQueue.h"

class DijkstraOpenList {
public:
	// �R���X�g���N�^
	DijkstraOpenList();
	// �����J�n
	void start(const NodePtr& start);
	// �󂩁H
	bool empty() const;
	// �m�[�h�̎擾
	void pop();
	// �擪�̃m�[�h���擾
	NodePtr front() const;
	// �m�[�h�̒ǉ�
	void push(const NodePtr& node);
	// �ړI�n�ɓ��B�������H
	bool goal() const;

private:
	NodePtr		front_;

	NodePtr		target_;

	NodePriorityQueue	queue_;
};

#endif
