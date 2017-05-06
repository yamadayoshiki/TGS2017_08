#include"Arm.h"
#include"../../../ActorContains/Body/OrientedBoundingBox.h"


//�R���X�g���N�^
Arm::Arm(const IWorldPtr& world, GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
	:Actor(world
	,ActorName::Player_Arm
	, position
	, gameManager
	, std::make_shared<NullTexture>()
		, std::make_shared<OrientedBoundingBox>(GSvector2{32.0f,32.0f}, GSvector2{ 2.0f, 1.0f }, GS_MATRIX4_IDENTITY))
	,m_Angle(0.0f)
	,mHitFlag(false)
{

}
//�f�X�g���N�^
Arm::~Arm()
{

}
//�X�V����
void Arm::onUpdate(float deltaTime)
{
	
}
//�`�揈��
void Arm::onDraw()const
{
	Actor::onDraw();
}
//�Փ˔���
void Arm::onCollide(Actor& other)
{
	mHitFlag = true;
}
//�Փ˂��Ă�����Ԃ�
bool Arm::isCollide(const Actor& other)
{
	// ��]���܂ޏꍇ
	return p_Body->transform(getPose())->isCollide(*other.getBody()->transform(other.getPose()).get(), HitInfo());
}
//���W�̐ݒ�
void Arm::setPosition(GSvector2 position)
{
	m_Position = position;
}
//�s��
void Arm::setMatrix(GSmatrix4 matrix)
{
	m_Matrix = matrix;
}
//��]�p�x
void Arm::setAngle(float angle)
{
	m_Angle = angle;
}