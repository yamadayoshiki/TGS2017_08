#pragma once

#include "../../../State/Base/StateMgr.h"

// ��s�錾
struct Vector3;
struct Matrix;

// �v���C���[�X�e�[�g�̃}�l�[�W���[
class PlayerStateMgr : public StateMgr{
public:
	// �R���X�g���N�^
	PlayerStateMgr();
	// �R���X�g���N�^
	PlayerStateMgr(Vector3& pos, Matrix& mat);
};