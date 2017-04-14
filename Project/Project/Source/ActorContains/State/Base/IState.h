#pragma once

#include "ActionType.h"

// ��s�錾
class Actor;

// �X�e�[�g�N���X�̃C���^�[�t�F�[�X
class IState {
public:
	// �X�e�[�g�̗v�f
	struct Component {
		// �X�e�[�g��ID
		int mID;
		// �X�e�[�g�̃^�C�v
		ActionType mType;
	};
public:
	// ���z�f�X�g���N�^
	virtual ~IState() {}
	// �S��ԋ��ʂ̏�����
	virtual void common_init(Actor& actor, const Component comp) = 0;
	// �e��ԓƎ��̏�����
	virtual void unique_init(Actor& actor) = 0;
	// ���͏���
	virtual void input() = 0;
	// �X�V����
	virtual void update(Actor & actor, float deltaTime) = 0;
	// ���ԍX�V����
	virtual void timer(const float& deltaTime) = 0;
	// ��Ԃ̕ύX
	virtual void change(const Component comp) = 0;
	// �Փ˔���
	virtual void collide(const Actor & other) = 0;
	// �I����Ԃ�
	virtual bool isEnd() = 0;
	// ���̃X�e�[�g�̗v�f
	virtual Component next() const = 0;
	// �I�����̏���
	virtual void end() = 0;
};
