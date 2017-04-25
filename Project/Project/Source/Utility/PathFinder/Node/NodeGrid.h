#ifndef NODE_GRID_H_
#define NODE_GRID_H_

#include "Node.h"
#include "NodePtr.h"
#include <vector>
#include <array>
#include <functional>
#include <iostream>
#include <cassert>

class Map;

class NodeGrid {
public:
	NodeGrid(const Map& map);
	NodePtr operator [] (const Point2& position) const;
	bool isInside(const Point2& position) const;
	void neighbors(const NodePtr& node, std::function<void(const NodePtr&)> fn) const;
	std::vector<NodePtr> createPath(const NodePtr& goal) const;
	void draw() const;

private:
	void createNode(const Map& map);
	bool opened(const Point2& position) const;

private:
	// ïù
	int width_;
	// çÇÇ≥
	int height_;
	// äiéqÉmÅ[Éh
	std::vector<std::vector<NodePtr>> grid_;
};

#endif