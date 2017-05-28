#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// �e�N�X�`�������N���X
class SpriteCreator : public Actor {
	enum class Element {
		NAME = 0,		// �e�N�X�`���̖��O
		ANIMATE = 1,	// �A�j���[�V�������邩���Ȃ���
		WIDTH = 2,		// �\�������e�N�X�`���̉���
		HEIGHT = 3,		// �\�������e�N�X�`���̏c��
		POS_X = 4,		// �e�N�X�`���̍��W
		POS_Y = 5,		// �e�N�X�`���̍��W
		TIME = 6,		// �P�t���[���̍Đ�����
		ANGLE = 7,		// �p�x
		ALPHA = 8,		// �����x
	};
public:
	// �R���X�g���N�^
	SpriteCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// ����
	void create(const std::string & file_name);
};