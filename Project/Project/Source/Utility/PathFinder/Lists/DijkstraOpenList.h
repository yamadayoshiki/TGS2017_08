#ifndef DIJKSTRA_OPEN_LIST_H_
#define DIJKSTRA_OPEN_LIST_H_

#include "../Node/NodePriorityQueue.h"

class DijkstraOpenList {
public:
	// コンストラクタ
	DijkstraOpenList();
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
	// 目的地に到達したか？
	bool goal() const;

private:
	NodePtr		front_;

	NodePtr		target_;

	NodePriorityQueue	queue_;
};

#endif
