#pragma once

// ��s�錾
class Actor;

#include <unordered_map>
#include "../../ActorPtr.h"

enum class ActorName;

// �X�e�[�g�N���X�̃C���^�[�t�F�[�X
class IState {
public:
	// ���z�f�X�g���N�^
	virtual ~IState() {}
	// �S��ԋ��ʂ̏�����
	virtual void common_init(const int id) = 0;
	// �e��ԓƎ��̏�����
	virtual void unique_init() = 0;
	// ���͏���
	virtual void input() = 0;
	// �X�V����
	virtual void update(float deltaTime) = 0;
	// ���ԍX�V����
	virtual void timer(const float& deltaTime) = 0;
	// ��Ԃ̕ύX
	virtual void change_int(const int id) = 0;
	// �Փ˔���
	virtual void collide(const Actor & other) = 0;
	// �I����Ԃ�
	virtual bool isEnd() = 0;
	// ���̃X�e�[�g�̗v�f
	virtual int next() const = 0;
	// �I�����̏���
	virtual void end() = 0;
	// �q�̒ǉ�
	virtual void addChild(const ActorName& name, const ActorPtr& child) = 0;
};