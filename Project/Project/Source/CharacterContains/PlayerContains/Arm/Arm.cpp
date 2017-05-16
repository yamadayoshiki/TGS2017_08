#include"Arm.h"
#include"../../../ActorContains/Body/OrientedBoundingBox.h"


//�R���X�g���N�^
Arm::Arm(IWorld* world, GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world
	,ActorName::Player_Arm
	, position
	, gameManager
	, std::make_shared<NullTexture>()
		, std::make_shared<OrientedBoundingBox>(GSvector2{0.0f,0.0f}, -90.0f, GSvector2{ 1.0f, 2.0f }))
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
	m_Transform.m_Position = m_Transform.m_Position.clamp(GSvector2(16.0f, 16.0f), GSvector2(1280 - 16, 960 - 16));
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
////�Փ˂��Ă�����Ԃ�
//bool Arm::isCollide(const Actor& other)
//{
//	// ��]���܂ޏꍇ
//	//return p_Body->transform(getTransform())->isCollide(*other.getBody()->transform(other.getTransform()).get(), HitInfo());
//}