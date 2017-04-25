#ifndef NODE_H_
#define NODE_H_

#include "../Point2.h"
#include <string>
#include <functional>

class Node {
public:
	Node(const Point2& position, bool walkable);
	Point2 position() const;
	float total() const;
	bool updated(const Node& parent) const;
	void update(Node& parent, float h = 0.0f);
	void open();
	bool opened() const;
	bool closed() const;
	void close();
	void target();
	bool targeted() const;
	bool wakable() const;
	float distance(const Node& target);
	void backtrack(std::function<void(Node&)> f);
	bool operator < (const Node& other) const;
	std::string to_string() const;

private:
	Point2	position_;	// 迷路上の座標
	bool	walkable_;	// 移動可能か？
	float	cost_;		// 移動コスト
	Node*	parent_;	// 親ノード
	bool	closed_;	// 検索が終了している？
	bool	opened_;	// 検索中か？
	bool	targeted_;	// 目標地点か？
	float	g_;			// 移動コストの合計
	float	f_;			// 目的地までの見積もり
	bool	path_;		// 経路になっている（デバッグ用）
};

#endif
