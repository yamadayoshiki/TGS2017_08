#include "EnemyCommandAlongWallMove.h"
#include "../../../../../Define/Def_GSvector2.h"

//�R���X�g���N�^
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDirection(turnDirection)
	, m_NextTargetPos(GSVECTOR2_ZERO) {

}

//�X�V
void EnemyCommandAlongWallMove::Update(float deltaTime) {
}

//�I��
void EnemyCommandAlongWallMove::Finalize() {

}

//��]�����̐ݒ�
void EnemyCommandAlongWallMove::SetturnDirection(TurnDirection turnDirection) {
	m_TurnDirection = turnDirection;
}

//�e��ŗL�̏�����
void EnemyCommandAlongWallMove::OnInitialize() {

}

//�ڕW�n�_�̐ݒ�
void EnemyCommandAlongWallMove::SetTargetPos() {
	switch (m_TurnDirection)
	{
	case TurnDirection::Clockwise:
		break;
	case TurnDirection::AntiClockwise:
		break;
	}
}