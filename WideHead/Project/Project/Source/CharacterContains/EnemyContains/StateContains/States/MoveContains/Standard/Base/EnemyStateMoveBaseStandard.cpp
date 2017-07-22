#include "EnemyStateMoveBaseStandard.h"
#include "../../../../../Entity/Enemys/Base/EnemyBase.h"
#include "../../../../../../../WorldContains/EventMessage/EventMessage.h"
#include "../../../../../CommandContains/CommandManagers/Interface/IEnemyCommandManager.h"

// �R���X�g���N�^
EnemyStateMoveBaseStandard::EnemyStateMoveBaseStandard(const EnemyBasePtr& enemy)
	:EnemyStateBase(enemy) {
}

// �e��ԓƎ��̏�����
void EnemyStateMoveBaseStandard::unique_init() {
	//�p����̊e��ԓƎ��̏�����
	onUniqueInit();
}

// �X�V����
void EnemyStateMoveBaseStandard::update(float deltaTime) {
	//�ړI�n�܂ł̃x�N�g��
	GSvector2 velocity = p_Enemy.lock()->GetCommandManager()->GetCommandVector();

	//�ړ��̑��x�ɂ���ď�Ԃ�ύX�i�ҋ@�A�����j
	if (velocity.length() <= 0)
		change(EnemyStateName::Idle);
	else
		change(EnemyStateName::Move);

	//�p����̍X�V����
	onUpdate(deltaTime);
}

// �Փ˔���
void EnemyStateMoveBaseStandard::collide(const Actor & other, const Body::ContactSet& contactSet) {
	// �p����̏Փ˔���
	onCollide(other, contactSet);
}

// �I�����̏���
void EnemyStateMoveBaseStandard::end() {
	//�p����̏I������
	onEnd();
}

// ���͏���
void EnemyStateMoveBaseStandard::input() {
	// �R�}���h�w���State
	EnemyStateName name = p_Enemy.lock()->GetCommandManager()->GetCommandState();
	if (name != EnemyStateName::None)
		change(name);

	// �p����̓��͏���
	onInput();
}

// ���b�Z�[�W����
void EnemyStateMoveBaseStandard::OnHandleMessage(EventMessage message, void* param) {
	switch (message)
	{
		//�v���C���[�ɋ��܂ꂽ�Ƃ�
	case EventMessage::PLAYER_ROUNDS:
		change(EnemyStateName::Caught);
		break;
	}
}