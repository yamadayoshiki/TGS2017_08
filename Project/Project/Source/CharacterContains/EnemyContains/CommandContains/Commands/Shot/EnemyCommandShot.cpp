#include "EnemyCommandShot.h"
#include "../../../Enemys/Base/EnemyBase.h"

//�R���X�g���N�^
EnemyCommandShot::EnemyCommandShot(const EnemyBasePtr& enemy)
	:EnemyCommandBase(enemy) {
}

//�e��ŗL�̏�����
void EnemyCommandShot::OnInitialize() {

}

//�X�V
void EnemyCommandShot::Update(float deltaTime) {
}

//�I��
void EnemyCommandShot::Finalize() {

}

//�I���`�F�b�N
bool EnemyCommandShot::IsEnd() {
	return true;
}
//���߃X�e�[�g
EnemyStateName EnemyCommandShot::GetCurrentStateName() const {
	return EnemyStateName::Shot;
}