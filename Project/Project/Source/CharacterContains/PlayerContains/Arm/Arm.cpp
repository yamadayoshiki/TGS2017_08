#include"Arm.h"
#include "../../../ActorContains/BodyContains/AARectangle/AARectangle.h"
#include "../../../Define/Def_Nakayama.h"
#include "../../../ActorContains/Transform/Transform.h"

//コンストラクタ
Arm::Arm(IWorld* world, GSvector2& position, IGameManagerPtr gameManager)
	:Actor(world
	,ActorName::Player_Arm
	, position
	, gameManager
	, std::make_shared<NullTexture>()
		, std::make_shared<Body::AARectangle>(CHIP_SIZE,CHIP_SIZE))
	,m_Angle(0.0f)
	,mHitFlag(false)
{

}
//デストラクタ
Arm::~Arm()
{

}
//更新処理
void Arm::onUpdate(float deltaTime)
{
	p_Transform->m_Position = getPosition().clamp(GSvector2(16.0f, 16.0f), GSvector2(1280 - 16, 960 - 16));
}
//描画処理
void Arm::onDraw()const
{
	//Actor::onDraw();
}
//衝突判定
void Arm::onCollide(Actor& other)
{
	mHitFlag = true;
}