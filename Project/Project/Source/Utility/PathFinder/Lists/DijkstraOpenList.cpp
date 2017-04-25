#include "DijkstraOpenList.h"

// コンストラクタ
DijkstraOpenList::DijkstraOpenList() :
	front_(nullptr) {
}

// 検索開始
void DijkstraOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// 空か？
bool DijkstraOpenList::empty() const {
	return queue_.empty();
}

// ノードの取得
void DijkstraOpenList::pop() {
	front_ = queue_.pop();
}

// 先頭のノードを取得
NodePtr DijkstraOpenList::front() const {
	return front_;
}

// ノードの追加
void DijkstraOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_);
	queue_.push(node);
}

// 目的地に到達したか？
bool DijkstraOpenList::goal() const {
	return front_->targeted();
}
