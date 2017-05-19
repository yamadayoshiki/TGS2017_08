#include "Enemy04.h"

#include "../../../../ActorContains/ActorName.h"
#include "../../../../TextureContains/Texture/Texture.h"
#include "../../../../Base/GameManagerContains/IGameManager.h"
#include "../../../../Utility/Rederer2D/Renderer2D.h"
#include "../../../../Utility/FourDirection/FourDirection.h"
#include "../../../../Utility/MathSupport/MathSupport.h"
#include "../../../../Utility/TurnDirection/TurnDirection.h"
#include "../../../../ActorContains/Body/OrientedBoundingBox.h"

//CommandContains
#include "../../CommandContains/CommandManagers/Nomal/EnemyCommandManagerNormal.h"
#include "../../CommandContains/Commands/EnemyCommandName.h"

//State

Enemy04::Enemy04(IWorld * world, const GSvector2 & position, FourDirection & front, const IGameManagerPtr & gameManager)
	:EnemyBase(
		world,
		ActorName::Enemy_04,
		position,
		1.0f,
		10,
		gameManager,
		std::make_shared<Texture>("Enemy01", gameManager->GetRenderer2D()),
		std::make_shared<OrientedBoundingBox>(GSvector2(0.0f, 0.0f), -90.0f, GSvector2(1.0f, 1.0f))) {
	m_Transform.m_Angle = MathSupport::GetVec2ToVec2Angle(front.GetVector2());

}

void Enemy04::SetUpCommand()
{
}

void Enemy04::SetUpState()
{
}

void Enemy04::onDraw() const
{
}
