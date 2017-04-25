#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <functional>
#include <algorithm>
#include <vector>
#include <cassert>

template<typename Item, typename Comp=std::less<typename Item>>
class PriorityQueue {
public:
	// �R���X�g���N�^
	PriorityQueue() : items_(), comp_() {
	}
	// �R���X�g���N�^
	PriorityQueue(Comp comp) : items_(), comp_(comp) {
	}
	// �f�[�^�̒ǉ�
	void push(const Item& item) {
		items_.push_back(item);
		std::push_heap(items_.begin(), items_.end(), comp_);
	}
	// �f�[�^�̎��o��
	Item pop() {
		assert(!empty());
		std::pop_heap(items_.begin(), items_.end(), comp_);
		Item item = items_.back();
		items_.pop_back();
		return item;
	}
	// �D�揇�ʂ̍X�V
	void update() {
		std::make_heap(items_.begin(), items_.end(), comp_);
	}
	// �󂫂��ǂ����H
	bool empty() const {
		return items_.empty();
	}
	// ����
	void clear() {
		items_.clear();
	}

private:
	// �f�[�^
	std::vector<Item>	items_;
	// ��r�֐�
	Comp				comp_;
};


#endif
