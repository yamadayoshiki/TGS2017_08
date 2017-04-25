#include "AstarOpenList.h"

// コンストラクタ
AstarOpenList::AstarOpenList(const NodePtr & target) :
	front_(nullptr), target_(target) {
}

// 検索開始
void AstarOpenList::start(const NodePtr & start) {
	queue_.push(start);
}

// 空か？
bool AstarOpenList::empty() const {
	return queue_.empty();
}

// ノードの取得
void AstarOpenList::pop() {
	front_ = queue_.pop();
}

// 先頭のノードを取得
NodePtr AstarOpenList::front() const {
	return front_;
}

// ノードの追加
void AstarOpenList::push(const NodePtr & node) {
	if (!node->updated(*front_)) return;
	node->update(*front_, node->distance(*target_));
	queue_.push(node);
}

// 目的地に到達したか？
bool AstarOpenList::goal() const {
	return front_ == target_;
}

