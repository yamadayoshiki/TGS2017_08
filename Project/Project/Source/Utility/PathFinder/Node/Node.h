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
	Point2	position_;	// ���H��̍��W
	bool	walkable_;	// �ړ��\���H
	float	cost_;		// �ړ��R�X�g
	Node*	parent_;	// �e�m�[�h
	bool	closed_;	// �������I�����Ă���H
	bool	opened_;	// ���������H
	bool	targeted_;	// �ڕW�n�_���H
	float	g_;			// �ړ��R�X�g�̍��v
	float	f_;			// �ړI�n�܂ł̌��ς���
	bool	path_;		// �o�H�ɂȂ��Ă���i�f�o�b�O�p�j
};

#endif
