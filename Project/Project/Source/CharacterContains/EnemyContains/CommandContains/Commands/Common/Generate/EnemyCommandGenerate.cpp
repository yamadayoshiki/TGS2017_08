#include "EnemyCommandGenerate.h"

//�R���X�g���N�^
EnemyCommandGenerate::EnemyCommandGenerate(
	const EnemyBasePtr & enemy,
	const MapType type,
	const TurnDirection turnDirection)
	:EnemyCommandBase(enemy) {
}

//�f�X�g���N�^
EnemyCommandGenerate::~EnemyCommandGenerate() {
}

//�I��
void EnemyCommandGenerate::Finalize() {
}

//�e��ŗL�̏�����
void EnemyCommandGenerate::OnInitialize() {
}

//�e��ŗL�̍X�V
void EnemyCommandGenerate::OnUpdate(float deltaTime) {
}

