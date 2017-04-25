#include "PathFinder.h"

template<typename Grid, typename List, typename Node>
inline std::vector<Node> PathFinder::find_path(Grid & grid, List & list, const Node & start) {
	list.start(start);
	//grid.draw();
	while (!list.empty()) {
		list.pop();
		if (list.goal()) {
			return grid.createPath(list.front());
		}
		grid.neighbors(list.front(),
			[&](const Node& node) { list.push(node); });
		//grid.draw();
	}
	return std::vector<Node>();
}

// �R���X�g���N�^
PathFinder::PathFinder(const Map & map) : grid_(map) {
}

// �ڕW�n�_������
std::vector<NodePtr> PathFinder::findTarget(const Point2 & start, const Point2 & target) {
	AstarOpenList list(grid_[target]);
	return find_path(grid_, list, grid_[start]);
}

// �����̈ړ��͈͂�����
std::vector<NodePtr> PathFinder::findMultiTarget(const Point2 & start) {
	DijkstraOpenList list;
	return find_path(grid_, list, grid_[start]);
}

// �ړ��͈͂̌���
void PathFinder::findSearchRange(const Point2 & start, float cost) {
	RangeOpenList list(cost);
	list.start(grid_[start]);
	while (!list.empty()) {
		list.pop();
		grid_.neighbors(list.front(), [&](const NodePtr& node) { list.push(node); });
		//grid_.draw(); // �f�o�b�O�\��
	}
}

// �ڕW�n�_�̒ǉ�
void PathFinder::addTarget(const Point2 & target) {
	grid_[target]->target();
}

// �m�[�h�̎擾
NodePtr PathFinder::operator [] (const Point2& position) const {
	return grid_[position];
}

// �����p�X�m�[�h�̍쐬
std::vector<NodePtr> PathFinder::createPath(const Point2 & target) const {
	return grid_.createPath(grid_[target]);
}
