#include "AstarOpenList.h"

// �R���X�g���N�^
AstarOpenList::AstarOpenList(const NodePtr & target) :
	front_(nullptr), target_(target) {
}

// �����J�n
void AstarOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// �󂩁H
bool AstarOpenList::empty() const {
	return queue_.empty();
}

// �m�[�h�̎擾
void AstarOpenList::pop() {
	front_ = queue_.pop();
}

// �擪�̃m�[�h���擾
NodePtr AstarOpenList::front() const {
	return front_;
}

// �m�[�h�̒ǉ�
void AstarOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_, node->distance(*target_));
	queue_.push(node);
}

// �ړI�n�ɓ��B�������H
bool AstarOpenList::goal() const {
	return front_ == target_;
}

