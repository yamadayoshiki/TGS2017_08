#ifndef PATH_FINDER_H_
#define PATH_FINDER_H_

#include "Node/NodeGrid.h"
#include "Lists/AstarOpenList.h"
#include "Lists/DijkstraOpenList.h"
#include "Lists/RangeOpenList.h"

class Map;

class PathFinder {
public:
	// �R���X�g���N�^
	PathFinder(const Map& map);
	// �ڕW�n�_������
	std::vector<NodePtr> findTarget(const Point2& start, const Point2& target);
	// �����̈ړ��͈͂�����
	std::vector<NodePtr> findMultiTarget(const Point2& start);
	// �ړ��͈͂̌���
	void findSearchRange(const Point2& start, float cost);
	// �ڕW�n�_�̒ǉ�
	void addTarget(const Point2& target);
	// �m�[�h�̎擾
	NodePtr operator [] (const Point2& position) const;
	// �����p�X�m�[�h�̍쐬
	std::vector<NodePtr> createPath(const Point2& target) const;
	// �O���b�h�̕\��(�f�o�b�O�p�j
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


