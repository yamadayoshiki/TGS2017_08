#ifndef PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_H_

#include <functional>
#include <algorithm>
#include <vector>
#include <cassert>

template<typename Item, typename Comp=std::less<typename Item>>
class PriorityQueue {
public:
	// コンストラクタ
	PriorityQueue() : items_(), comp_() {
	}
	// コンストラクタ
	PriorityQueue(Comp comp) : items_(), comp_(comp) {
	}
	// データの追加
	void push(const Item& item) {
		items_.push_back(item);
		std::push_heap(items_.begin(), items_.end(), comp_);
	}
	// データの取り出し
	Item pop() {
		assert(!empty());
		std::pop_heap(items_.begin(), items_.end(), comp_);
		Item item = items_.back();
		items_.pop_back();
		return item;
	}
	// 優先順位の更新
	void update() {
		std::make_heap(items_.begin(), items_.end(), comp_);
	}
	// 空きかどうか？
	bool empty() const {
		return items_.empty();
	}
	// 消去
	void clear() {
		items_.clear();
	}

private:
	// データ
	std::vector<Item>	items_;
	// 比較関数
	Comp				comp_;
};


#endif
