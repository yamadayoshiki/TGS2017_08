#include "RangeOpenList.h"

// コンストラクタ
RangeOpenList::RangeOpenList(float cost) :
	front_(nullptr), cost_(cost) {
}

// 検索開始
void RangeOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// 空か？
bool RangeOpenList::empty() const {
	return queue_.empty();
}

// ノードの取得
void RangeOpenList::pop() {
	front_ = queue_.pop();
}

// 先頭のノードを取得
NodePtr RangeOpenList::front() const {
	return front_;
}

// ノードの追加
void RangeOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_);
	if (node->total() < cost_) {
		queue_.push(node);
	}
}
