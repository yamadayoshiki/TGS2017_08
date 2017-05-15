#include"PlayerState_CrushBase.h"

//�R���X�g���N�^
PlayerState_CrushBase::PlayerState_CrushBase(const PlayerPtr& player, IGameManagerPtr gameManager)
	:PlayerState(player, gameManager), m_FrameCounter(0.0f) {}

//�e��ԓƎ��̏�����
void PlayerState_CrushBase::unique_init()
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit();
}
//�X�V����
void PlayerState_CrushBase::update(float deltaTaime)
{
	//�p����̍X�V����
	onUpdate(deltaTaime);
}
//�Փ˔���
void PlayerState_CrushBase::collide(const Actor& other)
{
	if (other.getName() == ActorName::Enemy)
	{

	}
	//�p����̏Փˏ���
	onCollide(other);
}
//�I������
void PlayerState_CrushBase::end()
{
	//�p����̏I������
	onEnd();
}
//���͏���
void PlayerState_CrushBase::input()
{
	//�p����̓��͏���
	onInput();
}