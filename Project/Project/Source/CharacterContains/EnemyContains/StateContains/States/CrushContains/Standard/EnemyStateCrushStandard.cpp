#include "EnemyStateCrushStandard.h"
#include "../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../WorldContains/IWorld.h"
#include "../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "..\..\Damage\EnemyStateDamage.h"


//�R���X�g���N�^
EnemyStateCrushStandard::EnemyStateCrushStandard(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateCrushStandard::unique_init() {
	//���[�V�����̕ύX

}

// �X�V����
void EnemyStateCrushStandard::update(float deltaTime) {
	if (p_Enemy.lock()->GetHitPoint().IsDead() == true)
		change(EnemyStateName::Dead);

	else
		change(EnemyStateName::Caught);
}