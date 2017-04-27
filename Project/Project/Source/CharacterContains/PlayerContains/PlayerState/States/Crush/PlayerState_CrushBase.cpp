#include"PlayerState_CrushBase.h"

//�R���X�g���N�^
PlayerState_CrushBase::PlayerState_CrushBase(GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:PlayerState(position, matrix, gameManager) ,m_FrameCounter(0.0f){}

//�e��ԓƎ��̏�����
void PlayerState_CrushBase::unique_init(Actor& actor)
{
	// �p����̊e��ԓƎ��̏�����
	onUniqueInit(actor);
}
//�X�V����
void PlayerState_CrushBase::update(Actor& actor, float deltaTaime)
{


	move(actor, deltaTaime);

	//�p����̍X�V����
	onUpdate(actor, deltaTaime);
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
	//�A�[�����J��
	if (p_Input->IsPadTrigger(GS_XBOX_PAD_B)) change(PlayerStateName::Open);

	//�p����̓��͏���
	onInput();
}