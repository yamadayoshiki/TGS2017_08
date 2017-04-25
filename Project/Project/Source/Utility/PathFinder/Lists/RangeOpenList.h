#ifndef RANGE_OPEN_LIST_H_
#define RANGE_OPEN_LIST_H_

#include "../Node/NodePriorityQueue.h"

class RangeOpenList {
public:
	// �R���X�g���N�^
	RangeOpenList(float cost);
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

private:
	NodePtr				front_;
	float				cost_;
	NodePriorityQueue	queue_;
};

#endif
