#ifndef PATH_FINDER_H_
#define PATH_FINDER_H_

#include "Node/NodeGrid.h"
#include "Lists/AstarOpenList.h"
#include "Lists/DijkstraOpenList.h"
#include "Lists/RangeOpenList.h"

class Map;

class PathFinder {
public:
	// コンストラクタ
	PathFinder(const Map& map);
	// 目標地点を検索
	std::vector<NodePtr> findTarget(const Point2& start, const Point2& target);
	// 複数の移動範囲を検索
	std::vector<NodePtr> findMultiTarget(const Point2& start);
	// 移動範囲の検索
	void findSearchRange(const Point2& start, float cost);
	// 目標地点の追加
	void addTarget(const Point2& target);
	// ノードの取得
	NodePtr operator [] (const Point2& position) const;
	// 検索パスノードの作成
	std::vector<NodePtr> createPath(const Point2& target) const;
	// グリッドの表示(デバッグ用）
	void darw_grid() {
		grid_.draw();
	}

private:
	template <typename Grid, typename List, typename Node>
	std::vector<Node> find_path(Grid& grid, List& list, const Node& start);

private:
	NodeGrid grid_;
};

#endif


