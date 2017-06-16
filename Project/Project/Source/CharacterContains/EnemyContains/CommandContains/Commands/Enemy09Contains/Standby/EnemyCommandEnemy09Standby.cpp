#include "EnemyCommandEnemy09Standby.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../PlayerWatch/PlayerWatch.h"
#include "../../../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../../../FrontChipList/FrontChipList.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../Utility/FourDirection/FourDirection.h"

EnemyCommandEnemy09Standby::EnemyCommandEnemy09Standby(
	const EnemyBasePtr & enemy)
	: EnemyCommandBase(enemy)
	, p_FrontChipList(new FrontChipList(enemy->getWorld()->GetMap(), enemy->getPosition(), enemy->GetDirection(), MapType::Double)) {
}

EnemyCommandEnemy09Standby::~EnemyCommandEnemy09Standby() {
	m_SpeaceNumMap.clear();
	delete p_FrontChipList;
}

void EnemyCommandEnemy09Standby::OnInitialize() {
	//�e�����̕ǃ}�X�܂ł̋����̐ݒ�
	SetSpeaceNum(FourDirectionName::Up);
	SetSpeaceNum(FourDirectionName::Left);
	SetSpeaceNum(FourDirectionName::Right);
	SetSpeaceNum(FourDirectionName::Down);
}

void EnemyCommandEnemy09Standby::OnUpdate(float deltaTime) {
	//�v���C���[���������
	GSvector2 v = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerDis();
	//�p�x�Z�o
	float angle = MathSupport::GetVec2ToVec2Angle(v, GSvector2(0.0f, -1.0f));
	//�p�x�ݒ�
	p_Enemy.lock()->setAngle(angle);

	//�����ǂ��炩�d�Ȃ��Ă�����ːi
	if (IsAxisOverlap() == true)
		Change(EnemyCommandName::Rush);
}

bool EnemyCommandEnemy09Standby::IsAxisOverlap() {
	//�v���C���[�܂ł̃}�X��������
	GSvector2 toPlayer = p_Enemy.lock()->GetPlayerWatch()->GetToPlayerChipDis();

	if (toPlayer.x == 0 || toPlayer.y == 0)
	{
		float speaceNum = m_SpeaceNumMap[FourDirection(toPlayer)];
		if (speaceNum >= toPlayer.length())
		{
			p_Enemy.lock()->SetDirection(FourDirection(toPlayer));
			return true;
		}
	}

	return false;
}

//�w������̕ǃ}�X�܂ł̋����̐ݒ�
void EnemyCommandEnemy09Standby::SetSpeaceNum(const FourDirectionName name) {
	FourDirection dir = FourDirection(name);
	//�O���}�X�̐ݒ�
	p_FrontChipList->SetFrontChipList(p_Enemy.lock()->getPosition(), dir);
	//�ǃ}�X�܂ł̋���
	m_SpeaceNumMap[dir] = p_FrontChipList->GetSpeaceNum();
}
