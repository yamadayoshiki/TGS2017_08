#include "EnemyCommandAlongWallMove.h"
#include "../../../../../Define/Def_GSvector2.h"
#include "../../../Enemys/Base/EnemyBase.h"
#include "../../../../../WorldContains/IWorld.h"
#include "../../../../../Map/Map.h"
#include "../../../../../Define/Def_Float.h"
#include "../../../../../ActorContains/Transform/Transform.h"
#include "../../../../../Utility/MathSupport/MathSupport.h"

//�R���X�g���N�^
EnemyCommandAlongWallMove::EnemyCommandAlongWallMove(const EnemyBasePtr& enemy, const TurnDirection turnDirection)
	:EnemyCommandBase(enemy)
	, m_TurnDirection(turnDirection)
	, m_CurDirection(enemy->getTransform().m_Angle)
	, m_NextTargetPos(GSVECTOR2_ZERO) {
	// �ǂɔw�������Ă���O��ŖڕW�n�_��ݒ�
	SetTargetPos();
}

//�X�V
void EnemyCommandAlongWallMove::Update(float deltaTime) {
	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
	//�ڕW�n�_�ɂ��ǂ蒅���Ă��邩
	if (m_Velocity.length() <= FLOAT_EPSILON)
		SetTargetPos();
}

//�I��
void EnemyCommandAlongWallMove::Finalize() {

}

//��]�����̐ݒ�
void EnemyCommandAlongWallMove::SetTurnDirection(TurnDirection turnDirection) {
	m_TurnDirection = turnDirection;
}

//�e��ŗL�̏�����
void EnemyCommandAlongWallMove::OnInitialize() {

}

//�ڕW�n�_�̐ݒ�
void EnemyCommandAlongWallMove::SetTargetPos() {
	//�����̎��ӂ̃^�C���f�[�^�z��
	std::unordered_map<FourDirection, TileData> mapDate
		= p_Enemy->getWorld()->GetMap().GetAroundTile(p_Enemy->getPosition());

	//�i�s�����̋t�����ɕύX
	m_CurDirection.TurnOver();

	//���ʕϐ�
	TileData result;

	//�i�s���������肷��܂�
	while (true)
	{
		//90�x��]
		m_CurDirection.Turn(m_TurnDirection.GetReversal());
		//�����ɉ������^�C���f�[�^�̎��o��
		result = mapDate[m_CurDirection];
		//�^�C�����ǂł͂Ȃ���
		if (result.Flag() == 0)
			break;
	}

	//�i�s�����^�C���̍��W��ݒ�
	m_NextTargetPos = result.Position();

	//�ڕW�n�_�܂ł̋���
	m_Velocity = m_NextTargetPos - p_Enemy->getPosition();
}