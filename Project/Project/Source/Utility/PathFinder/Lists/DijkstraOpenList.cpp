#include "DijkstraOpenList.h"

// �R���X�g���N�^
DijkstraOpenList::DijkstraOpenList() :
	front_(nullptr) {
}

// �����J�n
void DijkstraOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// �󂩁H
bool DijkstraOpenList::empty() const {
	return queue_.empty();
}

// �m�[�h�̎擾
void DijkstraOpenList::pop() {
	front_ = queue_.pop();
}

// �擪�̃m�[�h���擾
NodePtr DijkstraOpenList::front() const {
	return front_;
}

// �m�[�h�̒ǉ�
void DijkstraOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_);
	queue_.push(node);
}

// �ړI�n�ɓ��B�������H
bool DijkstraOpenList::goal() const {
	return front_->targeted();
}
