#ifndef NUMBERCREATOR_H_
#define NUMBERCREATOR_H_
#include "../../ActorContains/Actor/Actor.h"
//�����e�N�X�`�������N���X
class NumberCreator : public Actor {
	enum class Element {
		NAME = 0,	// �e�N�X�`���̖��O
		POS_X,		// �E����W.x
		POS_Y,		// �E����W.y
		LENGTH,		// �\������
		USAGE,		// �p�r
		DRAWORDER,	// �`�揇��
	};
public:
	//�R���X�g���N�^
	NumberCreator(
		IWorld* world,
		const GSvector2& position,
		const IGameManagerPtr& gameManager,
		const std::string & file_name);
	// ����
	void Create(const std::string & file_name);
};

#endif // !NUMBERCREATOR_H_
