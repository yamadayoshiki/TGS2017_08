#include "RangeOpenList.h"

// �R���X�g���N�^
RangeOpenList::RangeOpenList(float cost) :
	front_(nullptr), cost_(cost) {
}

// �����J�n
void RangeOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// �󂩁H
bool RangeOpenList::empty() const {
	return queue_.empty();
}

// �m�[�h�̎擾
void RangeOpenList::pop() {
	front_ = queue_.pop();
}

// �擪�̃m�[�h���擾
NodePtr RangeOpenList::front() const {
	return front_;
}

// �m�[�h�̒ǉ�
void RangeOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_);
	if (node->total() < cost_) {
		queue_.push(node);
	}
}
