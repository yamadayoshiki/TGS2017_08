#include "Node.h"

Node::Node(const Point2 & position, bool walkable) :
	position_(position),
	walkable_(walkable),
	cost_(1.0f),
	parent_(nullptr),
	opened_(false),
	closed_(false),
	targeted_(false),
	g_(0.0f),
	f_(0.0f),
	path_(false) {
}

Point2 Node::position() const {
	return position_;
}

float Node::total() const {
	return g_;
}

bool Node::updated(const Node & parent) const {
	if (!opened())                return true;
	if ((parent.g_ + cost_) < g_) return true;
	return false;
}

void Node::update(Node & parent, float h) {
	g_ = parent.g_ + cost_;
	f_ = g_ + h;
	parent_ = &parent;
}

void Node::open() {
	opened_ = true;
}

bool Node::opened() const {
	return opened_;
}

bool Node::closed() const {
	return closed_;
}

void Node::close() {
	closed_ = true;
}

void Node::target() {
	targeted_ = true;
}

bool Node::targeted() const {
	return targeted_;
}

bool Node::wakable() const {
	return walkable_;
}

float Node::distance(const Node & target) {
	return position_.distance(target.position_);
}

void Node::backtrack(std::function<void(Node&)> f) {
	for (auto node = this; node != nullptr; node = node->parent_) {
		f(*node);
		node->path_ = true; // デバッグ用
	}
}

bool Node::operator < (const Node& other) const {
	return f_ < other.f_;
}

std::string Node::to_string() const {
	if (!walkable_) return "■";
	if (path_)      return "▽";
	if (closed_)    return "×";
	if (opened_)    return "○";
	if (targeted_)  return "◎";
	return "　";
}
