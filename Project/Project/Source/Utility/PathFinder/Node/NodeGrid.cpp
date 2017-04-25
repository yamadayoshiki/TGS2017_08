#include "NodeGrid.h"
#include "../../../Map/Map.h"

NodeGrid::NodeGrid(const Map& map) :
	width_(map.Width()),
	height_(map.Height()) {
	createNode(map);
}

NodePtr NodeGrid::operator [] (const Point2& position) const {
	assert(isInside(position));
	return grid_[position.y][position.x];
}

bool NodeGrid::isInside(const Point2 & position) const {
	return (position.x >= 0) && (position.x < width_)
		&& (position.x >= 0) && (position.y < height_);
}

void NodeGrid::neighbors(const NodePtr & node, std::function<void(const NodePtr&)> fn) const {
	std::array<Point2, 4> directions = {
		Point2(1, 0), Point2(-1, 0), Point2(0, 1), Point2(0, -1)
	};
	for (const auto& dir : directions) {
		if (opened(node->position() + dir)) {
			fn((*this)[node->position() + dir]);
		}
	}
}

std::vector<NodePtr> NodeGrid::createPath(const NodePtr & goal) const {
	std::vector<NodePtr> pathNode;
	goal->backtrack(
		[&](const Node& node) {
			pathNode.push_back((*this)[node.position()]);
		}
	);
	return pathNode;
}

void NodeGrid::draw() const {
	Point2 position;
	for (position.y = 0; position.y < height_; ++position.y) {
		for (position.x = 0; position.x < width_; ++position.x) {
			std::cout << (*this)[position]->to_string();
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void NodeGrid::createNode(const Map & map) {
	grid_.clear();
	Point2 position;
	for (position.y = 0; position.y < height_; ++position.y) {
		std::vector<NodePtr> row;
		for (position.x = 0; position.x < width_; ++position.x) {
			row.push_back(std::make_shared<Node>(position, !map[position]));
		}
		grid_.push_back(row);
	}
}

bool NodeGrid::opened(const Point2 & position) const {
	return isInside(position)
		&& (*this)[position]->wakable()
		&& (*this)[position]->closed() == false;
}
