#pragma once

#include "../../WorldContains/IWorld.h"
#include "../../ActorContains/Actor/Actor.h"

// �e�N�X�`�������N���X
class SpriteCreator : public Actor {
	enum class Element {
		NAME = 0,	// �e�N�X�`���̖��O
		ANIMATE,	// �A�j���[�V�������邩���Ȃ���
		WIDTH,		// �\�������e�N�X�`���̉���
		HEIGHT,		// �\�������e�N�X�`���̏c��
		POS_X,		// �e�N�X�`���̍��W
		POS_Y,		// �e�N�X�`���̍��W
		TIME,		// �P�t���[���̍Đ�����
		USAGE,		// �p�r
		DRAWORDER,	// �`�揇��
	};
public:
	// �R���X�g���N�^
	SpriteCreator(IWorld* world, const GSvector2& position, const IGameManagerPtr& gameManager, const std::string & file_name);
	// ����
	void create(const std::string & file_name);
};