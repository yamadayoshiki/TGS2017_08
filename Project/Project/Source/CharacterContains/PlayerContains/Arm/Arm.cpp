#include"Arm.h"
#include"../../../ActorContains/Body/OrientedBoundingBox.h"


//コンストラクタ
Arm::Arm(IWorld* world, GSvector2& position, GSmatrix4& matrix, IGameManagerPtr gameManager)
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
//デストラクタ
Arm::~Arm()
{

}
//更新処理
void Arm::onUpdate(float deltaTime)
{
	
}
//描画処理
void Arm::onDraw()const
{
	Actor::onDraw();
}
//衝突判定
void Arm::onCollide(Actor& other)
{
	mHitFlag = true;
}
//衝突していたら返す
bool Arm::isCollide(const Actor& other)
{
	// 回転を含む場合
	return p_Body->transform(getTransform())->isCollide(*other.getBody()->transform(other.getTransform()).get(), HitInfo());
}
//座標の設定
void Arm::setPosition(GSvector2 position)
{
	m_Transform.m_Position = position;
}
//行列
void Arm::setMatrix(GSmatrix4 matrix)
{
	//m_Matrix = matrix;
}
//回転角度
void Arm::setAngle(float angle)
{
	m_Angle = angle;
}