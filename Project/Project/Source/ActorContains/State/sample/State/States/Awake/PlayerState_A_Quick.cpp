#include "PlayerState_A_Quick.h"

// �R���X�g���N�^
PlayerState_A_Quick::PlayerState_A_Quick(Vector3& pos, Matrix& mat) : PlayerState(pos, mat) {}

// �e��ԌŗL�̏�����
void PlayerState_A_Quick::unique_init(Actor & actor) {}

// �X�V����
void PlayerState_A_Quick::update(Actor & actor, float  deltaTime) {}

// �Փ˔���
void PlayerState_A_Quick::collide(const Actor & other){}

// �I�����̏���
void PlayerState_A_Quick::end() { }

// ���͏���
void PlayerState_A_Quick::input() {}

