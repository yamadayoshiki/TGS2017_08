#ifndef RANGE_OPEN_LIST_H_
#define RANGE_OPEN_LIST_H_

#include "../Node/NodePriorityQueue.h"

class RangeOpenList {
public:
	// コンストラクタ
	RangeOpenList(float cost);
	// 検索開始
	void start(const NodePtr& start);
	// 空か？
	bool empty() const;
	// ノードの取得
	void pop();
	// 先頭のノードを取得
	NodePtr front() const;
	// ノードの追加
	void push(const NodePtr& node);

private:
	NodePtr				front_;
	float				cost_;
	NodePriorityQueue	queue_;
};

#endif
