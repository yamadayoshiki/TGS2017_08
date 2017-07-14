#include"Arm.h"
#include "../../../Define/Def_Nakayama.h"
#include "../../../ActorContains/Transform/Transform.h"

//�R���X�g���N�^
Arm::Arm(IWorld* world, GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world
		, ActorName::Player_Arm
		, position
		, gameManager
		, std::make_shared<NullTexture>()
		, Body::MotionType::Player
		, Body::BodyDataName::PlayerAttackRange)
	, m_Angle(0.0f)
	, mHitFlag(false)
{

}
//�f�X�g���N�^
Arm::~Arm()
{

}
//�X�V����
void Arm::onUpdate(float deltaTime){
	//p_Transform->m_Position = getPosition().clamp(GSvector2(16.0f, 16.0f), GSvector2(1280 - 16, 960 - 16));
}
//�`�揈��
void Arm::onDraw()const
{
	//Actor::onDraw();
}
//�Փ˔���
void Arm::onCollide(Actor& other, const Body::ContactSet& contactSet)
{
	mHitFlag = true;
}