#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// �e�L�X�g�����N���X
class TextCreator : public Actor {
	enum class Element {
		NAME = 0,		// �摜�̖��O
		ANIMATE = 1,	// �A�j���[�V�������邩���Ȃ���
		WIDTH = 2,		// �\�������摜�̉���
		HEIGHT = 3,		// �\�������摜�̏c��
		POS_X = 4,		// �摜�̍��W
		POS_Y = 5,		// �摜�̍��W
		TIME = 6,		// �P�t���[���̍Đ�����
		ANGLE = 7,		// �p�x
		ALPHA = 8,		// �����x
	};
public:
	// �R���X�g���N�^
	TextCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// ����
	void create(const std::string & file_name);
};